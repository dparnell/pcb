/* $Id$ */

/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 1994,1995,1996 Thomas Nau
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Contact addresses for paper mail and Email:
 *  Thomas Nau, Schlehenweg 15, 88471 Baustetten, Germany
 *  Thomas.Nau@rz.uni-ulm.de
 *
 */


/* routines to update widgets and global settings
 * (except output window and dialogs)
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "global.h"

#include "action.h"
#include "buffer.h"
#include "compat.h"
#include "crosshair.h"
#include "data.h"
#include "draw.h"
#include "error.h"
#include "find.h"
#include "misc.h"
#include "set.h"
#include "undo.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");

static int mode_position = 0;
static int mode_stack[MAX_MODESTACK_DEPTH];

/* ---------------------------------------------------------------------------
 * sets cursor grid with respect to grid offset values
 */
void
SetGrid (float Grid, bool align)
{
  if (Grid >= 1 && Grid <= MAX_GRID)
    {
      if (align)
	{
	  PCB->GridOffsetX =
	    Crosshair.X - (int) (Crosshair.X / Grid) * Grid + 0.5;
	  PCB->GridOffsetY =
	    Crosshair.Y - (int) (Crosshair.Y / Grid) * Grid + 0.5;
	}
      PCB->Grid = Grid;
      if (Settings.DrawGrid)
	UpdateAll ();
    }
}

/* ---------------------------------------------------------------------------
 * sets a new line thickness
 */
void
SetLineSize (BDimension Size)
{
  if (Size >= MIN_LINESIZE && Size <= MAX_LINESIZE)
    {
      Settings.LineThickness = Size;
      if (TEST_FLAG (AUTODRCFLAG, PCB))
	FitCrosshairIntoGrid (Crosshair.X, Crosshair.Y);
    }
}

/* ---------------------------------------------------------------------------
 * sets a new via thickness
 */
void
SetViaSize (BDimension Size, bool Force)
{
  if (Force || (Size <= MAX_PINORVIASIZE &&
		Size >= MIN_PINORVIASIZE &&
		Size >= Settings.ViaDrillingHole + MIN_PINORVIACOPPER))
    {
      Settings.ViaThickness = Size;
    }
}

/* ---------------------------------------------------------------------------
 * sets a new via drilling hole
 */
void
SetViaDrillingHole (BDimension Size, bool Force)
{
  if (Force || (Size <= MAX_PINORVIASIZE &&
		Size >= MIN_PINORVIAHOLE &&
		Size <= Settings.ViaThickness - MIN_PINORVIACOPPER))
    {
      Settings.ViaDrillingHole = Size;
    }
}

void
pcb_use_route_style (RouteStyleType * rst)
{
  Settings.LineThickness = rst->Thick;
  Settings.ViaThickness = rst->Diameter;
  Settings.ViaDrillingHole = rst->Hole;
  Settings.Keepaway = rst->Keepaway;
}

/* ---------------------------------------------------------------------------
 * sets a keepaway width
 */
void
SetKeepawayWidth (BDimension Width)
{
  if (Width <= MAX_LINESIZE)
    {
      Settings.Keepaway = Width;
    }
}

/* ---------------------------------------------------------------------------
 * sets a text scaling
 */
void
SetTextScale (Dimension Scale)
{
  if (Scale <= MAX_TEXTSCALE && Scale >= MIN_TEXTSCALE)
    {
      Settings.TextScale = Scale;
    }
}

/* ---------------------------------------------------------------------------
 * sets or resets changed flag and redraws status
 */
void
SetChangedFlag (bool New)
{
  if (PCB->Changed != New)
    {
      PCB->Changed = New;

    }
}

/* ---------------------------------------------------------------------------
 * sets the crosshair range to the current buffer extents 
 */
void
SetCrosshairRangeToBuffer (void)
{
  if (Settings.Mode == PASTEBUFFER_MODE)
    {
      SetBufferBoundingBox (PASTEBUFFER);
      SetCrosshairRange (PASTEBUFFER->X - PASTEBUFFER->BoundingBox.X1,
			 PASTEBUFFER->Y - PASTEBUFFER->BoundingBox.Y1,
			 PCB->MaxWidth -
			 (PASTEBUFFER->BoundingBox.X2 - PASTEBUFFER->X),
			 PCB->MaxHeight -
			 (PASTEBUFFER->BoundingBox.Y2 - PASTEBUFFER->Y));
    }
}

/* ---------------------------------------------------------------------------
 * sets a new buffer number
 */
void
SetBufferNumber (int Number)
{
  if (Number >= 0 && Number < MAX_BUFFER)
    {
      Settings.BufferNumber = Number;

      /* do an update on the crosshair range */
      SetCrosshairRangeToBuffer ();
    }
}

/* ---------------------------------------------------------------------------
 */

void
SaveMode (void)
{
  mode_stack[mode_position] = Settings.Mode;
  if (mode_position < MAX_MODESTACK_DEPTH - 1)
    mode_position++;
}

void
RestoreMode (void)
{
  if (mode_position == 0)
    {
      Message ("hace: underflow of restore mode\n");
      return;
    }
  SetMode (mode_stack[--mode_position]);
}


/* ---------------------------------------------------------------------------
 * set a new mode and update X cursor
 */
void
SetMode (int Mode)
{
  static bool recursing = false;
  /* protect the cursor while changing the mode
   * perform some additional stuff depending on the new mode
   * reset 'state' of attached objects
   */
  if (recursing)
    return;
  recursing = true;
  HideCrosshair (true);
  addedLines = 0;
  Crosshair.AttachedObject.Type = NO_TYPE;
  Crosshair.AttachedObject.State = STATE_FIRST;
  Crosshair.AttachedPolygon.PointN = 0;
  if (PCB->RatDraw)
    {
      if (Mode == ARC_MODE || Mode == RECTANGLE_MODE ||
	  Mode == VIA_MODE || Mode == POLYGON_MODE ||
	  Mode == POLYGONHOLE_MODE ||
	  Mode == TEXT_MODE || Mode == INSERTPOINT_MODE ||
	  Mode == THERMAL_MODE)
	{
	  Message (_("That mode is NOT allowed when drawing ratlines!\n"));
	  Mode = NO_MODE;
	}
    }
  if (Settings.Mode == LINE_MODE && Mode == ARC_MODE &&
      Crosshair.AttachedLine.State != STATE_FIRST)
    {
      Crosshair.AttachedLine.State = STATE_FIRST;
      Crosshair.AttachedBox.State = STATE_SECOND;
      Crosshair.AttachedBox.Point1.X = Crosshair.AttachedBox.Point2.X =
	Crosshair.AttachedLine.Point1.X;
      Crosshair.AttachedBox.Point1.Y = Crosshair.AttachedBox.Point2.Y =
	Crosshair.AttachedLine.Point1.Y;
      AdjustAttachedObjects ();
    }
  else if (Settings.Mode == ARC_MODE && Mode == LINE_MODE &&
	   Crosshair.AttachedBox.State != STATE_FIRST)
    {
      Crosshair.AttachedBox.State = STATE_FIRST;
      Crosshair.AttachedLine.State = STATE_SECOND;
      Crosshair.AttachedLine.Point1.X = Crosshair.AttachedLine.Point2.X =
	Crosshair.AttachedBox.Point1.X;
      Crosshair.AttachedLine.Point1.Y = Crosshair.AttachedLine.Point2.Y =
	Crosshair.AttachedBox.Point1.Y;
      Settings.Mode = Mode;
      AdjustAttachedObjects ();
    }
  else
    {
      if (Settings.Mode == ARC_MODE || Settings.Mode == LINE_MODE)
	SetLocalRef (0, 0, false);
      Crosshair.AttachedBox.State = STATE_FIRST;
      Crosshair.AttachedLine.State = STATE_FIRST;
      if (Mode == LINE_MODE && TEST_FLAG (AUTODRCFLAG, PCB))
	{
	  SaveUndoSerialNumber ();
	  ResetFoundPinsViasAndPads (true);
	  RestoreUndoSerialNumber ();
	  ResetFoundLinesAndPolygons (true);
	  IncrementUndoSerialNumber ();
	}
    }

  Settings.Mode = Mode;

  if (Mode == PASTEBUFFER_MODE)
    /* do an update on the crosshair range */
    SetCrosshairRangeToBuffer ();
  else
    SetCrosshairRange (0, 0, PCB->MaxWidth, PCB->MaxHeight);

  recursing = false;

  /* force a crosshair grid update because the valid range
   * may have changed
   */
  MoveCrosshairRelative (0, 0);
  RestoreCrosshair (true);
}

void
SetRouteStyle (char *name)
{
  char num[10];

  STYLE_LOOP (PCB);
  {
    if (name && NSTRCMP (name, style->Name) == 0)
      {
	sprintf (num, "%d", n + 1);
	hid_actionl ("RouteStyle", num, NULL);
	break;
      }
  }
  END_LOOP;
}

void
SetLocalRef (LocationType X, LocationType Y, bool Showing)
{
  static MarkType old;
  static int count = 0;

  if (Showing)
    {
      HideCrosshair (true);
      if (count == 0)
	old = Marked;
      Marked.X = X;
      Marked.Y = Y;
      Marked.status = true;
      count++;
      RestoreCrosshair (false);
    }
  else if (count > 0)
    {
      HideCrosshair (false);
      count = 0;
      Marked = old;
      RestoreCrosshair (false);
    }
}

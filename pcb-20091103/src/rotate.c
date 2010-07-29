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


/* functions used to rotate pins, elements ...
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#include "global.h"

#include "crosshair.h"
#include "data.h"
#include "draw.h"
#include "error.h"
#include "misc.h"
#include "polygon.h"
#include "rotate.h"
#include "rtree.h"
#include "rubberband.h"
#include "search.h"
#include "select.h"
#include "set.h"
#include "undo.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");




/* ---------------------------------------------------------------------------
 * some local prototypes
 */
static void *RotateText (LayerTypePtr, TextTypePtr);
static void *RotateArc (LayerTypePtr, ArcTypePtr);
static void *RotateElement (ElementTypePtr);
static void *RotateElementName (ElementTypePtr);
static void *RotateLinePoint (LayerTypePtr, LineTypePtr, PointTypePtr);

/* ----------------------------------------------------------------------
 * some local identifiers
 */
static LocationType CenterX,	/* center of rotation */
  CenterY;
static BYTE Number;		/* number of rotations */
static ObjectFunctionType RotateFunctions = {
  NULL,
  RotateText,
  NULL,
  NULL,
  RotateElement,
  RotateElementName,
  NULL,
  NULL,
  RotateLinePoint,
  NULL,
  RotateArc,
  NULL
};

/* ---------------------------------------------------------------------------
 * rotates a point in 90 degree steps
 */
void
RotatePointLowLevel (PointTypePtr Point, LocationType X, LocationType Y,
		     BYTE Number)
{
  ROTATE (Point->X, Point->Y, X, Y, Number);
}

/* ---------------------------------------------------------------------------
 * rotates a line in 90 degree steps
 */
void
RotateLineLowLevel (LineTypePtr Line, LocationType X, LocationType Y,
		    BYTE Number)
{
  ROTATE (Line->Point1.X, Line->Point1.Y, X, Y, Number);
  ROTATE (Line->Point2.X, Line->Point2.Y, X, Y, Number);
  /* keep horizontal, vertical Point2 > Point1 */
  if (Line->Point1.X == Line->Point2.X)
    {
      if (Line->Point1.Y > Line->Point2.Y)
	{
	  LocationType t;
	  t = Line->Point1.Y;
	  Line->Point1.Y = Line->Point2.Y;
	  Line->Point2.Y = t;
	}
    }
  else if (Line->Point1.Y == Line->Point2.Y)
    {
      if (Line->Point1.X > Line->Point2.X)
	{
	  LocationType t;
	  t = Line->Point1.X;
	  Line->Point1.X = Line->Point2.X;
	  Line->Point2.X = t;
	}
    }
  /* instead of rotating the bounding box, the call updates both end points too */
  SetLineBoundingBox (Line);
}

/* ---------------------------------------------------------------------------
 * rotates a text in 90 degree steps 
 * only the bounding box is rotated, text rotation itself
 * is done by the drawing routines
 */
void
RotateTextLowLevel (TextTypePtr Text, LocationType X, LocationType Y,
		    BYTE Number)
{
  BYTE number;

  number = TEST_FLAG (ONSOLDERFLAG, Text) ? (4 - Number) & 3 : Number;
  RotateBoxLowLevel (&Text->BoundingBox, X, Y, Number);
  ROTATE (Text->X, Text->Y, X, Y, Number);

  /* set new direction, 0..3,
   * 0-> to the right, 1-> straight up,
   * 2-> to the left, 3-> straight down
   */
  Text->Direction = ((Text->Direction + number) & 0x03);
}

/* ---------------------------------------------------------------------------
 * rotates a polygon in 90 degree steps
 */
void
RotatePolygonLowLevel (PolygonTypePtr Polygon,
		       LocationType X, LocationType Y, BYTE Number)
{
  POLYGONPOINT_LOOP (Polygon);
  {
    ROTATE (point->X, point->Y, X, Y, Number);
  }
  END_LOOP;
  RotateBoxLowLevel (&Polygon->BoundingBox, X, Y, Number);
}

/* ---------------------------------------------------------------------------
 * rotates a text object and redraws it
 */
static void *
RotateText (LayerTypePtr Layer, TextTypePtr Text)
{
  EraseText (Layer, Text);
  RestoreToPolygon (PCB->Data, TEXT_TYPE, Layer, Text);
  r_delete_entry (Layer->text_tree, (BoxTypePtr) Text);
  RotateTextLowLevel (Text, CenterX, CenterY, Number);
  r_insert_entry (Layer->text_tree, (BoxTypePtr) Text, 0);
  ClearFromPolygon (PCB->Data, TEXT_TYPE, Layer, Text);
  DrawText (Layer, Text, 0);
  Draw ();
  return (Text);
}

/* ---------------------------------------------------------------------------
 * rotates an arc
 */
void
RotateArcLowLevel (ArcTypePtr Arc, LocationType X, LocationType Y,
		   BYTE Number)
{
  BDimension save;

  /* add Number*90 degrees to the startangle and check for overflow */
  Arc->StartAngle = (Arc->StartAngle + Number * 90) % 360;
  ROTATE (Arc->X, Arc->Y, X, Y, Number);

  /* now change width and height */
  if (Number == 1 || Number == 3)
    {
      save = Arc->Width;
      Arc->Width = Arc->Height;
      Arc->Height = save;
    }
  RotateBoxLowLevel (&Arc->BoundingBox, X, Y, Number);
}

/* ---------------------------------------------------------------------------
 * rotate an element in 90 degree steps
 */
void
RotateElementLowLevel (DataTypePtr Data, ElementTypePtr Element,
		       LocationType X, LocationType Y, BYTE Number)
{
  /* solder side objects need a different orientation */

  /* the text subroutine decides by itself if the direction
   * is to be corrected
   */
  ELEMENTTEXT_LOOP (Element);
  {
    if (Data && Data->name_tree[n])
      r_delete_entry (Data->name_tree[n], (BoxType *) text);
    RotateTextLowLevel (text, X, Y, Number);
  }
  END_LOOP;
  ELEMENTLINE_LOOP (Element);
  {
    RotateLineLowLevel (line, X, Y, Number);
  }
  END_LOOP;
  PIN_LOOP (Element);
  {
    /* pre-delete the pins from the pin-tree before their coordinates change */
    if (Data)
      r_delete_entry (Data->pin_tree, (BoxType *) pin);
    RestoreToPolygon (Data, PIN_TYPE, Element, pin);
    ROTATE_PIN_LOWLEVEL (pin, X, Y, Number);
  }
  END_LOOP;
  PAD_LOOP (Element);
  {
    /* pre-delete the pads before their coordinates change */
    if (Data)
      r_delete_entry (Data->pad_tree, (BoxType *) pad);
    RestoreToPolygon (Data, PAD_TYPE, Element, pad);
    ROTATE_PAD_LOWLEVEL (pad, X, Y, Number);
  }
  END_LOOP;
  ARC_LOOP (Element);
  {
    RotateArcLowLevel (arc, X, Y, Number);
  }
  END_LOOP;
  ROTATE (Element->MarkX, Element->MarkY, X, Y, Number);
  /* SetElementBoundingBox reenters the rtree data */
  SetElementBoundingBox (Data, Element, &PCB->Font);
  ClearFromPolygon (Data, ELEMENT_TYPE, Element, Element);
}

/* ---------------------------------------------------------------------------
 * rotates a line's point
 */
static void *
RotateLinePoint (LayerTypePtr Layer, LineTypePtr Line, PointTypePtr Point)
{
  EraseLine (Line);
  if (Layer)
    {
      RestoreToPolygon (PCB->Data, LINE_TYPE, Layer, Line);
      r_delete_entry (Layer->line_tree, (BoxTypePtr) Line);
    }
  else
    r_delete_entry (PCB->Data->rat_tree, (BoxTypePtr) Line);
  RotatePointLowLevel (Point, CenterX, CenterY, Number);
  SetLineBoundingBox (Line);
  if (Layer)
    {
      r_insert_entry (Layer->line_tree, (BoxTypePtr) Line, 0);
      ClearFromPolygon (PCB->Data, LINE_TYPE, Layer, Line);
      DrawLine (Layer, Line, 0);
    }
  else
    {
      r_insert_entry (PCB->Data->rat_tree, (BoxTypePtr) Line, 0);
      DrawRat ((RatTypePtr) Line, 0);
    }
  Draw ();
  return (Line);
}

/* ---------------------------------------------------------------------------
 * rotates an arc
 */
static void *
RotateArc (LayerTypePtr Layer, ArcTypePtr Arc)
{
  EraseArc (Arc);
  r_delete_entry (Layer->arc_tree, (BoxTypePtr) Arc);
  RotateArcLowLevel (Arc, CenterX, CenterY, Number);
  r_insert_entry (Layer->arc_tree, (BoxTypePtr) Arc, 0);
  DrawArc (Layer, Arc, 0);
  Draw ();
  return (Arc);
}

/* ---------------------------------------------------------------------------
 * rotates an element
 */
static void *
RotateElement (ElementTypePtr Element)
{
  EraseElement (Element);
  RotateElementLowLevel (PCB->Data, Element, CenterX, CenterY, Number);
  DrawElement (Element, 0);
  Draw ();
  return (Element);
}

/* ----------------------------------------------------------------------
 * rotates the name of an element
 */
static void *
RotateElementName (ElementTypePtr Element)
{
  EraseElementName (Element);
  ELEMENTTEXT_LOOP (Element);
  {
    r_delete_entry (PCB->Data->name_tree[n], (BoxType *) text);
    RotateTextLowLevel (text, CenterX, CenterY, Number);
    r_insert_entry (PCB->Data->name_tree[n], (BoxType *) text, 0);
  }
  END_LOOP;
  DrawElementName (Element, 0);
  Draw ();
  return (Element);
}

/* ---------------------------------------------------------------------------
 * rotates a box in 90 degree steps 
 */
void
RotateBoxLowLevel (BoxTypePtr Box, LocationType X, LocationType Y,
		   BYTE Number)
{
  LocationType x1 = Box->X1, y1 = Box->Y1, x2 = Box->X2, y2 = Box->Y2;

  ROTATE (x1, y1, X, Y, Number);
  ROTATE (x2, y2, X, Y, Number);
  Box->X1 = MIN (x1, x2);
  Box->Y1 = MIN (y1, y2);
  Box->X2 = MAX (x1, x2);
  Box->Y2 = MAX (y1, y2);
}

/* ----------------------------------------------------------------------
 * rotates an objects at the cursor position as identified by its ID
 * the center of rotation is determined by the current cursor location
 */
void *
RotateObject (int Type, void *Ptr1, void *Ptr2, void *Ptr3,
	      LocationType X, LocationType Y, BYTE Steps)
{
  RubberbandTypePtr ptr;
  void *ptr2;
  Boolean changed = False;

  /* setup default  global identifiers */
  Number = Steps;
  CenterX = X;
  CenterY = Y;

  /* move all the rubberband lines... and reset the counter */
  ptr = Crosshair.AttachedObject.Rubberband;
  while (Crosshair.AttachedObject.RubberbandN)
    {
      changed = True;
      CLEAR_FLAG (RUBBERENDFLAG, ptr->Line);
      AddObjectToRotateUndoList (LINEPOINT_TYPE, ptr->Layer, ptr->Line,
				 ptr->MovedPoint, CenterX, CenterY, Steps);
      EraseLine (ptr->Line);
      if (ptr->Layer)
	{
	  RestoreToPolygon (PCB->Data, LINE_TYPE, ptr->Layer, ptr->Line);
	  r_delete_entry (ptr->Layer->line_tree, (BoxType *) ptr->Line);
	}
      else
	r_delete_entry (PCB->Data->rat_tree, (BoxType *) ptr->Line);
      RotatePointLowLevel (ptr->MovedPoint, CenterX, CenterY, Steps);
      SetLineBoundingBox (ptr->Line);
      if (ptr->Layer)
	{
	  r_insert_entry (ptr->Layer->line_tree, (BoxType *) ptr->Line, 0);
	  ClearFromPolygon (PCB->Data, LINE_TYPE, ptr->Layer, ptr->Line);
	  DrawLine (ptr->Layer, ptr->Line, 0);
	}
      else
	{
	  r_insert_entry (PCB->Data->rat_tree, (BoxType *) ptr->Line, 0);
	  DrawRat ((RatTypePtr) ptr->Line, 0);
	}
      Crosshair.AttachedObject.RubberbandN--;
      ptr++;
    }
  AddObjectToRotateUndoList (Type, Ptr1, Ptr2, Ptr3, CenterX, CenterY,
			     Number);
  ptr2 = ObjectOperation (&RotateFunctions, Type, Ptr1, Ptr2, Ptr3);
  changed |= (ptr2 != NULL);
  if (changed)
    {
      Draw ();
      IncrementUndoSerialNumber ();
    }
  return (ptr2);
}

void
RotateScreenObject (LocationType X, LocationType Y, BYTE Steps)
{
  int type;
  void *ptr1, *ptr2, *ptr3;
  if ((type = SearchScreen (X, Y, ROTATE_TYPES, &ptr1, &ptr2,
			    &ptr3)) != NO_TYPE)
    {
      if (TEST_FLAG (LOCKFLAG, (ArcTypePtr) ptr2))
	{
	  Message (_("Sorry, the object is locked\n"));
	  return;
	}
      Crosshair.AttachedObject.RubberbandN = 0;
      if (TEST_FLAG (RUBBERBANDFLAG, PCB))
	LookupRubberbandLines (type, ptr1, ptr2, ptr3);
      if (type == ELEMENT_TYPE)
	LookupRatLines (type, ptr1, ptr2, ptr3);
      RotateObject (type, ptr1, ptr2, ptr3, X, Y, Steps);
      SetChangedFlag (True);
    }
}

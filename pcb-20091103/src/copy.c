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

/* functions used to copy pins, elements ...
 * it's necessary to copy data by calling create... since the base pointer
 * may change cause of dynamic memory allocation
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#include "global.h"

#include "copy.h"
#include "create.h"
#include "data.h"
#include "draw.h"
#include "mymem.h"
#include "mirror.h"
#include "misc.h"
#include "move.h"
#include "polygon.h"
#include "rats.h"
#include "rtree.h"
#include "select.h"
#include "undo.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");

/* ---------------------------------------------------------------------------
 * some local prototypes
 */
static void *CopyVia (PinTypePtr);
static void *CopyLine (LayerTypePtr, LineTypePtr);
static void *CopyArc (LayerTypePtr, ArcTypePtr);
static void *CopyText (LayerTypePtr, TextTypePtr);
static void *CopyPolygon (LayerTypePtr, PolygonTypePtr);
static void *CopyElement (ElementTypePtr);

/* ---------------------------------------------------------------------------
 * some local identifiers
 */
static LocationType DeltaX, DeltaY;	/* movement vector */
static ObjectFunctionType CopyFunctions = {
  CopyLine,
  CopyText,
  CopyPolygon,
  CopyVia,
  CopyElement,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  CopyArc,
  NULL
};

/* ---------------------------------------------------------------------------
 * copies data from one polygon to another
 * 'Dest' has to exist
 */
PolygonTypePtr
CopyPolygonLowLevel (PolygonTypePtr Dest, PolygonTypePtr Src)
{
  /* copy all data */
  POLYGONPOINT_LOOP (Src);
  {
    CreateNewPointInPolygon (Dest, point->X, point->Y);
  }
  END_LOOP;
  SetPolygonBoundingBox (Dest);
  Dest->Flags = Src->Flags;
  CLEAR_FLAG (FOUNDFLAG, Dest);
  return (Dest);
}

/* ---------------------------------------------------------------------------
 * copies data from one element to another and creates the destination 
 * if necessary
 */
ElementTypePtr
CopyElementLowLevel (DataTypePtr Data, ElementTypePtr Dest,
		     ElementTypePtr Src, Boolean uniqueName, LocationType dx,
		     LocationType dy)
{
  int i;
  /* release old memory if necessary */
  if (Dest)
    FreeElementMemory (Dest);

  /* both coordinates and flags are the same */
  Dest = CreateNewElement (Data, Dest, &PCB->Font,
			   MaskFlags (Src->Flags, FOUNDFLAG),
			   DESCRIPTION_NAME (Src), NAMEONPCB_NAME (Src),
			   VALUE_NAME (Src), DESCRIPTION_TEXT (Src).X + dx,
			   DESCRIPTION_TEXT (Src).Y + dy,
			   DESCRIPTION_TEXT (Src).Direction,
			   DESCRIPTION_TEXT (Src).Scale,
			   MaskFlags (DESCRIPTION_TEXT (Src).Flags,
				      FOUNDFLAG), uniqueName);

  /* abort on error */
  if (!Dest)
    return (Dest);

  ELEMENTLINE_LOOP (Src);
  {
    CreateNewLineInElement (Dest, line->Point1.X + dx,
			    line->Point1.Y + dy, line->Point2.X + dx,
			    line->Point2.Y + dy, line->Thickness);
  }
  END_LOOP;
  PIN_LOOP (Src);
  {
    CreateNewPin (Dest, pin->X + dx, pin->Y + dy, pin->Thickness,
		  pin->Clearance, pin->Mask, pin->DrillingHole,
		  pin->Name, pin->Number, MaskFlags (pin->Flags, FOUNDFLAG));
  }
  END_LOOP;
  PAD_LOOP (Src);
  {
    CreateNewPad (Dest, pad->Point1.X + dx, pad->Point1.Y + dy,
		  pad->Point2.X + dx, pad->Point2.Y + dy, pad->Thickness,
		  pad->Clearance, pad->Mask, pad->Name, pad->Number,
		  MaskFlags (pad->Flags, FOUNDFLAG));
  }
  END_LOOP;
  ARC_LOOP (Src);
  {
    CreateNewArcInElement (Dest, arc->X + dx, arc->Y + dy, arc->Width,
			   arc->Height, arc->StartAngle, arc->Delta,
			   arc->Thickness);
  }
  END_LOOP;

  for (i=0; i<Src->Attributes.Number; i++)
    CreateNewAttribute (& Dest->Attributes,
			Src->Attributes.List[i].name,
			Src->Attributes.List[i].value);

  Dest->MarkX = Src->MarkX + dx;
  Dest->MarkY = Src->MarkY + dy;

  SetElementBoundingBox (Data, Dest, &PCB->Font);
  return (Dest);
}

/* ---------------------------------------------------------------------------
 * copies a via 
 */
static void *
CopyVia (PinTypePtr Via)
{
  PinTypePtr via;

  via = CreateNewVia (PCB->Data, Via->X + DeltaX, Via->Y + DeltaY,
		      Via->Thickness, Via->Clearance, Via->Mask,
		      Via->DrillingHole, Via->Name,
		      MaskFlags (Via->Flags, FOUNDFLAG));
  if (!via)
    return (via);
  DrawVia (via, 0);
  AddObjectToCreateUndoList (VIA_TYPE, via, via, via);
  return (via);
}

/* ---------------------------------------------------------------------------
 * copies a line 
 */
static void *
CopyLine (LayerTypePtr Layer, LineTypePtr Line)
{
  LineTypePtr line;

  line = CreateDrawnLineOnLayer (Layer, Line->Point1.X + DeltaX,
				 Line->Point1.Y + DeltaY,
				 Line->Point2.X + DeltaX,
				 Line->Point2.Y + DeltaY, Line->Thickness,
				 Line->Clearance,
				 MaskFlags (Line->Flags, FOUNDFLAG));
  if (!line)
    return (line);
  if (Line->Number)
    line->Number = MyStrdup (Line->Number, "CopyLine");
  DrawLine (Layer, line, 0);
  AddObjectToCreateUndoList (LINE_TYPE, Layer, line, line);
  return (line);
}

/* ---------------------------------------------------------------------------
 * copies an arc
 */
static void *
CopyArc (LayerTypePtr Layer, ArcTypePtr Arc)
{
  ArcTypePtr arc;

  arc = CreateNewArcOnLayer (Layer, Arc->X + DeltaX,
			     Arc->Y + DeltaY, Arc->Width, Arc->Height, Arc->StartAngle,
			     Arc->Delta, Arc->Thickness, Arc->Clearance,
			     MaskFlags (Arc->Flags, FOUNDFLAG));
  if (!arc)
    return (arc);
  DrawArc (Layer, arc, 0);
  AddObjectToCreateUndoList (ARC_TYPE, Layer, arc, arc);
  return (arc);
}

/* ---------------------------------------------------------------------------
 * copies a text 
 */
static void *
CopyText (LayerTypePtr Layer, TextTypePtr Text)
{
  TextTypePtr text;

  text = CreateNewText (Layer, &PCB->Font, Text->X + DeltaX,
			Text->Y + DeltaY, Text->Direction,
			Text->Scale, Text->TextString,
			MaskFlags (Text->Flags, FOUNDFLAG));
  DrawText (Layer, text, 0);
  AddObjectToCreateUndoList (TEXT_TYPE, Layer, text, text);
  return (text);
}

/* ---------------------------------------------------------------------------
 * copies a polygon 
 */
static void *
CopyPolygon (LayerTypePtr Layer, PolygonTypePtr Polygon)
{
  PolygonTypePtr polygon;

  polygon = CreateNewPolygon (Layer, NoFlags ());
  CopyPolygonLowLevel (polygon, Polygon);
  MovePolygonLowLevel (polygon, DeltaX, DeltaY);
  if (!Layer->polygon_tree)
    Layer->polygon_tree = r_create_tree (NULL, 0, 0);
  r_insert_entry (Layer->polygon_tree, (BoxTypePtr) polygon, 0);
  InitClip (PCB->Data, Layer, polygon);
  DrawPolygon (Layer, polygon, 0);
  AddObjectToCreateUndoList (POLYGON_TYPE, Layer, polygon, polygon);
  return (polygon);
}

/* ---------------------------------------------------------------------------
 * copies a element 
 */
static void *
CopyElement (ElementTypePtr Element)
{
  Boolean didDraw = False;
  ElementTypePtr element = CopyElementLowLevel (PCB->Data,
						NULL, Element,
						TEST_FLAG (UNIQUENAMEFLAG,
							   PCB), DeltaX,
						DeltaY);

  /* this call clears the polygons */
  AddObjectToCreateUndoList (ELEMENT_TYPE, element, element, element);
  if (PCB->ElementOn && (FRONT (element) || PCB->InvisibleObjectsOn))
    {
      DrawElementName (element, 0);
      DrawElementPackage (element, 0);
      didDraw = True;
    }
  if (PCB->PinOn)
    {
      DrawElementPinsAndPads (element, 0);
      didDraw = True;
    }
  return (element);
}

/* ---------------------------------------------------------------------------
 * pastes the contents of the buffer to the layout. Only visible objects
 * are handled by the routine.
 */
Boolean
CopyPastebufferToLayout (LocationType X, LocationType Y)
{
  Cardinal i;
  Boolean changed = False;

  /* set movement vector */
  DeltaX = X - PASTEBUFFER->X, DeltaY = Y - PASTEBUFFER->Y;

  /* paste all layers */
  for (i = 0; i < max_layer + 2; i++)
    {
      LayerTypePtr sourcelayer = &PASTEBUFFER->Data->Layer[i],
	destlayer = LAYER_PTR (i);

      if (destlayer->On)
	{
	  changed = changed ||
	    (sourcelayer->LineN != 0) ||
	    (sourcelayer->ArcN != 0) ||
	    (sourcelayer->PolygonN != 0) || (sourcelayer->TextN != 0);
	  LINE_LOOP (sourcelayer);
	  {
	    CopyLine (destlayer, line);
	  }
	  END_LOOP;
	  ARC_LOOP (sourcelayer);
	  {
	    CopyArc (destlayer, arc);
	  }
	  END_LOOP;
	  TEXT_LOOP (sourcelayer);
	  {
	    CopyText (destlayer, text);
	  }
	  END_LOOP;
	  POLYGON_LOOP (sourcelayer);
	  {
	    CopyPolygon (destlayer, polygon);
	  }
	  END_LOOP;
	}
    }

  /* paste elements */
  if (PCB->PinOn && PCB->ElementOn)
    {
      ELEMENT_LOOP (PASTEBUFFER->Data);
      {
	if (FRONT (element) || PCB->InvisibleObjectsOn)
	  {
	    CopyElement (element);
	    changed = True;
	  }
      }
      END_LOOP;
    }

  /* finally the vias */
  if (PCB->ViaOn)
    {
      changed |= (PASTEBUFFER->Data->ViaN != 0);
      VIA_LOOP (PASTEBUFFER->Data);
      {
	CopyVia (via);
      }
      END_LOOP;
    }
  if (changed)
    {
      Draw ();
      IncrementUndoSerialNumber ();
    }
  return (changed);
}

/* ---------------------------------------------------------------------------
 * copies the object identified by its data pointers and the type
 * the new objects is moved by DX,DY
 * I assume that the appropriate layer ... is switched on
 */
void *
CopyObject (int Type, void *Ptr1, void *Ptr2, void *Ptr3,
	    LocationType DX, LocationType DY)
{
  void *ptr;

  /* setup movement vector */
  DeltaX = DX;
  DeltaY = DY;

  /* the subroutines add the objects to the undo-list */
  ptr = ObjectOperation (&CopyFunctions, Type, Ptr1, Ptr2, Ptr3);
  IncrementUndoSerialNumber ();
  return (ptr);
}

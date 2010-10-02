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


/* functions used by 'rubberband moves'
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include <memory.h>
#include <math.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "global.h"

#include "create.h"
#include "data.h"
#include "error.h"
#include "misc.h"
#include "polygon.h"
#include "rubberband.h"
#include "rtree.h"
#include "search.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");


/* ---------------------------------------------------------------------------
 * some local prototypes
 */
static void CheckPadForRubberbandConnection (PadTypePtr);
static void CheckPinForRubberbandConnection (PinTypePtr);
static void CheckLinePointForRubberbandConnection (LayerTypePtr,
						   LineTypePtr,
						   PointTypePtr,
						   bool);
static void CheckPolygonForRubberbandConnection (LayerTypePtr,
						 PolygonTypePtr);
static void CheckLinePointForRat (LayerTypePtr, PointTypePtr);
static int rubber_callback (const BoxType * b, void *cl);

struct rubber_info
{
  int radius;
  LocationType X, Y;
  LineTypePtr line;
  BoxType box;
  LayerTypePtr layer;
};

static int
rubber_callback (const BoxType * b, void *cl)
{
  LineTypePtr line = (LineTypePtr) b;
  struct rubber_info *i = (struct rubber_info *) cl;
  float x, y, rad, dist1, dist2;
  BDimension t;
  int touches = 0;

  t = line->Thickness / 2;

  if (TEST_FLAG (LOCKFLAG, line))
    return 0;
  if (line == i->line)
    return 0;
  /* 
   * Check to see if the line touches a rectangular region.
   * To do this we need to look for the intersection of a circular
   * region and a rectangular region.
   */
  if (i->radius == 0)
    {
      int found = 0;

      if (line->Point1.X + t >= i->box.X1 && line->Point1.X - t <= i->box.X2
	  && line->Point1.Y + t >= i->box.Y1
	  && line->Point1.Y - t <= i->box.Y2)
	{
	  if (((i->box.X1 <= line->Point1.X) &&
	       (line->Point1.X <= i->box.X2)) ||
	      ((i->box.Y1 <= line->Point1.Y) &&
	       (line->Point1.Y <= i->box.Y2)))
	    {
	      /* 
	       * The circle is positioned such that the closest point
	       * on the rectangular region boundary is not at a corner
	       * of the rectangle.  i.e. the shortest line from circle
	       * center to rectangle intersects the rectangle at 90
	       * degrees.  In this case our first test is sufficient
	       */
	      touches = 1;
	    }
	  else
	    {
	      /* 
	       * Now we must check the distance from the center of the
	       * circle to the corners of the rectangle since the
	       * closest part of the rectangular region is the corner.
	       */
	      x = MIN (abs (i->box.X1 - line->Point1.X),
		       abs (i->box.X2 - line->Point1.X));
	      x *= x;
	      y = MIN (abs (i->box.Y1 - line->Point1.Y),
		       abs (i->box.Y2 - line->Point1.Y));
	      y *= y;
	      x = x + y - (t * t);

	      if (x <= 0)
		touches = 1;
	    }
	  if (touches)
	    {
	      CreateNewRubberbandEntry (i->layer, line, &line->Point1);
	      found++;
	    }
	}
      if (line->Point2.X + t >= i->box.X1 && line->Point2.X - t <= i->box.X2
	  && line->Point2.Y + t >= i->box.Y1
	  && line->Point2.Y - t <= i->box.Y2)
	{
	  if (((i->box.X1 <= line->Point2.X) &&
	       (line->Point2.X <= i->box.X2)) ||
	      ((i->box.Y1 <= line->Point2.Y) &&
	       (line->Point2.Y <= i->box.Y2)))
	    {
	      touches = 1;
	    }
	  else
	    {
	      x = MIN (abs (i->box.X1 - line->Point2.X),
		       abs (i->box.X2 - line->Point2.X));
	      x *= x;
	      y = MIN (abs (i->box.Y1 - line->Point2.Y),
		       abs (i->box.Y2 - line->Point2.Y));
	      y *= y;
	      x = x + y - (t * t);

	      if (x <= 0)
		touches = 1;
	    }
	  if (touches)
	    {
	      CreateNewRubberbandEntry (i->layer, line, &line->Point2);
	      found++;
	    }
	}
      return found;
    }
  /* circular search region */
  if (i->radius < 0)
    rad = 0;  /* require exact match */
  else
    rad = SQUARE(i->radius + t);

  x = (i->X - line->Point1.X);
  x *= x;
  y = (i->Y - line->Point1.Y);
  y *= y;
  dist1 = x + y - rad;

  x = (i->X - line->Point2.X);
  x *= x;
  y = (i->Y - line->Point2.Y);
  y *= y;
  dist2 = x + y - rad;

  if (dist1 > 0 && dist2 > 0)
    return 0;

#ifdef CLOSEST_ONLY	/* keep this to remind me */
  if (dist1 < dist2)
    CreateNewRubberbandEntry (i->layer, line, &line->Point1);
  else
    CreateNewRubberbandEntry (i->layer, line, &line->Point2);
#else
  if (dist1 <= 0)
    CreateNewRubberbandEntry (i->layer, line, &line->Point1);
  if (dist2 <= 0)
    CreateNewRubberbandEntry (i->layer, line, &line->Point2);
#endif
  return 1;
}

/* ---------------------------------------------------------------------------
 * checks all visible lines which belong to the same layergroup as the
 * passed pad. If one of the endpoints of the line lays inside the pad,
 * the line is added to the 'rubberband' list
 */
static void
CheckPadForRubberbandConnection (PadTypePtr Pad)
{
  BDimension half = Pad->Thickness / 2;
  Cardinal i, group;
  struct rubber_info info;

  info.box.X1 = MIN (Pad->Point1.X, Pad->Point2.X) - half;
  info.box.Y1 = MIN (Pad->Point1.Y, Pad->Point2.Y) - half;
  info.box.X2 = MAX (Pad->Point1.X, Pad->Point2.X) + half;
  info.box.Y2 = MAX (Pad->Point1.Y, Pad->Point2.Y) + half;
  info.radius = 0;
  info.line = NULL;
  i = TEST_FLAG (ONSOLDERFLAG, Pad) ? solder_silk_layer : component_silk_layer;
  group = GetLayerGroupNumberByNumber (i);

  /* check all visible layers in the same group */
  GROUP_LOOP (PCB->Data, group);
  {
    /* check all visible lines of the group member */
    info.layer = layer;
    if (info.layer->On)
      {
	r_search (info.layer->line_tree, &info.box, NULL, rubber_callback,
		  &info);
      }
  }
  END_LOOP;
}

struct rinfo
{
  int type;
  Cardinal group;
  PinTypePtr pin;
  PadTypePtr pad;
  PointTypePtr point;
};

static int
rat_callback (const BoxType * box, void *cl)
{
  RatTypePtr rat = (RatTypePtr) box;
  struct rinfo *i = (struct rinfo *) cl;

  switch (i->type)
    {
    case PIN_TYPE:
      if (rat->Point1.X == i->pin->X && rat->Point1.Y == i->pin->Y)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point1);
      else if (rat->Point2.X == i->pin->X && rat->Point2.Y == i->pin->Y)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point2);
      break;
    case PAD_TYPE:
      if (rat->Point1.X == i->pad->Point1.X &&
	  rat->Point1.Y == i->pad->Point1.Y && rat->group1 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point1);
      else
	if (rat->Point2.X == i->pad->Point1.X &&
	    rat->Point2.Y == i->pad->Point1.Y && rat->group2 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point2);
      else
	if (rat->Point1.X == i->pad->Point2.X &&
	    rat->Point1.Y == i->pad->Point2.Y && rat->group1 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point1);
      else
	if (rat->Point2.X == i->pad->Point2.X &&
	    rat->Point2.Y == i->pad->Point2.Y && rat->group2 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point2);
      else
	if (rat->Point1.X == (i->pad->Point1.X + i->pad->Point2.X) / 2 &&
	    rat->Point1.Y == (i->pad->Point1.Y + i->pad->Point2.Y) / 2 &&
	    rat->group1 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point1);
      else
	if (rat->Point2.X == (i->pad->Point1.X + i->pad->Point2.X) / 2 &&
	    rat->Point2.Y == (i->pad->Point1.Y + i->pad->Point2.Y) / 2 &&
	    rat->group2 == i->group)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point2);
      break;
    case LINEPOINT_TYPE:
      if (rat->group1 == i->group &&
	  rat->Point1.X == i->point->X && rat->Point1.Y == i->point->Y)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point1);
      else
	if (rat->group2 == i->group &&
	    rat->Point2.X == i->point->X && rat->Point2.Y == i->point->Y)
	CreateNewRubberbandEntry (NULL, (LineTypePtr) rat, &rat->Point2);
      break;
    default:
      Message ("hace: bad rubber-rat lookup callback\n");
    }
  return 0;
}

static void
CheckPadForRat (PadTypePtr Pad)
{
  struct rinfo info;
  Cardinal i;

  i = TEST_FLAG (ONSOLDERFLAG, Pad) ? solder_silk_layer : component_silk_layer;
  info.group = GetLayerGroupNumberByNumber (i);
  info.pad = Pad;
  info.type = PAD_TYPE;

  r_search (PCB->Data->rat_tree, &Pad->BoundingBox, NULL, rat_callback,
	    &info);
}

static void
CheckPinForRat (PinTypePtr Pin)
{
  struct rinfo info;

  info.type = PIN_TYPE;
  info.pin = Pin;
  r_search (PCB->Data->rat_tree, &Pin->BoundingBox, NULL, rat_callback,
	    &info);
}

static void
CheckLinePointForRat (LayerTypePtr Layer, PointTypePtr Point)
{
  struct rinfo info;
  info.group = GetLayerGroupNumberByPointer (Layer);
  info.point = Point;
  info.type = LINEPOINT_TYPE;

  r_search (PCB->Data->rat_tree, (BoxType *) Point, NULL, rat_callback,
	    &info);
}

/* ---------------------------------------------------------------------------
 * checks all visible lines. If one of the endpoints of the line lays
 * inside the pin, the line is added to the 'rubberband' list
 *
 * Square pins are handled as if they were round. Speed
 * and readability is more important then the few %
 * of failures that are immediately recognized
 */
static void
CheckPinForRubberbandConnection (PinTypePtr Pin)
{
  struct rubber_info info;
  Cardinal n;
  BDimension t = Pin->Thickness / 2;

  info.box.X1 = Pin->X - t;
  info.box.X2 = Pin->X + t;
  info.box.Y1 = Pin->Y - t;
  info.box.Y2 = Pin->Y + t;
  info.line = NULL;
  if (TEST_FLAG (SQUAREFLAG, Pin))
    info.radius = 0;
  else
    {
      info.radius = t;
      info.X = Pin->X;
      info.Y = Pin->Y;
    }

  for (n = 0; n < max_copper_layer; n++)
    {
      info.layer = LAYER_PTR (n);
      r_search (info.layer->line_tree, &info.box, NULL, rubber_callback,
		&info);
    }
}

/* ---------------------------------------------------------------------------
 * checks all visible lines which belong to the same group as the passed line.
 * If one of the endpoints of the line lays * inside the passed line,
 * the scanned line is added to the 'rubberband' list
 */
static void
CheckLinePointForRubberbandConnection (LayerTypePtr Layer,
				       LineTypePtr Line,
				       PointTypePtr LinePoint,
				       bool Exact)
{
  Cardinal group;
  struct rubber_info info;
  BDimension t = Line->Thickness / 2;

  /* lookup layergroup and check all visible lines in this group */
  info.radius = Exact ? -1 : MAX(Line->Thickness / 2, 1);
  info.box.X1 = LinePoint->X - t;
  info.box.X2 = LinePoint->X + t;
  info.box.Y1 = LinePoint->Y - t;
  info.box.Y2 = LinePoint->Y + t;
  info.line = Line;
  info.X = LinePoint->X;
  info.Y = LinePoint->Y;
  group = GetLayerGroupNumberByPointer (Layer);
  GROUP_LOOP (PCB->Data, group);
  {
    /* check all visible lines of the group member */
    if (layer->On)
      {
	info.layer = layer;
	r_search (layer->line_tree, &info.box, NULL, rubber_callback, &info);
      }
  }
  END_LOOP;
}

/* ---------------------------------------------------------------------------
 * checks all visible lines which belong to the same group as the passed polygon.
 * If one of the endpoints of the line lays inside the passed polygon,
 * the scanned line is added to the 'rubberband' list
 */
static void
CheckPolygonForRubberbandConnection (LayerTypePtr Layer,
				     PolygonTypePtr Polygon)
{
  Cardinal group;

  /* lookup layergroup and check all visible lines in this group */
  group = GetLayerGroupNumberByPointer (Layer);
  GROUP_LOOP (PCB->Data, group);
  {
    if (layer->On)
      {
	BDimension thick;

	/* the following code just stupidly compares the endpoints
	 * of the lines
	 */
	LINE_LOOP (layer);
	{
	  if (TEST_FLAG (LOCKFLAG, line))
	    continue;
	  if (TEST_FLAG (CLEARLINEFLAG, line))
	    continue;
	  thick = (line->Thickness + 1) / 2;
	  if (IsPointInPolygon (line->Point1.X, line->Point1.Y,
				thick, Polygon))
	    CreateNewRubberbandEntry (layer, line, &line->Point1);
	  if (IsPointInPolygon (line->Point2.X, line->Point2.Y,
				thick, Polygon))
	    CreateNewRubberbandEntry (layer, line, &line->Point2);
	}
	END_LOOP;
      }
  }
  END_LOOP;
}

/* ---------------------------------------------------------------------------
 * lookup all lines that are connected to an object and save the
 * data to 'Crosshair.AttachedObject.Rubberband'
 * lookup is only done for visible layers
 */
void
LookupRubberbandLines (int Type, void *Ptr1, void *Ptr2, void *Ptr3)
{

  /* the function is only supported for some types
   * check all visible lines;
   * it is only necessary to check if one of the endpoints
   * is connected
   */
  switch (Type)
    {
    case ELEMENT_TYPE:
      {
	ElementTypePtr element = (ElementTypePtr) Ptr1;

	/* square pins are handled as if they are round. Speed
	 * and readability is more important then the few %
	 * of failures that are immediately recognized
	 */
	PIN_LOOP (element);
	{
	  CheckPinForRubberbandConnection (pin);
	}
	END_LOOP;
	PAD_LOOP (element);
	{
	  CheckPadForRubberbandConnection (pad);
	}
	END_LOOP;
	break;
      }

    case LINE_TYPE:
      {
	LayerTypePtr layer = (LayerTypePtr) Ptr1;
	LineTypePtr line = (LineTypePtr) Ptr2;
	if (GetLayerNumber (PCB->Data, layer) < max_copper_layer)
	  {
	    CheckLinePointForRubberbandConnection (layer, line,
						   &line->Point1, false);
	    CheckLinePointForRubberbandConnection (layer, line,
						   &line->Point2, false);
	  }
	break;
      }

    case LINEPOINT_TYPE:
      if (GetLayerNumber (PCB->Data, (LayerTypePtr) Ptr1) < max_copper_layer)
	CheckLinePointForRubberbandConnection ((LayerTypePtr) Ptr1,
					       (LineTypePtr) Ptr2,
					       (PointTypePtr) Ptr3, true);
      break;

    case VIA_TYPE:
      CheckPinForRubberbandConnection ((PinTypePtr) Ptr1);
      break;

    case POLYGON_TYPE:
      if (GetLayerNumber (PCB->Data, (LayerTypePtr) Ptr1) < max_copper_layer)
	CheckPolygonForRubberbandConnection ((LayerTypePtr) Ptr1,
					     (PolygonTypePtr) Ptr2);
      break;
    }
}

void
LookupRatLines (int Type, void *Ptr1, void *Ptr2, void *Ptr3)
{
  switch (Type)
    {
    case ELEMENT_TYPE:
      {
	ElementTypePtr element = (ElementTypePtr) Ptr1;

	PIN_LOOP (element);
	{
	  CheckPinForRat (pin);
	}
	END_LOOP;
	PAD_LOOP (element);
	{
	  CheckPadForRat (pad);
	}
	END_LOOP;
	break;
      }

    case LINE_TYPE:
      {
	LayerTypePtr layer = (LayerTypePtr) Ptr1;
	LineTypePtr line = (LineTypePtr) Ptr2;

	CheckLinePointForRat (layer, &line->Point1);
	CheckLinePointForRat (layer, &line->Point2);
	break;
      }

    case LINEPOINT_TYPE:
      CheckLinePointForRat ((LayerTypePtr) Ptr1, (PointTypePtr) Ptr3);
      break;

    case VIA_TYPE:
      CheckPinForRat ((PinTypePtr) Ptr1);
      break;
    }
}

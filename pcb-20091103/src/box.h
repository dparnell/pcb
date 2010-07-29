/* $Id$ */

/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 1994,1995,1996 Thomas Nau
 *  Copyright (C) 1998,1999,2000,2001 harry eaton
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
 *  harry eaton, 6697 Buttonhole Ct, Columbia, MD 21044 USA
 *  haceaton@aplcomm.jhuapl.edu
 *
 */

/* this file, box.h, was written and is
 * Copyright (c) 2001 C. Scott Ananian.
 */

/* random box-related utilities.
 */

#ifndef __BOX_H_INCLUDED__
#define __BOX_H_INCLUDED__

#include <assert.h>
#include "global.h"

typedef enum
{ NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NE = 4, SE = 5, SW = 6, NW =
    7, ALL = 8 } direction_t;

/* rotates box 90-degrees cw */
/* that's a strange rotation! */
#define ROTATEBOX_CW(box) { LocationType t;\
    t = (box).X1; (box).X1 = -(box).Y2; (box).Y2 = (box).X2;\
    (box).X2 = -(box).Y1; (box).Y1 = t;\
}
#define ROTATEBOX_TO_NORTH(box, dir) do { LocationType t;\
  switch(dir) {\
  case EAST: \
   t = (box).X1; (box).X1 = (box).Y1; (box).Y1 = -(box).X2;\
   (box).X2 = (box).Y2; (box).Y2 = -t; break;\
  case SOUTH: \
   t = (box).X1; (box).X1 = -(box).X2; (box).X2 = -t;\
   t = (box).Y1; (box).Y1 = -(box).Y2; (box).Y2 = -t; break;\
  case WEST: \
   t = (box).X1; (box).X1 = -(box).Y2; (box).Y2 = (box).X2;\
   (box).X2 = -(box).Y1; (box).Y1 = t; break;\
  case NORTH: break;\
  default: assert(0);\
  }\
  } while (0)
#define ROTATEBOX_FROM_NORTH(box, dir) do { LocationType t;\
  switch(dir) {\
  case WEST: \
   t = (box).X1; (box).X1 = (box).Y1; (box).Y1 = -(box).X2;\
   (box).X2 = (box).Y2; (box).Y2 = -t; break;\
  case SOUTH: \
   t = (box).X1; (box).X1 = -(box).X2; (box).X2 = -t;\
   t = (box).Y1; (box).Y1 = -(box).Y2; (box).Y2 = -t; break;\
  case EAST: \
   t = (box).X1; (box).X1 = -(box).Y2; (box).Y2 = (box).X2;\
   (box).X2 = -(box).Y1; (box).Y1 = t; break;\
  case NORTH: break;\
  default: assert(0);\
  }\
  } while (0)

/* to avoid overflow, we calculate centers this way */
#define CENTER_X(b) ((b).X1 + ((b).X2 - (b).X1)/2)
#define CENTER_Y(b) ((b).Y1 + ((b).Y2 - (b).Y1)/2)
/* some useful box utilities. */

typedef struct cheap_point
{
  LocationType X, Y;
} CheapPointType;


/* note that boxes are closed on top and left and open on bottom and right. */
/* this means that top-left corner is in box, *but bottom-right corner is
 * not*.  */
static inline Boolean
point_in_box (const BoxType * box, LocationType X, LocationType Y)
{
  return (X >= box->X1) && (Y >= box->Y1) && (X < box->X2) && (Y < box->Y2);
}

static inline Boolean
point_in_closed_box (const BoxType * box, LocationType X, LocationType Y)
{
  return (X >= box->X1) && (Y >= box->Y1) && (X <= box->X2) && (Y <= box->Y2);
}

static inline Boolean
box_is_good (const BoxType * b)
{
  return (b->X1 < b->X2) && (b->Y1 < b->Y2);
}

static inline Boolean
box_intersect (const BoxType * a, const BoxType * b)
{
  return
    (a->X1 < b->X2) && (b->X1 < a->X2) && (a->Y1 < b->Y2) && (b->Y1 < a->Y2);
}

static inline CheapPointType
closest_point_in_box (const CheapPointType * from, const BoxType * box)
{
  CheapPointType r;
  assert (box->X1 < box->X2 && box->Y1 < box->Y2);
  r.X =
    (from->X < box->X1) ? box->X1 : (from->X >
				     box->X2 - 1) ? box->X2 - 1 : from->X;
  r.Y =
    (from->Y < box->Y1) ? box->Y1 : (from->Y >
				     box->Y2 - 1) ? box->Y2 - 1 : from->Y;
  assert (point_in_box (box, r.X, r.Y));
  return r;
}

static inline Boolean
box_in_box (const BoxType * outer, const BoxType * inner)
{
  return
    (outer->X1 <= inner->X1) && (inner->X2 <= outer->X2) &&
    (outer->Y1 <= inner->Y1) && (inner->Y2 <= outer->Y2);
}

static inline BoxType
clip_box (const BoxType * box, const BoxType * clipbox)
{
  BoxType r;
  assert (box_intersect (box, clipbox));
  r.X1 = MAX (box->X1, clipbox->X1);
  r.X2 = MIN (box->X2, clipbox->X2);
  r.Y1 = MAX (box->Y1, clipbox->Y1);
  r.Y2 = MIN (box->Y2, clipbox->Y2);
  assert (box_in_box (clipbox, &r));
  return r;
}

static inline BoxType
shrink_box (const BoxType * box, LocationType amount)
{
  BoxType r = *box;
  r.X1 += amount;
  r.Y1 += amount;
  r.X2 -= amount;
  r.Y2 -= amount;
  return r;
}

static inline BoxType
bloat_box (const BoxType * box, LocationType amount)
{
  return shrink_box (box, -amount);
}

/* construct a minimum box that touches the input box at the center */
static inline BoxType
box_center (const BoxType * box)
{
  BoxType r;
  r.X1 = box->X1 + (box->X2 - box->X1)/2;
  r.X2 = r.X1 + 1;
  r.Y1 = box->Y1 + (box->Y2 - box->Y1)/2;
  r.Y2 = r.Y1 + 1;
  return r;
}

/* construct a minimum box that touches the input box at the corner */
static inline BoxType
box_corner (const BoxType * box)
{
  BoxType r;
  r.X1 = box->X1;
  r.X2 = r.X1 + 1;
  r.Y1 = box->Y1;
  r.Y2 = r.Y1 + 1;
  return r;
}

/* construct a box that holds a single point */
static inline BoxType
point_box (LocationType X, LocationType Y)
{
  BoxType r;
  r.X1 = X;
  r.X2 = X + 1;
  r.Y1 = Y;
  r.Y2 = Y + 1;
  return r;
}

/* close a bounding box by pushing its upper right corner */
static inline void
close_box (BoxType * r)
{
  r->X2++;
  r->Y2++;
}

/* return the square of the minimum distance from a point to some point
 * inside a box.  The box is half-closed!  That is, the top-left corner
 * is considered in the box, but the bottom-right corner is not. */
static inline float
dist2_to_box (const CheapPointType * p, const BoxType * b)
{
  CheapPointType r = closest_point_in_box (p, b);
  float x_dist = (r.X - p->X);
  float y_dist = (r.Y - p->Y);
  return (x_dist * x_dist) + (y_dist * y_dist);
}

#endif /* __BOX_H_INCLUDED__ */

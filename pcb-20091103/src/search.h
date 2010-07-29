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
 *  RCS: $Id$
 */

/* prototypes for search routines
 */

#ifndef	__SEARCH_INCLUDED__
#define	__SEARCH_INCLUDED__

#include "global.h"

#define SLOP 5
/* ---------------------------------------------------------------------------
 * some useful macros
 */
/* ---------------------------------------------------------------------------
 * some define to check for 'type' in box
 */
#define	POINT_IN_BOX(x,y,b)	\
	((x) >= (b)->X1 && (x) <= (b)->X2 && (y) >= (b)->Y1 && (y) <= (b)->Y2)

#define	VIA_OR_PIN_IN_BOX(v,b) \
	POINT_IN_BOX((v)->X,(v)->Y,(b))

#define	LINE_IN_BOX(l,b)	\
	(POINT_IN_BOX((l)->Point1.X,(l)->Point1.Y,(b)) &&	\
	POINT_IN_BOX((l)->Point2.X,(l)->Point2.Y,(b)))

#define	PAD_IN_BOX(p,b)	LINE_IN_BOX((LineTypePtr)(p),(b))

#define	BOX_IN_BOX(b1,b)	\
	((b1)->X1 >= (b)->X1 && (b1)->X2 <= (b)->X2 &&	\
	((b1)->Y1 >= (b)->Y1 && (b1)->Y2 <= (b)->Y2))

#define	TEXT_IN_BOX(t,b)	\
	(BOX_IN_BOX(&((t)->BoundingBox), (b)))

#define	POLYGON_IN_BOX(p,b)	\
	(BOX_IN_BOX(&((p)->BoundingBox), (b)))

#define	ELEMENT_IN_BOX(e,b)	\
	(BOX_IN_BOX(&((e)->BoundingBox), (b)))

#define ARC_IN_BOX(a,b)		\
	(BOX_IN_BOX(&((a)->BoundingBox), (b)))

/* ---------------------------------------------------------------------------
 * prototypes
 */
Boolean IsPointOnLine (float, float, float, LineTypePtr);
Boolean IsPointOnPin (float, float, float, PinTypePtr);
Boolean IsPointOnArc (float, float, float, ArcTypePtr);
Boolean IsPointOnLineEnd (LocationType, LocationType, RatTypePtr);
Boolean IsLineInRectangle (LocationType, LocationType, LocationType,
			   LocationType, LineTypePtr);
Boolean IsLineInQuadrangle (PointType p[4], LineTypePtr Line);
Boolean IsArcInRectangle (LocationType, LocationType, LocationType,
			  LocationType, ArcTypePtr);
Boolean IsPointInPad (LocationType, LocationType, BDimension, PadTypePtr);
Boolean IsPointInBox (LocationType, LocationType, BoxTypePtr, BDimension);
int SearchObjectByLocation (int, void **, void **, void **, LocationType,
			    LocationType, BDimension);
int SearchScreen (LocationType, LocationType, int, void **, void **, void **);
int SearchObjectByID (DataTypePtr, void **, void **, void **, int, int);
ElementTypePtr SearchElementByName (DataTypePtr, char *);

#endif

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

/* prototypes for transform routines
 */

#ifndef	__ROTATE_INCLUDED__
#define	__ROTATE_INCLUDED__

#include "global.h"

/* ---------------------------------------------------------------------------
 * some useful transformation macros and constants
 */
#define	ROTATE(x,y,x0,y0,n)							\
	{												\
		LocationType	dx = (x)-(x0),					\
					dy = (y)-(y0);					\
													\
		switch(n & 0x03)									\
		{											\
			case 1:		(x)=(x0)+dy; (y)=(y0)-dx;	\
						break;						\
			case 2:		(x)=(x0)-dx; (y)=(y0)-dy;	\
						break;						\
			case 3:		(x)=(x0)-dy; (y)=(y0)+dx;	\
						break;						\
			default:	break;						\
		}											\
	}
#define	ROTATE_VIA_LOWLEVEL(v,x0,y0,n)	ROTATE((v)->X,(v)->Y,(x0),(y0),(n))
#define	ROTATE_PIN_LOWLEVEL(p,x0,y0,n)	ROTATE((p)->X,(p)->Y,(x0),(y0),(n))
#define	ROTATE_PAD_LOWLEVEL(p,x0,y0,n)	\
	RotateLineLowLevel(((LineTypePtr) (p)),(x0),(y0),(n))

#define	ROTATE_TYPES	(ELEMENT_TYPE | TEXT_TYPE | ELEMENTNAME_TYPE | ARC_TYPE)


void RotateLineLowLevel (LineTypePtr, LocationType, LocationType, BYTE);
void RotateArcLowLevel (ArcTypePtr, LocationType, LocationType, BYTE);
void RotateBoxLowLevel (BoxTypePtr, LocationType, LocationType, BYTE);
void RotateTextLowLevel (TextTypePtr, LocationType, LocationType, BYTE);
void RotatePolygonLowLevel (PolygonTypePtr, LocationType, LocationType, BYTE);
void RotateElementLowLevel (DataTypePtr, ElementTypePtr, LocationType,
			    LocationType, BYTE);
void *RotateObject (int, void *, void *, void *, LocationType, LocationType,
		    BYTE);
void RotateScreenObject (LocationType, LocationType, BYTE);

#endif

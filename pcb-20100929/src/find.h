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

/* prototypes connection search routines
 */

#ifndef	__FIND_INCLUDED__
#define	__FIND_INCLUDED__

#include <stdio.h>		/* needed to define 'FILE *' */
#include "global.h"

/* ---------------------------------------------------------------------------
 * some local defines
 */
#define LOOKUP_FIRST	\
	(PIN_TYPE | PAD_TYPE)
#define LOOKUP_MORE	\
	(VIA_TYPE | LINE_TYPE | RATLINE_TYPE | POLYGON_TYPE | ARC_TYPE)
#define SILK_TYPE	\
	(LINE_TYPE | ARC_TYPE | POLYGON_TYPE)

bool LineLineIntersect (LineTypePtr, LineTypePtr);
bool LineArcIntersect (LineTypePtr, ArcTypePtr);
bool PinLineIntersect (PinTypePtr, LineTypePtr);
bool LinePadIntersect (LineTypePtr, PadTypePtr);
bool ArcPadIntersect (ArcTypePtr, PadTypePtr);
bool IsPolygonInPolygon (PolygonTypePtr, PolygonTypePtr);
void LookupElementConnections (ElementTypePtr, FILE *);
void LookupConnectionsToAllElements (FILE *);
void LookupConnection (LocationType, LocationType, bool, BDimension, int);
void LookupUnusedPins (FILE *);
void ResetFoundLinesAndPolygons (bool);
void ResetFoundPinsViasAndPads (bool);
void InitConnectionLookup (void);
void InitComponentLookup (void);
void InitLayoutLookup (void);
void FreeConnectionLookupMemory (void);
void FreeComponentLookupMemory (void);
void FreeLayoutLookupMemory (void);
void RatFindHook (int, void *, void *, void *, bool, bool);
void SaveFindFlag (int);
void RestoreFindFlag (void);
int DRCAll (void);
bool lineClear (LineTypePtr, Cardinal);
bool IsLineInPolygon (LineTypePtr, PolygonTypePtr);
bool IsArcInPolygon (ArcTypePtr, PolygonTypePtr);
bool IsPadInPolygon (PadTypePtr, PolygonTypePtr);

#endif

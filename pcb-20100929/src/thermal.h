/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 1994,1995,1996,2006 Thomas Nau
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

/* prototypes for thermal routines
 *
 * Thermals are normal lines on the layout. The only thing unique
 * about them is that they have the USETHERMALFLAG set so that they
 * can be identified as thermals. It is handy for pcb to automatically
 * make adjustments to the thermals when the user performs certain
 * operations, and the functions in thermal.h help implement that.
 */

#ifndef	__THERMAL_INCLUDED__
#define	__THERMAL_INCLUDED__

#include <stdlib.h>
#include "global.h"
#include "mymem.h"

POLYAREA * ThermPoly (PCBTypePtr, PinTypePtr, Cardinal);

#endif

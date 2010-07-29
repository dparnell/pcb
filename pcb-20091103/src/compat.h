/* $Id$ */

/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 2004 Dan McMahill
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
 */

#ifndef __COMPAT_H__
#define __COMPAT_H__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>

#ifndef HAVE_EXPF
float expf (float);
#endif

#ifndef HAVE_LOGF
float logf (float);
#endif

#ifndef HAVE_RANDOM
long random (void);
#endif

#if !defined(HAVE_DLFCN_H) && defined(WIN32)
void * dlopen (const char *, int);
void dlclose (void *);
char * dlerror (void);

void * dlsym(void *, const char *);

#define RTLD_NOW 2
#define RTLD_LOCAL 0
#define RTLD_GLOBAL 4

#endif


#endif /* __COMPAT_H__ */


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

/* this file, vector.c, was written and is
 * Copyright (c) 2001 C. Scott Ananian.
 */

/* operations on vectors.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <stdlib.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "global.h"
#include "vector.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");

/* ---------------------------------------------------------------------------
 * some local prototypes
 */

/* ---------------------------------------------------------------------------
 * some local types
 */
struct vector_struct
{
  vector_element_t *element;
  int size, max;
};

/* ---------------------------------------------------------------------------
 * some local identifiers
 */

/* ---------------------------------------------------------------------------
 * functions.
 */

/* helper function for assertions */
#ifndef NDEBUG
static int
__vector_is_good (vector_t * vector)
{
  return vector && (vector->max == 0 || vector->element) &&
    (vector->max >= 0) && (vector->size >= 0) &&
    (vector->size <= vector->max) && 1;
}
#endif /* !NDEBUG */

/* create an empty vector */
vector_t *
vector_create ()
{
  vector_t *vector;
  /* okay, create empty vector */
  vector = calloc (1, sizeof (*vector));
  assert (vector);
  assert (__vector_is_good (vector));
  return vector;
}

/* destroy a vector */
void
vector_destroy (vector_t ** vector)
{
  assert (vector && *vector);
  assert (__vector_is_good (*vector));
  if ((*vector)->element)
    free ((*vector)->element);
  free (*vector);
  *vector = NULL;
}

/* -- interrogation -- */
int
vector_is_empty (vector_t * vector)
{
  assert (__vector_is_good (vector));
  return (vector->size == 0);
}

int
vector_size (vector_t * vector)
{
  assert (__vector_is_good (vector));
  return (vector->size);
}

vector_element_t
vector_element (vector_t * vector, int N)
{
  assert (__vector_is_good (vector));
  assert (N < vector->size);
  return vector->element[N];
}

/* return the first element of the vector. */
vector_element_t
vector_element_first (vector_t * vector)
{
  assert (__vector_is_good (vector));
  assert (vector->size > 0);
  return vector_element (vector, 0);
}

/* return the last element of the vector. */
vector_element_t
vector_element_last (vector_t * vector)
{
  assert (__vector_is_good (vector));
  assert (vector->size > 0);
  return vector_element (vector, vector->size - 1);
}

/* -- mutation -- */
/* add data to end of vector */
void
vector_append (vector_t * vector, vector_element_t data)
{
  vector_insert_many (vector, vector->size, &data, 1);
}

void
vector_append_many (vector_t * vector, vector_element_t data[], int count)
{
  vector_insert_many (vector, vector->size, data, count);
}

void
vector_append_vector (vector_t * vector, vector_t * other_vector)
{
  vector_append_many (vector, other_vector->element, other_vector->size);
}

void
vector_insert (vector_t * vector, int N, vector_element_t data)
{
  vector_insert_many (vector, N, &data, 1);
}

/* add data at specified position of vector */
void
vector_insert_many (vector_t * vector, int N,
		    vector_element_t data[], int count)
{
  assert (__vector_is_good (vector));
  assert (N <= vector->size);
  if (count == 0)
    return;
  assert (data && count > 0);
  if (vector->size + count > vector->max)
    {
      vector->max = MAX (32, MAX (vector->size + count, vector->max * 2));
      vector->element = realloc (vector->element,
				 vector->max * sizeof (*vector->element));
    }
  memmove (vector->element + N + count, vector->element + N,
	   (vector->size - N) * sizeof (*vector->element));
  memmove (vector->element + N, data, count * sizeof (*data));
  vector->size += count;
  assert (__vector_is_good (vector));
}

vector_t *
vector_duplicate (vector_t * orig)
{
  vector_t * new = vector_create();
  if (!orig)
    return new;
  new->element = malloc (orig->max * sizeof (*orig->element));
  new->max = orig->max;
  new->size = orig->size;
  memcpy (new->element, orig->element, orig->size * sizeof (vector_element_t));
  assert (__vector_is_good (new));
  return new;
}

/* return and delete the *last* element of vector */
vector_element_t
vector_remove_last (vector_t * vector)
{
  assert (vector->size > 0);
  return vector_remove (vector, vector->size - 1);
}

/* return and delete data at specified position of vector */
vector_element_t
vector_remove (vector_t * vector, int N)
{
  vector_element_t old;
  assert (__vector_is_good (vector));
  assert (N < vector->size);
  old = vector->element[N];
  memmove (vector->element + N, vector->element + N + 1,
	   (vector->size - (N + 1)) * sizeof (*vector->element));
  vector->size--;
  assert (__vector_is_good (vector));
  return old;
}

/* replace the data at the specified position with the given data.
 * returns the old data. */
vector_element_t
vector_replace (vector_t * vector, vector_element_t data, int N)
{
  vector_element_t old;
  assert (__vector_is_good (vector));
  assert (N < vector->size);
  old = vector->element[N];
  vector->element[N] = data;
  assert (__vector_is_good (vector));
  return old;
}

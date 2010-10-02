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

/* this file, mtspace.c, was written and is
 * Copyright (c) 2001 C. Scott Ananian.
 * Copyright (c) 2006 harry eaton.
 */

/* implementation for "empty space" routines (needed for via-space tracking
 * in the auto-router.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "global.h"

#include <assert.h>
#include <setjmp.h>

#include "box.h"
#include "heap.h"
#include "rtree.h"
#include "mtspace.h"
#include "vector.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

#define ABS(x) ((x) < 0 ? -(x) : (x))
RCSID ("$Id$");

/* mtspace data structures are built on r-trees. */

/* ---------------------------------------------------------------------------
 * some local types
 */

typedef struct mtspacebox
{
  const BoxType box;
  BDimension keepaway;		/* the smallest keepaway around this box */
}
mtspacebox_t;

/* this is an mtspace_t */
struct mtspace
{
  /* rtrees keeping track of regions expanded by their required clearance. */
  /* one for fixed, even, and odd */
  rtree_t *ftree, *etree, *otree;
};

typedef union
{
  vector_t * v;
  heap_t * h;
} heap_or_vector;

/* this is a vetting_t */
struct vetting
{
  heap_or_vector untested;
  heap_or_vector no_fix;
  heap_or_vector no_hi;
  heap_or_vector hi_candidate;
  BDimension radius;
  BDimension keepaway;
  CheapPointType desired;
};

#define SPECIAL 823157

mtspacebox_t *
mtspace_create_box (const BoxType * box, BDimension keepaway)
{
  mtspacebox_t *mtsb;
  assert (box_is_good (box));
  mtsb = malloc (sizeof (*mtsb));
  /* the box was sent to us pre-bloated by the keepaway amount */
  *((BoxTypePtr) & mtsb->box) = *box;
  mtsb->keepaway = keepaway;
  assert (box_is_good (&mtsb->box));
  return mtsb;
}

/* create an "empty space" representation */
mtspace_t *
mtspace_create (void)
{
  mtspace_t *mtspace;

  /* create mtspace data structure */
  mtspace = malloc (sizeof (*mtspace));
  mtspace->ftree = r_create_tree (NULL, 0, 0);
  mtspace->etree = r_create_tree (NULL, 0, 0);
  mtspace->otree = r_create_tree (NULL, 0, 0);
  /* done! */
  return mtspace;
}

/* destroy an "empty space" representation. */
void
mtspace_destroy (mtspace_t ** mtspacep)
{
  assert (mtspacep);
  r_destroy_tree (&(*mtspacep)->ftree);
  r_destroy_tree (&(*mtspacep)->etree);
  r_destroy_tree (&(*mtspacep)->otree);
  free (*mtspacep);
  *mtspacep = NULL;
}

struct mts_info
{
  BDimension keepaway;
  BoxType box;
  rtree_t *tree;
  jmp_buf env;
};

static int
mts_remove_one (const BoxType * b, void *cl)
{
  struct mts_info *info = (struct mts_info *) cl;
  mtspacebox_t *box = (mtspacebox_t *) b;

  /* there can be duplicate boxes, we just remove one */
  /* the info box is pre-bloated, so just check equality */
  if (b->X1 == info->box.X1 && b->X2 == info->box.X2 &&
      b->Y1 == info->box.Y1 && b->Y2 == info->box.Y2 &&
      box->keepaway == info->keepaway)
    {
      r_delete_entry (info->tree, b);
      longjmp (info->env, 1);
    }
  return 0;
}

rtree_t *
which_tree (mtspace_t * mtspace, mtspace_type_t which)
{
  switch (which)
    {
    case FIXED:
      return mtspace->ftree;
    case EVEN:
      return mtspace->etree;
    default:
      return mtspace->otree;
    }
}

/* add a space-filler to the empty space representation.  */
void
mtspace_add (mtspace_t * mtspace, const BoxType * box, mtspace_type_t which,
	     BDimension keepaway)
{
  mtspacebox_t *filler = mtspace_create_box (box, keepaway);
  r_insert_entry (which_tree (mtspace, which), (const BoxType *) filler, 1);
}

/* remove a space-filler from the empty space representation. */
void
mtspace_remove (mtspace_t * mtspace,
		const BoxType * box, mtspace_type_t which,
		BDimension keepaway)
{
  struct mts_info cl;
  BoxType small_search;

  cl.keepaway = keepaway;
  cl.box = *box;
  cl.tree = which_tree (mtspace, which);
  small_search = box_center(box);
  if (setjmp (cl.env) == 0)
    {
      r_search (cl.tree, &small_search, NULL, mts_remove_one, &cl);
      assert (0);		/* didn't find it?? */
    }
}

struct query_closure
{
  BoxType *cbox;
  heap_or_vector checking;
  heap_or_vector touching;
  CheapPointType *desired;
  BDimension radius, keepaway;
  jmp_buf env;
  bool touch_is_vec;
};

static inline void
heap_append (heap_t *heap, CheapPointType *desired, BoxType *new)
{
  CheapPointType p = *desired;
  assert (desired);
  closest_point_in_box (&p, new);
  heap_insert (heap, ABS(p.X - desired->X) + (p.Y - desired->Y), new);
}

static inline void
append (struct query_closure * qc, BoxType *new)
{ 
  if (qc->desired)
    heap_append (qc->checking.h, qc->desired, new);
  else
    vector_append (qc->checking.v, new);
}

/* we found some space filler that may intersect this query.
 * First check if it does intersect, then break it into
 * overlaping regions that don't intersect this box.
 */
static int
query_one (const BoxType * box, void *cl)
{
  struct query_closure *qc = (struct query_closure *) cl;
  mtspacebox_t *mtsb = (mtspacebox_t *) box;
  BDimension shrink;
  assert (box_intersect (qc->cbox, &mtsb->box));
  /* we need to satisfy the larger of the two keepaways */
  if (qc->keepaway > mtsb->keepaway)
    shrink = mtsb->keepaway;
  else
    shrink = qc->keepaway;
  /* if we shrink qc->box by this amount and it doesn't intersect
   * then we didn't actually touch this box */
  if (qc->cbox->X1 + shrink >= mtsb->box.X2 ||
      qc->cbox->X2 - shrink <= mtsb->box.X1 ||
      qc->cbox->Y1 + shrink >= mtsb->box.Y2 ||
      qc->cbox->Y2 - shrink <= mtsb->box.Y1)
    return 0;
  /* ok, we do touch this box, now create up to 4 boxes that don't */
  if (mtsb->box.Y1 > qc->cbox->Y1 + shrink)	/* top region exists */
    {
      int Y1 = qc->cbox->Y1;
      int Y2 = mtsb->box.Y1 + shrink;
      if (Y2 - Y1 >= 2 * (qc->radius + qc->keepaway))
	{
	  BoxType *new = (BoxType *) malloc (sizeof (BoxType));
	  new->X1 = qc->cbox->X1;
	  new->X2 = qc->cbox->X2;
	  new->Y1 = Y1;
	  new->Y2 = Y2;
	  assert (new->Y2 < qc->cbox->Y2);
          append(qc, new);
	}
    }
  if (mtsb->box.Y2 < qc->cbox->Y2 - shrink)	/* bottom region exists */
    {
      int Y1 = mtsb->box.Y2 - shrink;
      int Y2 = qc->cbox->Y2;
      if (Y2 - Y1 >= 2 * (qc->radius + qc->keepaway))
	{
	  BoxType *new = (BoxType *) malloc (sizeof (BoxType));
	  new->X1 = qc->cbox->X1;
	  new->X2 = qc->cbox->X2;
	  new->Y2 = qc->cbox->Y2;
	  new->Y1 = Y1;
	  assert (new->Y1 > qc->cbox->Y1);
	  append (qc, new);
	}
    }
  if (mtsb->box.X1 > qc->cbox->X1 + shrink)	/* left region exists */
    {
      int X1 = qc->cbox->X1;
      int X2 = mtsb->box.X1 + shrink;
      if (X2 - X1 >= 2 * (qc->radius + qc->keepaway))
	{
	  BoxType *new;
	  new = (BoxType *) malloc (sizeof (BoxType));
	  new->Y1 = qc->cbox->Y1;
	  new->Y2 = qc->cbox->Y2;
	  new->X1 = qc->cbox->X1;
	  new->X2 = X2;
	  assert (new->X2 < qc->cbox->X2);
	  append (qc, new);
	}
    }
  if (mtsb->box.X2 < qc->cbox->X2 - shrink)	/* right region exists */
    {
      int X1 = mtsb->box.X2 - shrink;
      int X2 = qc->cbox->X2;
      if (X2 - X1 >= 2 * (qc->radius + qc->keepaway))
	{
	  BoxType *new = (BoxType *) malloc (sizeof (BoxType));
	  new->Y1 = qc->cbox->Y1;
	  new->Y2 = qc->cbox->Y2;
	  new->X2 = qc->cbox->X2;
	  new->X1 = X1;
	  assert (new->X1 > qc->cbox->X1);
	  append (qc, new);
	}
    }
  if (qc->touching.v)
    {
      if (qc->touch_is_vec || !qc->desired)
        vector_append (qc->touching.v, qc->cbox);
      else
        heap_append (qc->touching.h, qc->desired, qc->cbox);
    }
  else
    free (qc->cbox);		/* done with this one */
  longjmp (qc->env, 1);
  return 1;			/* never reached */
}

/* qloop takes a vector (or heap) of regions to check (checking) if they don't intersect
 * anything. If a region does intersect something, it is broken into
 * pieces that don't intersect that thing (if possible) which are
 * put back into the vector/heap of regions to check.
 * qloop returns false when it finds the first empty region
 * it returns true if it has exhausted the region vector/heap and never
 * found an empty area.
 */
static void
qloop (struct query_closure *qc, rtree_t * tree, heap_or_vector res, bool is_vec)
{
  BoxType *cbox;
#ifndef NDEBUG
  int n;
#endif
  while (!(qc->desired ? heap_is_empty (qc->checking.h) : vector_is_empty (qc->checking.v)))
    {
      cbox = qc->desired ? heap_remove_smallest (qc->checking.h) : vector_remove_last (qc->checking.v);
      if (setjmp (qc->env) == 0)
	{
	  assert (box_is_good (cbox));
	  qc->cbox = cbox;
#ifndef NDEBUG
	  n =
#endif
	    r_search (tree, cbox, NULL, query_one, qc);
	  assert (n == 0);
	  /* nothing intersected with this tree, put it in the result vector */
          if (is_vec)
	    vector_append (res.v, cbox);
          else
            {
              if (qc->desired)
                heap_append (res.h, qc->desired, cbox);
              else
	        vector_append (res.v, cbox);
            }
	  return;		/* found one - perhaps one answer is good enough */
	}
    }
}

/* free the memory used by the vetting structure */
void
mtsFreeWork (vetting_t ** w)
{
  vetting_t *work = (*w);
  if (work->desired.X != -SPECIAL || work->desired.Y != -SPECIAL)
    {
       heap_free (work->untested.h, free);
       heap_destroy (&work->untested.h);
       heap_free (work->no_fix.h, free);
       heap_destroy (&work->no_fix.h);
       heap_free (work->no_hi.h, free);
       heap_destroy (&work->no_hi.h);
       heap_free (work->hi_candidate.h, free);
       heap_destroy (&work->hi_candidate.h);
    }
  else
    {
       while (!vector_is_empty (work->untested.v))
         free (vector_remove_last (work->untested.v));
       vector_destroy (&work->untested.v);
       while (!vector_is_empty (work->no_fix.v))
         free (vector_remove_last (work->no_fix.v));
       vector_destroy (&work->no_fix.v);
       while (!vector_is_empty (work->no_hi.v))
         free (vector_remove_last (work->no_hi.v));
       vector_destroy (&work->no_hi.v);
       while (!vector_is_empty (work->hi_candidate.v))
         free (vector_remove_last (work->hi_candidate.v));
       vector_destroy (&work->hi_candidate.v);
    }
  free (work);
  (*w) = NULL;
}


/* returns some empty spaces in 'region' (or former narrowed regions)
 * that may hold a feature with the specified radius and keepaway
 * It tries first to find Completely empty regions (which are appended
 * to the free_space_vec vector). If that fails, it looks for regions
 * filled only by objects generated by the previous pass (which are
 * appended to the lo_conflict_space_vec vector). Then it looks for
 * regions that are filled by objects generated during *this* pass
 * (which  are appended to the hi_conflict_space_vec vector). The
 * current pass identity is given by 'is_odd'.  As soon as one completely
 * free region is found, it returns with that answer. It saves partially
 * searched regions in vectors "untested", "no_fix", "no_hi", and
 * "hi_candidate" which can be passed to future calls of this function
 * to search harder for such regions if the computation becomes
 * necessary.
 */
vetting_t *
mtspace_query_rect (mtspace_t * mtspace, const BoxType * region,
		    BDimension radius, BDimension keepaway,
		    vetting_t * work,
		    vector_t * free_space_vec,
		    vector_t * lo_conflict_space_vec,
		    vector_t * hi_conflict_space_vec,
		    bool is_odd, bool with_conflicts, CheapPointType *desired)
{
  struct query_closure qc;

  /* pre-assertions */
  assert (free_space_vec);
  assert (lo_conflict_space_vec);
  assert (hi_conflict_space_vec);
  /* search out to anything that might matter */
  if (region)
    {
      BoxType *cbox;
      assert (work == NULL);
      assert (box_is_good (region));
      assert(vector_is_empty (free_space_vec));
      assert(vector_is_empty (lo_conflict_space_vec));
      assert(vector_is_empty (hi_conflict_space_vec));
      work = (vetting_t *) malloc (sizeof (vetting_t));
      work->keepaway = keepaway;
      work->radius = radius;
      cbox = (BoxType *) malloc (sizeof (BoxType));
      *cbox = bloat_box (region, keepaway + radius);
      if (desired)
        {
          work->untested.h = heap_create ();
          work->no_fix.h = heap_create ();
          work->hi_candidate.h = heap_create ();
          work->no_hi.h =heap_create ();
          assert (work->untested.h && work->no_fix.h &&
                  work->no_hi.h && work->hi_candidate.h);
          heap_insert (work->untested.h, 0, cbox);
          work->desired = *desired;
        }
      else
        {
          work->untested.v = vector_create ();
          work->no_fix.v = vector_create ();
          work->hi_candidate.v = vector_create ();
          work->no_hi.v = vector_create ();
          assert (work->untested.v && work->no_fix.v &&
                  work->no_hi.v && work->hi_candidate.v);
          vector_append (work->untested.v, cbox);
          work->desired.X = work->desired.Y = -SPECIAL;
        }
      return work;
    }
  qc.keepaway = work->keepaway;
  qc.radius = work->radius;
  if (work->desired.X == -SPECIAL && work->desired.Y == -SPECIAL)
    qc.desired = NULL;
  else
    qc.desired = &work->desired;
  /* do the query */
  do
    {
      /* search the fixed object tree discarding any intersections
       * and placing empty regions in the no_fix vector.
       */
      qc.checking = work->untested;
      qc.touching.v = NULL;
      qloop (&qc, mtspace->ftree, work->no_fix, false);
      /* search the hi-conflict tree placing intersectors in the
       * hi_candidate vector (if conflicts are allowed) and
       * placing empty regions in the no_hi vector.
       */
      qc.checking.v = work->no_fix.v;
      qc.touching.v = with_conflicts ? work->hi_candidate.v : NULL;
      qc.touch_is_vec = false;
      qloop (&qc, is_odd ? mtspace->otree : mtspace->etree, work->no_hi, false);
      /* search the lo-conflict tree placing intersectors in the
       * lo-conflict answer vector (if conflicts allowed) and
       * placing emptry regions in the free-space answer vector.
       */
      qc.checking = work->no_hi;
/* XXX lo_conflict_space_vec will be treated like a heap! */
      qc.touching.v = (with_conflicts ? lo_conflict_space_vec : NULL);
      qc.touch_is_vec = true;
      qloop (&qc, is_odd ? mtspace->etree : mtspace->otree, (heap_or_vector)free_space_vec, true);
      if (!vector_is_empty (free_space_vec))
	{
	  if (qc.desired)
          {
            if (heap_is_empty (work->untested.h))
              break;
          }
          else
          {
            if (vector_is_empty (work->untested.v))
	      break;
          }
	  return work;
	}
      /* finally check the hi-conflict intersectors against the
       * lo-conflict tree discarding intersectors (two types of conflict is real bad)
       * and placing empty regions in the hi-conflict answer vector.
       */
      if (with_conflicts)
	{
	  qc.checking = work->hi_candidate;
	  qc.touching.v = NULL;
	  qloop (&qc, is_odd ? mtspace->etree : mtspace->otree,
		 (heap_or_vector)hi_conflict_space_vec, true);
	}
    }
  while (!(qc.desired ? heap_is_empty(work->untested.h) : vector_is_empty (work->untested.v)));
  if (qc.desired)
    {
      if (heap_is_empty (work->no_fix.h) &&
          heap_is_empty (work->no_hi.h) &&
          heap_is_empty (work->hi_candidate.h))
       {
          mtsFreeWork (&work);
          return NULL;
       }
    }
  else
    {
      if (vector_is_empty (work->no_fix.v) &&
          vector_is_empty (work->no_hi.v) && vector_is_empty (work->hi_candidate.v))
        {
          mtsFreeWork (&work);
          return NULL;
        }
     }
  return work;
}

int
mtsBoxCount (vetting_t * w)
{
#if 0
  int ans;
  ans = 3 * vector_size (w->untested);
  ans += 2 * vector_size (w->no_fix);
  ans += vector_size (w->no_hi);
  ans += vector_size (w->hi_candidate);
  return ans;
#endif
  return 100;
}

/* $Id$ */

/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 1994,1995,1996, 2005 Thomas Nau
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

/* generic netlist operations
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include <ctype.h>
#include <sys/types.h>
#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#include "global.h"
#include "action.h"
#include "buffer.h"
#include "command.h"
#include "data.h"
#include "djopt.h"
#include "error.h"
#include "file.h"
#include "find.h"
#include "mymem.h"
#include "misc.h"
#include "rats.h"
#include "set.h"
#include "vendor.h"

#ifdef HAVE_REGCOMP
#undef HAVE_RE_COMP
#endif

#if defined(HAVE_REGCOMP) || defined(HAVE_RE_COMP)
#define USE_RE
#endif

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");

/*
  int    PCB->NetlistLib.MenuN
  char * PCB->NetlistLib.Menu[i].Name
     [0] == '*' (ok for rats) or ' ' (skip for rats)
     [1] == unused
     [2..] actual name
  char * PCB->NetlistLib.Menu[i].Style
  int    PCB->NetlistLib.Menu[i].EntryN
  char * PCB->NetlistLib.Menu[i].Entry[j].ListEntry
*/

typedef void (*NFunc) (LibraryMenuType *, LibraryEntryType *);

LibraryMenuTypePtr
netnode_to_netname (char *nodename)
{
  int i, j;
  /*printf("nodename [%s]\n", nodename);*/
  for (i=0; i<PCB->NetlistLib.MenuN; i++)
    {
      for (j=0; j<PCB->NetlistLib.Menu[i].EntryN; j++)
	{
	  if (strcmp (PCB->NetlistLib.Menu[i].Entry[j].ListEntry, nodename) == 0)
	    {
	      /*printf(" in [%s]\n", PCB->NetlistLib.Menu[i].Name);*/
	      return & (PCB->NetlistLib.Menu[i]);
	    }
	}
    }
  return 0;
}

LibraryMenuTypePtr
netname_to_netname (char *netname)
{
  int i;

  if ((netname[0] == '*' || netname[0] == ' ') && netname[1] == ' ')
    {
      /* Looks like we were passed an internal netname, skip the prefix */
      netname += 2;
    }
  for (i=0; i<PCB->NetlistLib.MenuN; i++)
    {
      if (strcmp (PCB->NetlistLib.Menu[i].Name + 2, netname) == 0)
	{
	  return & (PCB->NetlistLib.Menu[i]);
	}
    }
  return 0;
}

static int
pin_name_to_xy (LibraryEntryType * pin, int *x, int *y)
{
  ConnectionType conn;
  if (!SeekPad (pin, &conn, False))
    return 1;
  switch (conn.type)
    {
    case PIN_TYPE:
      *x = ((PinType *) (conn.ptr2))->X;
      *y = ((PinType *) (conn.ptr2))->Y;
      return 0;
    case PAD_TYPE:
      *x = ((PadType *) (conn.ptr2))->Point1.X;
      *y = ((PadType *) (conn.ptr2))->Point1.Y;
      return 0;
    }
  return 1;
}

static void
netlist_find (LibraryMenuType * net, LibraryEntryType * pin)
{
  int x, y;
  if (pin_name_to_xy (net->Entry, &x, &y))
    return;
  LookupConnection (x, y, 1, 1, FOUNDFLAG);
}

static void
netlist_select (LibraryMenuType * net, LibraryEntryType * pin)
{
  int x, y;
  if (pin_name_to_xy (net->Entry, &x, &y))
    return;
  LookupConnection (x, y, 1, 1, SELECTEDFLAG);
}

static void
netlist_rats (LibraryMenuType * net, LibraryEntryType * pin)
{
  net->Name[0] = ' ';
  net->flag = 1;
  hid_action ("NetlistChanged");
}

static void
netlist_norats (LibraryMenuType * net, LibraryEntryType * pin)
{
  net->Name[0] = '*';
  net->flag = 0;
  hid_action ("NetlistChanged");
}


static const char netlist_syntax[] =
  "Net(find|select|rats|norats[,net[,pin]])";

static const char netlist_help[] = "Perform various actions on netlists.";

/* %start-doc actions Netlist

Each of these actions apply to a specified set of nets.  @var{net} and
@var{pin} are patterns which match one or more nets or pins; these
patterns may be full names or regular expressions.  If an exact match
is found, it is the only match; if no exact match is found,
@emph{then} the pattern is tried as a regular expression.

If neither @var{net} nor @var{pin} are specified, all nets apply.  If
@var{net} is specified but not @var{pin}, all nets matching @var{net}
apply.  If both are specified, nets which match @var{net} and contain
a pin matching @var{pin} apply.

@table @code

@item find
Nets which apply are marked @emph{found} and are drawn in the
@code{connected-color} color.

@item select
Nets which apply are selected.

@item rats
Nets which apply are marked as available for the rats nest.

@item norats
Nets which apply are marked as not available for the rats nest.

@end table

%end-doc */

static int
Netlist (int argc, char **argv, int x, int y)
{
  NFunc func;
  int i, j;
  LibraryMenuType *net;
  LibraryEntryType *pin;
  int net_found = 0;
  int pin_found = 0;
#if defined(USE_RE)
  int use_re = 0;
#endif
#if defined(HAVE_REGCOMP)
  regex_t elt_pattern;
  regmatch_t match;
#endif
#if defined(HAVE_RE_COMP)
  char *elt_pattern;
#endif

  if (!PCB)
    return 1;
  if (argc == 0)
    {
      Message (netlist_syntax);
      return 1;
    }
  if (strcasecmp (argv[0], "find") == 0)
    func = netlist_find;
  else if (strcasecmp (argv[0], "select") == 0)
    func = netlist_select;
  else if (strcasecmp (argv[0], "rats") == 0)
    func = netlist_rats;
  else if (strcasecmp (argv[0], "norats") == 0)
    func = netlist_norats;
  else
    {
      Message (netlist_syntax);
      return 1;
    }

#if defined(USE_RE)
  if (argc > 1)
    {
      int result;
      use_re = 1;
      for (i = 0; i < PCB->NetlistLib.MenuN; i++)
	{
	  net = PCB->NetlistLib.Menu + i;
	  if (strcasecmp (argv[1], net->Name + 2) == 0)
	    use_re = 0;
	}
      if (use_re)
	{
#if defined(HAVE_REGCOMP)
	  result =
	    regcomp (&elt_pattern, argv[1],
		     REG_EXTENDED | REG_ICASE | REG_NOSUB);
	  if (result)
	    {
	      char errorstring[128];

	      regerror (result, &elt_pattern, errorstring, 128);
	      Message (_("regexp error: %s\n"), errorstring);
	      regfree (&elt_pattern);
	      return (1);
	    }
#endif
#if defined(HAVE_RE_COMP)
	  if ((elt_pattern = re_comp (argv[1])) != NULL)
	    {
	      Message (_("re_comp error: %s\n"), elt_pattern);
	      return (False);
	    }
#endif
	}
    }
#endif

  for (i = 0; i < PCB->NetlistLib.MenuN; i++)
    {
      net = PCB->NetlistLib.Menu + i;

      if (argc > 1)
	{
#if defined(USE_RE)
	  if (use_re)
	    {
#if defined(HAVE_REGCOMP)
	      if (regexec (&elt_pattern, net->Name + 2, 1, &match, 0) != 0)
		continue;
#endif
#if defined(HAVE_RE_COMP)
	      if (re_exec (net->Name + 2) != 1)
		continue;
#endif
	    }
	  else
#endif
	  if (strcasecmp (net->Name + 2, argv[1]))
	    continue;
	}
      net_found = 1;

      pin = 0;
      if (argc > 2)
	{
	  int l = strlen (argv[2]);
	  for (j = 0; j < net->EntryN; j++)
	    if (strcasecmp (net->Entry[j].ListEntry, argv[2]) == 0
		|| (strncasecmp (net->Entry[j].ListEntry, argv[2], l) == 0
		    && net->Entry[j].ListEntry[l] == '-'))
	      {
		pin = net->Entry + j;
		pin_found = 1;
		func (net, pin);
	      }
	}
      else
	func (net, 0);
    }

  if (argc > 2 && !pin_found)
    {
      gui->log ("Net %s has no pin %s\n", argv[1], argv[2]);
      return 1;
    }
  else if (!net_found)
    {
      gui->log ("No net named %s\n", argv[1]);
    }
#ifdef HAVE_REGCOMP
  if (use_re)
    regfree (&elt_pattern);
#endif

  return 0;
}

HID_Action netlist_action_list[] = {
  {"net", 0, Netlist,
   netlist_help, netlist_syntax}
  ,
  {"netlist", 0, Netlist,
   netlist_help, netlist_syntax}
};

REGISTER_ACTIONS (netlist_action_list)

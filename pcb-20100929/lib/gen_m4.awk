#!/usr/bin/awk -f
#
# $Id$
#
#                            COPYRIGHT
#
#   PCB, interactive printed circuit board design
#   Copyright (C) 2003 Dan McMahill
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
# 
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
# 
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# Script to regenerate *.m4 from *.inc
#
# Usage:
#
#  awk -f gen_m4.awk name=foo foo.inc > foo.m4
#

BEGIN {
	printf("divert(-1)\n");
	printf("#\n");
	printf("# NOTE: Auto-generated. Do not change.\n");
	printf("#");
	do_process = 0;
}

/^\#[ \t]*EXTRACT_BEGIN/ {
  do_process = 1;
}

/^\#[ \t]*EXTRACT_END/ {
  do_process = 0;
}

do_process == 0 {
  next;
}

/^\#\#/ {
	descr = $0;
	ind = index(descr, $2);
	descr = substr(descr, ind);
	printf("#\n");
	next;
}


/^[ \t]*define/ {
	pkg = $1;
	ind = index(pkg, "PKG");
	pkg = substr(pkg, ind+4);
	ind = index(pkg, "'");
	pkg = substr(pkg, 1, ind-1);
	printf("define(`Description_%s_%s',\t``%s'')\n", name, pkg, descr);
}

END {
	printf("divert(0)dnl\n");
}


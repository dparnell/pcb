#!/bin/sh
#
#                             COPYRIGHT
# 
#   PCB, interactive printed circuit board design
#   Copyright (C) 1994,1995,1996 Thomas Nau
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
#   Contact addresses for paper mail and Email:
#   Thomas Nau, Schlehenweg 15, 88471 Baustetten, Germany
#   Thomas.Nau@rz.uni-ulm.de
# 
#   RCS: $Id: ListLibraryContents.sh,v 1.1.1.1 2003/02/20 00:23:19 danmc Exp $
#
# list the contents of a library
#
# usage: ListLibraryContents.sh [path] file

Usage()
{
	echo "usage: $0 [path] file" >&2
	exit 1
}

SearchPath=.
case $# in
	1)	File="$1";;
	2)	SearchPath=`echo "$1" | tr ':' ' '`; File="$2";;
	*)	Usage;;
esac

for dir in $SearchPath; do
	name=$dir/$File.contents
	if [ -r $name ]; then
		cat $name
	fi
done

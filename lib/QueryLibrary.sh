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
#   RCS: $Id: QueryLibrary.sh.in,v 1.3 2006/03/14 02:33:54 danmc Exp $
#
# query a library
#
# usage: QueryLibrary.sh template value package

M4=/usr/bin/m4

Usage()
{
	echo "usage: $0 [-fp] [path] library template value package" >&2
	echo "      If given, the -fp flag returns the correct value for" >&2
	echo "      the gschem footprint= attribute" >&2
	exit 1
}

Fn=CreateObject
if test $1 = "-fp" ; then
	Fn=QueryObject
	shift
fi

SearchPath=.
case $# in
	4)  ;;
	5)  SearchPath=`echo "$1" | tr ':' ' '`; shift;;
	*)  Usage;;
esac
Library="$1"
Template="$2"
Value="$3"
Package="$4"

PATH=$PATH:`dirname $0`

for dir in $SearchPath; do
	name=$dir/$Library
	if [ -r $name ]; then
		echo "${Fn}(\`$Template', \`$Value', \`$Package')" |
			PATH=${SearchPath}:$PATH $M4 -R $name - |
			awk '/^[ \t]*$/ {next} {print}' 
		exit
	fi
done

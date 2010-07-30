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
#   RCS: $Id: CreateLibrary.sh.in,v 1.1.1.1 2003/02/20 00:23:19 danmc Exp $
#
# creates a library
#
# usage: CreateContents.sh library common_macro_file file...

M4=/opt/local/bin/gm4

while test -n "$1" ; do
case "$1"
in
    -I|--include)
	m4_flags="$m4_flags -I $2"
	shift 2
	;;

    -*)
	echo "error:  unknown flag $1 to $0"
	exit 1
	;;
	
    *)
	break
	;;
esac
done

if [ $# -lt 3 ]; then
	echo "usage: $0 library common_macro_file file..." >&2; exit 1
fi
Library=$1
CommonFile=$2
shift; shift

if [ ! -r $CommonFile ]; then
	echo "$0: file '$CommonFile' isn't readable or doesn't exit" >&2; exit 1
fi

echo "$M4 $m4_flags -F $Library $CommonFile $@"
$M4 $m4_flags -F $Library $CommonFile $@

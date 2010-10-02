
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     CHAR_CONST = 259,
     FLOAT = 260,
     STRING = 261,
     T_FILEVERSION = 262,
     T_PCB = 263,
     T_LAYER = 264,
     T_VIA = 265,
     T_RAT = 266,
     T_LINE = 267,
     T_ARC = 268,
     T_RECTANGLE = 269,
     T_TEXT = 270,
     T_ELEMENTLINE = 271,
     T_ELEMENT = 272,
     T_PIN = 273,
     T_PAD = 274,
     T_GRID = 275,
     T_FLAGS = 276,
     T_SYMBOL = 277,
     T_SYMBOLLINE = 278,
     T_CURSOR = 279,
     T_ELEMENTARC = 280,
     T_MARK = 281,
     T_GROUPS = 282,
     T_STYLES = 283,
     T_POLYGON = 284,
     T_POLYGON_HOLE = 285,
     T_NETLIST = 286,
     T_NET = 287,
     T_CONN = 288,
     T_AREA = 289,
     T_THERMAL = 290,
     T_DRC = 291,
     T_ATTRIBUTE = 292
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define CHAR_CONST 259
#define FLOAT 260
#define STRING 261
#define T_FILEVERSION 262
#define T_PCB 263
#define T_LAYER 264
#define T_VIA 265
#define T_RAT 266
#define T_LINE 267
#define T_ARC 268
#define T_RECTANGLE 269
#define T_TEXT 270
#define T_ELEMENTLINE 271
#define T_ELEMENT 272
#define T_PIN 273
#define T_PAD 274
#define T_GRID 275
#define T_FLAGS 276
#define T_SYMBOL 277
#define T_SYMBOLLINE 278
#define T_CURSOR 279
#define T_ELEMENTARC 280
#define T_MARK 281
#define T_GROUPS 282
#define T_STYLES 283
#define T_POLYGON 284
#define T_POLYGON_HOLE 285
#define T_NETLIST 286
#define T_NET 287
#define T_CONN 288
#define T_AREA 289
#define T_THERMAL 290
#define T_DRC 291
#define T_ATTRIBUTE 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 92 "parse_y.y"

	int		number;
	float		floating;
	char		*string;
	FlagType	flagtype;



/* Line 1676 of yacc.c  */
#line 135 "parse_y.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



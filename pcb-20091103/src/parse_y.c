/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     T_NETLIST = 285,
     T_NET = 286,
     T_CONN = 287,
     T_AREA = 288,
     T_THERMAL = 289,
     T_DRC = 290,
     T_ATTRIBUTE = 291
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
#define T_NETLIST 285
#define T_NET 286
#define T_CONN 287
#define T_AREA 288
#define T_THERMAL 289
#define T_DRC 290
#define T_ATTRIBUTE 291




/* Copy the first part of user declarations.  */
#line 11 "parse_y.y"

/*
 *                            COPYRIGHT
 *
 *  PCB, interactive printed circuit board design
 *  Copyright (C) 1994,1995,1996 Thomas Nau
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

/* grammar to parse ASCII input of PCB description
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define GRIDFIT(x,g) (int)(0.5 + (int)(((x)+(g)/2.)/(g))*(g))
#include "global.h"
#include "create.h"
#include "data.h"
#include "error.h"
#include "file.h"
#include "mymem.h"
#include "misc.h"
#include "parse_l.h"
#include "polygon.h"
#include "remove.h"
#include "rtree.h"
#include "strflags.h"
#include "thermal.h"

#ifdef HAVE_LIBDMALLOC
# include <dmalloc.h> /* see http://dmalloc.com */
#endif

RCSID("$Id$");

static	LayerTypePtr	Layer;
static	PolygonTypePtr	Polygon;
static	SymbolTypePtr	Symbol;
static	int		pin_num;
static	LibraryMenuTypePtr	Menu;
static	Boolean			LayerFlag[MAX_LAYER + 2];

extern	char			*yytext;		/* defined by LEX */
extern	PCBTypePtr		yyPCB;
extern	DataTypePtr		yyData;
extern	ElementTypePtr	yyElement;
extern	FontTypePtr		yyFont;
extern	int				yylineno;		/* linenumber */
extern	char			*yyfilename;	/* in this file */

static char *layer_group_string; 

static AttributeListTypePtr attr_list; 

int yyerror(const char *s);
int yylex();
static int check_file_version (int);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 92 "parse_y.y"
{
	int		number;
	float		floating;
	char		*string;
	FlagType	flagtype;
}
/* Line 187 of yacc.c.  */
#line 255 "parse_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 268 "parse_y.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNRULES -- Number of states.  */
#define YYNSTATES  609

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    12,    27,    28,
      31,    32,    35,    37,    38,    39,    42,    43,    48,    53,
      60,    67,    69,    71,    73,    75,    82,    90,    98,   106,
     113,   120,   127,   128,   129,   134,   135,   140,   141,   143,
     145,   147,   154,   162,   172,   177,   182,   183,   188,   189,
     194,   199,   200,   202,   203,   205,   208,   210,   211,   214,
     216,   218,   219,   222,   224,   226,   228,   230,   232,   234,
     246,   258,   269,   279,   288,   299,   310,   311,   322,   324,
     325,   327,   330,   332,   334,   336,   338,   340,   342,   351,
     353,   355,   357,   358,   361,   362,   371,   382,   393,   403,
     416,   429,   441,   450,   460,   470,   472,   475,   480,   485,
     486,   488,   490,   492,   494,   496,   497,   510,   511,   527,
     528,   545,   546,   565,   566,   585,   587,   590,   592,   594,
     596,   598,   600,   609,   618,   629,   640,   646,   652,   653,
     656,   658,   661,   663,   665,   667,   669,   678,   687,   698,
     709,   710,   713,   726,   739,   750,   760,   769,   783,   797,
     809,   820,   822,   824,   826,   829,   830,   840,   841,   851,
     853,   855,   857,   860,   862,   864,   865,   874,   883,   885,
     886,   893,   895,   896,   898,   901,   902,   912,   914,   915,
     917,   920,   925,   927,   930,   936,   938
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    46,    -1,    49,    -1,     1,
      -1,    -1,    44,    51,    52,    53,    58,    59,    60,    61,
      65,    66,    67,    48,    68,   134,    -1,    -1,    45,    98,
      -1,    -1,    47,    68,    -1,    49,    -1,    -1,    -1,    50,
     125,    -1,    -1,     7,    37,     3,    38,    -1,     8,    39,
       6,    40,    -1,     8,    39,     6,     3,     3,    40,    -1,
       8,    37,     6,     3,     3,    38,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    20,    39,     3,     3,     3,
      40,    -1,    20,    39,     3,     3,     3,     3,    40,    -1,
      20,    39,     5,     3,     3,     3,    40,    -1,    20,    37,
       5,     3,     3,     3,    38,    -1,    24,    39,     3,     3,
       3,    40,    -1,    24,    37,     3,     3,     3,    38,    -1,
      24,    37,     3,     3,     5,    38,    -1,    -1,    -1,    33,
      37,     5,    38,    -1,    -1,    34,    37,     5,    38,    -1,
      -1,    62,    -1,    63,    -1,    64,    -1,    35,    37,     3,
       3,     3,    38,    -1,    35,    37,     3,     3,     3,     3,
      38,    -1,    35,    37,     3,     3,     3,     3,     3,     3,
      38,    -1,    21,    39,     3,    40,    -1,    21,    39,     6,
      40,    -1,    -1,    27,    39,     6,    40,    -1,    -1,    28,
      39,     6,    40,    -1,    28,    37,     6,    38,    -1,    -1,
      69,    -1,    -1,    70,    -1,    69,    70,    -1,    73,    -1,
      -1,    71,   143,    -1,    79,    -1,    80,    -1,    -1,    72,
      98,    -1,     1,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    10,    37,     3,     3,     3,     3,
       3,     3,     6,   124,    38,    -1,    10,    39,     3,     3,
       3,     3,     3,     3,     6,     3,    40,    -1,    10,    39,
       3,     3,     3,     3,     3,     6,     3,    40,    -1,    10,
      39,     3,     3,     3,     3,     6,     3,    40,    -1,    10,
      39,     3,     3,     3,     6,     3,    40,    -1,    11,    37,
       3,     3,     3,     3,     3,     3,   124,    38,    -1,    11,
      39,     3,     3,     3,     3,     3,     3,     3,    40,    -1,
      -1,     9,    39,     3,     6,   145,    40,    39,    81,    82,
      40,    -1,    83,    -1,    -1,    84,    -1,    83,    84,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    14,    39,     3,     3,     3,     3,     3,    40,
      -1,    95,    -1,    94,    -1,    93,    -1,    -1,    85,   143,
      -1,    -1,    29,    39,   124,    40,    39,    86,    96,    40,
      -1,    12,    37,     3,     3,     3,     3,     3,     3,   124,
      38,    -1,    12,    39,     3,     3,     3,     3,     3,     3,
       3,    40,    -1,    12,    39,     3,     3,     3,     3,     3,
       3,    40,    -1,    13,    37,     3,     3,     3,     3,     3,
       3,     3,     3,   124,    38,    -1,    13,    39,     3,     3,
       3,     3,     3,     3,     3,     3,     3,    40,    -1,    13,
      39,     3,     3,     3,     3,     3,     3,     3,     3,    40,
      -1,    15,    39,     3,     3,     3,     6,     3,    40,    -1,
      15,    39,     3,     3,     3,     3,     6,     3,    40,    -1,
      15,    37,     3,     3,     3,     3,     6,   124,    38,    -1,
      97,    -1,    96,    97,    -1,    39,     3,     3,    40,    -1,
      37,     3,     3,    38,    -1,    -1,    99,    -1,   101,    -1,
     103,    -1,   105,    -1,   107,    -1,    -1,    17,    39,     6,
       6,     3,     3,     3,    40,    39,   100,   109,    40,    -1,
      -1,    17,    39,     3,     6,     6,     3,     3,     3,     3,
       3,    40,    39,   102,   109,    40,    -1,    -1,    17,    39,
       3,     6,     6,     6,     3,     3,     3,     3,     3,    40,
      39,   104,   109,    40,    -1,    -1,    17,    39,     3,     6,
       6,     6,     3,     3,     3,     3,     3,     3,     3,    40,
      39,   106,   112,    40,    -1,    -1,    17,    37,   124,     6,
       6,     6,     3,     3,     3,     3,     3,     3,   124,    38,
      39,   108,   112,    40,    -1,   110,    -1,   109,   110,    -1,
     117,    -1,   118,    -1,   119,    -1,   122,    -1,   123,    -1,
      16,    37,     3,     3,     3,     3,     3,    38,    -1,    16,
      39,     3,     3,     3,     3,     3,    40,    -1,    25,    37,
       3,     3,     3,     3,     3,     3,     3,    38,    -1,    25,
      39,     3,     3,     3,     3,     3,     3,     3,    40,    -1,
      26,    37,     3,     3,    38,    -1,    26,    39,     3,     3,
      40,    -1,    -1,   111,   143,    -1,   113,    -1,   112,   113,
      -1,   116,    -1,   115,    -1,   121,    -1,   120,    -1,    16,
      37,     3,     3,     3,     3,     3,    38,    -1,    16,    39,
       3,     3,     3,     3,     3,    40,    -1,    25,    37,     3,
       3,     3,     3,     3,     3,     3,    38,    -1,    25,    39,
       3,     3,     3,     3,     3,     3,     3,    40,    -1,    -1,
     114,   143,    -1,    18,    37,     3,     3,     3,     3,     3,
       3,     6,     6,   124,    38,    -1,    18,    39,     3,     3,
       3,     3,     3,     3,     6,     6,     3,    40,    -1,    18,
      39,     3,     3,     3,     3,     6,     6,     3,    40,    -1,
      18,    39,     3,     3,     3,     3,     6,     3,    40,    -1,
      18,    39,     3,     3,     3,     6,     3,    40,    -1,    19,
      37,     3,     3,     3,     3,     3,     3,     3,     6,     6,
     124,    38,    -1,    19,    39,     3,     3,     3,     3,     3,
       3,     3,     6,     6,     3,    40,    -1,    19,    39,     3,
       3,     3,     3,     3,     6,     6,     3,    40,    -1,    19,
      39,     3,     3,     3,     3,     3,     6,     3,    40,    -1,
       3,    -1,     6,    -1,   126,    -1,   125,   126,    -1,    -1,
      22,    37,   129,     3,    38,    39,   127,   130,    40,    -1,
      -1,    22,    39,   129,     3,    40,    39,   128,   130,    40,
      -1,     3,    -1,     4,    -1,   131,    -1,   130,   131,    -1,
     132,    -1,   133,    -1,    -1,    23,    39,     3,     3,     3,
       3,     3,    40,    -1,    23,    37,     3,     3,     3,     3,
       3,    38,    -1,   135,    -1,    -1,    30,    39,    40,    39,
     136,    40,    -1,   137,    -1,    -1,   138,    -1,   137,   138,
      -1,    -1,    31,    39,     6,     6,    40,    39,   139,   140,
      40,    -1,   141,    -1,    -1,   142,    -1,   141,   142,    -1,
      32,    39,     6,    40,    -1,   144,    -1,   143,   144,    -1,
      36,    39,     6,     6,    40,    -1,     6,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   116,   117,   118,   142,   142,   196,   196,
     207,   207,   226,   227,   232,   232,   271,   273,   305,   311,
     317,   346,   347,   348,   349,   352,   360,   373,   385,   417,
     423,   429,   435,   451,   453,   477,   479,   510,   512,   513,
     514,   518,   528,   539,   566,   570,   574,   602,   606,   650,
     658,   666,   670,   671,   675,   676,   680,   681,   681,   682,
     683,   685,   685,   692,   696,   697,   698,   699,   700,   736,
     745,   756,   766,   776,   812,   817,   849,   848,   872,   873,
     877,   878,   882,   883,   884,   885,   886,   887,   889,   894,
     895,   896,   897,   897,   900,   899,   952,   960,   969,  1017,
    1025,  1034,  1071,  1081,  1099,  1140,  1141,  1146,  1150,  1154,
    1211,  1212,  1213,  1214,  1215,  1223,  1222,  1241,  1240,  1259,
    1258,  1279,  1277,  1300,  1298,  1378,  1379,  1383,  1384,  1385,
    1386,  1387,  1389,  1394,  1399,  1404,  1409,  1414,  1419,  1419,
    1423,  1424,  1428,  1429,  1430,  1431,  1433,  1439,  1446,  1451,
    1456,  1456,  1497,  1509,  1521,  1532,  1548,  1602,  1616,  1629,
    1640,  1651,  1652,  1656,  1657,  1681,  1680,  1698,  1697,  1717,
    1718,  1722,  1723,  1727,  1728,  1729,  1750,  1757,  1773,  1774,
    1778,  1783,  1784,  1788,  1789,  1812,  1811,  1821,  1822,  1826,
    1827,  1846,  1875,  1876,  1879,  1887,  1888
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "CHAR_CONST", "FLOAT",
  "STRING", "T_FILEVERSION", "T_PCB", "T_LAYER", "T_VIA", "T_RAT",
  "T_LINE", "T_ARC", "T_RECTANGLE", "T_TEXT", "T_ELEMENTLINE", "T_ELEMENT",
  "T_PIN", "T_PAD", "T_GRID", "T_FLAGS", "T_SYMBOL", "T_SYMBOLLINE",
  "T_CURSOR", "T_ELEMENTARC", "T_MARK", "T_GROUPS", "T_STYLES",
  "T_POLYGON", "T_NETLIST", "T_NET", "T_CONN", "T_AREA", "T_THERMAL",
  "T_DRC", "T_ATTRIBUTE", "'['", "']'", "'('", "')'", "$accept", "parse",
  "parsepcb", "@1", "@2", "parsedata", "@3", "pcbfont", "parsefont", "@4",
  "pcbfileversion", "pcbname", "pcbgrid", "pcbgridold", "pcbgridnew",
  "pcb2grid", "pcbhigrid", "pcbcursor", "polyarea", "pcbthermal", "pcbdrc",
  "pcbdrc1", "pcbdrc2", "pcbdrc3", "pcbflags", "pcbgroups", "pcbstyles",
  "pcbdata", "pcbdefinitions", "pcbdefinition", "@5", "@6", "via",
  "via_hi_format", "via_2.0_format", "via_1.7_format", "via_newformat",
  "via_oldformat", "rats", "layer", "@7", "layerdata", "layerdefinitions",
  "layerdefinition", "@8", "@9", "line_hi_format", "line_1.7_format",
  "line_oldformat", "arc_hi_format", "arc_1.7_format", "arc_oldformat",
  "text_oldformat", "text_newformat", "text_hi_format", "polygonpoints",
  "polygonpoint", "element", "element_oldformat", "@10",
  "element_1.3.4_format", "@11", "element_newformat", "@12",
  "element_1.7_format", "@13", "element_hi_format", "@14",
  "elementdefinitions", "elementdefinition", "@15", "relementdefs",
  "relementdef", "@16", "pin_hi_format", "pin_1.7_format",
  "pin_1.6.3_format", "pin_newformat", "pin_oldformat", "pad_hi_format",
  "pad_1.7_format", "pad_newformat", "pad", "flags", "symbols", "symbol",
  "@17", "@18", "symbolid", "symboldata", "symboldefinitions",
  "symboldefinition", "hiressymbol", "pcbnetlist", "pcbnetdef", "nets",
  "netdefs", "net", "@19", "connections", "conndefs", "conn", "attributes",
  "attribute", "opt_string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    91,    93,    40,
      41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    44,    43,    45,    43,
      47,    46,    48,    48,    50,    49,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    54,    55,    56,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    63,    64,    65,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    70,    71,    70,    70,
      70,    72,    70,    70,    73,    73,    73,    73,    73,    74,
      75,    76,    77,    78,    79,    79,    81,    80,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    84,    86,    84,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    96,    97,    97,    97,
      98,    98,    98,    98,    98,   100,    99,   102,   101,   104,
     103,   106,   105,   108,   107,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   110,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   113,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   124,   125,   125,   127,   126,   128,   126,   129,
     129,   130,   130,   131,   131,   131,   132,   133,   134,   134,
     135,   136,   136,   137,   137,   139,   138,   140,   140,   141,
     141,   142,   143,   143,   144,   145,   145
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     0,    14,     0,     2,
       0,     2,     1,     0,     0,     2,     0,     4,     4,     6,
       6,     1,     1,     1,     1,     6,     7,     7,     7,     6,
       6,     6,     0,     0,     4,     0,     4,     0,     1,     1,
       1,     6,     7,     9,     4,     4,     0,     4,     0,     4,
       4,     0,     1,     0,     1,     2,     1,     0,     2,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,    11,
      11,    10,     9,     8,    10,    10,     0,    10,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     8,     1,
       1,     1,     0,     2,     0,     8,    10,    10,     9,    12,
      12,    11,     8,     9,     9,     1,     2,     4,     4,     0,
       1,     1,     1,     1,     1,     0,    12,     0,    15,     0,
      16,     0,    18,     0,    18,     1,     2,     1,     1,     1,
       1,     1,     8,     8,    10,    10,     5,     5,     0,     2,
       1,     2,     1,     1,     1,     1,     8,     8,    10,    10,
       0,     2,    12,    12,    10,     9,     8,    13,    13,    11,
      10,     1,     1,     1,     2,     0,     9,     0,     9,     1,
       1,     1,     2,     1,     1,     0,     8,     8,     1,     0,
       6,     1,     0,     1,     2,     0,     9,     1,     0,     1,
       2,     4,     1,     2,     5,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,    16,     0,     3,     0,     4,     0,
       1,     0,     0,     0,     9,   110,   111,   112,   113,   114,
      63,     0,     0,     0,    11,     0,    54,     0,     0,    56,
      64,    65,    66,    67,    68,    59,    60,     0,    15,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    58,   192,    62,     0,     0,   164,     0,     0,
       0,     0,    32,    21,    22,    23,    24,   161,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   169,
     170,     0,     0,    17,     0,     0,     0,     0,     0,    33,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   165,   167,    20,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    38,    39,    40,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,   175,   175,     0,     0,    25,     0,     0,     0,     0,
      34,     0,     0,     0,    48,     0,     0,     0,     0,    79,
       0,     0,     0,     0,    73,     0,     0,     0,     0,   171,
     173,   174,     0,    28,    26,    27,    30,    31,    29,    36,
       0,     0,     0,    51,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,    78,    80,     0,    82,    83,    84,
      85,    86,    87,    91,    90,    89,     0,     0,     0,    72,
       0,     0,     0,     0,   166,   172,   168,     0,     0,     0,
       0,     0,    13,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    81,    93,     0,     0,
      71,    74,    75,     0,     0,     0,    44,    45,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   125,     0,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,     0,
       0,     0,    41,    47,     0,     0,   179,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     126,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    50,    49,     0,     7,   178,     0,
     138,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,   138,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,    43,     0,   123,   118,
     121,   138,     0,     0,     0,     0,     0,     0,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   177,   176,   182,   150,   150,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,   102,     0,     0,    95,   106,     0,     0,   181,
     183,     0,     0,     0,     0,   150,   140,     0,   143,   142,
     145,   144,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,   104,   103,     0,     0,     0,
     180,   184,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   141,   151,   122,   132,   133,     0,     0,   156,     0,
       0,     0,    96,    97,     0,     0,   108,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   155,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,   160,     0,   134,   135,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   189,   146,   147,     0,     0,     0,     0,
       0,     0,     0,   186,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   191,     0,
       0,     0,     0,   152,   153,     0,     0,   157,   158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,   281,     8,     9,
      12,    42,    62,    63,    64,    65,    66,    89,   110,   132,
     156,   157,   158,   159,   184,   213,   252,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     189,   223,   224,   225,   226,   393,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   420,   421,    14,    15,   256,
      16,   350,    17,   376,    18,   426,    19,   425,   291,   292,
     293,   455,   456,   457,   458,   459,   294,   295,   296,   460,
     461,   297,   298,    69,    38,    39,   171,   172,    81,   198,
     199,   200,   201,   347,   348,   448,   449,   450,   561,   571,
     572,   573,    52,    53,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -424
static const yytype_int16 yypact[] =
{
      11,  -424,    16,  -424,    47,    49,  -424,    14,  -424,    33,
    -424,    55,    77,    38,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,    58,   117,   120,  -424,    48,  -424,    66,    49,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,   121,    33,  -424,
     100,   124,    92,    50,    73,   115,   122,   127,   137,   138,
    -424,   114,    66,  -424,  -424,    23,    23,  -424,   132,   170,
     175,   125,   177,  -424,  -424,  -424,  -424,  -424,  -424,   176,
     193,   197,   198,   202,   203,   204,   205,   206,  -424,  -424,
    -424,   207,   208,  -424,   210,     1,   209,   162,   129,   183,
     211,   212,   216,   214,   219,   220,   221,   222,   223,   171,
     186,   224,   225,  -424,   227,   228,   229,   231,   232,   199,
     213,   233,   105,   234,  -424,   200,   235,   111,   239,   240,
     215,   217,   218,   226,   230,   241,   242,   243,   245,   246,
     247,   236,   237,   248,   250,   251,   255,   238,   256,   126,
     257,   258,   259,  -424,  -424,  -424,  -424,  -424,   260,     3,
     262,   166,   263,   244,   264,   249,   253,  -424,  -424,  -424,
     265,   268,   272,   252,  -424,   273,   133,   275,   254,   277,
     278,   261,   261,   266,   267,  -424,   269,   270,   274,   271,
    -424,   276,   280,   279,   286,   282,   284,   285,   281,    59,
     283,   287,   288,   289,  -424,    50,   292,   135,   -10,  -424,
    -424,  -424,    -6,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
     293,   139,   291,   294,   295,   296,   297,  -424,   136,   140,
     298,   141,   299,   300,    59,  -424,    66,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,    50,   302,   301,  -424,
     290,   303,   312,   313,  -424,  -424,  -424,   314,   304,   305,
     315,   146,   309,   316,   306,   320,   108,   321,   322,   323,
     324,   329,   330,   331,    50,  -424,  -424,    66,   310,   307,
    -424,  -424,  -424,   332,   333,     2,  -424,  -424,   311,   336,
     343,    51,  -424,   347,   317,     4,   147,   318,   319,   150,
     151,    64,  -424,    66,  -424,  -424,  -424,  -424,  -424,   349,
     350,   351,   352,   356,   357,   358,   325,  -424,  -424,   359,
     360,    26,  -424,  -424,   326,   327,   338,    50,  -424,   363,
     334,   366,   367,   368,   369,   371,   372,   373,   374,  -424,
    -424,    66,   375,   376,   377,   378,   379,   380,   381,   346,
     383,   384,   385,  -424,  -424,  -424,   353,  -424,  -424,   355,
     108,   354,  -424,   386,   387,   388,   392,   393,   394,   396,
     397,   398,   399,   400,   401,   402,   403,   143,  -424,   405,
     406,   382,   370,   389,    75,   390,   108,   408,   409,   410,
     411,   412,   413,   395,   391,   414,   415,   416,   418,   419,
     417,   420,   421,   154,   404,   407,  -424,   422,  -424,  -424,
    -424,    80,   424,   427,   144,   429,   431,   432,  -424,  -424,
     433,   434,   435,   436,   423,    50,   438,   425,   440,   441,
      -2,  -424,  -424,  -424,   308,   119,   119,  -424,   442,   443,
     444,   445,   446,   448,   449,    50,     5,   450,   451,  -424,
     426,   428,  -424,   452,   453,  -424,  -424,   430,   437,   308,
    -424,   155,   158,   159,   163,    91,  -424,    66,  -424,  -424,
    -424,  -424,   103,   447,   439,   145,   454,   456,   455,   457,
     458,   459,  -424,   463,   464,  -424,  -424,   460,   461,   465,
    -424,  -424,   467,   469,   470,   471,   472,   473,   475,   477,
    -424,  -424,    66,  -424,  -424,  -424,   462,   478,  -424,   149,
     479,   480,  -424,  -424,    50,     6,  -424,  -424,   481,   483,
     485,   486,   487,   488,   489,   490,   492,  -424,   466,   468,
     494,   474,   476,   482,   484,  -424,   491,   497,   500,   501,
     502,   504,   506,   507,   508,  -424,  -424,   493,  -424,  -424,
    -424,  -424,   495,   510,   511,   512,   514,   515,   516,   518,
     519,  -424,  -424,   520,   522,   523,   524,   525,   526,   527,
     529,   503,   498,   499,   534,   535,   537,   538,   539,   540,
     505,   509,   503,  -424,  -424,  -424,   541,   542,   543,   547,
     548,   549,   550,  -424,  -424,   551,   552,   553,   554,   517,
     513,   521,    50,   559,   557,   558,  -424,  -424,  -424,   528,
     530,    50,   562,  -424,  -424,   531,   532,  -424,  -424
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,    15,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,   -31,  -424,   546,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,    78,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -130,   545,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,  -340,  -288,
    -424,  -129,  -423,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -194,  -424,   536,  -424,  -424,   533,   131,
    -135,  -424,  -424,  -424,  -424,  -424,  -424,  -148,  -424,  -424,
    -424,  -266,  -224,   -52,  -424
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      78,   240,   267,   330,   102,   311,   174,   319,   471,   524,
     374,   -10,     1,   197,   -53,    20,    10,   197,    -6,    -6,
     -10,   -10,   -10,    21,    22,    23,    79,    80,    -8,   342,
     244,   -61,   491,   -14,   246,   418,   401,   419,   445,   491,
     312,   103,   268,   175,   320,   472,   525,   -10,   -52,    20,
     -57,   -53,    20,    67,    11,    37,    68,    21,    22,    23,
      21,    22,    23,   245,   343,   -61,    13,   245,   -61,   331,
     306,   218,   219,   220,   221,    43,    70,    44,   -52,    71,
     286,   -53,   287,   288,   -57,    41,   330,   -57,   222,   289,
     290,   286,    40,   287,   288,   -92,   286,    45,   287,   288,
     289,   290,    51,    58,   329,   289,   290,   451,   134,   452,
     453,   135,    61,   330,   139,   399,   454,   140,    72,   451,
     427,   452,   453,   349,   286,    73,   287,   288,   454,   166,
      74,   490,   167,   289,   290,   451,   191,   452,   453,   192,
      75,    76,   248,   493,   454,   249,   391,   430,   496,   392,
     431,   497,   519,    77,    46,   520,    47,    48,    55,    49,
      56,    59,    86,    60,    87,   105,   107,   106,   108,   177,
      83,   178,   242,   257,   243,   258,    84,   259,   262,   260,
     263,    85,    90,   279,   321,   280,   322,   325,   327,   326,
     328,   418,   482,   419,   483,   484,   486,   485,   487,    91,
     488,    88,   489,    92,    93,    94,    95,    96,    97,   121,
      99,   100,    98,   101,   104,    78,   109,   111,   112,   113,
     114,   440,   116,   117,   118,   119,   122,   123,   124,   120,
     125,   126,   127,   492,   128,   129,   130,   136,   138,   133,
     137,   470,   141,   142,   148,   149,   150,   131,   151,   152,
     316,   160,   153,   161,   162,   143,   144,   145,   163,   165,
     168,   169,   170,   173,   146,   176,   179,   282,   185,   181,
     147,   186,   155,   154,   183,   187,   190,   164,   193,    78,
     195,   196,   180,   210,   197,   214,   182,   215,   216,   236,
     446,   238,   188,   237,   194,   241,   247,   462,   253,   254,
     255,   481,   266,   202,   203,   269,   584,   204,   206,   205,
     523,   208,   207,   212,   209,   273,   274,   275,   211,   283,
     217,   278,   251,   285,   299,   300,   301,   302,   271,   239,
     250,   -14,   303,   304,   305,   309,   310,   261,   264,   447,
     265,   270,   314,   272,   276,   277,   284,   308,   307,   315,
     317,   313,   332,   333,   334,   335,   318,   323,   324,   336,
     337,   338,   340,   341,   344,   339,   351,   345,   346,   353,
     354,   355,   356,   352,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   377,
     378,   379,   372,   373,   375,   380,   381,   382,   599,   383,
     384,   385,   386,   387,   388,   389,   390,   605,   394,   395,
     397,   402,   403,   404,   405,   406,   407,   410,   411,   412,
     396,   413,   414,   415,   417,     0,   416,   428,   398,   400,
     429,   409,   432,   408,   433,   434,   435,   436,   437,   438,
      78,   441,   422,   443,   444,   463,   464,   423,   466,   467,
     465,   468,   469,   473,   474,   477,   478,     0,   500,     0,
     501,   424,   499,   439,   475,   442,   504,   505,   476,   479,
     509,   508,   510,   511,   512,   513,   514,   480,   515,   495,
     516,   518,   521,   522,     0,   494,   527,   526,   528,   529,
     530,   531,   532,   533,   498,   534,   502,   537,   506,   503,
     543,   507,   517,   544,   545,   546,   535,   547,   536,   548,
     549,   550,   538,   553,   554,   555,   539,   556,   557,   558,
     540,   559,   560,   562,   541,   563,   564,   565,   566,   567,
     568,   542,   569,   551,   552,   570,   574,   576,   577,   575,
     578,   579,   580,   581,   582,     0,   587,   585,   586,   583,
     588,   589,   590,   597,     0,   596,   591,   592,   593,   594,
     595,   598,   600,   601,   602,   606,   603,     0,     0,   607,
     604,    50,   608,    54,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      52,   195,   226,   291,     3,     3,     3,     3,     3,     3,
     350,     0,     1,    23,     0,     1,     0,    23,     7,     8,
       9,    10,    11,     9,    10,    11,     3,     4,    17,     3,
      40,    17,   455,    22,    40,    37,   376,    39,    40,   462,
      38,    40,   236,    40,    40,    40,    40,    36,     0,     1,
      36,     0,     1,     3,     7,    22,     6,     9,    10,    11,
       9,    10,    11,   198,    38,    17,    17,   202,    17,   293,
     264,    12,    13,    14,    15,    37,     3,    39,    30,     6,
      16,    30,    18,    19,    36,     8,   374,    36,    29,    25,
      26,    16,    37,    18,    19,    36,    16,    39,    18,    19,
      25,    26,    36,     3,    40,    25,    26,    16,     3,    18,
      19,     6,    20,   401,     3,    40,    25,     6,     3,    16,
      40,    18,    19,   317,    16,     3,    18,    19,    25,     3,
       3,    40,     6,    25,    26,    16,     3,    18,    19,     6,
       3,     3,     3,    40,    25,     6,     3,     3,     3,     6,
       6,     6,     3,    39,    37,     6,    39,    37,    37,    39,
      39,    37,    37,    39,    39,     3,    37,     5,    39,     3,
      38,     5,    37,    37,    39,    39,     6,    37,    37,    39,
      39,     6,     6,    37,    37,    39,    39,    37,    37,    39,
      39,    37,    37,    39,    39,    37,    37,    39,    39,     6,
      37,    24,    39,     6,     6,     3,     3,     3,     3,    38,
       3,     3,     6,     3,     5,   267,    33,     6,     6,     3,
       6,   415,     3,     3,     3,     3,    40,     3,     3,     6,
       3,     3,     3,   457,     3,     3,    37,     3,     3,     6,
      40,   435,     3,     3,     3,     3,     3,    34,     3,     3,
     281,     3,     5,     3,     3,    40,    39,    39,     3,     3,
       3,     3,     3,     3,    38,     3,     3,   252,     3,     5,
      40,     3,    35,    37,    21,     3,     3,    39,     3,   331,
       3,     3,    38,     3,    23,     3,    37,     3,     3,     6,
     420,     3,    40,     6,    40,     3,     3,   426,     3,     3,
       3,   449,   224,   172,    38,     3,   572,    40,    38,    40,
     504,    40,    38,    27,    38,     3,     3,     3,    39,     3,
      39,     6,    28,     3,     3,     3,     3,     3,    38,    40,
      39,    22,     3,     3,     3,     3,     3,    39,    39,    31,
      40,    40,     6,    40,    40,    40,    40,    40,    38,     6,
       3,    40,     3,     3,     3,     3,    39,    39,    39,     3,
       3,     3,     3,     3,    38,    40,     3,    40,    30,     3,
       3,     3,     3,    39,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,    39,     3,     3,     3,     3,
       3,     3,    39,    38,    40,     3,     3,     3,   592,     3,
       3,     3,     3,     3,     3,     3,     3,   601,     3,     3,
      40,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      38,     3,     3,     6,     3,    -1,     6,     3,    39,    39,
       3,    40,     3,    38,     3,     3,     3,     3,     3,     3,
     492,     3,    38,     3,     3,     3,     3,    40,     3,     3,
       6,     3,     3,     3,     3,     3,     3,    -1,     3,    -1,
       3,    39,     6,    40,    38,    40,     3,     3,    40,    39,
       3,     6,     3,     3,     3,     3,     3,    40,     3,    40,
       3,     3,     3,     3,    -1,    38,     3,     6,     3,     3,
       3,     3,     3,     3,    40,     3,    38,     3,    38,    40,
       3,    40,    40,     3,     3,     3,    40,     3,    40,     3,
       3,     3,    38,     3,     3,     3,    40,     3,     3,     3,
      38,     3,     3,     3,    40,     3,     3,     3,     3,     3,
       3,    40,     3,    40,    39,    32,    38,     3,     3,    40,
       3,     3,     3,     3,    39,    -1,     3,     6,     6,    40,
       3,     3,     3,    40,    -1,    38,     6,     6,     6,     6,
       6,    40,     3,     6,     6,     3,    38,    -1,    -1,    38,
      40,    25,    40,    28,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    42,    43,    44,    45,    46,    47,    49,    50,
       0,     7,    51,    17,    98,    99,   101,   103,   105,   107,
       1,     9,    10,    11,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    22,   125,   126,
      37,     8,    52,    37,    39,    39,    37,    39,    37,    39,
      70,    36,   143,   144,    98,    37,    39,   126,     3,    37,
      39,    20,    53,    54,    55,    56,    57,     3,     6,   124,
       3,     6,     3,     3,     3,     3,     3,    39,   144,     3,
       4,   129,   129,    38,     6,     6,    37,    39,    24,    58,
       6,     6,     6,     6,     3,     3,     3,     3,     6,     3,
       3,     3,     3,    40,     5,     3,     5,    37,    39,    33,
      59,     6,     6,     3,     6,   145,     3,     3,     3,     3,
       6,    38,    40,     3,     3,     3,     3,     3,     3,     3,
      37,    34,    60,     6,     3,     6,     3,    40,     3,     3,
       6,     3,     3,    40,    39,    39,    38,    40,     3,     3,
       3,     3,     3,     5,    37,    35,    61,    62,    63,    64,
       3,     3,     3,     3,    39,     3,     3,     6,     3,     3,
       3,   127,   128,     3,     3,    40,     3,     3,     5,     3,
      38,     5,    37,    21,    65,     3,     3,     3,    40,    81,
       3,     3,     6,     3,    40,     3,     3,    23,   130,   131,
     132,   133,   130,    38,    40,    40,    38,    38,    40,    38,
       3,    39,    27,    66,     3,     3,     3,    39,    12,    13,
      14,    15,    29,    82,    83,    84,    85,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     6,     6,     3,    40,
     124,     3,    37,    39,    40,   131,    40,     3,     3,     6,
      39,    28,    67,     3,     3,     3,   100,    37,    39,    37,
      39,    39,    37,    39,    39,    40,    84,   143,   124,     3,
      40,    38,    40,     3,     3,     3,    40,    40,     6,    37,
      39,    48,    49,     3,    40,     3,    16,    18,    19,    25,
      26,   109,   110,   111,   117,   118,   119,   122,   123,     3,
       3,     3,     3,     3,     3,     3,   124,    38,    40,     3,
       3,     3,    38,    40,     6,     6,    68,     3,    39,     3,
      40,    37,    39,    39,    39,    37,    39,    37,    39,    40,
     110,   143,     3,     3,     3,     3,     3,     3,     3,    40,
       3,     3,     3,    38,    38,    40,    30,   134,   135,   124,
     102,     3,    39,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,    39,     3,
       3,     3,    39,    38,   109,    40,   104,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,    86,     3,     3,    38,    40,    39,    40,
      39,   109,     3,     3,     3,     3,     3,     3,    38,    40,
       3,     3,     3,     3,     3,     6,     6,     3,    37,    39,
      96,    97,    38,    40,    39,   108,   106,    40,     3,     3,
       3,     6,     3,     3,     3,     3,     3,     3,     3,    40,
     124,     3,    40,     3,     3,    40,    97,    31,   136,   137,
     138,    16,    18,    19,    25,   112,   113,   114,   115,   116,
     120,   121,   112,     3,     3,     6,     3,     3,     3,     3,
     124,     3,    40,     3,     3,    38,    40,     3,     3,    39,
      40,   138,    37,    39,    37,    39,    37,    39,    37,    39,
      40,   113,   143,    40,    38,    40,     3,     6,    40,     6,
       3,     3,    38,    40,     3,     3,    38,    40,     6,     3,
       3,     3,     3,     3,     3,     3,     3,    40,     3,     3,
       6,     3,     3,   124,     3,    40,     6,     3,     3,     3,
       3,     3,     3,     3,     3,    40,    40,     3,    38,    40,
      38,    40,    40,     3,     3,     3,     3,     3,     3,     3,
       3,    40,    39,     3,     3,     3,     3,     3,     3,     3,
       3,   139,     3,     3,     3,     3,     3,     3,     3,     3,
      32,   140,   141,   142,    38,    40,     3,     3,     3,     3,
       3,     3,    39,    40,   142,     6,     6,     3,     3,     3,
       3,     6,     6,     6,     6,     6,    38,    40,    40,   124,
       3,     6,     6,    38,    40,   124,     3,    38,    40
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 118 "parse_y.y"
    { YYABORT; }
    break;

  case 6:
#line 142 "parse_y.y"
    {
					/* reset flags for 'used layers';
					 * init font and data pointers
					 */
				int	i;

				if (!yyPCB)
				{
					Message("illegal fileformat\n");
					YYABORT;
				}
				for (i = 0; i < MAX_LAYER + 2; i++)
					LayerFlag[i] = False;
				yyFont = &yyPCB->Font;
				yyData = yyPCB->Data;
				yyData->pcb = (void *)yyPCB;
				yyData->LayerN = 0;
				layer_group_string = NULL;
			}
    break;

  case 7:
#line 174 "parse_y.y"
    {
			  int i, j;
			  PCBTypePtr pcb_save = PCB;

			  if (layer_group_string == NULL)
			    layer_group_string = Settings.Groups;
			  CreateNewPCBPost (yyPCB, 0);
			  if (ParseGroupString(layer_group_string, &yyPCB->LayerGroups, yyData->LayerN))
			    {
			      Message("illegal layer-group string\n");
			      YYABORT;
			    }
			/* initialize the polygon clipping now since
			 * we didn't know the layer grouping before.
			 */
			PCB = yyPCB;
			for (i = 0; i < yyData->LayerN+2; i++)
			  for (j = 0; j < yyData->Layer[i].PolygonN; j++)
			      InitClip (yyData, &yyData->Layer[i], &yyData->Layer[i].Polygon[j]);
			PCB = pcb_save;
			}
    break;

  case 8:
#line 196 "parse_y.y"
    { PreLoadElementPCB ();
		    layer_group_string = NULL; }
    break;

  case 9:
#line 199 "parse_y.y"
    { LayerFlag[0] = True;
		    LayerFlag[1] = True;
		    yyData->LayerN = 2;
		    PostLoadElementPCB ();
		  }
    break;

  case 10:
#line 207 "parse_y.y"
    {
					/* reset flags for 'used layers';
					 * init font and data pointers
					 */
				int	i;

				if (!yyData || !yyFont)
				{
					Message("illegal fileformat\n");
					YYABORT;
				}
				for (i = 0; i < MAX_LAYER + 2; i++)
					LayerFlag[i] = False;
				yyData->LayerN = 0;
			}
    break;

  case 14:
#line 232 "parse_y.y"
    {
					/* mark all symbols invalid */
				int	i;

				if (!yyFont)
				{
					Message("illegal fileformat\n");
					YYABORT;
				}
				yyFont->Valid = False;
				for (i = 0; i <= MAX_FONTPOSITION; i++)
					yyFont->Symbol[i].Valid = False;
			}
    break;

  case 15:
#line 246 "parse_y.y"
    {
				yyFont->Valid = True;
		  		SetFontInfo(yyFont);
			}
    break;

  case 17:
#line 274 "parse_y.y"
    {
  if (check_file_version ((yyvsp[(3) - (4)].number)) != 0)
    {
      YYABORT;
    }
}
    break;

  case 18:
#line 306 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (4)].string);
				yyPCB->MaxWidth = MAX_COORD;
				yyPCB->MaxHeight = MAX_COORD;
			}
    break;

  case 19:
#line 312 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (6)].string);
				yyPCB->MaxWidth = (yyvsp[(4) - (6)].number)*100;
				yyPCB->MaxHeight = (yyvsp[(5) - (6)].number)*100;
			}
    break;

  case 20:
#line 318 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (6)].string);
				yyPCB->MaxWidth = (yyvsp[(4) - (6)].number);
				yyPCB->MaxHeight = (yyvsp[(5) - (6)].number);
			}
    break;

  case 25:
#line 353 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (6)].number)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (6)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (6)].number)*100;
			}
    break;

  case 26:
#line 361 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].number)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number)*100;
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = True;
				else
					Settings.DrawGrid = False;
			}
    break;

  case 27:
#line 374 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].floating)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number)*100;
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = True;
				else
					Settings.DrawGrid = False;
			}
    break;

  case 28:
#line 386 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].floating);
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number);
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number);
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = True;
				else
					Settings.DrawGrid = False;
			}
    break;

  case 29:
#line 418 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number)*100;
				yyPCB->CursorY = (yyvsp[(4) - (6)].number)*100;
				yyPCB->Zoom = (yyvsp[(5) - (6)].number)*2;
			}
    break;

  case 30:
#line 424 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number);
				yyPCB->CursorY = (yyvsp[(4) - (6)].number);
				yyPCB->Zoom = (yyvsp[(5) - (6)].number);
			}
    break;

  case 31:
#line 430 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number);
				yyPCB->CursorY = (yyvsp[(4) - (6)].number);
				yyPCB->Zoom = (yyvsp[(5) - (6)].floating);
			}
    break;

  case 34:
#line 454 "parse_y.y"
    {
				yyPCB->IsleArea = (yyvsp[(3) - (4)].floating);
			}
    break;

  case 36:
#line 480 "parse_y.y"
    {
				yyPCB->ThermScale = (yyvsp[(3) - (4)].floating);
			}
    break;

  case 41:
#line 519 "parse_y.y"
    {
				yyPCB->Bloat = (yyvsp[(3) - (6)].number);
				yyPCB->Shrink = (yyvsp[(4) - (6)].number);
				yyPCB->minWid = (yyvsp[(5) - (6)].number);
				yyPCB->minRing = (yyvsp[(5) - (6)].number);
			}
    break;

  case 42:
#line 529 "parse_y.y"
    {
				yyPCB->Bloat = (yyvsp[(3) - (7)].number);
				yyPCB->Shrink = (yyvsp[(4) - (7)].number);
				yyPCB->minWid = (yyvsp[(5) - (7)].number);
				yyPCB->minSlk = (yyvsp[(6) - (7)].number);
				yyPCB->minRing = (yyvsp[(5) - (7)].number);
			}
    break;

  case 43:
#line 540 "parse_y.y"
    {
				yyPCB->Bloat = (yyvsp[(3) - (9)].number);
				yyPCB->Shrink = (yyvsp[(4) - (9)].number);
				yyPCB->minWid = (yyvsp[(5) - (9)].number);
				yyPCB->minSlk = (yyvsp[(6) - (9)].number);
				yyPCB->minDrill = (yyvsp[(7) - (9)].number);
				yyPCB->minRing = (yyvsp[(8) - (9)].number);
			}
    break;

  case 44:
#line 567 "parse_y.y"
    {
				yyPCB->Flags = MakeFlags ((yyvsp[(3) - (4)].number) & PCB_FLAGS);
			}
    break;

  case 45:
#line 571 "parse_y.y"
    {
			  yyPCB->Flags = string_to_pcbflags ((yyvsp[(3) - (4)].string), yyerror);
			}
    break;

  case 47:
#line 603 "parse_y.y"
    {
			  layer_group_string = (yyvsp[(3) - (4)].string);
			}
    break;

  case 49:
#line 651 "parse_y.y"
    {
				if (ParseRouteString((yyvsp[(3) - (4)].string), &yyPCB->RouteStyle[0], 100))
				{
					Message("illegal route-style string\n");
					YYABORT;
				}
			}
    break;

  case 50:
#line 659 "parse_y.y"
    {
				if (ParseRouteString((yyvsp[(3) - (4)].string), &yyPCB->RouteStyle[0], 1))
				{
					Message("illegal route-style string\n");
					YYABORT;
				}
			}
    break;

  case 57:
#line 681 "parse_y.y"
    { attr_list = & yyPCB->Attributes; }
    break;

  case 61:
#line 685 "parse_y.y"
    {
					/* clear pointer to force memory allocation by 
					 * the appropriate subroutine
					 */
				yyElement = NULL;
			}
    break;

  case 63:
#line 692 "parse_y.y"
    { YYABORT; }
    break;

  case 69:
#line 737 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (11)].number), (yyvsp[(4) - (11)].number), (yyvsp[(5) - (11)].number), (yyvsp[(6) - (11)].number), (yyvsp[(7) - (11)].number), (yyvsp[(8) - (11)].number), (yyvsp[(9) - (11)].string), (yyvsp[(10) - (11)].flagtype));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 70:
#line 746 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (11)].number)*100, (yyvsp[(4) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(6) - (11)].number)*100, (yyvsp[(7) - (11)].number)*100, (yyvsp[(8) - (11)].number)*100, (yyvsp[(9) - (11)].string),
					OldFlags((yyvsp[(10) - (11)].number)));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 71:
#line 757 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100,
					     ((yyvsp[(5) - (10)].number) + (yyvsp[(6) - (10)].number))*100, (yyvsp[(7) - (10)].number)*100, (yyvsp[(8) - (10)].string), OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 72:
#line 767 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (9)].number) + 2*MASKFRAME)*100,  (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].string), OldFlags((yyvsp[(8) - (9)].number)));
				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 73:
#line 777 "parse_y.y"
    {
				BDimension	hole = ((yyvsp[(5) - (8)].number) *DEFAULT_DRILLINGHOLE);

					/* make sure that there's enough copper left */
				if ((yyvsp[(5) - (8)].number) -hole < MIN_PINORVIACOPPER && 
					(yyvsp[(5) - (8)].number) > MIN_PINORVIACOPPER)
					hole = (yyvsp[(5) - (8)].number) -MIN_PINORVIACOPPER;

				CreateNewVia(yyData, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (8)].number) + 2*MASKFRAME)*100, hole, (yyvsp[(6) - (8)].string), OldFlags((yyvsp[(7) - (8)].number)));
				SaveFree((yyvsp[(6) - (8)].string));
			}
    break;

  case 74:
#line 813 "parse_y.y"
    {
				CreateNewRat(yyData, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(8) - (10)].number),
					Settings.RatThickness, (yyvsp[(9) - (10)].flagtype));
			}
    break;

  case 75:
#line 818 "parse_y.y"
    {
				CreateNewRat(yyData, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number)*100, (yyvsp[(5) - (10)].number), (yyvsp[(8) - (10)].number),
					Settings.RatThickness, OldFlags((yyvsp[(9) - (10)].number)));
			}
    break;

  case 76:
#line 849 "parse_y.y"
    {
				if ((yyvsp[(3) - (7)].number) <= 0 || (yyvsp[(3) - (7)].number) > MAX_LAYER + 2)
				{
					yyerror("Layernumber out of range");
					YYABORT;
				}
				if (LayerFlag[(yyvsp[(3) - (7)].number)-1])
				{
					yyerror("Layernumber used twice");
					YYABORT;
				}
				Layer = &yyData->Layer[(yyvsp[(3) - (7)].number)-1];

					/* memory for name is already allocated */
				Layer->Name = (yyvsp[(4) - (7)].string);
				LayerFlag[(yyvsp[(3) - (7)].number)-1] = True;
				if (yyData->LayerN + 2 < (yyvsp[(3) - (7)].number))
				  yyData->LayerN = (yyvsp[(3) - (7)].number) - 2;
			}
    break;

  case 88:
#line 890 "parse_y.y"
    {
				CreateNewPolygonFromRectangle(Layer,
					(yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, ((yyvsp[(3) - (8)].number)+(yyvsp[(5) - (8)].number))*100, ((yyvsp[(4) - (8)].number)+(yyvsp[(6) - (8)].number))*100, OldFlags((yyvsp[(7) - (8)].number)));
			}
    break;

  case 92:
#line 897 "parse_y.y"
    { attr_list = & Layer->Attributes; }
    break;

  case 94:
#line 900 "parse_y.y"
    {
				Polygon = CreateNewPolygon(Layer, (yyvsp[(3) - (5)].flagtype));
			}
    break;

  case 95:
#line 904 "parse_y.y"
    {
					/* ignore junk */
				if (Polygon->PointN >= 3)
				  {
				    SetPolygonBoundingBox (Polygon);
				    if (!Layer->polygon_tree)
				      Layer->polygon_tree = r_create_tree (NULL, 0, 0);
				    r_insert_entry (Layer->polygon_tree, (BoxType *) Polygon, 0);
				  }
				else
				{
					Message("WARNING parsing file '%s'\n"
						"    line:        %i\n"
						"    description: 'ignored polygon (< 3 points)'\n",
						yyfilename, yylineno);
					DestroyObject(yyData, POLYGON_TYPE, Layer, Polygon, Polygon);
				}
			}
    break;

  case 96:
#line 953 "parse_y.y"
    {
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].flagtype));
			}
    break;

  case 97:
#line 961 "parse_y.y"
    {
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100,
						     (yyvsp[(7) - (10)].number)*100, (yyvsp[(8) - (10)].number)*100, OldFlags((yyvsp[(9) - (10)].number)));
			}
    break;

  case 98:
#line 970 "parse_y.y"
    {
				/* eliminate old-style rat-lines */
			if (((yyvsp[(8) - (9)].number) & RATFLAG) == 0)
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].number)*100,
					200*GROUNDPLANEFRAME, OldFlags((yyvsp[(8) - (9)].number)));
			}
    break;

  case 99:
#line 1018 "parse_y.y"
    {
			  CreateNewArcOnLayer(Layer, (yyvsp[(3) - (12)].number), (yyvsp[(4) - (12)].number), (yyvsp[(5) - (12)].number), (yyvsp[(6) - (12)].number), (yyvsp[(9) - (12)].number), (yyvsp[(10) - (12)].number), (yyvsp[(7) - (12)].number), (yyvsp[(8) - (12)].number), (yyvsp[(11) - (12)].flagtype));
			}
    break;

  case 100:
#line 1026 "parse_y.y"
    {
				CreateNewArcOnLayer(Layer, (yyvsp[(3) - (12)].number)*100, (yyvsp[(4) - (12)].number)*100, (yyvsp[(5) - (12)].number)*100, (yyvsp[(6) - (12)].number)*100, (yyvsp[(9) - (12)].number), (yyvsp[(10) - (12)].number),
						    (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number)*100, OldFlags((yyvsp[(11) - (12)].number)));
			}
    break;

  case 101:
#line 1035 "parse_y.y"
    {
				CreateNewArcOnLayer(Layer, (yyvsp[(3) - (11)].number)*100, (yyvsp[(4) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(8) - (11)].number), (yyvsp[(9) - (11)].number),
					(yyvsp[(7) - (11)].number)*100, 200*GROUNDPLANEFRAME, OldFlags((yyvsp[(10) - (11)].number)));
			}
    break;

  case 102:
#line 1072 "parse_y.y"
    {
					/* use a default scale of 100% */
				CreateNewText(Layer,yyFont,(yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number), 100, (yyvsp[(6) - (8)].string), OldFlags((yyvsp[(7) - (8)].number)));
				SaveFree((yyvsp[(6) - (8)].string));
			}
    break;

  case 103:
#line 1082 "parse_y.y"
    {
				if ((yyvsp[(8) - (9)].number) & ONSILKFLAG)
				{
					LayerTypePtr lay = &yyData->Layer[yyData->LayerN +
						(((yyvsp[(8) - (9)].number) & ONSOLDERFLAG) ? SOLDER_LAYER : COMPONENT_LAYER)];

					CreateNewText(lay ,yyFont, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(7) - (9)].string),
						      OldFlags((yyvsp[(8) - (9)].number)));
				}
				else
					CreateNewText(Layer, yyFont, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(7) - (9)].string),
						      OldFlags((yyvsp[(8) - (9)].number)));
				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 104:
#line 1100 "parse_y.y"
    {
				/* FIXME: shouldn't know about .f */
				/* I don't think this matters because anything with hi_format
				 * will have the silk on its own layer in the file rather
				 * than using the ONSILKFLAG and having it in a copper layer.
				 * Thus there is no need for anything besides the 'else'
				 * part of this code.
				 */
				if ((yyvsp[(8) - (9)].flagtype).f & ONSILKFLAG)
				{
					LayerTypePtr lay = &yyData->Layer[yyData->LayerN +
						(((yyvsp[(8) - (9)].flagtype).f & ONSOLDERFLAG) ? SOLDER_LAYER : COMPONENT_LAYER)];

					CreateNewText(lay, yyFont, (yyvsp[(3) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(5) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(7) - (9)].string), (yyvsp[(8) - (9)].flagtype));
				}
				else
					CreateNewText(Layer, yyFont, (yyvsp[(3) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(5) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(7) - (9)].string), (yyvsp[(8) - (9)].flagtype));
				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 107:
#line 1147 "parse_y.y"
    {
				CreateNewPointInPolygon(Polygon, (yyvsp[(2) - (4)].number)*100, (yyvsp[(3) - (4)].number)*100);
			}
    break;

  case 108:
#line 1151 "parse_y.y"
    {
				CreateNewPointInPolygon(Polygon, (yyvsp[(2) - (4)].number), (yyvsp[(3) - (4)].number));
			}
    break;

  case 115:
#line 1223 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, NoFlags(),
					(yyvsp[(3) - (9)].string), (yyvsp[(4) - (9)].string), NULL, (yyvsp[(5) - (9)].number)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].number), 100, NoFlags(), False);
				SaveFree((yyvsp[(3) - (9)].string));
				SaveFree((yyvsp[(4) - (9)].string));
				pin_num = 1;
			}
    break;

  case 116:
#line 1231 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 117:
#line 1241 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (12)].number)),
					(yyvsp[(4) - (12)].string), (yyvsp[(5) - (12)].string), NULL, (yyvsp[(6) - (12)].number)*100, (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number), (yyvsp[(9) - (12)].number), OldFlags((yyvsp[(10) - (12)].number)), False);
				SaveFree((yyvsp[(4) - (12)].string));
				SaveFree((yyvsp[(5) - (12)].string));
				pin_num = 1;
			}
    break;

  case 118:
#line 1249 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 119:
#line 1259 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (13)].number)),
					(yyvsp[(4) - (13)].string), (yyvsp[(5) - (13)].string), (yyvsp[(6) - (13)].string), (yyvsp[(7) - (13)].number)*100, (yyvsp[(8) - (13)].number)*100, (yyvsp[(9) - (13)].number), (yyvsp[(10) - (13)].number), OldFlags((yyvsp[(11) - (13)].number)), False);
				SaveFree((yyvsp[(4) - (13)].string));
				SaveFree((yyvsp[(5) - (13)].string));
				SaveFree((yyvsp[(6) - (13)].string));
				pin_num = 1;
			}
    break;

  case 120:
#line 1268 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 121:
#line 1279 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (15)].number)),
					(yyvsp[(4) - (15)].string), (yyvsp[(5) - (15)].string), (yyvsp[(6) - (15)].string), ((yyvsp[(7) - (15)].number)+(yyvsp[(9) - (15)].number))*100, ((yyvsp[(8) - (15)].number)+(yyvsp[(10) - (15)].number))*100, (yyvsp[(11) - (15)].number), (yyvsp[(12) - (15)].number), OldFlags((yyvsp[(13) - (15)].number)), False);
				yyElement->MarkX = (yyvsp[(7) - (15)].number)*100;
				yyElement->MarkY = (yyvsp[(8) - (15)].number)*100;
				SaveFree((yyvsp[(4) - (15)].string));
				SaveFree((yyvsp[(5) - (15)].string));
				SaveFree((yyvsp[(6) - (15)].string));
			}
    break;

  case 122:
#line 1289 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 123:
#line 1300 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, (yyvsp[(3) - (15)].flagtype),
					(yyvsp[(4) - (15)].string), (yyvsp[(5) - (15)].string), (yyvsp[(6) - (15)].string), ((yyvsp[(7) - (15)].number)+(yyvsp[(9) - (15)].number)), ((yyvsp[(8) - (15)].number)+(yyvsp[(10) - (15)].number)), (yyvsp[(11) - (15)].number), (yyvsp[(12) - (15)].number), (yyvsp[(13) - (15)].flagtype), False);
				yyElement->MarkX = (yyvsp[(7) - (15)].number);
				yyElement->MarkY = (yyvsp[(8) - (15)].number);
				SaveFree((yyvsp[(4) - (15)].string));
				SaveFree((yyvsp[(5) - (15)].string));
				SaveFree((yyvsp[(6) - (15)].string));
			}
    break;

  case 124:
#line 1310 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 132:
#line 1390 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number), (yyvsp[(4) - (8)].number), (yyvsp[(5) - (8)].number), (yyvsp[(6) - (8)].number), (yyvsp[(7) - (8)].number));
			}
    break;

  case 133:
#line 1395 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, (yyvsp[(6) - (8)].number)*100, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 134:
#line 1400 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number));
			}
    break;

  case 135:
#line 1405 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number)*100);
			}
    break;

  case 136:
#line 1410 "parse_y.y"
    {
				yyElement->MarkX = (yyvsp[(3) - (5)].number);
				yyElement->MarkY = (yyvsp[(4) - (5)].number);
			}
    break;

  case 137:
#line 1415 "parse_y.y"
    {
				yyElement->MarkX = (yyvsp[(3) - (5)].number)*100;
				yyElement->MarkY = (yyvsp[(4) - (5)].number)*100;
			}
    break;

  case 138:
#line 1419 "parse_y.y"
    { attr_list = & yyElement->Attributes; }
    break;

  case 146:
#line 1434 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number) + yyElement->MarkX,
					(yyvsp[(4) - (8)].number) + yyElement->MarkY, (yyvsp[(5) - (8)].number) + yyElement->MarkX,
					(yyvsp[(6) - (8)].number) + yyElement->MarkY, (yyvsp[(7) - (8)].number));
			}
    break;

  case 147:
#line 1440 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (8)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (8)].number)*100 + yyElement->MarkX,
					(yyvsp[(6) - (8)].number)*100 + yyElement->MarkY, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 148:
#line 1447 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number) + yyElement->MarkX,
					(yyvsp[(4) - (10)].number) + yyElement->MarkY, (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number));
			}
    break;

  case 149:
#line 1452 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (10)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number)*100);
			}
    break;

  case 150:
#line 1456 "parse_y.y"
    { attr_list = & yyElement->Attributes; }
    break;

  case 152:
#line 1498 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (12)].number) + yyElement->MarkX,
					(yyvsp[(4) - (12)].number) + yyElement->MarkY, (yyvsp[(5) - (12)].number), (yyvsp[(6) - (12)].number), (yyvsp[(7) - (12)].number), (yyvsp[(8) - (12)].number), (yyvsp[(9) - (12)].string),
					(yyvsp[(10) - (12)].string), (yyvsp[(11) - (12)].flagtype));
				SaveFree((yyvsp[(9) - (12)].string));
				SaveFree((yyvsp[(10) - (12)].string));
			}
    break;

  case 153:
#line 1510 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (12)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (12)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (12)].number)*100, (yyvsp[(6) - (12)].number)*100, (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number)*100, (yyvsp[(9) - (12)].string),
					(yyvsp[(10) - (12)].string), OldFlags((yyvsp[(11) - (12)].number)));
				SaveFree((yyvsp[(9) - (12)].string));
				SaveFree((yyvsp[(10) - (12)].string));
			}
    break;

  case 154:
#line 1522 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (10)].number) + 2*MASKFRAME)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].string), (yyvsp[(8) - (10)].string), OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(7) - (10)].string));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 155:
#line 1533 "parse_y.y"
    {
				char	p_number[8];

				sprintf(p_number, "%d", pin_num++);
				CreateNewPin(yyElement, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (9)].number) + 2*MASKFRAME)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].string), p_number, OldFlags((yyvsp[(8) - (9)].number)));

				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 156:
#line 1549 "parse_y.y"
    {
				BDimension	hole = ((yyvsp[(5) - (8)].number) *DEFAULT_DRILLINGHOLE);
				char		p_number[8];

					/* make sure that there's enough copper left */
				if ((yyvsp[(5) - (8)].number) -hole < MIN_PINORVIACOPPER && 
					(yyvsp[(5) - (8)].number) > MIN_PINORVIACOPPER)
					hole = (yyvsp[(5) - (8)].number) -MIN_PINORVIACOPPER;

				sprintf(p_number, "%d", pin_num++);
				CreateNewPin(yyElement, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (8)].number) + 2*MASKFRAME)*100, hole, (yyvsp[(6) - (8)].string), p_number, OldFlags((yyvsp[(7) - (8)].number)));
				SaveFree((yyvsp[(6) - (8)].string));
			}
    break;

  case 157:
#line 1603 "parse_y.y"
    {
				CreateNewPad(yyElement, (yyvsp[(3) - (13)].number) + yyElement->MarkX,
					(yyvsp[(4) - (13)].number) + yyElement->MarkY,
					(yyvsp[(5) - (13)].number) + yyElement->MarkX,
					(yyvsp[(6) - (13)].number) + yyElement->MarkY, (yyvsp[(7) - (13)].number), (yyvsp[(8) - (13)].number), (yyvsp[(9) - (13)].number),
					(yyvsp[(10) - (13)].string), (yyvsp[(11) - (13)].string), (yyvsp[(12) - (13)].flagtype));
				SaveFree((yyvsp[(10) - (13)].string));
				SaveFree((yyvsp[(11) - (13)].string));
			}
    break;

  case 158:
#line 1617 "parse_y.y"
    {
				CreateNewPad(yyElement,(yyvsp[(3) - (13)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (13)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (13)].number)*100 + yyElement->MarkX,
					(yyvsp[(6) - (13)].number)*100 + yyElement->MarkY, (yyvsp[(7) - (13)].number)*100, (yyvsp[(8) - (13)].number)*100, (yyvsp[(9) - (13)].number)*100,
					(yyvsp[(10) - (13)].string), (yyvsp[(11) - (13)].string), OldFlags((yyvsp[(12) - (13)].number)));
				SaveFree((yyvsp[(10) - (13)].string));
				SaveFree((yyvsp[(11) - (13)].string));
			}
    break;

  case 159:
#line 1630 "parse_y.y"
    {
				CreateNewPad(yyElement,(yyvsp[(3) - (11)].number)*100,(yyvsp[(4) - (11)].number)*100,(yyvsp[(5) - (11)].number)*100,(yyvsp[(6) - (11)].number)*100,(yyvsp[(7) - (11)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(7) - (11)].number) + 2*MASKFRAME)*100, (yyvsp[(8) - (11)].string),(yyvsp[(9) - (11)].string), OldFlags((yyvsp[(10) - (11)].number)));
				SaveFree((yyvsp[(8) - (11)].string));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 160:
#line 1641 "parse_y.y"
    {
				char		p_number[8];

				sprintf(p_number, "%d", pin_num++);
				CreateNewPad(yyElement,(yyvsp[(3) - (10)].number)*100,(yyvsp[(4) - (10)].number)*100,(yyvsp[(5) - (10)].number)*100,(yyvsp[(6) - (10)].number)*100,(yyvsp[(7) - (10)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(7) - (10)].number) + 2*MASKFRAME)*100, (yyvsp[(8) - (10)].string),p_number, OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 161:
#line 1651 "parse_y.y"
    { (yyval.flagtype) = OldFlags((yyvsp[(1) - (1)].number)); }
    break;

  case 162:
#line 1652 "parse_y.y"
    { (yyval.flagtype) = string_to_flags ((yyvsp[(1) - (1)].string), yyerror); }
    break;

  case 165:
#line 1681 "parse_y.y"
    {
				if ((yyvsp[(3) - (6)].number) <= 0 || (yyvsp[(3) - (6)].number) > MAX_FONTPOSITION)
				{
					yyerror("fontposition out of range");
					YYABORT;
				}
				Symbol = &yyFont->Symbol[(yyvsp[(3) - (6)].number)];
				if (Symbol->Valid)
				{
					yyerror("symbol ID used twice");
					YYABORT;
				}
				Symbol->Valid = True;
				Symbol->Delta = (yyvsp[(4) - (6)].number);
			}
    break;

  case 167:
#line 1698 "parse_y.y"
    {
				if ((yyvsp[(3) - (6)].number) <= 0 || (yyvsp[(3) - (6)].number) > MAX_FONTPOSITION)
				{
					yyerror("fontposition out of range");
					YYABORT;
				}
				Symbol = &yyFont->Symbol[(yyvsp[(3) - (6)].number)];
				if (Symbol->Valid)
				{
					yyerror("symbol ID used twice");
					YYABORT;
				}
				Symbol->Valid = True;
				Symbol->Delta = (yyvsp[(4) - (6)].number)*100;
			}
    break;

  case 176:
#line 1751 "parse_y.y"
    {
				CreateNewLineInSymbol(Symbol, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, (yyvsp[(6) - (8)].number)*100, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 177:
#line 1758 "parse_y.y"
    {
				CreateNewLineInSymbol(Symbol, (yyvsp[(3) - (8)].number), (yyvsp[(4) - (8)].number), (yyvsp[(5) - (8)].number), (yyvsp[(6) - (8)].number), (yyvsp[(7) - (8)].number));
			}
    break;

  case 185:
#line 1812 "parse_y.y"
    {
				Menu = CreateNewNet(&yyPCB->NetlistLib, (yyvsp[(3) - (6)].string), (yyvsp[(4) - (6)].string));
				SaveFree((yyvsp[(3) - (6)].string));
				SaveFree((yyvsp[(4) - (6)].string));
			}
    break;

  case 191:
#line 1847 "parse_y.y"
    {
				CreateNewConnection(Menu, (yyvsp[(3) - (4)].string));
				SaveFree((yyvsp[(3) - (4)].string));
			}
    break;

  case 194:
#line 1880 "parse_y.y"
    {
				CreateNewAttribute (attr_list, (yyvsp[(3) - (5)].string), (yyvsp[(4) - (5)].string));
				SaveFree ((yyvsp[(3) - (5)].string));
				SaveFree ((yyvsp[(4) - (5)].string));
			}
    break;

  case 195:
#line 1887 "parse_y.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 196:
#line 1888 "parse_y.y"
    { (yyval.string) = 0; }
    break;


/* Line 1267 of yacc.c.  */
#line 2935 "parse_y.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1891 "parse_y.y"


/* ---------------------------------------------------------------------------
 * error routine called by parser library
 */
int yyerror(s)
const char *s;
{
	Message("ERROR parsing file '%s'\n"
		"    line:        %i\n"
		"    description: '%s'\n",
		yyfilename, yylineno, s);
	return(0);
}

int yywrap()
{
  return 1;
}


static int
check_file_version (int ver)
{
  if ( ver > PCB_FILE_VERSION ) {
    Message ("ERROR:  The file you are attempting to load is in a format\n"
	     "which is too new for this version of pcb.  To load this file\n"
	     "you need a version of pcb which is >= %d.  If you are\n"
	     "using a version built from cvs sources, the source date\n"
	     "must be >= %d.  This copy of pcb can only read files\n"
	     "up to file version %d.\n", ver, ver, PCB_FILE_VERSION);
    return 1;
  }
  
  return 0;
}




/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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
static	bool			LayerFlag[MAX_LAYER + 2];

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



/* Line 189 of yacc.c  */
#line 154 "parse_y.c"

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

/* Line 214 of yacc.c  */
#line 92 "parse_y.y"

	int		number;
	float		floating;
	char		*string;
	FlagType	flagtype;



/* Line 214 of yacc.c  */
#line 273 "parse_y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 285 "parse_y.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   719

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNRULES -- Number of states.  */
#define YYNSTATES  618

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
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
     353,   355,   357,   358,   361,   363,   374,   385,   395,   408,
     421,   433,   442,   452,   462,   463,   473,   474,   476,   479,
     480,   486,   488,   491,   496,   501,   502,   504,   506,   508,
     510,   512,   513,   526,   527,   543,   544,   561,   562,   581,
     582,   601,   603,   606,   608,   610,   612,   614,   616,   625,
     634,   645,   656,   662,   668,   669,   672,   674,   677,   679,
     681,   683,   685,   694,   703,   714,   725,   726,   729,   742,
     755,   766,   776,   785,   799,   813,   825,   836,   838,   840,
     842,   845,   846,   856,   857,   867,   869,   871,   873,   876,
     878,   880,   881,   890,   899,   901,   902,   909,   911,   912,
     914,   917,   918,   928,   930,   931,   933,   936,   941,   943,
     946,   952,   954
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    47,    -1,    50,    -1,     1,
      -1,    -1,    45,    52,    53,    54,    59,    60,    61,    62,
      66,    67,    68,    49,    69,   139,    -1,    -1,    46,   103,
      -1,    -1,    48,    69,    -1,    50,    -1,    -1,    -1,    51,
     130,    -1,    -1,     7,    38,     3,    39,    -1,     8,    40,
       6,    41,    -1,     8,    40,     6,     3,     3,    41,    -1,
       8,    38,     6,     3,     3,    39,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    20,    40,     3,     3,     3,
      41,    -1,    20,    40,     3,     3,     3,     3,    41,    -1,
      20,    40,     5,     3,     3,     3,    41,    -1,    20,    38,
       5,     3,     3,     3,    39,    -1,    24,    40,     3,     3,
       3,    41,    -1,    24,    38,     3,     3,     3,    39,    -1,
      24,    38,     3,     3,     5,    39,    -1,    -1,    -1,    34,
      38,     5,    39,    -1,    -1,    35,    38,     5,    39,    -1,
      -1,    63,    -1,    64,    -1,    65,    -1,    36,    38,     3,
       3,     3,    39,    -1,    36,    38,     3,     3,     3,     3,
      39,    -1,    36,    38,     3,     3,     3,     3,     3,     3,
      39,    -1,    21,    40,     3,    41,    -1,    21,    40,     6,
      41,    -1,    -1,    27,    40,     6,    41,    -1,    -1,    28,
      40,     6,    41,    -1,    28,    38,     6,    39,    -1,    -1,
      70,    -1,    -1,    71,    -1,    70,    71,    -1,    74,    -1,
      -1,    72,   148,    -1,    80,    -1,    81,    -1,    -1,    73,
     103,    -1,     1,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    10,    38,     3,     3,     3,     3,
       3,     3,     6,   129,    39,    -1,    10,    40,     3,     3,
       3,     3,     3,     3,     6,     3,    41,    -1,    10,    40,
       3,     3,     3,     3,     3,     6,     3,    41,    -1,    10,
      40,     3,     3,     3,     3,     6,     3,    41,    -1,    10,
      40,     3,     3,     3,     6,     3,    41,    -1,    11,    38,
       3,     3,     3,     3,     3,     3,   129,    39,    -1,    11,
      40,     3,     3,     3,     3,     3,     3,     3,    41,    -1,
      -1,     9,    40,     3,     6,   150,    41,    40,    82,    83,
      41,    -1,    84,    -1,    -1,    85,    -1,    84,    85,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    14,    40,     3,     3,     3,     3,     3,    41,
      -1,    95,    -1,    94,    -1,    93,    -1,    -1,    86,   148,
      -1,    96,    -1,    12,    38,     3,     3,     3,     3,     3,
       3,   129,    39,    -1,    12,    40,     3,     3,     3,     3,
       3,     3,     3,    41,    -1,    12,    40,     3,     3,     3,
       3,     3,     3,    41,    -1,    13,    38,     3,     3,     3,
       3,     3,     3,     3,     3,   129,    39,    -1,    13,    40,
       3,     3,     3,     3,     3,     3,     3,     3,     3,    41,
      -1,    13,    40,     3,     3,     3,     3,     3,     3,     3,
       3,    41,    -1,    15,    40,     3,     3,     3,     6,     3,
      41,    -1,    15,    40,     3,     3,     3,     3,     6,     3,
      41,    -1,    15,    38,     3,     3,     3,     3,     6,   129,
      39,    -1,    -1,    29,    40,   129,    41,    40,    97,   101,
      98,    41,    -1,    -1,    99,    -1,    98,    99,    -1,    -1,
      30,    40,   100,   101,    41,    -1,   102,    -1,   101,   102,
      -1,    40,     3,     3,    41,    -1,    38,     3,     3,    39,
      -1,    -1,   104,    -1,   106,    -1,   108,    -1,   110,    -1,
     112,    -1,    -1,    17,    40,     6,     6,     3,     3,     3,
      41,    40,   105,   114,    41,    -1,    -1,    17,    40,     3,
       6,     6,     3,     3,     3,     3,     3,    41,    40,   107,
     114,    41,    -1,    -1,    17,    40,     3,     6,     6,     6,
       3,     3,     3,     3,     3,    41,    40,   109,   114,    41,
      -1,    -1,    17,    40,     3,     6,     6,     6,     3,     3,
       3,     3,     3,     3,     3,    41,    40,   111,   117,    41,
      -1,    -1,    17,    38,   129,     6,     6,     6,     3,     3,
       3,     3,     3,     3,   129,    39,    40,   113,   117,    41,
      -1,   115,    -1,   114,   115,    -1,   122,    -1,   123,    -1,
     124,    -1,   127,    -1,   128,    -1,    16,    38,     3,     3,
       3,     3,     3,    39,    -1,    16,    40,     3,     3,     3,
       3,     3,    41,    -1,    25,    38,     3,     3,     3,     3,
       3,     3,     3,    39,    -1,    25,    40,     3,     3,     3,
       3,     3,     3,     3,    41,    -1,    26,    38,     3,     3,
      39,    -1,    26,    40,     3,     3,    41,    -1,    -1,   116,
     148,    -1,   118,    -1,   117,   118,    -1,   121,    -1,   120,
      -1,   126,    -1,   125,    -1,    16,    38,     3,     3,     3,
       3,     3,    39,    -1,    16,    40,     3,     3,     3,     3,
       3,    41,    -1,    25,    38,     3,     3,     3,     3,     3,
       3,     3,    39,    -1,    25,    40,     3,     3,     3,     3,
       3,     3,     3,    41,    -1,    -1,   119,   148,    -1,    18,
      38,     3,     3,     3,     3,     3,     3,     6,     6,   129,
      39,    -1,    18,    40,     3,     3,     3,     3,     3,     3,
       6,     6,     3,    41,    -1,    18,    40,     3,     3,     3,
       3,     6,     6,     3,    41,    -1,    18,    40,     3,     3,
       3,     3,     6,     3,    41,    -1,    18,    40,     3,     3,
       3,     6,     3,    41,    -1,    19,    38,     3,     3,     3,
       3,     3,     3,     3,     6,     6,   129,    39,    -1,    19,
      40,     3,     3,     3,     3,     3,     3,     3,     6,     6,
       3,    41,    -1,    19,    40,     3,     3,     3,     3,     3,
       6,     6,     3,    41,    -1,    19,    40,     3,     3,     3,
       3,     3,     6,     3,    41,    -1,     3,    -1,     6,    -1,
     131,    -1,   130,   131,    -1,    -1,    22,    38,   134,     3,
      39,    40,   132,   135,    41,    -1,    -1,    22,    40,   134,
       3,    41,    40,   133,   135,    41,    -1,     3,    -1,     4,
      -1,   136,    -1,   135,   136,    -1,   137,    -1,   138,    -1,
      -1,    23,    40,     3,     3,     3,     3,     3,    41,    -1,
      23,    38,     3,     3,     3,     3,     3,    39,    -1,   140,
      -1,    -1,    31,    40,    41,    40,   141,    41,    -1,   142,
      -1,    -1,   143,    -1,   142,   143,    -1,    -1,    32,    40,
       6,     6,    41,    40,   144,   145,    41,    -1,   146,    -1,
      -1,   147,    -1,   146,   147,    -1,    33,    40,     6,    41,
      -1,   149,    -1,   148,   149,    -1,    37,    40,     6,     6,
      41,    -1,     6,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   116,   117,   141,   141,   195,   195,
     206,   206,   225,   226,   231,   231,   270,   272,   302,   308,
     314,   343,   344,   345,   346,   349,   357,   370,   382,   414,
     420,   426,   432,   448,   450,   474,   476,   507,   509,   510,
     511,   515,   525,   536,   563,   567,   571,   599,   603,   647,
     655,   663,   667,   668,   672,   673,   677,   678,   678,   679,
     680,   682,   682,   689,   693,   694,   695,   696,   697,   733,
     742,   753,   763,   773,   809,   814,   846,   845,   869,   870,
     874,   875,   879,   880,   881,   882,   883,   884,   886,   891,
     892,   893,   894,   894,   895,   925,   933,   942,   990,   998,
    1007,  1044,  1054,  1072,  1122,  1121,  1160,  1162,  1163,  1168,
    1167,  1175,  1176,  1181,  1185,  1189,  1246,  1247,  1248,  1249,
    1250,  1258,  1257,  1276,  1275,  1294,  1293,  1314,  1312,  1335,
    1333,  1413,  1414,  1418,  1419,  1420,  1421,  1422,  1424,  1429,
    1434,  1439,  1444,  1449,  1454,  1454,  1458,  1459,  1463,  1464,
    1465,  1466,  1468,  1474,  1481,  1486,  1491,  1491,  1532,  1544,
    1556,  1567,  1583,  1637,  1651,  1664,  1675,  1686,  1687,  1691,
    1692,  1716,  1715,  1733,  1732,  1752,  1753,  1757,  1758,  1762,
    1763,  1764,  1785,  1792,  1808,  1809,  1813,  1818,  1819,  1823,
    1824,  1847,  1846,  1856,  1857,  1861,  1862,  1881,  1910,  1911,
    1914,  1922,  1923
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
  "T_POLYGON", "T_POLYGON_HOLE", "T_NETLIST", "T_NET", "T_CONN", "T_AREA",
  "T_THERMAL", "T_DRC", "T_ATTRIBUTE", "'['", "']'", "'('", "')'",
  "$accept", "parse", "parsepcb", "$@1", "$@2", "parsedata", "$@3",
  "pcbfont", "parsefont", "$@4", "pcbfileversion", "pcbname", "pcbgrid",
  "pcbgridold", "pcbgridnew", "pcb2grid", "pcbhigrid", "pcbcursor",
  "polyarea", "pcbthermal", "pcbdrc", "pcbdrc1", "pcbdrc2", "pcbdrc3",
  "pcbflags", "pcbgroups", "pcbstyles", "pcbdata", "pcbdefinitions",
  "pcbdefinition", "$@5", "$@6", "via", "via_hi_format", "via_2.0_format",
  "via_1.7_format", "via_newformat", "via_oldformat", "rats", "layer",
  "$@7", "layerdata", "layerdefinitions", "layerdefinition", "$@8",
  "line_hi_format", "line_1.7_format", "line_oldformat", "arc_hi_format",
  "arc_1.7_format", "arc_oldformat", "text_oldformat", "text_newformat",
  "text_hi_format", "polygon_format", "$@9", "polygonholes", "polygonhole",
  "$@10", "polygonpoints", "polygonpoint", "element", "element_oldformat",
  "$@11", "element_1.3.4_format", "$@12", "element_newformat", "$@13",
  "element_1.7_format", "$@14", "element_hi_format", "$@15",
  "elementdefinitions", "elementdefinition", "$@16", "relementdefs",
  "relementdef", "$@17", "pin_hi_format", "pin_1.7_format",
  "pin_1.6.3_format", "pin_newformat", "pin_oldformat", "pad_hi_format",
  "pad_1.7_format", "pad_newformat", "pad", "flags", "symbols", "symbol",
  "$@18", "$@19", "symbolid", "symboldata", "symboldefinitions",
  "symboldefinition", "hiressymbol", "pcbnetlist", "pcbnetdef", "nets",
  "netdefs", "net", "$@20", "connections", "conndefs", "conn",
  "attributes", "attribute", "opt_string", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,    91,    93,
      40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    45,    44,    46,    44,
      48,    47,    49,    49,    51,    50,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    55,    56,    57,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    63,    64,    65,    66,    66,    66,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    71,    72,    71,    71,
      71,    73,    71,    71,    74,    74,    74,    74,    74,    75,
      76,    77,    78,    79,    80,    80,    82,    81,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    85,    85,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    97,    96,    98,    98,    98,   100,
      99,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   105,   104,   107,   106,   109,   108,   111,   110,   113,
     112,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   115,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   119,   118,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   129,   130,
     130,   132,   131,   133,   131,   134,   134,   135,   135,   136,
     136,   136,   137,   138,   139,   139,   140,   141,   141,   142,
     142,   144,   143,   145,   145,   146,   146,   147,   148,   148,
     149,   150,   150
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
       1,     1,     0,     2,     1,    10,    10,     9,    12,    12,
      11,     8,     9,     9,     0,     9,     0,     1,     2,     0,
       5,     1,     2,     4,     4,     0,     1,     1,     1,     1,
       1,     0,    12,     0,    15,     0,    16,     0,    18,     0,
      18,     1,     2,     1,     1,     1,     1,     1,     8,     8,
      10,    10,     5,     5,     0,     2,     1,     2,     1,     1,
       1,     1,     8,     8,    10,    10,     0,     2,    12,    12,
      10,     9,     8,    13,    13,    11,    10,     1,     1,     1,
       2,     0,     9,     0,     9,     1,     1,     1,     2,     1,
       1,     0,     8,     8,     1,     0,     6,     1,     0,     1,
       2,     0,     9,     1,     0,     1,     2,     4,     1,     2,
       5,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,    16,     0,     3,     0,     4,     0,
       1,     0,     0,     0,     9,   116,   117,   118,   119,   120,
      63,     0,     0,     0,    11,     0,    54,     0,     0,    56,
      64,    65,    66,    67,    68,    59,    60,     0,    15,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    58,   198,    62,     0,     0,   170,     0,     0,
       0,     0,    32,    21,    22,    23,    24,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   175,
     176,     0,     0,    17,     0,     0,     0,     0,     0,    33,
       0,     0,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   171,   173,    20,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    38,    39,    40,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,   181,   181,     0,     0,    25,     0,     0,     0,     0,
      34,     0,     0,     0,    48,     0,     0,     0,     0,    79,
       0,     0,     0,     0,    73,     0,     0,     0,     0,   177,
     179,   180,     0,    28,    26,    27,    30,    31,    29,    36,
       0,     0,     0,    51,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,    78,    80,     0,    82,    83,    84,
      85,    86,    87,    91,    90,    89,    94,     0,     0,     0,
      72,     0,     0,     0,     0,   172,   178,   174,     0,     0,
       0,     0,     0,    13,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    81,    93,     0,
       0,    71,    74,    75,     0,     0,     0,    44,    45,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   131,     0,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
       0,     0,     0,    41,    47,     0,     0,   185,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   132,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    50,    49,     0,     7,   184,
       0,   144,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,   144,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,    43,     0,   129,
     124,   127,   144,     0,     0,     0,     0,     0,     0,   142,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   111,   183,   182,   188,   156,   156,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,   101,     0,     0,     0,     0,   107,   112,
       0,     0,   187,   189,     0,     0,     0,     0,   156,   146,
       0,   149,   148,   151,   150,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,   103,   102,
       0,     0,   109,   105,   108,     0,   186,   190,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   147,   157,   128,
     138,   139,     0,     0,   162,     0,     0,     0,    95,    96,
       0,     0,   114,   113,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   160,   166,     0,   140,   141,    98,    99,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   191,     0,     0,     0,     0,     0,     0,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   195,   152,   153,     0,     0,     0,     0,     0,
       0,     0,   192,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,   155,   197,     0,     0,
       0,     0,   158,   159,     0,     0,   163,   164
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,   282,     8,     9,
      12,    42,    62,    63,    64,    65,    66,    89,   110,   132,
     156,   157,   158,   159,   184,   213,   253,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     189,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   394,   447,   448,   514,   421,
     422,    14,    15,   257,    16,   351,    17,   377,    18,   427,
      19,   426,   292,   293,   294,   458,   459,   460,   461,   462,
     295,   296,   297,   463,   464,   298,   299,    69,    38,    39,
     171,   172,    81,   198,   199,   200,   201,   348,   349,   451,
     452,   453,   570,   580,   581,   582,    52,    53,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -419
static const yytype_int16 yypact[] =
{
      12,  -419,    57,  -419,    69,    71,  -419,    16,  -419,    39,
    -419,    51,    90,   122,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,    65,   125,   126,  -419,    41,  -419,    75,    71,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,   129,    39,  -419,
     103,   130,    93,    56,   105,   127,   138,   156,   180,   186,
    -419,    82,    75,  -419,  -419,    32,    32,  -419,    86,   123,
     201,   134,   184,  -419,  -419,  -419,  -419,  -419,  -419,   203,
     204,   205,   206,   210,   211,   212,   214,   213,  -419,  -419,
    -419,   215,   217,  -419,   218,     3,   148,   168,   137,   189,
     219,   220,   221,   222,   224,   226,   227,   228,   229,   193,
     192,   231,   234,  -419,   235,   236,   237,   238,   240,   207,
     209,   241,   120,   243,  -419,   208,   245,   133,   247,   248,
     216,   223,   225,   230,   232,   249,   250,   251,   252,   253,
     254,   233,   239,   255,   257,   258,   259,   242,   261,   139,
     263,   264,   265,  -419,  -419,  -419,  -419,  -419,   267,     4,
     269,   173,   271,   244,   272,   246,   260,  -419,  -419,  -419,
     273,   275,   276,   256,  -419,   282,   143,   283,   262,   284,
     285,   266,   266,   268,   270,  -419,   274,   278,   279,   280,
    -419,   281,   287,   286,   277,   288,   289,   290,   291,    54,
     292,   293,   297,   294,  -419,    56,   298,   141,    -9,  -419,
    -419,  -419,    14,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
     299,   144,   296,   295,   302,   303,   305,  -419,   142,   146,
     300,   147,   301,   304,    54,  -419,    75,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,    56,   306,   307,
    -419,   308,   309,   310,   311,  -419,  -419,  -419,   316,   312,
     313,   318,   150,   315,   319,   314,   322,    74,   324,   325,
     326,   327,   329,   330,   331,    56,  -419,  -419,    75,   317,
     320,  -419,  -419,  -419,   335,   336,    15,  -419,  -419,   321,
     337,   338,    64,  -419,   339,   323,     5,   153,   328,   332,
     154,   157,    78,  -419,    75,  -419,  -419,  -419,  -419,  -419,
     343,   346,   348,   349,   354,   355,   356,   333,  -419,  -419,
     357,   361,    21,  -419,  -419,   334,   340,   344,    56,  -419,
     362,   342,   363,   364,   366,   367,   368,   373,   374,   375,
    -419,  -419,    75,   376,   377,   380,   381,   382,   383,   384,
     350,   385,   386,   388,  -419,  -419,  -419,   352,  -419,  -419,
     358,    74,   353,  -419,   390,   392,   393,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   405,   406,   145,  -419,
     407,   408,   378,   371,   379,    91,   387,    74,   410,   411,
     412,   415,   417,   418,   389,   391,   419,   420,   421,   422,
     423,   424,   425,   426,   158,   394,   404,  -419,   409,  -419,
    -419,  -419,   102,   431,   432,   149,   433,   434,   435,  -419,
    -419,   436,   437,   438,   439,   413,    56,   440,   414,   441,
     444,     0,  -419,  -419,  -419,   416,   119,   119,  -419,   447,
     448,   446,   450,   453,   454,   455,    56,     6,   456,   457,
    -419,   427,   428,  -419,   458,   459,   430,    -2,  -419,  -419,
     442,   443,   416,  -419,   161,   162,   165,   166,    61,  -419,
      75,  -419,  -419,  -419,  -419,   115,   429,   445,   151,   449,
     461,   460,   462,   452,   451,  -419,   468,   469,  -419,  -419,
     463,   464,  -419,  -419,  -419,   467,  -419,  -419,   471,   472,
     473,   474,   475,   476,   477,   478,  -419,  -419,    75,  -419,
    -419,  -419,   465,   480,  -419,   155,   482,   484,  -419,  -419,
      56,     7,  -419,  -419,   158,   483,   485,   490,   491,   492,
     493,   494,   495,   496,  -419,   466,   470,   497,   479,   481,
     486,   487,  -419,    44,   488,   498,   500,   501,   505,   506,
     507,   509,   510,  -419,  -419,   489,  -419,  -419,  -419,  -419,
    -419,   499,   511,   512,   513,   514,   516,   517,   518,   520,
    -419,  -419,   521,   523,   524,   528,   529,   530,   531,   532,
     503,   502,   504,   534,   535,   537,   539,   540,   541,   508,
     515,   503,  -419,  -419,  -419,   543,   544,   548,   549,   550,
     551,   552,  -419,  -419,   553,   554,   555,   556,   525,   522,
     526,    56,   562,   560,   563,  -419,  -419,  -419,   533,   527,
      56,   567,  -419,  -419,   536,   538,  -419,  -419
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,    42,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,    28,  -419,   546,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,    70,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -151,  -419,  -202,
    -418,   519,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -346,  -288,  -419,    37,  -402,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -194,  -419,   542,
    -419,  -419,   545,   547,  -187,  -419,  -419,  -419,  -419,  -419,
    -419,    94,  -419,  -419,  -419,   -26,  -224,   -52,  -419
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      78,   241,   268,   449,   331,   375,   102,   174,   320,   474,
     531,   246,   -10,     1,   197,   246,   -53,    20,   312,    -6,
      -6,   -10,   -10,   -10,   343,    21,    22,    23,   446,    -8,
     446,   402,   245,   -61,   -14,    79,    80,   197,   419,   483,
     420,   -52,    20,   269,   103,   175,   321,   475,   532,   -10,
      21,    22,    23,   -57,   313,   247,   497,    10,   -61,    67,
     344,    37,    68,   497,   -53,    20,   218,   219,   220,   221,
     332,   307,   -52,    21,    22,    23,    11,   454,   -57,   455,
     456,   -61,   419,   222,   420,   550,   457,   331,    13,    40,
     287,   -92,   288,   289,   287,   -53,   288,   289,    41,   290,
     291,   -57,   496,   290,   291,    45,    58,   287,    70,   288,
     289,    71,    51,    61,   331,   449,   290,   291,   287,   330,
     288,   289,    77,   134,   350,    83,   135,   290,   291,    84,
      72,   454,   400,   455,   456,   454,   139,   455,   456,   140,
     457,    73,   166,   428,   457,   167,   191,   249,   392,   192,
     250,   393,   431,   104,   502,   432,   499,   503,   526,    74,
      43,   527,    44,    46,    48,    47,    49,    55,    59,    56,
      60,   105,    86,   106,    87,   107,   177,   108,   178,   243,
     258,   244,   259,    75,   260,   263,   261,   264,   280,    76,
     281,   322,   326,   323,   327,   328,   419,   329,   420,   488,
     490,   489,   491,   492,   494,   493,   495,    85,    88,    90,
      91,    92,    93,    94,    95,    96,    78,    97,    99,    98,
     100,   101,   441,   109,   113,   111,   112,   116,   114,   117,
     118,   119,   121,   122,   123,   120,   498,   124,   125,   126,
     127,   128,   473,   129,   131,   130,   136,   133,   138,   137,
     141,   142,   148,   149,   150,   151,   152,   143,   160,   153,
     161,   162,   163,   144,   165,   145,   168,   169,   170,   146,
     173,   154,   176,   147,   179,   155,   185,   181,   186,   187,
      78,   183,   164,   180,   182,   190,   193,   195,   196,   197,
     210,   214,   215,   216,   267,   283,   484,   188,   237,   238,
     239,   242,   248,   194,   212,   254,   255,   203,   256,   270,
     317,   204,   533,   274,   275,   205,   530,   206,   207,   276,
     209,   208,   284,   252,   279,   286,   211,   300,   301,   302,
     303,   217,   304,   305,   306,   240,   251,   -14,   310,   311,
     262,   265,   318,   315,   316,   266,   333,   272,   271,   334,
     273,   335,   336,   277,   278,   285,   308,   337,   338,   339,
     341,   309,   314,   319,   342,   352,   354,   355,   324,   356,
     357,   358,   325,   345,   340,   347,   359,   360,   361,   362,
     363,   346,   353,   364,   365,   366,   367,   368,   370,   371,
     369,   372,   373,   378,   376,   379,   380,   374,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   608,   390,   391,
     395,   396,   398,   403,   404,   405,   614,   397,   406,   399,
     407,   408,   411,   412,   413,   414,   415,   401,   409,   418,
     416,   417,   410,   423,   429,   430,   433,   434,   435,   436,
     437,   438,   439,   442,   444,   424,    78,   445,   450,   425,
     466,   467,   468,   469,   440,   443,   470,   471,   472,   476,
     477,   480,   481,   506,   465,   507,   478,   505,   500,   479,
     482,   510,   511,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   485,   525,   486,   528,   501,   529,   535,   534,
     504,   508,   509,   536,   537,   538,   539,   540,   541,   542,
     545,   552,   512,   553,   554,   513,   524,   543,   555,   556,
     557,   544,   558,   559,   562,   563,   564,   565,   546,   566,
     567,   568,   547,   569,   571,   548,   572,   573,   549,   551,
     560,   574,   575,   576,   577,   578,   579,   585,   586,   561,
     587,   583,   588,   589,   590,   584,   487,    54,   591,   594,
     595,   596,   597,   598,   599,   593,   592,     0,   600,   601,
     602,   603,   604,   606,   605,   609,   610,   607,   613,   611,
     615,    50,   612,     0,     0,   616,     0,     0,     0,   617,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202
};

static const yytype_int16 yycheck[] =
{
      52,   195,   226,   421,   292,   351,     3,     3,     3,     3,
       3,   198,     0,     1,    23,   202,     0,     1,     3,     7,
       8,     9,    10,    11,     3,     9,    10,    11,    30,    17,
      30,   377,    41,    17,    22,     3,     4,    23,    38,    41,
      40,     0,     1,   237,    41,    41,    41,    41,    41,    37,
       9,    10,    11,    37,    39,    41,   458,     0,    17,     3,
      39,    22,     6,   465,     0,     1,    12,    13,    14,    15,
     294,   265,    31,     9,    10,    11,     7,    16,    37,    18,
      19,    17,    38,    29,    40,    41,    25,   375,    17,    38,
      16,    37,    18,    19,    16,    31,    18,    19,     8,    25,
      26,    37,    41,    25,    26,    40,     3,    16,     3,    18,
      19,     6,    37,    20,   402,   533,    25,    26,    16,    41,
      18,    19,    40,     3,   318,    39,     6,    25,    26,     6,
       3,    16,    41,    18,    19,    16,     3,    18,    19,     6,
      25,     3,     3,    41,    25,     6,     3,     3,     3,     6,
       6,     6,     3,     5,     3,     6,    41,     6,     3,     3,
      38,     6,    40,    38,    38,    40,    40,    38,    38,    40,
      40,     3,    38,     5,    40,    38,     3,    40,     5,    38,
      38,    40,    40,     3,    38,    38,    40,    40,    38,     3,
      40,    38,    38,    40,    40,    38,    38,    40,    40,    38,
      38,    40,    40,    38,    38,    40,    40,     6,    24,     6,
       6,     6,     6,     3,     3,     3,   268,     3,     3,     6,
       3,     3,   416,    34,     3,     6,     6,     3,     6,     3,
       3,     3,    39,    41,     3,     6,   460,     3,     3,     3,
       3,     3,   436,     3,    35,    38,     3,     6,     3,    41,
       3,     3,     3,     3,     3,     3,     3,    41,     3,     5,
       3,     3,     3,    40,     3,    40,     3,     3,     3,    39,
       3,    38,     3,    41,     3,    36,     3,     5,     3,     3,
     332,    21,    40,    39,    38,     3,     3,     3,     3,    23,
       3,     3,     3,     3,   224,   253,   447,    41,     6,     6,
       3,     3,     3,    41,    27,     3,     3,    39,     3,     3,
     282,    41,   514,     3,     3,    41,   510,    39,    39,     3,
      39,    41,     3,    28,     6,     3,    40,     3,     3,     3,
       3,    40,     3,     3,     3,    41,    40,    22,     3,     3,
      40,    40,     3,     6,     6,    41,     3,    39,    41,     3,
      41,     3,     3,    41,    41,    41,    39,     3,     3,     3,
       3,    41,    41,    40,     3,     3,     3,     3,    40,     3,
       3,     3,    40,    39,    41,    31,     3,     3,     3,     3,
       3,    41,    40,     3,     3,     3,     3,     3,     3,     3,
      40,     3,    40,     3,    41,     3,     3,    39,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   601,     3,     3,
       3,     3,    41,     3,     3,     3,   610,    39,     3,    40,
       3,     3,     3,     3,     3,     3,     3,    40,    39,     3,
       6,     6,    41,    39,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,    41,   498,     3,    32,    40,
       3,     3,     6,     3,    41,    41,     3,     3,     3,     3,
       3,     3,     3,     3,   427,     3,    39,     6,    39,    41,
      40,     3,     3,     6,     3,     3,     3,     3,     3,     3,
       3,     3,    40,     3,    41,     3,    41,     3,     3,     6,
      41,    39,    41,     3,     3,     3,     3,     3,     3,     3,
       3,     3,    39,     3,     3,    41,    41,    41,     3,     3,
       3,    41,     3,     3,     3,     3,     3,     3,    39,     3,
       3,     3,    41,     3,     3,    39,     3,     3,    41,    41,
      41,     3,     3,     3,     3,     3,    33,     3,     3,    40,
       3,    39,     3,     3,     3,    41,   452,    28,    40,     6,
       6,     3,     3,     3,     3,   581,    41,    -1,     6,     6,
       6,     6,     6,    41,    39,     3,     6,    41,    41,     6,
       3,    25,    39,    -1,    -1,    39,    -1,    -1,    -1,    41,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    43,    44,    45,    46,    47,    48,    50,    51,
       0,     7,    52,    17,   103,   104,   106,   108,   110,   112,
       1,     9,    10,    11,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    22,   130,   131,
      38,     8,    53,    38,    40,    40,    38,    40,    38,    40,
      71,    37,   148,   149,   103,    38,    40,   131,     3,    38,
      40,    20,    54,    55,    56,    57,    58,     3,     6,   129,
       3,     6,     3,     3,     3,     3,     3,    40,   149,     3,
       4,   134,   134,    39,     6,     6,    38,    40,    24,    59,
       6,     6,     6,     6,     3,     3,     3,     3,     6,     3,
       3,     3,     3,    41,     5,     3,     5,    38,    40,    34,
      60,     6,     6,     3,     6,   150,     3,     3,     3,     3,
       6,    39,    41,     3,     3,     3,     3,     3,     3,     3,
      38,    35,    61,     6,     3,     6,     3,    41,     3,     3,
       6,     3,     3,    41,    40,    40,    39,    41,     3,     3,
       3,     3,     3,     5,    38,    36,    62,    63,    64,    65,
       3,     3,     3,     3,    40,     3,     3,     6,     3,     3,
       3,   132,   133,     3,     3,    41,     3,     3,     5,     3,
      39,     5,    38,    21,    66,     3,     3,     3,    41,    82,
       3,     3,     6,     3,    41,     3,     3,    23,   135,   136,
     137,   138,   135,    39,    41,    41,    39,    39,    41,    39,
       3,    40,    27,    67,     3,     3,     3,    40,    12,    13,
      14,    15,    29,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     6,     6,     3,
      41,   129,     3,    38,    40,    41,   136,    41,     3,     3,
       6,    40,    28,    68,     3,     3,     3,   105,    38,    40,
      38,    40,    40,    38,    40,    40,    41,    85,   148,   129,
       3,    41,    39,    41,     3,     3,     3,    41,    41,     6,
      38,    40,    49,    50,     3,    41,     3,    16,    18,    19,
      25,    26,   114,   115,   116,   122,   123,   124,   127,   128,
       3,     3,     3,     3,     3,     3,     3,   129,    39,    41,
       3,     3,     3,    39,    41,     6,     6,    69,     3,    40,
       3,    41,    38,    40,    40,    40,    38,    40,    38,    40,
      41,   115,   148,     3,     3,     3,     3,     3,     3,     3,
      41,     3,     3,     3,    39,    39,    41,    31,   139,   140,
     129,   107,     3,    40,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,    40,
       3,     3,     3,    40,    39,   114,    41,   109,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,    97,     3,     3,    39,    41,    40,
      41,    40,   114,     3,     3,     3,     3,     3,     3,    39,
      41,     3,     3,     3,     3,     3,     6,     6,     3,    38,
      40,   101,   102,    39,    41,    40,   113,   111,    41,     3,
       3,     3,     6,     3,     3,     3,     3,     3,     3,     3,
      41,   129,     3,    41,     3,     3,    30,    98,    99,   102,
      32,   141,   142,   143,    16,    18,    19,    25,   117,   118,
     119,   120,   121,   125,   126,   117,     3,     3,     6,     3,
       3,     3,     3,   129,     3,    41,     3,     3,    39,    41,
       3,     3,    40,    41,    99,    40,    41,   143,    38,    40,
      38,    40,    38,    40,    38,    40,    41,   118,   148,    41,
      39,    41,     3,     6,    41,     6,     3,     3,    39,    41,
       3,     3,    39,    41,   100,     6,     3,     3,     3,     3,
       3,     3,     3,     3,    41,     3,     3,     6,     3,     3,
     129,     3,    41,   101,     6,     3,     3,     3,     3,     3,
       3,     3,     3,    41,    41,     3,    39,    41,    39,    41,
      41,    41,     3,     3,     3,     3,     3,     3,     3,     3,
      41,    40,     3,     3,     3,     3,     3,     3,     3,     3,
     144,     3,     3,     3,     3,     3,     3,     3,     3,    33,
     145,   146,   147,    39,    41,     3,     3,     3,     3,     3,
       3,    40,    41,   147,     6,     6,     3,     3,     3,     3,
       6,     6,     6,     6,     6,    39,    41,    41,   129,     3,
       6,     6,    39,    41,   129,     3,    39,    41
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 117 "parse_y.y"
    { YYABORT; }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 141 "parse_y.y"
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
					LayerFlag[i] = false;
				yyFont = &yyPCB->Font;
				yyData = yyPCB->Data;
				yyData->pcb = (void *)yyPCB;
				yyData->LayerN = 0;
				layer_group_string = NULL;
			}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 173 "parse_y.y"
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

/* Line 1455 of yacc.c  */
#line 195 "parse_y.y"
    { PreLoadElementPCB ();
		    layer_group_string = NULL; }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 198 "parse_y.y"
    { LayerFlag[0] = true;
		    LayerFlag[1] = true;
		    yyData->LayerN = 2;
		    PostLoadElementPCB ();
		  }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 206 "parse_y.y"
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
					LayerFlag[i] = false;
				yyData->LayerN = 0;
			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 231 "parse_y.y"
    {
					/* mark all symbols invalid */
				int	i;

				if (!yyFont)
				{
					Message("illegal fileformat\n");
					YYABORT;
				}
				yyFont->Valid = false;
				for (i = 0; i <= MAX_FONTPOSITION; i++)
					yyFont->Symbol[i].Valid = false;
			}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 245 "parse_y.y"
    {
				yyFont->Valid = true;
		  		SetFontInfo(yyFont);
			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 273 "parse_y.y"
    {
  if (check_file_version ((yyvsp[(3) - (4)].number)) != 0)
    {
      YYABORT;
    }
}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 303 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (4)].string);
				yyPCB->MaxWidth = MAX_COORD;
				yyPCB->MaxHeight = MAX_COORD;
			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 309 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (6)].string);
				yyPCB->MaxWidth = (yyvsp[(4) - (6)].number)*100;
				yyPCB->MaxHeight = (yyvsp[(5) - (6)].number)*100;
			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 315 "parse_y.y"
    {
				yyPCB->Name = (yyvsp[(3) - (6)].string);
				yyPCB->MaxWidth = (yyvsp[(4) - (6)].number);
				yyPCB->MaxHeight = (yyvsp[(5) - (6)].number);
			}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 350 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (6)].number)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (6)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (6)].number)*100;
			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 358 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].number)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number)*100;
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = true;
				else
					Settings.DrawGrid = false;
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 371 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].floating)*100;
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number)*100;
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number)*100;
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = true;
				else
					Settings.DrawGrid = false;
			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 383 "parse_y.y"
    {
				yyPCB->Grid = (yyvsp[(3) - (7)].floating);
				yyPCB->GridOffsetX = (yyvsp[(4) - (7)].number);
				yyPCB->GridOffsetY = (yyvsp[(5) - (7)].number);
				if ((yyvsp[(6) - (7)].number))
					Settings.DrawGrid = true;
				else
					Settings.DrawGrid = false;
			}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 415 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number)*100;
				yyPCB->CursorY = (yyvsp[(4) - (6)].number)*100;
				yyPCB->Zoom = (yyvsp[(5) - (6)].number)*2;
			}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 421 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number);
				yyPCB->CursorY = (yyvsp[(4) - (6)].number);
				yyPCB->Zoom = (yyvsp[(5) - (6)].number);
			}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 427 "parse_y.y"
    {
				yyPCB->CursorX = (yyvsp[(3) - (6)].number);
				yyPCB->CursorY = (yyvsp[(4) - (6)].number);
				yyPCB->Zoom = (yyvsp[(5) - (6)].floating);
			}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 451 "parse_y.y"
    {
				yyPCB->IsleArea = (yyvsp[(3) - (4)].floating);
			}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 477 "parse_y.y"
    {
				yyPCB->ThermScale = (yyvsp[(3) - (4)].floating);
			}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 516 "parse_y.y"
    {
				yyPCB->Bloat = (yyvsp[(3) - (6)].number);
				yyPCB->Shrink = (yyvsp[(4) - (6)].number);
				yyPCB->minWid = (yyvsp[(5) - (6)].number);
				yyPCB->minRing = (yyvsp[(5) - (6)].number);
			}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 526 "parse_y.y"
    {
				yyPCB->Bloat = (yyvsp[(3) - (7)].number);
				yyPCB->Shrink = (yyvsp[(4) - (7)].number);
				yyPCB->minWid = (yyvsp[(5) - (7)].number);
				yyPCB->minSlk = (yyvsp[(6) - (7)].number);
				yyPCB->minRing = (yyvsp[(5) - (7)].number);
			}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 537 "parse_y.y"
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

/* Line 1455 of yacc.c  */
#line 564 "parse_y.y"
    {
				yyPCB->Flags = MakeFlags ((yyvsp[(3) - (4)].number) & PCB_FLAGS);
			}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 568 "parse_y.y"
    {
			  yyPCB->Flags = string_to_pcbflags ((yyvsp[(3) - (4)].string), yyerror);
			}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 600 "parse_y.y"
    {
			  layer_group_string = (yyvsp[(3) - (4)].string);
			}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 648 "parse_y.y"
    {
				if (ParseRouteString((yyvsp[(3) - (4)].string), &yyPCB->RouteStyle[0], 100))
				{
					Message("illegal route-style string\n");
					YYABORT;
				}
			}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 656 "parse_y.y"
    {
				if (ParseRouteString((yyvsp[(3) - (4)].string), &yyPCB->RouteStyle[0], 1))
				{
					Message("illegal route-style string\n");
					YYABORT;
				}
			}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 678 "parse_y.y"
    { attr_list = & yyPCB->Attributes; }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 682 "parse_y.y"
    {
					/* clear pointer to force memory allocation by 
					 * the appropriate subroutine
					 */
				yyElement = NULL;
			}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 689 "parse_y.y"
    { YYABORT; }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 734 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (11)].number), (yyvsp[(4) - (11)].number), (yyvsp[(5) - (11)].number), (yyvsp[(6) - (11)].number), (yyvsp[(7) - (11)].number), (yyvsp[(8) - (11)].number), (yyvsp[(9) - (11)].string), (yyvsp[(10) - (11)].flagtype));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 743 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (11)].number)*100, (yyvsp[(4) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(6) - (11)].number)*100, (yyvsp[(7) - (11)].number)*100, (yyvsp[(8) - (11)].number)*100, (yyvsp[(9) - (11)].string),
					OldFlags((yyvsp[(10) - (11)].number)));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 754 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100,
					     ((yyvsp[(5) - (10)].number) + (yyvsp[(6) - (10)].number))*100, (yyvsp[(7) - (10)].number)*100, (yyvsp[(8) - (10)].string), OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 764 "parse_y.y"
    {
				CreateNewVia(yyData, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (9)].number) + 2*MASKFRAME)*100,  (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].string), OldFlags((yyvsp[(8) - (9)].number)));
				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 774 "parse_y.y"
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

/* Line 1455 of yacc.c  */
#line 810 "parse_y.y"
    {
				CreateNewRat(yyData, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(8) - (10)].number),
					Settings.RatThickness, (yyvsp[(9) - (10)].flagtype));
			}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 815 "parse_y.y"
    {
				CreateNewRat(yyData, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number)*100, (yyvsp[(5) - (10)].number), (yyvsp[(8) - (10)].number),
					Settings.RatThickness, OldFlags((yyvsp[(9) - (10)].number)));
			}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 846 "parse_y.y"
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
				LayerFlag[(yyvsp[(3) - (7)].number)-1] = true;
				if (yyData->LayerN + 2 < (yyvsp[(3) - (7)].number))
				  yyData->LayerN = (yyvsp[(3) - (7)].number) - 2;
			}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 887 "parse_y.y"
    {
				CreateNewPolygonFromRectangle(Layer,
					(yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, ((yyvsp[(3) - (8)].number)+(yyvsp[(5) - (8)].number))*100, ((yyvsp[(4) - (8)].number)+(yyvsp[(6) - (8)].number))*100, OldFlags((yyvsp[(7) - (8)].number)));
			}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 894 "parse_y.y"
    { attr_list = & Layer->Attributes; }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 926 "parse_y.y"
    {
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].flagtype));
			}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 934 "parse_y.y"
    {
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100,
						     (yyvsp[(7) - (10)].number)*100, (yyvsp[(8) - (10)].number)*100, OldFlags((yyvsp[(9) - (10)].number)));
			}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 943 "parse_y.y"
    {
				/* eliminate old-style rat-lines */
			if (((yyvsp[(8) - (9)].number) & RATFLAG) == 0)
				CreateNewLineOnLayer(Layer, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].number)*100,
					200*GROUNDPLANEFRAME, OldFlags((yyvsp[(8) - (9)].number)));
			}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 991 "parse_y.y"
    {
			  CreateNewArcOnLayer(Layer, (yyvsp[(3) - (12)].number), (yyvsp[(4) - (12)].number), (yyvsp[(5) - (12)].number), (yyvsp[(6) - (12)].number), (yyvsp[(9) - (12)].number), (yyvsp[(10) - (12)].number), (yyvsp[(7) - (12)].number), (yyvsp[(8) - (12)].number), (yyvsp[(11) - (12)].flagtype));
			}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 999 "parse_y.y"
    {
				CreateNewArcOnLayer(Layer, (yyvsp[(3) - (12)].number)*100, (yyvsp[(4) - (12)].number)*100, (yyvsp[(5) - (12)].number)*100, (yyvsp[(6) - (12)].number)*100, (yyvsp[(9) - (12)].number), (yyvsp[(10) - (12)].number),
						    (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number)*100, OldFlags((yyvsp[(11) - (12)].number)));
			}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1008 "parse_y.y"
    {
				CreateNewArcOnLayer(Layer, (yyvsp[(3) - (11)].number)*100, (yyvsp[(4) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(5) - (11)].number)*100, (yyvsp[(8) - (11)].number), (yyvsp[(9) - (11)].number),
					(yyvsp[(7) - (11)].number)*100, 200*GROUNDPLANEFRAME, OldFlags((yyvsp[(10) - (11)].number)));
			}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1045 "parse_y.y"
    {
					/* use a default scale of 100% */
				CreateNewText(Layer,yyFont,(yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number), 100, (yyvsp[(6) - (8)].string), OldFlags((yyvsp[(7) - (8)].number)));
				SaveFree((yyvsp[(6) - (8)].string));
			}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1055 "parse_y.y"
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

  case 103:

/* Line 1455 of yacc.c  */
#line 1073 "parse_y.y"
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

  case 104:

/* Line 1455 of yacc.c  */
#line 1122 "parse_y.y"
    {
				Polygon = CreateNewPolygon(Layer, (yyvsp[(3) - (5)].flagtype));
			}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1127 "parse_y.y"
    {
				Cardinal contour, contour_start, contour_end;
				bool bad_contour_found = false;
				/* ignore junk */
				for (contour = 0; contour <= Polygon->HoleIndexN; contour++)
				  {
				    contour_start = (contour == 0) ?
						      0 : Polygon->HoleIndex[contour - 1];
				    contour_end = (contour == Polygon->HoleIndexN) ?
						 Polygon->PointN :
						 Polygon->HoleIndex[contour];
				    if (contour_end - contour_start < 3)
				      bad_contour_found = true;
				  }

				if (bad_contour_found)
				  {
				    Message("WARNING parsing file '%s'\n"
					    "    line:        %i\n"
					    "    description: 'ignored polygon (< 3 points in a contour)'\n",
					    yyfilename, yylineno);
				    DestroyObject(yyData, POLYGON_TYPE, Layer, Polygon, Polygon);
				  }
				else
				  {
				    SetPolygonBoundingBox (Polygon);
				    if (!Layer->polygon_tree)
				      Layer->polygon_tree = r_create_tree (NULL, 0, 0);
				    r_insert_entry (Layer->polygon_tree, (BoxType *) Polygon, 0);
				  }
			}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1168 "parse_y.y"
    {
				CreateNewHoleInPolygon (Polygon);
			}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1182 "parse_y.y"
    {
				CreateNewPointInPolygon(Polygon, (yyvsp[(2) - (4)].number)*100, (yyvsp[(3) - (4)].number)*100);
			}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1186 "parse_y.y"
    {
				CreateNewPointInPolygon(Polygon, (yyvsp[(2) - (4)].number), (yyvsp[(3) - (4)].number));
			}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1258 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, NoFlags(),
					(yyvsp[(3) - (9)].string), (yyvsp[(4) - (9)].string), NULL, (yyvsp[(5) - (9)].number)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].number), 100, NoFlags(), false);
				SaveFree((yyvsp[(3) - (9)].string));
				SaveFree((yyvsp[(4) - (9)].string));
				pin_num = 1;
			}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1266 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1276 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (12)].number)),
					(yyvsp[(4) - (12)].string), (yyvsp[(5) - (12)].string), NULL, (yyvsp[(6) - (12)].number)*100, (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number), (yyvsp[(9) - (12)].number), OldFlags((yyvsp[(10) - (12)].number)), false);
				SaveFree((yyvsp[(4) - (12)].string));
				SaveFree((yyvsp[(5) - (12)].string));
				pin_num = 1;
			}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1284 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1294 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (13)].number)),
					(yyvsp[(4) - (13)].string), (yyvsp[(5) - (13)].string), (yyvsp[(6) - (13)].string), (yyvsp[(7) - (13)].number)*100, (yyvsp[(8) - (13)].number)*100, (yyvsp[(9) - (13)].number), (yyvsp[(10) - (13)].number), OldFlags((yyvsp[(11) - (13)].number)), false);
				SaveFree((yyvsp[(4) - (13)].string));
				SaveFree((yyvsp[(5) - (13)].string));
				SaveFree((yyvsp[(6) - (13)].string));
				pin_num = 1;
			}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1303 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1314 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, OldFlags((yyvsp[(3) - (15)].number)),
					(yyvsp[(4) - (15)].string), (yyvsp[(5) - (15)].string), (yyvsp[(6) - (15)].string), ((yyvsp[(7) - (15)].number)+(yyvsp[(9) - (15)].number))*100, ((yyvsp[(8) - (15)].number)+(yyvsp[(10) - (15)].number))*100, (yyvsp[(11) - (15)].number), (yyvsp[(12) - (15)].number), OldFlags((yyvsp[(13) - (15)].number)), false);
				yyElement->MarkX = (yyvsp[(7) - (15)].number)*100;
				yyElement->MarkY = (yyvsp[(8) - (15)].number)*100;
				SaveFree((yyvsp[(4) - (15)].string));
				SaveFree((yyvsp[(5) - (15)].string));
				SaveFree((yyvsp[(6) - (15)].string));
			}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1324 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1335 "parse_y.y"
    {
				yyElement = CreateNewElement(yyData, yyElement, yyFont, (yyvsp[(3) - (15)].flagtype),
					(yyvsp[(4) - (15)].string), (yyvsp[(5) - (15)].string), (yyvsp[(6) - (15)].string), ((yyvsp[(7) - (15)].number)+(yyvsp[(9) - (15)].number)), ((yyvsp[(8) - (15)].number)+(yyvsp[(10) - (15)].number)), (yyvsp[(11) - (15)].number), (yyvsp[(12) - (15)].number), (yyvsp[(13) - (15)].flagtype), false);
				yyElement->MarkX = (yyvsp[(7) - (15)].number);
				yyElement->MarkY = (yyvsp[(8) - (15)].number);
				SaveFree((yyvsp[(4) - (15)].string));
				SaveFree((yyvsp[(5) - (15)].string));
				SaveFree((yyvsp[(6) - (15)].string));
			}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1345 "parse_y.y"
    {
				SetElementBoundingBox(yyData, yyElement, yyFont);
			}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1425 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number), (yyvsp[(4) - (8)].number), (yyvsp[(5) - (8)].number), (yyvsp[(6) - (8)].number), (yyvsp[(7) - (8)].number));
			}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1430 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, (yyvsp[(6) - (8)].number)*100, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1435 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number), (yyvsp[(4) - (10)].number), (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number));
			}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1440 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number)*100);
			}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1445 "parse_y.y"
    {
				yyElement->MarkX = (yyvsp[(3) - (5)].number);
				yyElement->MarkY = (yyvsp[(4) - (5)].number);
			}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1450 "parse_y.y"
    {
				yyElement->MarkX = (yyvsp[(3) - (5)].number)*100;
				yyElement->MarkY = (yyvsp[(4) - (5)].number)*100;
			}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1454 "parse_y.y"
    { attr_list = & yyElement->Attributes; }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1469 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number) + yyElement->MarkX,
					(yyvsp[(4) - (8)].number) + yyElement->MarkY, (yyvsp[(5) - (8)].number) + yyElement->MarkX,
					(yyvsp[(6) - (8)].number) + yyElement->MarkY, (yyvsp[(7) - (8)].number));
			}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1475 "parse_y.y"
    {
				CreateNewLineInElement(yyElement, (yyvsp[(3) - (8)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (8)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (8)].number)*100 + yyElement->MarkX,
					(yyvsp[(6) - (8)].number)*100 + yyElement->MarkY, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1482 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number) + yyElement->MarkX,
					(yyvsp[(4) - (10)].number) + yyElement->MarkY, (yyvsp[(5) - (10)].number), (yyvsp[(6) - (10)].number), (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number));
			}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1487 "parse_y.y"
    {
				CreateNewArcInElement(yyElement, (yyvsp[(3) - (10)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (10)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (10)].number)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].number), (yyvsp[(8) - (10)].number), (yyvsp[(9) - (10)].number)*100);
			}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1491 "parse_y.y"
    { attr_list = & yyElement->Attributes; }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1533 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (12)].number) + yyElement->MarkX,
					(yyvsp[(4) - (12)].number) + yyElement->MarkY, (yyvsp[(5) - (12)].number), (yyvsp[(6) - (12)].number), (yyvsp[(7) - (12)].number), (yyvsp[(8) - (12)].number), (yyvsp[(9) - (12)].string),
					(yyvsp[(10) - (12)].string), (yyvsp[(11) - (12)].flagtype));
				SaveFree((yyvsp[(9) - (12)].string));
				SaveFree((yyvsp[(10) - (12)].string));
			}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1545 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (12)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (12)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (12)].number)*100, (yyvsp[(6) - (12)].number)*100, (yyvsp[(7) - (12)].number)*100, (yyvsp[(8) - (12)].number)*100, (yyvsp[(9) - (12)].string),
					(yyvsp[(10) - (12)].string), OldFlags((yyvsp[(11) - (12)].number)));
				SaveFree((yyvsp[(9) - (12)].string));
				SaveFree((yyvsp[(10) - (12)].string));
			}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1557 "parse_y.y"
    {
				CreateNewPin(yyElement, (yyvsp[(3) - (10)].number)*100, (yyvsp[(4) - (10)].number)*100, (yyvsp[(5) - (10)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (10)].number) + 2*MASKFRAME)*100, (yyvsp[(6) - (10)].number)*100, (yyvsp[(7) - (10)].string), (yyvsp[(8) - (10)].string), OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(7) - (10)].string));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1568 "parse_y.y"
    {
				char	p_number[8];

				sprintf(p_number, "%d", pin_num++);
				CreateNewPin(yyElement, (yyvsp[(3) - (9)].number)*100, (yyvsp[(4) - (9)].number)*100, (yyvsp[(5) - (9)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(5) - (9)].number) + 2*MASKFRAME)*100, (yyvsp[(6) - (9)].number)*100, (yyvsp[(7) - (9)].string), p_number, OldFlags((yyvsp[(8) - (9)].number)));

				SaveFree((yyvsp[(7) - (9)].string));
			}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1584 "parse_y.y"
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

  case 163:

/* Line 1455 of yacc.c  */
#line 1638 "parse_y.y"
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

  case 164:

/* Line 1455 of yacc.c  */
#line 1652 "parse_y.y"
    {
				CreateNewPad(yyElement,(yyvsp[(3) - (13)].number)*100 + yyElement->MarkX,
					(yyvsp[(4) - (13)].number)*100 + yyElement->MarkY, (yyvsp[(5) - (13)].number)*100 + yyElement->MarkX,
					(yyvsp[(6) - (13)].number)*100 + yyElement->MarkY, (yyvsp[(7) - (13)].number)*100, (yyvsp[(8) - (13)].number)*100, (yyvsp[(9) - (13)].number)*100,
					(yyvsp[(10) - (13)].string), (yyvsp[(11) - (13)].string), OldFlags((yyvsp[(12) - (13)].number)));
				SaveFree((yyvsp[(10) - (13)].string));
				SaveFree((yyvsp[(11) - (13)].string));
			}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1665 "parse_y.y"
    {
				CreateNewPad(yyElement,(yyvsp[(3) - (11)].number)*100,(yyvsp[(4) - (11)].number)*100,(yyvsp[(5) - (11)].number)*100,(yyvsp[(6) - (11)].number)*100,(yyvsp[(7) - (11)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(7) - (11)].number) + 2*MASKFRAME)*100, (yyvsp[(8) - (11)].string),(yyvsp[(9) - (11)].string), OldFlags((yyvsp[(10) - (11)].number)));
				SaveFree((yyvsp[(8) - (11)].string));
				SaveFree((yyvsp[(9) - (11)].string));
			}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1676 "parse_y.y"
    {
				char		p_number[8];

				sprintf(p_number, "%d", pin_num++);
				CreateNewPad(yyElement,(yyvsp[(3) - (10)].number)*100,(yyvsp[(4) - (10)].number)*100,(yyvsp[(5) - (10)].number)*100,(yyvsp[(6) - (10)].number)*100,(yyvsp[(7) - (10)].number)*100, 200*GROUNDPLANEFRAME,
					((yyvsp[(7) - (10)].number) + 2*MASKFRAME)*100, (yyvsp[(8) - (10)].string),p_number, OldFlags((yyvsp[(9) - (10)].number)));
				SaveFree((yyvsp[(8) - (10)].string));
			}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1686 "parse_y.y"
    { (yyval.flagtype) = OldFlags((yyvsp[(1) - (1)].number)); }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1687 "parse_y.y"
    { (yyval.flagtype) = string_to_flags ((yyvsp[(1) - (1)].string), yyerror); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1716 "parse_y.y"
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
				Symbol->Valid = true;
				Symbol->Delta = (yyvsp[(4) - (6)].number);
			}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1733 "parse_y.y"
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
				Symbol->Valid = true;
				Symbol->Delta = (yyvsp[(4) - (6)].number)*100;
			}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1786 "parse_y.y"
    {
				CreateNewLineInSymbol(Symbol, (yyvsp[(3) - (8)].number)*100, (yyvsp[(4) - (8)].number)*100, (yyvsp[(5) - (8)].number)*100, (yyvsp[(6) - (8)].number)*100, (yyvsp[(7) - (8)].number)*100);
			}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1793 "parse_y.y"
    {
				CreateNewLineInSymbol(Symbol, (yyvsp[(3) - (8)].number), (yyvsp[(4) - (8)].number), (yyvsp[(5) - (8)].number), (yyvsp[(6) - (8)].number), (yyvsp[(7) - (8)].number));
			}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1847 "parse_y.y"
    {
				Menu = CreateNewNet(&yyPCB->NetlistLib, (yyvsp[(3) - (6)].string), (yyvsp[(4) - (6)].string));
				SaveFree((yyvsp[(3) - (6)].string));
				SaveFree((yyvsp[(4) - (6)].string));
			}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1882 "parse_y.y"
    {
				CreateNewConnection(Menu, (yyvsp[(3) - (4)].string));
				SaveFree((yyvsp[(3) - (4)].string));
			}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1915 "parse_y.y"
    {
				CreateNewAttribute (attr_list, (yyvsp[(3) - (5)].string), (yyvsp[(4) - (5)].string) ? (yyvsp[(4) - (5)].string) : "");
				SaveFree ((yyvsp[(3) - (5)].string));
				SaveFree ((yyvsp[(4) - (5)].string));
			}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1922 "parse_y.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1923 "parse_y.y"
    { (yyval.string) = 0; }
    break;



/* Line 1455 of yacc.c  */
#line 3202 "parse_y.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 1926 "parse_y.y"


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
	     "using a version built from git source, the source date\n"
	     "must be >= %d.  This copy of pcb can only read files\n"
	     "up to file version %d.\n", ver, ver, PCB_FILE_VERSION);
    return 1;
  }
  
  return 0;
}



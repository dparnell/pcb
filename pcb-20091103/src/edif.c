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

/* Substitute the variable and function names.  */
#define yyparse edifparse
#define yylex   ediflex
#define yyerror ediferror
#define yylval  ediflval
#define yychar  edifchar
#define yydebug edifdebug
#define yynerrs edifnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EDIF_TOK_IDENT = 258,
     EDIF_TOK_INT = 259,
     EDIF_TOK_KEYWORD = 260,
     EDIF_TOK_STR = 261,
     EDIF_TOK_ANGLE = 262,
     EDIF_TOK_BEHAVIOR = 263,
     EDIF_TOK_CALCULATED = 264,
     EDIF_TOK_CAPACITANCE = 265,
     EDIF_TOK_CENTERCENTER = 266,
     EDIF_TOK_CENTERLEFT = 267,
     EDIF_TOK_CENTERRIGHT = 268,
     EDIF_TOK_CHARGE = 269,
     EDIF_TOK_CONDUCTANCE = 270,
     EDIF_TOK_CURRENT = 271,
     EDIF_TOK_DISTANCE = 272,
     EDIF_TOK_DOCUMENT = 273,
     EDIF_TOK_ENERGY = 274,
     EDIF_TOK_EXTEND = 275,
     EDIF_TOK_FLUX = 276,
     EDIF_TOK_FREQUENCY = 277,
     EDIF_TOK_GENERIC = 278,
     EDIF_TOK_GRAPHIC = 279,
     EDIF_TOK_INDUCTANCE = 280,
     EDIF_TOK_INOUT = 281,
     EDIF_TOK_INPUT = 282,
     EDIF_TOK_LOGICMODEL = 283,
     EDIF_TOK_LOWERCENTER = 284,
     EDIF_TOK_LOWERLEFT = 285,
     EDIF_TOK_LOWERRIGHT = 286,
     EDIF_TOK_MASKLAYOUT = 287,
     EDIF_TOK_MASS = 288,
     EDIF_TOK_MEASURED = 289,
     EDIF_TOK_MX = 290,
     EDIF_TOK_MXR90 = 291,
     EDIF_TOK_MY = 292,
     EDIF_TOK_MYR90 = 293,
     EDIF_TOK_NETLIST = 294,
     EDIF_TOK_OUTPUT = 295,
     EDIF_TOK_PCBLAYOUT = 296,
     EDIF_TOK_POWER = 297,
     EDIF_TOK_R0 = 298,
     EDIF_TOK_R180 = 299,
     EDIF_TOK_R270 = 300,
     EDIF_TOK_R90 = 301,
     EDIF_TOK_REQUIRED = 302,
     EDIF_TOK_RESISTANCE = 303,
     EDIF_TOK_RIPPER = 304,
     EDIF_TOK_ROUND = 305,
     EDIF_TOK_SCHEMATIC = 306,
     EDIF_TOK_STRANGER = 307,
     EDIF_TOK_SYMBOLIC = 308,
     EDIF_TOK_TEMPERATURE = 309,
     EDIF_TOK_TIE = 310,
     EDIF_TOK_TIME = 311,
     EDIF_TOK_TRUNCATE = 312,
     EDIF_TOK_UPPERCENTER = 313,
     EDIF_TOK_UPPERLEFT = 314,
     EDIF_TOK_UPPERRIGHT = 315,
     EDIF_TOK_VOLTAGE = 316,
     EDIF_TOK_ACLOAD = 317,
     EDIF_TOK_AFTER = 318,
     EDIF_TOK_ANNOTATE = 319,
     EDIF_TOK_APPLY = 320,
     EDIF_TOK_ARC = 321,
     EDIF_TOK_ARRAY = 322,
     EDIF_TOK_ARRAYMACRO = 323,
     EDIF_TOK_ARRAYRELATEDINFO = 324,
     EDIF_TOK_ARRAYSITE = 325,
     EDIF_TOK_ATLEAST = 326,
     EDIF_TOK_ATMOST = 327,
     EDIF_TOK_AUTHOR = 328,
     EDIF_TOK_BASEARRAY = 329,
     EDIF_TOK_BECOMES = 330,
     EDIF_TOK_BETWEEN = 331,
     EDIF_TOK_BOOLEAN = 332,
     EDIF_TOK_BOOLEANDISPLAY = 333,
     EDIF_TOK_BOOLEANMAP = 334,
     EDIF_TOK_BORDERPATTERN = 335,
     EDIF_TOK_BORDERWIDTH = 336,
     EDIF_TOK_BOUNDINGBOX = 337,
     EDIF_TOK_CELL = 338,
     EDIF_TOK_CELLREF = 339,
     EDIF_TOK_CELLTYPE = 340,
     EDIF_TOK_CHANGE = 341,
     EDIF_TOK_CIRCLE = 342,
     EDIF_TOK_COLOR = 343,
     EDIF_TOK_COMMENT = 344,
     EDIF_TOK_COMMENTGRAPHICS = 345,
     EDIF_TOK_COMPOUND = 346,
     EDIF_TOK_CONNECTLOCATION = 347,
     EDIF_TOK_CONTENTS = 348,
     EDIF_TOK_CORNERTYPE = 349,
     EDIF_TOK_CRITICALITY = 350,
     EDIF_TOK_CURRENTMAP = 351,
     EDIF_TOK_CURVE = 352,
     EDIF_TOK_CYCLE = 353,
     EDIF_TOK_DATAORIGIN = 354,
     EDIF_TOK_DCFANINLOAD = 355,
     EDIF_TOK_DCFANOUTLOAD = 356,
     EDIF_TOK_DCMAXFANIN = 357,
     EDIF_TOK_DCMAXFANOUT = 358,
     EDIF_TOK_DELAY = 359,
     EDIF_TOK_DELTA = 360,
     EDIF_TOK_DERIVATION = 361,
     EDIF_TOK_DESIGN = 362,
     EDIF_TOK_DESIGNATOR = 363,
     EDIF_TOK_DIFFERENCE = 364,
     EDIF_TOK_DIRECTION = 365,
     EDIF_TOK_DISPLAY = 366,
     EDIF_TOK_DOMINATES = 367,
     EDIF_TOK_DOT = 368,
     EDIF_TOK_DURATION = 369,
     EDIF_TOK_E = 370,
     EDIF_TOK_EDIF = 371,
     EDIF_TOK_EDIFLEVEL = 372,
     EDIF_TOK_EDIFVERSION = 373,
     EDIF_TOK_ENCLOSUREDISTANCE = 374,
     EDIF_TOK_ENDTYPE = 375,
     EDIF_TOK_ENTRY = 376,
     EDIF_TOK_EVENT = 377,
     EDIF_TOK_EXACTLY = 378,
     EDIF_TOK_EXTERNAL = 379,
     EDIF_TOK_FABRICATE = 380,
     EDIF_TOK_FALSE = 381,
     EDIF_TOK_FIGURE = 382,
     EDIF_TOK_FIGUREAREA = 383,
     EDIF_TOK_FIGUREGROUP = 384,
     EDIF_TOK_FIGUREGROUPOBJECT = 385,
     EDIF_TOK_FIGUREGROUPOVERRIDE = 386,
     EDIF_TOK_FIGUREGROUPREF = 387,
     EDIF_TOK_FIGUREPERIMETER = 388,
     EDIF_TOK_FIGUREWIDTH = 389,
     EDIF_TOK_FILLPATTERN = 390,
     EDIF_TOK_FOLLOW = 391,
     EDIF_TOK_FORBIDDENEVENT = 392,
     EDIF_TOK_GLOBALPORTREF = 393,
     EDIF_TOK_GREATERTHAN = 394,
     EDIF_TOK_GRIDMAP = 395,
     EDIF_TOK_IGNORE = 396,
     EDIF_TOK_INCLUDEFIGUREGROUP = 397,
     EDIF_TOK_INITIAL = 398,
     EDIF_TOK_INSTANCE = 399,
     EDIF_TOK_INSTANCEBACKANNOTATE = 400,
     EDIF_TOK_INSTANCEGROUP = 401,
     EDIF_TOK_INSTANCEMAP = 402,
     EDIF_TOK_INSTANCEREF = 403,
     EDIF_TOK_INTEGER = 404,
     EDIF_TOK_INTEGERDISPLAY = 405,
     EDIF_TOK_INTERFACE = 406,
     EDIF_TOK_INTERFIGUREGROUPSPACING = 407,
     EDIF_TOK_INTERSECTION = 408,
     EDIF_TOK_INTRAFIGUREGROUPSPACING = 409,
     EDIF_TOK_INVERSE = 410,
     EDIF_TOK_ISOLATED = 411,
     EDIF_TOK_JOINED = 412,
     EDIF_TOK_JUSTIFY = 413,
     EDIF_TOK_KEYWORDDISPLAY = 414,
     EDIF_TOK_KEYWORDLEVEL = 415,
     EDIF_TOK_KEYWORDMAP = 416,
     EDIF_TOK_LESSTHAN = 417,
     EDIF_TOK_LIBRARY = 418,
     EDIF_TOK_LIBRARYREF = 419,
     EDIF_TOK_LISTOFNETS = 420,
     EDIF_TOK_LISTOFPORTS = 421,
     EDIF_TOK_LOADDELAY = 422,
     EDIF_TOK_LOGICASSIGN = 423,
     EDIF_TOK_LOGICINPUT = 424,
     EDIF_TOK_LOGICLIST = 425,
     EDIF_TOK_LOGICMAPINPUT = 426,
     EDIF_TOK_LOGICMAPOUTPUT = 427,
     EDIF_TOK_LOGICONEOF = 428,
     EDIF_TOK_LOGICOUTPUT = 429,
     EDIF_TOK_LOGICPORT = 430,
     EDIF_TOK_LOGICREF = 431,
     EDIF_TOK_LOGICVALUE = 432,
     EDIF_TOK_LOGICWAVEFORM = 433,
     EDIF_TOK_MAINTAIN = 434,
     EDIF_TOK_MATCH = 435,
     EDIF_TOK_MEMBER = 436,
     EDIF_TOK_MINOMAX = 437,
     EDIF_TOK_MINOMAXDISPLAY = 438,
     EDIF_TOK_MNM = 439,
     EDIF_TOK_MULTIPLEVALUESET = 440,
     EDIF_TOK_MUSTJOIN = 441,
     EDIF_TOK_NAME = 442,
     EDIF_TOK_NET = 443,
     EDIF_TOK_NETBACKANNOTATE = 444,
     EDIF_TOK_NETBUNDLE = 445,
     EDIF_TOK_NETDELAY = 446,
     EDIF_TOK_NETGROUP = 447,
     EDIF_TOK_NETMAP = 448,
     EDIF_TOK_NETREF = 449,
     EDIF_TOK_NOCHANGE = 450,
     EDIF_TOK_NONPERMUTABLE = 451,
     EDIF_TOK_NOTALLOWED = 452,
     EDIF_TOK_NOTCHSPACING = 453,
     EDIF_TOK_NUMBER = 454,
     EDIF_TOK_NUMBERDEFINITION = 455,
     EDIF_TOK_NUMBERDISPLAY = 456,
     EDIF_TOK_OFFPAGECONNECTOR = 457,
     EDIF_TOK_OFFSETEVENT = 458,
     EDIF_TOK_OPENSHAPE = 459,
     EDIF_TOK_ORIENTATION = 460,
     EDIF_TOK_ORIGIN = 461,
     EDIF_TOK_OVERHANGDISTANCE = 462,
     EDIF_TOK_OVERLAPDISTANCE = 463,
     EDIF_TOK_OVERSIZE = 464,
     EDIF_TOK_OWNER = 465,
     EDIF_TOK_PAGE = 466,
     EDIF_TOK_PAGESIZE = 467,
     EDIF_TOK_PARAMETER = 468,
     EDIF_TOK_PARAMETERASSIGN = 469,
     EDIF_TOK_PARAMETERDISPLAY = 470,
     EDIF_TOK_PATH = 471,
     EDIF_TOK_PATHDELAY = 472,
     EDIF_TOK_PATHWIDTH = 473,
     EDIF_TOK_PERMUTABLE = 474,
     EDIF_TOK_PHYSICALDESIGNRULE = 475,
     EDIF_TOK_PLUG = 476,
     EDIF_TOK_POINT = 477,
     EDIF_TOK_POINTDISPLAY = 478,
     EDIF_TOK_POINTLIST = 479,
     EDIF_TOK_POLYGON = 480,
     EDIF_TOK_PORT = 481,
     EDIF_TOK_PORTBACKANNOTATE = 482,
     EDIF_TOK_PORTBUNDLE = 483,
     EDIF_TOK_PORTDELAY = 484,
     EDIF_TOK_PORTGROUP = 485,
     EDIF_TOK_PORTIMPLEMENTATION = 486,
     EDIF_TOK_PORTINSTANCE = 487,
     EDIF_TOK_PORTLIST = 488,
     EDIF_TOK_PORTLISTALIAS = 489,
     EDIF_TOK_PORTMAP = 490,
     EDIF_TOK_PORTREF = 491,
     EDIF_TOK_PROGRAM = 492,
     EDIF_TOK_PROPERTY = 493,
     EDIF_TOK_PROPERTYDISPLAY = 494,
     EDIF_TOK_PROTECTIONFRAME = 495,
     EDIF_TOK_PT = 496,
     EDIF_TOK_RANGEVECTOR = 497,
     EDIF_TOK_RECTANGLE = 498,
     EDIF_TOK_RECTANGLESIZE = 499,
     EDIF_TOK_RENAME = 500,
     EDIF_TOK_RESOLVES = 501,
     EDIF_TOK_SCALE = 502,
     EDIF_TOK_SCALEX = 503,
     EDIF_TOK_SCALEY = 504,
     EDIF_TOK_SECTION = 505,
     EDIF_TOK_SHAPE = 506,
     EDIF_TOK_SIMULATE = 507,
     EDIF_TOK_SIMULATIONINFO = 508,
     EDIF_TOK_SINGLEVALUESET = 509,
     EDIF_TOK_SITE = 510,
     EDIF_TOK_SOCKET = 511,
     EDIF_TOK_SOCKETSET = 512,
     EDIF_TOK_STATUS = 513,
     EDIF_TOK_STEADY = 514,
     EDIF_TOK_STRING = 515,
     EDIF_TOK_STRINGDISPLAY = 516,
     EDIF_TOK_STRONG = 517,
     EDIF_TOK_SYMBOL = 518,
     EDIF_TOK_SYMMETRY = 519,
     EDIF_TOK_TABLE = 520,
     EDIF_TOK_TABLEDEFAULT = 521,
     EDIF_TOK_TECHNOLOGY = 522,
     EDIF_TOK_TEXTHEIGHT = 523,
     EDIF_TOK_TIMEINTERVAL = 524,
     EDIF_TOK_TIMESTAMP = 525,
     EDIF_TOK_TIMING = 526,
     EDIF_TOK_TRANSFORM = 527,
     EDIF_TOK_TRANSITION = 528,
     EDIF_TOK_TRIGGER = 529,
     EDIF_TOK_TRUE = 530,
     EDIF_TOK_UNCONSTRAINED = 531,
     EDIF_TOK_UNDEFINED = 532,
     EDIF_TOK_UNION = 533,
     EDIF_TOK_UNIT = 534,
     EDIF_TOK_UNUSED = 535,
     EDIF_TOK_USERDATA = 536,
     EDIF_TOK_VERSION = 537,
     EDIF_TOK_VIEW = 538,
     EDIF_TOK_VIEWLIST = 539,
     EDIF_TOK_VIEWMAP = 540,
     EDIF_TOK_VIEWREF = 541,
     EDIF_TOK_VIEWTYPE = 542,
     EDIF_TOK_VISIBLE = 543,
     EDIF_TOK_VOLTAGEMAP = 544,
     EDIF_TOK_WAVEVALUE = 545,
     EDIF_TOK_WEAK = 546,
     EDIF_TOK_WEAKJOINED = 547,
     EDIF_TOK_WHEN = 548,
     EDIF_TOK_WRITTEN = 549
   };
#endif
/* Tokens.  */
#define EDIF_TOK_IDENT 258
#define EDIF_TOK_INT 259
#define EDIF_TOK_KEYWORD 260
#define EDIF_TOK_STR 261
#define EDIF_TOK_ANGLE 262
#define EDIF_TOK_BEHAVIOR 263
#define EDIF_TOK_CALCULATED 264
#define EDIF_TOK_CAPACITANCE 265
#define EDIF_TOK_CENTERCENTER 266
#define EDIF_TOK_CENTERLEFT 267
#define EDIF_TOK_CENTERRIGHT 268
#define EDIF_TOK_CHARGE 269
#define EDIF_TOK_CONDUCTANCE 270
#define EDIF_TOK_CURRENT 271
#define EDIF_TOK_DISTANCE 272
#define EDIF_TOK_DOCUMENT 273
#define EDIF_TOK_ENERGY 274
#define EDIF_TOK_EXTEND 275
#define EDIF_TOK_FLUX 276
#define EDIF_TOK_FREQUENCY 277
#define EDIF_TOK_GENERIC 278
#define EDIF_TOK_GRAPHIC 279
#define EDIF_TOK_INDUCTANCE 280
#define EDIF_TOK_INOUT 281
#define EDIF_TOK_INPUT 282
#define EDIF_TOK_LOGICMODEL 283
#define EDIF_TOK_LOWERCENTER 284
#define EDIF_TOK_LOWERLEFT 285
#define EDIF_TOK_LOWERRIGHT 286
#define EDIF_TOK_MASKLAYOUT 287
#define EDIF_TOK_MASS 288
#define EDIF_TOK_MEASURED 289
#define EDIF_TOK_MX 290
#define EDIF_TOK_MXR90 291
#define EDIF_TOK_MY 292
#define EDIF_TOK_MYR90 293
#define EDIF_TOK_NETLIST 294
#define EDIF_TOK_OUTPUT 295
#define EDIF_TOK_PCBLAYOUT 296
#define EDIF_TOK_POWER 297
#define EDIF_TOK_R0 298
#define EDIF_TOK_R180 299
#define EDIF_TOK_R270 300
#define EDIF_TOK_R90 301
#define EDIF_TOK_REQUIRED 302
#define EDIF_TOK_RESISTANCE 303
#define EDIF_TOK_RIPPER 304
#define EDIF_TOK_ROUND 305
#define EDIF_TOK_SCHEMATIC 306
#define EDIF_TOK_STRANGER 307
#define EDIF_TOK_SYMBOLIC 308
#define EDIF_TOK_TEMPERATURE 309
#define EDIF_TOK_TIE 310
#define EDIF_TOK_TIME 311
#define EDIF_TOK_TRUNCATE 312
#define EDIF_TOK_UPPERCENTER 313
#define EDIF_TOK_UPPERLEFT 314
#define EDIF_TOK_UPPERRIGHT 315
#define EDIF_TOK_VOLTAGE 316
#define EDIF_TOK_ACLOAD 317
#define EDIF_TOK_AFTER 318
#define EDIF_TOK_ANNOTATE 319
#define EDIF_TOK_APPLY 320
#define EDIF_TOK_ARC 321
#define EDIF_TOK_ARRAY 322
#define EDIF_TOK_ARRAYMACRO 323
#define EDIF_TOK_ARRAYRELATEDINFO 324
#define EDIF_TOK_ARRAYSITE 325
#define EDIF_TOK_ATLEAST 326
#define EDIF_TOK_ATMOST 327
#define EDIF_TOK_AUTHOR 328
#define EDIF_TOK_BASEARRAY 329
#define EDIF_TOK_BECOMES 330
#define EDIF_TOK_BETWEEN 331
#define EDIF_TOK_BOOLEAN 332
#define EDIF_TOK_BOOLEANDISPLAY 333
#define EDIF_TOK_BOOLEANMAP 334
#define EDIF_TOK_BORDERPATTERN 335
#define EDIF_TOK_BORDERWIDTH 336
#define EDIF_TOK_BOUNDINGBOX 337
#define EDIF_TOK_CELL 338
#define EDIF_TOK_CELLREF 339
#define EDIF_TOK_CELLTYPE 340
#define EDIF_TOK_CHANGE 341
#define EDIF_TOK_CIRCLE 342
#define EDIF_TOK_COLOR 343
#define EDIF_TOK_COMMENT 344
#define EDIF_TOK_COMMENTGRAPHICS 345
#define EDIF_TOK_COMPOUND 346
#define EDIF_TOK_CONNECTLOCATION 347
#define EDIF_TOK_CONTENTS 348
#define EDIF_TOK_CORNERTYPE 349
#define EDIF_TOK_CRITICALITY 350
#define EDIF_TOK_CURRENTMAP 351
#define EDIF_TOK_CURVE 352
#define EDIF_TOK_CYCLE 353
#define EDIF_TOK_DATAORIGIN 354
#define EDIF_TOK_DCFANINLOAD 355
#define EDIF_TOK_DCFANOUTLOAD 356
#define EDIF_TOK_DCMAXFANIN 357
#define EDIF_TOK_DCMAXFANOUT 358
#define EDIF_TOK_DELAY 359
#define EDIF_TOK_DELTA 360
#define EDIF_TOK_DERIVATION 361
#define EDIF_TOK_DESIGN 362
#define EDIF_TOK_DESIGNATOR 363
#define EDIF_TOK_DIFFERENCE 364
#define EDIF_TOK_DIRECTION 365
#define EDIF_TOK_DISPLAY 366
#define EDIF_TOK_DOMINATES 367
#define EDIF_TOK_DOT 368
#define EDIF_TOK_DURATION 369
#define EDIF_TOK_E 370
#define EDIF_TOK_EDIF 371
#define EDIF_TOK_EDIFLEVEL 372
#define EDIF_TOK_EDIFVERSION 373
#define EDIF_TOK_ENCLOSUREDISTANCE 374
#define EDIF_TOK_ENDTYPE 375
#define EDIF_TOK_ENTRY 376
#define EDIF_TOK_EVENT 377
#define EDIF_TOK_EXACTLY 378
#define EDIF_TOK_EXTERNAL 379
#define EDIF_TOK_FABRICATE 380
#define EDIF_TOK_FALSE 381
#define EDIF_TOK_FIGURE 382
#define EDIF_TOK_FIGUREAREA 383
#define EDIF_TOK_FIGUREGROUP 384
#define EDIF_TOK_FIGUREGROUPOBJECT 385
#define EDIF_TOK_FIGUREGROUPOVERRIDE 386
#define EDIF_TOK_FIGUREGROUPREF 387
#define EDIF_TOK_FIGUREPERIMETER 388
#define EDIF_TOK_FIGUREWIDTH 389
#define EDIF_TOK_FILLPATTERN 390
#define EDIF_TOK_FOLLOW 391
#define EDIF_TOK_FORBIDDENEVENT 392
#define EDIF_TOK_GLOBALPORTREF 393
#define EDIF_TOK_GREATERTHAN 394
#define EDIF_TOK_GRIDMAP 395
#define EDIF_TOK_IGNORE 396
#define EDIF_TOK_INCLUDEFIGUREGROUP 397
#define EDIF_TOK_INITIAL 398
#define EDIF_TOK_INSTANCE 399
#define EDIF_TOK_INSTANCEBACKANNOTATE 400
#define EDIF_TOK_INSTANCEGROUP 401
#define EDIF_TOK_INSTANCEMAP 402
#define EDIF_TOK_INSTANCEREF 403
#define EDIF_TOK_INTEGER 404
#define EDIF_TOK_INTEGERDISPLAY 405
#define EDIF_TOK_INTERFACE 406
#define EDIF_TOK_INTERFIGUREGROUPSPACING 407
#define EDIF_TOK_INTERSECTION 408
#define EDIF_TOK_INTRAFIGUREGROUPSPACING 409
#define EDIF_TOK_INVERSE 410
#define EDIF_TOK_ISOLATED 411
#define EDIF_TOK_JOINED 412
#define EDIF_TOK_JUSTIFY 413
#define EDIF_TOK_KEYWORDDISPLAY 414
#define EDIF_TOK_KEYWORDLEVEL 415
#define EDIF_TOK_KEYWORDMAP 416
#define EDIF_TOK_LESSTHAN 417
#define EDIF_TOK_LIBRARY 418
#define EDIF_TOK_LIBRARYREF 419
#define EDIF_TOK_LISTOFNETS 420
#define EDIF_TOK_LISTOFPORTS 421
#define EDIF_TOK_LOADDELAY 422
#define EDIF_TOK_LOGICASSIGN 423
#define EDIF_TOK_LOGICINPUT 424
#define EDIF_TOK_LOGICLIST 425
#define EDIF_TOK_LOGICMAPINPUT 426
#define EDIF_TOK_LOGICMAPOUTPUT 427
#define EDIF_TOK_LOGICONEOF 428
#define EDIF_TOK_LOGICOUTPUT 429
#define EDIF_TOK_LOGICPORT 430
#define EDIF_TOK_LOGICREF 431
#define EDIF_TOK_LOGICVALUE 432
#define EDIF_TOK_LOGICWAVEFORM 433
#define EDIF_TOK_MAINTAIN 434
#define EDIF_TOK_MATCH 435
#define EDIF_TOK_MEMBER 436
#define EDIF_TOK_MINOMAX 437
#define EDIF_TOK_MINOMAXDISPLAY 438
#define EDIF_TOK_MNM 439
#define EDIF_TOK_MULTIPLEVALUESET 440
#define EDIF_TOK_MUSTJOIN 441
#define EDIF_TOK_NAME 442
#define EDIF_TOK_NET 443
#define EDIF_TOK_NETBACKANNOTATE 444
#define EDIF_TOK_NETBUNDLE 445
#define EDIF_TOK_NETDELAY 446
#define EDIF_TOK_NETGROUP 447
#define EDIF_TOK_NETMAP 448
#define EDIF_TOK_NETREF 449
#define EDIF_TOK_NOCHANGE 450
#define EDIF_TOK_NONPERMUTABLE 451
#define EDIF_TOK_NOTALLOWED 452
#define EDIF_TOK_NOTCHSPACING 453
#define EDIF_TOK_NUMBER 454
#define EDIF_TOK_NUMBERDEFINITION 455
#define EDIF_TOK_NUMBERDISPLAY 456
#define EDIF_TOK_OFFPAGECONNECTOR 457
#define EDIF_TOK_OFFSETEVENT 458
#define EDIF_TOK_OPENSHAPE 459
#define EDIF_TOK_ORIENTATION 460
#define EDIF_TOK_ORIGIN 461
#define EDIF_TOK_OVERHANGDISTANCE 462
#define EDIF_TOK_OVERLAPDISTANCE 463
#define EDIF_TOK_OVERSIZE 464
#define EDIF_TOK_OWNER 465
#define EDIF_TOK_PAGE 466
#define EDIF_TOK_PAGESIZE 467
#define EDIF_TOK_PARAMETER 468
#define EDIF_TOK_PARAMETERASSIGN 469
#define EDIF_TOK_PARAMETERDISPLAY 470
#define EDIF_TOK_PATH 471
#define EDIF_TOK_PATHDELAY 472
#define EDIF_TOK_PATHWIDTH 473
#define EDIF_TOK_PERMUTABLE 474
#define EDIF_TOK_PHYSICALDESIGNRULE 475
#define EDIF_TOK_PLUG 476
#define EDIF_TOK_POINT 477
#define EDIF_TOK_POINTDISPLAY 478
#define EDIF_TOK_POINTLIST 479
#define EDIF_TOK_POLYGON 480
#define EDIF_TOK_PORT 481
#define EDIF_TOK_PORTBACKANNOTATE 482
#define EDIF_TOK_PORTBUNDLE 483
#define EDIF_TOK_PORTDELAY 484
#define EDIF_TOK_PORTGROUP 485
#define EDIF_TOK_PORTIMPLEMENTATION 486
#define EDIF_TOK_PORTINSTANCE 487
#define EDIF_TOK_PORTLIST 488
#define EDIF_TOK_PORTLISTALIAS 489
#define EDIF_TOK_PORTMAP 490
#define EDIF_TOK_PORTREF 491
#define EDIF_TOK_PROGRAM 492
#define EDIF_TOK_PROPERTY 493
#define EDIF_TOK_PROPERTYDISPLAY 494
#define EDIF_TOK_PROTECTIONFRAME 495
#define EDIF_TOK_PT 496
#define EDIF_TOK_RANGEVECTOR 497
#define EDIF_TOK_RECTANGLE 498
#define EDIF_TOK_RECTANGLESIZE 499
#define EDIF_TOK_RENAME 500
#define EDIF_TOK_RESOLVES 501
#define EDIF_TOK_SCALE 502
#define EDIF_TOK_SCALEX 503
#define EDIF_TOK_SCALEY 504
#define EDIF_TOK_SECTION 505
#define EDIF_TOK_SHAPE 506
#define EDIF_TOK_SIMULATE 507
#define EDIF_TOK_SIMULATIONINFO 508
#define EDIF_TOK_SINGLEVALUESET 509
#define EDIF_TOK_SITE 510
#define EDIF_TOK_SOCKET 511
#define EDIF_TOK_SOCKETSET 512
#define EDIF_TOK_STATUS 513
#define EDIF_TOK_STEADY 514
#define EDIF_TOK_STRING 515
#define EDIF_TOK_STRINGDISPLAY 516
#define EDIF_TOK_STRONG 517
#define EDIF_TOK_SYMBOL 518
#define EDIF_TOK_SYMMETRY 519
#define EDIF_TOK_TABLE 520
#define EDIF_TOK_TABLEDEFAULT 521
#define EDIF_TOK_TECHNOLOGY 522
#define EDIF_TOK_TEXTHEIGHT 523
#define EDIF_TOK_TIMEINTERVAL 524
#define EDIF_TOK_TIMESTAMP 525
#define EDIF_TOK_TIMING 526
#define EDIF_TOK_TRANSFORM 527
#define EDIF_TOK_TRANSITION 528
#define EDIF_TOK_TRIGGER 529
#define EDIF_TOK_TRUE 530
#define EDIF_TOK_UNCONSTRAINED 531
#define EDIF_TOK_UNDEFINED 532
#define EDIF_TOK_UNION 533
#define EDIF_TOK_UNIT 534
#define EDIF_TOK_UNUSED 535
#define EDIF_TOK_USERDATA 536
#define EDIF_TOK_VERSION 537
#define EDIF_TOK_VIEW 538
#define EDIF_TOK_VIEWLIST 539
#define EDIF_TOK_VIEWMAP 540
#define EDIF_TOK_VIEWREF 541
#define EDIF_TOK_VIEWTYPE 542
#define EDIF_TOK_VISIBLE 543
#define EDIF_TOK_VOLTAGEMAP 544
#define EDIF_TOK_WAVEVALUE 545
#define EDIF_TOK_WEAK 546
#define EDIF_TOK_WEAKJOINED 547
#define EDIF_TOK_WHEN 548
#define EDIF_TOK_WRITTEN 549




/* Copy the first part of user declarations.  */
#line 1 "edif.y"

/* 
 * PCB Edif parser based heavily on:
 *
 *	Header: edif.y,v 1.18 87/12/07 19:59:49 roger Locked 
 */
/************************************************************************
 *									*
 *				edif.y					*
 *									*
 *			EDIF 2.0.0 parser, Level 0			*
 *									*
 *	You are free to copy, distribute, use it, abuse it, make it	*
 *	write bad tracks all over the disk ... or anything else.	*
 *									*
 *	Your friendly neighborhood Rogue Monster - roger@mips.com	*
 *									*
 ************************************************************************/
#include <stdio.h>

/* for malloc, free, atoi */
#include <stdlib.h>

/* for strcpy */
#include <string.h>

#include <ctype.h>

#include "global.h"
#include "data.h"
/* from mymem.h, not include because of the malloc junk */
LibraryMenuTypePtr GetLibraryMenuMemory (LibraryTypePtr);
LibraryEntryTypePtr GetLibraryEntryMemory (LibraryMenuTypePtr);

/*
 *	Local definitions.
 */
#define	IDENT_LENGTH		255
#define	Malloc(s)		malloc(s)
#define	Free(p)			free(p)
#define	ABS(v)			((v) < 0 ? -(v) : (v))
#define	Getc(s)			getc(s)
#define	Ungetc(c)		ungetc(c,Input)

 typedef struct _str_pair
 {
     char* str1;
     char* str2;
     struct _str_pair* next;
 } str_pair;

 typedef struct _pair_list
 {
     char* name;
     str_pair* list;
 } pair_list;

 str_pair* new_str_pair(char* s1, char* s2)
 {
     str_pair* ps = malloc(sizeof(str_pair));
     ps->str1 = s1;
     ps->str2 = s2;
     ps->next = NULL;
     return ps;
 }
 
 pair_list* new_pair_list(str_pair* ps)
 {
     pair_list* pl = malloc(sizeof(pair_list));
     pl->list = ps;
     pl->name = NULL;
     return pl;
 }

 void str_pair_free(str_pair* ps)
 {
     str_pair* node;
     while ( ps )
     {
	 free(ps->str1);
	 free(ps->str2);
	 node = ps;
	 ps = ps->next;
	 free(node);
     }
 }
  
 void pair_list_free(pair_list* pl)
 {
     str_pair_free(pl->list);
     free(pl->name);
     free(pl);
 }

 void define_pcb_net(str_pair* name, pair_list* nodes)
 {
     int tl;
     str_pair* done_node;
     str_pair* node;
     char* buf;
     char* p;
     LibraryEntryTypePtr entry;
     LibraryMenuTypePtr menu = GetLibraryMenuMemory (&PCB->NetlistLib);

     if ( !name->str1 )
     {
	 /* no net name given, stop now */
	 /* if renamed str2 also exists and must be freed */
	 if ( name->str2 )  free(name->str2);
	 free(name);
	 pair_list_free(nodes);
	 return;
     }
     menu->Name = strdup (name->str1);
     free(name->str1);
     /* if renamed str2 also exists and must be freed */
     if ( name->str2 )  free(name->str2);
     free(name);
     buf = malloc(256);
     if ( !buf )
     {
	 /* no memory */
	 pair_list_free(nodes);
	 return;
     }

     node = nodes->list;
     free(nodes->name);
     free(nodes);
     while ( node )
     {
	 /* check for node with no instance */
	 if ( !node->str1 )
	 {
	     /* toss it and move on */
	     free(node->str2);
	     done_node = node;
	     node = node->next;
	     free(done_node);
	     continue;
	 }
	 tl = strlen(node->str1) + strlen(node->str2);
	 if ( tl + 3 > 256 )
	 {
	     free(buf);
	     buf = malloc(tl+3);
	     if ( !buf )
	     {
		 /* no memory */
		 str_pair_free(node);
		 return;
	     }
	 }
	 strcpy(buf,node->str1);
	 /* make all upper case, because of PCB funky behaviour */
	 p=buf;
	 while ( *p ) 
	 {
	     *p = toupper( (int) *p);
	     p++;
	 }
	 /* add dash separating designator from node */
	 *(buf+strlen(node->str1)) = '-';
	 /* check for the edif number prefix */
	 if ( node->str2[0] == '&' )
	 {
	     /* skip number prefix */
	     strcpy(buf+strlen(node->str1)+1,node->str2 +1);
	 }
	 else
	 {
	     strcpy(buf+strlen(node->str1)+1,node->str2);
	 }
	 /* free the strings */
	 free(node->str1);
	 free(node->str2);
	 entry = GetLibraryEntryMemory (menu);
	 entry->ListEntry = strdup(buf);
	 done_node = node;
	 node = node->next;
	 free(done_node);
     }
 }
 
 
/* forward function declarations */
 static int yylex(void);
 static void yyerror(const char *);
 static void PopC(void);


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
#line 194 "edif.y"
{
    char* s;
    pair_list* pl;
    str_pair* ps;
}
/* Line 187 of yacc.c.  */
#line 889 "edif.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 902 "edif.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  296
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  472
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1626

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   549

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   295,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    13,    14,    17,    20,    23,    26,
      29,    32,    34,    38,    44,    48,    50,    52,    56,    58,
      61,    64,    67,    70,    73,    77,    79,    81,    85,    87,
      90,    93,    96,    99,   105,   111,   112,   114,   118,   122,
     124,   126,   128,   131,   134,   138,   142,   146,   150,   153,
     157,   159,   161,   163,   168,   170,   172,   174,   176,   180,
     181,   184,   187,   190,   194,   196,   199,   203,   205,   207,
     213,   217,   221,   226,   228,   231,   234,   237,   240,   243,
     246,   248,   253,   254,   256,   258,   262,   264,   266,   268,
     273,   275,   277,   279,   280,   282,   284,   290,   291,   294,
     300,   304,   305,   308,   312,   313,   316,   319,   322,   325,
     328,   331,   334,   338,   342,   343,   346,   349,   352,   355,
     358,   361,   364,   367,   370,   373,   376,   379,   382,   385,
     388,   391,   394,   398,   399,   401,   405,   407,   409,   411,
     415,   417,   419,   423,   427,   428,   431,   434,   439,   440,
     442,   447,   448,   450,   454,   456,   458,   462,   464,   466,
     470,   472,   474,   478,   480,   482,   486,   488,   490,   494,
     495,   498,   502,   504,   506,   508,   513,   515,   518,   521,
     524,   527,   531,   533,   535,   537,   541,   542,   545,   548,
     551,   554,   557,   560,   563,   566,   569,   572,   575,   578,
     581,   584,   588,   590,   592,   595,   598,   602,   604,   606,
     608,   615,   617,   619,   620,   622,   623,   625,   626,   628,
     632,   633,   636,   640,   642,   645,   649,   656,   658,   660,
     663,   666,   670,   672,   674,   676,   682,   684,   686,   688,
     690,   692,   694,   696,   697,   699,   701,   705,   707,   709,
     711,   713,   715,   718,   721,   725,   731,   733,   736,   739,
     742,   745,   750,   753,   757,   759,   762,   765,   768,   771,
     774,   777,   780,   783,   786,   789,   792,   795,   798,   800,
     802,   806,   808,   810,   812,   816,   818,   821,   824,   827,
     830,   833,   836,   839,   842,   845,   848,   851,   854,   859,
     860,   862,   866,   868,   870,   873,   876,   879,   882,   885,
     888,   891,   894,   897,   903,   905,   907,   910,   913,   915,
     917,   919,   921,   923,   929,   931,   933,   936,   939,   945,
     947,   949,   952,   955,   961,   966,   968,   970,   972,   974,
     977,   980,   984,   986,   989,   993,   994,   997,  1000,  1003,
    1006,  1010,  1014,  1019,  1022,  1026,  1028,  1030,  1033,  1038,
    1040,  1042,  1045,  1048,  1051,  1054,  1057,  1060,  1063,  1066,
    1071,  1072,  1074,  1076,  1080,  1082,  1085,  1088,  1091,  1094,
    1098,  1099,  1102,  1106,  1107,  1110,  1113,  1116,  1119,  1121,
    1123,  1125,  1127,  1131,  1133,  1136,  1140,  1141,  1144,  1147,
    1150,  1154,  1155,  1158,  1161,  1164,  1167,  1170,  1173,  1176,
    1179,  1182,  1185,  1188,  1191,  1194,  1197,  1200,  1203,  1210,
    1212,  1214,  1217,  1220,  1224,  1226,  1228,  1231,  1234,  1240,
    1242,  1244,  1247,  1250,  1254,  1256,  1258,  1261,  1265,  1266,
    1269,  1272,  1275,  1279,  1281,  1283,  1285,  1287,  1289,  1291,
    1293,  1295,  1297,  1301,  1303,  1306,  1310,  1314,  1316,  1319,
    1321,  1323,  1327,  1329,  1331,  1337,  1339,  1342,  1345,  1348,
    1351,  1355,  1359,  1360,  1363,  1367,  1368,  1371,  1374,  1379,
    1381,  1383,  1389,  1391,  1393,  1395,  1397,  1399,  1400,  1402,
    1404,  1408,  1410,  1412,  1414,  1417,  1421,  1422,  1425,  1428,
    1431,  1435,  1436,  1439,  1443,  1444,  1447,  1449,  1451,  1455,
    1456,  1459,  1462,  1466,  1468,  1470,  1472,  1475,  1479,  1481,
    1484,  1487,  1490,  1495,  1496,  1498,  1502,  1504,  1507,  1510,
    1513,  1516,  1519,  1522,  1525,  1528,  1531,  1534,  1537,  1540,
    1543,  1546,  1550,  1551,  1554,  1557,  1560,  1563,  1568,  1570,
    1572,  1573,  1575,  1577,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1599,  1601,  1604,  1608,  1609,  1612,  1615,  1618,  1622,
    1624,  1627,  1629,  1631,  1637,  1639,  1641,  1643,  1647,  1648,
    1651,  1655,  1656,  1659,  1662,  1665,  1668,  1672,  1674,  1677,
    1679,  1681,  1683,  1685,  1687,  1692,  1694,  1697,  1700,  1703,
    1706,  1709,  1712,  1715,  1718,  1721,  1725,  1727,  1730,  1733,
    1736,  1739,  1744,  1746,  1749,  1752,  1755,  1758,  1761,  1766,
    1768,  1771,  1774,  1778,  1779,  1782,  1785,  1789,  1790,  1793,
    1796,  1799,  1802,  1804,  1806,  1808,  1810,  1815,  1816,  1818,
    1820,  1822,  1825,  1829,  1830,  1833,  1836,  1841,  1843,  1846,
    1849,  1855,  1857,  1859,  1862,  1865,  1869,  1870,  1873,  1876,
    1879,  1883,  1885,  1888,  1892,  1893,  1896,  1899,  1902,  1906,
    1908,  1911,  1914,  1917,  1920,  1925,  1929,  1931,  1934,  1938,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,  1958,  1965,
    1967,  1969,  1972,  1975,  1982,  1984,  1986,  1989,  1992,  1998,
    2000,  2002,  2006,  2010,  2012,  2015,  2018,  2021,  2024,  2027,
    2030,  2033,  2036,  2039,  2043,  2047,  2049,  2052,  2058,  2059,
    2061,  2066,  2070,  2072,  2075,  2079,  2081,  2084,  2088,  2092,
    2093,  2096,  2099,  2102,  2106,  2107,  2110,  2114,  2115,  2118,
    2121,  2124,  2128,  2130,  2133,  2137,  2138,  2141,  2146,  2150,
    2152,  2155,  2159,  2161,  2164,  2167,  2170,  2173,  2176,  2179,
    2182,  2185,  2188,  2191,  2194,  2197,  2201,  2203,  2206,  2209,
    2212,  2215,  2218,  2221,  2224,  2227,  2230,  2235,  2237,  2240,
    2243,  2246,  2251,  2253,  2255,  2258,  2261,  2265,  2266,  2269,
    2272,  2276,  2278,  2280,  2283,  2286,  2289,  2292,  2295,  2298,
    2301,  2304,  2307,  2311,  2313,  2315,  2318,  2321,  2324,  2327,
    2330,  2333,  2336,  2339,  2342,  2345,  2348,  2352,  2353,  2356,
    2359,  2364,  2368,  2369,  2372,  2375,  2378,  2381,  2383,  2385,
    2387,  2389,  2394,  2395,  2397,  2399,  2401,  2406,  2407,  2409,
    2413,  2415,  2418,  2423,  2425,  2428,  2431,  2434,  2437,  2439,
    2441,  2445,  2446,  2449,  2452,  2455,  2458,  2461,  2464,  2467,
    2470,  2473,  2476,  2479,  2481,  2483,  2485,  2487,  2489,  2491,
    2495,  2496,  2499,  2502,  2507,  2509,  2512,  2518,  2520,  2522,
    2525,  2528,  2533,  2535,  2537,  2539,  2541,  2545,  2546,  2549,
    2551,  2557,  2559,  2564,  2569,  2574,  2578,  2580,  2583,  2586,
    2589,  2593,  2595,  2598,  2600,  2604,  2606,  2609,  2612,  2615,
    2618,  2621,  2625,  2626,  2629,  2632,  2635,  2639,  2640,  2642,
    2647,  2648,  2650,  2654,  2655,  2657,  2661,  2663,  2666,  2670,
    2671,  2674,  2677,  2680,  2685,  2687,  2689,  2691,  2693,  2696,
    2699,  2703,  2707,  2708,  2711,  2714,  2717,  2719,  2722,  2726,
    2730,  2731,  2734,  2737,  2740,  2743,  2746,  2749,  2752,  2755,
    2758,  2761,  2764,  2767,  2770,  2774,  2775,  2778,  2782,  2783,
    2786,  2789,  2794,  2796,  2798,  2800,  2802,  2803,  2805,  2807,
    2811,  2813,  2816,  2819,  2822,  2825,  2828,  2831,  2835,  2840,
    2842,  2844,  2846,  2848,  2850,  2859,  2863,  2865,  2868,  2871,
    2874,  2877,  2885,  2886,  2888,  2889,  2891,  2892,  2894,  2895,
    2897,  2898,  2900,  2905,  2907,  2909,  2911,  2915,  2916,  2919,
    2922,  2925,  2928,  2930,  2932,  2934,  2936,  2938,  2940,  2943,
    2946,  2950,  2952,  2954,  2957,  2960,  2964,  2966,  2968,  2970,
    2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,
    2992,  2994,  2996,  2999,  3003,  3005,  3008,  3011,  3014,  3017,
    3019,  3021,  3023,  3025,  3029,  3035,  3037,  3040,  3043,  3046,
    3049,  3052,  3056,  3057,  3060,  3063,  3067,  3068,  3071,  3074,
    3077,  3080,  3083,  3086,  3089,  3092,  3094,  3096,  3101,  3102,
    3104,  3108,  3110,  3112,  3114,  3116,  3118,  3120,  3122,  3124,
    3126,  3128,  3132,  3136,  3142,  3146,  3150,  3151,  3154,  3157,
    3160,  3164,  3166,  3169,  3172,  3175,  3178,  3181,  3184,  3188,
    3190,  3193,  3196,  3199,  3202,  3205,  3208,  3210,  3212,  3214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     298,     0,    -1,   295,    -1,   116,   300,   302,   301,   488,
     299,   297,    -1,    -1,   299,   690,    -1,   299,   416,    -1,
     299,   495,    -1,   299,   384,    -1,   299,   350,    -1,   299,
     737,    -1,   551,    -1,   117,   766,   297,    -1,   118,   766,
     766,   766,   297,    -1,    62,   304,   297,    -1,   542,    -1,
     540,    -1,    63,   306,   297,    -1,   542,    -1,   306,   440,
      -1,   306,   530,    -1,   306,   504,    -1,   306,   350,    -1,
     306,   737,    -1,    64,   308,   297,    -1,   765,    -1,   695,
      -1,    65,   310,   297,    -1,   366,    -1,   310,   508,    -1,
     310,   520,    -1,   310,   350,    -1,   310,   737,    -1,    66,
     620,   620,   620,   297,    -1,    67,   551,   766,   313,   297,
      -1,    -1,   766,    -1,    68,   612,   297,    -1,    69,   316,
     297,    -1,   321,    -1,   317,    -1,   314,    -1,   316,   350,
      -1,   316,   737,    -1,    70,   686,   297,    -1,    71,   670,
     297,    -1,    72,   670,   297,    -1,    73,   765,   297,    -1,
      74,   297,    -1,    75,   323,   297,    -1,   517,    -1,   510,
      -1,   518,    -1,    76,   325,   326,   297,    -1,   318,    -1,
     448,    -1,   319,    -1,   492,    -1,    77,   328,   297,    -1,
      -1,   328,   332,    -1,   328,   329,    -1,   328,   327,    -1,
      78,   330,   297,    -1,   332,    -1,   330,   395,    -1,    79,
     332,   297,    -1,   728,    -1,   419,    -1,    80,   766,   766,
     327,   297,    -1,    81,   766,   297,    -1,    82,   659,   297,
      -1,    83,   338,   337,   297,    -1,   342,    -1,   337,   690,
      -1,   337,   746,    -1,   337,   742,    -1,   337,   350,    -1,
     337,   737,    -1,   337,   650,    -1,   551,    -1,    84,   341,
     340,   297,    -1,    -1,   497,    -1,   552,    -1,    85,   343,
     297,    -1,    55,    -1,    49,    -1,    23,    -1,    86,   345,
     346,   297,    -1,   643,    -1,   644,    -1,   637,    -1,    -1,
     322,    -1,   724,    -1,    87,   620,   620,   348,   297,    -1,
      -1,   348,   650,    -1,    88,   670,   670,   670,   297,    -1,
      89,   351,   297,    -1,    -1,   351,   765,    -1,    90,   353,
     297,    -1,    -1,   353,   307,    -1,   353,   430,    -1,   353,
     454,    -1,   353,   335,    -1,   353,   650,    -1,   353,   350,
      -1,   353,   737,    -1,    91,   517,   297,    -1,    93,   356,
     297,    -1,    -1,   356,   454,    -1,   356,   582,    -1,   356,
     430,    -1,   356,   673,    -1,   356,   553,    -1,   356,   557,
      -1,   356,   597,    -1,   356,   352,    -1,   356,   633,    -1,
     356,   716,    -1,   356,   678,    -1,   356,   760,    -1,   356,
     440,    -1,   356,   522,    -1,   356,   335,    -1,   356,   350,
      -1,   356,   737,    -1,    92,   358,   297,    -1,    -1,   430,
      -1,    94,   360,   297,    -1,    20,    -1,    50,    -1,    57,
      -1,    95,   362,   297,    -1,   766,    -1,   466,    -1,    96,
     542,   297,    -1,    97,   365,   297,    -1,    -1,   365,   311,
      -1,   365,   620,    -1,    98,   766,   367,   297,    -1,    -1,
     404,    -1,    99,   765,   369,   297,    -1,    -1,   741,    -1,
     100,   371,   297,    -1,   670,    -1,   578,    -1,   101,   373,
     297,    -1,   670,    -1,   578,    -1,   102,   375,   297,    -1,
     670,    -1,   578,    -1,   103,   377,   297,    -1,   670,    -1,
     578,    -1,   104,   379,   297,    -1,   542,    -1,   540,    -1,
     105,   381,   297,    -1,    -1,   381,   620,    -1,   106,   383,
     297,    -1,     9,    -1,    34,    -1,    47,    -1,   107,   388,
     385,   297,    -1,   339,    -1,   385,   690,    -1,   385,   350,
      -1,   385,   650,    -1,   385,   737,    -1,   108,   387,   297,
      -1,   765,    -1,   695,    -1,   551,    -1,   220,   390,   297,
      -1,    -1,   390,   437,    -1,   390,   432,    -1,   390,   661,
      -1,   390,   435,    -1,   390,   592,    -1,   390,   590,    -1,
     390,   405,    -1,   390,   472,    -1,   390,   476,    -1,   390,
     574,    -1,   390,   572,    -1,   390,   420,    -1,   390,   350,
      -1,   390,   737,    -1,   109,   392,   297,    -1,   428,    -1,
     434,    -1,   392,   428,    -1,   392,   434,    -1,   110,   394,
     297,    -1,    26,    -1,    27,    -1,    40,    -1,   111,   396,
     397,   398,   399,   297,    -1,   423,    -1,   426,    -1,    -1,
     483,    -1,    -1,   587,    -1,    -1,   589,    -1,   112,   401,
     297,    -1,    -1,   401,   517,    -1,   113,   403,   297,    -1,
     620,    -1,   403,   650,    -1,   114,   670,   297,    -1,   119,
     668,   424,   424,   406,   297,    -1,   656,    -1,   682,    -1,
     406,   350,    -1,   406,   737,    -1,   120,   408,   297,    -1,
      20,    -1,    50,    -1,    57,    -1,   121,   410,   411,   412,
     297,    -1,   533,    -1,   344,    -1,   692,    -1,   524,    -1,
     644,    -1,   569,    -1,   704,    -1,    -1,   378,    -1,   502,
      -1,   122,   414,   297,    -1,   644,    -1,   637,    -1,   631,
      -1,   567,    -1,   561,    -1,   414,   724,    -1,   414,   322,
      -1,   123,   670,   297,    -1,   124,   493,   301,   417,   297,
      -1,   709,    -1,   417,   690,    -1,   417,   336,    -1,   417,
     350,    -1,   417,   737,    -1,   125,   491,   423,   297,    -1,
     126,   297,    -1,   129,   421,   297,    -1,   422,    -1,   421,
     359,    -1,   421,   407,    -1,   421,   609,    -1,   421,   334,
      -1,   421,   349,    -1,   421,   439,    -1,   421,   333,    -1,
     421,   711,    -1,   421,   754,    -1,   421,   350,    -1,   421,
     650,    -1,   421,   737,    -1,   421,   451,    -1,   551,    -1,
     552,    -1,   130,   425,   297,    -1,   423,    -1,   428,    -1,
     434,    -1,   131,   427,   297,    -1,   423,    -1,   427,   359,
      -1,   427,   407,    -1,   427,   609,    -1,   427,   334,    -1,
     427,   349,    -1,   427,   439,    -1,   427,   333,    -1,   427,
     711,    -1,   427,   754,    -1,   427,   350,    -1,   427,   650,
      -1,   427,   737,    -1,   132,   423,   429,   297,    -1,    -1,
     497,    -1,   127,   431,   297,    -1,   422,    -1,   426,    -1,
     431,   347,    -1,   431,   402,    -1,   431,   585,    -1,   431,
     605,    -1,   431,   621,    -1,   431,   659,    -1,   431,   675,
      -1,   431,   350,    -1,   431,   737,    -1,   128,   668,   424,
     433,   297,    -1,   656,    -1,   682,    -1,   433,   350,    -1,
     433,   737,    -1,   474,    -1,   732,    -1,   391,    -1,   478,
      -1,   594,    -1,   133,   668,   424,   436,   297,    -1,   656,
      -1,   682,    -1,   436,   350,    -1,   436,   737,    -1,   134,
     668,   424,   438,   297,    -1,   656,    -1,   682,    -1,   438,
     350,    -1,   438,   737,    -1,   135,   766,   766,   327,   297,
      -1,   136,   441,   442,   297,    -1,   643,    -1,   644,    -1,
     644,    -1,   704,    -1,   442,   378,    -1,   442,   502,    -1,
     137,   444,   297,    -1,   712,    -1,   444,   413,    -1,   767,
     446,   295,    -1,    -1,   446,   766,    -1,   446,   765,    -1,
     446,   764,    -1,   446,   445,    -1,   138,   643,   297,    -1,
     139,   670,   297,    -1,   140,   670,   670,   297,    -1,   141,
     297,    -1,   142,   452,   297,    -1,   428,    -1,   434,    -1,
     143,   297,    -1,   144,   464,   455,   297,    -1,   750,    -1,
     744,    -1,   455,   718,    -1,   455,   604,    -1,   455,   635,
      -1,   455,   716,    -1,   455,   386,    -1,   455,   650,    -1,
     455,   350,    -1,   455,   737,    -1,   148,   465,   457,   297,
      -1,    -1,   456,    -1,   750,    -1,   145,   459,   297,    -1,
     456,    -1,   459,   386,    -1,   459,   716,    -1,   459,   650,
      -1,   459,   350,    -1,   146,   461,   297,    -1,    -1,   461,
     456,    -1,   147,   463,   297,    -1,    -1,   463,   456,    -1,
     463,   460,    -1,   463,   350,    -1,   463,   737,    -1,   551,
      -1,   312,    -1,   552,    -1,   536,    -1,   150,   467,   297,
      -1,   766,    -1,   467,   395,    -1,   149,   469,   297,    -1,
      -1,   469,   766,    -1,   469,   466,    -1,   469,   468,    -1,
     151,   471,   297,    -1,    -1,   471,   623,    -1,   471,   627,
      -1,   471,   700,    -1,   471,   654,    -1,   471,   315,    -1,
     471,   602,    -1,   471,   481,    -1,   471,   547,    -1,   471,
     758,    -1,   471,   610,    -1,   471,   716,    -1,   471,   678,
      -1,   471,   386,    -1,   471,   650,    -1,   471,   350,    -1,
     471,   737,    -1,   152,   668,   424,   424,   473,   297,    -1,
     656,    -1,   682,    -1,   473,   350,    -1,   473,   737,    -1,
     153,   475,   297,    -1,   428,    -1,   434,    -1,   475,   428,
      -1,   475,   434,    -1,   154,   668,   424,   477,   297,    -1,
     656,    -1,   682,    -1,   477,   350,    -1,   477,   737,    -1,
     155,   479,   297,    -1,   428,    -1,   434,    -1,   156,   297,
      -1,   157,   482,   297,    -1,    -1,   482,   644,    -1,   482,
     637,    -1,   482,   447,    -1,   158,   484,   297,    -1,    11,
      -1,    12,    -1,    13,    -1,    29,    -1,    30,    -1,    31,
      -1,    58,    -1,    59,    -1,    60,    -1,   159,   486,   297,
      -1,   490,    -1,   486,   395,    -1,   160,   766,   297,    -1,
     161,   489,   297,    -1,   487,    -1,   489,   350,    -1,   764,
      -1,   551,    -1,   162,   670,   297,    -1,   551,    -1,   552,
      -1,   163,   493,   301,   496,   297,    -1,   709,    -1,   496,
     690,    -1,   496,   336,    -1,   496,   350,    -1,   496,   737,
      -1,   164,   494,   297,    -1,   165,   499,   297,    -1,    -1,
     499,   553,    -1,   166,   501,   297,    -1,    -1,   501,   623,
      -1,   501,   627,    -1,   167,   503,   503,   297,    -1,   542,
      -1,   540,    -1,   168,   505,   506,   507,   297,    -1,   643,
      -1,   644,    -1,   644,    -1,   524,    -1,   704,    -1,    -1,
     378,    -1,   502,    -1,   169,   509,   297,    -1,   637,    -1,
     644,    -1,   643,    -1,   509,   528,    -1,   170,   511,   297,
      -1,    -1,   511,   517,    -1,   511,   518,    -1,   511,   450,
      -1,   171,   513,   297,    -1,    -1,   513,   517,    -1,   172,
     515,   297,    -1,    -1,   515,   517,    -1,   551,    -1,   552,
      -1,   173,   519,   297,    -1,    -1,   519,   517,    -1,   519,
     510,    -1,   174,   521,   297,    -1,   637,    -1,   644,    -1,
     643,    -1,   521,   528,    -1,   175,   523,   297,    -1,   642,
      -1,   523,   650,    -1,   523,   350,    -1,   523,   737,    -1,
     176,   517,   525,   297,    -1,    -1,   497,    -1,   177,   527,
     297,    -1,   516,    -1,   527,   755,    -1,   527,   363,    -1,
     527,   331,    -1,   527,   354,    -1,   527,   757,    -1,   527,
     699,    -1,   527,   400,    -1,   527,   514,    -1,   527,   512,
      -1,   527,   480,    -1,   527,   666,    -1,   527,   650,    -1,
     527,   350,    -1,   527,   737,    -1,   178,   529,   297,    -1,
      -1,   529,   517,    -1,   529,   510,    -1,   529,   518,    -1,
     529,   450,    -1,   179,   531,   532,   297,    -1,   643,    -1,
     644,    -1,    -1,   378,    -1,   502,    -1,   180,   534,   535,
     297,    -1,   643,    -1,   644,    -1,   637,    -1,   517,    -1,
     510,    -1,   518,    -1,   181,   552,   537,   297,    -1,   766,
      -1,   537,   766,    -1,   182,   539,   297,    -1,    -1,   539,
     542,    -1,   539,   540,    -1,   539,   538,    -1,   183,   541,
     297,    -1,   542,    -1,   541,   395,    -1,   543,    -1,   670,
      -1,   184,   544,   544,   544,   297,    -1,   670,    -1,   731,
      -1,   730,    -1,   185,   546,   297,    -1,    -1,   546,   657,
      -1,   186,   548,   297,    -1,    -1,   548,   644,    -1,   548,
     637,    -1,   548,   758,    -1,   548,   481,    -1,   187,   550,
     297,    -1,   764,    -1,   550,   395,    -1,   764,    -1,   549,
      -1,   663,    -1,   764,    -1,   549,    -1,   188,   565,   554,
     297,    -1,   481,    -1,   554,   361,    -1,   554,   559,    -1,
     554,   430,    -1,   554,   553,    -1,   554,   454,    -1,   554,
     352,    -1,   554,   650,    -1,   554,   350,    -1,   554,   737,
      -1,   189,   556,   297,    -1,   567,    -1,   556,   559,    -1,
     556,   361,    -1,   556,   650,    -1,   556,   350,    -1,   190,
     565,   558,   297,    -1,   498,    -1,   558,   430,    -1,   558,
     352,    -1,   558,   650,    -1,   558,   350,    -1,   558,   737,
      -1,   191,   382,   560,   297,    -1,   378,    -1,   560,   724,
      -1,   560,   322,    -1,   192,   562,   297,    -1,    -1,   562,
     566,    -1,   562,   567,    -1,   193,   564,   297,    -1,    -1,
     564,   567,    -1,   564,   561,    -1,   564,   350,    -1,   564,
     737,    -1,   551,    -1,   312,    -1,   552,    -1,   536,    -1,
     194,   566,   568,   297,    -1,    -1,   567,    -1,   456,    -1,
     750,    -1,   195,   297,    -1,   196,   571,   297,    -1,    -1,
     571,   644,    -1,   571,   610,    -1,   197,   668,   573,   297,
      -1,   424,    -1,   573,   350,    -1,   573,   737,    -1,   198,
     668,   424,   575,   297,    -1,   656,    -1,   682,    -1,   575,
     350,    -1,   575,   737,    -1,   199,   577,   297,    -1,    -1,
     577,   670,    -1,   577,   578,    -1,   577,   576,    -1,   201,
     579,   297,    -1,   670,    -1,   579,   395,    -1,   200,   581,
     297,    -1,    -1,   581,   669,    -1,   581,   449,    -1,   581,
     350,    -1,   202,   583,   297,    -1,   642,    -1,   583,   736,
      -1,   583,   650,    -1,   583,   350,    -1,   583,   737,    -1,
     203,   413,   670,   297,    -1,   204,   586,   297,    -1,   364,
      -1,   586,   650,    -1,   205,   588,   297,    -1,    43,    -1,
      46,    -1,    44,    -1,    45,    -1,    35,    -1,    37,    -1,
      38,    -1,    36,    -1,   206,   620,   297,    -1,   207,   668,
     424,   424,   591,   297,    -1,   656,    -1,   682,    -1,   591,
     350,    -1,   591,   737,    -1,   208,   668,   424,   424,   593,
     297,    -1,   656,    -1,   682,    -1,   593,   350,    -1,   593,
     737,    -1,   209,   766,   595,   359,   297,    -1,   428,    -1,
     434,    -1,   210,   765,   297,    -1,   211,   598,   297,    -1,
     464,    -1,   598,   454,    -1,   598,   553,    -1,   598,   557,
      -1,   598,   352,    -1,   598,   633,    -1,   598,   599,    -1,
     598,   335,    -1,   598,   350,    -1,   598,   737,    -1,   212,
     659,   297,    -1,   215,   601,   297,    -1,   740,    -1,   601,
     395,    -1,   213,   739,   729,   603,   297,    -1,    -1,   734,
      -1,   214,   740,   729,   297,    -1,   216,   606,   297,    -1,
     618,    -1,   606,   650,    -1,   217,   608,   297,    -1,   378,
      -1,   608,   413,    -1,   218,   766,   297,    -1,   219,   611,
     297,    -1,    -1,   611,   644,    -1,   611,   610,    -1,   611,
     570,    -1,   221,   613,   297,    -1,    -1,   613,   688,    -1,
     222,   615,   297,    -1,    -1,   615,   620,    -1,   615,   616,
      -1,   615,   614,    -1,   223,   617,   297,    -1,   620,    -1,
     617,   395,    -1,   224,   619,   297,    -1,    -1,   619,   620,
      -1,   241,   766,   766,   297,    -1,   225,   622,   297,    -1,
     618,    -1,   622,   650,    -1,   226,   624,   297,    -1,   642,
      -1,   624,   393,    -1,   624,   736,    -1,   624,   629,    -1,
     624,   386,    -1,   624,   370,    -1,   624,   372,    -1,   624,
     374,    -1,   624,   376,    -1,   624,   303,    -1,   624,   650,
      -1,   624,   350,    -1,   624,   737,    -1,   227,   626,   297,
      -1,   644,    -1,   626,   386,    -1,   626,   629,    -1,   626,
     370,    -1,   626,   372,    -1,   626,   374,    -1,   626,   376,
      -1,   626,   303,    -1,   626,   650,    -1,   626,   350,    -1,
     228,   642,   628,   297,    -1,   500,    -1,   628,   650,    -1,
     628,   350,    -1,   628,   737,    -1,   229,   382,   630,   297,
      -1,   378,    -1,   502,    -1,   630,   724,    -1,   630,   322,
      -1,   230,   632,   297,    -1,    -1,   632,   643,    -1,   632,
     644,    -1,   231,   634,   297,    -1,   644,    -1,   643,    -1,
     634,   357,    -1,   634,   430,    -1,   634,   454,    -1,   634,
     352,    -1,   634,   648,    -1,   634,   485,    -1,   634,   650,
      -1,   634,   737,    -1,   634,   350,    -1,   232,   636,   297,
      -1,   644,    -1,   643,    -1,   636,   736,    -1,   636,   629,
      -1,   636,   386,    -1,   636,   370,    -1,   636,   372,    -1,
     636,   374,    -1,   636,   376,    -1,   636,   303,    -1,   636,
     650,    -1,   636,   350,    -1,   636,   737,    -1,   233,   638,
     297,    -1,    -1,   638,   644,    -1,   638,   643,    -1,   234,
     642,   637,   297,    -1,   235,   641,   297,    -1,    -1,   641,
     644,    -1,   641,   631,    -1,   641,   350,    -1,   641,   737,
      -1,   551,    -1,   312,    -1,   552,    -1,   536,    -1,   236,
     643,   645,   297,    -1,    -1,   644,    -1,   456,    -1,   750,
      -1,   237,   765,   647,   297,    -1,    -1,   741,    -1,   239,
     649,   297,    -1,   653,    -1,   649,   395,    -1,   238,   652,
     651,   297,    -1,   729,    -1,   651,   596,    -1,   651,   734,
      -1,   651,   650,    -1,   651,   350,    -1,   551,    -1,   552,
      -1,   240,   655,   297,    -1,    -1,   655,   633,    -1,   655,
     430,    -1,   655,   454,    -1,   655,   352,    -1,   655,   335,
      -1,   655,   648,    -1,   655,   485,    -1,   655,   600,    -1,
     655,   650,    -1,   655,   350,    -1,   655,   737,    -1,   492,
      -1,   448,    -1,   319,    -1,   318,    -1,   415,    -1,   324,
      -1,   242,   658,   297,    -1,    -1,   658,   656,    -1,   658,
     682,    -1,   243,   620,   660,   297,    -1,   620,    -1,   660,
     650,    -1,   244,   668,   424,   662,   297,    -1,   657,    -1,
     545,    -1,   662,   350,    -1,   662,   737,    -1,   245,   664,
     665,   297,    -1,   764,    -1,   549,    -1,   765,    -1,   695,
      -1,   246,   667,   297,    -1,    -1,   667,   517,    -1,   551,
      -1,   247,   670,   670,   734,   297,    -1,   766,    -1,   115,
     766,   766,   297,    -1,   248,   766,   766,   297,    -1,   249,
     766,   766,   297,    -1,   250,   674,   297,    -1,   765,    -1,
     674,   673,    -1,   674,   765,    -1,   674,   454,    -1,   251,
     676,   297,    -1,   364,    -1,   676,   650,    -1,   551,    -1,
     252,   679,   297,    -1,   677,    -1,   679,   639,    -1,   679,
     756,    -1,   679,   309,    -1,   679,   350,    -1,   679,   737,
      -1,   253,   681,   297,    -1,    -1,   681,   526,    -1,   681,
     350,    -1,   681,   737,    -1,   254,   683,   297,    -1,    -1,
     656,    -1,   255,   750,   685,   297,    -1,    -1,   718,    -1,
     256,   687,   297,    -1,    -1,   702,    -1,   257,   689,   297,
      -1,   702,    -1,   689,   684,    -1,   258,   691,   297,    -1,
      -1,   691,   762,    -1,   691,   350,    -1,   691,   737,    -1,
     259,   693,   694,   297,    -1,   643,    -1,   644,    -1,   637,
      -1,   404,    -1,   694,   724,    -1,   694,   322,    -1,   261,
     698,   297,    -1,   260,   697,   297,    -1,    -1,   697,   765,
      -1,   697,   695,    -1,   697,   696,    -1,   765,    -1,   698,
     395,    -1,   262,   517,   297,    -1,   263,   701,   297,    -1,
      -1,   701,   633,    -1,   701,   430,    -1,   701,   454,    -1,
     701,   352,    -1,   701,   307,    -1,   701,   599,    -1,   701,
     335,    -1,   701,   648,    -1,   701,   485,    -1,   701,   600,
      -1,   701,   650,    -1,   701,   350,    -1,   701,   737,    -1,
     264,   703,   297,    -1,    -1,   703,   718,    -1,   265,   705,
     297,    -1,    -1,   705,   409,    -1,   705,   706,    -1,   266,
     707,   708,   297,    -1,   524,    -1,   644,    -1,   569,    -1,
     704,    -1,    -1,   378,    -1,   502,    -1,   267,   710,   297,
      -1,   580,    -1,   710,   420,    -1,   710,   418,    -1,   710,
     680,    -1,   710,   389,    -1,   710,   350,    -1,   710,   737,
      -1,   268,   766,   297,    -1,   269,   713,   714,   297,    -1,
     413,    -1,   584,    -1,   413,    -1,   584,    -1,   404,    -1,
     270,   766,   766,   766,   766,   766,   766,   297,    -1,   271,
     717,   297,    -1,   382,    -1,   717,   607,    -1,   717,   443,
      -1,   717,   350,    -1,   717,   737,    -1,   272,   719,   720,
     721,   722,   723,   297,    -1,    -1,   671,    -1,    -1,   672,
      -1,    -1,   380,    -1,    -1,   587,    -1,    -1,   589,    -1,
     273,   725,   725,   297,    -1,   517,    -1,   510,    -1,   518,
      -1,   274,   727,   297,    -1,    -1,   727,   344,    -1,   727,
     692,    -1,   727,   453,    -1,   275,   297,    -1,   327,    -1,
     468,    -1,   538,    -1,   576,    -1,   614,    -1,   696,    -1,
     276,   297,    -1,   277,   297,    -1,   278,   733,   297,    -1,
     428,    -1,   434,    -1,   733,   428,    -1,   733,   434,    -1,
     279,   735,   297,    -1,    17,    -1,    10,    -1,    16,    -1,
      48,    -1,    54,    -1,    56,    -1,    61,    -1,    33,    -1,
      22,    -1,    25,    -1,    19,    -1,    42,    -1,    14,    -1,
      15,    -1,    21,    -1,     7,    -1,   280,   297,    -1,   281,
     738,   297,    -1,   764,    -1,   738,   766,    -1,   738,   765,
      -1,   738,   764,    -1,   738,   445,    -1,   551,    -1,   312,
      -1,   552,    -1,   536,    -1,   282,   765,   297,    -1,   283,
     748,   752,   743,   297,    -1,   470,    -1,   743,   690,    -1,
     743,   355,    -1,   743,   350,    -1,   743,   650,    -1,   743,
     737,    -1,   284,   745,   297,    -1,    -1,   745,   750,    -1,
     745,   744,    -1,   285,   747,   297,    -1,    -1,   747,   640,
      -1,   747,   625,    -1,   747,   462,    -1,   747,   458,    -1,
     747,   563,    -1,   747,   555,    -1,   747,   350,    -1,   747,
     737,    -1,   551,    -1,   552,    -1,   286,   749,   751,   297,
      -1,    -1,   339,    -1,   287,   753,   297,    -1,    32,    -1,
      41,    -1,    39,    -1,    51,    -1,    53,    -1,     8,    -1,
      28,    -1,    18,    -1,    24,    -1,    52,    -1,   288,   332,
     297,    -1,   289,   542,   297,    -1,   290,   516,   670,   528,
     297,    -1,   291,   517,   297,    -1,   292,   759,   297,    -1,
      -1,   759,   644,    -1,   759,   637,    -1,   759,   481,    -1,
     293,   761,   297,    -1,   726,    -1,   761,   305,    -1,   761,
     440,    -1,   761,   530,    -1,   761,   504,    -1,   761,   350,
      -1,   761,   737,    -1,   294,   763,   297,    -1,   715,    -1,
     763,   320,    -1,   763,   646,    -1,   763,   368,    -1,   763,
     650,    -1,   763,   350,    -1,   763,   737,    -1,     3,    -1,
       6,    -1,     4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   506,   506,   509,   512,   513,   514,   515,   516,   517,
     518,   521,   524,   527,   531,   534,   535,   538,   541,   542,
     543,   544,   545,   546,   549,   552,   553,   556,   559,   560,
     561,   562,   563,   566,   569,   572,   573,   576,   579,   582,
     583,   584,   585,   586,   589,   592,   595,   598,   601,   604,
     607,   608,   609,   612,   615,   616,   619,   620,   623,   626,
     627,   628,   629,   632,   635,   636,   639,   642,   643,   646,
     649,   652,   655,   658,   659,   660,   661,   662,   663,   664,
     667,   670,   673,   674,   677,   680,   683,   684,   685,   688,
     691,   692,   693,   696,   697,   698,   701,   704,   705,   708,
     711,   714,   715,   718,   721,   722,   723,   724,   725,   726,
     727,   728,   731,   734,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   757,   760,   761,   764,   767,   768,   769,   772,
     775,   776,   779,   782,   785,   786,   787,   790,   793,   794,
     797,   800,   801,   804,   807,   808,   811,   814,   815,   818,
     821,   822,   825,   828,   829,   832,   835,   836,   839,   842,
     843,   846,   849,   850,   851,   854,   857,   858,   859,   860,
     861,   864,   867,   868,   871,   874,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   894,   897,   898,   899,   900,   903,   906,   907,   908,
     911,   914,   915,   918,   919,   922,   923,   926,   927,   930,
     933,   934,   937,   940,   941,   944,   947,   951,   952,   953,
     954,   957,   960,   961,   962,   965,   969,   970,   971,   974,
     975,   976,   977,   980,   981,   982,   985,   988,   989,   990,
     991,   992,   993,   994,   997,  1000,  1003,  1004,  1005,  1006,
    1007,  1010,  1013,  1016,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1035,  1038,
    1041,  1044,  1045,  1046,  1049,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1067,  1070,
    1071,  1074,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1090,  1093,  1094,  1095,  1096,  1099,  1100,
    1101,  1102,  1103,  1106,  1109,  1110,  1111,  1112,  1115,  1118,
    1119,  1120,  1121,  1124,  1127,  1130,  1131,  1134,  1135,  1136,
    1137,  1140,  1143,  1144,  1147,  1150,  1151,  1152,  1153,  1154,
    1157,  1160,  1163,  1166,  1169,  1172,  1173,  1176,  1179,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1194,
    1197,  1198,  1199,  1202,  1205,  1206,  1207,  1208,  1209,  1212,
    1215,  1216,  1219,  1222,  1223,  1224,  1225,  1226,  1229,  1230,
    1233,  1234,  1237,  1240,  1241,  1244,  1247,  1248,  1249,  1250,
    1253,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1275,  1279,
    1280,  1281,  1282,  1285,  1288,  1289,  1290,  1291,  1294,  1297,
    1298,  1299,  1300,  1303,  1306,  1307,  1310,  1313,  1316,  1317,
    1318,  1319,  1322,  1325,  1326,  1327,  1328,  1329,  1330,  1331,
    1332,  1333,  1336,  1339,  1340,  1343,  1346,  1349,  1350,  1353,
    1356,  1359,  1362,  1365,  1368,  1371,  1372,  1373,  1374,  1375,
    1378,  1381,  1384,  1385,  1388,  1391,  1392,  1393,  1396,  1399,
    1400,  1403,  1406,  1407,  1410,  1411,  1412,  1415,  1416,  1417,
    1420,  1423,  1424,  1425,  1426,  1429,  1432,  1433,  1434,  1435,
    1438,  1441,  1442,  1445,  1448,  1449,  1452,  1455,  1458,  1461,
    1462,  1463,  1466,  1469,  1470,  1471,  1472,  1475,  1478,  1479,
    1480,  1481,  1484,  1487,  1488,  1491,  1494,  1495,  1496,  1497,
    1498,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,
    1508,  1511,  1514,  1515,  1516,  1517,  1518,  1521,  1524,  1525,
    1528,  1529,  1530,  1533,  1536,  1537,  1538,  1541,  1542,  1543,
    1546,  1549,  1550,  1553,  1556,  1557,  1558,  1559,  1562,  1565,
    1566,  1569,  1570,  1573,  1576,  1577,  1578,  1581,  1584,  1585,
    1588,  1591,  1592,  1593,  1594,  1595,  1598,  1601,  1602,  1605,
    1606,  1607,  1610,  1611,  1614,  1617,  1618,  1619,  1620,  1621,
    1622,  1623,  1624,  1625,  1626,  1629,  1632,  1633,  1634,  1635,
    1636,  1639,  1642,  1643,  1644,  1645,  1646,  1647,  1650,  1653,
    1654,  1655,  1658,  1661,  1662,  1663,  1666,  1669,  1670,  1671,
    1672,  1673,  1676,  1677,  1681,  1682,  1685,  1688,  1689,  1690,
    1691,  1694,  1697,  1700,  1701,  1702,  1705,  1708,  1709,  1710,
    1713,  1716,  1717,  1718,  1719,  1722,  1725,  1726,  1727,  1728,
    1731,  1734,  1735,  1738,  1741,  1742,  1743,  1744,  1747,  1750,
    1751,  1752,  1753,  1754,  1757,  1760,  1763,  1764,  1767,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1780,  1783,  1787,
    1788,  1789,  1790,  1793,  1797,  1798,  1799,  1800,  1803,  1806,
    1807,  1810,  1813,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1824,  1825,  1828,  1831,  1834,  1835,  1838,  1841,  1842,
    1845,  1848,  1851,  1852,  1855,  1858,  1859,  1862,  1865,  1868,
    1869,  1870,  1871,  1874,  1877,  1878,  1881,  1884,  1885,  1886,
    1887,  1890,  1893,  1894,  1897,  1900,  1901,  1904,  1907,  1910,
    1911,  1914,  1917,  1918,  1919,  1920,  1921,  1922,  1923,  1924,
    1925,  1926,  1927,  1928,  1929,  1932,  1935,  1936,  1937,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1947,  1950,  1951,  1952,
    1953,  1956,  1959,  1960,  1961,  1962,  1965,  1968,  1969,  1970,
    1973,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,
    1985,  1986,  1989,  1992,  1993,  1994,  1995,  1996,  1997,  1998,
    1999,  2000,  2001,  2002,  2003,  2004,  2007,  2010,  2011,  2012,
    2015,  2018,  2021,  2022,  2023,  2024,  2025,  2028,  2029,  2032,
    2033,  2036,  2051,  2052,  2053,  2054,  2057,  2060,  2061,  2064,
    2067,  2068,  2071,  2074,  2075,  2076,  2077,  2078,  2081,  2084,
    2087,  2090,  2091,  2092,  2093,  2094,  2095,  2096,  2097,  2098,
    2099,  2100,  2101,  2104,  2105,  2106,  2107,  2108,  2109,  2112,
    2115,  2116,  2117,  2120,  2123,  2124,  2127,  2130,  2131,  2132,
    2133,  2136,  2140,  2141,  2144,  2145,  2148,  2151,  2152,  2155,
    2158,  2161,  2162,  2165,  2168,  2171,  2174,  2175,  2176,  2177,
    2180,  2183,  2184,  2187,  2190,  2193,  2194,  2195,  2196,  2197,
    2198,  2201,  2204,  2205,  2206,  2207,  2210,  2213,  2214,  2217,
    2220,  2221,  2224,  2227,  2228,  2231,  2234,  2235,  2238,  2241,
    2242,  2243,  2244,  2247,  2250,  2251,  2252,  2255,  2256,  2257,
    2260,  2263,  2266,  2267,  2268,  2269,  2272,  2273,  2276,  2279,
    2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  2294,  2295,  2298,  2301,  2302,  2305,  2308,  2309,
    2310,  2313,  2316,  2317,  2318,  2319,  2322,  2323,  2324,  2327,
    2330,  2331,  2332,  2333,  2334,  2335,  2336,  2339,  2342,  2345,
    2346,  2349,  2350,  2351,  2354,  2358,  2361,  2362,  2363,  2364,
    2365,  2368,  2372,  2373,  2376,  2377,  2380,  2381,  2384,  2385,
    2388,  2389,  2392,  2395,  2396,  2397,  2400,  2403,  2404,  2405,
    2406,  2409,  2412,  2413,  2414,  2415,  2416,  2417,  2420,  2423,
    2426,  2429,  2430,  2431,  2432,  2435,  2438,  2439,  2440,  2441,
    2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,
    2452,  2453,  2456,  2459,  2462,  2463,  2464,  2465,  2466,  2469,
    2470,  2473,  2474,  2477,  2480,  2483,  2484,  2485,  2486,  2487,
    2488,  2491,  2494,  2495,  2496,  2499,  2502,  2503,  2504,  2505,
    2506,  2507,  2508,  2509,  2510,  2513,  2516,  2519,  2522,  2523,
    2526,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2541,  2544,  2547,  2550,  2553,  2556,  2557,  2558,  2559,
    2562,  2565,  2566,  2567,  2568,  2569,  2570,  2571,  2574,  2577,
    2578,  2579,  2580,  2581,  2582,  2583,  2586,  2589,  2592,  2595
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EDIF_TOK_IDENT", "EDIF_TOK_INT",
  "EDIF_TOK_KEYWORD", "EDIF_TOK_STR", "EDIF_TOK_ANGLE",
  "EDIF_TOK_BEHAVIOR", "EDIF_TOK_CALCULATED", "EDIF_TOK_CAPACITANCE",
  "EDIF_TOK_CENTERCENTER", "EDIF_TOK_CENTERLEFT", "EDIF_TOK_CENTERRIGHT",
  "EDIF_TOK_CHARGE", "EDIF_TOK_CONDUCTANCE", "EDIF_TOK_CURRENT",
  "EDIF_TOK_DISTANCE", "EDIF_TOK_DOCUMENT", "EDIF_TOK_ENERGY",
  "EDIF_TOK_EXTEND", "EDIF_TOK_FLUX", "EDIF_TOK_FREQUENCY",
  "EDIF_TOK_GENERIC", "EDIF_TOK_GRAPHIC", "EDIF_TOK_INDUCTANCE",
  "EDIF_TOK_INOUT", "EDIF_TOK_INPUT", "EDIF_TOK_LOGICMODEL",
  "EDIF_TOK_LOWERCENTER", "EDIF_TOK_LOWERLEFT", "EDIF_TOK_LOWERRIGHT",
  "EDIF_TOK_MASKLAYOUT", "EDIF_TOK_MASS", "EDIF_TOK_MEASURED",
  "EDIF_TOK_MX", "EDIF_TOK_MXR90", "EDIF_TOK_MY", "EDIF_TOK_MYR90",
  "EDIF_TOK_NETLIST", "EDIF_TOK_OUTPUT", "EDIF_TOK_PCBLAYOUT",
  "EDIF_TOK_POWER", "EDIF_TOK_R0", "EDIF_TOK_R180", "EDIF_TOK_R270",
  "EDIF_TOK_R90", "EDIF_TOK_REQUIRED", "EDIF_TOK_RESISTANCE",
  "EDIF_TOK_RIPPER", "EDIF_TOK_ROUND", "EDIF_TOK_SCHEMATIC",
  "EDIF_TOK_STRANGER", "EDIF_TOK_SYMBOLIC", "EDIF_TOK_TEMPERATURE",
  "EDIF_TOK_TIE", "EDIF_TOK_TIME", "EDIF_TOK_TRUNCATE",
  "EDIF_TOK_UPPERCENTER", "EDIF_TOK_UPPERLEFT", "EDIF_TOK_UPPERRIGHT",
  "EDIF_TOK_VOLTAGE", "EDIF_TOK_ACLOAD", "EDIF_TOK_AFTER",
  "EDIF_TOK_ANNOTATE", "EDIF_TOK_APPLY", "EDIF_TOK_ARC", "EDIF_TOK_ARRAY",
  "EDIF_TOK_ARRAYMACRO", "EDIF_TOK_ARRAYRELATEDINFO", "EDIF_TOK_ARRAYSITE",
  "EDIF_TOK_ATLEAST", "EDIF_TOK_ATMOST", "EDIF_TOK_AUTHOR",
  "EDIF_TOK_BASEARRAY", "EDIF_TOK_BECOMES", "EDIF_TOK_BETWEEN",
  "EDIF_TOK_BOOLEAN", "EDIF_TOK_BOOLEANDISPLAY", "EDIF_TOK_BOOLEANMAP",
  "EDIF_TOK_BORDERPATTERN", "EDIF_TOK_BORDERWIDTH", "EDIF_TOK_BOUNDINGBOX",
  "EDIF_TOK_CELL", "EDIF_TOK_CELLREF", "EDIF_TOK_CELLTYPE",
  "EDIF_TOK_CHANGE", "EDIF_TOK_CIRCLE", "EDIF_TOK_COLOR",
  "EDIF_TOK_COMMENT", "EDIF_TOK_COMMENTGRAPHICS", "EDIF_TOK_COMPOUND",
  "EDIF_TOK_CONNECTLOCATION", "EDIF_TOK_CONTENTS", "EDIF_TOK_CORNERTYPE",
  "EDIF_TOK_CRITICALITY", "EDIF_TOK_CURRENTMAP", "EDIF_TOK_CURVE",
  "EDIF_TOK_CYCLE", "EDIF_TOK_DATAORIGIN", "EDIF_TOK_DCFANINLOAD",
  "EDIF_TOK_DCFANOUTLOAD", "EDIF_TOK_DCMAXFANIN", "EDIF_TOK_DCMAXFANOUT",
  "EDIF_TOK_DELAY", "EDIF_TOK_DELTA", "EDIF_TOK_DERIVATION",
  "EDIF_TOK_DESIGN", "EDIF_TOK_DESIGNATOR", "EDIF_TOK_DIFFERENCE",
  "EDIF_TOK_DIRECTION", "EDIF_TOK_DISPLAY", "EDIF_TOK_DOMINATES",
  "EDIF_TOK_DOT", "EDIF_TOK_DURATION", "EDIF_TOK_E", "EDIF_TOK_EDIF",
  "EDIF_TOK_EDIFLEVEL", "EDIF_TOK_EDIFVERSION",
  "EDIF_TOK_ENCLOSUREDISTANCE", "EDIF_TOK_ENDTYPE", "EDIF_TOK_ENTRY",
  "EDIF_TOK_EVENT", "EDIF_TOK_EXACTLY", "EDIF_TOK_EXTERNAL",
  "EDIF_TOK_FABRICATE", "EDIF_TOK_FALSE", "EDIF_TOK_FIGURE",
  "EDIF_TOK_FIGUREAREA", "EDIF_TOK_FIGUREGROUP",
  "EDIF_TOK_FIGUREGROUPOBJECT", "EDIF_TOK_FIGUREGROUPOVERRIDE",
  "EDIF_TOK_FIGUREGROUPREF", "EDIF_TOK_FIGUREPERIMETER",
  "EDIF_TOK_FIGUREWIDTH", "EDIF_TOK_FILLPATTERN", "EDIF_TOK_FOLLOW",
  "EDIF_TOK_FORBIDDENEVENT", "EDIF_TOK_GLOBALPORTREF",
  "EDIF_TOK_GREATERTHAN", "EDIF_TOK_GRIDMAP", "EDIF_TOK_IGNORE",
  "EDIF_TOK_INCLUDEFIGUREGROUP", "EDIF_TOK_INITIAL", "EDIF_TOK_INSTANCE",
  "EDIF_TOK_INSTANCEBACKANNOTATE", "EDIF_TOK_INSTANCEGROUP",
  "EDIF_TOK_INSTANCEMAP", "EDIF_TOK_INSTANCEREF", "EDIF_TOK_INTEGER",
  "EDIF_TOK_INTEGERDISPLAY", "EDIF_TOK_INTERFACE",
  "EDIF_TOK_INTERFIGUREGROUPSPACING", "EDIF_TOK_INTERSECTION",
  "EDIF_TOK_INTRAFIGUREGROUPSPACING", "EDIF_TOK_INVERSE",
  "EDIF_TOK_ISOLATED", "EDIF_TOK_JOINED", "EDIF_TOK_JUSTIFY",
  "EDIF_TOK_KEYWORDDISPLAY", "EDIF_TOK_KEYWORDLEVEL",
  "EDIF_TOK_KEYWORDMAP", "EDIF_TOK_LESSTHAN", "EDIF_TOK_LIBRARY",
  "EDIF_TOK_LIBRARYREF", "EDIF_TOK_LISTOFNETS", "EDIF_TOK_LISTOFPORTS",
  "EDIF_TOK_LOADDELAY", "EDIF_TOK_LOGICASSIGN", "EDIF_TOK_LOGICINPUT",
  "EDIF_TOK_LOGICLIST", "EDIF_TOK_LOGICMAPINPUT",
  "EDIF_TOK_LOGICMAPOUTPUT", "EDIF_TOK_LOGICONEOF", "EDIF_TOK_LOGICOUTPUT",
  "EDIF_TOK_LOGICPORT", "EDIF_TOK_LOGICREF", "EDIF_TOK_LOGICVALUE",
  "EDIF_TOK_LOGICWAVEFORM", "EDIF_TOK_MAINTAIN", "EDIF_TOK_MATCH",
  "EDIF_TOK_MEMBER", "EDIF_TOK_MINOMAX", "EDIF_TOK_MINOMAXDISPLAY",
  "EDIF_TOK_MNM", "EDIF_TOK_MULTIPLEVALUESET", "EDIF_TOK_MUSTJOIN",
  "EDIF_TOK_NAME", "EDIF_TOK_NET", "EDIF_TOK_NETBACKANNOTATE",
  "EDIF_TOK_NETBUNDLE", "EDIF_TOK_NETDELAY", "EDIF_TOK_NETGROUP",
  "EDIF_TOK_NETMAP", "EDIF_TOK_NETREF", "EDIF_TOK_NOCHANGE",
  "EDIF_TOK_NONPERMUTABLE", "EDIF_TOK_NOTALLOWED", "EDIF_TOK_NOTCHSPACING",
  "EDIF_TOK_NUMBER", "EDIF_TOK_NUMBERDEFINITION", "EDIF_TOK_NUMBERDISPLAY",
  "EDIF_TOK_OFFPAGECONNECTOR", "EDIF_TOK_OFFSETEVENT",
  "EDIF_TOK_OPENSHAPE", "EDIF_TOK_ORIENTATION", "EDIF_TOK_ORIGIN",
  "EDIF_TOK_OVERHANGDISTANCE", "EDIF_TOK_OVERLAPDISTANCE",
  "EDIF_TOK_OVERSIZE", "EDIF_TOK_OWNER", "EDIF_TOK_PAGE",
  "EDIF_TOK_PAGESIZE", "EDIF_TOK_PARAMETER", "EDIF_TOK_PARAMETERASSIGN",
  "EDIF_TOK_PARAMETERDISPLAY", "EDIF_TOK_PATH", "EDIF_TOK_PATHDELAY",
  "EDIF_TOK_PATHWIDTH", "EDIF_TOK_PERMUTABLE",
  "EDIF_TOK_PHYSICALDESIGNRULE", "EDIF_TOK_PLUG", "EDIF_TOK_POINT",
  "EDIF_TOK_POINTDISPLAY", "EDIF_TOK_POINTLIST", "EDIF_TOK_POLYGON",
  "EDIF_TOK_PORT", "EDIF_TOK_PORTBACKANNOTATE", "EDIF_TOK_PORTBUNDLE",
  "EDIF_TOK_PORTDELAY", "EDIF_TOK_PORTGROUP",
  "EDIF_TOK_PORTIMPLEMENTATION", "EDIF_TOK_PORTINSTANCE",
  "EDIF_TOK_PORTLIST", "EDIF_TOK_PORTLISTALIAS", "EDIF_TOK_PORTMAP",
  "EDIF_TOK_PORTREF", "EDIF_TOK_PROGRAM", "EDIF_TOK_PROPERTY",
  "EDIF_TOK_PROPERTYDISPLAY", "EDIF_TOK_PROTECTIONFRAME", "EDIF_TOK_PT",
  "EDIF_TOK_RANGEVECTOR", "EDIF_TOK_RECTANGLE", "EDIF_TOK_RECTANGLESIZE",
  "EDIF_TOK_RENAME", "EDIF_TOK_RESOLVES", "EDIF_TOK_SCALE",
  "EDIF_TOK_SCALEX", "EDIF_TOK_SCALEY", "EDIF_TOK_SECTION",
  "EDIF_TOK_SHAPE", "EDIF_TOK_SIMULATE", "EDIF_TOK_SIMULATIONINFO",
  "EDIF_TOK_SINGLEVALUESET", "EDIF_TOK_SITE", "EDIF_TOK_SOCKET",
  "EDIF_TOK_SOCKETSET", "EDIF_TOK_STATUS", "EDIF_TOK_STEADY",
  "EDIF_TOK_STRING", "EDIF_TOK_STRINGDISPLAY", "EDIF_TOK_STRONG",
  "EDIF_TOK_SYMBOL", "EDIF_TOK_SYMMETRY", "EDIF_TOK_TABLE",
  "EDIF_TOK_TABLEDEFAULT", "EDIF_TOK_TECHNOLOGY", "EDIF_TOK_TEXTHEIGHT",
  "EDIF_TOK_TIMEINTERVAL", "EDIF_TOK_TIMESTAMP", "EDIF_TOK_TIMING",
  "EDIF_TOK_TRANSFORM", "EDIF_TOK_TRANSITION", "EDIF_TOK_TRIGGER",
  "EDIF_TOK_TRUE", "EDIF_TOK_UNCONSTRAINED", "EDIF_TOK_UNDEFINED",
  "EDIF_TOK_UNION", "EDIF_TOK_UNIT", "EDIF_TOK_UNUSED",
  "EDIF_TOK_USERDATA", "EDIF_TOK_VERSION", "EDIF_TOK_VIEW",
  "EDIF_TOK_VIEWLIST", "EDIF_TOK_VIEWMAP", "EDIF_TOK_VIEWREF",
  "EDIF_TOK_VIEWTYPE", "EDIF_TOK_VISIBLE", "EDIF_TOK_VOLTAGEMAP",
  "EDIF_TOK_WAVEVALUE", "EDIF_TOK_WEAK", "EDIF_TOK_WEAKJOINED",
  "EDIF_TOK_WHEN", "EDIF_TOK_WRITTEN", "')'", "$accept", "PopC", "Edif",
  "_Edif", "EdifFileName", "EdifLevel", "EdifVersion", "AcLoad", "_AcLoad",
  "After", "_After", "Annotate", "_Annotate", "Apply", "_Apply", "Arc",
  "Array", "_Array", "ArrayMacro", "ArrayRelInfo", "_ArrayRelInfo",
  "ArraySite", "AtLeast", "AtMost", "Author", "BaseArray", "Becomes",
  "_Becomes", "Between", "__Between", "_Between", "Boolean", "_Boolean",
  "BooleanDisp", "_BooleanDisp", "BooleanMap", "BooleanValue", "BorderPat",
  "BorderWidth", "BoundBox", "Cell", "_Cell", "CellNameDef", "CellRef",
  "_CellRef", "CellNameRef", "CellType", "_CellType", "Change", "__Change",
  "_Change", "Circle", "_Circle", "Color", "Comment", "_Comment",
  "CommGraph", "_CommGraph", "Compound", "Contents", "_Contents",
  "ConnectLoc", "_ConnectLoc", "CornerType", "_CornerType", "Criticality",
  "_Criticality", "CurrentMap", "Curve", "_Curve", "Cycle", "_Cycle",
  "DataOrigin", "_DataOrigin", "DcFanInLoad", "_DcFanInLoad",
  "DcFanOutLoad", "_DcFanOutLoad", "DcMaxFanIn", "_DcMaxFanIn",
  "DcMaxFanOut", "_DcMaxFanOut", "Delay", "_Delay", "Delta", "_Delta",
  "Derivation", "_Derivation", "Design", "_Design", "Designator",
  "_Designator", "DesignNameDef", "DesignRule", "_DesignRule",
  "Difference", "_Difference", "Direction", "_Direction", "Display",
  "_Display", "_DisplayJust", "_DisplayOrien", "_DisplayOrg", "Dominates",
  "_Dominates", "Dot", "_Dot", "Duration", "EncloseDist", "_EncloseDist",
  "EndType", "_EndType", "Entry", "___Entry", "__Entry", "_Entry", "Event",
  "_Event", "Exactly", "External", "_External", "Fabricate", "False",
  "FigGrp", "_FigGrp", "FigGrpNameDef", "FigGrpNameRef", "FigGrpObj",
  "_FigGrpObj", "FigGrpOver", "_FigGrpOver", "FigGrpRef", "_FigGrpRef",
  "Figure", "_Figure", "FigureArea", "_FigureArea", "FigureOp",
  "FigurePerim", "_FigurePerim", "FigureWidth", "_FigureWidth",
  "FillPattern", "Follow", "__Follow", "_Follow", "Forbidden",
  "_Forbidden", "Form", "_Form", "GlobPortRef", "GreaterThan", "GridMap",
  "Ignore", "IncFigGrp", "_IncFigGrp", "Initial", "Instance", "_Instance",
  "InstanceRef", "_InstanceRef", "InstBackAn", "_InstBackAn", "InstGroup",
  "_InstGroup", "InstMap", "_InstMap", "InstNameDef", "InstNameRef",
  "IntDisplay", "_IntDisplay", "Integer", "_Integer", "Interface",
  "_Interface", "InterFigGrp", "_InterFigGrp", "Intersection",
  "_Intersection", "IntraFigGrp", "_IntraFigGrp", "Inverse", "_Inverse",
  "Isolated", "Joined", "_Joined", "Justify", "_Justify", "KeywordDisp",
  "_KeywordDisp", "KeywordLevel", "KeywordMap", "_KeywordMap",
  "KeywordName", "LayerNameDef", "LessThan", "LibNameDef", "LibNameRef",
  "Library", "_Library", "LibraryRef", "ListOfNets", "_ListOfNets",
  "ListOfPorts", "_ListOfPorts", "LoadDelay", "_LoadDelay", "LogicAssn",
  "___LogicAssn", "__LogicAssn", "_LogicAssn", "LogicIn", "_LogicIn",
  "LogicList", "_LogicList", "LogicMapIn", "_LogicMapIn", "LogicMapOut",
  "_LogicMapOut", "LogicNameDef", "LogicNameRef", "LogicOneOf",
  "_LogicOneOf", "LogicOut", "_LogicOut", "LogicPort", "_LogicPort",
  "LogicRef", "_LogicRef", "LogicValue", "_LogicValue", "LogicWave",
  "_LogicWave", "Maintain", "__Maintain", "_Maintain", "Match", "__Match",
  "_Match", "Member", "_Member", "MiNoMa", "_MiNoMa", "MiNoMaDisp",
  "_MiNoMaDisp", "MiNoMaValue", "Mnm", "_Mnm", "MultValSet", "_MultValSet",
  "MustJoin", "_MustJoin", "Name", "_Name", "NameDef", "NameRef", "Net",
  "_Net", "NetBackAn", "_NetBackAn", "NetBundle", "_NetBundle", "NetDelay",
  "_NetDelay", "NetGroup", "_NetGroup", "NetMap", "_NetMap", "NetNameDef",
  "NetNameRef", "NetRef", "_NetRef", "NoChange", "NonPermut", "_NonPermut",
  "NotAllowed", "_NotAllowed", "NotchSpace", "_NotchSpace", "Number",
  "_Number", "NumbDisplay", "_NumbDisplay", "NumberDefn", "_NumberDefn",
  "OffPageConn", "_OffPageConn", "OffsetEvent", "OpenShape", "_OpenShape",
  "Orientation", "_Orientation", "Origin", "OverhngDist", "_OverhngDist",
  "OverlapDist", "_OverlapDist", "Oversize", "_Oversize", "Owner", "Page",
  "_Page", "PageSize", "ParamDisp", "_ParamDisp", "Parameter",
  "_Parameter", "ParamAssign", "Path", "_Path", "PathDelay", "_PathDelay",
  "PathWidth", "Permutable", "_Permutable", "Plug", "_Plug", "Point",
  "_Point", "PointDisp", "_PointDisp", "PointList", "_PointList",
  "PointValue", "Polygon", "_Polygon", "Port", "_Port", "PortBackAn",
  "_PortBackAn", "PortBundle", "_PortBundle", "PortDelay", "_PortDelay",
  "PortGroup", "_PortGroup", "PortImpl", "_PortImpl", "PortInst",
  "_PortInst", "PortList", "_PortList", "PortListAls", "PortMap",
  "_PortMap", "PortNameDef", "PortNameRef", "PortRef", "_PortRef",
  "Program", "_Program", "PropDisplay", "_PropDisplay", "Property",
  "_Property", "PropNameDef", "PropNameRef", "ProtectFrame",
  "_ProtectFrame", "Range", "RangeVector", "_RangeVector", "Rectangle",
  "_Rectangle", "RectSize", "_RectSize", "Rename", "__Rename", "_Rename",
  "Resolves", "_Resolves", "RuleNameDef", "Scale", "ScaledInt", "ScaleX",
  "ScaleY", "Section", "_Section", "Shape", "_Shape", "SimNameDef",
  "Simulate", "_Simulate", "SimulInfo", "_SimulInfo", "SingleValSet",
  "_SingleValSet", "Site", "_Site", "Socket", "_Socket", "SocketSet",
  "_SocketSet", "Status", "_Status", "Steady", "__Steady", "_Steady",
  "StrDisplay", "String", "_String", "_StrDisplay", "Strong", "Symbol",
  "_Symbol", "Symmetry", "_Symmetry", "Table", "_Table", "TableDeflt",
  "__TableDeflt", "_TableDeflt", "Technology", "_Technology", "TextHeight",
  "TimeIntval", "__TimeIntval", "_TimeIntval", "TimeStamp", "Timing",
  "_Timing", "Transform", "_TransX", "_TransY", "_TransDelta",
  "_TransOrien", "_TransOrg", "Transition", "_Transition", "Trigger",
  "_Trigger", "True", "TypedValue", "Unconstrained", "Undefined", "Union",
  "_Union", "Unit", "_Unit", "Unused", "UserData", "_UserData",
  "ValueNameDef", "ValueNameRef", "Version", "View", "_View", "ViewList",
  "_ViewList", "ViewMap", "_ViewMap", "ViewNameDef", "ViewNameRef",
  "ViewRef", "_ViewRef", "ViewType", "_ViewType", "Visible", "VoltageMap",
  "WaveValue", "Weak", "WeakJoined", "_WeakJoined", "When", "_When",
  "Written", "_Written", "Ident", "Str", "Int", "Keyword", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   296,   297,   298,   299,   299,   299,   299,   299,   299,
     299,   300,   301,   302,   303,   304,   304,   305,   306,   306,
     306,   306,   306,   306,   307,   308,   308,   309,   310,   310,
     310,   310,   310,   311,   312,   313,   313,   314,   315,   316,
     316,   316,   316,   316,   317,   318,   319,   320,   321,   322,
     323,   323,   323,   324,   325,   325,   326,   326,   327,   328,
     328,   328,   328,   329,   330,   330,   331,   332,   332,   333,
     334,   335,   336,   337,   337,   337,   337,   337,   337,   337,
     338,   339,   340,   340,   341,   342,   343,   343,   343,   344,
     345,   345,   345,   346,   346,   346,   347,   348,   348,   349,
     350,   351,   351,   352,   353,   353,   353,   353,   353,   353,
     353,   353,   354,   355,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   357,   358,   358,   359,   360,   360,   360,   361,
     362,   362,   363,   364,   365,   365,   365,   366,   367,   367,
     368,   369,   369,   370,   371,   371,   372,   373,   373,   374,
     375,   375,   376,   377,   377,   378,   379,   379,   380,   381,
     381,   382,   383,   383,   383,   384,   385,   385,   385,   385,
     385,   386,   387,   387,   388,   389,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   391,   392,   392,   392,   392,   393,   394,   394,   394,
     395,   396,   396,   397,   397,   398,   398,   399,   399,   400,
     401,   401,   402,   403,   403,   404,   405,   406,   406,   406,
     406,   407,   408,   408,   408,   409,   410,   410,   410,   411,
     411,   411,   411,   412,   412,   412,   413,   414,   414,   414,
     414,   414,   414,   414,   415,   416,   417,   417,   417,   417,
     417,   418,   419,   420,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   422,   423,
     424,   425,   425,   425,   426,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   428,   429,
     429,   430,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   432,   433,   433,   433,   433,   434,   434,
     434,   434,   434,   435,   436,   436,   436,   436,   437,   438,
     438,   438,   438,   439,   440,   441,   441,   442,   442,   442,
     442,   443,   444,   444,   445,   446,   446,   446,   446,   446,
     447,   448,   449,   450,   451,   452,   452,   453,   454,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   456,
     457,   457,   457,   458,   459,   459,   459,   459,   459,   460,
     461,   461,   462,   463,   463,   463,   463,   463,   464,   464,
     465,   465,   466,   467,   467,   468,   469,   469,   469,   469,
     470,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   472,   473,
     473,   473,   473,   474,   475,   475,   475,   475,   476,   477,
     477,   477,   477,   478,   479,   479,   480,   481,   482,   482,
     482,   482,   483,   484,   484,   484,   484,   484,   484,   484,
     484,   484,   485,   486,   486,   487,   488,   489,   489,   490,
     491,   492,   493,   494,   495,   496,   496,   496,   496,   496,
     497,   498,   499,   499,   500,   501,   501,   501,   502,   503,
     503,   504,   505,   505,   506,   506,   506,   507,   507,   507,
     508,   509,   509,   509,   509,   510,   511,   511,   511,   511,
     512,   513,   513,   514,   515,   515,   516,   517,   518,   519,
     519,   519,   520,   521,   521,   521,   521,   522,   523,   523,
     523,   523,   524,   525,   525,   526,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   528,   529,   529,   529,   529,   529,   530,   531,   531,
     532,   532,   532,   533,   534,   534,   534,   535,   535,   535,
     536,   537,   537,   538,   539,   539,   539,   539,   540,   541,
     541,   542,   542,   543,   544,   544,   544,   545,   546,   546,
     547,   548,   548,   548,   548,   548,   549,   550,   550,   551,
     551,   551,   552,   552,   553,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   555,   556,   556,   556,   556,
     556,   557,   558,   558,   558,   558,   558,   558,   559,   560,
     560,   560,   561,   562,   562,   562,   563,   564,   564,   564,
     564,   564,   565,   565,   566,   566,   567,   568,   568,   568,
     568,   569,   570,   571,   571,   571,   572,   573,   573,   573,
     574,   575,   575,   575,   575,   576,   577,   577,   577,   577,
     578,   579,   579,   580,   581,   581,   581,   581,   582,   583,
     583,   583,   583,   583,   584,   585,   586,   586,   587,   588,
     588,   588,   588,   588,   588,   588,   588,   589,   590,   591,
     591,   591,   591,   592,   593,   593,   593,   593,   594,   595,
     595,   596,   597,   598,   598,   598,   598,   598,   598,   598,
     598,   598,   598,   599,   600,   601,   601,   602,   603,   603,
     604,   605,   606,   606,   607,   608,   608,   609,   610,   611,
     611,   611,   611,   612,   613,   613,   614,   615,   615,   615,
     615,   616,   617,   617,   618,   619,   619,   620,   621,   622,
     622,   623,   624,   624,   624,   624,   624,   624,   624,   624,
     624,   624,   624,   624,   624,   625,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   627,   628,   628,   628,
     628,   629,   630,   630,   630,   630,   631,   632,   632,   632,
     633,   634,   634,   634,   634,   634,   634,   634,   634,   634,
     634,   634,   635,   636,   636,   636,   636,   636,   636,   636,
     636,   636,   636,   636,   636,   636,   637,   638,   638,   638,
     639,   640,   641,   641,   641,   641,   641,   642,   642,   643,
     643,   644,   645,   645,   645,   645,   646,   647,   647,   648,
     649,   649,   650,   651,   651,   651,   651,   651,   652,   653,
     654,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   656,   656,   656,   656,   656,   656,   657,
     658,   658,   658,   659,   660,   660,   661,   662,   662,   662,
     662,   663,   664,   664,   665,   665,   666,   667,   667,   668,
     669,   670,   670,   671,   672,   673,   674,   674,   674,   674,
     675,   676,   676,   677,   678,   679,   679,   679,   679,   679,
     679,   680,   681,   681,   681,   681,   682,   683,   683,   684,
     685,   685,   686,   687,   687,   688,   689,   689,   690,   691,
     691,   691,   691,   692,   693,   693,   693,   694,   694,   694,
     695,   696,   697,   697,   697,   697,   698,   698,   699,   700,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   702,   703,   703,   704,   705,   705,
     705,   706,   707,   707,   707,   707,   708,   708,   708,   709,
     710,   710,   710,   710,   710,   710,   710,   711,   712,   713,
     713,   714,   714,   714,   715,   716,   717,   717,   717,   717,
     717,   718,   719,   719,   720,   720,   721,   721,   722,   722,
     723,   723,   724,   725,   725,   725,   726,   727,   727,   727,
     727,   728,   729,   729,   729,   729,   729,   729,   730,   731,
     732,   733,   733,   733,   733,   734,   735,   735,   735,   735,
     735,   735,   735,   735,   735,   735,   735,   735,   735,   735,
     735,   735,   736,   737,   738,   738,   738,   738,   738,   739,
     739,   740,   740,   741,   742,   743,   743,   743,   743,   743,
     743,   744,   745,   745,   745,   746,   747,   747,   747,   747,
     747,   747,   747,   747,   747,   748,   749,   750,   751,   751,
     752,   753,   753,   753,   753,   753,   753,   753,   753,   753,
     753,   754,   755,   756,   757,   758,   759,   759,   759,   759,
     760,   761,   761,   761,   761,   761,   761,   761,   762,   763,
     763,   763,   763,   763,   763,   763,   764,   765,   766,   767
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     0,     2,     2,     2,     2,     2,
       2,     1,     3,     5,     3,     1,     1,     3,     1,     2,
       2,     2,     2,     2,     3,     1,     1,     3,     1,     2,
       2,     2,     2,     5,     5,     0,     1,     3,     3,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     4,     1,     1,     1,     1,     3,     0,
       2,     2,     2,     3,     1,     2,     3,     1,     1,     5,
       3,     3,     4,     1,     2,     2,     2,     2,     2,     2,
       1,     4,     0,     1,     1,     3,     1,     1,     1,     4,
       1,     1,     1,     0,     1,     1,     5,     0,     2,     5,
       3,     0,     2,     3,     0,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     0,     1,     3,     1,     1,     1,     3,
       1,     1,     3,     3,     0,     2,     2,     4,     0,     1,
       4,     0,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     0,
       2,     3,     1,     1,     1,     4,     1,     2,     2,     2,
       2,     3,     1,     1,     1,     3,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     1,     1,     2,     2,     3,     1,     1,     1,
       6,     1,     1,     0,     1,     0,     1,     0,     1,     3,
       0,     2,     3,     1,     2,     3,     6,     1,     1,     2,
       2,     3,     1,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     2,     3,     5,     1,     2,     2,     2,
       2,     4,     2,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     0,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     5,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     5,     1,     1,     2,     2,     5,     1,
       1,     2,     2,     5,     4,     1,     1,     1,     1,     2,
       2,     3,     1,     2,     3,     0,     2,     2,     2,     2,
       3,     3,     4,     2,     3,     1,     1,     2,     4,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       0,     1,     1,     3,     1,     2,     2,     2,     2,     3,
       0,     2,     3,     0,     2,     2,     2,     2,     1,     1,
       1,     1,     3,     1,     2,     3,     0,     2,     2,     2,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     6,     1,
       1,     2,     2,     3,     1,     1,     2,     2,     5,     1,
       1,     2,     2,     3,     1,     1,     2,     3,     0,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     3,     1,     2,     1,
       1,     3,     1,     1,     5,     1,     2,     2,     2,     2,
       3,     3,     0,     2,     3,     0,     2,     2,     4,     1,
       1,     5,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     1,     1,     1,     2,     3,     0,     2,     2,     2,
       3,     0,     2,     3,     0,     2,     1,     1,     3,     0,
       2,     2,     3,     1,     1,     1,     2,     3,     1,     2,
       2,     2,     4,     0,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     0,     2,     2,     2,     2,     4,     1,     1,
       0,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       4,     1,     2,     3,     0,     2,     2,     2,     3,     1,
       2,     1,     1,     5,     1,     1,     1,     3,     0,     2,
       3,     0,     2,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     2,     2,
       2,     4,     1,     2,     2,     2,     2,     2,     4,     1,
       2,     2,     3,     0,     2,     2,     3,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     4,     0,     1,     1,
       1,     2,     3,     0,     2,     2,     4,     1,     2,     2,
       5,     1,     1,     2,     2,     3,     0,     2,     2,     2,
       3,     1,     2,     3,     0,     2,     2,     2,     3,     1,
       2,     2,     2,     2,     4,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     1,
       1,     2,     2,     6,     1,     1,     2,     2,     5,     1,
       1,     3,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     1,     2,     5,     0,     1,
       4,     3,     1,     2,     3,     1,     2,     3,     3,     0,
       2,     2,     2,     3,     0,     2,     3,     0,     2,     2,
       2,     3,     1,     2,     3,     0,     2,     4,     3,     1,
       2,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     1,     2,     2,
       2,     4,     1,     1,     2,     2,     3,     0,     2,     2,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     0,     2,     2,
       4,     3,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     4,     0,     1,     1,     1,     4,     0,     1,     3,
       1,     2,     4,     1,     2,     2,     2,     2,     1,     1,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       0,     2,     2,     4,     1,     2,     5,     1,     1,     2,
       2,     4,     1,     1,     1,     1,     3,     0,     2,     1,
       5,     1,     4,     4,     4,     3,     1,     2,     2,     2,
       3,     1,     2,     1,     3,     1,     2,     2,     2,     2,
       2,     3,     0,     2,     2,     2,     3,     0,     1,     4,
       0,     1,     3,     0,     1,     3,     1,     2,     3,     0,
       2,     2,     2,     4,     1,     1,     1,     1,     2,     2,
       3,     3,     0,     2,     2,     2,     1,     2,     3,     3,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     0,     2,     3,     0,     2,
       2,     4,     1,     1,     1,     1,     0,     1,     1,     3,
       1,     2,     2,     2,     2,     2,     2,     3,     4,     1,
       1,     1,     1,     1,     8,     3,     1,     2,     2,     2,
       2,     7,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     4,     1,     1,     1,     3,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     3,     5,     1,     2,     2,     2,     2,
       2,     3,     0,     2,     2,     3,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     4,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     3,     3,     0,     2,     2,     2,
       3,     1,     2,     2,     2,     2,     2,     2,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,  1126,     0,     0,     0,   590,    11,   591,
     589,     1,     0,   587,   883,     0,   882,     0,     0,     0,
       2,   586,   588,  1127,     0,     0,   885,   884,  1128,     0,
       0,     0,     0,   213,   211,   212,   593,   279,   592,     0,
     946,   881,     0,     0,     0,     4,   285,     0,     0,   215,
     214,   940,   947,     0,    12,     0,   457,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   292,   289,   290,   295,   286,   287,   291,   288,
     296,   293,   297,   294,   443,   444,   445,   446,   447,   448,
     449,   450,   451,     0,     0,   217,   216,    13,     0,   456,
     458,     0,     0,     0,   929,     3,     9,     8,     6,     7,
       5,    10,     0,     0,     0,     0,   891,     0,   136,   137,
     138,     0,   232,   233,   234,     0,     0,     0,   848,     0,
       0,     0,  1054,     0,     0,     0,    68,    67,   442,   683,
     686,   684,   685,   679,   681,   682,   680,     0,     0,     0,
     218,   455,     0,   184,     0,   462,     0,     0,     0,    70,
       0,     0,   100,   102,   135,   231,     0,   727,    59,   396,
     564,   656,   737,   942,  1022,  1023,  1024,  1025,  1026,     0,
    1027,   843,   987,  1129,  1053,  1058,  1057,  1056,  1055,   345,
     262,  1021,  1101,   678,     0,     0,   210,     0,   176,     0,
       0,     0,     0,   928,   931,   932,   930,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   842,
     847,   844,   846,   845,     0,     0,   687,    82,    84,   175,
     178,   179,   177,   180,     0,     0,   256,     0,   465,     0,
    1119,     0,    69,   892,    99,   333,     0,    58,    62,    61,
      60,     0,   395,   398,   399,   397,     0,     0,   563,   567,
     566,   565,   571,   572,     0,   655,   659,   658,   657,     0,
     736,   740,   739,   738,   941,   944,   945,   943,     0,  1051,
    1037,  1048,  1049,  1038,  1036,  1046,  1050,  1044,  1045,  1043,
    1047,  1039,  1040,  1041,  1042,     0,   344,   349,   348,   347,
     346,     0,     0,     0,    83,   664,   980,     0,     0,   255,
     258,   259,   257,   260,   464,   467,   468,   466,   469,     0,
       0,     0,     0,  1118,  1120,  1124,  1122,  1121,  1123,  1125,
       0,    64,     0,   393,     0,   569,     0,     0,     0,   574,
     576,   575,     0,   661,     0,   742,   701,  1035,   747,     0,
     463,    81,     0,     0,     0,   186,   912,   979,   985,   984,
     982,   981,   983,   986,     0,    80,     0,     0,   151,   837,
      63,    65,   392,   394,   568,   570,  1028,  1029,     0,   660,
     662,   741,   743,   470,     0,     0,   663,   667,   666,   665,
       0,   460,     0,   264,   278,     0,     0,     0,     0,    73,
       0,    47,     0,     0,   152,     0,   838,     0,     0,     0,
       0,     0,   263,   271,   268,   269,   274,   265,   266,   270,
     277,   267,   275,   272,   276,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,   199,   193,
     198,   188,   190,   187,   194,   195,   197,   196,   192,   191,
     189,   200,     0,   911,   914,   913,   915,    88,    87,    86,
       0,     0,  1076,    72,    77,    79,    74,    78,    76,    75,
       0,     0,   150,   836,   573,     0,     0,   261,     0,     0,
       0,     0,     0,     0,   320,   355,   356,     0,   318,   321,
     322,   319,   889,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,     0,   506,    85,  1085,     0,
       0,     0,  1063,   352,     0,     0,   202,   203,   299,   424,
     425,     0,   434,   435,     0,     0,  1031,  1032,     0,   354,
       0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
       0,     0,     0,     0,     0,     0,   220,     0,   501,   504,
     887,     0,     0,     0,   525,   529,   539,   530,   528,   533,
     536,   535,   534,   538,   537,   532,   540,   527,   531,     0,
       0,     0,   383,     0,   627,     0,   822,  1075,  1083,  1080,
    1079,  1082,  1081,  1078,  1077,  1084,     0,   890,   201,   204,
     205,     0,   300,   423,   426,   427,   433,   699,   700,     0,
    1030,  1033,  1034,   281,     0,   282,   283,     0,     0,     0,
       0,     0,     0,     0,   917,   866,   865,   868,   867,     0,
     864,   863,   314,   315,     0,   324,   325,     0,   329,   330,
       0,     0,   429,   430,   646,   648,   649,     0,   651,   652,
       0,     0,   578,   870,   878,   877,     0,     0,     0,   507,
       0,     0,   436,     0,     0,     0,     0,     0,     0,  1096,
    1098,  1099,  1097,  1091,  1093,  1092,  1094,  1100,  1095,     0,
     401,  1065,     0,     0,   374,     0,     0,     0,     0,   606,
       0,     0,     0,   766,     0,   994,   298,     0,   280,     0,
     227,   228,     0,     0,    54,     0,    55,     0,     0,     0,
     918,     0,   313,   316,   317,   323,   326,   327,   328,   331,
     332,     0,   419,   420,   428,   431,   432,   650,   653,   654,
       0,   689,   690,     0,   694,   695,     0,     0,   876,   879,
     880,    66,   112,   142,   219,   221,   500,   502,   503,   505,
     886,   888,   948,  1102,  1104,  1090,     0,   114,  1064,  1068,
    1067,  1069,  1066,  1070,     0,   370,   391,   390,     0,     0,
     373,   378,   375,   377,   376,   380,   382,   386,   384,   385,
     387,   635,   634,   637,     0,     0,   605,   610,   608,   607,
     609,   623,   626,   630,   629,   628,   631,   830,   829,   832,
       0,     0,     0,     0,     0,     0,   765,   773,   775,   769,
     770,   771,   772,   767,   768,   774,   787,   821,   825,   824,
     823,   826,   698,   226,   229,   230,    45,    46,    56,     0,
      57,   254,   351,   461,   916,   418,   421,   422,   688,   691,
     692,   693,   696,   697,   577,   579,   869,   871,   872,     0,
     438,   581,     0,   729,     0,     0,   851,     0,   950,  1106,
     400,   406,   416,   414,   408,   409,   407,   411,   402,   403,
     415,   405,   413,   404,   412,   417,   410,     0,     0,     0,
     371,     0,   372,     0,   183,   182,     0,   996,     0,     0,
     639,   638,     0,   640,     0,   141,   140,     0,     0,   834,
     833,     0,   835,     0,    16,    15,     0,   155,   154,     0,
     158,   157,     0,   161,   160,     0,   164,   163,     0,     0,
      53,     0,     0,     0,    41,     0,    40,    39,     0,     0,
       0,  1060,  1059,     0,     0,   828,   827,     0,   752,     0,
       0,   903,   905,     0,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
     129,   130,   122,   117,   127,   115,   128,   119,   120,   116,
     121,   123,   118,   125,   124,   131,   126,     0,   561,  1086,
    1088,   369,   181,   172,   173,   174,     0,     0,     0,   995,
     999,   998,   997,  1000,   379,   381,   636,   139,     0,   619,
       0,   622,   624,   625,   831,    14,   153,   156,   159,   162,
       0,   782,   783,     0,   786,   788,   789,   734,     0,   923,
       0,    48,    38,    42,    43,     0,   817,   437,   441,   440,
     439,   580,   585,   583,   582,   584,     0,   718,   643,   728,
     732,   731,   730,     0,     0,   751,   761,   763,   757,   758,
     759,   760,   756,   753,   755,   762,   754,   764,   475,   777,
       0,     0,     0,     0,   850,   856,   861,   855,   853,   854,
     858,   859,   852,   857,   860,   862,     0,     0,     0,   904,
     908,   909,   906,   910,   907,     0,     0,   949,   955,   957,
     962,   954,   952,   953,   959,   956,   960,   951,   958,   961,
     963,  1105,  1109,  1108,  1107,     0,     0,     0,   302,   303,
       0,     0,   335,   336,   389,     0,   388,     0,   518,   633,
     632,     0,     0,     0,   669,   703,     0,     0,   792,   791,
       0,   896,  1017,  1111,     0,   560,   562,  1089,     0,   171,
       0,     0,   342,   725,     0,     0,   167,   166,     0,     0,
     618,   621,   620,     0,   480,   479,   781,   785,   784,     0,
      37,   965,     0,   924,    44,     0,     0,    35,     0,   719,
       0,   207,   208,   209,     0,  1052,     0,   776,   779,   778,
     780,     0,   453,   459,  1062,  1061,     0,   715,   849,     0,
     840,     0,     0,    28,     0,     0,     0,    26,    25,     0,
       0,    71,   103,   105,   108,   110,   106,   107,   109,   111,
       0,     0,     0,     0,     0,     0,   301,   304,   311,   305,
     306,   307,   308,   309,   310,   312,   968,     0,   337,   338,
    1072,     0,   360,   359,   517,   520,   519,   521,   595,     0,
     472,   612,     0,   668,   672,   671,   670,   673,   702,   710,
     711,   707,   704,   705,   706,   709,   708,   712,   133,   790,
     801,   796,   793,   794,   795,   798,   797,   799,   800,   895,
     899,   897,   898,     0,     0,     0,     0,  1110,  1112,  1116,
    1113,  1115,  1114,  1117,  1087,     0,     0,   989,   990,     0,
     341,   343,   724,   726,   165,   496,   509,     0,    51,    50,
      52,  1014,  1013,  1015,     0,     0,     0,   733,   735,     0,
     922,   350,   816,   819,   818,     0,    36,   717,   642,   645,
     644,   206,   474,   476,   477,   452,   454,   714,   716,   839,
     841,   148,     0,     0,    27,    31,    29,    30,    32,     0,
       0,    24,   713,   874,     0,     0,     0,   223,   144,   676,
       0,   745,     0,   722,   749,     0,   901,     0,     0,   334,
     339,   340,     0,     0,     0,  1002,   358,   367,   365,   362,
     363,   366,   364,   361,   368,   594,   603,   601,   596,   598,
     600,   599,   597,   602,   604,     0,   611,   616,   614,   613,
     615,   617,     0,   134,     0,     0,     0,  1016,  1018,  1020,
    1019,     0,    18,     0,   482,   483,   550,   548,   549,     0,
     251,   250,   249,   248,   247,     0,     0,   993,   991,   992,
       0,     0,     0,    49,     0,   478,     0,   926,   964,   966,
      34,     0,   149,     0,   491,   493,   492,     0,   513,   515,
     514,   820,   542,     0,   873,   875,    97,   222,   224,     0,
     675,   677,     0,   721,   723,   748,   750,   900,   902,     0,
       0,   967,   969,   970,  1071,  1074,  1073,     0,     0,   804,
     803,     0,  1003,  1004,   471,   473,   132,    93,    92,    90,
      91,   357,   936,   934,   935,     0,    17,    22,    19,    21,
      20,    23,     0,   487,   485,   484,   486,   551,   552,     0,
     246,   253,   252,     0,     0,   988,     0,   495,   499,   497,
     498,   508,   511,   510,  1012,     0,   925,   927,   147,   490,
     494,   512,   516,     0,  1103,     0,     0,   143,   145,   146,
     744,   746,     0,   237,     0,   236,   238,     0,   972,   974,
     973,   975,   976,     0,   802,   812,   814,   808,   809,   810,
     811,   807,   806,   813,   805,   815,     0,     0,  1005,  1006,
      94,     0,    95,   937,     0,   523,   488,   489,     0,   547,
     674,   225,   353,   920,   541,   546,   544,   543,   545,    96,
      98,     0,     0,   556,   554,   555,   243,   239,   241,   240,
     242,   641,   977,   978,     0,   720,     0,     0,   169,  1007,
    1008,    89,   933,   939,   938,   524,     0,   481,     0,   921,
       0,   558,   557,   559,     0,   244,     0,   245,   971,   893,
       0,     0,  1009,  1010,   522,   919,     0,   553,   235,   894,
     168,   170,  1011,     0,    33,  1001
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,     2,    58,     6,    31,    18,   797,   893,  1268,
    1391,  1078,  1186,  1070,  1182,  1518,   925,  1305,   914,   851,
     915,   916,   615,   616,   324,   917,  1141,  1287,   617,   695,
     819,   174,   211,   249,   330,   555,   135,    72,    73,   950,
     310,   398,   364,   198,   303,   227,   399,   460,  1388,  1467,
    1551,  1207,  1515,    74,    75,   117,   952,  1097,   557,   750,
     867,  1252,  1382,    76,   121,   778,   884,   558,  1339,  1439,
    1183,  1421,   326,   403,   799,   896,   800,   899,   801,   902,
     802,   905,   989,  1135,  1589,  1611,   877,   976,   107,   199,
     762,   873,   152,   359,   395,   484,   515,  1043,  1164,    22,
      33,    49,    95,   149,   559,   651,  1209,  1336,  1407,   439,
     689,    77,   125,  1452,  1524,  1576,  1606,  1277,  1399,   618,
     108,   235,   360,   136,   361,   392,   393,    34,   531,   604,
      35,    47,   485,   591,   953,  1100,   441,   619,   486,   442,
     624,   443,   627,    78,   954,  1101,  1217,   981,  1131,   185,
     224,  1018,   620,   388,  1498,   420,   487,  1389,   955,  1221,
     674,   871,   579,   675,   769,   879,   580,   676,  1105,   755,
     253,   332,   175,   212,   671,   746,   444,   711,   488,   521,
     445,   631,   489,   524,   560,   854,   918,    50,    93,  1060,
    1171,    56,    45,    57,  1172,   390,   621,   154,   349,   109,
     237,   304,  1231,  1375,  1049,  1166,  1002,  1143,  1271,  1393,
    1483,  1558,  1326,  1423,  1291,  1411,   561,   653,   562,   654,
     504,  1292,  1293,  1412,  1327,  1427,   956,  1107,  1484,  1596,
     455,   505,  1433,  1513,  1272,  1396,  1489,  1525,  1572,  1604,
     787,   967,   176,   213,  1144,   334,  1145,   262,   338,   644,
     726,   855,   919,    36,    12,   492,   649,   957,  1229,   581,
     678,   958,  1232,   779,   990,   784,   888,   582,   680,  1111,
     773,   679,   882,  1529,  1030,  1160,   446,   538,   447,   637,
     177,   214,   267,   342,   306,   352,   959,  1113,  1278,  1210,
    1340,    96,   147,   150,   448,   720,   449,   723,   490,   599,
     221,   960,  1116,  1085,  1061,  1176,   856,  1158,  1359,  1211,
    1342,   982,  1134,    79,   857,   924,  1008,  1149,   178,   215,
     272,   344,  1343,  1442,   195,  1212,  1345,   858,   927,   583,
     682,   859,  1050,   804,  1003,   809,   909,   961,  1117,  1360,
    1458,  1019,  1156,  1072,   584,   684,   928,   789,   683,   891,
     327,   405,  1063,  1179,    80,   179,   129,  1180,   861,   930,
     622,   645,   727,  1096,  1334,   450,   646,     9,    15,    25,
     564,   655,   493,   389,   263,  1462,  1548,   962,  1120,  1214,
    1347,   932,   862,   933,   362,   396,   623,   701,  1507,  1598,
    1010,  1152,  1298,  1416,   110,   157,  1390,  1475,  1554,    26,
     180,   216,    39,   565,   863,   934,  1153,  1299,  1219,  1348,
    1453,  1532,  1584,   236,   307,    81,  1132,  1279,  1410,   240,
     764,   878,  1363,  1463,  1549,  1590,  1613,  1623,  1142,  1294,
    1123,  1263,   137,   181,   340,   341,   491,   528,   223,   295,
    1046,    82,   131,   923,  1177,   404,   468,   672,  1222,  1352,
     469,   510,   509,   970,   872,  1128,   570,   669,    83,   567,
    1074,   568,   866,   935,   966,  1124,   206,   241,    38,    27,
     116,   189
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1333
static const yytype_int16 yypact[] =
{
      41,   152,   149, -1333,   176,    81,   305, -1333, -1333, -1333,
   -1333, -1333,    33, -1333, -1333,    59, -1333,   148,   317,   101,
   -1333, -1333, -1333, -1333,   437,   150, -1333, -1333, -1333,   148,
     148,   304,    81,   312, -1333, -1333, -1333, -1333, -1333,    33,
   -1333, -1333,   148,   150,   316, -1333, -1333,  1508,  1780,   272,
   -1333, -1333, -1333,   150, -1333,   148, -1333,   122,   715,   148,
     148,   111, -1333,   997,  1020,   148,   148,   152,   148,   176,
     300, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,   150,  1588,   280, -1333, -1333,   150, -1333,
   -1333,   152,   152,   152, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333,   148,   150,   148,   111, -1333,    36, -1333, -1333,
   -1333,   150, -1333, -1333, -1333,   150,   148,   150, -1333,  1023,
     150,    66, -1333,   150,   150,   150, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333,   150,   260,   150,
   -1333, -1333,   424, -1333,   317, -1333,   317,   273,   439, -1333,
     148,   111, -1333, -1333, -1333, -1333,   439, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   310,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333,   148,   150, -1333,    81, -1333,   441,
     254,   254,   266, -1333, -1333, -1333, -1333,   150,   150,   150,
     150,   416,    49,   115,    91,   801,    77,   437,  2006, -1333,
   -1333, -1333, -1333, -1333,    71,   148, -1333,   376, -1333, -1333,
   -1333, -1333, -1333, -1333,   343,   445, -1333,   445, -1333,   148,
   -1333,   158, -1333, -1333, -1333, -1333,   300, -1333, -1333, -1333,
   -1333,   148, -1333, -1333, -1333, -1333,   276,   144, -1333, -1333,
   -1333, -1333, -1333, -1333,   111, -1333, -1333, -1333, -1333,   260,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   150, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,   150, -1333, -1333, -1333, -1333,
   -1333,   150,    81,   150, -1333, -1333, -1333,   546,   152, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   148,
     437,   437,   437, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
      33, -1333,    33, -1333,    33, -1333,   150,   150,   144, -1333,
   -1333, -1333,    33, -1333,    33, -1333, -1333, -1333, -1333,   150,
   -1333, -1333,   132,   152,   152, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333,   468, -1333,   148,   150,   306,   306,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   144, -1333,
   -1333, -1333, -1333, -1333,   111,   111, -1333, -1333, -1333, -1333,
      81, -1333,  1442, -1333, -1333,  1794,   519,   832,   940, -1333,
     148, -1333,   437,   150, -1333,   150, -1333,   150,   111,   111,
     150,  1196, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333,   152, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     150,   152, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     148,   150, -1333, -1333, -1333,   150,   321, -1333,  1196,    81,
    1196,  1196,   148,  1196, -1333, -1333, -1333,   150, -1333, -1333,
   -1333, -1333, -1333,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461, -1333,  1198, -1333, -1333, -1333,   322,
     867,   148, -1333, -1333,   150,  1263, -1333, -1333,   376, -1333,
   -1333,  1263, -1333, -1333,   150,  1196, -1333, -1333,  1263, -1333,
     342,   461,  1545,  1545,  1545,   461,  1545, -1333,   130,  1545,
     461,   461,   -29,   300,    81,   276, -1333,   150, -1333, -1333,
   -1333,    81,   276,    81, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,  1879,
     444,   466, -1333,   425, -1333,   382, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   150, -1333, -1333, -1333,
   -1333,   150, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   540,
   -1333, -1333, -1333, -1333,   150, -1333, -1333,  1545,   111,   111,
      42,   111,   111,   111,  1276, -1333, -1333, -1333, -1333,   130,
   -1333, -1333, -1333, -1333,   130, -1333, -1333,   130, -1333, -1333,
    1545,   130, -1333, -1333, -1333, -1333, -1333,   130, -1333, -1333,
    1545,  1545, -1333, -1333, -1333, -1333,   130,   150,   150, -1333,
     150,    63, -1333,    63,    63,    63,   150,   150,   150, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   150,
   -1333, -1333,   186,   529, -1333,   653,   833,   529,   605, -1333,
     171,   529,   581, -1333,   783, -1333, -1333,   150, -1333,   130,
   -1333, -1333,   150,   150, -1333,    53, -1333,   150,   150,   150,
   -1333,   150, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333,   130, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     130, -1333, -1333,   130, -1333, -1333,   -75,   361, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   990, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333,    81,   -34, -1333, -1333,    59,   548,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,   442,   460,   548, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   539,
     523,    93,    93,    93,    93,   548, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   150,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   543,
   -1333, -1333,   108, -1333,   108,   108, -1333,   152, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333,  1584,   148,    81,
   -1333,   150, -1333,   150, -1333, -1333,   894, -1333,   708,   252,
   -1333, -1333,   150, -1333,   150, -1333, -1333,   561,    46, -1333,
   -1333,   150, -1333,   150, -1333, -1333,   150, -1333, -1333,   150,
   -1333, -1333,   150, -1333, -1333,   150, -1333, -1333,    26,    86,
   -1333,   431,   421,   150, -1333,   130, -1333, -1333,   531,   281,
     152, -1333, -1333,  1023,   -73, -1333, -1333,   631, -1333,   512,
     762, -1333, -1333,   481,   365,   588,   454, -1333,    76,   104,
     108,   108,   108,   108,   108,   108,   104,   437,   418, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333,    51, -1333, -1333,
     424, -1333, -1333, -1333, -1333, -1333,   150,   436,   561, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   523, -1333,
     -31, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     523, -1333, -1333,   -31, -1333, -1333, -1333, -1333,   150,   453,
     150, -1333, -1333, -1333, -1333,   529, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   148,   321, -1333, -1333,
   -1333, -1333, -1333,   711,   150, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     726,   176,   529,    81, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   620,   108,   152, -1333,
   -1333, -1333, -1333, -1333, -1333,    59,   454, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,   260,   150,   691, -1333, -1333,
     751,   -85, -1333, -1333, -1333,  -115, -1333,   726, -1333, -1333,
   -1333,   568,   562,   635, -1333, -1333,   449,  1253, -1333, -1333,
      97, -1333, -1333, -1333,   448, -1333, -1333, -1333,   150, -1333,
     384,   -24, -1333, -1333,   -24,   150, -1333, -1333,   950,   950,
   -1333, -1333, -1333,   523, -1333, -1333, -1333, -1333, -1333,  -122,
   -1333, -1333,   150, -1333, -1333,   150,    86,   148,   150, -1333,
     -77, -1333, -1333, -1333,   150, -1333,   -90, -1333, -1333, -1333,
   -1333,    33, -1333, -1333, -1333, -1333,    33, -1333, -1333,    33,
   -1333,   148,   409, -1333,   530,   111,   150, -1333, -1333,   150,
     260, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
     260,   260,   675,   553,   553,   675, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333,    99, -1333, -1333,
   -1333,   812, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   679,
   -1333, -1333,   946, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   651, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,    34,   276,   104,   104, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,  1014,   671, -1333, -1333,   634,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333,   150, -1333, -1333,
   -1333, -1333, -1333, -1333,   950,   150,   453, -1333, -1333,  -119,
   -1333, -1333, -1333, -1333, -1333,   150, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333,   684,   255,   255, -1333, -1333, -1333, -1333, -1333,   150,
     624, -1333, -1333, -1333,  -117,   260,  -117, -1333, -1333, -1333,
    -117, -1333,  -117, -1333, -1333,  -117, -1333,  -117,   269, -1333,
   -1333, -1333,   428,   529,   104,   560, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,   -98, -1333, -1333, -1333, -1333,
   -1333, -1333,   150, -1333,   255,   150,   255, -1333, -1333, -1333,
   -1333,   739, -1333,   -64, -1333, -1333,    26, -1333, -1333,   -31,
   -1333, -1333, -1333, -1333, -1333,   111,   111, -1333, -1333, -1333,
     150,   114,    64, -1333,   150, -1333,  -127, -1333, -1333, -1333,
   -1333,   150, -1333,   -52, -1333, -1333, -1333,   -52, -1333, -1333,
   -1333, -1333, -1333,   150, -1333, -1333, -1333, -1333, -1333,    28,
   -1333, -1333,   -46, -1333, -1333, -1333, -1333, -1333, -1333,   383,
     890, -1333, -1333, -1333, -1333, -1333, -1333,  1023,   657, -1333,
   -1333,   148, -1333,   564, -1333, -1333, -1333,    11, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,   684, -1333, -1333, -1333, -1333,
   -1333, -1333,    81,    26, -1333, -1333, -1333, -1333, -1333,   150,
   -1333, -1333, -1333,   150,   150, -1333,   150, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,   534, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,   113, -1333,  -117,   260, -1333, -1333, -1333,
   -1333, -1333,   255, -1333,   890, -1333, -1333,   150, -1333, -1333,
   -1333, -1333,    26,   150, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333, -1333,   148,   148, -1333,   725,
   -1333,   150, -1333, -1333,   -31,   376, -1333, -1333,   150, -1333,
   -1333, -1333, -1333,   577, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333,   260,   950, -1333, -1333, -1333,    26, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333,   150, -1333,   150,   148, -1333, -1333,
     272, -1333, -1333, -1333, -1333, -1333,   150, -1333,   150, -1333,
     260, -1333, -1333, -1333,   150, -1333,   150, -1333, -1333, -1333,
     150,   -46, -1333,   280, -1333, -1333,   150, -1333, -1333, -1333,
   -1333, -1333, -1333,   150, -1333, -1333
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1333,   -25, -1333, -1333, -1333,     8, -1333,  -906, -1333, -1333,
   -1333,  -265, -1333, -1333, -1333, -1333,   173, -1333, -1333, -1333,
   -1333, -1333,   223,   139, -1333, -1333,  -996, -1333, -1333, -1333,
   -1333,   645, -1333, -1333, -1333, -1333,  -168,   470,   473,  -285,
     599, -1333, -1333,   -91, -1333, -1333, -1333, -1333,  -557, -1333,
   -1333, -1333, -1333,   504,  1011, -1333,  -878, -1333, -1333, -1333,
   -1333, -1333, -1333,  -310, -1333,  -316, -1333, -1333,  -291, -1333,
   -1333, -1333, -1333, -1333,  -902, -1333,  -901, -1333,  -896, -1333,
    -893, -1333,  -891, -1333, -1333, -1333,  -630, -1333, -1333, -1333,
    -666, -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,   -26,
   -1333, -1333, -1333, -1333, -1333, -1333, -1333, -1333,  -890, -1333,
   -1333,   527, -1333, -1333, -1333, -1333, -1333,  -284, -1333, -1333,
   -1333, -1333, -1333, -1333,   528, -1333,   -11,     3,  1663, -1333,
      -7, -1333,  1085, -1333,  -880, -1333, -1333, -1333,  1301, -1333,
   -1333, -1333, -1333,   544, -1043, -1333, -1333, -1333, -1333,   716,
   -1333, -1333,   329, -1333,  -570, -1333, -1333, -1333,  -872, -1333,
     308, -1333, -1333, -1333, -1333, -1333, -1333, -1333,     4, -1333,
     180, -1333,   745, -1333, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333, -1333,  -834, -1333, -1333, -1333,  -871,
   -1333, -1333, -1333, -1333, -1333, -1333,   263,   858, -1333, -1333,
   -1333,  -517, -1333, -1333, -1333, -1333, -1202,  -181,  -428, -1333,
   -1333, -1333, -1333, -1333, -1109, -1333, -1333, -1333, -1333, -1333,
     -99,  -514, -1097, -1333, -1333, -1333, -1333, -1333, -1332, -1333,
   -1333, -1333, -1227, -1333,  -420, -1333, -1333, -1333, -1333, -1333,
    -665, -1333,   769, -1333,  -193, -1333,  -209, -1333,    90, -1333,
   -1333, -1333, -1333,   355, -1333,   903,   128, -1025, -1333, -1333,
   -1333,  -141, -1333,  -242, -1333,  -287, -1333, -1333, -1333,    55,
     123,  -674, -1333,  -502, -1333, -1333, -1333, -1333, -1333, -1333,
     813, -1333,   472, -1333, -1333, -1333, -1333, -1333,  -251, -1333,
   -1333,  -560, -1333,  -582, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,   -83,   105, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333, -1333,   656,  -864, -1333, -1333, -1333,   830, -1333,
   -1333, -1333,  -155, -1333,  -210, -1333, -1333,  -113, -1333, -1333,
   -1333,  -105, -1333,  -889, -1333,  -213, -1333,  -803, -1333, -1333,
   -1333,  -874, -1333, -1333, -1333, -1333,  -679,  -882,   502, -1333,
   -1333, -1333,  -699, -1333,   767, -1333, -1333, -1333, -1333, -1333,
     845,   339, -1333,  -942, -1333, -1333, -1333, -1333, -1333, -1333,
   -1333, -1333,   902, -1333,   141, -1333, -1333,   -44, -1333, -1333,
   -1333, -1333,   213, -1333, -1333, -1333,   411, -1333, -1333, -1333,
   -1333, -1333, -1333, -1333,  -189, -1333,  -363, -1333, -1333,  -214,
     873, -1333, -1333, -1333, -1333, -1333,  -195, -1333, -1300, -1333,
   -1333, -1333, -1333,   904, -1333,   712, -1333, -1333, -1333, -1333,
    -706, -1333, -1248, -1333, -1333, -1333, -1333, -1333,  -980,  -186,
   -1333, -1333, -1333,  -912, -1333, -1333, -1333, -1333,  -467, -1333,
   -1089,  1032, -1333, -1333,  -241,   742, -1333, -1333,  -235, -1333,
   -1333, -1333, -1333, -1333,  -770, -1333, -1333, -1333,   727, -1333,
   -1333, -1333,   203, -1333, -1333, -1333, -1333, -1333,  1551,    12,
     347, -1333
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,   592,   275,   883,   261,   273,   785,  1147,   756,   514,
     232,  1027,   771,    52,    51,  1351,   803,  1001,    54,   892,
     260,  1036,    71,  1148,  1236,  1038,  1039,  1005,    97,  1288,
     648,  1040,    99,   105,  1041,    46,    40,   656,  1044,   658,
     864,  1290,    23,   250,  1138,  1023,   312,   335,   317,     3,
    1058,  1419,  1057,    28,  1082,    28,  1081,  1102,  1059,   345,
    1031,  1093,  1083,  1084,  1118,    23,     3,     3,   138,     3,
      28,   183,    23,   151,     3,    28,   183,    23,   331,     3,
     853,  1270,   417,    23,     3,  1022,  1138,  1133,   159,     3,
     942,  1243,   162,  1486,  1516,    28,   164,    28,  1275,   881,
     165,  1092,   167,    23,     3,   182,   184,     3,   190,   191,
     192,     3,  1482,   608,   673,    28,     3,     3,  1528,    28,
    1384,    67,   193,  1028,   196,   609,  1432,  1062,  1505,   163,
     988,  1087,   203,  1155,  1189,  1296,   844,   735,   845,   737,
     739,   741,   843,   187,    19,   887,   843,    37,    28,    11,
    1531,   681,    28,  1355,   219,     3,   642,     1,  1213,   681,
      37,   964,   200,   681,   201,   908,   929,   643,    20,  1220,
     226,   869,   681,    20,   229,   920,    20,  1385,    20,     3,
    1216,   612,   242,   243,   244,   245,   247,   252,   258,   265,
     270,   274,  1577,  1000,  1488,   194,  1510,    20,   169,   251,
    1512,  1216,   115,   988,  1371,    20,   114,    32,   114,   466,
     309,    62,   314,   643,   993,   613,   323,  1196,    20,    62,
      20,    62,    20,   771,  1580,  1197,   114,   754,   277,   278,
     114,   320,    32,     4,  1285,  1088,   299,  1253,  1241,  1251,
     677,   940,  1139,    20,  1242,  1254,  1255,    62,  1260,    20,
       4,     4,   869,   346,  1496,  1496,   161,   321,     3,   114,
      62,  1042,  1108,     4,    20,  1114,  1000,   754,     4,   194,
     347,    20,   384,     4,  1303,    62,   348,  1228,   351,   747,
      28,  1557,   357,  1285,  1139,   754,  1286,  1286,     4,   687,
     171,     4,   264,  1386,   264,     4,  1309,   170,   256,   257,
       4,     4,   209,  1502,   371,   370,   373,   372,   375,   374,
    1329,   376,   377,  1246,  1500,  1599,   380,   379,   382,   381,
      24,     5,   681,    20,   383,   228,  1350,   386,    20,    20,
    1583,    20,   367,   368,   369,  1223,   650,   173,    24,     4,
     681,    20,   401,   657,    20,     3,    20,   947,  1478,  1369,
    1465,  1367,  1379,     5,  1378,   268,     7,  1370,    20,    20,
      14,    20,    62,   781,    29,   677,   296,   412,  1383,  1544,
     437,   453,    20,   463,  1607,   647,    42,    43,   472,   385,
     473,    20,   474,  1394,  1397,   477,    20,  1174,  1184,    53,
    1449,   114,    20,   410,    20,   322,    67,     5,   339,    62,
     673,  1403,    98,  1491,  1566,   343,   112,   113,    20,    20,
      20,    69,   126,   127,   471,   130,  1568,    20,  1256,  1492,
     336,   337,     7,    17,    67,    20,   133,    20,   378,  1075,
     350,  1422,   608,   609,    30,   507,   754,   610,   840,    69,
    1425,  1429,     4,    23,   104,    20,   512,   936,  1424,  1428,
     513,   478,    69,    20,    62,   937,     7,     7,     7,   158,
     257,   160,   529,  1601,    28,    44,    20,    69,   407,  1384,
      48,  1550,  1459,   166,   479,  1603,    55,    94,   188,   339,
     554,    20,   518,   752,   611,   577,   148,  1552,  1016,   587,
     588,   681,   938,   168,   246,   480,   593,   481,    62,   596,
     612,   194,  1469,   600,  1473,  1487,  1275,   208,   197,   940,
    1468,  1264,  1472,   634,  1016,  1362,   168,   681,    37,   339,
     217,   234,   652,   613,  1051,   408,   409,    28,   308,     4,
      62,   936,     3,   603,    62,  1450,   239,    62,    62,   937,
     302,   225,   133,   305,   874,  1533,  1066,    20,    67,   475,
     476,   482,  1535,   397,    69,  1358,  1537,  1538,  1593,   255,
    1159,   685,  1539,  1522,    20,  1540,   686,   202,    20,  1542,
      62,   300,   301,   849,  1594,   134,    20,  1076,  1322,   688,
    1052,   895,  1456,  1323,   939,  1553,   319,  1276,   402,   218,
     673,   530,  1556,   940,   702,   670,   946,   894,   333,   705,
     218,  1401,   708,    67,  1053,    20,   714,    37,    62,   569,
     251,   911,   717,   912,   673,   614,  1265,   913,   681,   677,
     483,   728,   731,   732,  1289,   733,   734,  1266,   736,   738,
     740,   742,   743,   744,    63,    62,   677,   942,   114,   943,
    1574,  1582,  1386,   790,   745,  1055,    69,   748,  1573,  1079,
     760,   766,  1007,   776,   876,   782,    20,   796,    37,   807,
      20,  1076,   812,     7,   813,   988,   366,   816,   817,  1015,
      62,   353,   821,   822,   823,   354,   824,  1009,  1048,    67,
     946,   791,   792,   793,   794,  1605,   825,   673,  1174,   758,
      69,   134,  1122,   790,    62,   828,   452,  1095,   831,   104,
     774,   834,   836,   104,    20,  1130,   256,   257,     7,     7,
     754,    20,  1220,   400,   869,  1067,     4,  1151,  1181,   790,
      62,   850,    69,    20,    62,   840,    69,  1230,   869,    69,
      69,   791,   792,   793,   794,  1563,    20,  1161,  1162,   758,
      20,  1033,    62,    20,    20,   840,    62,   470,  1406,   692,
     693,  1163,   697,   698,   699,  1075,  1275,   791,   792,   793,
     794,   758,    69,  1016,  1016,   758,   355,   681,    62,   937,
     875,  1068,  1338,   936,   774,   681,    20,  1341,   938,  1137,
      62,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,  1541,  1275,   910,  1136,   775,    62,  1406,   356,
      69,   757,  1432,   207,    62,   772,   938,     7,  1461,   788,
     795,   210,  1194,  1547,    20,    62,     7,   511,   938,    67,
     869,  1016,   101,   940,   681,   869,    20,    69,    62,   525,
    1588,  1239,  1193,   694,   818,   940,   315,  1276,  1200,   102,
      62,    20,   949,    67,   936,   977,   971,  1281,   972,  1355,
    1283,    62,   937,   979,   984,   457,   248,   986,   586,   987,
     795,  1187,   413,   991,  1201,   414,   994,   942,   995,    67,
     775,   996,    62,    67,   997,   939,    20,   998,   103,  1127,
     999,   458,   868,    20,  1004,  1190,   795,   459,  1011,   938,
    1012,    67,  1523,  1017,  1021,    67,   415,  1499,  1503,  1029,
      20,    62,  1035,   973,     8,  1054,   940,  1265,  1069,  1077,
    1091,  1034,    69,  1368,  1346,  1034,    69,    67,  1266,   418,
     758,  1051,    62,   440,   759,   978,    20,  1098,   974,    67,
      20,  1099,   898,   901,   904,   907,   419,  1034,    69,   696,
     297,   975,  1125,  1565,   626,   629,   222,   633,    20,  1115,
     639,  1129,    20,     3,   885,  1202,    62,   254,   820,  1121,
      69,   156,  1295,  1479,    67,  1140,   231,  1203,  1555,  1185,
     128,  1480,    69,   104,    20,  1244,  1204,  1052,  1146,   765,
    1333,   673,   259,  1150,   768,  1154,    20,  1372,  1400,    69,
    1335,  1337,  1405,   946,  1095,  1408,    69,   969,  1112,  1567,
      67,  1053,  1205,    20,   153,   155,   155,    69,   328,  1165,
      20,   992,   571,   806,   572,   921,   772,   118,   691,   681,
      69,    20,  1578,   172,   269,  1167,  1353,   266,  1409,    62,
    1612,  1622,    69,  1245,    20,    62,   937,   788,  1595,  1086,
     122,   713,   194,    69,  1354,   271,    20,   119,   421,  1344,
      67,   722,   725,  1313,   120,  1392,   573,    20,  1602,   839,
     574,  1314,  1402,   870,    69,   835,  1482,   788,   100,   106,
     123,  1191,  1192,   938,   788,  1206,  1261,   124,    20,    62,
     963,   880,  1224,   759,  1355,  1527,  1526,  1188,  1233,   276,
     111,  1238,  1249,    69,   575,  1259,    20,   889,   758,  1267,
     168,  1417,   576,  1274,   423,   238,  1280,    20,  1414,  1282,
    1284,   406,  1457,  1104,    69,  1109,  1109,  1455,  1104,   425,
    1285,   886,  1025,  1286,  1297,  1436,   681,  1300,    20,     0,
    1301,  1302,  1262,  1307,     0,  1308,     0,     4,   838,  1311,
       0,  1312,     0,   788,     0,  1316,  1315,   840,    69,     0,
    1318,  1317,     0,  1320,  1319,  1216,     0,  1324,     0,   422,
       0,  1331,    20,     0,  1332,   465,     0,     0,   204,     0,
       0,     0,   169,     0,     0,     0,   841,     0,    67,     0,
    1175,  1178,     0,     0,    67,     0,   810,   985,     0,   205,
     220,     0,  1349,     0,     0,     0,  1356,     7,   104,     7,
       7,     0,     7,   842,  1365,   170,   781,  1376,   677,   843,
     230,   365,     0,     0,     0,   968,   844,     0,   845,     0,
       0,    69,   171,   461,     0,   462,     0,    69,    67,  1519,
     846,   233,  1521,     0,     0,    20,     0,     0,  1387,     0,
       0,    20,   847,     0,   806,   172,   311,  1016,   316,     0,
     681,     0,   325,   848,     0,     0,   391,   394,     0,     0,
       0,   759,  1413,   897,   900,   903,   906,   313,     0,   318,
    1415,    69,   563,   329,  1418,     7,     0,   543,     0,     0,
    1420,     0,   849,   173,   788,    20,     0,    62,     0,   544,
       0,   890,     0,     7,   545,     7,     7,     7,     7,     7,
       7,     0,     0,     0,  1431,   478,  1571,     0,     0,  1434,
     546,  1437,     0,     0,  1126,  1440,     0,  1443,   358,     0,
    1445,     0,  1447,  1451,     0,     0,  1330,  1454,   479,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   363,
       0,     0,    62,   937,     0,  1248,     0,   608,   609,   480,
    1464,   481,   610,     0,   547,   506,     0,  1466,     0,     0,
    1471,  1600,     0,   387,   508,     0,  1476,     0,     0,   548,
     549,     0,   478,  1157,  1490,     0,     0,     0,   625,   628,
     938,   632,     0,     0,   638,  1495,  1497,  1501,     0,  1504,
    1616,  1506,     0,   788,   788,   479,  1508,   940,  1509,   611,
       0,  1621,  1511,   416,     0,   482,   438,   454,  1514,   464,
       0,  1006,  1051,     0,  1517,   612,   480,  1520,   481,     0,
    1020,  1024,     7,     7,   424,     0,  1032,   451,   456,     0,
     467,     0,     0,  1534,     0,     0,    67,  1094,   613,   751,
       0,  1103,   763,     0,   550,   780,     0,     0,  1119,   805,
     788,   788,   690,     0,     0,     0,     0,     0,     0,   700,
     551,     0,     0,     0,  1559,     0,     0,     0,  1560,  1561,
       0,  1562,   482,     0,   483,   712,     0,     0,     0,    69,
       0,  1175,   788,     0,     0,   721,   724,   552,  1564,   553,
    1569,    67,  1053,    20,     0,     0,     0,     0,     0,     0,
       0,     0,  1581,     0,  1306,     0,     0,     0,  1585,     0,
       0,     0,   788,   860,   788,     0,   556,     0,     0,     0,
       0,   578,    59,    60,     0,     0,  1591,     0,  1321,  1592,
      61,    62,     0,  1597,    69,     0,    63,   566,     0,     0,
       0,   483,   585,     0,     0,     0,  1493,  1494,    20,   635,
       0,     0,    10,     0,     0,    13,    16,     0,    20,  1608,
       0,  1609,    64,   516,     0,   519,   522,     0,   526,     0,
     636,  1614,   837,  1615,     0,     0,     0,    65,     0,  1617,
       0,  1618,     0,     0,   411,  1619,  1620,     0,    59,    60,
       0,  1624,     0,     0,     0,     0,    61,    62,  1625,     0,
     589,     0,    63,  1218,     0,     0,   594,     0,     0,     0,
     597,     0,     0,   601,     0,   605,   608,   609,    10,     0,
     132,   610,     0,   139,   140,   141,   142,     0,    64,     0,
     703,   143,   144,   145,   146,   706,     0,     0,   709,     0,
       0,     0,   715,    65,     0,     0,     0,     0,   718,     0,
     788,   704,    10,    10,    10,     0,   707,   729,  1304,   710,
      66,     0,  1310,   716,     0,     0,   936,     0,   611,   719,
       0,     0,     0,    62,   937,     0,     0,     0,   730,     0,
      67,     0,   186,   749,   612,     0,   761,   767,     0,   777,
       0,   783,     0,   798,  1045,   808,     0,  1064,     0,     0,
     814,  1089,     0,     0,   753,     0,     0,   613,   770,     0,
      68,   938,   786,     0,     0,     0,   811,     0,     0,     0,
     939,   815,   826,    69,     0,     0,    66,     0,   940,     0,
      70,   829,     0,     0,   832,     0,     0,    20,     0,     0,
       0,     0,     0,   827,     0,   922,    67,   926,   926,     0,
     931,     0,   830,     0,     0,   833,     0,   852,     0,   941,
       0,     0,     0,     0,     0,     0,     0,  1395,  1398,     0,
       0,     0,   942,     0,   943,   298,    68,  1404,   865,   517,
       0,   520,   523,     0,   527,     0,   944,     0,     0,    69,
       0,    84,    85,    86,     0,   945,    70,     0,     0,   614,
       0,     0,     0,    20,     0,     0,     0,     0,  1546,    87,
      88,    89,     0,     0,     0,   946,   590,  1169,     0,     0,
       0,     0,   595,  1026,  1426,  1430,   598,     0,     0,   602,
       0,   606,     0,     0,   947,     0,   847,     0,    90,    91,
      92,   394,     0,  1106,   926,  1110,  1110,   926,  1106,     0,
       0,     0,     0,     0,     0,   759,  1460,     0,     0,    10,
       0,     0,     0,     0,  1198,    69,     0,     0,     0,     0,
       0,     0,     0,     0,  1226,     0,     0,   948,   951,    20,
    1235,     0,     0,    62,  1257,     0,  1470,   659,  1474,   980,
       0,     0,     0,  1586,  1587,  1485,     0,   660,     0,   965,
       0,     0,     0,   661,    10,    10,     0,   662,     0,     0,
     983,   663,     0,   426,     0,     0,     0,     0,   664,     0,
     665,     0,   427,   354,     0,     0,  1013,   428,   429,     0,
     666,   667,   668,     0,  1610,     0,     0,     0,  1037,     0,
       0,  1056,     0,     0,  1071,  1080,   430,  1014,   431,     0,
       0,     0,  1530,     0,     0,     0,     0,     0,     0,  1047,
       0,     0,  1065,     0,     0,  1073,  1090,     0,     0,     0,
     926,   506,     0,     0,     0,     0,     0,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,  1361,     0,
       0,   432,   433,     0,     0,     0,  1373,     0,     0,  1380,
       0,   434,   435,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    10,   279,     0,     0,   280,     0,     0,     0,
     281,   282,   283,   284,  1575,   285,  1579,   286,   287,     0,
       0,   288,     0,     0,     0,     0,     0,     0,   436,   289,
       0,     0,     0,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
     292,  1168,   293,     0,     0,     0,     0,   294,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,  1170,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1435,     0,  1438,     0,     0,     0,  1441,  1195,  1444,
       0,  1208,  1446,     0,  1448,     0,     0,     0,  1225,     0,
       0,     0,     0,     0,  1234,     0,     0,  1240,  1250,  1199,
       0,     0,  1215,     0,     0,  1269,     0,     0,     0,  1227,
       0,     0,     0,     0,     0,  1237,     0,     0,  1247,  1258,
       0,     0,     0,     0,     0,     0,  1273,   532,   533,   534,
     535,   536,   537,   539,   540,   541,   542,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1325,   607,     0,     0,     0,   630,     0,
       0,     0,     0,   640,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1543,     0,     0,     0,     0,
       0,     0,  1357,     0,     0,     0,     0,     0,     0,     0,
    1366,     0,     0,  1377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1364,     0,     0,     0,     0,     0,     0,
       0,  1374,     0,     0,  1381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1570,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    10,     0,    10,    10,     0,    10,     0,
       0,     0,  1477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1536,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
    1545,    10,    10,    10,    10,    10,    10,     0,     0,     0,
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
       0,     0,  1173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    10
};

static const yytype_int16 yycheck[] =
{
      25,   518,   216,   773,   213,   215,   680,  1003,   673,   476,
     199,   923,   677,    39,    39,  1217,   682,   908,    43,   789,
     213,   927,    47,  1003,  1113,   927,   927,   909,    53,  1138,
     544,   927,    57,    58,   927,    32,    24,   551,   927,   553,
     746,  1138,     6,   211,    75,   919,   235,   256,   237,     3,
     930,  1299,   930,     4,   934,     4,   934,   939,   930,   269,
     924,   935,   934,   934,   946,     6,     3,     3,    93,     3,
       4,     5,     6,    98,     3,     4,     5,     6,   246,     3,
     746,  1124,   392,     6,     3,   919,    75,   978,   113,     3,
     188,  1116,   117,  1393,    66,     4,   121,     4,   122,   773,
     125,   935,   127,     6,     3,   130,   131,     3,   133,   134,
     135,     3,   176,    71,   148,     4,     3,     3,  1450,     4,
      86,   238,   147,   196,   149,    72,   178,   930,   255,   117,
     104,   934,   157,  1015,  1076,   257,   226,   651,   228,   653,
     654,   655,   219,   131,   111,   775,   219,    19,     4,     0,
    1450,   236,     4,   272,   179,     3,   185,   116,  1100,   236,
      32,   867,   154,   236,   156,   795,   845,   242,   295,   284,
     195,   286,   236,   295,   199,    67,   295,   143,   295,     3,
     265,   139,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,  1524,   167,  1396,   241,  1423,   295,   149,   150,
    1427,   265,    61,   104,  1229,   295,   115,   131,   115,   398,
     235,    89,   237,   242,   888,   162,   241,  1097,   295,    89,
     295,    89,   295,   888,  1524,  1097,   115,   181,   216,   217,
     115,    73,   131,   187,   170,   934,   224,  1117,  1116,  1117,
     194,   144,   273,   295,  1116,  1117,  1117,    89,  1120,   295,
     187,   187,   286,   278,   141,   141,   115,    99,     3,   115,
      89,   927,   941,   187,   295,   944,   167,   181,   187,   241,
     295,   295,   140,   187,  1156,    89,   301,  1111,   303,    93,
       4,  1483,   307,   170,   273,   181,   173,   173,   187,   599,
     199,   187,   201,   259,   201,   187,  1160,   182,   183,   184,
     187,   187,   161,  1412,   330,   330,   332,   332,   334,   334,
    1184,   336,   337,  1116,  1411,  1563,   342,   342,   344,   344,
     261,   245,   236,   295,   349,   197,  1217,   352,   295,   295,
    1532,   295,   320,   321,   322,  1105,   545,   260,   261,   187,
     236,   295,   367,   552,   295,     3,   295,   250,  1391,  1229,
    1375,  1229,  1232,   245,  1232,   214,     1,  1229,   295,   295,
       5,   295,    89,   192,    17,   194,   295,   392,  1248,  1458,
     395,   396,   295,   398,  1576,   543,    29,    30,   403,   247,
     405,   295,   407,  1265,  1266,   410,   295,  1052,  1067,    42,
     121,   115,   295,   390,   295,   237,   238,   245,   257,    89,
     148,  1275,    55,  1399,  1513,   264,    59,    60,   295,   295,
     295,   281,    65,    66,   402,    68,  1513,   295,  1117,  1399,
     276,   277,    67,   118,   238,   295,   126,   295,   338,    64,
     302,  1321,    71,    72,   117,   460,   181,    76,   157,   281,
    1322,  1323,   187,     6,   258,   295,   471,    82,  1322,  1323,
     475,   109,   281,   295,    89,    90,   101,   102,   103,   112,
     184,   114,   487,  1572,     4,   161,   295,   281,   378,    86,
     158,  1467,  1354,   126,   132,  1572,   160,   205,   131,   338,
     505,   295,   479,   672,   123,   510,   206,  1467,   233,   514,
     515,   236,   127,    77,    78,   153,   521,   155,    89,   524,
     139,   241,  1384,   528,  1386,  1396,   122,   160,    84,   144,
    1384,    63,  1386,   538,   233,  1221,    77,   236,   390,   378,
     210,   267,   547,   162,   159,   384,   385,     4,    83,   187,
      89,    82,     3,   530,    89,   266,   270,    89,    89,    90,
     164,   194,   126,   200,   758,  1457,    65,   295,   238,   408,
     409,   209,  1458,    85,   281,  1221,  1458,  1458,  1554,   212,
    1027,   586,  1458,   180,   295,  1458,   591,   294,   295,  1458,
      89,   224,   225,   292,  1554,   275,   295,   212,   169,   604,
     215,   790,  1352,   174,   136,  1475,   239,   203,   282,   279,
     148,   130,  1483,   144,   619,   151,   231,   790,   251,   624,
     279,  1275,   627,   238,   239,   295,   631,   479,    89,   287,
     150,    68,   637,    70,   148,   254,   168,    74,   236,   194,
     278,   646,   647,   648,  1138,   650,   651,   179,   653,   654,
     655,   656,   657,   658,    94,    89,   194,   188,   115,   190,
    1522,  1532,   259,    62,   669,   930,   281,   672,  1522,   934,
     675,   676,   221,   678,   106,   680,   295,   682,   530,   684,
     295,   212,   687,   308,   689,   104,   319,   692,   693,   138,
      89,   125,   697,   698,   699,   129,   701,   256,   166,   238,
     231,   100,   101,   102,   103,  1576,   711,   148,  1353,   108,
     281,   275,   274,    62,    89,   720,   177,   243,   723,   258,
      95,   726,   727,   258,   295,   269,   183,   184,   353,   354,
     181,   295,   284,   366,   286,   234,   187,   264,    98,    62,
      89,   746,   281,   295,    89,   157,   281,   165,   286,   281,
     281,   100,   101,   102,   103,  1505,   295,    26,    27,   108,
     295,   110,    89,   295,   295,   157,    89,   400,   114,   608,
     609,    40,   611,   612,   613,    64,   122,   100,   101,   102,
     103,   108,   281,   233,   233,   108,   220,   236,    89,    90,
     758,   290,    97,    82,    95,   236,   295,   224,   127,   988,
      89,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,  1458,   122,   819,   988,   191,    89,   114,   253,
     281,   673,   178,   158,    89,   677,   127,   452,   248,   681,
     229,   166,  1097,   249,   295,    89,   461,   470,   127,   238,
     286,   233,   107,   144,   236,   286,   295,   281,    89,   482,
     105,  1116,  1097,   610,   695,   144,   237,   203,    87,   124,
      89,   295,   867,   238,    82,   137,   871,  1131,   873,   272,
    1134,    89,    90,   878,   879,    23,   211,   882,   511,   884,
     229,  1075,   392,   888,   113,   392,   891,   188,   893,   238,
     191,   896,    89,   238,   899,   136,   295,   902,   163,   970,
     905,    49,   754,   295,   909,  1095,   229,    55,   913,   127,
     915,   238,  1449,   918,   919,   238,   392,  1411,  1412,   924,
     295,    89,   927,     9,     1,   930,   144,   168,   933,   934,
     935,   280,   281,  1229,  1205,   280,   281,   238,   179,   392,
     108,   159,    89,   395,   271,   217,   295,   938,    34,   238,
     295,   938,   791,   792,   793,   794,   392,   280,   281,   610,
     224,    47,   967,  1513,   533,   534,   179,   536,   295,   945,
     539,   976,   295,     3,   774,   204,    89,   212,   695,   947,
     281,   103,  1143,  1391,   238,   990,   199,   216,  1482,  1068,
      67,  1391,   281,   258,   295,  1116,   225,   215,  1003,   146,
    1190,   148,   213,  1008,   676,  1010,   295,  1229,  1275,   281,
    1200,  1201,  1276,   231,   243,  1279,   281,   869,   943,  1513,
     238,   239,   251,   295,   101,   102,   103,   281,   241,  1034,
     295,   888,   145,   230,   147,   842,   888,    20,   607,   236,
     281,   295,  1524,   222,   223,  1050,   214,   214,  1279,    89,
    1590,  1613,   281,  1116,   295,    89,    90,   909,  1555,   934,
      20,   630,   241,   281,   232,   215,   295,    50,   392,  1204,
     238,   640,   641,  1166,    57,  1264,   189,   295,  1572,    69,
     193,  1166,  1275,   755,   281,   726,   176,   939,    57,    58,
      50,  1096,  1097,   127,   946,  1100,  1120,    57,   295,    89,
     867,   773,  1107,   271,   272,   195,  1449,  1075,  1113,   216,
      58,  1116,  1117,   281,   227,  1120,   295,   789,   108,  1124,
      77,  1296,   235,  1128,   392,   201,  1131,   295,  1294,  1134,
    1135,   369,  1353,   940,   281,   942,   943,  1352,   945,   392,
     170,   774,   919,   173,  1149,  1335,   236,  1152,   295,    -1,
    1155,  1156,  1120,  1158,    -1,  1160,    -1,   187,   727,  1164,
      -1,  1166,    -1,  1015,    -1,  1171,  1171,   157,   281,    -1,
    1176,  1176,    -1,  1179,  1179,   265,    -1,  1182,    -1,   392,
      -1,  1186,   295,    -1,  1189,   398,    -1,    -1,   157,    -1,
      -1,    -1,   149,    -1,    -1,    -1,   186,    -1,   238,    -1,
    1052,  1053,    -1,    -1,   238,    -1,   684,   879,    -1,   157,
     179,    -1,  1217,    -1,    -1,    -1,  1221,   842,   258,   844,
     845,    -1,   847,   213,  1229,   182,   192,  1232,   194,   219,
     199,   308,    -1,    -1,    -1,   868,   226,    -1,   228,    -1,
      -1,   281,   199,   283,    -1,   285,    -1,   281,   238,  1439,
     240,   199,  1442,    -1,    -1,   295,    -1,    -1,  1263,    -1,
      -1,   295,   252,    -1,   230,   222,   235,   233,   237,    -1,
     236,    -1,   241,   263,    -1,    -1,   353,   354,    -1,    -1,
      -1,   271,  1287,   791,   792,   793,   794,   235,    -1,   237,
    1295,   281,   505,   241,  1299,   920,    -1,    79,    -1,    -1,
    1305,    -1,   292,   260,  1156,   295,    -1,    89,    -1,    91,
      -1,   789,    -1,   938,    96,   940,   941,   942,   943,   944,
     945,    -1,    -1,    -1,  1329,   109,  1516,    -1,    -1,  1334,
     112,  1336,    -1,    -1,   967,  1340,    -1,  1342,   307,    -1,
    1345,    -1,  1347,  1348,    -1,    -1,  1185,  1352,   132,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   307,
      -1,    -1,    89,    90,    -1,    92,    -1,    71,    72,   153,
    1375,   155,    76,    -1,   156,   452,    -1,  1382,    -1,    -1,
    1385,  1571,    -1,   352,   461,    -1,  1391,    -1,    -1,   171,
     172,    -1,   109,  1026,  1399,    -1,    -1,    -1,   533,   534,
     127,   536,    -1,    -1,   539,  1410,  1411,  1412,    -1,  1414,
    1600,  1416,    -1,  1265,  1266,   132,  1421,   144,  1423,   123,
      -1,  1611,  1427,   392,    -1,   209,   395,   396,  1433,   398,
      -1,   909,   159,    -1,  1439,   139,   153,  1442,   155,    -1,
     918,   919,  1067,  1068,   392,    -1,   924,   395,   396,    -1,
     398,    -1,    -1,  1458,    -1,    -1,   238,   935,   162,   672,
      -1,   939,   675,    -1,   246,   678,    -1,    -1,   946,   682,
    1322,  1323,   607,    -1,    -1,    -1,    -1,    -1,    -1,   614,
     262,    -1,    -1,    -1,  1489,    -1,    -1,    -1,  1493,  1494,
      -1,  1496,   209,    -1,   278,   630,    -1,    -1,    -1,   281,
      -1,  1353,  1354,    -1,    -1,   640,   641,   289,  1513,   291,
    1515,   238,   239,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1527,    -1,  1157,    -1,    -1,    -1,  1533,    -1,
      -1,    -1,  1384,   746,  1386,    -1,   505,    -1,    -1,    -1,
      -1,   510,    80,    81,    -1,    -1,  1551,    -1,  1181,  1554,
      88,    89,    -1,  1558,   281,    -1,    94,   505,    -1,    -1,
      -1,   278,   510,    -1,    -1,    -1,  1405,  1406,   295,   538,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,   295,  1584,
      -1,  1586,   120,   478,    -1,   480,   481,    -1,   483,    -1,
     538,  1596,   727,  1598,    -1,    -1,    -1,   135,    -1,  1604,
      -1,  1606,    -1,    -1,   142,  1610,  1611,    -1,    80,    81,
      -1,  1616,    -1,    -1,    -1,    -1,    88,    89,  1623,    -1,
     515,    -1,    94,  1101,    -1,    -1,   521,    -1,    -1,    -1,
     525,    -1,    -1,   528,    -1,   530,    71,    72,    67,    -1,
      69,    76,    -1,    35,    36,    37,    38,    -1,   120,    -1,
     619,    43,    44,    45,    46,   624,    -1,    -1,   627,    -1,
      -1,    -1,   631,   135,    -1,    -1,    -1,    -1,   637,    -1,
    1522,   619,   101,   102,   103,    -1,   624,   646,  1156,   627,
     218,    -1,  1160,   631,    -1,    -1,    82,    -1,   123,   637,
      -1,    -1,    -1,    89,    90,    -1,    -1,    -1,   646,    -1,
     238,    -1,   131,   672,   139,    -1,   675,   676,    -1,   678,
      -1,   680,    -1,   682,   927,   684,    -1,   930,    -1,    -1,
     689,   934,    -1,    -1,   672,    -1,    -1,   162,   676,    -1,
     268,   127,   680,    -1,    -1,    -1,   684,    -1,    -1,    -1,
     136,   689,   711,   281,    -1,    -1,   218,    -1,   144,    -1,
     288,   720,    -1,    -1,   723,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,   711,    -1,   842,   238,   844,   845,    -1,
     847,    -1,   720,    -1,    -1,   723,    -1,   746,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1265,  1266,    -1,
      -1,    -1,   188,    -1,   190,   224,   268,  1275,   746,   478,
      -1,   480,   481,    -1,   483,    -1,   202,    -1,    -1,   281,
      -1,    11,    12,    13,    -1,   211,   288,    -1,    -1,   254,
      -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,  1461,    29,
      30,    31,    -1,    -1,    -1,   231,   515,  1050,    -1,    -1,
      -1,    -1,   521,   920,  1322,  1323,   525,    -1,    -1,   528,
      -1,   530,    -1,    -1,   250,    -1,   252,    -1,    58,    59,
      60,   938,    -1,   940,   941,   942,   943,   944,   945,    -1,
      -1,    -1,    -1,    -1,    -1,   271,  1354,    -1,    -1,   308,
      -1,    -1,    -1,    -1,  1097,   281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1107,    -1,    -1,   293,   867,   295,
    1113,    -1,    -1,    89,  1117,    -1,  1384,     8,  1386,   878,
      -1,    -1,    -1,  1546,  1547,  1393,    -1,    18,    -1,   867,
      -1,    -1,    -1,    24,   353,   354,    -1,    28,    -1,    -1,
     878,    32,    -1,   119,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,   128,   129,    -1,    -1,   915,   133,   134,    -1,
      51,    52,    53,    -1,  1587,    -1,    -1,    -1,   927,    -1,
      -1,   930,    -1,    -1,   933,   934,   152,   915,   154,    -1,
      -1,    -1,  1450,    -1,    -1,    -1,    -1,    -1,    -1,   927,
      -1,    -1,   930,    -1,    -1,   933,   934,    -1,    -1,    -1,
    1067,  1068,    -1,    -1,    -1,    -1,    -1,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,  1221,    -1,
      -1,   197,   198,    -1,    -1,    -1,  1229,    -1,    -1,  1232,
      -1,   207,   208,   452,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    15,    16,    17,  1522,    19,  1524,    21,    22,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,   244,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      54,  1050,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,    -1,    -1,
      -1,    -1,  1050,    -1,    -1,    -1,    -1,    -1,    -1,   295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1334,    -1,  1336,    -1,    -1,    -1,  1340,  1097,  1342,
      -1,  1100,  1345,    -1,  1347,    -1,    -1,    -1,  1107,    -1,
      -1,    -1,    -1,    -1,  1113,    -1,    -1,  1116,  1117,  1097,
      -1,    -1,  1100,    -1,    -1,  1124,    -1,    -1,    -1,  1107,
      -1,    -1,    -1,    -1,    -1,  1113,    -1,    -1,  1116,  1117,
      -1,    -1,    -1,    -1,    -1,    -1,  1124,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1182,   531,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,   540,   541,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1458,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1229,    -1,    -1,  1232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1229,    -1,    -1,  1232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   842,    -1,   844,   845,    -1,   847,    -1,
      -1,    -1,  1391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1391,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,
      -1,   920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,
    1458,   940,   941,   942,   943,   944,   945,    -1,    -1,    -1,
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
      -1,    -1,  1051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1067,  1068
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   116,   298,     3,   187,   245,   300,   549,   551,   663,
     764,     0,   550,   764,   549,   664,   764,   118,   302,   111,
     295,   297,   395,     6,   261,   665,   695,   765,     4,   766,
     117,   301,   131,   396,   423,   426,   549,   552,   764,   698,
     765,   297,   766,   766,   161,   488,   423,   427,   158,   397,
     483,   297,   395,   766,   297,   160,   487,   489,   299,    80,
      81,    88,    89,    94,   120,   135,   218,   238,   268,   281,
     288,   297,   333,   334,   349,   350,   359,   407,   439,   609,
     650,   711,   737,   754,    11,    12,    13,    29,    30,    31,
      58,    59,    60,   484,   205,   398,   587,   297,   766,   297,
     350,   107,   124,   163,   258,   297,   350,   384,   416,   495,
     690,   737,   766,   766,   115,   670,   766,   351,    20,    50,
      57,   360,    20,    50,    57,   408,   766,   766,   551,   652,
     766,   738,   764,   126,   275,   332,   419,   728,   297,    35,
      36,    37,    38,    43,    44,    45,    46,   588,   206,   399,
     589,   297,   388,   551,   493,   551,   493,   691,   766,   297,
     766,   670,   297,   765,   297,   297,   766,   297,    77,   149,
     182,   199,   222,   260,   327,   468,   538,   576,   614,   651,
     696,   729,   297,     5,   297,   445,   764,   765,   766,   767,
     297,   297,   297,   297,   241,   620,   297,    84,   339,   385,
     301,   301,   294,   297,   350,   737,   762,   327,   766,   670,
     327,   328,   469,   539,   577,   615,   697,   210,   279,   297,
     350,   596,   650,   734,   446,   766,   297,   341,   552,   297,
     350,   650,   690,   737,   267,   417,   709,   496,   709,   270,
     715,   763,   297,   297,   297,   297,    78,   297,   327,   329,
     332,   150,   297,   466,   468,   766,   183,   184,   297,   538,
     540,   542,   543,   670,   201,   297,   576,   578,   670,   223,
     297,   614,   616,   620,   297,   695,   696,   765,   765,     7,
      10,    14,    15,    16,    17,    19,    21,    22,    25,    33,
      42,    48,    54,    56,    61,   735,   295,   445,   764,   765,
     766,   766,   164,   340,   497,   200,   580,   710,    83,   297,
     336,   350,   690,   737,   297,   336,   350,   690,   737,   766,
      73,    99,   237,   297,   320,   350,   368,   646,   650,   737,
     330,   332,   467,   766,   541,   542,   276,   277,   544,   670,
     730,   731,   579,   670,   617,   620,   297,   297,   297,   494,
     552,   297,   581,   125,   129,   220,   253,   297,   350,   389,
     418,   420,   680,   737,   338,   551,   766,   765,   765,   765,
     297,   395,   297,   395,   297,   395,   297,   297,   544,   297,
     395,   297,   395,   297,   140,   247,   297,   350,   449,   669,
     491,   551,   421,   422,   551,   390,   681,    85,   337,   342,
     766,   297,   282,   369,   741,   647,   741,   544,   670,   670,
     423,   142,   297,   333,   334,   349,   350,   359,   407,   439,
     451,   609,   650,   711,   737,   754,   119,   128,   133,   134,
     152,   154,   197,   198,   207,   208,   244,   297,   350,   405,
     420,   432,   435,   437,   472,   476,   572,   574,   590,   592,
     661,   737,   177,   297,   350,   526,   737,    23,    49,    55,
     343,   283,   285,   297,   350,   650,   690,   737,   742,   746,
     766,   765,   297,   297,   297,   670,   670,   297,   109,   132,
     153,   155,   209,   278,   391,   428,   434,   452,   474,   478,
     594,   732,   551,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   516,   527,   551,   297,   551,   748,
     747,   766,   297,   297,   734,   392,   428,   434,   423,   428,
     434,   475,   428,   434,   479,   766,   428,   434,   733,   297,
     130,   424,   424,   424,   424,   424,   424,   424,   573,   424,
     424,   424,   424,    79,    91,    96,   112,   156,   171,   172,
     246,   262,   289,   291,   297,   331,   350,   354,   363,   400,
     480,   512,   514,   650,   666,   699,   737,   755,   757,   287,
     752,   145,   147,   189,   193,   227,   235,   297,   350,   458,
     462,   555,   563,   625,   640,   737,   766,   297,   297,   428,
     434,   429,   497,   297,   428,   434,   297,   428,   434,   595,
     297,   428,   434,   423,   425,   428,   434,   424,    71,    72,
      76,   123,   139,   162,   254,   318,   319,   324,   415,   433,
     448,   492,   656,   682,   436,   656,   682,   438,   656,   682,
     424,   477,   656,   682,   297,   350,   737,   575,   656,   682,
     424,   424,   185,   242,   545,   657,   662,   332,   517,   552,
     542,   401,   297,   513,   515,   667,   517,   542,   517,     8,
      18,    24,    28,    32,    39,    41,    51,    52,    53,   753,
     151,   470,   743,   148,   456,   459,   463,   194,   556,   567,
     564,   236,   626,   644,   641,   297,   297,   359,   297,   406,
     656,   682,   670,   670,   318,   325,   448,   670,   670,   670,
     656,   683,   297,   350,   737,   297,   350,   737,   297,   350,
     737,   473,   656,   682,   297,   350,   737,   297,   350,   737,
     591,   656,   682,   593,   656,   682,   546,   658,   297,   350,
     737,   297,   297,   297,   297,   517,   297,   517,   297,   517,
     297,   517,   297,   297,   297,   297,   471,    93,   297,   350,
     355,   650,   690,   737,   181,   465,   536,   552,   108,   271,
     297,   350,   386,   650,   716,   146,   297,   350,   456,   460,
     737,   536,   552,   566,    95,   191,   297,   350,   361,   559,
     650,   192,   297,   350,   561,   567,   737,   536,   552,   643,
      62,   100,   101,   102,   103,   229,   297,   303,   350,   370,
     372,   374,   376,   386,   629,   650,   230,   297,   350,   631,
     644,   737,   297,   297,   350,   737,   297,   297,   319,   326,
     492,   297,   297,   297,   297,   297,   350,   737,   297,   350,
     737,   297,   350,   737,   297,   657,   297,   656,   682,    69,
     157,   186,   213,   219,   226,   228,   240,   252,   263,   292,
     297,   315,   350,   386,   481,   547,   602,   610,   623,   627,
     650,   654,   678,   700,   716,   737,   758,   356,   552,   286,
     456,   457,   750,   387,   695,   765,   106,   382,   717,   461,
     456,   567,   568,   750,   362,   466,   766,   382,   562,   456,
     644,   645,   750,   304,   540,   542,   371,   578,   670,   373,
     578,   670,   375,   578,   670,   377,   578,   670,   382,   632,
     297,    68,    70,    74,   314,   316,   317,   321,   482,   548,
      67,   312,   551,   739,   611,   312,   551,   624,   642,   642,
     655,   551,   677,   679,   701,   759,    82,    90,   127,   136,
     144,   175,   188,   190,   202,   211,   231,   250,   293,   297,
     335,   350,   352,   430,   440,   454,   522,   553,   557,   582,
     597,   633,   673,   678,   716,   737,   760,   537,   766,   552,
     749,   297,   297,     9,    34,    47,   383,   137,   217,   297,
     350,   443,   607,   737,   297,   456,   297,   297,   104,   378,
     560,   297,   566,   567,   297,   297,   297,   297,   297,   297,
     167,   378,   502,   630,   297,   643,   644,   221,   612,   256,
     686,   297,   297,   350,   737,   138,   233,   297,   447,   637,
     644,   297,   481,   637,   644,   758,   551,   729,   196,   297,
     570,   610,   644,   110,   280,   297,   303,   350,   370,   372,
     374,   376,   386,   393,   629,   650,   736,   737,   166,   500,
     628,   159,   215,   239,   297,   335,   350,   352,   430,   454,
     485,   600,   633,   648,   650,   737,    65,   234,   290,   297,
     309,   350,   639,   737,   756,    64,   212,   297,   307,   335,
     350,   352,   430,   454,   485,   599,   600,   633,   648,   650,
     737,   297,   481,   637,   644,   243,   659,   353,   422,   426,
     431,   441,   643,   644,   312,   464,   551,   523,   642,   312,
     551,   565,   565,   583,   642,   464,   598,   634,   643,   644,
     674,   765,   274,   726,   761,   297,   766,   339,   751,   297,
     269,   444,   712,   378,   608,   379,   540,   542,    75,   273,
     297,   322,   724,   503,   540,   542,   297,   322,   724,   613,
     297,   264,   687,   702,   297,   643,   638,   766,   603,   734,
     571,    26,    27,    40,   394,   297,   501,   297,   350,   650,
     737,   486,   490,   764,   536,   552,   601,   740,   552,   649,
     653,    98,   310,   366,   642,   516,   308,   695,   765,   659,
     620,   297,   297,   307,   335,   350,   430,   454,   650,   737,
      87,   113,   204,   216,   225,   251,   297,   347,   350,   402,
     585,   605,   621,   659,   675,   737,   265,   442,   644,   704,
     284,   455,   744,   750,   297,   350,   650,   737,   481,   554,
     165,   498,   558,   297,   350,   650,   736,   737,   297,   335,
     350,   352,   454,   553,   557,   599,   633,   737,    92,   297,
     350,   352,   357,   430,   454,   485,   648,   650,   737,   297,
     454,   673,   765,   727,    63,   168,   179,   297,   305,   350,
     440,   504,   530,   737,   297,   122,   203,   413,   584,   713,
     297,   413,   297,   413,   297,   170,   173,   323,   510,   517,
     518,   510,   517,   518,   725,   503,   257,   297,   688,   703,
     297,   297,   297,   643,   644,   313,   766,   297,   297,   610,
     644,   297,   297,   623,   627,   297,   395,   297,   395,   297,
     395,   766,   169,   174,   297,   350,   508,   520,   737,   637,
     670,   297,   297,   620,   660,   620,   403,   620,    97,   364,
     586,   224,   606,   618,   618,   622,   364,   676,   705,   297,
     378,   502,   745,   214,   232,   272,   297,   350,   386,   604,
     635,   650,   716,   718,   737,   297,   350,   352,   361,   430,
     454,   553,   559,   650,   737,   499,   297,   350,   352,   430,
     650,   737,   358,   430,    86,   143,   259,   297,   344,   453,
     692,   306,   542,   505,   643,   644,   531,   643,   644,   414,
     561,   567,   631,   637,   644,   413,   114,   404,   413,   584,
     714,   511,   519,   297,   725,   297,   689,   702,   297,   718,
     297,   367,   404,   509,   637,   643,   644,   521,   637,   643,
     644,   297,   178,   528,   297,   650,   620,   297,   650,   365,
     297,   650,   619,   297,   650,   297,   650,   297,   650,   121,
     266,   297,   409,   706,   297,   744,   750,   740,   636,   643,
     644,   248,   671,   719,   297,   553,   297,   345,   637,   643,
     644,   297,   637,   643,   644,   693,   297,   350,   440,   504,
     530,   737,   176,   506,   524,   644,   704,   378,   502,   532,
     297,   322,   724,   670,   670,   297,   141,   297,   450,   517,
     518,   297,   510,   517,   297,   255,   297,   684,   297,   297,
     528,   297,   528,   529,   297,   348,    66,   297,   311,   620,
     297,   620,   180,   344,   410,   533,   692,   195,   524,   569,
     644,   704,   707,   729,   297,   303,   350,   370,   372,   374,
     376,   386,   629,   650,   736,   737,   766,   249,   672,   720,
     322,   346,   724,   404,   694,   517,   378,   502,   507,   297,
     297,   297,   297,   750,   297,   450,   510,   517,   518,   297,
     650,   620,   534,   637,   643,   644,   411,   524,   569,   644,
     704,   297,   378,   502,   708,   297,   766,   766,   105,   380,
     721,   297,   297,   322,   724,   497,   525,   297,   685,   718,
     620,   510,   517,   518,   535,   378,   412,   502,   297,   297,
     766,   381,   587,   722,   297,   297,   620,   297,   297,   297,
     297,   620,   589,   723,   297,   297
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
        case 2:
#line 506 "edif.y"
    { PopC(); }
    break;

  case 11:
#line 521 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 12:
#line 524 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 13:
#line 528 "edif.y"
    { free((yyvsp[(2) - (5)].s)); free((yyvsp[(3) - (5)].s)); free((yyvsp[(4) - (5)].s)); }
    break;

  case 25:
#line 552 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 34:
#line 569 "edif.y"
    { str_pair_free((yyvsp[(2) - (5)].ps)); free((yyvsp[(3) - (5)].s)); }
    break;

  case 36:
#line 573 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 47:
#line 598 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 69:
#line 646 "edif.y"
    { free((yyvsp[(2) - (5)].s)); free((yyvsp[(3) - (5)].s)); }
    break;

  case 70:
#line 649 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 80:
#line 667 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 84:
#line 677 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 91:
#line 692 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 102:
#line 715 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 140:
#line 775 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 147:
#line 790 "edif.y"
    { free((yyvsp[(2) - (4)].s)); }
    break;

  case 150:
#line 797 "edif.y"
    { free((yyvsp[(2) - (4)].s)); }
    break;

  case 182:
#line 867 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 184:
#line 871 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 240:
#line 975 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 247:
#line 988 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 278:
#line 1035 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 279:
#line 1038 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 333:
#line 1124 "edif.y"
    { free((yyvsp[(2) - (5)].s)); free((yyvsp[(3) - (5)].s)); }
    break;

  case 336:
#line 1131 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 337:
#line 1134 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 344:
#line 1147 "edif.y"
    { free((yyvsp[(1) - (3)].s)); }
    break;

  case 346:
#line 1151 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 347:
#line 1152 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 348:
#line 1153 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 369:
#line 1194 "edif.y"
    { (yyval.s)=(yyvsp[(2) - (4)].s); }
    break;

  case 371:
#line 1198 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 374:
#line 1205 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 381:
#line 1216 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 384:
#line 1223 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 388:
#line 1229 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 390:
#line 1233 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 393:
#line 1240 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 397:
#line 1248 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 408:
#line 1263 "edif.y"
    { pair_list_free((yyvsp[(2) - (2)].pl)); }
    break;

  case 437:
#line 1313 "edif.y"
    { (yyval.pl) = new_pair_list((yyvsp[(2) - (3)].ps)); }
    break;

  case 438:
#line 1316 "edif.y"
    { (yyval.ps)=NULL; }
    break;

  case 439:
#line 1317 "edif.y"
    { (yyvsp[(2) - (2)].ps)->next = (yyvsp[(1) - (2)].ps); (yyval.ps) = (yyvsp[(2) - (2)].ps); }
    break;

  case 455:
#line 1343 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 459:
#line 1353 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 460:
#line 1356 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 462:
#line 1362 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 463:
#line 1365 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 483:
#line 1407 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 484:
#line 1410 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 492:
#line 1424 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 506:
#line 1452 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 507:
#line 1455 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 514:
#line 1470 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 549:
#line 1525 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 555:
#line 1537 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 560:
#line 1546 "edif.y"
    { free((yyvsp[(2) - (4)].s)); }
    break;

  case 561:
#line 1549 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 562:
#line 1550 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 582:
#line 1592 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 585:
#line 1595 "edif.y"
    { pair_list_free((yyvsp[(2) - (2)].pl)); }
    break;

  case 586:
#line 1598 "edif.y"
    { (yyval.s)=(yyvsp[(2) - (3)].s); }
    break;

  case 587:
#line 1601 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 589:
#line 1605 "edif.y"
    { (yyval.ps) = new_str_pair((yyvsp[(1) - (1)].s),NULL); }
    break;

  case 590:
#line 1606 "edif.y"
    { (yyval.ps) = new_str_pair((yyvsp[(1) - (1)].s),NULL); }
    break;

  case 591:
#line 1607 "edif.y"
    { (yyval.ps)=(yyvsp[(1) - (1)].ps); }
    break;

  case 592:
#line 1610 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 593:
#line 1611 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 594:
#line 1614 "edif.y"
    { define_pcb_net((yyvsp[(2) - (4)].ps), (yyvsp[(3) - (4)].pl)); }
    break;

  case 595:
#line 1617 "edif.y"
    { (yyval.pl)=(yyvsp[(1) - (1)].pl); }
    break;

  case 611:
#line 1639 "edif.y"
    { str_pair_free((yyvsp[(2) - (4)].ps)); }
    break;

  case 632:
#line 1676 "edif.y"
    { (yyval.ps)=(yyvsp[(1) - (1)].ps); }
    break;

  case 633:
#line 1677 "edif.y"
    { (yyval.ps)=NULL; }
    break;

  case 634:
#line 1681 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 639:
#line 1690 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 644:
#line 1701 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 698:
#line 1803 "edif.y"
    { free((yyvsp[(2) - (5)].s)); }
    break;

  case 701:
#line 1810 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 727:
#line 1862 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 730:
#line 1869 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 747:
#line 1904 "edif.y"
    { free((yyvsp[(2) - (4)].s)); free((yyvsp[(3) - (4)].s)); }
    break;

  case 766:
#line 1935 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 789:
#line 1970 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 791:
#line 1976 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 803:
#line 1992 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 818:
#line 2011 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 823:
#line 2022 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 827:
#line 2028 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 829:
#line 2032 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 831:
#line 2037 "edif.y"
    { 
    if ((yyvsp[(3) - (4)].ps))
    {
	(yyval.ps) = new_str_pair((yyvsp[(3) - (4)].ps)->str1,(yyvsp[(2) - (4)].s));
	free((yyvsp[(3) - (4)].ps));
    }
    else 
    {
	/* handle port with no instance by passing up the chain */
	(yyval.ps) = new_str_pair(NULL,(yyvsp[(2) - (4)].s));
    }
}
    break;

  case 832:
#line 2051 "edif.y"
    { (yyval.ps)=NULL; }
    break;

  case 833:
#line 2052 "edif.y"
    { (yyval.ps)=(yyvsp[(1) - (1)].ps); }
    break;

  case 834:
#line 2053 "edif.y"
    { (yyval.ps) = new_str_pair((yyvsp[(1) - (1)].s),NULL); }
    break;

  case 835:
#line 2054 "edif.y"
    { (yyval.ps)=NULL; }
    break;

  case 848:
#line 2081 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 849:
#line 2084 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 881:
#line 2137 "edif.y"
    { (yyval.ps) = new_str_pair((yyvsp[(2) - (4)].s),(yyvsp[(3) - (4)].s)); }
    break;

  case 882:
#line 2140 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 883:
#line 2141 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 884:
#line 2144 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 885:
#line 2145 "edif.y"
    { (yyval.s)=NULL; }
    break;

  case 889:
#line 2155 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 891:
#line 2161 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 892:
#line 2162 "edif.y"
    { free((yyvsp[(2) - (4)].s)); free((yyvsp[(3) - (4)].s)); }
    break;

  case 893:
#line 2165 "edif.y"
    { free((yyvsp[(2) - (4)].s)); free((yyvsp[(3) - (4)].s)); }
    break;

  case 894:
#line 2168 "edif.y"
    { free((yyvsp[(2) - (4)].s)); free((yyvsp[(3) - (4)].s)); }
    break;

  case 896:
#line 2174 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 898:
#line 2176 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 903:
#line 2187 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 935:
#line 2251 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 943:
#line 2267 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 946:
#line 2272 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 973:
#line 2317 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 987:
#line 2339 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 994:
#line 2355 "edif.y"
    { free((yyvsp[(2) - (8)].s)); free((yyvsp[(3) - (8)].s)); free((yyvsp[(4) - (8)].s)); free((yyvsp[(5) - (8)].s)); free((yyvsp[(6) - (8)].s)); free((yyvsp[(7) - (8)].s)); }
    break;

  case 1054:
#line 2462 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 1055:
#line 2463 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 1056:
#line 2464 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 1057:
#line 2465 "edif.y"
    { free((yyvsp[(2) - (2)].s)); }
    break;

  case 1059:
#line 2469 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 1061:
#line 2473 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 1063:
#line 2477 "edif.y"
    { free((yyvsp[(2) - (3)].s)); }
    break;

  case 1085:
#line 2513 "edif.y"
    { str_pair_free((yyvsp[(1) - (1)].ps)); }
    break;

  case 1086:
#line 2516 "edif.y"
    { free((yyvsp[(1) - (1)].s)); }
    break;

  case 1107:
#line 2557 "edif.y"
    { str_pair_free((yyvsp[(2) - (2)].ps)); }
    break;

  case 1109:
#line 2559 "edif.y"
    { pair_list_free((yyvsp[(2) - (2)].pl)); }
    break;

  case 1126:
#line 2586 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 1127:
#line 2589 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 1128:
#line 2592 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;

  case 1129:
#line 2595 "edif.y"
    { (yyval.s)=(yyvsp[(1) - (1)].s); }
    break;


/* Line 1267 of yacc.c.  */
#line 4858 "edif.c"
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


#line 2598 "edif.y"

/*
 *	xmalloc:
 *
 *	  Garbage function for 'alloca()'.
 */
char *xmalloc(siz)
int siz;
{
  return (Malloc(siz));
}
/*
 *	Token & context carriers:
 *
 *	  These are the linkage pointers for threading this context garbage
 *	for converting identifiers into parser tokens.
 */
typedef struct TokenCar {
  struct TokenCar *Next;	/* pointer to next carrier */
  struct Token *Token;		/* associated token */
} TokenCar;
typedef struct UsedCar {
  struct UsedCar *Next;		/* pointer to next carrier */
  short Code;			/* used '%token' value */
} UsedCar;
typedef struct ContextCar {
  struct ContextCar *Next;	/* pointer to next carrier */
  struct Context *Context;	/* associated context */
  union {
    int Single;			/* single usage flag (context tree) */
    struct UsedCar *Used;	/* single used list (context stack) */
  } u;
} ContextCar;
/*
 *	Token definitions:
 *
 *	  This associates the '%token' codings with strings which are to
 *	be free standing tokens. Doesn't have to be in sorted order but the
 *	strings must be in lower case.
 */
typedef struct Token {
  char *Name;			/* token name */
  int Code;			/* '%token' value */
  struct Token *Next;		/* hash table linkage */
} Token;
static Token TokenDef[] = {
  {"angle",		EDIF_TOK_ANGLE},
  {"behavior",		EDIF_TOK_BEHAVIOR},
  {"calculated",	EDIF_TOK_CALCULATED},
  {"capacitance",	EDIF_TOK_CAPACITANCE},
  {"centercenter",	EDIF_TOK_CENTERCENTER},
  {"centerleft",	EDIF_TOK_CENTERLEFT},
  {"centerright",	EDIF_TOK_CENTERRIGHT},
  {"charge",		EDIF_TOK_CHARGE},
  {"conductance",	EDIF_TOK_CONDUCTANCE},
  {"current",		EDIF_TOK_CURRENT},
  {"distance",		EDIF_TOK_DISTANCE},
  {"document",		EDIF_TOK_DOCUMENT},
  {"energy",		EDIF_TOK_ENERGY},
  {"extend",		EDIF_TOK_EXTEND},
  {"flux",		EDIF_TOK_FLUX},
  {"frequency",		EDIF_TOK_FREQUENCY},
  {"generic",		EDIF_TOK_GENERIC},
  {"graphic",		EDIF_TOK_GRAPHIC},
  {"inductance",	EDIF_TOK_INDUCTANCE},
  {"inout",		EDIF_TOK_INOUT},
  {"input",		EDIF_TOK_INPUT},
  {"logicmodel",	EDIF_TOK_LOGICMODEL},
  {"lowercenter",	EDIF_TOK_LOWERCENTER},
  {"lowerleft",		EDIF_TOK_LOWERLEFT},
  {"lowerright",	EDIF_TOK_LOWERRIGHT},
  {"masklayout",	EDIF_TOK_MASKLAYOUT},
  {"mass",		EDIF_TOK_MASS},
  {"measured",		EDIF_TOK_MEASURED},
  {"mx",		EDIF_TOK_MX},
  {"mxr90",		EDIF_TOK_MXR90},
  {"my",		EDIF_TOK_MY},
  {"myr90",		EDIF_TOK_MYR90},
  {"netlist",		EDIF_TOK_NETLIST},
  {"output",		EDIF_TOK_OUTPUT},
  {"pcblayout",		EDIF_TOK_PCBLAYOUT},
  {"power",		EDIF_TOK_POWER},
  {"r0",		EDIF_TOK_R0},
  {"r180",		EDIF_TOK_R180},
  {"r270",		EDIF_TOK_R270},
  {"r90",		EDIF_TOK_R90},
  {"required",		EDIF_TOK_REQUIRED},
  {"resistance",	EDIF_TOK_RESISTANCE},
  {"ripper",		EDIF_TOK_RIPPER},
  {"round",		EDIF_TOK_ROUND},
  {"schematic",		EDIF_TOK_SCHEMATIC},
  {"stranger",		EDIF_TOK_STRANGER},
  {"symbolic",		EDIF_TOK_SYMBOLIC},
  {"temperature",	EDIF_TOK_TEMPERATURE},
  {"tie",		EDIF_TOK_TIE},
  {"time",		EDIF_TOK_TIME},
  {"truncate",		EDIF_TOK_TRUNCATE},
  {"uppercenter",	EDIF_TOK_UPPERCENTER},
  {"upperleft",		EDIF_TOK_UPPERLEFT},
  {"upperright",	EDIF_TOK_UPPERRIGHT},
  {"voltage",		EDIF_TOK_VOLTAGE}
};
static int TokenDefSize = sizeof(TokenDef) / sizeof(Token);
/*
 *	Token enable definitions:
 *
 *	  There is one array for each set of tokens enabled by a
 *	particular context (barf). Another array is used to bind
 *	these arrays to a context.
 */
static short e_CellType[] = {EDIF_TOK_TIE, EDIF_TOK_RIPPER, EDIF_TOK_GENERIC};
static short e_CornerType[] = {EDIF_TOK_EXTEND, EDIF_TOK_TRUNCATE,
			       EDIF_TOK_ROUND};
static short e_Derivation[] = {EDIF_TOK_CALCULATED, EDIF_TOK_MEASURED,
			       EDIF_TOK_REQUIRED};
static short e_Direction[] = {EDIF_TOK_INPUT, EDIF_TOK_OUTPUT,
			      EDIF_TOK_INOUT};
static short e_EndType[] = {EDIF_TOK_EXTEND, EDIF_TOK_TRUNCATE,
			    EDIF_TOK_ROUND};
static short e_Justify[] = {EDIF_TOK_CENTERCENTER, EDIF_TOK_CENTERLEFT,
			    EDIF_TOK_CENTERRIGHT, EDIF_TOK_LOWERCENTER,
			    EDIF_TOK_LOWERLEFT, EDIF_TOK_LOWERRIGHT,
			    EDIF_TOK_UPPERCENTER, EDIF_TOK_UPPERLEFT,
			    EDIF_TOK_UPPERRIGHT};
static short e_Orientation[] = {EDIF_TOK_R0, EDIF_TOK_R90, EDIF_TOK_R180,
				EDIF_TOK_R270, EDIF_TOK_MX, EDIF_TOK_MY,
				EDIF_TOK_MXR90, EDIF_TOK_MYR90};
static short e_Unit[] = {EDIF_TOK_DISTANCE, EDIF_TOK_CAPACITANCE,
			 EDIF_TOK_CURRENT, EDIF_TOK_RESISTANCE,
			 EDIF_TOK_TEMPERATURE, EDIF_TOK_TIME,
			 EDIF_TOK_VOLTAGE, EDIF_TOK_MASS, EDIF_TOK_FREQUENCY,
			 EDIF_TOK_INDUCTANCE, EDIF_TOK_ENERGY,
			 EDIF_TOK_POWER, EDIF_TOK_CHARGE,
			 EDIF_TOK_CONDUCTANCE, EDIF_TOK_FLUX, EDIF_TOK_ANGLE};
static short e_ViewType[] = {EDIF_TOK_MASKLAYOUT, EDIF_TOK_PCBLAYOUT,
			     EDIF_TOK_NETLIST, EDIF_TOK_SCHEMATIC,
			     EDIF_TOK_SYMBOLIC, EDIF_TOK_BEHAVIOR,
			     EDIF_TOK_LOGICMODEL, EDIF_TOK_DOCUMENT,
			     EDIF_TOK_GRAPHIC, EDIF_TOK_STRANGER};
/*
 *	Token tying table:
 *
 *	  This binds enabled tokens to a context.
 */
typedef struct Tie {
  short *Enable;		/* pointer to enable array */
  short Origin;			/* '%token' value of context */
  short EnableSize;		/* size of enabled array */
} Tie;
#define	TE(e,o)			{e,o,sizeof(e)/sizeof(short)}
static Tie TieDef[] = {
  TE(e_CellType,	EDIF_TOK_CELLTYPE),
  TE(e_CornerType,	EDIF_TOK_CORNERTYPE),
  TE(e_Derivation,	EDIF_TOK_DERIVATION),
  TE(e_Direction,	EDIF_TOK_DIRECTION),
  TE(e_EndType,		EDIF_TOK_ENDTYPE),
  TE(e_Justify,		EDIF_TOK_JUSTIFY),
  TE(e_Orientation,	EDIF_TOK_ORIENTATION),
  TE(e_Unit,		EDIF_TOK_UNIT),
  TE(e_ViewType,	EDIF_TOK_VIEWTYPE)
};
static int TieDefSize = sizeof(TieDef) / sizeof(Tie);
/*
 *	Context definitions:
 *
 *	  This associates keyword strings with '%token' values. It
 *	also creates a pretty much empty header for later building of
 *	the context tree. Again they needn't be sorted, but strings
 *	must be lower case.
 */
typedef struct Context {
  char *Name;			/* keyword name */
  short Code;			/* '%token' value */
  short Flags;			/* special operation flags */
  struct ContextCar *Context;	/* contexts which can be moved to */
  struct TokenCar *Token;	/* active tokens */
  struct Context *Next;		/* hash table linkage */
} Context;
static Context ContextDef[] = {
  {"",				0},		/* start context */
  {"acload",			EDIF_TOK_ACLOAD},
  {"after",			EDIF_TOK_AFTER},
  {"annotate",			EDIF_TOK_ANNOTATE},
  {"apply",			EDIF_TOK_APPLY},
  {"arc",			EDIF_TOK_ARC},
  {"array",			EDIF_TOK_ARRAY},
  {"arraymacro",		EDIF_TOK_ARRAYMACRO},
  {"arrayrelatedinfo",		EDIF_TOK_ARRAYRELATEDINFO},
  {"arraysite",			EDIF_TOK_ARRAYSITE},
  {"atleast",			EDIF_TOK_ATLEAST},
  {"atmost",			EDIF_TOK_ATMOST},
  {"author",			EDIF_TOK_AUTHOR},
  {"basearray",			EDIF_TOK_BASEARRAY},
  {"becomes",			EDIF_TOK_BECOMES},
  {"between",			EDIF_TOK_BETWEEN},
  {"boolean",			EDIF_TOK_BOOLEAN},
  {"booleandisplay",		EDIF_TOK_BOOLEANDISPLAY},
  {"booleanmap",		EDIF_TOK_BOOLEANMAP},
  {"borderpattern",		EDIF_TOK_BORDERPATTERN},
  {"borderwidth",		EDIF_TOK_BORDERWIDTH},
  {"boundingbox",		EDIF_TOK_BOUNDINGBOX},
  {"cell",			EDIF_TOK_CELL},
  {"cellref",			EDIF_TOK_CELLREF},
  {"celltype",			EDIF_TOK_CELLTYPE},
  {"change",			EDIF_TOK_CHANGE},
  {"circle",			EDIF_TOK_CIRCLE},
  {"color",			EDIF_TOK_COLOR},
  {"comment",			EDIF_TOK_COMMENT},
  {"commentgraphics",		EDIF_TOK_COMMENTGRAPHICS},
  {"compound",			EDIF_TOK_COMPOUND},
  {"connectlocation",		EDIF_TOK_CONNECTLOCATION},
  {"contents",			EDIF_TOK_CONTENTS},
  {"cornertype",		EDIF_TOK_CORNERTYPE},
  {"criticality",		EDIF_TOK_CRITICALITY},
  {"currentmap",		EDIF_TOK_CURRENTMAP},
  {"curve",			EDIF_TOK_CURVE},
  {"cycle",			EDIF_TOK_CYCLE},
  {"dataorigin",		EDIF_TOK_DATAORIGIN},
  {"dcfaninload",		EDIF_TOK_DCFANINLOAD},
  {"dcfanoutload",		EDIF_TOK_DCFANOUTLOAD},
  {"dcmaxfanin",		EDIF_TOK_DCMAXFANIN},
  {"dcmaxfanout",		EDIF_TOK_DCMAXFANOUT},
  {"delay",			EDIF_TOK_DELAY},
  {"delta",			EDIF_TOK_DELTA},
  {"derivation",		EDIF_TOK_DERIVATION},
  {"design",			EDIF_TOK_DESIGN},
  {"designator",		EDIF_TOK_DESIGNATOR},
  {"difference",		EDIF_TOK_DIFFERENCE},
  {"direction",			EDIF_TOK_DIRECTION},
  {"display",			EDIF_TOK_DISPLAY},
  {"dominates",			EDIF_TOK_DOMINATES},
  {"dot",			EDIF_TOK_DOT},
  {"duration",			EDIF_TOK_DURATION},
  {"e",				EDIF_TOK_E},
  {"edif",			EDIF_TOK_EDIF},
  {"ediflevel",			EDIF_TOK_EDIFLEVEL},
  {"edifversion",		EDIF_TOK_EDIFVERSION},
  {"enclosuredistance",		EDIF_TOK_ENCLOSUREDISTANCE},
  {"endtype",			EDIF_TOK_ENDTYPE},
  {"entry",			EDIF_TOK_ENTRY},
  {"exactly",			EDIF_TOK_EXACTLY},
  {"external",			EDIF_TOK_EXTERNAL},
  {"fabricate",			EDIF_TOK_FABRICATE},
  {"false",			EDIF_TOK_FALSE},
  {"figure",			EDIF_TOK_FIGURE},
  {"figurearea",		EDIF_TOK_FIGUREAREA},
  {"figuregroup",		EDIF_TOK_FIGUREGROUP},
  {"figuregroupobject",		EDIF_TOK_FIGUREGROUPOBJECT},
  {"figuregroupoverride",	EDIF_TOK_FIGUREGROUPOVERRIDE},
  {"figuregroupref",		EDIF_TOK_FIGUREGROUPREF},
  {"figureperimeter",		EDIF_TOK_FIGUREPERIMETER},
  {"figurewidth",		EDIF_TOK_FIGUREWIDTH},
  {"fillpattern",		EDIF_TOK_FILLPATTERN},
  {"follow",			EDIF_TOK_FOLLOW},
  {"forbiddenevent",		EDIF_TOK_FORBIDDENEVENT},
  {"globalportref",		EDIF_TOK_GLOBALPORTREF},
  {"greaterthan",		EDIF_TOK_GREATERTHAN},
  {"gridmap",			EDIF_TOK_GRIDMAP},
  {"ignore",			EDIF_TOK_IGNORE},
  {"includefiguregroup",	EDIF_TOK_INCLUDEFIGUREGROUP},
  {"initial",			EDIF_TOK_INITIAL},
  {"instance",			EDIF_TOK_INSTANCE},
  {"instancebackannotate",	EDIF_TOK_INSTANCEBACKANNOTATE},
  {"instancegroup",		EDIF_TOK_INSTANCEGROUP},
  {"instancemap",		EDIF_TOK_INSTANCEMAP},
  {"instanceref",		EDIF_TOK_INSTANCEREF},
  {"integer",			EDIF_TOK_INTEGER},
  {"integerdisplay",		EDIF_TOK_INTEGERDISPLAY},
  {"interface",			EDIF_TOK_INTERFACE},
  {"interfiguregroupspacing",	EDIF_TOK_INTERFIGUREGROUPSPACING},
  {"intersection",		EDIF_TOK_INTERSECTION},
  {"intrafiguregroupspacing",	EDIF_TOK_INTRAFIGUREGROUPSPACING},
  {"inverse",			EDIF_TOK_INVERSE},
  {"isolated",			EDIF_TOK_ISOLATED},
  {"joined",			EDIF_TOK_JOINED},
  {"justify",			EDIF_TOK_JUSTIFY},
  {"keyworddisplay",		EDIF_TOK_KEYWORDDISPLAY},
  {"keywordlevel",		EDIF_TOK_KEYWORDLEVEL},
  {"keywordmap",		EDIF_TOK_KEYWORDMAP},
  {"lessthan",			EDIF_TOK_LESSTHAN},
  {"library",			EDIF_TOK_LIBRARY},
  {"libraryref",		EDIF_TOK_LIBRARYREF},
  {"listofnets",		EDIF_TOK_LISTOFNETS},
  {"listofports",		EDIF_TOK_LISTOFPORTS},
  {"loaddelay",			EDIF_TOK_LOADDELAY},
  {"logicassign",		EDIF_TOK_LOGICASSIGN},
  {"logicinput",		EDIF_TOK_LOGICINPUT},
  {"logiclist",			EDIF_TOK_LOGICLIST},
  {"logicmapinput",		EDIF_TOK_LOGICMAPINPUT},
  {"logicmapoutput",		EDIF_TOK_LOGICMAPOUTPUT},
  {"logiconeof",		EDIF_TOK_LOGICONEOF},
  {"logicoutput",		EDIF_TOK_LOGICOUTPUT},
  {"logicport",			EDIF_TOK_LOGICPORT},
  {"logicref",			EDIF_TOK_LOGICREF},
  {"logicvalue",		EDIF_TOK_LOGICVALUE},
  {"logicwaveform",		EDIF_TOK_LOGICWAVEFORM},
  {"maintain",			EDIF_TOK_MAINTAIN},
  {"match",			EDIF_TOK_MATCH},
  {"member",			EDIF_TOK_MEMBER},
  {"minomax",			EDIF_TOK_MINOMAX},
  {"minomaxdisplay",		EDIF_TOK_MINOMAXDISPLAY},
  {"mnm",			EDIF_TOK_MNM},
  {"multiplevalueset",		EDIF_TOK_MULTIPLEVALUESET},
  {"mustjoin",			EDIF_TOK_MUSTJOIN},
  {"name",			EDIF_TOK_NAME},
  {"net",			EDIF_TOK_NET},
  {"netbackannotate",		EDIF_TOK_NETBACKANNOTATE},
  {"netbundle",			EDIF_TOK_NETBUNDLE},
  {"netdelay",			EDIF_TOK_NETDELAY},
  {"netgroup",			EDIF_TOK_NETGROUP},
  {"netmap",			EDIF_TOK_NETMAP},
  {"netref",			EDIF_TOK_NETREF},
  {"nochange",			EDIF_TOK_NOCHANGE},
  {"nonpermutable",		EDIF_TOK_NONPERMUTABLE},
  {"notallowed",		EDIF_TOK_NOTALLOWED},
  {"notchspacing",		EDIF_TOK_NOTCHSPACING},
  {"number",			EDIF_TOK_NUMBER},
  {"numberdefinition",		EDIF_TOK_NUMBERDEFINITION},
  {"numberdisplay",		EDIF_TOK_NUMBERDISPLAY},
  {"offpageconnector",		EDIF_TOK_OFFPAGECONNECTOR},
  {"offsetevent",		EDIF_TOK_OFFSETEVENT},
  {"openshape",			EDIF_TOK_OPENSHAPE},
  {"orientation",		EDIF_TOK_ORIENTATION},
  {"origin",			EDIF_TOK_ORIGIN},
  {"overhangdistance",		EDIF_TOK_OVERHANGDISTANCE},
  {"overlapdistance",		EDIF_TOK_OVERLAPDISTANCE},
  {"oversize",			EDIF_TOK_OVERSIZE},
  {"owner",			EDIF_TOK_OWNER},
  {"page",			EDIF_TOK_PAGE},
  {"pagesize",			EDIF_TOK_PAGESIZE},
  {"parameter",			EDIF_TOK_PARAMETER},
  {"parameterassign",		EDIF_TOK_PARAMETERASSIGN},
  {"parameterdisplay",		EDIF_TOK_PARAMETERDISPLAY},
  {"path",			EDIF_TOK_PATH},
  {"pathdelay",			EDIF_TOK_PATHDELAY},
  {"pathwidth",			EDIF_TOK_PATHWIDTH},
  {"permutable",		EDIF_TOK_PERMUTABLE},
  {"physicaldesignrule",	EDIF_TOK_PHYSICALDESIGNRULE},
  {"plug",			EDIF_TOK_PLUG},
  {"point",			EDIF_TOK_POINT},
  {"pointdisplay",		EDIF_TOK_POINTDISPLAY},
  {"pointlist",			EDIF_TOK_POINTLIST},
  {"polygon",			EDIF_TOK_POLYGON},
  {"port",			EDIF_TOK_PORT},
  {"portbackannotate",		EDIF_TOK_PORTBACKANNOTATE},
  {"portbundle",		EDIF_TOK_PORTBUNDLE},
  {"portdelay",			EDIF_TOK_PORTDELAY},
  {"portgroup",			EDIF_TOK_PORTGROUP},
  {"portimplementation",	EDIF_TOK_PORTIMPLEMENTATION},
  {"portinstance",		EDIF_TOK_PORTINSTANCE},
  {"portlist",			EDIF_TOK_PORTLIST},
  {"portlistalias",		EDIF_TOK_PORTLISTALIAS},
  {"portmap",			EDIF_TOK_PORTMAP},
  {"portref",			EDIF_TOK_PORTREF},
  {"program",			EDIF_TOK_PROGRAM},
  {"property",			EDIF_TOK_PROPERTY},
  {"propertydisplay",		EDIF_TOK_PROPERTYDISPLAY},
  {"protectionframe",		EDIF_TOK_PROTECTIONFRAME},
  {"pt",			EDIF_TOK_PT},
  {"rangevector",		EDIF_TOK_RANGEVECTOR},
  {"rectangle",			EDIF_TOK_RECTANGLE},
  {"rectanglesize",		EDIF_TOK_RECTANGLESIZE},
  {"rename",			EDIF_TOK_RENAME},
  {"resolves",			EDIF_TOK_RESOLVES},
  {"scale",			EDIF_TOK_SCALE},
  {"scalex",			EDIF_TOK_SCALEX},
  {"scaley",			EDIF_TOK_SCALEY},
  {"section",			EDIF_TOK_SECTION},
  {"shape",			EDIF_TOK_SHAPE},
  {"simulate",			EDIF_TOK_SIMULATE},
  {"simulationinfo",		EDIF_TOK_SIMULATIONINFO},
  {"singlevalueset",		EDIF_TOK_SINGLEVALUESET},
  {"site",			EDIF_TOK_SITE},
  {"socket",			EDIF_TOK_SOCKET},
  {"socketset",			EDIF_TOK_SOCKETSET},
  {"status",			EDIF_TOK_STATUS},
  {"steady",			EDIF_TOK_STEADY},
  {"string",			EDIF_TOK_STRING},
  {"stringdisplay",		EDIF_TOK_STRINGDISPLAY},
  {"strong",			EDIF_TOK_STRONG},
  {"symbol",			EDIF_TOK_SYMBOL},
  {"symmetry",			EDIF_TOK_SYMMETRY},
  {"table",			EDIF_TOK_TABLE},
  {"tabledefault",		EDIF_TOK_TABLEDEFAULT},
  {"technology",		EDIF_TOK_TECHNOLOGY},
  {"textheight",		EDIF_TOK_TEXTHEIGHT},
  {"timeinterval",		EDIF_TOK_TIMEINTERVAL},
  {"timestamp",			EDIF_TOK_TIMESTAMP},
  {"timing",			EDIF_TOK_TIMING},
  {"transform",			EDIF_TOK_TRANSFORM},
  {"transition",		EDIF_TOK_TRANSITION},
  {"trigger",			EDIF_TOK_TRIGGER},
  {"true",			EDIF_TOK_TRUE},
  {"unconstrained",		EDIF_TOK_UNCONSTRAINED},
  {"undefined",			EDIF_TOK_UNDEFINED},
  {"union",			EDIF_TOK_UNION},
  {"unit",			EDIF_TOK_UNIT},
  {"unused",			EDIF_TOK_UNUSED},
  {"userdata",			EDIF_TOK_USERDATA},
  {"version",			EDIF_TOK_VERSION},
  {"view",			EDIF_TOK_VIEW},
  {"viewlist",			EDIF_TOK_VIEWLIST},
  {"viewmap",			EDIF_TOK_VIEWMAP},
  {"viewref",			EDIF_TOK_VIEWREF},
  {"viewtype",			EDIF_TOK_VIEWTYPE},
  {"visible",			EDIF_TOK_VISIBLE},
  {"voltagemap",		EDIF_TOK_VOLTAGEMAP},
  {"wavevalue",			EDIF_TOK_WAVEVALUE},
  {"weak",			EDIF_TOK_WEAK},
  {"weakjoined",		EDIF_TOK_WEAKJOINED},
  {"when",			EDIF_TOK_WHEN},
  {"written",			EDIF_TOK_WRITTEN}
};
static int ContextDefSize = sizeof(ContextDef) / sizeof(Context);
/*
 *	Context follower tables:
 *
 *	  This is pretty ugly, an array is defined for each context
 *	which has following context levels. Yet another table is used
 *	to bind these arrays to the originating contexts.
 *	  Arrays are declared as:
 *
 *		static short f_<Context name>[] = { ... };
 *
 *	The array entries are the '%token' values for all keywords which
 *	can be reached from the <Context name> context. Like I said, ugly,
 *	but it works.
 *	  A negative entry means that the follow can only occur once within
 *	the specified context.
 */
static short f_NULL[] = {EDIF_TOK_EDIF};
static short f_Edif[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_EDIFVERSION,
			 EDIF_TOK_EDIFLEVEL, EDIF_TOK_KEYWORDMAP,
			 -EDIF_TOK_STATUS, EDIF_TOK_EXTERNAL,
			 EDIF_TOK_LIBRARY, EDIF_TOK_DESIGN, EDIF_TOK_COMMENT,
			 EDIF_TOK_USERDATA};
static short f_AcLoad[] = {EDIF_TOK_MNM, EDIF_TOK_E, EDIF_TOK_MINOMAXDISPLAY};
static short f_After[] = {EDIF_TOK_MNM, EDIF_TOK_E, EDIF_TOK_FOLLOW,
			  EDIF_TOK_MAINTAIN, EDIF_TOK_LOGICASSIGN,
			  EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_Annotate[] = {EDIF_TOK_STRINGDISPLAY};
static short f_Apply[] = {EDIF_TOK_CYCLE, EDIF_TOK_LOGICINPUT,
			  EDIF_TOK_LOGICOUTPUT, EDIF_TOK_COMMENT,
			  EDIF_TOK_USERDATA};
static short f_Arc[] = {EDIF_TOK_PT};
static short f_Array[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME};
static short f_ArrayMacro[] = {EDIF_TOK_PLUG};
static short f_ArrayRelatedInfo[] = {EDIF_TOK_BASEARRAY, EDIF_TOK_ARRAYSITE,
				     EDIF_TOK_ARRAYMACRO, EDIF_TOK_COMMENT,
				     EDIF_TOK_USERDATA};
static short f_ArraySite[] = {EDIF_TOK_SOCKET};
static short f_AtLeast[] = {EDIF_TOK_E};
static short f_AtMost[] = {EDIF_TOK_E};
static short f_Becomes[] = {EDIF_TOK_NAME, EDIF_TOK_LOGICLIST,
			    EDIF_TOK_LOGICONEOF};
/*
static short f_Between[] = {EDIF_TOK_ATLEAST, EDIF_TOK_GREATERTHAN,
			    EDIF_TOK_ATMOST, EDIF_TOK_LESSTHAN};
*/
static short f_Boolean[] = {EDIF_TOK_FALSE, EDIF_TOK_TRUE,
			    EDIF_TOK_BOOLEANDISPLAY, EDIF_TOK_BOOLEAN};
static short f_BooleanDisplay[] = {EDIF_TOK_FALSE, EDIF_TOK_TRUE,
				   EDIF_TOK_DISPLAY};
static short f_BooleanMap[] = {EDIF_TOK_FALSE, EDIF_TOK_TRUE};
static short f_BorderPattern[] = {EDIF_TOK_BOOLEAN};
static short f_BoundingBox[] = {EDIF_TOK_RECTANGLE};
static short f_Cell[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_CELLTYPE,
			 -EDIF_TOK_STATUS, -EDIF_TOK_VIEWMAP, EDIF_TOK_VIEW,
			 EDIF_TOK_COMMENT, EDIF_TOK_USERDATA,
			 EDIF_TOK_PROPERTY};
static short f_CellRef[] = {EDIF_TOK_NAME, EDIF_TOK_LIBRARYREF};
static short f_Change[] = {EDIF_TOK_NAME, EDIF_TOK_PORTREF, EDIF_TOK_PORTLIST,
			   EDIF_TOK_BECOMES, EDIF_TOK_TRANSITION};
static short f_Circle[] = {EDIF_TOK_PT, EDIF_TOK_PROPERTY};
static short f_Color[] = {EDIF_TOK_E};
static short f_CommentGraphics[] = {EDIF_TOK_ANNOTATE, EDIF_TOK_FIGURE,
				    EDIF_TOK_INSTANCE, -EDIF_TOK_BOUNDINGBOX,
				    EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
				    EDIF_TOK_USERDATA};
static short f_Compound[] = {EDIF_TOK_NAME};
static short f_ConnectLocation[] = {EDIF_TOK_FIGURE};
static short f_Contents[] = {EDIF_TOK_INSTANCE, EDIF_TOK_OFFPAGECONNECTOR,
			     EDIF_TOK_FIGURE, EDIF_TOK_SECTION, EDIF_TOK_NET,
			     EDIF_TOK_NETBUNDLE, EDIF_TOK_PAGE,
			     EDIF_TOK_COMMENTGRAPHICS,
			     EDIF_TOK_PORTIMPLEMENTATION,
			     EDIF_TOK_TIMING, EDIF_TOK_SIMULATE,
			     EDIF_TOK_WHEN, EDIF_TOK_FOLLOW,
			     EDIF_TOK_LOGICPORT, -EDIF_TOK_BOUNDINGBOX,
			     EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_Criticality[] = {EDIF_TOK_INTEGERDISPLAY};
static short f_CurrentMap[] = {EDIF_TOK_MNM, EDIF_TOK_E};
static short f_Curve[] = {EDIF_TOK_ARC, EDIF_TOK_PT};
static short f_Cycle[] = {EDIF_TOK_DURATION};
static short f_DataOrigin[] = {EDIF_TOK_VERSION};
static short f_DcFanInLoad[] = {EDIF_TOK_E, EDIF_TOK_NUMBERDISPLAY};
static short f_DcFanOutLoad[] = {EDIF_TOK_E, EDIF_TOK_NUMBERDISPLAY};
static short f_DcMaxFanIn[] = {EDIF_TOK_E, EDIF_TOK_NUMBERDISPLAY};
static short f_DcMaxFanOut[] = {EDIF_TOK_E, EDIF_TOK_NUMBERDISPLAY};
static short f_Delay[] = {EDIF_TOK_MNM, EDIF_TOK_E};
static short f_Delta[] = {EDIF_TOK_PT};
static short f_Design[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_CELLREF,
			   EDIF_TOK_STATUS, EDIF_TOK_COMMENT,
			   EDIF_TOK_PROPERTY, EDIF_TOK_USERDATA};
static short f_Designator[] = {EDIF_TOK_STRINGDISPLAY};
static short f_Difference[] = {EDIF_TOK_FIGUREGROUPREF, EDIF_TOK_INTERSECTION,
			       EDIF_TOK_UNION, EDIF_TOK_DIFFERENCE,
			       EDIF_TOK_INVERSE, EDIF_TOK_OVERSIZE};
static short f_Display[] = {EDIF_TOK_NAME, EDIF_TOK_FIGUREGROUPOVERRIDE,
			    EDIF_TOK_JUSTIFY, EDIF_TOK_ORIENTATION,
			    EDIF_TOK_ORIGIN};
static short f_Dominates[] = {EDIF_TOK_NAME};
static short f_Dot[] = {EDIF_TOK_PT, EDIF_TOK_PROPERTY};
static short f_Duration[] = {EDIF_TOK_E};
static short f_EnclosureDistance[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				      EDIF_TOK_FIGUREGROUPOBJECT,
				      EDIF_TOK_LESSTHAN, EDIF_TOK_GREATERTHAN,
				      EDIF_TOK_ATMOST, EDIF_TOK_ATLEAST,
				      EDIF_TOK_EXACTLY, EDIF_TOK_BETWEEN,
				      EDIF_TOK_SINGLEVALUESET,
				      EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_Entry[] = {EDIF_TOK_MATCH, EDIF_TOK_CHANGE, EDIF_TOK_STEADY,
			  EDIF_TOK_LOGICREF, EDIF_TOK_PORTREF,
			  EDIF_TOK_NOCHANGE, EDIF_TOK_TABLE,
			  EDIF_TOK_DELAY, EDIF_TOK_LOADDELAY};
static short f_Exactly[] = {EDIF_TOK_E};
static short f_External[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
			     EDIF_TOK_EDIFLEVEL, EDIF_TOK_TECHNOLOGY,
			     -EDIF_TOK_STATUS, EDIF_TOK_CELL, EDIF_TOK_COMMENT,
			     EDIF_TOK_USERDATA};
static short f_Fabricate[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME};
static short f_Figure[] = {EDIF_TOK_NAME, EDIF_TOK_FIGUREGROUPOVERRIDE,
			   EDIF_TOK_CIRCLE, EDIF_TOK_DOT, EDIF_TOK_OPENSHAPE,
			   EDIF_TOK_PATH, EDIF_TOK_POLYGON,
			   EDIF_TOK_RECTANGLE, EDIF_TOK_SHAPE,
			   EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_FigureArea[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
			       EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_LESSTHAN,
			       EDIF_TOK_GREATERTHAN, EDIF_TOK_ATMOST,
			       EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
			       EDIF_TOK_BETWEEN, EDIF_TOK_SINGLEVALUESET,
			       EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_FigureGroup[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				-EDIF_TOK_CORNERTYPE, -EDIF_TOK_ENDTYPE,
				-EDIF_TOK_PATHWIDTH, -EDIF_TOK_BORDERWIDTH,
				-EDIF_TOK_COLOR, -EDIF_TOK_FILLPATTERN,
				-EDIF_TOK_BORDERPATTERN, -EDIF_TOK_TEXTHEIGHT,
				-EDIF_TOK_VISIBLE, EDIF_TOK_INCLUDEFIGUREGROUP,
				EDIF_TOK_COMMENT, EDIF_TOK_PROPERTY,
				EDIF_TOK_USERDATA};
static short f_FigureGroupObject[] = {EDIF_TOK_NAME,
				      EDIF_TOK_FIGUREGROUPOBJECT,
				      EDIF_TOK_INTERSECTION, EDIF_TOK_UNION,
				      EDIF_TOK_DIFFERENCE, EDIF_TOK_INVERSE,
				      EDIF_TOK_OVERSIZE};
static short f_FigureGroupOverride[] = {EDIF_TOK_NAME, -EDIF_TOK_CORNERTYPE,
					-EDIF_TOK_ENDTYPE, -EDIF_TOK_PATHWIDTH,
					-EDIF_TOK_BORDERWIDTH, -EDIF_TOK_COLOR,
					-EDIF_TOK_FILLPATTERN,
					-EDIF_TOK_TEXTHEIGHT,
					-EDIF_TOK_BORDERPATTERN,
					EDIF_TOK_VISIBLE, EDIF_TOK_COMMENT,
					EDIF_TOK_PROPERTY, EDIF_TOK_USERDATA};
static short f_FigureGroupRef[] = {EDIF_TOK_NAME, EDIF_TOK_LIBRARYREF};
static short f_FigurePerimeter[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				    EDIF_TOK_FIGUREGROUPOBJECT,
				    EDIF_TOK_LESSTHAN, EDIF_TOK_GREATERTHAN,
				    EDIF_TOK_ATMOST, EDIF_TOK_ATLEAST,
				    EDIF_TOK_EXACTLY, EDIF_TOK_BETWEEN,
				    EDIF_TOK_SINGLEVALUESET, EDIF_TOK_COMMENT,
				    EDIF_TOK_USERDATA};
static short f_FigureWidth[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_LESSTHAN,
				EDIF_TOK_GREATERTHAN, EDIF_TOK_ATMOST,
				EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
				EDIF_TOK_BETWEEN, EDIF_TOK_SINGLEVALUESET,
				EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_FillPattern[] = {EDIF_TOK_BOOLEAN};
static short f_Follow[] = {EDIF_TOK_NAME, EDIF_TOK_PORTREF, EDIF_TOK_TABLE,
			   EDIF_TOK_DELAY, EDIF_TOK_LOADDELAY};
static short f_ForbiddenEvent[] = {EDIF_TOK_TIMEINTERVAL, EDIF_TOK_EVENT};
static short f_GlobalPortRef[] = {EDIF_TOK_NAME};
static short f_GreaterThan[] = {EDIF_TOK_E};
static short f_GridMap[] = {EDIF_TOK_E};
static short f_IncludeFigureGroup[] = {EDIF_TOK_FIGUREGROUPREF,
				       EDIF_TOK_INTERSECTION, EDIF_TOK_UNION,
				       EDIF_TOK_DIFFERENCE, EDIF_TOK_INVERSE,
				       EDIF_TOK_OVERSIZE};
static short f_Instance[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			     EDIF_TOK_VIEWREF, EDIF_TOK_VIEWLIST,
			     -EDIF_TOK_TRANSFORM, EDIF_TOK_PARAMETERASSIGN,
			     EDIF_TOK_PORTINSTANCE, EDIF_TOK_TIMING,
			     -EDIF_TOK_DESIGNATOR, EDIF_TOK_PROPERTY,
			     EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_InstanceBackAnnotate[] = {EDIF_TOK_INSTANCEREF,
					 -EDIF_TOK_DESIGNATOR, EDIF_TOK_TIMING,
					 EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT};
static short f_InstanceGroup[] = {EDIF_TOK_INSTANCEREF};
static short f_InstanceMap[] = {EDIF_TOK_INSTANCEREF, EDIF_TOK_INSTANCEGROUP,
				EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_InstanceRef[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER,
				EDIF_TOK_INSTANCEREF, EDIF_TOK_VIEWREF};
static short f_Integer[] = {EDIF_TOK_INTEGERDISPLAY, EDIF_TOK_INTEGER};
static short f_IntegerDisplay[] = {EDIF_TOK_DISPLAY};
static short f_Interface[] = {EDIF_TOK_PORT, EDIF_TOK_PORTBUNDLE,
			      -EDIF_TOK_SYMBOL, -EDIF_TOK_PROTECTIONFRAME,
			      -EDIF_TOK_ARRAYRELATEDINFO, EDIF_TOK_PARAMETER,
			      EDIF_TOK_JOINED, EDIF_TOK_MUSTJOIN,
			      EDIF_TOK_WEAKJOINED, EDIF_TOK_PERMUTABLE,
			      EDIF_TOK_TIMING, EDIF_TOK_SIMULATE,
			      -EDIF_TOK_DESIGNATOR, EDIF_TOK_PROPERTY,
			      EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_InterFigureGroupSpacing[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
					    EDIF_TOK_FIGUREGROUPOBJECT,
					    EDIF_TOK_LESSTHAN,
					    EDIF_TOK_GREATERTHAN,
					    EDIF_TOK_ATMOST,
					    EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
					    EDIF_TOK_BETWEEN,
					    EDIF_TOK_SINGLEVALUESET,
					    EDIF_TOK_COMMENT,
					    EDIF_TOK_USERDATA};
static short f_Intersection[] = {EDIF_TOK_FIGUREGROUPREF,
				 EDIF_TOK_INTERSECTION, EDIF_TOK_UNION,
				 EDIF_TOK_DIFFERENCE, EDIF_TOK_INVERSE,
				 EDIF_TOK_OVERSIZE};
static short f_IntraFigureGroupSpacing[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
					    EDIF_TOK_FIGUREGROUPOBJECT,
					    EDIF_TOK_LESSTHAN,
					    EDIF_TOK_GREATERTHAN,
					    EDIF_TOK_ATMOST, EDIF_TOK_ATLEAST,
					    EDIF_TOK_EXACTLY, EDIF_TOK_BETWEEN,
					    EDIF_TOK_SINGLEVALUESET,
					    EDIF_TOK_COMMENT,
					    EDIF_TOK_USERDATA};
static short f_Inverse[] = {EDIF_TOK_FIGUREGROUPREF, EDIF_TOK_INTERSECTION,
			    EDIF_TOK_UNION, EDIF_TOK_DIFFERENCE,
			    EDIF_TOK_INVERSE, EDIF_TOK_OVERSIZE};
static short f_Joined[] = {EDIF_TOK_PORTREF, EDIF_TOK_PORTLIST,
			   EDIF_TOK_GLOBALPORTREF};
static short f_KeywordDisplay[] = {EDIF_TOK_DISPLAY};
static short f_KeywordMap[] = {EDIF_TOK_KEYWORDLEVEL, EDIF_TOK_COMMENT};
static short f_LessThan[] = {EDIF_TOK_E};
static short f_Library[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_EDIFLEVEL,
			    EDIF_TOK_TECHNOLOGY, -EDIF_TOK_STATUS,
			    EDIF_TOK_CELL, EDIF_TOK_COMMENT,
			    EDIF_TOK_USERDATA};
static short f_LibraryRef[] = {EDIF_TOK_NAME};
static short f_ListOfNets[] = {EDIF_TOK_NET};
static short f_ListOfPorts[] = {EDIF_TOK_PORT, EDIF_TOK_PORTBUNDLE};
static short f_LoadDelay[] = {EDIF_TOK_MNM, EDIF_TOK_E, EDIF_TOK_MINOMAXDISPLAY};
static short f_LogicAssign[] = {EDIF_TOK_NAME, EDIF_TOK_PORTREF,
				EDIF_TOK_LOGICREF, EDIF_TOK_TABLE,
				EDIF_TOK_DELAY, EDIF_TOK_LOADDELAY};
static short f_LogicInput[] = {EDIF_TOK_PORTLIST, EDIF_TOK_PORTREF,
			       EDIF_TOK_NAME, EDIF_TOK_LOGICWAVEFORM};
static short f_LogicList[] = {EDIF_TOK_NAME, EDIF_TOK_LOGICONEOF,
			      EDIF_TOK_IGNORE};
static short f_LogicMapInput[] = {EDIF_TOK_LOGICREF};
static short f_LogicMapOutput[] = {EDIF_TOK_LOGICREF};
static short f_LogicOneOf[] = {EDIF_TOK_NAME, EDIF_TOK_LOGICLIST};
static short f_LogicOutput[] = {EDIF_TOK_PORTLIST, EDIF_TOK_PORTREF,
				EDIF_TOK_NAME, EDIF_TOK_LOGICWAVEFORM};
static short f_LogicPort[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
			      EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
			      EDIF_TOK_USERDATA};
static short f_LogicRef[] = {EDIF_TOK_NAME, EDIF_TOK_LIBRARYREF};
static short f_LogicValue[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
			       -EDIF_TOK_VOLTAGEMAP, -EDIF_TOK_CURRENTMAP,
			       -EDIF_TOK_BOOLEANMAP, -EDIF_TOK_COMPOUND,
			       -EDIF_TOK_WEAK ,-EDIF_TOK_STRONG,
			       -EDIF_TOK_DOMINATES, -EDIF_TOK_LOGICMAPOUTPUT,
			       -EDIF_TOK_LOGICMAPINPUT,
			       -EDIF_TOK_ISOLATED, EDIF_TOK_RESOLVES,
			       EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
			       EDIF_TOK_USERDATA};
static short f_LogicWaveform[] = {EDIF_TOK_NAME, EDIF_TOK_LOGICLIST,
				  EDIF_TOK_LOGICONEOF, EDIF_TOK_IGNORE};
static short f_Maintain[] = {EDIF_TOK_NAME, EDIF_TOK_PORTREF, EDIF_TOK_DELAY,
			     EDIF_TOK_LOADDELAY};
static short f_Match[] = {EDIF_TOK_NAME, EDIF_TOK_PORTREF, EDIF_TOK_PORTLIST,
			  EDIF_TOK_LOGICLIST, EDIF_TOK_LOGICONEOF};
static short f_Member[] = {EDIF_TOK_NAME};
static short f_MiNoMax[] = {EDIF_TOK_MNM, EDIF_TOK_E, EDIF_TOK_MINOMAXDISPLAY,
			    EDIF_TOK_MINOMAX};
static short f_MiNoMaxDisplay[] = {EDIF_TOK_MNM, EDIF_TOK_E, EDIF_TOK_DISPLAY};
static short f_Mnm[] = {EDIF_TOK_E, EDIF_TOK_UNDEFINED,
			EDIF_TOK_UNCONSTRAINED};
static short f_MultipleValueSet[] = {EDIF_TOK_RANGEVECTOR};
static short f_MustJoin[] = {EDIF_TOK_PORTREF, EDIF_TOK_PORTLIST,
			     EDIF_TOK_WEAKJOINED, EDIF_TOK_JOINED};
static short f_Name[] = {EDIF_TOK_DISPLAY};
static short f_Net[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, -EDIF_TOK_CRITICALITY,
			EDIF_TOK_NETDELAY, EDIF_TOK_FIGURE, EDIF_TOK_NET,
			EDIF_TOK_INSTANCE, EDIF_TOK_COMMENTGRAPHICS,
			EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
			EDIF_TOK_USERDATA, EDIF_TOK_JOINED, EDIF_TOK_ARRAY};
static short f_NetBackAnnotate[] = {EDIF_TOK_NETREF, EDIF_TOK_NETDELAY,
				    -EDIF_TOK_CRITICALITY, EDIF_TOK_PROPERTY,
				    EDIF_TOK_COMMENT};
static short f_NetBundle[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			      EDIF_TOK_LISTOFNETS, EDIF_TOK_FIGURE,
			      EDIF_TOK_COMMENTGRAPHICS, EDIF_TOK_PROPERTY,
			      EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_NetDelay[] = {EDIF_TOK_DERIVATION, EDIF_TOK_DELAY,
			     EDIF_TOK_TRANSITION, EDIF_TOK_BECOMES};
static short f_NetGroup[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER, EDIF_TOK_NETREF};
static short f_NetMap[] = {EDIF_TOK_NETREF, EDIF_TOK_NETGROUP,
			   EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_NetRef[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER, EDIF_TOK_NETREF,
			   EDIF_TOK_INSTANCEREF, EDIF_TOK_VIEWREF};
static short f_NonPermutable[] = {EDIF_TOK_PORTREF, EDIF_TOK_PERMUTABLE};
static short f_NotAllowed[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
			       EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_COMMENT,
			       EDIF_TOK_USERDATA};
static short f_NotchSpacing[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				 EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_LESSTHAN,
				 EDIF_TOK_GREATERTHAN, EDIF_TOK_ATMOST,
				 EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
				 EDIF_TOK_BETWEEN, EDIF_TOK_SINGLEVALUESET,
				 EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_Number[] = {EDIF_TOK_E, EDIF_TOK_NUMBERDISPLAY, EDIF_TOK_NUMBER};
static short f_NumberDefinition[] = {EDIF_TOK_SCALE, -EDIF_TOK_GRIDMAP,
				     EDIF_TOK_COMMENT};
static short f_NumberDisplay[] = {EDIF_TOK_E, EDIF_TOK_DISPLAY};
static short f_OffPageConnector[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				     -EDIF_TOK_UNUSED, EDIF_TOK_PROPERTY,
				     EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_OffsetEvent[] = {EDIF_TOK_EVENT, EDIF_TOK_E};
static short f_OpenShape[] = {EDIF_TOK_CURVE, EDIF_TOK_PROPERTY};
static short f_Origin[] = {EDIF_TOK_PT};
static short f_OverhangDistance[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				     EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_LESSTHAN,
				     EDIF_TOK_GREATERTHAN, EDIF_TOK_ATMOST,
				     EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
				     EDIF_TOK_BETWEEN, EDIF_TOK_SINGLEVALUESET,
				     EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_OverlapDistance[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				    EDIF_TOK_FIGUREGROUPOBJECT, EDIF_TOK_LESSTHAN,
				    EDIF_TOK_GREATERTHAN, EDIF_TOK_ATMOST,
				    EDIF_TOK_ATLEAST, EDIF_TOK_EXACTLY,
				    EDIF_TOK_BETWEEN, EDIF_TOK_SINGLEVALUESET,
				    EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_Oversize[] = {EDIF_TOK_FIGUREGROUPREF, EDIF_TOK_INTERSECTION,
			     EDIF_TOK_UNION, EDIF_TOK_DIFFERENCE,
			     EDIF_TOK_INVERSE, EDIF_TOK_OVERSIZE,
			     EDIF_TOK_CORNERTYPE};
static short f_Page[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			 EDIF_TOK_INSTANCE, EDIF_TOK_NET, EDIF_TOK_NETBUNDLE,
			 EDIF_TOK_COMMENTGRAPHICS, EDIF_TOK_PORTIMPLEMENTATION,
			 -EDIF_TOK_PAGESIZE, -EDIF_TOK_BOUNDINGBOX,
			 EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_PageSize[] = {EDIF_TOK_RECTANGLE};
static short f_Parameter[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			      EDIF_TOK_BOOLEAN, EDIF_TOK_INTEGER,
			      EDIF_TOK_MINOMAX, EDIF_TOK_NUMBER,
			      EDIF_TOK_POINT, EDIF_TOK_STRING};
static short f_ParameterAssign[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER,
				    EDIF_TOK_BOOLEAN, EDIF_TOK_INTEGER,
				    EDIF_TOK_MINOMAX, EDIF_TOK_NUMBER, EDIF_TOK_POINT,
				    EDIF_TOK_STRING};
static short f_ParameterDisplay[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER,
				     EDIF_TOK_DISPLAY};
static short f_Path[] = {EDIF_TOK_POINTLIST, EDIF_TOK_PROPERTY};
static short f_PathDelay[] = {EDIF_TOK_DELAY, EDIF_TOK_EVENT};
static short f_Permutable[] = {EDIF_TOK_PORTREF, EDIF_TOK_PERMUTABLE,
			       EDIF_TOK_NONPERMUTABLE};
static short f_PhysicalDesignRule[] = {EDIF_TOK_FIGUREWIDTH,
				       EDIF_TOK_FIGUREAREA,
				       EDIF_TOK_RECTANGLESIZE,
				       EDIF_TOK_FIGUREPERIMETER,
				       EDIF_TOK_OVERLAPDISTANCE,
				       EDIF_TOK_OVERHANGDISTANCE,
				       EDIF_TOK_ENCLOSUREDISTANCE,
				       EDIF_TOK_INTERFIGUREGROUPSPACING,
				       EDIF_TOK_NOTCHSPACING,
				       EDIF_TOK_INTRAFIGUREGROUPSPACING,
				       EDIF_TOK_NOTALLOWED,
				       EDIF_TOK_FIGUREGROUP, EDIF_TOK_COMMENT,
				       EDIF_TOK_USERDATA};
static short f_Plug[] = {EDIF_TOK_SOCKETSET};
static short f_Point[] = {EDIF_TOK_PT, EDIF_TOK_POINTDISPLAY,
			  EDIF_TOK_POINT};
static short f_PointDisplay[] = {EDIF_TOK_PT, EDIF_TOK_DISPLAY};
static short f_PointList[] = {EDIF_TOK_PT};
static short f_Polygon[] = {EDIF_TOK_POINTLIST, EDIF_TOK_PROPERTY};
static short f_Port[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			 -EDIF_TOK_DIRECTION, -EDIF_TOK_UNUSED,
			 EDIF_TOK_PORTDELAY, -EDIF_TOK_DESIGNATOR,
			 -EDIF_TOK_DCFANINLOAD, -EDIF_TOK_DCFANOUTLOAD,
			 -EDIF_TOK_DCMAXFANIN, -EDIF_TOK_DCMAXFANOUT,
			 -EDIF_TOK_ACLOAD, EDIF_TOK_PROPERTY,
			 EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_PortBackAnnotate[] = {EDIF_TOK_PORTREF, -EDIF_TOK_DESIGNATOR,
				     EDIF_TOK_PORTDELAY, -EDIF_TOK_DCFANINLOAD,
				     -EDIF_TOK_DCFANOUTLOAD,
				     -EDIF_TOK_DCMAXFANIN,
				     -EDIF_TOK_DCMAXFANOUT, -EDIF_TOK_ACLOAD,
				     EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT};
static short f_PortBundle[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_ARRAY,
			       EDIF_TOK_LISTOFPORTS, EDIF_TOK_PROPERTY,
			       EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_PortDelay[] = {EDIF_TOK_DERIVATION, EDIF_TOK_DELAY,
			      EDIF_TOK_LOADDELAY, EDIF_TOK_TRANSITION,
			      EDIF_TOK_BECOMES};
static short f_PortGroup[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER,
			      EDIF_TOK_PORTREF};
static short f_PortImplementation[] = {EDIF_TOK_PORTREF, EDIF_TOK_NAME, EDIF_TOK_MEMBER,
				       -EDIF_TOK_CONNECTLOCATION,
				       EDIF_TOK_FIGURE, EDIF_TOK_INSTANCE,
				       EDIF_TOK_COMMENTGRAPHICS,
				       EDIF_TOK_PROPERTYDISPLAY,
				       EDIF_TOK_KEYWORDDISPLAY,
				       EDIF_TOK_PROPERTY,
				       EDIF_TOK_USERDATA, EDIF_TOK_COMMENT};
static short f_PortInstance[] = {EDIF_TOK_PORTREF, EDIF_TOK_NAME,
				 EDIF_TOK_MEMBER, -EDIF_TOK_UNUSED,
				 EDIF_TOK_PORTDELAY, -EDIF_TOK_DESIGNATOR,
				 -EDIF_TOK_DCFANINLOAD,
				 -EDIF_TOK_DCFANOUTLOAD, -EDIF_TOK_DCMAXFANIN,
				 -EDIF_TOK_DCMAXFANOUT, -EDIF_TOK_ACLOAD,
				 EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
				 EDIF_TOK_USERDATA};
static short f_PortList[] = {EDIF_TOK_PORTREF, EDIF_TOK_NAME,
			     EDIF_TOK_MEMBER};
static short f_PortListAlias[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				  EDIF_TOK_ARRAY, EDIF_TOK_PORTLIST};
static short f_PortMap[] = {EDIF_TOK_PORTREF, EDIF_TOK_PORTGROUP,
			    EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_PortRef[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER,
			    EDIF_TOK_PORTREF, EDIF_TOK_INSTANCEREF,
			    EDIF_TOK_VIEWREF};
static short f_Program[] = {EDIF_TOK_VERSION};
static short f_Property[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_BOOLEAN,
			     EDIF_TOK_INTEGER, EDIF_TOK_MINOMAX,
			     EDIF_TOK_NUMBER, EDIF_TOK_POINT, EDIF_TOK_STRING,
			     -EDIF_TOK_OWNER, -EDIF_TOK_UNIT,
			     EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT};
static short f_PropertyDisplay[] = {EDIF_TOK_NAME, EDIF_TOK_DISPLAY};
static short f_ProtectionFrame[] = {EDIF_TOK_PORTIMPLEMENTATION,
				    EDIF_TOK_FIGURE, EDIF_TOK_INSTANCE,
				    EDIF_TOK_COMMENTGRAPHICS,
				    -EDIF_TOK_BOUNDINGBOX,
				    EDIF_TOK_PROPERTYDISPLAY,
				    EDIF_TOK_KEYWORDDISPLAY,
				    EDIF_TOK_PARAMETERDISPLAY,
				    EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
				    EDIF_TOK_USERDATA};
static short f_RangeVector[] = {EDIF_TOK_LESSTHAN, EDIF_TOK_GREATERTHAN,
				EDIF_TOK_ATMOST, EDIF_TOK_ATLEAST,
				EDIF_TOK_EXACTLY, EDIF_TOK_BETWEEN,
				EDIF_TOK_SINGLEVALUESET};
static short f_Rectangle[] = {EDIF_TOK_PT, EDIF_TOK_PROPERTY};
static short f_RectangleSize[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME,
				  EDIF_TOK_FIGUREGROUPOBJECT,
				  EDIF_TOK_RANGEVECTOR,
				  EDIF_TOK_MULTIPLEVALUESET,EDIF_TOK_COMMENT,
				  EDIF_TOK_USERDATA};
static short f_Rename[] = {EDIF_TOK_NAME, EDIF_TOK_STRINGDISPLAY};
static short f_Resolves[] = {EDIF_TOK_NAME};
static short f_Scale[] = {EDIF_TOK_E, EDIF_TOK_UNIT};
static short f_Section[] = {EDIF_TOK_SECTION, EDIF_TOK_INSTANCE};
static short f_Shape[] = {EDIF_TOK_CURVE, EDIF_TOK_PROPERTY};
static short f_Simulate[] = {EDIF_TOK_NAME, EDIF_TOK_PORTLISTALIAS,
			     EDIF_TOK_WAVEVALUE, EDIF_TOK_APPLY,
			     EDIF_TOK_COMMENT, EDIF_TOK_USERDATA};
static short f_SimulationInfo[] = {EDIF_TOK_LOGICVALUE, EDIF_TOK_COMMENT,
				   EDIF_TOK_USERDATA};
static short f_SingleValueSet[] = {EDIF_TOK_LESSTHAN, EDIF_TOK_GREATERTHAN,
				   EDIF_TOK_ATMOST, EDIF_TOK_ATLEAST,
				   EDIF_TOK_EXACTLY, EDIF_TOK_BETWEEN};
static short f_Site[] = {EDIF_TOK_VIEWREF, EDIF_TOK_TRANSFORM};
static short f_Socket[] = {EDIF_TOK_SYMMETRY};
static short f_SocketSet[] = {EDIF_TOK_SYMMETRY, EDIF_TOK_SITE};
static short f_Status[] = {EDIF_TOK_WRITTEN, EDIF_TOK_COMMENT,
			   EDIF_TOK_USERDATA};
static short f_Steady[] = {EDIF_TOK_NAME, EDIF_TOK_MEMBER, EDIF_TOK_PORTREF,
			   EDIF_TOK_PORTLIST, EDIF_TOK_DURATION,
			   EDIF_TOK_TRANSITION, EDIF_TOK_BECOMES};
static short f_String[] = {EDIF_TOK_STRINGDISPLAY, EDIF_TOK_STRING};
static short f_StringDisplay[] = {EDIF_TOK_DISPLAY};
static short f_Strong[] = {EDIF_TOK_NAME};
static short f_Symbol[] = {EDIF_TOK_PORTIMPLEMENTATION, EDIF_TOK_FIGURE,
			   EDIF_TOK_INSTANCE, EDIF_TOK_COMMENTGRAPHICS,
			   EDIF_TOK_ANNOTATE, -EDIF_TOK_PAGESIZE,
			   -EDIF_TOK_BOUNDINGBOX, EDIF_TOK_PROPERTYDISPLAY,
			   EDIF_TOK_KEYWORDDISPLAY, EDIF_TOK_PARAMETERDISPLAY,
			   EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
			   EDIF_TOK_USERDATA};
static short f_Symmetry[] = {EDIF_TOK_TRANSFORM};
static short f_Table[] = {EDIF_TOK_ENTRY, EDIF_TOK_TABLEDEFAULT};
static short f_TableDefault[] = {EDIF_TOK_LOGICREF, EDIF_TOK_PORTREF,
				 EDIF_TOK_NOCHANGE, EDIF_TOK_TABLE,
				 EDIF_TOK_DELAY, EDIF_TOK_LOADDELAY};
static short f_Technology[] = {EDIF_TOK_NUMBERDEFINITION, EDIF_TOK_FIGUREGROUP,
			       EDIF_TOK_FABRICATE, -EDIF_TOK_SIMULATIONINFO,
			       EDIF_TOK_COMMENT, EDIF_TOK_USERDATA,
			       -EDIF_TOK_PHYSICALDESIGNRULE};
static short f_TimeInterval[] = {EDIF_TOK_EVENT, EDIF_TOK_OFFSETEVENT,
				 EDIF_TOK_DURATION};
static short f_Timing[] = {EDIF_TOK_DERIVATION, EDIF_TOK_PATHDELAY,
			   EDIF_TOK_FORBIDDENEVENT, EDIF_TOK_COMMENT,
			   EDIF_TOK_USERDATA};
static short f_Transform[] = {EDIF_TOK_SCALEX, EDIF_TOK_SCALEY, EDIF_TOK_DELTA,
			      EDIF_TOK_ORIENTATION, EDIF_TOK_ORIGIN};
static short f_Transition[] = {EDIF_TOK_NAME, EDIF_TOK_LOGICLIST,
			       EDIF_TOK_LOGICONEOF};
static short f_Trigger[] = {EDIF_TOK_CHANGE, EDIF_TOK_STEADY,
			    EDIF_TOK_INITIAL};
static short f_Union[] = {EDIF_TOK_FIGUREGROUPREF, EDIF_TOK_INTERSECTION,
			  EDIF_TOK_UNION, EDIF_TOK_DIFFERENCE,
			  EDIF_TOK_INVERSE, EDIF_TOK_OVERSIZE};
static short f_View[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_VIEWTYPE,
			 EDIF_TOK_INTERFACE, -EDIF_TOK_STATUS,
			 -EDIF_TOK_CONTENTS, EDIF_TOK_COMMENT,
			 EDIF_TOK_PROPERTY, EDIF_TOK_USERDATA};
static short f_ViewList[] = {EDIF_TOK_VIEWREF, EDIF_TOK_VIEWLIST};
static short f_ViewMap[] = {EDIF_TOK_PORTMAP, EDIF_TOK_PORTBACKANNOTATE,
			    EDIF_TOK_INSTANCEMAP,
			    EDIF_TOK_INSTANCEBACKANNOTATE, EDIF_TOK_NETMAP,
			    EDIF_TOK_NETBACKANNOTATE, EDIF_TOK_COMMENT,
			    EDIF_TOK_USERDATA};
static short f_ViewRef[] = {EDIF_TOK_NAME, EDIF_TOK_CELLREF};
static short f_Visible[] = {EDIF_TOK_FALSE, EDIF_TOK_TRUE};
static short f_VoltageMap[] = {EDIF_TOK_MNM, EDIF_TOK_E};
static short f_WaveValue[] = {EDIF_TOK_NAME, EDIF_TOK_RENAME, EDIF_TOK_E,
			      EDIF_TOK_LOGICWAVEFORM};
static short f_Weak[] = {EDIF_TOK_NAME};
static short f_WeakJoined[] = {EDIF_TOK_PORTREF, EDIF_TOK_PORTLIST,
			       EDIF_TOK_JOINED};
static short f_When[] = {EDIF_TOK_TRIGGER, EDIF_TOK_AFTER,
			 EDIF_TOK_FOLLOW, EDIF_TOK_MAINTAIN,
			 EDIF_TOK_LOGICASSIGN, EDIF_TOK_COMMENT,
			 EDIF_TOK_USERDATA};
static short f_Written[] = {EDIF_TOK_TIMESTAMP, EDIF_TOK_AUTHOR,
			    EDIF_TOK_PROGRAM, EDIF_TOK_DATAORIGIN,
			    EDIF_TOK_PROPERTY, EDIF_TOK_COMMENT,
			    EDIF_TOK_USERDATA};
/*
 *	Context binding table:
 *
 *	  This binds context follower arrays to their originating context.
 */
typedef struct Binder {
  short *Follower;		/* pointer to follower array */
  short Origin;			/* '%token' value of origin */
  short FollowerSize;		/* size of follower array */
} Binder;
#define	BE(f,o)			{f,o,sizeof(f)/sizeof(short)}
static Binder BinderDef[] = {
  BE(f_NULL,			0),
  BE(f_Edif,			EDIF_TOK_EDIF),
  BE(f_AcLoad,			EDIF_TOK_ACLOAD),
  BE(f_After,			EDIF_TOK_AFTER),
  BE(f_Annotate,		EDIF_TOK_ANNOTATE),
  BE(f_Apply,			EDIF_TOK_APPLY),
  BE(f_Arc,			EDIF_TOK_ARC),
  BE(f_Array,			EDIF_TOK_ARRAY),
  BE(f_ArrayMacro,		EDIF_TOK_ARRAYMACRO),
  BE(f_ArrayRelatedInfo,	EDIF_TOK_ARRAYRELATEDINFO),
  BE(f_ArraySite,		EDIF_TOK_ARRAYSITE),
  BE(f_AtLeast,			EDIF_TOK_ATLEAST),
  BE(f_AtMost,			EDIF_TOK_ATMOST),
  BE(f_Becomes,			EDIF_TOK_BECOMES),
  BE(f_Boolean,			EDIF_TOK_BOOLEAN),
  BE(f_BooleanDisplay,		EDIF_TOK_BOOLEANDISPLAY),
  BE(f_BooleanMap,		EDIF_TOK_BOOLEANMAP),
  BE(f_BorderPattern,		EDIF_TOK_BORDERPATTERN),
  BE(f_BoundingBox,		EDIF_TOK_BOUNDINGBOX),
  BE(f_Cell,			EDIF_TOK_CELL),
  BE(f_CellRef,			EDIF_TOK_CELLREF),
  BE(f_Change,			EDIF_TOK_CHANGE),
  BE(f_Circle,			EDIF_TOK_CIRCLE),
  BE(f_Color,			EDIF_TOK_COLOR),
  BE(f_CommentGraphics,		EDIF_TOK_COMMENTGRAPHICS),
  BE(f_Compound,		EDIF_TOK_COMPOUND),
  BE(f_ConnectLocation,		EDIF_TOK_CONNECTLOCATION),
  BE(f_Contents,		EDIF_TOK_CONTENTS),
  BE(f_Criticality,		EDIF_TOK_CRITICALITY),
  BE(f_CurrentMap,		EDIF_TOK_CURRENTMAP),
  BE(f_Curve,			EDIF_TOK_CURVE),
  BE(f_Cycle,			EDIF_TOK_CYCLE),
  BE(f_DataOrigin,		EDIF_TOK_DATAORIGIN),
  BE(f_DcFanInLoad,		EDIF_TOK_DCFANINLOAD),
  BE(f_DcFanOutLoad,		EDIF_TOK_DCFANOUTLOAD),
  BE(f_DcMaxFanIn,		EDIF_TOK_DCMAXFANIN),
  BE(f_DcMaxFanOut,		EDIF_TOK_DCMAXFANOUT),
  BE(f_Delay,			EDIF_TOK_DELAY),
  BE(f_Delta,			EDIF_TOK_DELTA),
  BE(f_Design,			EDIF_TOK_DESIGN),
  BE(f_Designator,		EDIF_TOK_DESIGNATOR),
  BE(f_Difference,		EDIF_TOK_DIFFERENCE),
  BE(f_Display,			EDIF_TOK_DISPLAY),
  BE(f_Dominates,		EDIF_TOK_DOMINATES),
  BE(f_Dot,			EDIF_TOK_DOT),
  BE(f_Duration,		EDIF_TOK_DURATION),
  BE(f_EnclosureDistance,	EDIF_TOK_ENCLOSUREDISTANCE),
  BE(f_Entry,			EDIF_TOK_ENTRY),
  BE(f_Exactly,			EDIF_TOK_EXACTLY),
  BE(f_External,		EDIF_TOK_EXTERNAL),
  BE(f_Fabricate,		EDIF_TOK_FABRICATE),
  BE(f_Figure,			EDIF_TOK_FIGURE),
  BE(f_FigureArea,		EDIF_TOK_FIGUREAREA),
  BE(f_FigureGroup,		EDIF_TOK_FIGUREGROUP),
  BE(f_FigureGroupObject,	EDIF_TOK_FIGUREGROUPOBJECT),
  BE(f_FigureGroupOverride,	EDIF_TOK_FIGUREGROUPOVERRIDE),
  BE(f_FigureGroupRef,		EDIF_TOK_FIGUREGROUPREF),
  BE(f_FigurePerimeter,		EDIF_TOK_FIGUREPERIMETER),
  BE(f_FigureWidth,		EDIF_TOK_FIGUREWIDTH),
  BE(f_FillPattern,		EDIF_TOK_FILLPATTERN),
  BE(f_Follow,			EDIF_TOK_FOLLOW),
  BE(f_ForbiddenEvent,		EDIF_TOK_FORBIDDENEVENT),
  BE(f_GlobalPortRef,		EDIF_TOK_GLOBALPORTREF),
  BE(f_GreaterThan,		EDIF_TOK_GREATERTHAN),
  BE(f_GridMap,			EDIF_TOK_GRIDMAP),
  BE(f_IncludeFigureGroup,	EDIF_TOK_INCLUDEFIGUREGROUP),
  BE(f_Instance,		EDIF_TOK_INSTANCE),
  BE(f_InstanceBackAnnotate,	EDIF_TOK_INSTANCEBACKANNOTATE),
  BE(f_InstanceGroup,		EDIF_TOK_INSTANCEGROUP),
  BE(f_InstanceMap,		EDIF_TOK_INSTANCEMAP),
  BE(f_InstanceRef,		EDIF_TOK_INSTANCEREF),
  BE(f_Integer,			EDIF_TOK_INTEGER),
  BE(f_IntegerDisplay,		EDIF_TOK_INTEGERDISPLAY),
  BE(f_InterFigureGroupSpacing,	EDIF_TOK_INTERFIGUREGROUPSPACING),
  BE(f_Interface,		EDIF_TOK_INTERFACE),
  BE(f_Intersection,		EDIF_TOK_INTERSECTION),
  BE(f_IntraFigureGroupSpacing,	EDIF_TOK_INTRAFIGUREGROUPSPACING),
  BE(f_Inverse,			EDIF_TOK_INVERSE),
  BE(f_Joined,			EDIF_TOK_JOINED),
  BE(f_KeywordDisplay,		EDIF_TOK_KEYWORDDISPLAY),
  BE(f_KeywordMap,		EDIF_TOK_KEYWORDMAP),
  BE(f_LessThan,		EDIF_TOK_LESSTHAN),
  BE(f_Library,			EDIF_TOK_LIBRARY),
  BE(f_LibraryRef,		EDIF_TOK_LIBRARYREF),
  BE(f_ListOfNets,		EDIF_TOK_LISTOFNETS),
  BE(f_ListOfPorts,		EDIF_TOK_LISTOFPORTS),
  BE(f_LoadDelay,		EDIF_TOK_LOADDELAY),
  BE(f_LogicAssign,		EDIF_TOK_LOGICASSIGN),
  BE(f_LogicInput,		EDIF_TOK_LOGICINPUT),
  BE(f_LogicList,		EDIF_TOK_LOGICLIST),
  BE(f_LogicMapInput,		EDIF_TOK_LOGICMAPINPUT),
  BE(f_LogicMapOutput,		EDIF_TOK_LOGICMAPOUTPUT),
  BE(f_LogicOneOf,		EDIF_TOK_LOGICONEOF),
  BE(f_LogicOutput,		EDIF_TOK_LOGICOUTPUT),
  BE(f_LogicPort,		EDIF_TOK_LOGICPORT),
  BE(f_LogicRef,		EDIF_TOK_LOGICREF),
  BE(f_LogicValue,		EDIF_TOK_LOGICVALUE),
  BE(f_LogicWaveform,		EDIF_TOK_LOGICWAVEFORM),
  BE(f_Maintain,		EDIF_TOK_MAINTAIN),
  BE(f_Match,			EDIF_TOK_MATCH),
  BE(f_Member,			EDIF_TOK_MEMBER),
  BE(f_MiNoMax,			EDIF_TOK_MINOMAX),
  BE(f_MiNoMaxDisplay,		EDIF_TOK_MINOMAXDISPLAY),
  BE(f_Mnm,			EDIF_TOK_MNM),
  BE(f_MultipleValueSet,	EDIF_TOK_MULTIPLEVALUESET),
  BE(f_MustJoin,		EDIF_TOK_MUSTJOIN),
  BE(f_Name,			EDIF_TOK_NAME),
  BE(f_Net,			EDIF_TOK_NET),
  BE(f_NetBackAnnotate,		EDIF_TOK_NETBACKANNOTATE),
  BE(f_NetBundle,		EDIF_TOK_NETBUNDLE),
  BE(f_NetDelay,		EDIF_TOK_NETDELAY),
  BE(f_NetGroup,		EDIF_TOK_NETGROUP),
  BE(f_NetMap,			EDIF_TOK_NETMAP),
  BE(f_NetRef,			EDIF_TOK_NETREF),
  BE(f_NonPermutable,		EDIF_TOK_NONPERMUTABLE),
  BE(f_NotAllowed,		EDIF_TOK_NOTALLOWED),
  BE(f_NotchSpacing,		EDIF_TOK_NOTCHSPACING),
  BE(f_Number,			EDIF_TOK_NUMBER),
  BE(f_NumberDefinition,	EDIF_TOK_NUMBERDEFINITION),
  BE(f_NumberDisplay,		EDIF_TOK_NUMBERDISPLAY),
  BE(f_OffPageConnector,	EDIF_TOK_OFFPAGECONNECTOR),
  BE(f_OffsetEvent,		EDIF_TOK_OFFSETEVENT),
  BE(f_OpenShape,		EDIF_TOK_OPENSHAPE),
  BE(f_Origin,			EDIF_TOK_ORIGIN),
  BE(f_OverhangDistance,	EDIF_TOK_OVERHANGDISTANCE),
  BE(f_OverlapDistance,		EDIF_TOK_OVERLAPDISTANCE),
  BE(f_Oversize,		EDIF_TOK_OVERSIZE),
  BE(f_Page,			EDIF_TOK_PAGE),
  BE(f_PageSize,		EDIF_TOK_PAGESIZE),
  BE(f_Parameter,		EDIF_TOK_PARAMETER),
  BE(f_ParameterAssign,		EDIF_TOK_PARAMETERASSIGN),
  BE(f_ParameterDisplay,	EDIF_TOK_PARAMETERDISPLAY),
  BE(f_Path,			EDIF_TOK_PATH),
  BE(f_PathDelay,		EDIF_TOK_PATHDELAY),
  BE(f_Permutable,		EDIF_TOK_PERMUTABLE),
  BE(f_PhysicalDesignRule,	EDIF_TOK_PHYSICALDESIGNRULE),
  BE(f_Plug,			EDIF_TOK_PLUG),
  BE(f_Point,			EDIF_TOK_POINT),
  BE(f_PointDisplay,		EDIF_TOK_POINTDISPLAY),
  BE(f_PointList,		EDIF_TOK_POINTLIST),
  BE(f_Polygon,			EDIF_TOK_POLYGON),
  BE(f_Port,			EDIF_TOK_PORT),
  BE(f_PortBackAnnotate,	EDIF_TOK_PORTBACKANNOTATE),
  BE(f_PortBundle,		EDIF_TOK_PORTBUNDLE),
  BE(f_PortDelay,		EDIF_TOK_PORTDELAY),
  BE(f_PortGroup,		EDIF_TOK_PORTGROUP),
  BE(f_PortImplementation,	EDIF_TOK_PORTIMPLEMENTATION),
  BE(f_PortInstance,		EDIF_TOK_PORTINSTANCE),
  BE(f_PortList,		EDIF_TOK_PORTLIST),
  BE(f_PortListAlias,		EDIF_TOK_PORTLISTALIAS),
  BE(f_PortMap,			EDIF_TOK_PORTMAP),
  BE(f_PortRef,			EDIF_TOK_PORTREF),
  BE(f_Program,			EDIF_TOK_PROGRAM),
  BE(f_Property,		EDIF_TOK_PROPERTY),
  BE(f_PropertyDisplay,		EDIF_TOK_PROPERTYDISPLAY),
  BE(f_ProtectionFrame,		EDIF_TOK_PROTECTIONFRAME),
  BE(f_RangeVector,		EDIF_TOK_RANGEVECTOR),
  BE(f_Rectangle,		EDIF_TOK_RECTANGLE),
  BE(f_RectangleSize,		EDIF_TOK_RECTANGLESIZE),
  BE(f_Rename,			EDIF_TOK_RENAME),
  BE(f_Resolves,		EDIF_TOK_RESOLVES),
  BE(f_Scale,			EDIF_TOK_SCALE),
  BE(f_Section,			EDIF_TOK_SECTION),
  BE(f_Shape,			EDIF_TOK_SHAPE),
  BE(f_Simulate,		EDIF_TOK_SIMULATE),
  BE(f_SimulationInfo,		EDIF_TOK_SIMULATIONINFO),
  BE(f_SingleValueSet,		EDIF_TOK_SINGLEVALUESET),
  BE(f_Site,			EDIF_TOK_SITE),
  BE(f_Socket,			EDIF_TOK_SOCKET),
  BE(f_SocketSet,		EDIF_TOK_SOCKETSET),
  BE(f_Status,			EDIF_TOK_STATUS),
  BE(f_Steady,			EDIF_TOK_STEADY),
  BE(f_String,			EDIF_TOK_STRING),
  BE(f_StringDisplay,		EDIF_TOK_STRINGDISPLAY),
  BE(f_Strong,			EDIF_TOK_STRONG),
  BE(f_Symbol,			EDIF_TOK_SYMBOL),
  BE(f_Symmetry,		EDIF_TOK_SYMMETRY),
  BE(f_Table,			EDIF_TOK_TABLE),
  BE(f_TableDefault,		EDIF_TOK_TABLEDEFAULT),
  BE(f_Technology,		EDIF_TOK_TECHNOLOGY),
  BE(f_TimeInterval,		EDIF_TOK_TIMEINTERVAL),
  BE(f_Timing,			EDIF_TOK_TIMING),
  BE(f_Transform,		EDIF_TOK_TRANSFORM),
  BE(f_Transition,		EDIF_TOK_TRANSITION),
  BE(f_Trigger,			EDIF_TOK_TRIGGER),
  BE(f_Union,			EDIF_TOK_UNION),
  BE(f_View,			EDIF_TOK_VIEW),
  BE(f_ViewList,		EDIF_TOK_VIEWLIST),
  BE(f_ViewMap,			EDIF_TOK_VIEWMAP),
  BE(f_ViewRef,			EDIF_TOK_VIEWREF),
  BE(f_Visible,			EDIF_TOK_VISIBLE),
  BE(f_VoltageMap,		EDIF_TOK_VOLTAGEMAP),
  BE(f_WaveValue,		EDIF_TOK_WAVEVALUE),
  BE(f_Weak,			EDIF_TOK_WEAK),
  BE(f_WeakJoined,		EDIF_TOK_WEAKJOINED),
  BE(f_When,			EDIF_TOK_WHEN),
  BE(f_Written,			EDIF_TOK_WRITTEN)
};
static int BinderDefSize = sizeof(BinderDef) / sizeof(Binder);
/*
 *	Keyword table:
 *
 *	  This hash table holds all strings which may have to be matched
 *	to. WARNING: it is assumed that there is no overlap of the 'token'
 *	and 'context' strings.
 */
typedef struct Keyword {
  struct Keyword *Next;	 	/* pointer to next entry */
  char *String;			/* pointer to associated string */
} Keyword;
#define	KEYWORD_HASH	127	/* hash table size */
static Keyword *KeywordTable[KEYWORD_HASH];
/*
 *	Enter keyword:
 *
 *	  The passed string is entered into the keyword hash table.
 */
static void EnterKeyword(str)
char *str;
{
  /* 
   *	Locals.
   */
  register Keyword *key;
  register unsigned int hsh;
  register char *cp;
  /*
   *	Create the hash code, and add an entry to the table.
   */
  for (hsh = 0, cp = str; *cp; hsh += hsh + *cp++);
  hsh %= KEYWORD_HASH;
  key = (Keyword *) Malloc(sizeof(Keyword));
  key->Next = KeywordTable[hsh];
  (KeywordTable[hsh] = key)->String = str;
}
/*
 *	Find keyword:
 *
 *	  The passed string is located within the keyword table. If an
 *	entry exists, then the value of the keyword string is returned. This
 *	is real useful for doing string comparisons by pointer value later.
 *	If there is no match, a NULL is returned.
 */
static char *FindKeyword(str)
char *str;
{
  /*
   *	Locals.
   */
  register Keyword *wlk,*owk;
  register unsigned int hsh;
  register char *cp;
  char lower[IDENT_LENGTH + 1];
  /*
   *	Create a lower case copy of the string.
   */
  for (cp = lower; *str;)
    if (isupper( (int) *str))
      *cp++ = tolower( (int) *str++);
    else
      *cp++ = *str++;
  *cp = '\0';
  /*
   *	Search the hash table for a match.
   */
  for (hsh = 0, cp = lower; *cp; hsh += hsh + *cp++);
  hsh %= KEYWORD_HASH;
  for (owk = NULL, wlk = KeywordTable[hsh]; wlk; wlk = (owk = wlk)->Next)
    if (!strcmp(wlk->String,lower)){
      /*
       *	Readjust the LRU.
       */
      if (owk){
      	owk->Next = wlk->Next;
      	wlk->Next = KeywordTable[hsh];
      	KeywordTable[hsh] = wlk;
      }
      return (wlk->String);
    }
  return (NULL);
}
/*
 *	Token hash table.
 */
#define	TOKEN_HASH	51
static Token *TokenHash[TOKEN_HASH];
/*
 *	Find token:
 *
 *	  A pointer to the token of the passed code is returned. If
 *	no such beastie is present a NULL is returned instead.
 */
static Token *FindToken(cod)
register int cod;
{
  /*
   *	Locals.
   */
  register Token *wlk,*owk;
  register unsigned int hsh;
  /*
   *	Search the hash table for a matching token.
   */
  hsh = cod % TOKEN_HASH;
  for (owk = NULL, wlk = TokenHash[hsh]; wlk; wlk = (owk = wlk)->Next)
    if (cod == wlk->Code){
      if (owk){
      	owk->Next = wlk->Next;
      	wlk->Next = TokenHash[hsh];
      	TokenHash[hsh] = wlk;
      }
      break;
    }
  return (wlk);
}
/*
 *	Context hash table.
 */
#define	CONTEXT_HASH	127
static Context *ContextHash[CONTEXT_HASH];
/*
 *	Find context:
 *
 *	  A pointer to the context of the passed code is returned. If
 *	no such beastie is present a NULL is returned instead.
 */
static Context *FindContext(cod)
register int cod;
{
  /*
   *	Locals.
   */
  register Context *wlk,*owk;
  register unsigned int hsh;
  /*
   *	Search the hash table for a matching context.
   */
  hsh = cod % CONTEXT_HASH;
  for (owk = NULL, wlk = ContextHash[hsh]; wlk; wlk = (owk = wlk)->Next)
    if (cod == wlk->Code){
      if (owk){
      	owk->Next = wlk->Next;
      	wlk->Next = ContextHash[hsh];
      	ContextHash[hsh] = wlk;
      }
      break;
    }
  return (wlk);
}
/*
 *	Token stacking variables.
 */
#ifdef	DEBUG
#define	TS_DEPTH	8
#define	TS_MASK		(TS_DEPTH - 1)
static unsigned int TSP = 0;		/* token stack pointer */
static char *TokenStack[TS_DEPTH];	/* token name strings */
static short TokenType[TS_DEPTH];	/* token types */
/*
 *	Stack:
 *
 *	  Add a token to the debug stack. The passed string and type are
 *	what is to be pushed.
 */
static Stack(str,typ)
char *str;
int typ;
{
  /*
   *	Free any previous string, then push.
   */
  if (TokenStack[TSP & TS_MASK])
    Free(TokenStack[TSP & TS_MASK]);
  TokenStack[TSP & TS_MASK] = strcpy(Malloc(strlen(str) + 1),str);
  TokenType[TSP & TS_MASK] = typ;
  TSP += 1;
}
/*
 *	Dump stack:
 *
 *	  This displays the last set of accumulated tokens.
 */
static DumpStack()
{
  /*
   *	Locals.
   */
  register int i;
  register Context *cxt;
  register Token *tok;
  register char *nam;
  /*
   *	Run through the list displaying the oldest first.
   */
  fprintf(Error,"\n\n");
  for (i = 0; i < TS_DEPTH; i += 1)
    if (TokenStack[(TSP + i) & TS_MASK]){
      /*
       *	Get the type name string.
       */
      if (cxt = FindContext(TokenType[(TSP + i) & TS_MASK]))
        nam = cxt->Name;
      else if (tok = FindToken(TokenType[(TSP + i) & TS_MASK]))
        nam = tok->Name;
      else switch (TokenType[(TSP + i) & TS_MASK]){
      	case IDENT:	nam = "IDENT";		break;
      	case INT:	nam = "INT";		break;
      	case KEYWORD:	nam = "KEYWORD";	break;
      	case STR:	nam = "STR";		break;
      	default:	nam = "?";		break;
      }
      /*
       *	Now print the token state.
       */
      fprintf(Error,"%2d %-16.16s '%s'\n",TS_DEPTH - i,nam,
        TokenStack[(TSP + i) & TS_MASK]);
    }
  fprintf(Error,"\n");
}
#else
#define	Stack(s,t)
#endif	/* DEBUG */
/*
 *	Parser state variables.
 */
static FILE *Input = NULL;		/* input stream */
static FILE *Error = NULL;		/* error stream */
static char *InFile;			/* file name on the input stream */
static long LineNumber;			/* current input line number */
static ContextCar *CSP = NULL;		/* top of context stack */
static char yytext[IDENT_LENGTH + 1];	/* token buffer */
static char CharBuf[IDENT_LENGTH + 1];	/* garbage buffer */
/*
 *	yyerror:
 *
 *	  Standard error reporter, it prints out the passed string
 *	preceeded by the current filename and line number.
 */
static void yyerror(const char *ers)
{
#ifdef	DEBUG
  DumpStack();
#endif	/* DEBUG */
  fprintf(Error,"%s, line %ld: %s\n",InFile,LineNumber,ers);
}
/*
 *	String bucket definitions.
 */
#define	BUCKET_SIZE	64
typedef struct Bucket {
  struct Bucket *Next;			/* pointer to next bucket */
  int Index;				/* pointer to next free slot */
  char Data[BUCKET_SIZE];		/* string data */
} Bucket;
static Bucket *CurrentBucket = NULL;	/* string bucket list */
static int StringSize = 0;		/* current string length */
/*
 *	Push string:
 *
 *	  This adds the passed charater to the current string bucket.
 */
static void PushString(chr)
char chr;
{
  /*
   *	Locals.
   */
  register Bucket *bck;
  /*
   *	Make sure there is room for the push.
   */
  if ((bck = CurrentBucket)->Index >= BUCKET_SIZE){
    bck = (Bucket *) Malloc(sizeof(Bucket));
    bck->Next = CurrentBucket;
    (CurrentBucket = bck)->Index = 0;
  }
  /*
   *	Push the character.
   */
  bck->Data[bck->Index++] = chr;
  StringSize += 1;
}
/*
 *	Form string:
 *
 *	  This converts the current string bucket into a real live string,
 *	whose pointer is returned.
 */
static char *FormString()
{
  /*
   *	Locals.
   */
  register Bucket *bck;
  register char *cp;
  /*
   *	Allocate space for the string, set the pointer at the end.
   */
  cp = (char *) Malloc(StringSize + 1);
  
  cp += StringSize;
  *cp-- = '\0';
  /*
   *	Yank characters out of the bucket.
   */
  for (bck = CurrentBucket; bck->Index || bck->Next;){
    if (!bck->Index){
      CurrentBucket = bck->Next;
      Free(bck);
      bck = CurrentBucket;
    }
    *cp-- = bck->Data[--bck->Index];
  }
  /* reset buffer size  to zero */
  StringSize =0;
  return (cp + 1);
}
/*
 *	Parse EDIF:
 *
 *	  This builds the context tree and then calls the real parser.
 *	It is passed two file streams, the first is where the input comes
 *	from; the second is where error messages get printed.
 */
void ParseEDIF(char* filename,FILE* err)
{
  /*
   *	Locals.
   */
  register int i;
  static int ContextDefined = 1;
  /*
   *	Set up the file state to something useful.
   */
  InFile = filename;
  Input = fopen(filename,"r");
  Error = err;
  LineNumber = 1;
  /*
   *	Define both the enabled token and context strings.
   */
  if (ContextDefined){
    for (i = TokenDefSize; i--; EnterKeyword(TokenDef[i].Name)){
      register unsigned int hsh;
      hsh = TokenDef[i].Code % TOKEN_HASH;
      TokenDef[i].Next = TokenHash[hsh];
      TokenHash[hsh] = &TokenDef[i];
    }
    for (i = ContextDefSize; i--; EnterKeyword(ContextDef[i].Name)){
      register unsigned int hsh;
      hsh = ContextDef[i].Code % CONTEXT_HASH;
      ContextDef[i].Next = ContextHash[hsh];
      ContextHash[hsh] = &ContextDef[i];
    }
    /*
     *	Build the context tree.
     */
    for (i = BinderDefSize; i--;){
      register Context *cxt;
      register int j;
      /*
       *	Define the current context to have carriers bound to it.
       */
      cxt = FindContext(BinderDef[i].Origin);
      for (j = BinderDef[i].FollowerSize; j--;){
        register ContextCar *cc;
        /*
         *	Add carriers to the current context.
         */
        cc = (ContextCar *) Malloc(sizeof(ContextCar));
        cc->Next = cxt->Context;
        (cxt->Context = cc)->Context =
          FindContext(ABS(BinderDef[i].Follower[j]));
        cc->u.Single = BinderDef[i].Follower[j] < 0;
      }
    }
    /*
     *	Build the token tree.
     */
    for (i = TieDefSize; i--;){
      register Context *cxt;
      register int j;
      /*
       *	Define the current context to have carriers bound to it.
       */
      cxt = FindContext(TieDef[i].Origin);
      for (j = TieDef[i].EnableSize; j--;){
        register TokenCar *tc;
        /*
         *	Add carriers to the current context.
         */
        tc = (TokenCar *) Malloc(sizeof(TokenCar));
        tc->Next = cxt->Token;
        (cxt->Token = tc)->Token = FindToken(TieDef[i].Enable[j]);
      }
    }
    /*
     *	Put a bogus context on the stack which has 'EDIF' as its
     *	follower.
     */
    CSP = (ContextCar *) Malloc(sizeof(ContextCar));
    CSP->Next = NULL;
    CSP->Context = FindContext(NULL);
    CSP->u.Used = NULL;
    ContextDefined = 0;
  }
  /*
   *	Create an initial, empty string bucket.
   */
  CurrentBucket = (Bucket *) Malloc(sizeof(Bucket));
  CurrentBucket->Next = 0;
  CurrentBucket->Index = 0;
  /*
   *	Fill the token stack with NULLs if debugging is enabled.
   */
#ifdef	DEBUG
  for (i = TS_DEPTH; i--; TokenStack[i] = NULL)
    if (TokenStack[i])
      Free(TokenStack[i]);
  TSP = 0;
#endif	/* DEBUG */
  /*
   *	Go parse things!
   */
  edifparse();
}
/*
 *	Match token:
 *
 *	  The passed string is looked up in the current context's token
 *	list to see if it is enabled. If so the token value is returned,
 *	if not then zero.
 */
static int MatchToken(str)
register char *str;
{
  /*
   *	Locals.
   */
  register TokenCar *wlk,*owk;
  /*
   *	Convert the string to the proper form, then search the token
   *	carrier list for a match.
   */
  str = FindKeyword(str);
  for (owk = NULL, wlk = CSP->Context->Token; wlk; wlk = (owk = wlk)->Next)
    if (str == wlk->Token->Name){
      if (owk){
        owk->Next = wlk->Next;
        wlk->Next = CSP->Context->Token;
        CSP->Context->Token = wlk;
      }
      return (wlk->Token->Code);
    }
  return (0);
}
/*
 *	Match context:
 *
 *	  If the passed keyword string is within the current context, the
 *	new context is pushed and token value is returned. A zero otherwise.
 */
static int MatchContext(str)
register char *str;
{
  /*
   *	Locals.
   */
  register ContextCar *wlk,*owk;
  /*
   *	See if the context is present.
   */
  str = FindKeyword(str);
  for (owk = NULL, wlk = CSP->Context->Context; wlk; wlk = (owk = wlk)->Next)
    if (str == wlk->Context->Name){
      if (owk){
      	owk->Next = wlk->Next;
      	wlk->Next = CSP->Context->Context;
      	CSP->Context->Context = wlk;
      }
      /*
       *	If a single context, make sure it isn't already used.
       */
      if (wlk->u.Single){
      	register UsedCar *usc;
      	for (usc = CSP->u.Used; usc; usc = usc->Next)
      	  if (usc->Code == wlk->Context->Code)
      	    break;
      	if (usc){
      	  sprintf(CharBuf,"'%s' is used more than once within '%s'",
      	    str,CSP->Context->Name);
      	  yyerror(CharBuf);
      	} else {
      	  usc = (UsedCar *) Malloc(sizeof(UsedCar));
      	  usc->Next = CSP->u.Used;
      	  (CSP->u.Used = usc)->Code = wlk->Context->Code;
      	}
      }
      /*
       *	Push the new context.
       */
      owk = (ContextCar *) Malloc(sizeof(ContextCar));
      owk->Next = CSP;
      (CSP = owk)->Context = wlk->Context;
      owk->u.Used = NULL;
      return (wlk->Context->Code);
    }
  return (0);
}
/*
 *	PopC:
 *
 *	  This pops the current context.
 */
static void PopC()
{
  /*
   *	Locals.
   */
  register UsedCar *usc;
  register ContextCar *csp;
  /*
   *	Release single markers and pop context.
   */
  while ( (usc = CSP->u.Used) ){
    CSP->u.Used = usc->Next;
    Free(usc);
  }
  csp = CSP->Next;
  Free(CSP);
  CSP = csp;
}
/*
 *	Lexical analyzer states.
 */
#define	L_START		0
#define	L_INT		1
#define	L_IDENT		2
#define	L_KEYWORD	3
#define	L_STRING	4
#define	L_KEYWORD2	5
#define	L_ASCIICHAR	6
#define	L_ASCIICHAR2	7
/*
 *	yylex:
 *
 *	  This is the lexical analyzer called by the YACC/BISON parser.
 *	It returns a pretty restricted set of token types and does the
 *	context movement when acceptable keywords are found. The token
 *	value returned is a NULL terminated string to allocated storage
 *	(ie - it should get released some time) with some restrictions.
 *	  The token value for integers is strips a leading '+' if present.
 *	String token values have the leading and trailing '"'-s stripped.
 *	'%' conversion characters in string values are passed converted.
 *	The '(' and ')' characters do not have a token value.
 */
static int yylex()
{
  /*
   *	Locals.
   */
  register int c,s,l;
  /*
   *	Keep on sucking up characters until we find something which
   *	explicitly forces us out of this function.
   */
  for (s = L_START, l = 0; 1;){
    yytext[l++] = c = Getc(Input);
    switch (s){
      /*
       *	Starting state, look for something resembling a token.
       */
      case L_START:
        if (isdigit(c) || c == '-')
          s = L_INT;
        else if (isalpha(c) || c == '&')
          s = L_IDENT;
        else if (isspace(c)){
          if (c == '\n')
            LineNumber += 1;
          l = 0;
        } else if (c == '('){
          l = 0;
          s = L_KEYWORD;
        } else if (c == '"')
          s = L_STRING;
        else if (c == '+'){
          l = 0;				/* strip '+' */
          s = L_INT;
        } else if (c == EOF)
          return ('\0');
        else {
          yytext[1] = '\0';
          Stack(yytext,c);
          return (c);
        }
        break;
      /*
       *	Suck up the integer digits.
       */
      case L_INT:
        if (isdigit(c))
          break;
        Ungetc(c);
        yytext[--l] = '\0';
        yylval.s = strcpy(Malloc(l + 1),yytext);
        Stack(yytext,EDIF_TOK_INT);
        return (EDIF_TOK_INT);
      /*
       *	Grab an identifier, see if the current context enables
       *	it with a specific token value.
       */
      case L_IDENT:
        if (isalpha(c) || isdigit(c) || c == '_')
          break;
        Ungetc(c);
        yytext[--l] = '\0';
        if (CSP->Context->Token && (c = MatchToken(yytext))){
          Stack(yytext,c);
          return (c);
        }
        yylval.s = strcpy(Malloc(l + 1),yytext);
        Stack(yytext, EDIF_TOK_IDENT);
        return (EDIF_TOK_IDENT);
      /*
       *	Scan until you find the start of an identifier, discard
       *	any whitespace found. On no identifier, return a '('.
       */
      case L_KEYWORD:
        if (isalpha(c) || c == '&'){
          s = L_KEYWORD2;
          break;
        } else if (isspace(c)){
          l = 0;
          break;
        }
        Ungetc(c);
        Stack("(",'(');
        return ('(');
      /*
       *	Suck up the keyword identifier, if it matches the set of
       *	allowable contexts then return its token value and push
       *	the context, otherwise just return the identifier string.
       */
      case L_KEYWORD2:
        if (isalpha(c) || isdigit(c) || c == '_')
          break;
        Ungetc(c);
        yytext[--l] = '\0';
        if ( (c = MatchContext(yytext)) ){
          Stack(yytext,c);
          return (c);
        }
        yylval.s = strcpy(Malloc(l + 1),yytext);
        Stack(yytext, EDIF_TOK_KEYWORD);
        return (EDIF_TOK_KEYWORD);
      /*
       *	Suck up string characters but once resolved they should
       *	be deposited in the string bucket because they can be
       *	arbitrarily long.
       */
      case L_STRING:
        if (c == '\n')
          LineNumber += 1;
        else if (c == '\r')
          ;
        else if (c == '"' || c == EOF){
          yylval.s = FormString();
          Stack(yylval.s, EDIF_TOK_STR);
          return (EDIF_TOK_STR);
        } else if (c == '%')
          s = L_ASCIICHAR;
        else
          PushString(c);
        l = 0;
        break;
      /*
       *	Skip white space and look for integers to be pushed
       *	as characters.
       */
      case L_ASCIICHAR:
        if (isdigit(c)){
          s = L_ASCIICHAR2;
          break;
        } else if (c == '%' || c == EOF)
          s = L_STRING;
        else if (c == '\n')
          LineNumber += 1;
        l = 0;
        break;
      /*
       *	Convert the accumulated integer into a char and push.
       */
      case L_ASCIICHAR2:
        if (isdigit(c))
          break;
        Ungetc(c);
        yytext[--l] = '\0';
        PushString(atoi(yytext));
        s = L_ASCIICHAR;
        l = 0;
        break;
    }
  }
}


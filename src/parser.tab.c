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
     TOK_PROGRAM = 258,
     TOK_BEGIN = 259,
     TOK_END = 260,
     TOK_FUNCTION = 261,
     TOK_RETURN = 262,
     TOK_MAIN = 263,
     TOK_STRUCT = 264,
     TOK_ENDSTRUCT = 265,
     TOK_VAR = 266,
     TOK_AUTO = 267,
     TOK_ARRAY = 268,
     TOK_OF = 269,
     TOK_INT = 270,
     TOK_FLOAT = 271,
     TOK_BOOL = 272,
     TOK_STRING = 273,
     TOK_VOID = 274,
     TOK_IMAGE = 275,
     TOK_MATRIX = 276,
     TOK_KERNEL = 277,
     TOK_PIXEL = 278,
     TOK_MATCH = 279,
     TOK_WHEN = 280,
     TOK_ENDMATCH = 281,
     TOK_IF = 282,
     TOK_THEN = 283,
     TOK_ELSE = 284,
     TOK_ENDIF = 285,
     TOK_FOR = 286,
     TOK_FOREACH = 287,
     TOK_IN = 288,
     TOK_TO = 289,
     TOK_DO = 290,
     TOK_ENDFOR = 291,
     TOK_STEP = 292,
     TOK_WHILE = 293,
     TOK_ENDWHILE = 294,
     TOK_PRINT = 295,
     TOK_INPUT = 296,
     TOK_TRUE = 297,
     TOK_FALSE = 298,
     TOK_AND = 299,
     TOK_OR = 300,
     TOK_NOT = 301,
     TOK_LOAD = 302,
     TOK_SAVE = 303,
     TOK_GRAYSCALE = 304,
     TOK_HSV = 305,
     TOK_BLUR = 306,
     TOK_THRESHOLD = 307,
     TOK_CANNY = 308,
     TOK_RESIZE = 309,
     TOK_ROTATE = 310,
     TOK_ERODE = 311,
     TOK_DILATE = 312,
     TOK_FLIP = 313,
     TOK_ASSIGN = 314,
     TOK_RANGE = 315,
     TOK_INC = 316,
     TOK_DEC = 317,
     TOK_PLUS_ASSIGN = 318,
     TOK_MINUS_ASSIGN = 319,
     TOK_MULT_ASSIGN = 320,
     TOK_DIV_ASSIGN = 321,
     TOK_CONV_OP = 322,
     TOK_PIPE_OP = 323,
     TOK_PLUS = 324,
     TOK_MINUS = 325,
     TOK_MULT = 326,
     TOK_DIV = 327,
     TOK_MOD = 328,
     TOK_EQ = 329,
     TOK_NEQ = 330,
     TOK_LEQ = 331,
     TOK_GEQ = 332,
     TOK_LT = 333,
     TOK_GT = 334,
     TOK_LBRACKET = 335,
     TOK_RBRACKET = 336,
     TOK_LPAREN = 337,
     TOK_RPAREN = 338,
     TOK_COLON = 339,
     TOK_COMMA = 340,
     TOK_DOT = 341,
     TOK_SEMI = 342,
     TOK_ID = 343,
     TOK_HEX_INT = 344,
     TOK_FLOAT_LIT = 345,
     TOK_INT_LIT = 346,
     TOK_STR = 347
   };
#endif
/* Tokens.  */
#define TOK_PROGRAM 258
#define TOK_BEGIN 259
#define TOK_END 260
#define TOK_FUNCTION 261
#define TOK_RETURN 262
#define TOK_MAIN 263
#define TOK_STRUCT 264
#define TOK_ENDSTRUCT 265
#define TOK_VAR 266
#define TOK_AUTO 267
#define TOK_ARRAY 268
#define TOK_OF 269
#define TOK_INT 270
#define TOK_FLOAT 271
#define TOK_BOOL 272
#define TOK_STRING 273
#define TOK_VOID 274
#define TOK_IMAGE 275
#define TOK_MATRIX 276
#define TOK_KERNEL 277
#define TOK_PIXEL 278
#define TOK_MATCH 279
#define TOK_WHEN 280
#define TOK_ENDMATCH 281
#define TOK_IF 282
#define TOK_THEN 283
#define TOK_ELSE 284
#define TOK_ENDIF 285
#define TOK_FOR 286
#define TOK_FOREACH 287
#define TOK_IN 288
#define TOK_TO 289
#define TOK_DO 290
#define TOK_ENDFOR 291
#define TOK_STEP 292
#define TOK_WHILE 293
#define TOK_ENDWHILE 294
#define TOK_PRINT 295
#define TOK_INPUT 296
#define TOK_TRUE 297
#define TOK_FALSE 298
#define TOK_AND 299
#define TOK_OR 300
#define TOK_NOT 301
#define TOK_LOAD 302
#define TOK_SAVE 303
#define TOK_GRAYSCALE 304
#define TOK_HSV 305
#define TOK_BLUR 306
#define TOK_THRESHOLD 307
#define TOK_CANNY 308
#define TOK_RESIZE 309
#define TOK_ROTATE 310
#define TOK_ERODE 311
#define TOK_DILATE 312
#define TOK_FLIP 313
#define TOK_ASSIGN 314
#define TOK_RANGE 315
#define TOK_INC 316
#define TOK_DEC 317
#define TOK_PLUS_ASSIGN 318
#define TOK_MINUS_ASSIGN 319
#define TOK_MULT_ASSIGN 320
#define TOK_DIV_ASSIGN 321
#define TOK_CONV_OP 322
#define TOK_PIPE_OP 323
#define TOK_PLUS 324
#define TOK_MINUS 325
#define TOK_MULT 326
#define TOK_DIV 327
#define TOK_MOD 328
#define TOK_EQ 329
#define TOK_NEQ 330
#define TOK_LEQ 331
#define TOK_GEQ 332
#define TOK_LT 333
#define TOK_GT 334
#define TOK_LBRACKET 335
#define TOK_RBRACKET 336
#define TOK_LPAREN 337
#define TOK_RPAREN 338
#define TOK_COLON 339
#define TOK_COMMA 340
#define TOK_DOT 341
#define TOK_SEMI 342
#define TOK_ID 343
#define TOK_HEX_INT 344
#define TOK_FLOAT_LIT 345
#define TOK_INT_LIT 346
#define TOK_STR 347




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern int line_num;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", line_num, s);
    exit(1);
}


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 304 "src/parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNRULES -- Number of states.  */
#define YYNSTATES  355

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    12,    16,    18,    21,    23,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    56,    63,    73,    83,    85,    86,    92,    98,
     104,   110,   115,   117,   120,   125,   137,   148,   159,   169,
     179,   188,   190,   194,   198,   204,   209,   214,   218,   220,
     223,   225,   227,   229,   231,   233,   235,   237,   239,   241,
     244,   247,   252,   257,   262,   267,   272,   276,   280,   282,
     287,   291,   298,   307,   313,   321,   329,   336,   342,   353,
     363,   376,   388,   397,   405,   414,   420,   422,   425,   430,
     434,   438,   442,   446,   450,   453,   458,   462,   464,   469,
     474,   479,   484,   489,   494,   499,   504,   509,   514,   519,
     524,   526,   530,   534,   538,   542,   546,   550,   554,   558,
     562,   566,   570,   574,   578,   582,   586,   590,   593,   596,
     600,   602,   604,   606,   608,   610,   612,   614,   616,   618,
     620,   624,   628
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      94,     0,    -1,     3,    88,    95,   107,    -1,     3,    88,
     107,    -1,     3,    88,    95,    -1,    96,    -1,    95,    96,
      -1,   100,    -1,   101,    -1,   104,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    98,    -1,    88,    -1,    13,
      80,    91,    81,    14,    97,    -1,    13,    80,   124,    81,
      14,    97,    -1,    13,    80,    91,    81,    80,    91,    81,
      14,    97,    -1,    13,    80,   124,    81,    80,   124,    81,
      14,    97,    -1,    87,    -1,    -1,    11,    88,    84,    97,
      99,    -1,    12,    88,    59,   124,    99,    -1,    97,    88,
      59,   124,    99,    -1,     9,    88,   102,    10,    99,    -1,
       9,    88,    10,    99,    -1,   103,    -1,   102,   103,    -1,
      88,    84,    97,    99,    -1,     6,    88,    82,   105,    83,
      84,    97,     4,   108,     5,    99,    -1,     6,    88,    82,
      83,    84,    97,     4,   108,     5,    99,    -1,     6,    88,
      82,   105,    83,    84,    97,     4,     5,    99,    -1,     6,
      88,    82,    83,    84,    97,     4,     5,    99,    -1,     6,
      88,    82,   105,    83,    84,    97,   107,    99,    -1,     6,
      88,    82,    83,    84,    97,   107,    99,    -1,   106,    -1,
     105,    85,   106,    -1,    88,    84,    97,    -1,     8,     4,
     108,     5,    99,    -1,     4,   108,     5,    99,    -1,     8,
       4,     5,    99,    -1,     4,     5,    99,    -1,   109,    -1,
     108,   109,    -1,   100,    -1,   110,    -1,   112,    -1,   113,
      -1,   114,    -1,   115,    -1,   116,    -1,   119,    -1,   120,
      -1,   121,    99,    -1,   124,    99,    -1,   111,    59,   124,
      99,    -1,   111,    63,   124,    99,    -1,   111,    64,   124,
      99,    -1,   111,    65,   124,    99,    -1,   111,    66,   124,
      99,    -1,   111,    61,    99,    -1,   111,    62,    99,    -1,
      88,    -1,   111,    80,   124,    81,    -1,   111,    86,    88,
      -1,    27,   124,    28,   108,    30,    99,    -1,    27,   124,
      28,   108,    29,   108,    30,    99,    -1,    27,   124,    28,
      30,    99,    -1,    27,   124,    28,    29,   108,    30,    99,
      -1,    27,   124,    28,   108,    29,    30,    99,    -1,    38,
     124,    35,   108,    39,    99,    -1,    38,   124,    35,    39,
      99,    -1,    31,   111,    59,   124,    34,   124,    35,   108,
      36,    99,    -1,    31,   111,    59,   124,    34,   124,    35,
      36,    99,    -1,    31,   111,    59,   124,    34,   124,    37,
     124,    35,   108,    36,    99,    -1,    31,   111,    59,   124,
      34,   124,    37,   124,    35,    36,    99,    -1,    32,    88,
      33,   124,    35,   108,    36,    99,    -1,    32,    88,    33,
     124,    35,    36,    99,    -1,    24,   124,    25,   124,    84,
     108,    26,    99,    -1,    24,   124,   117,    26,    99,    -1,
     118,    -1,   117,   118,    -1,    25,   124,    84,   108,    -1,
      25,   124,    84,    -1,    40,   124,    99,    -1,    40,    92,
      99,    -1,    41,   111,    99,    -1,     7,   124,    99,    -1,
       7,    99,    -1,    88,    82,   123,    83,    -1,    88,    82,
      83,    -1,   122,    -1,    47,    82,   123,    83,    -1,    48,
      82,   123,    83,    -1,    49,    82,   123,    83,    -1,    50,
      82,   123,    83,    -1,    51,    82,   123,    83,    -1,    52,
      82,   123,    83,    -1,    53,    82,   123,    83,    -1,    54,
      82,   123,    83,    -1,    55,    82,   123,    83,    -1,    56,
      82,   123,    83,    -1,    57,    82,   123,    83,    -1,    58,
      82,   123,    83,    -1,   124,    -1,   123,    85,   124,    -1,
     124,    69,   124,    -1,   124,    70,   124,    -1,   124,    71,
     124,    -1,   124,    72,   124,    -1,   124,    73,   124,    -1,
     124,    74,   124,    -1,   124,    75,   124,    -1,   124,    76,
     124,    -1,   124,    77,   124,    -1,   124,    78,   124,    -1,
     124,    79,   124,    -1,   124,    44,   124,    -1,   124,    45,
     124,    -1,   124,    67,   124,    -1,   124,    68,   124,    -1,
      46,   124,    -1,    70,   124,    -1,    82,   124,    83,    -1,
     111,    -1,   121,    -1,    91,    -1,    90,    -1,    89,    -1,
      42,    -1,    43,    -1,    92,    -1,   125,    -1,   126,    -1,
     124,    60,   124,    -1,    80,   123,    81,    -1,    80,    81,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    56,    60,    61,    65,    66,    67,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      74,    78,    79,    80,    81,    85,    86,    90,    91,    92,
      96,    97,   101,   102,   106,   110,   111,   112,   113,   114,
     115,   119,   120,   124,   128,   129,   130,   131,   135,   136,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   154,   155,   156,   157,   158,   159,   160,   164,   165,
     166,   170,   171,   172,   173,   174,   178,   179,   183,   184,
     185,   186,   190,   191,   195,   196,   200,   201,   205,   206,
     210,   211,   212,   216,   217,   221,   222,   223,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     242,   243,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     278,   282,   283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PROGRAM", "TOK_BEGIN", "TOK_END",
  "TOK_FUNCTION", "TOK_RETURN", "TOK_MAIN", "TOK_STRUCT", "TOK_ENDSTRUCT",
  "TOK_VAR", "TOK_AUTO", "TOK_ARRAY", "TOK_OF", "TOK_INT", "TOK_FLOAT",
  "TOK_BOOL", "TOK_STRING", "TOK_VOID", "TOK_IMAGE", "TOK_MATRIX",
  "TOK_KERNEL", "TOK_PIXEL", "TOK_MATCH", "TOK_WHEN", "TOK_ENDMATCH",
  "TOK_IF", "TOK_THEN", "TOK_ELSE", "TOK_ENDIF", "TOK_FOR", "TOK_FOREACH",
  "TOK_IN", "TOK_TO", "TOK_DO", "TOK_ENDFOR", "TOK_STEP", "TOK_WHILE",
  "TOK_ENDWHILE", "TOK_PRINT", "TOK_INPUT", "TOK_TRUE", "TOK_FALSE",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_LOAD", "TOK_SAVE", "TOK_GRAYSCALE",
  "TOK_HSV", "TOK_BLUR", "TOK_THRESHOLD", "TOK_CANNY", "TOK_RESIZE",
  "TOK_ROTATE", "TOK_ERODE", "TOK_DILATE", "TOK_FLIP", "TOK_ASSIGN",
  "TOK_RANGE", "TOK_INC", "TOK_DEC", "TOK_PLUS_ASSIGN", "TOK_MINUS_ASSIGN",
  "TOK_MULT_ASSIGN", "TOK_DIV_ASSIGN", "TOK_CONV_OP", "TOK_PIPE_OP",
  "TOK_PLUS", "TOK_MINUS", "TOK_MULT", "TOK_DIV", "TOK_MOD", "TOK_EQ",
  "TOK_NEQ", "TOK_LEQ", "TOK_GEQ", "TOK_LT", "TOK_GT", "TOK_LBRACKET",
  "TOK_RBRACKET", "TOK_LPAREN", "TOK_RPAREN", "TOK_COLON", "TOK_COMMA",
  "TOK_DOT", "TOK_SEMI", "TOK_ID", "TOK_HEX_INT", "TOK_FLOAT_LIT",
  "TOK_INT_LIT", "TOK_STR", "$accept", "Program", "Declarations", "Decl",
  "Type", "ArrayType", "OptSemi", "VarDecl", "StructDecl", "StructMembers",
  "StructMember", "FuncDecl", "ParamList", "Param", "MainBlock",
  "Statements", "Statement", "AssignStmt", "LValue", "IfStmt", "WhileStmt",
  "ForStmt", "ForeachStmt", "MatchStmt", "MatchWhenList", "MatchWhen",
  "IOStmt", "ReturnStmt", "FuncCallStmt", "ImageOpFunc", "ArgList", "Expr",
  "RangeExpr", "ArrayInitializer", 0
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
     345,   346,   347
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   103,   104,   104,   104,   104,   104,
     104,   105,   105,   106,   107,   107,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     6,     9,     9,     1,     0,     5,     5,     5,
       5,     4,     1,     2,     4,    11,    10,    10,     9,     9,
       8,     1,     3,     3,     5,     4,     4,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     4,     4,     4,     4,     3,     3,     1,     4,
       3,     6,     8,     5,     7,     7,     6,     5,    10,     9,
      12,    11,     8,     7,     8,     5,     1,     2,     4,     3,
       3,     3,     3,     3,     2,     4,     3,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    20,     4,     5,     0,    19,     7,     8,     9,     3,
      26,    26,     0,     0,     0,     0,     0,     0,     0,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,   134,   133,
     132,   137,    50,     0,    48,    51,   130,    52,    53,    54,
      55,    56,    57,    58,    26,    97,    26,   138,   139,     0,
       0,     0,     0,     0,     0,     6,     2,     0,    25,    47,
      68,    94,   130,   131,    26,     0,     0,    68,     0,     0,
       0,    26,    26,    26,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   142,     0,
     110,     0,     0,    26,    49,     0,    26,    26,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,    26,     0,    26,     0,     0,    32,     0,
       0,   132,     0,     0,    93,     0,     0,    86,     0,     0,
       0,     0,    91,    90,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   129,
      96,     0,    45,    26,    66,    67,    26,    26,    26,    26,
       0,    70,   123,   124,   140,   125,   126,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,    41,    46,    26,    31,     0,    26,    33,    26,    26,
       0,     0,    26,     0,     0,    26,    87,     0,    26,     0,
       0,     0,    26,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   111,    95,    61,    62,
      63,    64,    65,    69,     0,     0,     0,     0,    44,    26,
      30,    27,    28,     0,     0,     0,     0,    29,    89,     0,
      85,     0,    73,     0,    26,     0,     0,    77,    26,     0,
      43,     0,    42,    34,    21,     0,    22,     0,    88,    89,
      26,    26,     0,    71,     0,    26,     0,    76,     0,    26,
       0,     0,     0,    26,    88,    74,    75,    26,     0,     0,
      83,    26,    26,     0,    40,     0,    26,     0,     0,    84,
      72,    26,     0,     0,    82,    38,    26,    26,     0,    39,
      23,    24,    79,    26,     0,    36,    37,    26,    78,    26,
       0,    35,    81,    26,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    22,    23,    24,    25,    89,    62,    27,   157,
     158,    28,   220,   221,    29,    63,    64,    65,    92,    67,
      68,    69,    70,    71,   166,   167,    72,    73,    93,    75,
     119,    76,    77,    78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
       4,   -72,    46,     2,  -156,   389,    -1,    82,     0,    14,
      33,    25,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,     2,  -156,    50,  -156,  -156,  -156,  -156,  -156,
     -15,  2599,  2752,  2752,    59,    64,  2752,  2803,    59,  -156,
    -156,  2752,    58,    73,    75,    77,    78,    79,    80,    83,
      85,    86,    87,    88,  2752,  2650,  2752,   -39,  -156,  -156,
    -156,  -156,  -156,   717,  -156,  -156,     3,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,    55,  -156,  3011,  -156,  -156,    92,
     818,    -8,    32,    97,  2854,  -156,  -156,   105,  -156,  -156,
      93,  -156,    -4,  -156,  3011,   133,   440,  -156,   -32,   138,
     561,  3032,  3011,   -27,   116,  2752,  2752,  2752,  2752,  2752,
    2752,  2752,  2752,  2752,  2752,  2752,  2752,    17,  -156,    10,
    3189,  3109,  2701,   -15,  -156,  2752,   -15,   -15,  2752,  2752,
    2752,  2752,  2752,    94,  -156,  2752,  2752,  2752,  2752,  2752,
    2752,  2752,  2752,  2752,  2752,  2752,  2752,  2752,  2752,  2752,
    2752,  -156,    -9,   -15,   906,   -15,    96,    -7,  -156,    19,
    2752,   102,  3129,  2752,  -156,  2752,     5,  -156,  1344,  2752,
    2752,  1516,  -156,  -156,  -156,   -38,   -22,   -12,    18,    21,
      28,    29,    34,    52,    56,    60,    61,  -156,  2752,  -156,
    -156,    65,  -156,  3011,  -156,  -156,  3011,  3011,  3011,  3011,
    3149,  -156,   467,  3209,  3189,    17,    17,   -16,   -16,    17,
      17,    17,   119,   119,   119,   119,   119,   119,   100,   110,
      68,  -156,  -156,   -15,  -156,    19,   -15,  -156,   -15,  3011,
      -2,    12,  3011,  3068,  2752,   -15,  -156,  2548,   -15,  1430,
    2881,  2946,   -15,  1602,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  3189,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,    19,    19,   111,   108,  -156,   -15,
    -156,  -156,  -156,    19,   106,    19,  2752,  -156,  2548,  3088,
    -156,  1688,  -156,  1774,   -15,  2752,  1860,  -156,   -15,    89,
    -156,    19,  -156,  -156,  -156,   117,  -156,  3169,  1946,  2548,
     -15,   -15,  2032,  -156,  2926,   -15,  2118,  -156,   994,   -15,
      90,   200,   201,   -15,  2548,  -156,  -156,   -15,  2204,  2752,
    -156,   -15,   -15,  1082,  -156,  1170,   -15,    19,    19,  -156,
    -156,   -15,  2290,  2991,  -156,   130,   -15,   -15,  1258,  -156,
    -156,  -156,  -156,   -15,  2376,   131,   130,   -15,  -156,   -15,
    2462,   131,  -156,   -15,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   197,  -155,  -156,   264,     6,  -156,  -156,
      63,  -156,  -156,   -46,   -21,    74,   -58,  -156,    -5,  -156,
    -156,  -156,  -156,  -156,  -156,    62,  -156,  -156,    45,  -156,
    2932,   543,  -156,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -138
static const yytype_int16 yytable[] =
{
      66,    86,   155,   226,   228,   124,     5,     1,     6,    26,
       7,     8,   273,     9,    10,    11,     3,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   275,   169,    26,    98,
     234,   235,    11,   103,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   122,   137,   244,     4,   188,   132,   -20,
      74,   138,   139,   132,   133,   142,   143,   144,    66,   133,
      88,   245,   125,   188,   126,   127,   128,   129,   130,   131,
     269,   246,    88,   188,   218,    66,   132,   137,   274,   219,
     156,   156,   133,   132,   138,   139,    80,    79,    81,   133,
      21,   187,   276,   308,   325,   188,   124,     7,     7,  -131,
    -131,   247,    82,   188,   248,    84,   188,    21,    74,   289,
     290,   249,   250,   188,   188,  -131,   159,   251,   294,   188,
     296,    83,  -131,  -131,  -131,    74,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,   252,   310,   188,    87,   253,
     105,   188,    88,   254,   255,   188,   188,    97,   257,    66,
     188,   266,    99,   267,   154,   106,   160,   107,   165,   108,
     109,   110,   111,    66,   163,   112,    66,   113,   114,   115,
     116,   170,   340,   341,   152,   122,   137,   135,   136,   137,
     225,   124,   201,   230,   264,   124,   138,   139,   140,   141,
     142,   143,   144,   137,   265,   291,   219,   295,   311,    74,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    74,   327,   328,    74,   -47,   -45,    85,
     227,   292,     0,   124,     0,     0,     0,     0,   236,     0,
       0,     0,    66,     0,    66,     0,     0,     0,    66,     0,
     124,     0,   239,     0,   124,   243,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,   309,     0,
       0,     0,     0,    66,   124,     0,    66,     0,    66,     0,
     124,    66,    74,     0,    74,     0,     0,     0,    74,   326,
       0,     0,   124,    66,    66,    91,     0,    66,     0,     0,
       0,    66,     0,    66,     0,     0,     0,     0,     0,    66,
       0,   281,     0,    66,     0,     0,     0,     0,    66,     0,
      66,     0,     0,    74,     0,     0,    74,    66,    74,     0,
       0,    74,     0,    66,     0,     0,     0,     0,   134,    66,
     151,     0,     0,    74,    74,    66,     0,    74,     0,     0,
       0,    74,   298,    74,     0,     0,     0,   302,   164,    74,
     306,     0,     0,    74,     0,   172,   173,   174,    74,     0,
      74,     0,     0,   314,     0,     0,     0,    74,     0,     0,
       0,     0,   323,    74,     0,     0,     0,   192,     0,    74,
     194,   195,   332,     0,    30,    74,    31,     0,     0,   338,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,   222,   350,   224,
      34,    35,     0,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    54,
     259,   260,   261,   262,     0,     0,     0,     0,   168,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,     0,     0,   135,   136,     0,   268,     0,     0,
     270,     0,   271,   272,     0,     0,   277,     0,     0,   280,
     137,     0,   282,     0,     0,     0,   287,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,   293,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,   303,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   316,     0,     0,     0,   320,
       0,     0,     0,   324,    94,    95,    96,   329,     0,   100,
     102,   330,     0,     0,   104,   334,   335,     0,     0,     0,
     339,     0,     0,     0,     0,   342,   171,   117,   120,   121,
     345,   346,     0,     0,     0,   135,   136,   348,     0,     0,
       0,   351,     0,   352,     0,     0,     0,   354,     0,     0,
       0,   137,     0,     0,     0,     0,     0,   162,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,     0,     0,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
       0,     0,     0,     0,     0,   120,     0,     0,   193,     0,
       0,   196,   197,   198,   199,   200,     0,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,   232,     0,   233,     0,
       0,     0,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,    31,     0,     0,     0,     9,    10,
      11,   256,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    32,     0,     0,    33,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    36,     0,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,   153,     0,    31,     0,     0,   304,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    32,     0,     0,    33,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,    36,     0,    37,    38,
      39,    40,   333,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,   223,     0,    31,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      32,     0,     0,    33,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    36,     0,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,   322,
       0,    31,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    32,     0,
       0,    33,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,    36,     0,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,   336,     0,    31,
       0,     0,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    32,     0,     0,    33,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
      36,     0,    37,    38,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,   337,     0,    31,     0,     0,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    32,     0,     0,    33,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,    36,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,   347,     0,    31,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    32,     0,     0,    33,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,    36,     0,    37,    38,
      39,    40,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    31,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    32,     0,
       0,    33,     0,   237,   238,    34,    35,     0,     0,     0,
       0,     0,    36,     0,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    31,     0,     0,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    32,     0,     0,    33,     0,   283,
     284,    34,    35,     0,     0,     0,     0,     0,    36,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    31,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      32,     0,     0,    33,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    36,   242,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    31,
       0,     0,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    32,     0,     0,    33,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
      36,   288,    37,    38,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    31,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    32,     0,     0,    33,     0,     0,   300,    34,
      35,     0,     0,     0,     0,     0,    36,     0,    37,    38,
      39,    40,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    31,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    32,     0,
       0,    33,     0,     0,   301,    34,    35,     0,     0,     0,
       0,     0,    36,     0,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    31,     0,     0,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    32,     0,     0,    33,     0,     0,
       0,    34,    35,     0,     0,     0,   305,     0,    36,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    31,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      32,     0,   313,    33,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    36,     0,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    31,
       0,     0,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    32,     0,     0,    33,
       0,     0,   317,    34,    35,     0,     0,     0,     0,     0,
      36,     0,    37,    38,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    31,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    32,     0,     0,    33,     0,     0,     0,    34,
      35,     0,     0,     0,   321,     0,    36,     0,    37,    38,
      39,    40,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    31,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    32,     0,
       0,    33,     0,     0,     0,    34,    35,     0,     0,     0,
     331,     0,    36,     0,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    31,     0,     0,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    32,     0,     0,    33,     0,     0,
       0,    34,    35,     0,     0,     0,   343,     0,    36,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    31,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      32,     0,     0,    33,     0,     0,     0,    34,    35,     0,
       0,     0,   349,     0,    36,     0,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    31,
       0,     0,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    32,     0,     0,    33,
       0,     0,     0,    34,    35,     0,     0,     0,   353,     0,
      36,     0,    37,    38,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    31,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    32,     0,     0,    33,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,    36,     0,    37,    38,
      39,    40,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,    88,    90,    58,    59,
      60,    61,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,   118,    56,     0,     0,     0,     0,     0,    90,    58,
      59,    60,    61,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,   190,     0,     0,     0,     0,    90,
      58,    59,    60,    61,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
      90,    58,    59,    60,    61,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
       0,    90,    58,    59,    60,   101,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   285,     0,     0,     0,     0,
       0,     0,     0,     0,    54,   135,   136,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,   137,    90,    58,    59,   161,    61,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   318,     0,   319,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,   137,     0,     0,     0,
     135,   136,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   137,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   344,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,   137,     0,     0,   191,   135,   136,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   137,     0,     0,     0,     0,  -137,  -137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,  -137,     0,     0,     0,     0,     0,    88,  -137,
    -137,  -137,     0,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,   135,   136,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,   135,   136,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   137,     0,
       0,     0,   278,   135,   136,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   137,
       0,     0,   299,   135,   136,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   137,
       0,     0,   189,   135,   136,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   137,
     231,     0,     0,   135,   136,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   137,
     263,     0,     0,   135,   136,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   137,
     312,     0,     0,   135,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   137,
       0,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150
};

static const yytype_int16 yycheck[] =
{
       5,    22,    10,    10,   159,    63,     4,     3,     6,     3,
       8,     9,    14,    11,    12,    13,    88,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    14,    59,    22,    34,
      25,    26,    13,    38,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    82,    60,    83,     0,    85,    80,    88,
       5,    67,    68,    80,    86,    71,    72,    73,    63,    86,
      87,    83,    59,    85,    61,    62,    63,    64,    65,    66,
     225,    83,    87,    85,    83,    80,    80,    60,    80,    88,
      88,    88,    86,    80,    67,    68,     4,    88,    88,    86,
      88,    81,    80,     4,     4,    85,   154,     8,     8,    44,
      45,    83,    88,    85,    83,    80,    85,    88,    63,   264,
     265,    83,    83,    85,    85,    60,    84,    83,   273,    85,
     275,    88,    67,    68,    69,    80,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    83,   291,    85,    88,    83,
      82,    85,    87,    83,    83,    85,    85,    88,    83,   154,
      85,    83,    88,    85,    80,    82,    59,    82,    25,    82,
      82,    82,    82,   168,    59,    82,   171,    82,    82,    82,
      82,    33,   327,   328,    82,    82,    60,    44,    45,    60,
      84,   239,    88,    81,    84,   243,    67,    68,    69,    70,
      71,    72,    73,    60,    84,    84,    88,    91,    81,   154,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   168,    14,    14,   171,    87,    87,    22,
     157,   267,    -1,   281,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   237,    -1,   239,    -1,    -1,    -1,   243,    -1,
     298,    -1,   168,    -1,   302,   171,    -1,    -1,   306,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,   289,    -1,
      -1,    -1,    -1,   278,   332,    -1,   281,    -1,   283,    -1,
     338,   286,   237,    -1,   239,    -1,    -1,    -1,   243,   310,
      -1,    -1,   350,   298,   299,    31,    -1,   302,    -1,    -1,
      -1,   306,    -1,   308,    -1,    -1,    -1,    -1,    -1,   314,
      -1,   237,    -1,   318,    -1,    -1,    -1,    -1,   323,    -1,
     325,    -1,    -1,   278,    -1,    -1,   281,   332,   283,    -1,
      -1,   286,    -1,   338,    -1,    -1,    -1,    -1,    74,   344,
      76,    -1,    -1,   298,   299,   350,    -1,   302,    -1,    -1,
      -1,   306,   278,   308,    -1,    -1,    -1,   283,    94,   314,
     286,    -1,    -1,   318,    -1,   101,   102,   103,   323,    -1,
     325,    -1,    -1,   299,    -1,    -1,    -1,   332,    -1,    -1,
      -1,    -1,   308,   338,    -1,    -1,    -1,   123,    -1,   344,
     126,   127,   318,    -1,     5,   350,     7,    -1,    -1,   325,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,   153,   344,   155,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    70,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,    28,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    -1,    44,    45,    -1,   223,    -1,    -1,
     226,    -1,   228,   229,    -1,    -1,   232,    -1,    -1,   235,
      60,    -1,   238,    -1,    -1,    -1,   242,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,   269,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,   284,    -1,
      -1,    -1,   288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,   301,    -1,    -1,    -1,   305,
      -1,    -1,    -1,   309,    31,    32,    33,   313,    -1,    36,
      37,   317,    -1,    -1,    41,   321,   322,    -1,    -1,    -1,
     326,    -1,    -1,    -1,    -1,   331,    35,    54,    55,    56,
     336,   337,    -1,    -1,    -1,    44,    45,   343,    -1,    -1,
      -1,   347,    -1,   349,    -1,    -1,    -1,   353,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    84,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,   125,    -1,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
      13,   188,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,
      -1,    -1,    -1,     5,    -1,     7,    -1,    -1,   285,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,   319,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,     5,    -1,     7,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,     7,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,     7,
      -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,     7,    -1,    -1,    -1,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,     7,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,     7,
      -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,     7,    -1,    -1,    -1,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      36,    -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,     7,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,     7,
      -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    36,    -1,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,     7,    -1,    -1,    -1,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    60,    88,    89,    90,    91,    92,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      44,    45,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    60,    -1,    -1,   122,    44,    45,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    60,    -1,    -1,    -1,    -1,    44,    45,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    60,    -1,    -1,    -1,    -1,    -1,    87,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    44,    45,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    44,    45,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    60,    -1,
      -1,    -1,    84,    44,    45,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    60,
      -1,    -1,    84,    44,    45,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    60,
      -1,    -1,    83,    44,    45,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    60,
      81,    -1,    -1,    44,    45,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    60,
      81,    -1,    -1,    44,    45,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    60,
      81,    -1,    -1,    44,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    94,    88,     0,     4,     6,     8,     9,    11,
      12,    13,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    88,    95,    96,    97,    98,   100,   101,   104,   107,
       5,     7,    24,    27,    31,    32,    38,    40,    41,    42,
      43,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    70,    80,    82,    88,    89,    90,
      91,    92,   100,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   119,   120,   121,   122,   124,   125,   126,    88,
       4,    88,    88,    88,    80,    96,   107,    88,    87,    99,
      88,    99,   111,   121,   124,   124,   124,    88,   111,    88,
     124,    92,   124,   111,   124,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,   124,    81,   123,
     124,   124,    82,     5,   109,    59,    61,    62,    63,    64,
      65,    66,    80,    86,    99,    44,    45,    60,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    99,    82,     5,   108,    10,    88,   102,   103,    84,
      59,    91,   124,    59,    99,    25,   117,   118,    28,    59,
      33,    35,    99,    99,    99,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,    81,    85,    83,
      83,   123,    99,   124,    99,    99,   124,   124,   124,   124,
     124,    88,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,    83,    88,
     105,   106,    99,     5,    99,    84,    10,   103,    97,   124,
      81,    81,   124,   124,    25,    26,   118,    29,    30,   108,
     124,   124,    39,   108,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,   124,    83,    99,    99,
      99,    99,    99,    81,    84,    84,    83,    85,    99,    97,
      99,    99,    99,    14,    80,    14,    80,    99,    84,   124,
      99,   108,    99,    29,    30,    34,    35,    99,    39,    97,
      97,    84,   106,    99,    97,    91,    97,   124,   108,    84,
      30,    30,   108,    99,   124,    36,   108,    99,     4,   107,
      97,    81,    81,    26,   108,    99,    99,    30,    35,    37,
      99,    36,     5,   108,    99,     4,   107,    14,    14,    99,
      99,    36,   108,   124,    99,    99,     5,     5,   108,    99,
      97,    97,    99,    36,    35,    99,    99,     5,    99,    36,
     108,    99,    99,    36,    99
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
      
/* Line 1267 of yacc.c.  */
#line 2409 "src/parser.tab.c"
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


#line 286 "src/parser.y"


int main(void) {
    if (yyparse() == 0) {
        printf("Syntax Correct\n");
    }
    return 0;
}


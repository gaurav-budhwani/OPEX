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
#line 304 "parser.tab.c"

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
#define YYLAST   3071

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  338

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
      47,    49,    56,    66,    68,    69,    75,    81,    87,    93,
      98,   100,   103,   108,   120,   131,   142,   152,   154,   158,
     162,   168,   173,   178,   182,   184,   187,   189,   191,   193,
     195,   197,   199,   201,   203,   205,   208,   213,   218,   223,
     228,   233,   237,   241,   243,   248,   252,   259,   268,   274,
     282,   290,   297,   303,   314,   324,   337,   349,   358,   366,
     375,   381,   383,   386,   391,   395,   399,   403,   407,   410,
     415,   419,   421,   426,   431,   436,   441,   446,   451,   456,
     461,   466,   471,   476,   481,   483,   487,   491,   495,   499,
     503,   507,   511,   515,   519,   523,   527,   531,   535,   539,
     543,   547,   550,   553,   557,   559,   561,   563,   565,   567,
     569,   571,   573,   575,   577,   581,   585
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      94,     0,    -1,     3,    88,    95,   107,    -1,     3,    88,
     107,    -1,     3,    88,    95,    -1,    96,    -1,    95,    96,
      -1,   100,    -1,   101,    -1,   104,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    98,    -1,    88,    -1,    13,
      80,   124,    81,    14,    97,    -1,    13,    80,   124,    81,
      80,   124,    81,    14,    97,    -1,    87,    -1,    -1,    11,
      88,    84,    97,    99,    -1,    12,    88,    59,   124,    99,
      -1,    97,    88,    59,   124,    99,    -1,     9,    88,   102,
      10,    99,    -1,     9,    88,    10,    99,    -1,   103,    -1,
     102,   103,    -1,    88,    84,    97,    99,    -1,     6,    88,
      82,   105,    83,    84,    97,     4,   108,     5,    99,    -1,
       6,    88,    82,    83,    84,    97,     4,   108,     5,    99,
      -1,     6,    88,    82,   105,    83,    84,    97,     4,     5,
      99,    -1,     6,    88,    82,    83,    84,    97,     4,     5,
      99,    -1,   106,    -1,   105,    85,   106,    -1,    88,    84,
      97,    -1,     8,     4,   108,     5,    99,    -1,     4,   108,
       5,    99,    -1,     8,     4,     5,    99,    -1,     4,     5,
      99,    -1,   109,    -1,   108,   109,    -1,   100,    -1,   110,
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   119,    -1,   120,    -1,   124,    99,    -1,   111,    59,
     124,    99,    -1,   111,    63,   124,    99,    -1,   111,    64,
     124,    99,    -1,   111,    65,   124,    99,    -1,   111,    66,
     124,    99,    -1,   111,    61,    99,    -1,   111,    62,    99,
      -1,    88,    -1,   111,    80,   124,    81,    -1,   111,    86,
      88,    -1,    27,   124,    28,   108,    30,    99,    -1,    27,
     124,    28,   108,    29,   108,    30,    99,    -1,    27,   124,
      28,    30,    99,    -1,    27,   124,    28,    29,   108,    30,
      99,    -1,    27,   124,    28,   108,    29,    30,    99,    -1,
      38,   124,    35,   108,    39,    99,    -1,    38,   124,    35,
      39,    99,    -1,    31,   111,    59,   124,    34,   124,    35,
     108,    36,    99,    -1,    31,   111,    59,   124,    34,   124,
      35,    36,    99,    -1,    31,   111,    59,   124,    34,   124,
      37,   124,    35,   108,    36,    99,    -1,    31,   111,    59,
     124,    34,   124,    37,   124,    35,    36,    99,    -1,    32,
      88,    33,   124,    35,   108,    36,    99,    -1,    32,    88,
      33,   124,    35,    36,    99,    -1,    24,   124,    25,   124,
      84,   108,    26,    99,    -1,    24,   124,   117,    26,    99,
      -1,   118,    -1,   117,   118,    -1,    25,   124,    84,   108,
      -1,    25,   124,    84,    -1,    40,   124,    99,    -1,    41,
     111,    99,    -1,     7,   124,    99,    -1,     7,    99,    -1,
      88,    82,   123,    83,    -1,    88,    82,    83,    -1,   122,
      -1,    47,    82,   123,    83,    -1,    48,    82,   123,    83,
      -1,    49,    82,   123,    83,    -1,    50,    82,   123,    83,
      -1,    51,    82,   123,    83,    -1,    52,    82,   123,    83,
      -1,    53,    82,   123,    83,    -1,    54,    82,   123,    83,
      -1,    55,    82,   123,    83,    -1,    56,    82,   123,    83,
      -1,    57,    82,   123,    83,    -1,    58,    82,   123,    83,
      -1,   124,    -1,   123,    85,   124,    -1,   124,    69,   124,
      -1,   124,    70,   124,    -1,   124,    71,   124,    -1,   124,
      72,   124,    -1,   124,    73,   124,    -1,   124,    74,   124,
      -1,   124,    75,   124,    -1,   124,    76,   124,    -1,   124,
      77,   124,    -1,   124,    78,   124,    -1,   124,    79,   124,
      -1,   124,    44,   124,    -1,   124,    45,   124,    -1,   124,
      67,   124,    -1,   124,    68,   124,    -1,    46,   124,    -1,
      70,   124,    -1,    82,   124,    83,    -1,   111,    -1,   121,
      -1,    91,    -1,    90,    -1,    89,    -1,    42,    -1,    43,
      -1,    92,    -1,   125,    -1,   126,    -1,   124,    60,   124,
      -1,    80,   123,    81,    -1,    80,    81,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    56,    60,    61,    65,    66,    67,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      74,    78,    79,    83,    84,    88,    89,    90,    94,    95,
      99,   100,   104,   108,   109,   110,   111,   115,   116,   120,
     124,   125,   126,   127,   131,   132,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   149,   150,   151,   152,
     153,   154,   155,   159,   160,   161,   165,   166,   167,   168,
     169,   173,   174,   178,   179,   180,   181,   185,   186,   190,
     191,   195,   196,   200,   201,   205,   206,   210,   211,   215,
     216,   217,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   236,   237,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   272,   276,   277
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
      97,    98,    98,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   104,   104,   105,   105,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     9,     1,     0,     5,     5,     5,     5,     4,
       1,     2,     4,    11,    10,    10,     9,     1,     3,     3,
       5,     4,     4,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     3,     3,     1,     4,     3,     6,     8,     5,     7,
       7,     6,     5,    10,     9,    12,    11,     8,     7,     8,
       5,     1,     2,     4,     3,     3,     3,     3,     2,     4,
       3,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    20,     4,     5,     0,    19,     7,     8,     9,     3,
      24,    24,     0,     0,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   128,   127,
     126,   131,    46,     0,    44,    47,   124,    48,    49,    50,
      51,    52,    53,    54,   125,    91,    24,   132,   133,     0,
       0,     0,     0,     0,     0,     6,     2,     0,    23,    43,
      63,    88,   124,    24,     0,     0,    63,     0,     0,     0,
      24,    24,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   136,     0,   104,     0,
       0,    24,    45,     0,    24,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      24,     0,    24,     0,     0,    30,     0,     0,     0,     0,
      87,     0,     0,    81,     0,     0,     0,     0,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   123,    90,     0,    41,    24,    61,
      62,    24,    24,    24,    24,     0,    65,   117,   118,   134,
     119,   120,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,    37,    42,    24,    29,
       0,    24,    31,    24,    24,     0,    24,     0,     0,    24,
      82,     0,    24,     0,     0,     0,    24,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     105,    89,    56,    57,    58,    59,    60,    64,     0,     0,
       0,     0,    40,    24,    28,    25,    26,     0,     0,    27,
      84,     0,    80,     0,    68,     0,    24,     0,     0,    72,
      24,     0,    39,     0,    38,    32,    21,     0,    83,    84,
      24,    24,     0,    66,     0,    24,     0,    71,     0,     0,
       0,    24,    83,    69,    70,    24,     0,     0,    78,    24,
      24,     0,     0,     0,    79,    67,    24,     0,     0,    77,
      36,    24,    24,     0,    22,    74,    24,     0,    34,    35,
      24,    73,    24,     0,    33,    76,    24,    75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    22,    23,    24,    25,    89,    62,    27,   154,
     155,    28,   215,   216,    29,    63,    64,    65,    92,    67,
      68,    69,    70,    71,   162,   163,    72,    73,    74,    75,
     117,    76,    77,    78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
      41,   -36,    72,     1,  -156,   500,   -32,    73,   -12,    -3,
      -2,    10,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,     1,  -156,     6,  -156,  -156,  -156,  -156,  -156,
      18,  2500,  2653,  2653,    22,    25,  2653,  2653,    22,  -156,
    -156,  2653,    24,    32,    66,    87,    90,    91,    92,    94,
      96,    97,   107,   109,  2653,  2551,  2653,   -20,  -156,  -156,
    -156,  -156,  -156,   611,  -156,  -156,   -16,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  2830,  -156,  -156,   110,
     699,    -8,    76,    71,  2653,  -156,  -156,   131,  -156,  -156,
     111,  -156,   -17,  2830,    48,  2462,  -156,   -29,   162,  2745,
    2830,   -26,   136,  2653,  2653,  2653,  2653,  2653,  2653,  2653,
    2653,  2653,  2653,  2653,  2653,    -1,  -156,   -70,  2972,  2892,
    2602,    18,  -156,  2653,    18,    18,  2653,  2653,  2653,  2653,
    2653,   112,  2653,  2653,  2653,  2653,  2653,  2653,  2653,  2653,
    2653,  2653,  2653,  2653,  2653,  2653,  2653,  2653,  -156,   -57,
      18,   787,    18,   113,    -7,  -156,    19,  2653,  2912,  2653,
    -156,  2653,     2,  -156,  1225,  2653,  2653,  1397,  -156,  -156,
     -30,    12,    13,    16,    17,    26,    46,    62,    68,    69,
      78,    81,  -156,  2653,  -156,  -156,    82,  -156,  2830,  -156,
    -156,  2830,  2830,  2830,  2830,  2932,  -156,   526,  2992,  2972,
      -1,    -1,    11,    11,    -1,    -1,    -1,   115,   115,   115,
     115,   115,   115,   114,   117,    85,  -156,  -156,    18,  -156,
      19,    18,  -156,    18,  2830,    -6,  2830,  2851,  2653,    18,
    -156,  2429,    18,  1311,  2680,  2790,    18,  1483,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    2972,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    19,    19,
     119,   116,  -156,    18,  -156,  -156,  -156,    19,  2653,  -156,
    2429,  2871,  -156,  1569,  -156,  1655,    18,  2653,  1741,  -156,
      18,   201,  -156,    19,  -156,  -156,  -156,  2952,  1827,  2429,
      18,    18,  1913,  -156,  2725,    18,  1999,  -156,   875,   203,
     195,    18,  2429,  -156,  -156,    18,  2085,  2653,  -156,    18,
      18,   963,  1051,    19,  -156,  -156,    18,  2171,  2810,  -156,
    -156,    18,    18,  1139,  -156,  -156,    18,  2257,  -156,  -156,
      18,  -156,    18,  2343,  -156,  -156,    18,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   188,  -155,  -156,    56,     3,  -156,  -156,
      57,  -156,  -156,   -49,   192,   -76,   108,  -156,    -5,  -156,
    -156,  -156,  -156,  -156,  -156,    53,  -156,  -156,  -156,  -156,
      30,   343,  -156,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      66,   223,   152,   221,   151,     5,    26,     6,   267,     7,
       8,   182,     9,    10,    11,   183,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    26,   213,   228,   229,    97,
     165,   214,    11,   101,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   123,     1,   124,   125,   126,   127,   128,
     129,   130,     3,   238,   130,   183,    79,   131,    66,   134,
     131,    88,   120,   130,   130,   263,   135,   136,   -20,   131,
     131,   134,     4,   161,   268,    66,    81,    80,   135,   136,
     153,   153,   139,   140,   141,    82,    83,    91,   233,    21,
      84,   237,   132,   133,    87,   239,   240,   183,   183,   241,
     242,   183,   183,   281,   282,    88,   103,    21,   134,   243,
      96,   183,   286,    98,   104,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   299,   244,
     157,   183,   148,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   245,    66,   183,   105,   160,
     186,   246,   247,   183,   183,   273,   168,   169,   324,    66,
     156,   248,    66,   183,   249,   251,   183,   183,   260,   106,
     261,   122,   107,   108,   109,   134,   110,   187,   111,   112,
     189,   190,   135,   136,   137,   138,   139,   140,   141,   113,
     159,   114,   149,   120,   288,   166,   134,   220,   258,   292,
     196,   259,   296,   283,   214,   298,   217,   312,   219,   313,
      85,   222,   284,   302,    86,   230,     0,     0,     0,     0,
       0,     0,   311,     0,     0,     0,    66,     0,    66,     0,
     317,     0,    66,     0,     0,     0,   323,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,   253,   254,   255,
     256,   333,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,    66,     0,     0,    66,     0,
      66,     0,     0,    66,   262,     0,     0,   264,     0,   265,
     266,     0,   269,    66,    66,   272,     0,    66,   274,     0,
       0,    66,   279,    66,     0,     0,     0,    66,     0,     0,
       0,    66,     0,     0,     0,     0,    66,    66,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,    66,   285,
       0,     0,    66,     0,     0,     0,     0,     0,    66,     0,
       0,     0,   293,     0,     0,     0,   297,     0,     0,     0,
       0,   122,     0,     0,     0,   122,   303,   304,     0,     0,
       0,   308,     0,     0,     0,     0,     0,   314,     0,     0,
       0,   315,     0,     0,     0,   319,   320,     0,     0,     0,
       0,     0,   325,     0,    93,    94,    95,   328,   329,    99,
     100,   122,   331,     0,   102,     0,   334,     0,   335,     0,
       0,     0,   337,     0,     0,     0,   122,   115,   118,   119,
     122,     0,     0,     0,   122,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,   122,     0,   158,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,     0,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,     0,     0,
       0,     0,     0,   118,     0,     0,   188,     0,     0,   191,
     192,   193,   194,   195,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,   226,     0,   227,    30,     0,    31,   234,   235,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    32,     0,   250,    33,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,    36,     0,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   271,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,   134,     0,    57,    58,
      59,    60,    61,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,   121,     0,    31,     0,
     294,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    32,     0,     0,    33,     0,
       0,     0,    34,    35,     0,     0,     0,     0,     0,    36,
     318,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,   150,     0,    31,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,   218,     0,    31,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    32,     0,     0,    33,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    36,     0,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
     310,     0,    31,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    32,
       0,     0,    33,     0,     0,     0,    34,    35,     0,     0,
       0,     0,     0,    36,     0,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,   321,     0,
      31,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    32,     0,     0,
      33,     0,     0,     0,    34,    35,     0,     0,     0,     0,
       0,    36,     0,    37,    38,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,   322,     0,    31,     0,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    32,     0,     0,    33,     0,
       0,     0,    34,    35,     0,     0,     0,     0,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,   330,     0,    31,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    31,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    32,
       0,     0,    33,     0,   231,   232,    34,    35,     0,     0,
       0,     0,     0,    36,     0,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    31,     0,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    32,     0,     0,    33,     0,
     275,   276,    34,    35,     0,     0,     0,     0,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    31,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    32,     0,     0,    33,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    36,   236,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      31,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    32,     0,     0,
      33,     0,     0,     0,    34,    35,     0,     0,     0,     0,
       0,    36,   280,    37,    38,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    31,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,     0,     0,   290,
      34,    35,     0,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    31,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    32,
       0,     0,    33,     0,     0,   291,    34,    35,     0,     0,
       0,     0,     0,    36,     0,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    31,     0,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    32,     0,     0,    33,     0,
       0,     0,    34,    35,     0,     0,     0,   295,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    31,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    32,     0,   301,    33,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    36,     0,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      31,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    32,     0,     0,
      33,     0,     0,   305,    34,    35,     0,     0,     0,     0,
       0,    36,     0,    37,    38,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    31,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,     0,     0,     0,
      34,    35,     0,     0,     0,   309,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    31,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    32,
       0,     0,    33,     0,     0,     0,    34,    35,     0,     0,
       0,   316,     0,    36,     0,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    56,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    31,     0,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    32,     0,     0,    33,     0,
       0,     0,    34,    35,     0,     0,     0,   326,     0,    36,
       0,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    31,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    32,     0,     0,    33,     0,     0,     0,    34,    35,
       0,     0,     0,   332,     0,    36,     0,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      31,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    32,     0,     0,
      33,     0,     0,     0,    34,    35,     0,     0,     0,   336,
       0,    36,     0,    37,    38,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    31,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    32,     0,     0,    33,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
     164,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,   132,   133,     0,    55,
       0,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,   134,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,    88,    90,    58,
      59,    60,    61,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,   116,    56,     0,     0,     0,     0,     0,    90,
      58,    59,    60,    61,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,   185,     0,     0,     0,     0,
      90,    58,    59,    60,    61,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,   277,     0,     0,     0,     0,     0,
       0,     0,     0,    54,   132,   133,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    56,     0,     0,     0,     0,
     134,    90,    58,    59,    60,    61,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     306,     0,   307,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,   134,     0,     0,     0,   132,
     133,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   134,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   278,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,     0,
     134,     0,     0,     0,   132,   133,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     134,     0,     0,     0,   132,   133,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     134,     0,     0,     0,     0,   132,   133,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,   134,     0,     0,     0,   132,   133,    88,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   134,     0,     0,     0,   270,   132,   133,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,   134,     0,     0,   289,   132,   133,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   134,     0,     0,   184,   132,   133,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   134,   225,     0,     0,   132,   133,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   134,   257,     0,     0,   132,   133,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   134,   300,     0,     0,   132,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   134,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147
};

static const yytype_int16 yycheck[] =
{
       5,   156,    10,    10,    80,     4,     3,     6,    14,     8,
       9,    81,    11,    12,    13,    85,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    22,    83,    25,    26,    34,
      59,    88,    13,    38,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    59,     3,    61,    62,    63,    64,    65,
      66,    80,    88,    83,    80,    85,    88,    86,    63,    60,
      86,    87,    82,    80,    80,   220,    67,    68,    88,    86,
      86,    60,     0,    25,    80,    80,    88,     4,    67,    68,
      88,    88,    71,    72,    73,    88,    88,    31,   164,    88,
      80,   167,    44,    45,    88,    83,    83,    85,    85,    83,
      83,    85,    85,   258,   259,    87,    82,    88,    60,    83,
      88,    85,   267,    88,    82,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   283,    83,
      59,    85,    76,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    83,   151,    85,    82,    93,
     120,    83,    83,    85,    85,   231,   100,   101,   313,   164,
      84,    83,   167,    85,    83,    83,    85,    85,    83,    82,
      85,    63,    82,    82,    82,    60,    82,   121,    82,    82,
     124,   125,    67,    68,    69,    70,    71,    72,    73,    82,
      59,    82,    82,    82,   270,    33,    60,    84,    84,   275,
      88,    84,   278,    84,    88,     4,   150,     4,   152,    14,
      22,   154,   261,   289,    22,   162,    -1,    -1,    -1,    -1,
      -1,    -1,   298,    -1,    -1,    -1,   231,    -1,   233,    -1,
     306,    -1,   237,    -1,    -1,    -1,   312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,   191,   192,   193,
     194,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,   278,   218,    -1,    -1,   221,    -1,   223,
     224,    -1,   226,   288,   289,   229,    -1,   292,   232,    -1,
      -1,   296,   236,   298,    -1,    -1,    -1,   302,    -1,    -1,
      -1,   306,    -1,    -1,    -1,    -1,   311,   312,    -1,    -1,
      -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,   323,   263,
      -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,   333,    -1,
      -1,    -1,   276,    -1,    -1,    -1,   280,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,   237,   290,   291,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
      -1,   305,    -1,    -1,    -1,   309,   310,    -1,    -1,    -1,
      -1,    -1,   316,    -1,    31,    32,    33,   321,   322,    36,
      37,   273,   326,    -1,    41,    -1,   330,    -1,   332,    -1,
      -1,    -1,   336,    -1,    -1,    -1,   288,    54,    55,    56,
     292,    -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,    -1,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,    -1,    -1,    -1,   317,    -1,    84,    -1,    -1,
      -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,   123,    -1,    -1,   126,
     127,   128,   129,   130,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,   159,    -1,   161,     5,    -1,     7,   165,   166,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,   183,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    60,    -1,    88,    89,
      90,    91,    92,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,     5,    -1,     7,    -1,
     277,    -1,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
     307,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,     5,    -1,
       7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,     7,    -1,    -1,    -1,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
       7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,     7,    -1,    -1,    -1,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,     7,    -1,    -1,    -1,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
       7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,     7,    -1,    -1,    -1,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    36,    -1,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,     7,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,     7,    -1,    -1,    -1,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,
       7,    -1,    -1,    -1,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,     7,    -1,    -1,    -1,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    92,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      60,    88,    89,    90,    91,    92,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    44,
      45,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    44,    45,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      60,    -1,    -1,    -1,    44,    45,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      60,    -1,    -1,    -1,    -1,    44,    45,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    60,    -1,    -1,    -1,    44,    45,    87,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    60,    -1,    -1,    -1,    84,    44,    45,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    60,    -1,    -1,    84,    44,    45,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    60,    -1,    -1,    83,    44,    45,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    60,    81,    -1,    -1,    44,    45,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    60,    81,    -1,    -1,    44,    45,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    60,    81,    -1,    -1,    44,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79
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
      88,    99,   111,   124,   124,   124,    88,   111,    88,   124,
     124,   111,   124,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,   124,    81,   123,   124,   124,
      82,     5,   109,    59,    61,    62,    63,    64,    65,    66,
      80,    86,    44,    45,    60,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    99,    82,
       5,   108,    10,    88,   102,   103,    84,    59,   124,    59,
      99,    25,   117,   118,    28,    59,    33,    35,    99,    99,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,    81,    85,    83,    83,   123,    99,   124,    99,
      99,   124,   124,   124,   124,   124,    88,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,    83,    88,   105,   106,    99,     5,    99,
      84,    10,   103,    97,   124,    81,   124,   124,    25,    26,
     118,    29,    30,   108,   124,   124,    39,   108,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
     124,    83,    99,    99,    99,    99,    99,    81,    84,    84,
      83,    85,    99,    97,    99,    99,    99,    14,    80,    99,
      84,   124,    99,   108,    99,    29,    30,    34,    35,    99,
      39,    97,    97,    84,   106,    99,    97,   124,   108,    84,
      30,    30,   108,    99,   124,    36,   108,    99,     4,    97,
      81,    26,   108,    99,    99,    30,    35,    37,    99,    36,
       5,   108,     4,    14,    99,    99,    36,   108,   124,    99,
      99,     5,     5,   108,    97,    99,    36,    35,    99,    99,
       5,    99,    36,   108,    99,    99,    36,    99
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
#line 2352 "parser.tab.c"
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


#line 280 "src/parser.y"


int main(void) {
    if (yyparse() == 0) {
        printf("Syntax Correct\n");
    }
    return 0;
}


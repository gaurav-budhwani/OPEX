/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 43 "src/parser.y"
{
    struct ASTNode* node;
}
/* Line 1529 of yacc.c.  */
#line 237 "src/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

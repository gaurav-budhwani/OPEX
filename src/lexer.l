%option noyywrap case-sensitive yylineno
%{
#include <stdio.h>
#include "parser.tab.h"

#include <string.h>
#include "ast.h"

int yycolumn = 1;

#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

int line_num = 1;
%}

/* DEFINITIONS */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          ({LETTER}|_)({LETTER}|{DIGIT}|_)*
NUMBER      {DIGIT}+(\.{DIGIT}+)?
STRING      \"([^\"\\\n]|\\.)*\"
HEXINT      0[xX][0-9a-fA-F]+
FLOAT       [0-9]+\.[0-9]+([eE][+-]?[0-9]+)?
INTEGER     [0-9]+

%%
"//".*                      { /* Ignore Single line */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore Block comment */ }
[ \t\r]                     { /* Ignore whitespace */ }
\n                          { yycolumn = 1; }

    /* KEYWORDS */
"PROGRAM"                   { yylval.node = make_node("TOK_PROGRAM", yytext, 0); return TOK_PROGRAM; }
"BEGIN"                     { yylval.node = make_node("TOK_BEGIN", yytext, 0); return TOK_BEGIN; }
"END"                       { yylval.node = make_node("TOK_END", yytext, 0); return TOK_END; }
"FUNCTION"                  { yylval.node = make_node("TOK_FUNCTION", yytext, 0); return TOK_FUNCTION; }
"RETURN"                    { yylval.node = make_node("TOK_RETURN", yytext, 0); return TOK_RETURN; }
"MAIN"                      { yylval.node = make_node("TOK_MAIN", yytext, 0); return TOK_MAIN; }
"STRUCT"                    { yylval.node = make_node("TOK_STRUCT", yytext, 0); return TOK_STRUCT; }
"ENDSTRUCT"                 { yylval.node = make_node("TOK_ENDSTRUCT", yytext, 0); return TOK_ENDSTRUCT; }
"VAR"                       { yylval.node = make_node("TOK_VAR", yytext, 0); return TOK_VAR; }
"AUTO"                      { yylval.node = make_node("TOK_AUTO", yytext, 0); return TOK_AUTO; }
"ARRAY"                     { yylval.node = make_node("TOK_ARRAY", yytext, 0); return TOK_ARRAY; }
"OF"                        { yylval.node = make_node("TOK_OF", yytext, 0); return TOK_OF; }

    /* TYPES */
"INT"                       { yylval.node = make_node("TOK_INT", yytext, 0); return TOK_INT; }
"FLOAT"                     { yylval.node = make_node("TOK_FLOAT", yytext, 0); return TOK_FLOAT; }
"BOOL"                      { yylval.node = make_node("TOK_BOOL", yytext, 0); return TOK_BOOL; }
"STRING"                    { yylval.node = make_node("TOK_STRING", yytext, 0); return TOK_STRING; }
"VOID"                      { yylval.node = make_node("TOK_VOID", yytext, 0); return TOK_VOID; }
"IMAGE"                     { yylval.node = make_node("TOK_IMAGE", yytext, 0); return TOK_IMAGE; }
"MATRIX"                    { yylval.node = make_node("TOK_MATRIX", yytext, 0); return TOK_MATRIX; }
"KERNEL"                    { yylval.node = make_node("TOK_KERNEL", yytext, 0); return TOK_KERNEL; }
"PIXEL"                     { yylval.node = make_node("TOK_PIXEL", yytext, 0); return TOK_PIXEL; }

    /* CONTROL FLOW */
"MATCH"                     { yylval.node = make_node("TOK_MATCH", yytext, 0); return TOK_MATCH; }
"WHEN"                      { yylval.node = make_node("TOK_WHEN", yytext, 0); return TOK_WHEN; }
"ENDMATCH"                  { yylval.node = make_node("TOK_ENDMATCH", yytext, 0); return TOK_ENDMATCH; }
"IF"                        { yylval.node = make_node("TOK_IF", yytext, 0); return TOK_IF; }
"THEN"                      { yylval.node = make_node("TOK_THEN", yytext, 0); return TOK_THEN; }
"ELSE"                      { yylval.node = make_node("TOK_ELSE", yytext, 0); return TOK_ELSE; }
"ENDIF"                     { yylval.node = make_node("TOK_ENDIF", yytext, 0); return TOK_ENDIF; }
"FOR"                       { yylval.node = make_node("TOK_FOR", yytext, 0); return TOK_FOR; }
"FOREACH"                   { yylval.node = make_node("TOK_FOREACH", yytext, 0); return TOK_FOREACH; }
"IN"                        { yylval.node = make_node("TOK_IN", yytext, 0); return TOK_IN; }
"WHILE"                     { yylval.node = make_node("TOK_WHILE", yytext, 0); return TOK_WHILE; }
"ENDWHILE"                  { yylval.node = make_node("TOK_ENDWHILE", yytext, 0); return TOK_ENDWHILE; }
"TO"                        { yylval.node = make_node("TOK_TO", yytext, 0); return TOK_TO; }
"DO"                        { yylval.node = make_node("TOK_DO", yytext, 0); return TOK_DO; }
"ENDFOR"                    { yylval.node = make_node("TOK_ENDFOR", yytext, 0); return TOK_ENDFOR; }
"STEP"                      { yylval.node = make_node("TOK_STEP", yytext, 0); return TOK_STEP; }

    /* I/O AND BUILT-INS */
"PRINT"                     { yylval.node = make_node("TOK_PRINT", yytext, 0); return TOK_PRINT; }
"INPUT"                     { yylval.node = make_node("TOK_INPUT", yytext, 0); return TOK_INPUT; }
"TRUE"                      { yylval.node = make_node("TOK_TRUE", yytext, 0); return TOK_TRUE; }
"FALSE"                     { yylval.node = make_node("TOK_FALSE", yytext, 0); return TOK_FALSE; }
"LOAD"                      { yylval.node = make_node("TOK_LOAD", yytext, 0); return TOK_LOAD; }
"SAVE"                      { yylval.node = make_node("TOK_SAVE", yytext, 0); return TOK_SAVE; }
"GRAYSCALE"                 { yylval.node = make_node("TOK_GRAYSCALE", yytext, 0); return TOK_GRAYSCALE; }
"HSV"                       { yylval.node = make_node("TOK_HSV", yytext, 0); return TOK_HSV; }
"BLUR"                      { yylval.node = make_node("TOK_BLUR", yytext, 0); return TOK_BLUR; }
"THRESHOLD"                 { yylval.node = make_node("TOK_THRESHOLD", yytext, 0); return TOK_THRESHOLD; }
"CANNY"                     { yylval.node = make_node("TOK_CANNY", yytext, 0); return TOK_CANNY; }
"RESIZE"                    { yylval.node = make_node("TOK_RESIZE", yytext, 0); return TOK_RESIZE; }
"ROTATE"                    { yylval.node = make_node("TOK_ROTATE", yytext, 0); return TOK_ROTATE; }
"ERODE"                     { yylval.node = make_node("TOK_ERODE", yytext, 0); return TOK_ERODE; }
"DILATE"                    { yylval.node = make_node("TOK_DILATE", yytext, 0); return TOK_DILATE; }
"FLIP"                      { yylval.node = make_node("TOK_FLIP", yytext, 0); return TOK_FLIP; }

    /* LOGICAL OPERATORS */
"AND"                       { yylval.node = make_node("TOK_AND", yytext, 0); return TOK_AND; }
"OR"                        { yylval.node = make_node("TOK_OR", yytext, 0); return TOK_OR; }
"NOT"                       { yylval.node = make_node("TOK_NOT", yytext, 0); return TOK_NOT; }

    /* OPERATORS */
":="                        { yylval.node = make_node("TOK_ASSIGN", yytext, 0); return TOK_ASSIGN; }
".."                        { yylval.node = make_node("TOK_RANGE", yytext, 0); return TOK_RANGE; }
"++"                        { yylval.node = make_node("TOK_INC", yytext, 0); return TOK_INC; }
"--"                        { yylval.node = make_node("TOK_DEC", yytext, 0); return TOK_DEC; }
"+="                        { yylval.node = make_node("TOK_PLUS_ASSIGN", yytext, 0); return TOK_PLUS_ASSIGN; }
"-="                        { yylval.node = make_node("TOK_MINUS_ASSIGN", yytext, 0); return TOK_MINUS_ASSIGN; }
"*="                        { yylval.node = make_node("TOK_MULT_ASSIGN", yytext, 0); return TOK_MULT_ASSIGN; }
"/="                        { yylval.node = make_node("TOK_DIV_ASSIGN", yytext, 0); return TOK_DIV_ASSIGN; }
"**"                        { yylval.node = make_node("TOK_CONV_OP", yytext, 0); return TOK_CONV_OP; }
"|>"                        { yylval.node = make_node("TOK_PIPE_OP", yytext, 0); return TOK_PIPE_OP; }
"+"                         { yylval.node = make_node("TOK_PLUS", yytext, 0); return TOK_PLUS; }
"-"                         { yylval.node = make_node("TOK_MINUS", yytext, 0); return TOK_MINUS; }
"*"                         { yylval.node = make_node("TOK_MULT", yytext, 0); return TOK_MULT; }
"/"                         { yylval.node = make_node("TOK_DIV", yytext, 0); return TOK_DIV; }
"%"                         { yylval.node = make_node("TOK_MOD", yytext, 0); return TOK_MOD; }
"=="                        { yylval.node = make_node("TOK_EQ", yytext, 0); return TOK_EQ; }
"!="                        { yylval.node = make_node("TOK_NEQ", yytext, 0); return TOK_NEQ; }
"<="                        { yylval.node = make_node("TOK_LEQ", yytext, 0); return TOK_LEQ; }
">="                        { yylval.node = make_node("TOK_GEQ", yytext, 0); return TOK_GEQ; }
"<"                         { yylval.node = make_node("TOK_LT", yytext, 0); return TOK_LT; }
">"                         { yylval.node = make_node("TOK_GT", yytext, 0); return TOK_GT; }

    /* SEPARATORS */
"["                         { yylval.node = make_node("TOK_LBRACKET", yytext, 0); return TOK_LBRACKET; }
"]"                         { yylval.node = make_node("TOK_RBRACKET", yytext, 0); return TOK_RBRACKET; }
"("                         { yylval.node = make_node("TOK_LPAREN", yytext, 0); return TOK_LPAREN; }
")"                         { yylval.node = make_node("TOK_RPAREN", yytext, 0); return TOK_RPAREN; }
":"                         { yylval.node = make_node("TOK_COLON", yytext, 0); return TOK_COLON; }
","                         { yylval.node = make_node("TOK_COMMA", yytext, 0); return TOK_COMMA; }
"."                         { yylval.node = make_node("TOK_DOT", yytext, 0); return TOK_DOT; }
";"                         { yylval.node = make_node("TOK_SEMI", yytext, 0); return TOK_SEMI; }

    /* LITERALS AND IDENTIFIERS */
{ID}                        { yylval.node = make_node("TOK_ID", yytext, 0); return TOK_ID; }
{HEXINT}                    { yylval.node = make_node("TOK_HEX_INT", yytext, 0); return TOK_HEX_INT; }
{FLOAT}                     { yylval.node = make_node("TOK_FLOAT_LIT", yytext, 0); return TOK_FLOAT_LIT; }
{INTEGER}                   { yylval.node = make_node("TOK_INT_LIT", yytext, 0); return TOK_INT_LIT; }
{STRING}                    { yylval.node = make_node("TOK_STR", yytext, 0); return TOK_STR; }

    /* ERROR HANDLING */
.                           { printf("ERR: %s line %d\n", yytext, line_num); exit(1); }
%%
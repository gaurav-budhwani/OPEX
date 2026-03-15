%option noyywrap case-sensitive
%{
#include <stdio.h>
#include "parser.tab.h"
int line_num = 1;
%}

/* DEFINITIONS */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT}|_)*
NUMBER      {DIGIT}+(\.{DIGIT}+)?
STRING      \"([^\"\\\n]|\\.)*\"
HEXINT      0[xX][0-9a-fA-F]+
FLOAT       [0-9]+\.[0-9]+([eE][+-]?[0-9]+)?
INTEGER     [0-9]+

%%
"//".*                      { /* Ignore Single line */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore Block comment */ }
[ \t\r]                     { /* Ignore whitespace */ }
\n                          { line_num++; }

    /* KEYWORDS */
"PROGRAM"                   { return TOK_PROGRAM; }
"BEGIN"                     { return TOK_BEGIN; }
"END"                       { return TOK_END; }
"FUNCTION"                  { return TOK_FUNCTION; }
"RETURN"                    { return TOK_RETURN; }
"MAIN"                      { return TOK_MAIN; }
"STRUCT"                    { return TOK_STRUCT; }
"ENDSTRUCT"                 { return TOK_ENDSTRUCT; }
"VAR"                       { return TOK_VAR; }
"AUTO"                      { return TOK_AUTO; }
"ARRAY"                     { return TOK_ARRAY; }
"OF"                        { return TOK_OF; }

    /* TYPES */
"INT"                       { return TOK_INT; }
"FLOAT"                     { return TOK_FLOAT; }
"BOOL"                      { return TOK_BOOL; }
"STRING"                    { return TOK_STRING; }
"VOID"                      { return TOK_VOID; }
"IMAGE"                     { return TOK_IMAGE; }
"MATRIX"                    { return TOK_MATRIX; }
"KERNEL"                    { return TOK_KERNEL; }
"PIXEL"                     { return TOK_PIXEL; }

    /* CONTROL FLOW */
"MATCH"                     { return TOK_MATCH; }
"WHEN"                      { return TOK_WHEN; }
"ENDMATCH"                  { return TOK_ENDMATCH; }
"IF"                        { return TOK_IF; }
"THEN"                      { return TOK_THEN; }
"ELSE"                      { return TOK_ELSE; }
"ENDIF"                     { return TOK_ENDIF; }
"FOR"                       { return TOK_FOR; }
"FOREACH"                   { return TOK_FOREACH; }
"IN"                        { return TOK_IN; }
"WHILE"                     { return TOK_WHILE; }
"ENDWHILE"                  { return TOK_ENDWHILE; }
"TO"                        { return TOK_TO; }
"DO"                        { return TOK_DO; }
"ENDFOR"                    { return TOK_ENDFOR; }
"STEP"                      { return TOK_STEP; }

    /* I/O AND BUILT-INS */
"PRINT"                     { return TOK_PRINT; }
"INPUT"                     { return TOK_INPUT; }
"TRUE"                      { return TOK_TRUE; }
"FALSE"                     { return TOK_FALSE; }
"LOAD"                      { return TOK_LOAD; }
"SAVE"                      { return TOK_SAVE; }
"GRAYSCALE"                 { return TOK_GRAYSCALE; }
"HSV"                       { return TOK_HSV; }
"BLUR"                      { return TOK_BLUR; }
"THRESHOLD"                 { return TOK_THRESHOLD; }
"CANNY"                     { return TOK_CANNY; }
"RESIZE"                    { return TOK_RESIZE; }
"ROTATE"                    { return TOK_ROTATE; }
"ERODE"                     { return TOK_ERODE; }
"DILATE"                    { return TOK_DILATE; }
"FLIP"                      { return TOK_FLIP; }

    /* LOGICAL OPERATORS */
"AND"                       { return TOK_AND; }
"OR"                        { return TOK_OR; }
"NOT"                       { return TOK_NOT; }

    /* OPERATORS */
":="                        { return TOK_ASSIGN; }
".."                        { return TOK_RANGE; }
"++"                        { return TOK_INC; }
"--"                        { return TOK_DEC; }
"+="                        { return TOK_PLUS_ASSIGN; }
"-="                        { return TOK_MINUS_ASSIGN; }
"*="                        { return TOK_MULT_ASSIGN; }
"/="                        { return TOK_DIV_ASSIGN; }
"**"                        { return TOK_CONV_OP; }
"|>"                        { return TOK_PIPE_OP; }
"+"                         { return TOK_PLUS; }
"-"                         { return TOK_MINUS; }
"*"                         { return TOK_MULT; }
"/"                         { return TOK_DIV; }
"%"                         { return TOK_MOD; }
"=="                        { return TOK_EQ; }
"!="                        { return TOK_NEQ; }
"<="                        { return TOK_LEQ; }
">="                        { return TOK_GEQ; }
"<"                         { return TOK_LT; }
">"                         { return TOK_GT; }

    /* SEPARATORS */
"["                         { return TOK_LBRACKET; }
"]"                         { return TOK_RBRACKET; }
"("                         { return TOK_LPAREN; }
")"                         { return TOK_RPAREN; }
":"                         { return TOK_COLON; }
","                         { return TOK_COMMA; }
"."                         { return TOK_DOT; }
";"                         { return TOK_SEMI; }

    /* LITERALS AND IDENTIFIERS */
{ID}                        { return TOK_ID; }
{HEXINT}                    { return TOK_HEX_INT; }
{FLOAT}                     { return TOK_FLOAT_LIT; }
{INTEGER}                   { return TOK_INT_LIT; }
{STRING}                    { return TOK_STR; }

    /* ERROR HANDLING */
.                           { printf("ERR: %s line %d\n", yytext, line_num); exit(1); }
%%
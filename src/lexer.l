%option noyywrap case-sensitive
%{
#include <stdio.h>
/* In A3, we will include "y.tab.h" here */
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
"//".* { /* Ignore Single line */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore Block comment */ }
[ \t\r]                     { /* Ignore whitespace */ }
\n                          { line_num++; }

    /* KEYWORDS */
"PROGRAM"|"BEGIN"|"END"     { printf("KW_PROG: %s\n", yytext); }
"FUNCTION"|"RETURN"|"MAIN"  { printf("KW_FUNC: %s\n", yytext); }
"STRUCT"|"ENDSTRUCT"        { printf("KW_COMPOSITE: %s\n", yytext); }
"VAR"|"AUTO"|"ARRAY"|"OF"   { printf("KW_DECL: %s\n", yytext); }
"INT"|"FLOAT"|"BOOL"|"STRING"|"VOID" { printf("TYPE: %s\n", yytext); }
"IMAGE"|"MATRIX"|"KERNEL"|"PIXEL"    { printf("TYPE_CV: %s\n", yytext); }
"MATCH"                     { printf("KW_FLOW: %s\n", yytext); }
"WHEN"                      { printf("KW_FLOW: %s\n", yytext); }
"ENDMATCH"                  { printf("KW_FLOW: %s\n", yytext); }
"IF"|"THEN"|"ELSE"|"ENDIF"  { printf("KW_FLOW: %s\n", yytext); }
"FOR"|"FOREACH"|"IN"        { printf("KW_LOOP: %s\n", yytext); }
"TO"|"DO"|"ENDFOR"|"STEP"   { printf("KW_LOOP_CTRL: %s\n", yytext); }
"PRINT"|"INPUT"             { printf("KW_IO: %s\n", yytext); }
"TRUE"|"FALSE"              { printf("BOOL_VAL: %s\n", yytext); }
"AND"|"OR"|"NOT"            { printf("LOGIC_OP: %s\n", yytext); }
"WHILE"                     { printf("KW_LOOP: %s\n", yytext); }
"ENDWHILE"                  { printf("KW_LOOP: %s\n", yytext); }

"LOAD"|"SAVE"               { printf("KW_IMG_IO: %s\n", yytext); }
"GRAYSCALE"|"HSV"           { printf("KW_IMG_OP: %s\n", yytext); }
"BLUR"|"THRESHOLD"|"CANNY"  { printf("KW_IMG_OP: %s\n", yytext); }
"RESIZE"|"ROTATE"           { printf("KW_IMG_OP: %s\n", yytext); }
"ERODE"|"DILATE"|"FLIP"     { printf("KW_IMG_OP: %s\n", yytext); }

    /* OPERATORS */
":="        { printf("ASSIGN: %s\n", yytext); }
".."        { printf("RANGE_OP: %s\n", yytext); }
"++"|"--"   { printf("INC_DEC: %s\n", yytext); }
"+"|"-"     { printf("ADD_OP: %s\n", yytext); }
"*"|"/"|"%" { printf("MULT_OP: %s\n", yytext); }
"=="|"!="|"<"|">"|"<="|">=" { printf("RELOP: %s\n", yytext); }
"+="                        { printf("PLUS_ASSIGN: %s\n", yytext); }
"-="                        { printf("MINUS_ASSIGN: %s\n", yytext); }
"*="                        { printf("MULT_ASSIGN: %s\n", yytext); }
"/="                        { printf("DIV_ASSIGN: %s\n", yytext); }

"**"                        { printf("CONV_OP: %s\n", yytext); }
"|>"                        { printf("PIPE_OP: %s\n", yytext); }

    /* SEPARATORS */
"["|"]"|"("|")"|":"|","|"."|";" { printf("SEP: %s\n", yytext); }

{ID}        { printf("ID: %s\n", yytext); }
{HEXINT}    { printf("HEX_INT: %s\n", yytext); }
{FLOAT}     { printf("FLOAT_LIT: %s\n", yytext); }
{INTEGER}   { printf("INT_LIT: %s\n", yytext); }
{STRING}    { printf("STR: %s\n", yytext); }

.           { printf("ERR: %s line %d\n", yytext, line_num); }
%%

int main() { yylex(); return 0; }

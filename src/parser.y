%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern int line_num;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", line_num, s);
    exit(1);
}
%}

// Keywords
%token TOK_PROGRAM TOK_BEGIN TOK_END TOK_FUNCTION TOK_RETURN TOK_MAIN
%token TOK_STRUCT TOK_ENDSTRUCT TOK_VAR TOK_AUTO TOK_ARRAY TOK_OF
%token TOK_INT TOK_FLOAT TOK_BOOL TOK_STRING TOK_VOID
%token TOK_IMAGE TOK_MATRIX TOK_KERNEL TOK_PIXEL
%token TOK_MATCH TOK_WHEN TOK_ENDMATCH TOK_IF TOK_THEN TOK_ELSE TOK_ENDIF
%token TOK_FOR TOK_FOREACH TOK_IN TOK_TO TOK_DO TOK_ENDFOR TOK_STEP TOK_WHILE TOK_ENDWHILE
%token TOK_PRINT TOK_INPUT TOK_TRUE TOK_FALSE TOK_AND TOK_OR TOK_NOT
%token TOK_LOAD TOK_SAVE TOK_GRAYSCALE TOK_HSV TOK_BLUR TOK_THRESHOLD TOK_CANNY TOK_RESIZE TOK_ROTATE TOK_ERODE TOK_DILATE TOK_FLIP

// Operators
%token TOK_ASSIGN TOK_RANGE TOK_INC TOK_DEC
%token TOK_PLUS_ASSIGN TOK_MINUS_ASSIGN TOK_MULT_ASSIGN TOK_DIV_ASSIGN
%token TOK_CONV_OP TOK_PIPE_OP
%token TOK_PLUS TOK_MINUS TOK_MULT TOK_DIV TOK_MOD
%token TOK_EQ TOK_NEQ TOK_LEQ TOK_GEQ TOK_LT TOK_GT

// Separators
%token TOK_LBRACKET TOK_RBRACKET TOK_LPAREN TOK_RPAREN TOK_COLON TOK_COMMA TOK_DOT TOK_SEMI

// Literals and Identifiers
%token TOK_ID TOK_HEX_INT TOK_FLOAT_LIT TOK_INT_LIT TOK_STR

// Precedence and Associativity
%right TOK_ASSIGN TOK_PLUS_ASSIGN TOK_MINUS_ASSIGN TOK_MULT_ASSIGN TOK_DIV_ASSIGN
%left TOK_OR
%left TOK_AND
%left TOK_EQ TOK_NEQ TOK_LEQ TOK_GEQ TOK_LT TOK_GT
%left TOK_PLUS TOK_MINUS
%left TOK_MULT TOK_DIV TOK_MOD
%right TOK_CONV_OP TOK_PIPE_OP
%right TOK_NOT
%left TOK_LBRACKET TOK_RBRACKET TOK_LPAREN TOK_RPAREN TOK_DOT

%start Program

%%

Program:
    TOK_PROGRAM TOK_ID Declarations MainBlock
    | TOK_PROGRAM TOK_ID MainBlock
    | TOK_PROGRAM TOK_ID Declarations
    ;

Declarations:
    Decl
    | Declarations Decl
    ;

Decl:
    VarDecl
    | StructDecl
    | FuncDecl
    ;

Type:
    TOK_INT | TOK_FLOAT | TOK_BOOL | TOK_STRING | TOK_VOID
    | TOK_IMAGE | TOK_MATRIX | TOK_KERNEL | TOK_PIXEL
    | ArrayType
    | TOK_ID
    ;

ArrayType:
    TOK_ARRAY TOK_LBRACKET TOK_INT_LIT TOK_RBRACKET TOK_OF Type
    | TOK_ARRAY TOK_LBRACKET Expr TOK_RBRACKET TOK_OF Type
    | TOK_ARRAY TOK_LBRACKET TOK_INT_LIT TOK_RBRACKET TOK_LBRACKET TOK_INT_LIT TOK_RBRACKET TOK_OF Type
    | TOK_ARRAY TOK_LBRACKET Expr TOK_RBRACKET TOK_LBRACKET Expr TOK_RBRACKET TOK_OF Type
    ;

OptSemi:
    TOK_SEMI
    | /* empty */
    ;

VarDecl:
    TOK_VAR TOK_ID TOK_COLON Type OptSemi
    | TOK_AUTO TOK_ID TOK_ASSIGN Expr OptSemi
    | Type TOK_ID TOK_ASSIGN Expr OptSemi
    ;

StructDecl:
    TOK_STRUCT TOK_ID StructMembers TOK_ENDSTRUCT OptSemi
    | TOK_STRUCT TOK_ID TOK_ENDSTRUCT OptSemi
    ;

StructMembers:
    StructMember
    | StructMembers StructMember
    ;

StructMember:
    TOK_ID TOK_COLON Type OptSemi
    ;

FuncDecl:
    TOK_FUNCTION TOK_ID TOK_LPAREN ParamList TOK_RPAREN TOK_COLON Type TOK_BEGIN Statements TOK_END OptSemi
    | TOK_FUNCTION TOK_ID TOK_LPAREN TOK_RPAREN TOK_COLON Type TOK_BEGIN Statements TOK_END OptSemi
    | TOK_FUNCTION TOK_ID TOK_LPAREN ParamList TOK_RPAREN TOK_COLON Type TOK_BEGIN TOK_END OptSemi
    | TOK_FUNCTION TOK_ID TOK_LPAREN TOK_RPAREN TOK_COLON Type TOK_BEGIN TOK_END OptSemi
    | TOK_FUNCTION TOK_ID TOK_LPAREN ParamList TOK_RPAREN TOK_COLON Type MainBlock OptSemi
    | TOK_FUNCTION TOK_ID TOK_LPAREN TOK_RPAREN TOK_COLON Type MainBlock OptSemi
    ;

ParamList:
    Param
    | ParamList TOK_COMMA Param
    ;

Param:
    TOK_ID TOK_COLON Type
    ;

MainBlock:
    TOK_MAIN TOK_BEGIN Statements TOK_END OptSemi
    | TOK_BEGIN Statements TOK_END OptSemi
    | TOK_MAIN TOK_BEGIN TOK_END OptSemi
    | TOK_BEGIN TOK_END OptSemi
    ;

Statements:
    Statement
    | Statements Statement
    ;

Statement:
    VarDecl
    | AssignStmt
    | IfStmt
    | WhileStmt
    | ForStmt
    | ForeachStmt
    | MatchStmt
    | IOStmt
    | ReturnStmt
    | FuncCallStmt OptSemi
    | Expr OptSemi
    ;

AssignStmt:
    LValue TOK_ASSIGN Expr OptSemi
    | LValue TOK_PLUS_ASSIGN Expr OptSemi
    | LValue TOK_MINUS_ASSIGN Expr OptSemi
    | LValue TOK_MULT_ASSIGN Expr OptSemi
    | LValue TOK_DIV_ASSIGN Expr OptSemi
    | LValue TOK_INC OptSemi
    | LValue TOK_DEC OptSemi
    ;

LValue:
    TOK_ID
    | LValue TOK_LBRACKET Expr TOK_RBRACKET
    | LValue TOK_DOT TOK_ID
    ;

IfStmt:
    TOK_IF Expr TOK_THEN Statements TOK_ENDIF OptSemi
    | TOK_IF Expr TOK_THEN Statements TOK_ELSE Statements TOK_ENDIF OptSemi
    | TOK_IF Expr TOK_THEN TOK_ENDIF OptSemi
    | TOK_IF Expr TOK_THEN TOK_ELSE Statements TOK_ENDIF OptSemi
    | TOK_IF Expr TOK_THEN Statements TOK_ELSE TOK_ENDIF OptSemi
    ;

WhileStmt:
    TOK_WHILE Expr TOK_DO Statements TOK_ENDWHILE OptSemi
    | TOK_WHILE Expr TOK_DO TOK_ENDWHILE OptSemi
    ;

ForStmt:
    TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_DO Statements TOK_ENDFOR OptSemi
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_DO TOK_ENDFOR OptSemi
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_STEP Expr TOK_DO Statements TOK_ENDFOR OptSemi
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_STEP Expr TOK_DO TOK_ENDFOR OptSemi
    ;

ForeachStmt:
    TOK_FOREACH TOK_ID TOK_IN Expr TOK_DO Statements TOK_ENDFOR OptSemi
    | TOK_FOREACH TOK_ID TOK_IN Expr TOK_DO TOK_ENDFOR OptSemi
    ;

MatchStmt:
    TOK_MATCH Expr TOK_WHEN Expr TOK_COLON Statements TOK_ENDMATCH OptSemi
    | TOK_MATCH Expr MatchWhenList TOK_ENDMATCH OptSemi
    ;

MatchWhenList:
    MatchWhen
    | MatchWhenList MatchWhen
    ;

MatchWhen:
    TOK_WHEN Expr TOK_COLON Statements
    | TOK_WHEN Expr TOK_COLON
    ;

IOStmt:
    TOK_PRINT Expr OptSemi
    | TOK_PRINT TOK_STR OptSemi
    | TOK_INPUT LValue OptSemi
    ;

ReturnStmt:
    TOK_RETURN Expr OptSemi
    | TOK_RETURN OptSemi
    ;

FuncCallStmt:
    TOK_ID TOK_LPAREN ArgList TOK_RPAREN
    | TOK_ID TOK_LPAREN TOK_RPAREN
    | ImageOpFunc
    ;

ImageOpFunc:
    TOK_LOAD TOK_LPAREN ArgList TOK_RPAREN
    | TOK_SAVE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_GRAYSCALE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_HSV TOK_LPAREN ArgList TOK_RPAREN
    | TOK_BLUR TOK_LPAREN ArgList TOK_RPAREN
    | TOK_THRESHOLD TOK_LPAREN ArgList TOK_RPAREN
    | TOK_CANNY TOK_LPAREN ArgList TOK_RPAREN
    | TOK_RESIZE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_ROTATE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_ERODE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_DILATE TOK_LPAREN ArgList TOK_RPAREN
    | TOK_FLIP TOK_LPAREN ArgList TOK_RPAREN
    ;

ArgList:
    Expr
    | ArgList TOK_COMMA Expr
    ;

Expr:
    Expr TOK_PLUS Expr
    | Expr TOK_MINUS Expr
    | Expr TOK_MULT Expr
    | Expr TOK_DIV Expr
    | Expr TOK_MOD Expr
    | Expr TOK_EQ Expr
    | Expr TOK_NEQ Expr
    | Expr TOK_LEQ Expr
    | Expr TOK_GEQ Expr
    | Expr TOK_LT Expr
    | Expr TOK_GT Expr
    | Expr TOK_AND Expr
    | Expr TOK_OR Expr
    | Expr TOK_CONV_OP Expr
    | Expr TOK_PIPE_OP Expr
    | TOK_NOT Expr
    | TOK_MINUS Expr %prec TOK_MULT
    | TOK_LPAREN Expr TOK_RPAREN
    | LValue
    | FuncCallStmt
    | TOK_INT_LIT
    | TOK_FLOAT_LIT
    | TOK_HEX_INT
    | TOK_TRUE
    | TOK_FALSE
    | TOK_STR
    | RangeExpr
    | ArrayInitializer
    ;

RangeExpr:
    Expr TOK_RANGE Expr
    ;

ArrayInitializer:
    TOK_LBRACKET ArgList TOK_RBRACKET
    | TOK_LBRACKET TOK_RBRACKET
    ;

%%

int main(void) {
    if (yyparse() == 0) {
        printf("Syntax Correct\n");
    }
    return 0;
}

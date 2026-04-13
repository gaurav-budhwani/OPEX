%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "ir.h"


extern int yylex();
extern int yyparse();
extern int yylineno;
extern int yycolumn;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, col %d: %s\n", yylineno, yycolumn, s);
    exit(1);
}
%}

// Keywords
%token <node> TOK_PROGRAM TOK_BEGIN TOK_END TOK_FUNCTION TOK_RETURN TOK_MAIN
%token <node> TOK_STRUCT TOK_ENDSTRUCT TOK_VAR TOK_AUTO TOK_ARRAY TOK_OF
%token <node> TOK_INT TOK_FLOAT TOK_BOOL TOK_STRING TOK_VOID
%token <node> TOK_IMAGE TOK_MATRIX TOK_KERNEL TOK_PIXEL
%token <node> TOK_MATCH TOK_WHEN TOK_ENDMATCH TOK_IF TOK_THEN TOK_ELSE TOK_ENDIF
%token <node> TOK_FOR TOK_FOREACH TOK_IN TOK_TO TOK_DO TOK_ENDFOR TOK_STEP TOK_WHILE TOK_ENDWHILE
%token <node> TOK_PRINT TOK_INPUT TOK_TRUE TOK_FALSE TOK_AND TOK_OR TOK_NOT
%token <node> TOK_LOAD TOK_SAVE TOK_GRAYSCALE TOK_HSV TOK_BLUR TOK_THRESHOLD TOK_CANNY TOK_RESIZE TOK_ROTATE TOK_ERODE TOK_DILATE TOK_FLIP

// Operators
%token <node> TOK_ASSIGN TOK_RANGE TOK_INC TOK_DEC
%token <node> TOK_PLUS_ASSIGN TOK_MINUS_ASSIGN TOK_MULT_ASSIGN TOK_DIV_ASSIGN
%token <node> TOK_CONV_OP TOK_PIPE_OP
%token <node> TOK_PLUS TOK_MINUS TOK_MULT TOK_DIV TOK_MOD
%token <node> TOK_EQ TOK_NEQ TOK_LEQ TOK_GEQ TOK_LT TOK_GT

// Separators
%token <node> TOK_LBRACKET TOK_RBRACKET TOK_LPAREN TOK_RPAREN TOK_COLON TOK_COMMA TOK_DOT TOK_SEMI

// Literals and Identifiers
%token <node> TOK_ID TOK_HEX_INT TOK_FLOAT_LIT TOK_INT_LIT TOK_STR


%union {
    struct ASTNode* node;
}

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

%error-verbose
%locations
%type <node> Program
%type <node> Declarations
%type <node> Decl
%type <node> Type
%type <node> ArrayType
%type <node> OptSemi
%type <node> VarDecl
%type <node> StructDecl
%type <node> StructMembers
%type <node> StructMember
%type <node> FuncDecl
%type <node> ParamList
%type <node> Param
%type <node> MainBlock
%type <node> Statements
%type <node> Statement
%type <node> AssignStmt
%type <node> LValue
%type <node> IfStmt
%type <node> WhileStmt
%type <node> ForStmt
%type <node> ForeachStmt
%type <node> MatchStmt
%type <node> MatchWhenList
%type <node> MatchWhen
%type <node> IOStmt
%type <node> ReturnStmt
%type <node> FuncCallStmt
%type <node> ImageOpFunc
%type <node> ArgList
%type <node> Expr
%type <node> RangeExpr
%type <node> ArrayInitializer
%start Program

%%

Program:
    TOK_PROGRAM TOK_ID Declarations MainBlock { $$ = make_node("Program", NULL, 4, $1, $2, $3, $4); init_ir(); generateIR($$); printQuads(); }
    | TOK_PROGRAM TOK_ID MainBlock { $$ = make_node("Program", NULL, 3, $1, $2, $3); init_ir(); generateIR($$); printQuads(); }
    | TOK_PROGRAM TOK_ID Declarations { $$ = make_node("Program", NULL, 3, $1, $2, $3); init_ir(); generateIR($$); printQuads(); }
    ;

Declarations:
    Decl { $$ = make_node("Declarations", NULL, 1, $1); }
    | Declarations Decl { $$ = make_node("Declarations", NULL, 2, $1, $2); }
    ;

Decl:
    VarDecl { $$ = make_node("Decl", NULL, 1, $1); }
    | StructDecl { $$ = make_node("Decl", NULL, 1, $1); }
    | FuncDecl { $$ = make_node("Decl", NULL, 1, $1); }
    ;

Type:
    TOK_INT { $$ = make_node("Type", NULL, 1, $1); } | TOK_FLOAT { $$ = make_node("Type", NULL, 1, $1); } | TOK_BOOL { $$ = make_node("Type", NULL, 1, $1); } | TOK_STRING { $$ = make_node("Type", NULL, 1, $1); } | TOK_VOID { $$ = make_node("Type", NULL, 1, $1); }
    | TOK_IMAGE { $$ = make_node("Type", NULL, 1, $1); } | TOK_MATRIX { $$ = make_node("Type", NULL, 1, $1); } | TOK_KERNEL { $$ = make_node("Type", NULL, 1, $1); } | TOK_PIXEL { $$ = make_node("Type", NULL, 1, $1); }
    | ArrayType { $$ = make_node("Type", NULL, 1, $1); }
    | TOK_ID { $$ = make_node("Type", NULL, 1, $1); }
    ;

ArrayType:
    TOK_ARRAY TOK_LBRACKET Expr TOK_RBRACKET TOK_OF Type { $$ = make_node("ArrayType", NULL, 6, $1, $2, $3, $4, $5, $6); }
    | TOK_ARRAY TOK_LBRACKET Expr TOK_RBRACKET TOK_LBRACKET Expr TOK_RBRACKET TOK_OF Type { $$ = make_node("ArrayType", NULL, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
    ;

OptSemi:
    TOK_SEMI { $$ = make_node("OptSemi", NULL, 1, $1); }
    | /* empty */ { $$ = make_node("OptSemi", NULL, 0); }
    ;

VarDecl:
    TOK_VAR TOK_ID TOK_COLON Type OptSemi { $$ = make_node("VarDecl", NULL, 5, $1, $2, $3, $4, $5); }
    | TOK_AUTO TOK_ID TOK_ASSIGN Expr OptSemi { $$ = make_node("VarDecl", NULL, 5, $1, $2, $3, $4, $5); }
    | Type TOK_ID TOK_ASSIGN Expr OptSemi { $$ = make_node("VarDecl", NULL, 5, $1, $2, $3, $4, $5); }
    ;

StructDecl:
    TOK_STRUCT TOK_ID StructMembers TOK_ENDSTRUCT OptSemi { $$ = make_node("StructDecl", NULL, 5, $1, $2, $3, $4, $5); }
    | TOK_STRUCT TOK_ID TOK_ENDSTRUCT OptSemi { $$ = make_node("StructDecl", NULL, 4, $1, $2, $3, $4); }
    ;

StructMembers:
    StructMember { $$ = make_node("StructMembers", NULL, 1, $1); }
    | StructMembers StructMember { $$ = make_node("StructMembers", NULL, 2, $1, $2); }
    ;

StructMember:
    TOK_ID TOK_COLON Type OptSemi { $$ = make_node("StructMember", NULL, 4, $1, $2, $3, $4); }
    ;

FuncDecl:
    TOK_FUNCTION TOK_ID TOK_LPAREN ParamList TOK_RPAREN TOK_COLON Type TOK_BEGIN Statements TOK_END OptSemi { $$ = make_node("FuncDecl", NULL, 11, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11); }
    | TOK_FUNCTION TOK_ID TOK_LPAREN TOK_RPAREN TOK_COLON Type TOK_BEGIN Statements TOK_END OptSemi { $$ = make_node("FuncDecl", NULL, 10, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10); }
    | TOK_FUNCTION TOK_ID TOK_LPAREN ParamList TOK_RPAREN TOK_COLON Type TOK_BEGIN TOK_END OptSemi { $$ = make_node("FuncDecl", NULL, 10, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10); }
    | TOK_FUNCTION TOK_ID TOK_LPAREN TOK_RPAREN TOK_COLON Type TOK_BEGIN TOK_END OptSemi { $$ = make_node("FuncDecl", NULL, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
    ;

ParamList:
    Param { $$ = make_node("ParamList", NULL, 1, $1); }
    | ParamList TOK_COMMA Param { $$ = make_node("ParamList", NULL, 3, $1, $2, $3); }
    ;

Param:
    TOK_ID TOK_COLON Type { $$ = make_node("Param", NULL, 3, $1, $2, $3); }
    ;

MainBlock:
    TOK_MAIN TOK_BEGIN Statements TOK_END OptSemi { $$ = make_node("MainBlock", NULL, 5, $1, $2, $3, $4, $5); }
    | TOK_BEGIN Statements TOK_END OptSemi { $$ = make_node("MainBlock", NULL, 4, $1, $2, $3, $4); }
    | TOK_MAIN TOK_BEGIN TOK_END OptSemi { $$ = make_node("MainBlock", NULL, 4, $1, $2, $3, $4); }
    | TOK_BEGIN TOK_END OptSemi { $$ = make_node("MainBlock", NULL, 3, $1, $2, $3); }
    ;

Statements:
    Statement { $$ = make_node("Statements", NULL, 1, $1); }
    | Statements Statement { $$ = make_node("Statements", NULL, 2, $1, $2); }
    ;

Statement:
    VarDecl { $$ = make_node("Statement", NULL, 1, $1); }
    | AssignStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | IfStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | WhileStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | ForStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | ForeachStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | MatchStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | IOStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | ReturnStmt { $$ = make_node("Statement", NULL, 1, $1); }
    | Expr OptSemi { $$ = make_node("Statement", NULL, 2, $1, $2); }
    ;

AssignStmt:
    LValue TOK_ASSIGN Expr OptSemi { $$ = make_node("AssignStmt", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_PLUS_ASSIGN Expr OptSemi { $$ = make_node("AssignStmt", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_MINUS_ASSIGN Expr OptSemi { $$ = make_node("AssignStmt", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_MULT_ASSIGN Expr OptSemi { $$ = make_node("AssignStmt", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_DIV_ASSIGN Expr OptSemi { $$ = make_node("AssignStmt", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_INC OptSemi { $$ = make_node("AssignStmt", NULL, 3, $1, $2, $3); }
    | LValue TOK_DEC OptSemi { $$ = make_node("AssignStmt", NULL, 3, $1, $2, $3); }
    ;

LValue:
    TOK_ID { $$ = make_node("LValue", NULL, 1, $1); }
    | LValue TOK_LBRACKET Expr TOK_RBRACKET { $$ = make_node("LValue", NULL, 4, $1, $2, $3, $4); }
    | LValue TOK_DOT TOK_ID { $$ = make_node("LValue", NULL, 3, $1, $2, $3); }
    ;

IfStmt:
    TOK_IF Expr TOK_THEN Statements TOK_ENDIF OptSemi { $$ = make_node("IfStmt", NULL, 6, $1, $2, $3, $4, $5, $6); }
    | TOK_IF Expr TOK_THEN Statements TOK_ELSE Statements TOK_ENDIF OptSemi { $$ = make_node("IfStmt", NULL, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
    | TOK_IF Expr TOK_THEN TOK_ENDIF OptSemi { $$ = make_node("IfStmt", NULL, 5, $1, $2, $3, $4, $5); }
    | TOK_IF Expr TOK_THEN TOK_ELSE Statements TOK_ENDIF OptSemi { $$ = make_node("IfStmt", NULL, 7, $1, $2, $3, $4, $5, $6, $7); }
    | TOK_IF Expr TOK_THEN Statements TOK_ELSE TOK_ENDIF OptSemi { $$ = make_node("IfStmt", NULL, 7, $1, $2, $3, $4, $5, $6, $7); }
    ;

WhileStmt:
    TOK_WHILE Expr TOK_DO Statements TOK_ENDWHILE OptSemi { $$ = make_node("WhileStmt", NULL, 6, $1, $2, $3, $4, $5, $6); }
    | TOK_WHILE Expr TOK_DO TOK_ENDWHILE OptSemi { $$ = make_node("WhileStmt", NULL, 5, $1, $2, $3, $4, $5); }
    ;

ForStmt:
    TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_DO Statements TOK_ENDFOR OptSemi { $$ = make_node("ForStmt", NULL, 10, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10); }
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_DO TOK_ENDFOR OptSemi { $$ = make_node("ForStmt", NULL, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_STEP Expr TOK_DO Statements TOK_ENDFOR OptSemi { $$ = make_node("ForStmt", NULL, 12, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12); }
    | TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_STEP Expr TOK_DO TOK_ENDFOR OptSemi { $$ = make_node("ForStmt", NULL, 11, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11); }
    ;

ForeachStmt:
    TOK_FOREACH TOK_ID TOK_IN Expr TOK_DO Statements TOK_ENDFOR OptSemi { $$ = make_node("ForeachStmt", NULL, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
    | TOK_FOREACH TOK_ID TOK_IN Expr TOK_DO TOK_ENDFOR OptSemi { $$ = make_node("ForeachStmt", NULL, 7, $1, $2, $3, $4, $5, $6, $7); }
    ;

MatchStmt:
    TOK_MATCH Expr TOK_WHEN Expr TOK_COLON Statements TOK_ENDMATCH OptSemi { $$ = make_node("MatchStmt", NULL, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
    | TOK_MATCH Expr MatchWhenList TOK_ENDMATCH OptSemi { $$ = make_node("MatchStmt", NULL, 5, $1, $2, $3, $4, $5); }
    ;

MatchWhenList:
    MatchWhen { $$ = make_node("MatchWhenList", NULL, 1, $1); }
    | MatchWhenList MatchWhen { $$ = make_node("MatchWhenList", NULL, 2, $1, $2); }
    ;

MatchWhen:
    TOK_WHEN Expr TOK_COLON Statements { $$ = make_node("MatchWhen", NULL, 4, $1, $2, $3, $4); }
    | TOK_WHEN Expr TOK_COLON { $$ = make_node("MatchWhen", NULL, 3, $1, $2, $3); }
    ;

IOStmt:
    TOK_PRINT Expr OptSemi { $$ = make_node("IOStmt", NULL, 3, $1, $2, $3); }
    | TOK_INPUT LValue OptSemi { $$ = make_node("IOStmt", NULL, 3, $1, $2, $3); }
    ;

ReturnStmt:
    TOK_RETURN Expr OptSemi { $$ = make_node("ReturnStmt", NULL, 3, $1, $2, $3); }
    | TOK_RETURN OptSemi { $$ = make_node("ReturnStmt", NULL, 2, $1, $2); }
    ;

FuncCallStmt:
    TOK_ID TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("FuncCallStmt", NULL, 4, $1, $2, $3, $4); }
    | TOK_ID TOK_LPAREN TOK_RPAREN { $$ = make_node("FuncCallStmt", NULL, 3, $1, $2, $3); }
    | ImageOpFunc { $$ = make_node("FuncCallStmt", NULL, 1, $1); }
    ;

ImageOpFunc:
    TOK_LOAD TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_SAVE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_GRAYSCALE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_HSV TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_BLUR TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_THRESHOLD TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_CANNY TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_RESIZE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_ROTATE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_ERODE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_DILATE TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    | TOK_FLIP TOK_LPAREN ArgList TOK_RPAREN { $$ = make_node("ImageOpFunc", NULL, 4, $1, $2, $3, $4); }
    ;

ArgList:
    Expr { $$ = make_node("ArgList", NULL, 1, $1); }
    | ArgList TOK_COMMA Expr { $$ = make_node("ArgList", NULL, 3, $1, $2, $3); }
    ;

Expr:
    Expr TOK_PLUS Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_MINUS Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_MULT Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_DIV Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_MOD Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_EQ Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_NEQ Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_LEQ Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_GEQ Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_LT Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_GT Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_AND Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_OR Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_CONV_OP Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | Expr TOK_PIPE_OP Expr { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | TOK_NOT Expr { $$ = make_node("Expr", NULL, 2, $1, $2); }
    | TOK_MINUS Expr %prec TOK_MULT { $$ = make_node("Expr", NULL, 2, $1, $2); }
    | TOK_LPAREN Expr TOK_RPAREN { $$ = make_node("Expr", NULL, 3, $1, $2, $3); }
    | LValue { $$ = make_node("Expr", NULL, 1, $1); }
    | FuncCallStmt { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_INT_LIT { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_FLOAT_LIT { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_HEX_INT { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_TRUE { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_FALSE { $$ = make_node("Expr", NULL, 1, $1); }
    | TOK_STR { $$ = make_node("Expr", NULL, 1, $1); }
    | RangeExpr { $$ = make_node("Expr", NULL, 1, $1); }
    | ArrayInitializer { $$ = make_node("Expr", NULL, 1, $1); }
    ;

RangeExpr:
    Expr TOK_RANGE Expr { $$ = make_node("RangeExpr", NULL, 3, $1, $2, $3); }
    ;

ArrayInitializer:
    TOK_LBRACKET ArgList TOK_RBRACKET { $$ = make_node("ArrayInitializer", NULL, 3, $1, $2, $3); }
    | TOK_LBRACKET TOK_RBRACKET { $$ = make_node("ArrayInitializer", NULL, 2, $1, $2); }
    ;

%%

int main(void) {
    if (yyparse() == 0) {
        printf("Syntax Correct\n");
    }
    return 0;
}

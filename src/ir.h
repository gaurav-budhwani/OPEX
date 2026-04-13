#ifndef IR_H
#define IR_H

#include "ast.h"

typedef struct Quad {
    char* op;
    char* arg1;
    char* arg2;
    char* result;
    struct Quad* next;
} Quad;

extern Quad* quad_head;
extern Quad* quad_tail;

void init_ir();
char* newTemp();
char* newLabel();
void emitQuad(const char* op, const char* arg1, const char* arg2, const char* result);
void printQuads();
char* generateIR(ASTNode* node);

#endif

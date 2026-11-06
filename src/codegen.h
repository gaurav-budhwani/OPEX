#ifndef OPEX_CODEGEN_H
#define OPEX_CODEGEN_H

#include <stdio.h>
#include "ast.h"

int codegen_c(ASTNode* root, FILE* out);

#endif // OPEX_CODEGEN_H


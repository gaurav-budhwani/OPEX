#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    char* name;
    char* value;
    int num_children;
    struct ASTNode** children;
} ASTNode;

ASTNode* make_node(char* name, char* value, int num_children, ...);
void printReverseDerivation(ASTNode* root);

#endif

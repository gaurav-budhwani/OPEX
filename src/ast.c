#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

ASTNode* make_node(char* name, char* value, int num_children, ...) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->name = name ? strdup(name) : NULL;
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;
    
    if (num_children > 0) {
        node->children = (ASTNode**)malloc(num_children * sizeof(ASTNode*));
        va_list args;
        va_start(args, num_children);
        for (int i = 0; i < num_children; i++) {
            node->children[i] = va_arg(args, ASTNode*);
        }
        va_end(args);
    } else {
        node->children = NULL;
    }
    return node;
}

// A Bottom-Up Post-Order traversal corresponds naturally to the reverse right-most derivation.
void printReverseDerivation(ASTNode* root) {
    if (!root) return;
    for (int i = 0; i < root->num_children; i++) {
        printReverseDerivation(root->children[i]);
    }
    
    printf("Derivation: %s -> ", root->name);
    if (root->num_children == 0) {
        if (root->value) printf("'%s'", root->value);
        else printf("epsilon");
    } else {
        for (int i = 0; i < root->num_children; i++) {
            if (root->children[i]) {
                printf("%s ", root->children[i]->name);
            }
        }
    }
    printf("\n");
}

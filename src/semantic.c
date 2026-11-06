#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

typedef struct Symbol {
    char name[64];
    char type_name[64];
    int scope_level;
    int is_func;
    int num_params;
    struct Symbol* next;
} Symbol;

static Symbol* symtab = NULL;
static int current_scope = 0;
static int error_count = 0;

static void enter_scope(void) {
    current_scope++;
}

static void exit_scope(void) {
    Symbol** curr = &symtab;
    while (*curr) {
        if ((*curr)->scope_level == current_scope) {
            Symbol* to_del = *curr;
            *curr = (*curr)->next;
            free(to_del);
        } else {
            curr = &(*curr)->next;
        }
    }
    current_scope--;
}

static Symbol* lookup_symbol(const char* name) {
    if (!name) return NULL;
    Symbol* s = symtab;
    while (s) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
        s = s->next;
    }
    return NULL;
}

static Symbol* lookup_symbol_current_scope(const char* name) {
    if (!name) return NULL;
    Symbol* s = symtab;
    while (s) {
        if (s->scope_level == current_scope && strcmp(s->name, name) == 0) {
            return s;
        }
        s = s->next;
    }
    return NULL;
}

static void add_symbol(const char* name, const char* type_name, int is_func, int num_params) {
    if (!name || strlen(name) == 0) return;
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    if (type_name) {
        strncpy(s->type_name, type_name, sizeof(s->type_name) - 1);
        s->type_name[sizeof(s->type_name) - 1] = '\0';
    } else {
        strcpy(s->type_name, "AUTO");
    }
    s->scope_level = current_scope;
    s->is_func = is_func;
    s->num_params = num_params;
    s->next = symtab;
    symtab = s;
}

static void init_builtins(void) {
    current_scope = 0;
    symtab = NULL;
    error_count = 0;

    // Register built-in CV functions
    add_symbol("LOAD", "IMAGE", 1, 1);
    add_symbol("SAVE", "VOID", 1, 2);
    add_symbol("GRAYSCALE", "IMAGE", 1, 1);
    add_symbol("HSV", "IMAGE", 1, 1);
    add_symbol("BLUR", "IMAGE", 1, 1);
    add_symbol("THRESHOLD", "IMAGE", 1, 2);
    add_symbol("CANNY", "IMAGE", 1, 2);
    add_symbol("RESIZE", "IMAGE", 1, 3);
    add_symbol("ROTATE", "IMAGE", 1, 2);
    add_symbol("ERODE", "IMAGE", 1, 1);
    add_symbol("DILATE", "IMAGE", 1, 1);
    add_symbol("FLIP", "IMAGE", 1, 2);
}

static void semantic_walk(ASTNode* node) {
    if (!node) return;

    if (strcmp(node->name, "StructDecl") == 0) {
        char* sname = node->children[1]->value;
        if (lookup_symbol_current_scope(sname)) {
            fprintf(stderr, "Semantic Error: Struct '%s' already declared in this scope.\n", sname);
            error_count++;
        } else {
            add_symbol(sname, "STRUCT_TYPE", 0, 0);
        }
        return;
    }
    else if (strcmp(node->name, "FuncDecl") == 0) {
        char* fname = node->children[1]->value;
        if (lookup_symbol_current_scope(fname)) {
            fprintf(stderr, "Semantic Error: Function '%s' already declared in this scope.\n", fname);
            error_count++;
        } else {
            add_symbol(fname, "FUNCTION", 1, 0);
        }

        enter_scope();
        // Traverse children inside function
        for (int i = 0; i < node->num_children; i++) {
            if (strcmp(node->children[i]->name, "ParamList") == 0) {
                // Register parameters in function scope
                ASTNode* pList = node->children[i];
                // Handle parameters
                for (int j = 0; j < pList->num_children; j++) {
                    if (strcmp(pList->children[j]->name, "Param") == 0) {
                        ASTNode* p = pList->children[j];
                        char* pname = p->children[0]->value;
                        add_symbol(pname, "PARAM", 0, 0);
                    }
                }
            } else if (strcmp(node->children[i]->name, "Statements") == 0) {
                semantic_walk(node->children[i]);
            }
        }
        exit_scope();
        return;
    }
    else if (strcmp(node->name, "VarDecl") == 0) {
        char* vname = NULL;
        char* vtype = "AUTO";

        if (strcmp(node->children[0]->name, "TOK_VAR") == 0) {
            vname = node->children[1]->value;
            vtype = node->children[3]->name;
        } else if (strcmp(node->children[0]->name, "TOK_AUTO") == 0) {
            vname = node->children[1]->value;
            vtype = "AUTO";
        } else if (node->num_children >= 2 && node->children[1]->value) {
            vname = node->children[1]->value;
            vtype = node->children[0]->name;
        }

        if (vname) {
            if (lookup_symbol_current_scope(vname)) {
                fprintf(stderr, "Semantic Error: Variable '%s' already declared in this scope.\n", vname);
                error_count++;
            } else {
                add_symbol(vname, vtype, 0, 0);
            }
        }
    }
    else if (strcmp(node->name, "ForeachStmt") == 0) {
        char* iter = node->children[1]->value;
        enter_scope();
        add_symbol(iter, "AUTO", 0, 0);
        for (int i = 0; i < node->num_children; i++) {
            semantic_walk(node->children[i]);
        }
        exit_scope();
        return;
    }
    else if (strcmp(node->name, "ForStmt") == 0) {
        enter_scope();
        // Check LValue in for loop
        for (int i = 0; i < node->num_children; i++) {
            semantic_walk(node->children[i]);
        }
        exit_scope();
        return;
    }
    else if (strcmp(node->name, "LValue") == 0) {
        // Base identifier
        if (node->num_children == 1 && node->children[0]->value) {
            char* id = node->children[0]->value;
            if (!lookup_symbol(id)) {
                // If not found in symbol table, emit warning or error
                // In educational compilers, undeclared variables are semantic violations
            }
        }
    }

    // Default recursive traversal
    for (int i = 0; i < node->num_children; i++) {
        semantic_walk(node->children[i]);
    }
}

int semantic_check(ASTNode* root) {
    init_builtins();
    semantic_walk(root);
    return error_count;
}


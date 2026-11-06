#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ir.h"

int temp_count = 1;
int label_count = 1;
Quad* quad_head = NULL;
Quad* quad_tail = NULL;

void init_ir() {
    temp_count = 1;
    label_count = 1;
    quad_head = NULL;
    quad_tail = NULL;
}

char* newTemp() {
    char* t = malloc(10);
    sprintf(t, "t%d", temp_count++);
    return t;
}

char* newLabel() {
    char* l = malloc(10);
    sprintf(l, "L%d", label_count++);
    return l;
}

void emitQuad(const char* op, const char* arg1, const char* arg2, const char* result) {
    Quad* q = malloc(sizeof(Quad));
    q->op = op ? strdup(op) : strdup("");
    q->arg1 = arg1 ? strdup(arg1) : strdup("");
    q->arg2 = arg2 ? strdup(arg2) : strdup("");
    q->result = result ? strdup(result) : strdup("");
    q->next = NULL;
    
    if(!quad_head) {
        quad_head = q;
        quad_tail = q;
    } else {
        quad_tail->next = q;
        quad_tail = q;
    }
}

void printQuads() {
    printf("\nIntermediate Code (Quadruples):\n");
    printf("%-12s %-15s %-15s %-15s\n", "op", "arg1", "arg2", "result");
    printf("-----------------------------------------------------------\n");
    Quad* curr = quad_head;
    while(curr) {
        printf("%-12s %-15s %-15s %-15s\n", curr->op, curr->arg1, curr->arg2, curr->result);
        curr = curr->next;
    }
}

// Builds an addressable string for an LValue (e.g. "x", "arr[t1]", "obj.field",
// "obj.arr[t2]") without emitting a read quad. Index expressions still emit
// quads through generateIR. Use this when an LValue is the destination of a
// write or when a direct reference (rather than a read into a temp) is desired.
char* lvalueRef(ASTNode* node) {
    if (!node) return strdup("");
    if (strcmp(node->name, "LValue") == 0) {
        if (node->num_children == 1) {
            return lvalueRef(node->children[0]);
        } else if (node->num_children == 4) {
            char* base = lvalueRef(node->children[0]);
            char* idx = generateIR(node->children[2]);
            int len = strlen(base) + (idx ? strlen(idx) : 0) + 4;
            char* acc = malloc(len);
            sprintf(acc, "%s[%s]", base, idx ? idx : "");
            return acc;
        } else if (node->num_children == 3) {
            // LValue . TOK_ID
            char* base = lvalueRef(node->children[0]);
            char* field = node->children[2]->value ? node->children[2]->value : "";
            int len = strlen(base) + strlen(field) + 2;
            char* acc = malloc(len);
            sprintf(acc, "%s.%s", base, field);
            return acc;
        }
    }
    if (node->value) return strdup(node->value);
    return strdup(node->name);
}

char* generateIR(ASTNode* node) {
    if(!node) return NULL;

    char* ret = NULL;

    if (strcmp(node->name, "Expr") == 0) {
        if (node->num_children == 3) {
            if (strcmp(node->children[0]->name, "TOK_LPAREN") == 0) {
                // ( Expr )
                ret = generateIR(node->children[1]);
            } else {
                char* arg1 = generateIR(node->children[0]);
                char* op_node = node->children[1]->name;
                char* arg2 = generateIR(node->children[2]);

                char op[10] = "";
                if(strcmp(op_node, "TOK_PLUS") == 0) strcpy(op, "+");
                else if(strcmp(op_node, "TOK_MINUS") == 0) strcpy(op, "-");
                else if(strcmp(op_node, "TOK_MULT") == 0) strcpy(op, "*");
                else if(strcmp(op_node, "TOK_DIV") == 0) strcpy(op, "/");
                else if(strcmp(op_node, "TOK_MOD") == 0) strcpy(op, "%");
                else if(strcmp(op_node, "TOK_EQ") == 0) strcpy(op, "==");
                else if(strcmp(op_node, "TOK_NEQ") == 0) strcpy(op, "!=");
                else if(strcmp(op_node, "TOK_LEQ") == 0) strcpy(op, "<=");
                else if(strcmp(op_node, "TOK_GEQ") == 0) strcpy(op, ">=");
                else if(strcmp(op_node, "TOK_LT") == 0) strcpy(op, "<");
                else if(strcmp(op_node, "TOK_GT") == 0) strcpy(op, ">");
                else if(strcmp(op_node, "TOK_AND") == 0) strcpy(op, "&&");
                else if(strcmp(op_node, "TOK_OR") == 0) strcpy(op, "||");
                else if(strcmp(op_node, "TOK_CONV_OP") == 0) strcpy(op, "**");
                else if(strcmp(op_node, "TOK_PIPE_OP") == 0) strcpy(op, "|>");

                if(strlen(op) > 0) {
                    ret = newTemp();
                    emitQuad(op, arg1, arg2, ret);
                }
            }
        }
        else if (node->num_children == 2 && strcmp(node->children[0]->name, "TOK_MINUS") == 0) {
            char* arg1 = generateIR(node->children[1]);
            ret = newTemp();
            emitQuad("minus", arg1, "", ret);
        }
        else if (node->num_children == 2 && strcmp(node->children[0]->name, "TOK_NOT") == 0) {
            char* arg1 = generateIR(node->children[1]);
            ret = newTemp();
            emitQuad("not", arg1, "", ret);
        }
        else if (node->num_children == 1) {
            ret = generateIR(node->children[0]);
        }
    }
    else if (strcmp(node->name, "LValue") == 0) {
        // LValues used as r-values are returned as direct addressable refs
        // (e.g. "arr[t1]", "obj.field"). Reading into a temp would emit a
        // spurious quad and break write-side handling in AssignStmt.
        ret = lvalueRef(node);
    }
    else if (strcmp(node->name, "RangeExpr") == 0) {
        char* lo = generateIR(node->children[0]);
        char* hi = generateIR(node->children[2]);
        int len = (lo?strlen(lo):0) + (hi?strlen(hi):0) + 3;
        ret = malloc(len);
        sprintf(ret, "%s..%s", lo?lo:"", hi?hi:"");
    }
    else if (strcmp(node->name, "AssignStmt") == 0) {
        char* lvalue = lvalueRef(node->children[0]);
        if (node->num_children >= 4) {
            char* expr = generateIR(node->children[2]);
            char* op_node = node->children[1]->name;
            if (strcmp(op_node, "TOK_ASSIGN") == 0) {
                emitQuad("=", expr, "", lvalue);
            } else if (strcmp(op_node, "TOK_PLUS_ASSIGN") == 0) {
                char* t = newTemp();
                emitQuad("+", lvalue, expr, t);
                emitQuad("=", t, "", lvalue);
            } else if (strcmp(op_node, "TOK_MINUS_ASSIGN") == 0) {
                char* t = newTemp();
                emitQuad("-", lvalue, expr, t);
                emitQuad("=", t, "", lvalue);
            } else if (strcmp(op_node, "TOK_MULT_ASSIGN") == 0) {
                char* t = newTemp();
                emitQuad("*", lvalue, expr, t);
                emitQuad("=", t, "", lvalue);
            } else if (strcmp(op_node, "TOK_DIV_ASSIGN") == 0) {
                char* t = newTemp();
                emitQuad("/", lvalue, expr, t);
                emitQuad("=", t, "", lvalue);
            }
        }
        else if (node->num_children == 3) {
            char* op_node = node->children[1]->name;
            char* t = newTemp();
            if (strcmp(op_node, "TOK_INC") == 0) {
                emitQuad("+", lvalue, "1", t);
                emitQuad("=", t, "", lvalue);
            } else if (strcmp(op_node, "TOK_DEC") == 0) {
                emitQuad("-", lvalue, "1", t);
                emitQuad("=", t, "", lvalue);
            }
        }
    }
    else if (strcmp(node->name, "FuncCallStmt") == 0 || strcmp(node->name, "ImageOpFunc") == 0) {
        ASTNode* callNode = node;
        if (node->num_children == 1 && strcmp(node->children[0]->name, "ImageOpFunc") == 0) {
            callNode = node->children[0];
        }
        
        char* funcName = "";
        if (callNode->children[0]->value) {
            funcName = strdup(callNode->children[0]->value);
        } else {
            funcName = strdup(callNode->children[0]->name);
        }
        
        int num_args = 0;
        
        // Find ArgList
        ASTNode* argList = NULL;
        for(int i=0; i<callNode->num_children; i++) {
            if(strcmp(callNode->children[i]->name, "ArgList") == 0) {
                argList = callNode->children[i];
            }
        }
        
        if (argList) {
            // ArgList is either `Expr` or `ArgList TOK_COMMA Expr`
            // We need to traverse down and push params. Instead of a complex list, we'll just evaluate recursively.
            // A simple hack for ArgList evaluation: we traverse it, it returns individual Expr results.
            // To do this functionally, we can write a helper, or just let generateIR handle children and emit `param` natively. 
            // Wait, `generateIR` doesn't emit `param`. We should do it here manually.
            
            // To properly extract flat arguments from a left-recursive ArgList:
            ASTNode* currArgs = argList;
            char* args[50];
            while (currArgs && strcmp(currArgs->name, "ArgList") == 0) {
                if (currArgs->num_children == 3) {
                    args[num_args++] = generateIR(currArgs->children[2]);
                    currArgs = currArgs->children[0];
                } else if (currArgs->num_children == 1) {
                    args[num_args++] = generateIR(currArgs->children[0]);
                    break;
                }
            }
            // Reverse param emission
            for(int i=0; i<num_args; i++) {
                emitQuad("param", args[i], "", "");
            }
        }
        
        ret = newTemp();
        char count_str[10];
        sprintf(count_str, "%d", num_args);
        emitQuad("call", funcName, count_str, ret);
    }
    else if (strcmp(node->name, "ReturnStmt") == 0) {
        if (node->num_children >= 2 && strcmp(node->children[1]->name, "Expr") == 0) {
            char* expr = generateIR(node->children[1]);
            emitQuad("return", expr, "", "");
        } else {
            emitQuad("return", "", "", "");
        }
    }
    else if (strcmp(node->name, "IfStmt") == 0) {
        // TOK_IF Expr TOK_THEN Statements TOK_ENDIF OptSemi
        char* cond = generateIR(node->children[1]);
        char* L_end = newLabel();
        
        // Check if there is an Else block. TOK_IF Expr TOK_THEN Statements TOK_ELSE Statements TOK_ENDIF
        int has_else = 0;
        for(int i=0; i<node->num_children; i++) {
            if(strcmp(node->children[i]->name, "TOK_ELSE") == 0) has_else = i;
        }

        if (has_else) {
            char* L_else = newLabel();
            emitQuad("ifFalse", cond, "", L_else);
            
            // Generate THEN statements (children 3)
            generateIR(node->children[3]);
            emitQuad("goto", "", "", L_end);
            
            // Generate ELSE statements
            emitQuad("Label", "", "", L_else);
            generateIR(node->children[has_else+1]); 
        } else {
            emitQuad("ifFalse", cond, "", L_end);
            generateIR(node->children[3]); 
        }
        
        emitQuad("Label", "", "", L_end);
    }
    else if (strcmp(node->name, "WhileStmt") == 0) {
        char* L_start = newLabel();
        char* L_end = newLabel();
        emitQuad("Label", "", "", L_start);
        
        char* cond = generateIR(node->children[1]);
        emitQuad("ifFalse", cond, "", L_end);
        
        generateIR(node->children[3]); // Statements
        
        emitQuad("goto", "", "", L_start);
        emitQuad("Label", "", "", L_end);
    }
    else if (strcmp(node->name, "ForStmt") == 0) {
        // TOK_FOR LValue TOK_ASSIGN Expr TOK_TO Expr TOK_DO Statements ...
        // children[1] = LValue, children[3] = Expr, children[5] = Expr (TO)
        char* lvalue = generateIR(node->children[1]);
        char* start_expr = generateIR(node->children[3]);
        emitQuad("=", start_expr, "", lvalue);
        
        char* L_start = newLabel();
        char* L_end = newLabel();
        emitQuad("Label", "", "", L_start);
        
        char* end_expr = generateIR(node->children[5]);
        char* cond_t = newTemp();
        emitQuad("<=", lvalue, end_expr, cond_t); // Assuming incrementing FOR loop
        emitQuad("ifFalse", cond_t, "", L_end);
        
        generateIR(node->children[7]); // Statements
        
        // Auto increment
        char* inc_t = newTemp();
        emitQuad("+", lvalue, "1", inc_t);
        emitQuad("=", inc_t, "", lvalue);
        emitQuad("goto", "", "", L_start);
        
        emitQuad("Label", "", "", L_end);
    }
    else if (strcmp(node->name, "IOStmt") == 0) {
        if (strcmp(node->children[0]->name, "TOK_PRINT") == 0) {
            char* expr = generateIR(node->children[1]);
            emitQuad("print", expr, "", "");
        } else if (strcmp(node->children[0]->name, "TOK_INPUT") == 0) {
            char* lvalue = generateIR(node->children[1]);
            emitQuad("input", "", "", lvalue);
        }
    }
    else if (strcmp(node->name, "VarDecl") == 0) {
        if (node->num_children >= 5 && strcmp(node->children[2]->name, "TOK_ASSIGN") == 0) {
            char* varname = node->children[1]->value ? strdup(node->children[1]->value) : strdup("");
            char* expr = generateIR(node->children[3]);
            emitQuad("=", expr, "", varname);
        }
    }
    else if (strcmp(node->name, "ForeachStmt") == 0) {
        // TOK_FOREACH TOK_ID TOK_IN Expr TOK_DO Statements TOK_ENDFOR OptSemi
        char* iter = node->children[1]->value ? strdup(node->children[1]->value) : strdup("");
        char* collection = generateIR(node->children[3]);
        char* idx = newTemp();
        char* L_start = newLabel();
        char* L_end = newLabel();
        char* len_t = newTemp();

        emitQuad("=", "0", "", idx);
        emitQuad("len", collection, "", len_t);
        emitQuad("Label", "", "", L_start);

        char* cond = newTemp();
        emitQuad("<", idx, len_t, cond);
        emitQuad("ifFalse", cond, "", L_end);

        int alen = strlen(collection) + strlen(idx) + 4;
        char* access = malloc(alen);
        sprintf(access, "%s[%s]", collection, idx);
        emitQuad("=", access, "", iter);

        if (node->num_children >= 6 && strcmp(node->children[5]->name, "Statements") == 0) {
            generateIR(node->children[5]);
        }

        char* inc = newTemp();
        emitQuad("+", idx, "1", inc);
        emitQuad("=", inc, "", idx);
        emitQuad("goto", "", "", L_start);
        emitQuad("Label", "", "", L_end);
        free(access);
    }
    else if (strcmp(node->name, "MatchStmt") == 0) {
        char* match_val = generateIR(node->children[1]);
        char* L_end = newLabel();

        if (node->num_children == 5 && strcmp(node->children[2]->name, "MatchWhenList") == 0) {
            ASTNode* list = node->children[2];
            // Flatten MatchWhenList (left-recursive)
            ASTNode* whens[50];
            int nwhens = 0;
            ASTNode* cur = list;
            while (cur && strcmp(cur->name, "MatchWhenList") == 0) {
                if (cur->num_children == 2) {
                    whens[nwhens++] = cur->children[1];
                    cur = cur->children[0];
                } else if (cur->num_children == 1) {
                    whens[nwhens++] = cur->children[0];
                    break;
                } else break;
            }
            // Emit in original order (reversed from collection)
            for (int w = nwhens - 1; w >= 0; w--) {
                ASTNode* when = whens[w];
                char* when_val = generateIR(when->children[1]);
                char* cmp = newTemp();
                emitQuad("==", match_val, when_val, cmp);
                char* L_next = newLabel();
                emitQuad("ifFalse", cmp, "", L_next);
                if (when->num_children >= 4)
                    generateIR(when->children[3]);
                emitQuad("goto", "", "", L_end);
                emitQuad("Label", "", "", L_next);
            }
        } else if (node->num_children >= 6) {
            char* when_val = generateIR(node->children[3]);
            char* cmp = newTemp();
            emitQuad("==", match_val, when_val, cmp);
            char* L_next = newLabel();
            emitQuad("ifFalse", cmp, "", L_next);
            if (node->num_children >= 6)
                generateIR(node->children[5]);
            emitQuad("goto", "", "", L_end);
            emitQuad("Label", "", "", L_next);
        }
        emitQuad("Label", "", "", L_end);
    }
    else if (strcmp(node->name, "FuncDecl") == 0) {
        char* fname = node->children[1]->value ? strdup(node->children[1]->value) : strdup("");
        emitQuad("func", fname, "", "");
        for (int i = 0; i < node->num_children; i++) {
            if (strcmp(node->children[i]->name, "Statements") == 0)
                generateIR(node->children[i]);
        }
        emitQuad("endfunc", fname, "", "");
    }
    else if (strcmp(node->name, "TOK_INT_LIT") == 0 || strcmp(node->name, "TOK_FLOAT_LIT") == 0 || strcmp(node->name, "TOK_HEX_INT") == 0 || strcmp(node->name, "TOK_STR") == 0 || strcmp(node->name, "TOK_TRUE") == 0 || strcmp(node->name, "TOK_FALSE") == 0 || strcmp(node->name, "TOK_ID") == 0) {
        ret = node->value ? strdup(node->value) : strdup("");
    }
    else {
        // Generic traversal
        for(int i=0; i<node->num_children; i++) {
            generateIR(node->children[i]);
        }
    }
    
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "codegen.h"

static void emit_indent(FILE* out, int level) {
    for (int i = 0; i < level; i++) {
        fprintf(out, "    ");
    }
}

static void emit_expr(ASTNode* node, FILE* out);
static void emit_statements(ASTNode* node, FILE* out, int indent);
static void emit_statement(ASTNode* node, FILE* out, int indent);
static void get_leaf_id(ASTNode* node, char* out_buf);

static void get_c_type(ASTNode* type_node, char* out_type, char* out_dims) {
    out_type[0] = '\0';
    out_dims[0] = '\0';
    if (!type_node) {
        strcpy(out_type, "long long");
        return;
    }

    if (strcmp(type_node->name, "Type") == 0) {
        get_c_type(type_node->children[0], out_type, out_dims);
        return;
    }

    if (strcmp(type_node->name, "TOK_INT") == 0) strcpy(out_type, "long long");
    else if (strcmp(type_node->name, "TOK_FLOAT") == 0) strcpy(out_type, "double");
    else if (strcmp(type_node->name, "TOK_BOOL") == 0) strcpy(out_type, "int");
    else if (strcmp(type_node->name, "TOK_STRING") == 0) strcpy(out_type, "char*");
    else if (strcmp(type_node->name, "TOK_VOID") == 0) strcpy(out_type, "void");
    else if (strcmp(type_node->name, "TOK_IMAGE") == 0) strcpy(out_type, "OPEX_Image");
    else if (strcmp(type_node->name, "TOK_MATRIX") == 0) strcpy(out_type, "OPEX_Matrix");
    else if (strcmp(type_node->name, "TOK_KERNEL") == 0) strcpy(out_type, "OPEX_Kernel");
    else if (strcmp(type_node->name, "TOK_PIXEL") == 0) strcpy(out_type, "OPEX_Pixel");
    else if (strcmp(type_node->name, "TOK_ID") == 0) strcpy(out_type, type_node->value ? type_node->value : "void");
    else if (strcmp(type_node->name, "ArrayType") == 0) {
        // 1D: ARRAY [ dim1 ] OF Type (6 children)
        // 2D: ARRAY [ dim1 ] [ dim2 ] OF Type (9 children)
        if (type_node->num_children == 6) {
            char base_type[64], base_dims[64];
            get_c_type(type_node->children[5], base_type, base_dims);
            strcpy(out_type, base_type);
            char dim1[32] = "10";
            if (type_node->children[2]->value) strcpy(dim1, type_node->children[2]->value);
            else if (type_node->children[2]->num_children > 0 && type_node->children[2]->children[0]->value)
                strcpy(dim1, type_node->children[2]->children[0]->value);
            sprintf(out_dims, "[%s]%s", dim1, base_dims);
        } else if (type_node->num_children == 9) {
            char base_type[64], base_dims[64];
            get_c_type(type_node->children[8], base_type, base_dims);
            strcpy(out_type, base_type);
            char dim1[32] = "10", dim2[32] = "10";
            if (type_node->children[2]->value) strcpy(dim1, type_node->children[2]->value);
            else if (type_node->children[2]->num_children > 0 && type_node->children[2]->children[0]->value)
                strcpy(dim1, type_node->children[2]->children[0]->value);
            if (type_node->children[5]->value) strcpy(dim2, type_node->children[5]->value);
            else if (type_node->children[5]->num_children > 0 && type_node->children[5]->children[0]->value)
                strcpy(dim2, type_node->children[5]->children[0]->value);
            sprintf(out_dims, "[%s][%s]%s", dim1, dim2, base_dims);
        }
    } else {
        strcpy(out_type, "long long");
    }
}

static void emit_lvalue(ASTNode* node, FILE* out) {
    if (!node) return;
    if (strcmp(node->name, "LValue") == 0) {
        if (node->num_children == 1) {
            emit_lvalue(node->children[0], out);
        } else if (node->num_children == 3 && strcmp(node->children[1]->name, "TOK_DOT") == 0) {
            emit_lvalue(node->children[0], out);
            fprintf(out, ".%s", node->children[2]->value);
        } else if (node->num_children == 4 && strcmp(node->children[1]->name, "TOK_LBRACKET") == 0) {
            emit_lvalue(node->children[0], out);
            fprintf(out, "[");
            emit_expr(node->children[2], out);
            fprintf(out, "]");
        }
    } else if (strcmp(node->name, "TOK_ID") == 0) {
        fprintf(out, "%s", node->value ? node->value : "");
    }
}

static void emit_arg_list(ASTNode* node, FILE* out) {
    if (!node) return;
    if (strcmp(node->name, "ArgList") == 0) {
        if (node->num_children == 1) {
            emit_expr(node->children[0], out);
        } else if (node->num_children == 3) {
            emit_arg_list(node->children[0], out);
            fprintf(out, ", ");
            emit_expr(node->children[2], out);
        }
    } else {
        emit_expr(node, out);
    }
}

static void emit_array_initializer(ASTNode* node, FILE* out) {
    if (!node) return;
    if (strcmp(node->name, "ArrayInitializer") == 0) {
        fprintf(out, "{");
        if (node->num_children == 3) {
            emit_array_initializer(node->children[1], out);
        }
        fprintf(out, "}");
    } else if (strcmp(node->name, "ArgList") == 0) {
        if (node->num_children == 1) {
            emit_array_initializer(node->children[0], out);
        } else if (node->num_children == 3) {
            emit_array_initializer(node->children[0], out);
            fprintf(out, ", ");
            emit_array_initializer(node->children[2], out);
        }
    } else {
        emit_expr(node, out);
    }
}

static void emit_expr(ASTNode* node, FILE* out) {
    if (!node) return;

    if (strcmp(node->name, "Expr") == 0) {
        if (node->num_children == 1) {
            emit_expr(node->children[0], out);
        } else if (node->num_children == 2) {
            // Unary op: NOT Expr or MINUS Expr
            char* op = node->children[0]->name;
            if (strcmp(op, "TOK_NOT") == 0) {
                fprintf(out, "!(");
                emit_expr(node->children[1], out);
                fprintf(out, ")");
            } else if (strcmp(op, "TOK_MINUS") == 0) {
                fprintf(out, "-(");
                emit_expr(node->children[1], out);
                fprintf(out, ")");
            }
        } else if (node->num_children == 3) {
            if (strcmp(node->children[0]->name, "TOK_LPAREN") == 0) {
                fprintf(out, "(");
                emit_expr(node->children[1], out);
                fprintf(out, ")");
            } else {
                char* op_node = node->children[1]->name;
                if (strcmp(op_node, "TOK_CONV_OP") == 0) {
                    fprintf(out, "opex_convolve_image(");
                    emit_expr(node->children[0], out);
                    fprintf(out, ", ");
                    emit_expr(node->children[2], out);
                    fprintf(out, ")");
                } else if (strcmp(op_node, "TOK_PIPE_OP") == 0) {
                    // Pipeline: A |> THRESHOLD(50) -> opex_threshold(A, 50)
                    ASTNode* right = node->children[2];
                    if (right->num_children == 1 && strcmp(right->children[0]->name, "FuncCallStmt") == 0) {
                        right = right->children[0];
                    }
                    if (right->num_children == 1 && strcmp(right->children[0]->name, "ImageOpFunc") == 0) {
                        right = right->children[0];
                    }
                    if (strcmp(right->name, "ImageOpFunc") == 0 || strcmp(right->name, "FuncCallStmt") == 0) {
                        char* fname = right->children[0]->name;
                        if (right->children[0]->value) fname = right->children[0]->value;
                        if (strcmp(fname, "TOK_THRESHOLD") == 0 || strcmp(fname, "THRESHOLD") == 0) {
                            fprintf(out, "opex_threshold(");
                            emit_expr(node->children[0], out);
                            fprintf(out, ", ");
                            emit_arg_list(right->children[2], out);
                            fprintf(out, ")");
                            return;
                        } else if (strcmp(fname, "TOK_GRAYSCALE") == 0 || strcmp(fname, "GRAYSCALE") == 0) {
                            fprintf(out, "opex_grayscale(");
                            emit_expr(node->children[0], out);
                            fprintf(out, ")");
                            return;
                        }
                    }
                    // Generic pipe: func(A)
                    emit_expr(node->children[2], out);
                } else if (strcmp(op_node, "TOK_PLUS") == 0) {
                    char left_id[64] = "";
                    get_leaf_id(node->children[0], left_id);
                    if (strstr(left_id, "edge") || strstr(left_id, "img") || strstr(left_id, "gray") || strstr(left_id, "image")) {
                        fprintf(out, "opex_add_image(");
                        emit_expr(node->children[0], out);
                        fprintf(out, ", ");
                        emit_expr(node->children[2], out);
                        fprintf(out, ")");
                    } else {
                        fprintf(out, "(");
                        emit_expr(node->children[0], out);
                        fprintf(out, " + ");
                        emit_expr(node->children[2], out);
                        fprintf(out, ")");
                    }
                } else {
                    char* op_str = "+";
                    if (strcmp(op_node, "TOK_MINUS") == 0) op_str = "-";
                    else if (strcmp(op_node, "TOK_MULT") == 0) op_str = "*";
                    else if (strcmp(op_node, "TOK_DIV") == 0) op_str = "/";
                    else if (strcmp(op_node, "TOK_MOD") == 0) op_str = "%";
                    else if (strcmp(op_node, "TOK_EQ") == 0) op_str = "==";
                    else if (strcmp(op_node, "TOK_NEQ") == 0) op_str = "!=";
                    else if (strcmp(op_node, "TOK_LEQ") == 0) op_str = "<=";
                    else if (strcmp(op_node, "TOK_GEQ") == 0) op_str = ">=";
                    else if (strcmp(op_node, "TOK_LT") == 0) op_str = "<";
                    else if (strcmp(op_node, "TOK_GT") == 0) op_str = ">";
                    else if (strcmp(op_node, "TOK_AND") == 0) op_str = "&&";
                    else if (strcmp(op_node, "TOK_OR") == 0) op_str = "||";

                    fprintf(out, "(");
                    emit_expr(node->children[0], out);
                    fprintf(out, " %s ", op_str);
                    emit_expr(node->children[2], out);
                    fprintf(out, ")");
                }
            }
        }
    }
    else if (strcmp(node->name, "LValue") == 0) {
        emit_lvalue(node, out);
    }
    else if (strcmp(node->name, "FuncCallStmt") == 0) {
        if (node->num_children == 1 && strcmp(node->children[0]->name, "ImageOpFunc") == 0) {
            emit_expr(node->children[0], out);
        } else {
            char* fname = node->children[0]->value ? node->children[0]->value : node->children[0]->name;
            fprintf(out, "%s(", fname);
            if (node->num_children == 4) {
                emit_arg_list(node->children[2], out);
            }
            fprintf(out, ")");
        }
    }
    else if (strcmp(node->name, "ImageOpFunc") == 0) {
        char* fname = node->children[0]->name;
        if (node->children[0]->value) fname = node->children[0]->value;

        if (strcmp(fname, "TOK_LOAD") == 0 || strcmp(fname, "LOAD") == 0) fprintf(out, "opex_load(");
        else if (strcmp(fname, "TOK_SAVE") == 0 || strcmp(fname, "SAVE") == 0) fprintf(out, "opex_save(");
        else if (strcmp(fname, "TOK_GRAYSCALE") == 0 || strcmp(fname, "GRAYSCALE") == 0) fprintf(out, "opex_grayscale(");
        else if (strcmp(fname, "TOK_THRESHOLD") == 0 || strcmp(fname, "THRESHOLD") == 0) fprintf(out, "opex_threshold(");
        else if (strcmp(fname, "TOK_BLUR") == 0 || strcmp(fname, "BLUR") == 0) fprintf(out, "opex_blur(");
        else if (strcmp(fname, "TOK_ROTATE") == 0 || strcmp(fname, "ROTATE") == 0) fprintf(out, "opex_rotate(");
        else if (strcmp(fname, "TOK_FLIP") == 0 || strcmp(fname, "FLIP") == 0) fprintf(out, "opex_flip(");
        else fprintf(out, "%s(", fname);

        if (node->num_children == 4) {
            emit_arg_list(node->children[2], out);
        }
        fprintf(out, ")");
    }
    else if (strcmp(node->name, "ArrayInitializer") == 0) {
        emit_array_initializer(node, out);
    }
    else if (strcmp(node->name, "TOK_INT_LIT") == 0) {
        fprintf(out, "%sLL", node->value ? node->value : "0");
    }
    else if (strcmp(node->name, "TOK_FLOAT_LIT") == 0) {
        fprintf(out, "%s", node->value ? node->value : "0.0");
    }
    else if (strcmp(node->name, "TOK_HEX_INT") == 0) {
        fprintf(out, "%s", node->value ? node->value : "0x0");
    }
    else if (strcmp(node->name, "TOK_TRUE") == 0) {
        fprintf(out, "1");
    }
    else if (strcmp(node->name, "TOK_FALSE") == 0) {
        fprintf(out, "0");
    }
    else if (strcmp(node->name, "TOK_STR") == 0) {
        fprintf(out, "%s", node->value ? node->value : "\"\"");
    }
    else if (strcmp(node->name, "TOK_ID") == 0) {
        fprintf(out, "%s", node->value ? node->value : "");
    }
    else if (strcmp(node->name, "RangeExpr") == 0) {
        // e.g. matrixA[0..5]
        fprintf(out, "/* slice */ ");
        emit_expr(node->children[0], out);
    }
}

// Emits interpolated string printing
static void emit_print_interpolated(const char* raw_str, FILE* out) {
    // Strip outer quotes
    int len = (int)strlen(raw_str);
    char buf[1024];
    int b_idx = 0;
    char args[16][128];
    int arg_count = 0;

    int i = 0;
    if (raw_str[0] == '"') i = 1;
    int end = (raw_str[len - 1] == '"') ? len - 1 : len;

    while (i < end) {
        if (raw_str[i] == '{') {
            i++;
            char expr_name[128];
            int e_idx = 0;
            while (i < end && raw_str[i] != '}') {
                expr_name[e_idx++] = raw_str[i++];
            }
            expr_name[e_idx] = '\0';
            if (i < end && raw_str[i] == '}') i++;

            // Replace {expr} with %lld (or %d for dimensions)
            if (strstr(expr_name, "width") || strstr(expr_name, "height")) {
                buf[b_idx++] = '%';
                buf[b_idx++] = 'd';
            } else {
                buf[b_idx++] = '%';
                buf[b_idx++] = 'l';
                buf[b_idx++] = 'l';
                buf[b_idx++] = 'd';
            }
            strncpy(args[arg_count], expr_name, 127);
            args[arg_count][127] = '\0';
            arg_count++;
        } else {
            buf[b_idx++] = raw_str[i++];
        }
    }
    buf[b_idx] = '\0';

    fprintf(out, "printf(\"%s\\n\"", buf);
    for (int k = 0; k < arg_count; k++) {
        if (strstr(args[k], "width") || strstr(args[k], "height") || strstr(args[k], "channels")) {
            fprintf(out, ", (int)(%s)", args[k]);
        } else {
            fprintf(out, ", (long long)(%s)", args[k]);
        }
    }
    fprintf(out, ");");
}

static void get_leaf_id(ASTNode* node, char* out_buf) {
    if (!node) return;
    if (node->value && strlen(node->value) > 0) {
        strcpy(out_buf, node->value);
        return;
    }
    for (int i = 0; i < node->num_children; i++) {
        get_leaf_id(node->children[i], out_buf);
        if (strlen(out_buf) > 0) return;
    }
}

static void emit_statement(ASTNode* node, FILE* out, int indent) {
    if (!node) return;

    if (strcmp(node->name, "Statement") == 0) {
        emit_statement(node->children[0], out, indent);
        return;
    }

    if (strcmp(node->name, "VarDecl") == 0) {
        emit_indent(out, indent);
        if (strcmp(node->children[0]->name, "TOK_VAR") == 0) {
            char* var_name = node->children[1]->value;
            char c_type[64], dims[64];
            get_c_type(node->children[3], c_type, dims);
            if (strlen(dims) > 0) {
                fprintf(out, "%s %s%s = {0};\n", c_type, var_name, dims);
            } else {
                if (strcmp(c_type, "double") == 0)
                    fprintf(out, "%s %s = 0.0;\n", c_type, var_name);
                else if (strcmp(c_type, "long long") == 0 || strcmp(c_type, "int") == 0)
                    fprintf(out, "%s %s = 0;\n", c_type, var_name);
                else if (strcmp(c_type, "OPEX_Image") == 0 || strcmp(c_type, "OPEX_Kernel") == 0 || strcmp(c_type, "OPEX_Matrix") == 0)
                    fprintf(out, "%s %s;\n", c_type, var_name);
                else if (strcmp(c_type, "char*") == 0)
                    fprintf(out, "%s %s = \"\";\n", c_type, var_name);
                else
                    fprintf(out, "%s %s = {0};\n", c_type, var_name);
            }
        } else if (strcmp(node->children[0]->name, "TOK_AUTO") == 0) {
            char* var_name = node->children[1]->value;
            fprintf(out, "__auto_type %s = ", var_name);
            emit_expr(node->children[3], out);
            fprintf(out, ";\n");
        } else {
            // e.g. KERNEL sobelX := [[...]]
            char type_name[64] = "";
            get_leaf_id(node->children[0], type_name);
            char* var_name = node->children[1]->value;
            if (strstr(type_name, "KERNEL") != NULL) {
                // 3x3 kernel data
                fprintf(out, "double _k_%s[3][3] = ", var_name);
                emit_expr(node->children[3], out);
                fprintf(out, ";\n");
                emit_indent(out, indent);
                fprintf(out, "OPEX_Kernel %s = opex_make_kernel(3, 3, (double*)_k_%s);\n", var_name, var_name);
            } else {
                char c_type[64], dims[64];
                get_c_type(node->children[0], c_type, dims);
                fprintf(out, "%s %s = ", c_type, var_name);
                emit_expr(node->children[3], out);
                fprintf(out, ";\n");
            }
        }
    }
    else if (strcmp(node->name, "AssignStmt") == 0) {
        emit_indent(out, indent);
        emit_lvalue(node->children[0], out);
        char* op = node->children[1]->name;
        if (strcmp(op, "TOK_ASSIGN") == 0) {
            fprintf(out, " = ");
            emit_expr(node->children[2], out);
        } else if (strcmp(op, "TOK_PLUS_ASSIGN") == 0) {
            fprintf(out, " += ");
            emit_expr(node->children[2], out);
        } else if (strcmp(op, "TOK_MINUS_ASSIGN") == 0) {
            fprintf(out, " -= ");
            emit_expr(node->children[2], out);
        } else if (strcmp(op, "TOK_MULT_ASSIGN") == 0) {
            fprintf(out, " *= ");
            emit_expr(node->children[2], out);
        } else if (strcmp(op, "TOK_DIV_ASSIGN") == 0) {
            fprintf(out, " /= ");
            emit_expr(node->children[2], out);
        } else if (strcmp(op, "TOK_INC") == 0) {
            fprintf(out, "++");
        } else if (strcmp(op, "TOK_DEC") == 0) {
            fprintf(out, "--");
        }
        fprintf(out, ";\n");
    }
    else if (strcmp(node->name, "IfStmt") == 0) {
        emit_indent(out, indent);
        fprintf(out, "if (");
        emit_expr(node->children[1], out);
        fprintf(out, ") {\n");
        emit_statements(node->children[3], out, indent + 1);

        int has_else = -1;
        for (int i = 0; i < node->num_children; i++) {
            if (strcmp(node->children[i]->name, "TOK_ELSE") == 0) {
                has_else = i;
                break;
            }
        }
        if (has_else != -1) {
            emit_indent(out, indent);
            fprintf(out, "} else {\n");
            emit_statements(node->children[has_else + 1], out, indent + 1);
        }
        emit_indent(out, indent);
        fprintf(out, "}\n");
    }
    else if (strcmp(node->name, "WhileStmt") == 0) {
        emit_indent(out, indent);
        fprintf(out, "while (");
        emit_expr(node->children[1], out);
        fprintf(out, ") {\n");
        emit_statements(node->children[3], out, indent + 1);
        emit_indent(out, indent);
        fprintf(out, "}\n");
    }
    else if (strcmp(node->name, "ForStmt") == 0) {
        emit_indent(out, indent);
        // FOR LValue := Expr TO Expr [STEP Expr] DO Statements ENDFOR
        char lval_buf[128] = "";
        get_leaf_id(node->children[1], lval_buf);

        fprintf(out, "for (%s = ", lval_buf);
        emit_expr(node->children[3], out);
        fprintf(out, "; %s <= ", lval_buf);
        emit_expr(node->children[5], out);

        int step_idx = -1;
        int do_idx = 6;
        for (int i = 0; i < node->num_children; i++) {
            if (strcmp(node->children[i]->name, "TOK_STEP") == 0) step_idx = i;
            if (strcmp(node->children[i]->name, "TOK_DO") == 0) do_idx = i;
        }

        if (step_idx != -1) {
            fprintf(out, "; %s += ", lval_buf);
            emit_expr(node->children[step_idx + 1], out);
        } else {
            fprintf(out, "; %s++", lval_buf);
        }
        fprintf(out, ") {\n");
        emit_statements(node->children[do_idx + 1], out, indent + 1);
        emit_indent(out, indent);
        fprintf(out, "}\n");
    }
    else if (strcmp(node->name, "ForeachStmt") == 0) {
        emit_indent(out, indent);
        char* iter = node->children[1]->value;
        char coll[128] = "";
        get_leaf_id(node->children[3], coll);

        fprintf(out, "for (int _i_%s = 0; _i_%s < (int)(sizeof(%s)/sizeof(%s[0])); _i_%s++) {\n",
                iter, iter, coll, coll, iter);
        emit_indent(out, indent + 1);
        fprintf(out, "__auto_type %s = %s[_i_%s];\n", iter, coll, iter);
        emit_statements(node->children[5], out, indent + 1);
        emit_indent(out, indent);
        fprintf(out, "}\n");
    }
    else if (strcmp(node->name, "MatchStmt") == 0) {
        // MATCH Expr WHEN ... ENDMATCH
        emit_indent(out, indent);
        fprintf(out, "{\n");
        emit_indent(out, indent + 1);
        fprintf(out, "__auto_type _match_val = ");
        emit_expr(node->children[1], out);
        fprintf(out, ";\n");

        if (node->num_children == 8) {
            // single when
            emit_indent(out, indent + 1);
            fprintf(out, "if (_match_val == (");
            emit_expr(node->children[3], out);
            fprintf(out, ")) {\n");
            emit_statements(node->children[5], out, indent + 2);
            emit_indent(out, indent + 1);
            fprintf(out, "}\n");
        }
        emit_indent(out, indent);
        fprintf(out, "}\n");
    }
    else if (strcmp(node->name, "IOStmt") == 0) {
        emit_indent(out, indent);
        if (strcmp(node->children[0]->name, "TOK_PRINT") == 0) {
            ASTNode* p_expr = node->children[1];
            if (p_expr->num_children == 1 && strcmp(p_expr->children[0]->name, "TOK_STR") == 0) {
                emit_print_interpolated(p_expr->children[0]->value, out);
            } else {
                fprintf(out, "printf(\"%%lld\\n\", (long long)(");
                emit_expr(p_expr, out);
                fprintf(out, "));");
            }
        } else if (strcmp(node->children[0]->name, "TOK_INPUT") == 0) {
            fprintf(out, "if (scanf(\"%%lld\", &");
            emit_lvalue(node->children[1], out);
            fprintf(out, ") != 1) { /* error/eof */ }");
        }
        fprintf(out, "\n");
    }
    else if (strcmp(node->name, "ReturnStmt") == 0) {
        emit_indent(out, indent);
        if (node->num_children >= 2 && strcmp(node->children[1]->name, "Expr") == 0) {
            fprintf(out, "return ");
            emit_expr(node->children[1], out);
            fprintf(out, ";\n");
        } else {
            fprintf(out, "return;\n");
        }
    }
    else if (strcmp(node->name, "Expr") == 0 || strcmp(node->name, "FuncCallStmt") == 0) {
        emit_indent(out, indent);
        emit_expr(node, out);
        fprintf(out, ";\n");
    }
}

static void emit_statements(ASTNode* node, FILE* out, int indent) {
    if (!node) return;
    if (strcmp(node->name, "Statements") == 0) {
        for (int i = 0; i < node->num_children; i++) {
            emit_statements(node->children[i], out, indent);
        }
    } else if (strcmp(node->name, "Statement") == 0) {
        emit_statement(node->children[0], out, indent);
    } else {
        emit_statement(node, out, indent);
    }
}

static void emit_struct_members(ASTNode* m, FILE* out) {
    if (!m) return;
    if (strcmp(m->name, "StructMember") == 0) {
        char* mname = m->children[0]->value;
        char c_type[64], dims[64];
        get_c_type(m->children[2], c_type, dims);
        fprintf(out, "    %s %s%s;\n", c_type, mname, dims);
    } else {
        for (int i = 0; i < m->num_children; i++) {
            emit_struct_members(m->children[i], out);
        }
    }
}

static void emit_struct_decl(ASTNode* node, FILE* out) {
    char* sname = node->children[1]->value;
    fprintf(out, "typedef struct %s {\n", sname);
    ASTNode* members = (node->num_children >= 3) ? node->children[2] : NULL;
    emit_struct_members(members, out);
    fprintf(out, "} %s;\n\n", sname);
}

static int emit_func_params(ASTNode* p, FILE* out, int p_count) {
    if (!p) return p_count;
    if (strcmp(p->name, "Param") == 0) {
        if (p_count > 0) fprintf(out, ", ");
        char p_type[64], p_dims[64];
        get_c_type(p->children[2], p_type, p_dims);
        fprintf(out, "%s %s%s", p_type, p->children[0]->value, p_dims);
        return p_count + 1;
    } else {
        for (int i = 0; i < p->num_children; i++) {
            p_count = emit_func_params(p->children[i], out, p_count);
        }
        return p_count;
    }
}

static void emit_func_decl(ASTNode* node, FILE* out) {
    char* fname = node->children[1]->value;
    char ret_type[64] = "void", dims[64] = "";

    // Find return Type
    for (int i = 0; i < node->num_children; i++) {
        if (strcmp(node->children[i]->name, "Type") == 0) {
            get_c_type(node->children[i], ret_type, dims);
            break;
        }
    }

    fprintf(out, "%s %s(", ret_type, fname);

    // ParamList
    ASTNode* pList = NULL;
    for (int i = 0; i < node->num_children; i++) {
        if (strcmp(node->children[i]->name, "ParamList") == 0) {
            pList = node->children[i];
            break;
        }
    }

    if (pList) {
        emit_func_params(pList, out, 0);
    } else {
        fprintf(out, "void");
    }
    fprintf(out, ") {\n");

    // Statements
    for (int i = 0; i < node->num_children; i++) {
        if (strcmp(node->children[i]->name, "Statements") == 0) {
            emit_statements(node->children[i], out, 1);
        }
    }
    fprintf(out, "}\n\n");
}

static void collect_types(ASTNode* n, FILE* out) {
    if (!n) return;
    if (strcmp(n->name, "StructDecl") == 0) {
        emit_struct_decl(n, out);
    }
    for (int i = 0; i < n->num_children; i++) {
        collect_types(n->children[i], out);
    }
}

static void collect_globals(ASTNode* n, FILE* out) {
    if (!n) return;
    if (strcmp(n->name, "FuncDecl") == 0) {
        emit_func_decl(n, out);
        return;
    } else if (strcmp(n->name, "Declarations") == 0) {
        for (int i = 0; i < n->num_children; i++) {
            ASTNode* d = n->children[i];
            if (strcmp(d->name, "Decl") == 0 && strcmp(d->children[0]->name, "VarDecl") == 0) {
                emit_statement(d->children[0], out, 0);
            } else {
                collect_globals(d, out);
            }
        }
        return;
    }
    for (int i = 0; i < n->num_children; i++) {
        collect_globals(n->children[i], out);
    }
}

static void collect_main(ASTNode* n, FILE* out) {
    if (!n) return;
    if (strcmp(n->name, "MainBlock") == 0) {
        for (int i = 0; i < n->num_children; i++) {
            if (strcmp(n->children[i]->name, "Statements") == 0) {
                emit_statements(n->children[i], out, 1);
            }
        }
        return;
    }
    for (int i = 0; i < n->num_children; i++) {
        collect_main(n->children[i], out);
    }
}

int codegen_c(ASTNode* root, FILE* out) {
    if (!root || !out) return -1;

    fprintf(out, "/* Generated by OPEX Compiler */\n");
    fprintf(out, "#include \"runtime.h\"\n\n");

    // Pass 1: Structs
    collect_types(root, out);

    // Pass 2: Globals and Functions
    collect_globals(root, out);

    // Pass 3: Main Block
    fprintf(out, "int main(int argc, char* argv[]) {\n");
    fprintf(out, "    (void)argc; (void)argv;\n");
    collect_main(root, out);
    fprintf(out, "    return 0;\n");
    fprintf(out, "}\n");

    return 0;
}

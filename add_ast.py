import re

# Update lexer.l
with open('src/lexer.l', 'r') as f:
    lex_text = f.read()

lex_text = re.sub(r'\{\s*return\s+(TOK_[A-Z_]+)\s*;\s*\}', r'{ yylval.node = make_node("\1", yytext, 0); return \1; }', lex_text)

loc_logic = """
#include <string.h>
#include "ast.h"

int yycolumn = 1;

#define YY_USER_ACTION \\
    yylloc.first_line = yylloc.last_line = yylineno; \\
    yylloc.first_column = yycolumn; \\
    yylloc.last_column = yycolumn + yyleng - 1; \\
    yycolumn += yyleng;
"""

if 'int yycolumn =' not in lex_text:
    lex_text = lex_text.replace('#include "parser.tab.h"', '#include "parser.tab.h"\n' + loc_logic)

lex_text = lex_text.replace('%option noyywrap case-sensitive', '%option noyywrap case-sensitive yylineno')
lex_text = re.sub(r'\\n\s+\{\s*line_num\+\+;\s*\}', r'\\n                          { yycolumn = 1; }', lex_text)

with open('src/lexer.l', 'w') as f:
    f.write(lex_text)

# Update parser.y
with open('src/parser.y', 'r') as f:
    yacc_text = f.read()

yacc_text = yacc_text.replace('%define parse.error verbose', '')  
yacc_text = yacc_text.replace('%error-verbose', '')
yacc_text = yacc_text.replace('%locations', '')
yacc_text = yacc_text.replace('%start Program', '%error-verbose\n%locations\n%start Program')

if '#include "ast.h"' not in yacc_text:
    yacc_text = yacc_text.replace('#include <stdlib.h>', '#include <stdlib.h>\n#include "ast.h"\n')

union_str = """
%union {
    struct ASTNode* node;
}
"""
if '%union' not in yacc_text:
    yacc_text = yacc_text.replace('// Precedence', union_str + '\n// Precedence')

yacc_text = re.sub(r'%token\s+(?!<node>)', r'%token <node> ', yacc_text)

non_terminals = [
    "Program", "Declarations", "Decl", "Type", "ArrayType", "OptSemi", "VarDecl",
    "StructDecl", "StructMembers", "StructMember", "FuncDecl", "ParamList", "Param",
    "MainBlock", "Statements", "Statement", "AssignStmt", "LValue", "IfStmt",
    "WhileStmt", "ForStmt", "ForeachStmt", "MatchStmt", "MatchWhenList", "MatchWhen",
    "IOStmt", "ReturnStmt", "FuncCallStmt", "ImageOpFunc", "ArgList", "Expr",
    "RangeExpr", "ArrayInitializer"
]
if '%type <node>' not in yacc_text:
    types_str = "\n".join([f"%type <node> {nt}" for nt in non_terminals]) + "\n"
    yacc_text = yacc_text.replace('%start Program', types_str + '%start Program')

out_lines = []
in_rules = False
current_lhs = ""

lines = yacc_text.split('\n')
for line in lines:
    if line == '%%':
        in_rules = not in_rules
        out_lines.append(line)
        continue
    
    if in_rules:
        m = re.match(r'^([A-Za-z_]+):', line)
        if m:
            current_lhs = m.group(1)
            out_lines.append(line)
            continue
        
        if line.strip() == ';':
            out_lines.append(line)
            continue
            
        rule_content = line.strip()
        if not rule_content:
            out_lines.append(line)
            continue

        prefix = line[:len(line) - len(line.lstrip())]
        
        has_pipe = False
        if rule_content.startswith('|'):
            rule_content = rule_content[1:].strip()
            has_pipe = True
            
        if rule_content == "/* empty */":
            action = f'{{ $$ = make_node("{current_lhs}", NULL, 0); }}'
            out_lines.append(prefix + ("| " if has_pipe else "") + rule_content + " " + action)
            continue

        alternatives = rule_content.split('|')
        rebuilt_alts = []
        for alt in alternatives:
            clean_alt = re.sub(r'%prec\s+[A-Za-z_]+', '', alt).strip()
            symbols = clean_alt.split()
            if len(symbols) == 0:
                continue
            args = ", ".join([f"${i+1}" for i in range(len(symbols))])
            action = f'{{ $$ = make_node("{current_lhs}", NULL, {len(symbols)}, {args}); }}'
            
            if current_lhs == "Program":
                action = f'{{ $$ = make_node("{current_lhs}", NULL, {len(symbols)}, {args}); printReverseDerivation($$); }}'
                
            rebuilt_alts.append(alt.strip() + " " + action)
            
        out_lines.append(prefix + ("| " if has_pipe else "") + " | ".join(rebuilt_alts))
            
    else:
        out_lines.append(line)

with open('src/parser.y', 'w') as f:
    f.write("\n".join(out_lines))

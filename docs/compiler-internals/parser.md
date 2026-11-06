# Syntax & LALR(1) Parsing

The Syntax Analyzer enforces the formal Context-Free Grammar (CFG) of OPEX using GNU Bison (Yacc) to construct an LALR(1) finite state automaton.

---

## Conflict Resolution: 172 to 0 Fatal Conflicts

Initial grammar specifications frequently exhibit structural overlaps. In our preliminary Bison build, the automaton contained:
- **81 Shift/Reduce Conflicts**: Stemming from optional semicolons (`OptSemi`) and operator precedence lookaheads.
- **173 Reduce/Reduce Conflicts**: Fatal intersections where multiple non-terminals overlapped on identical token sequences (notably in State 74, where standalone function calls overlapped with general expressions).

### Resolution Strategy
1. **Collapsed Expression Wrappers**: Stripped duplicated expression layers (`Statement -> Expr` vs `Statement -> FuncCallStmt`).
2. **Normalized Array Definitions**: Replaced specialized integer-only dimensions with generalized expressions.
3. **Formal Operator Precedence**: Assigned explicit Bison `%left` and `%right` precedence declarations.

**Result**: Reduced the 173 Reduce/Reduce conflicts down to precisely **0 fatal conflicts** (1 harmless structural lookahead in State 57 for user-defined struct types).

---

## Reverse Derivation Tree

A Bottom-Up LALR(1) parser naturally uncovers **Rightmost derivations in reverse order**.

During parsing, semantic actions allocate tree nodes (`make_node()`):

```c
Program:
    TOK_PROGRAM TOK_ID Declarations MainBlock { 
        $$ = make_node("Program", NULL, 4, $1, $2, $3, $4); 
        root = $$; 
    }
```

Running `./opex --derivations < file.opx` traverses the resulting AST in post-order, printing the exact derivation sequence used by the shift-reduce stack.

---

## Automated Parsing Table Extraction

Using [`print_table.py`](https://github.com/gaurav-budhwani/OPEX/blob/main/print_table.py), Bison's raw diagnostic output (`parser.output`) is processed into an Excel-compatible CSV parsing table:

```bash
python3 print_table.py > table.csv
```

The resulting table maps all **339 states** against every terminal and non-terminal symbol with their associated `shift`, `reduce`, and `goto` transitions.


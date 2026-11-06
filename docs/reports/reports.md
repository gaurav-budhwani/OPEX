# Academic Course Reports & Deliverables

The development of the OPEX compiler was structured across 4 rigorous academic assignment milestones for **CS327: Compilers** at IIT Gandhinagar under **Prof. Shouvick Mondal**.

---

## 1. Assignment 2: Lexical Analysis
- **Focus**: Regular expressions, DFA state machines, Flex specifications, token frequency analysis.
- **Repository PDF**: [`A2_Report.pdf`](https://github.com/gaurav-budhwani/OPEX/blob/main/A2_Report.pdf)
- **Key Deliverable**: Implementation of [`src/lexer.l`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/lexer.l) with coordinate tracking.

---

## 2. Assignment 3: Syntax Analysis
- **Focus**: Context-Free Grammars (CFG), LALR(1) state generation in Bison, Bottom-Up reverse derivation tracking, resolution of 172 Reduce/Reduce conflicts, and automated parsing table generation.
- **Repository PDF**: [`A3_Report.pdf`](https://github.com/gaurav-budhwani/OPEX/blob/main/A3_Report.pdf)
- **LaTeX Source**: [`A3_Report.tex`](https://github.com/gaurav-budhwani/OPEX/blob/main/A3_Report.tex)
- **Key Deliverable**: Parser implementation in [`src/parser.y`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/parser.y) and table generator [`print_table.py`](https://github.com/gaurav-budhwani/OPEX/blob/main/print_table.py).

---

## 3. Assignment 4: Intermediate Code Generation
- **Focus**: Syntax-Directed Translation (SDT), post-order AST traversal, virtual registers (`t1`, `t2`), label jump algorithms, and Three-Address Code (3AC) Quadruple outputs.
- **Repository PDF**: [`A4_Report.pdf`](https://github.com/gaurav-budhwani/OPEX/blob/main/A4_Report.pdf)
- **LaTeX Source**: [`A4_Report.tex`](https://github.com/gaurav-budhwani/OPEX/blob/main/A4_Report.tex)
- **Key Deliverable**: Intermediate code generator [`src/ir.c`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/ir.c) and 17 generated IR quadruple logs in [`ir_outputs/`](https://github.com/gaurav-budhwani/OPEX/tree/main/ir_outputs).

---

## 4. Language Specification
- **Authoritative Manual**: [`language_specifications.pdf`](https://github.com/gaurav-budhwani/OPEX/blob/main/language_specifications.pdf)
- Outlines the complete lexical rules, grammar, operator precedence tables, and computer vision typing expectations.

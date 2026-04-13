# Semantic Analyzer & Intermediate Code Generator (Assignment 4)

This branch natively maps the **Intermediate Code Generator (3AC)** for the OPEX programming language.

## Team
- **Gaurav Budhwani** (22110085)
- **John Twipraham Debbarma** (22110108)
- **Harshit** (22110095)

## Overview
The compiler engine has shifted from an explicit LALR(1) Syntax verifier into a pure Syntax Directed Translation (SDT) engine capable of evaluating algorithmic loops, array jumps, and boolean conditionals cleanly into **Three Address Code (TAC) Quadruples**.

## Project Structure
- `src/ir.c` & `src/ir.h`: The Core Post-Order AST mapping matrices dropping the TAC sequences dynamically natively tracking `temp()` and array logic allocations.
- `src/parser.y` & `src/lexer.l`: The foundational compilation nodes ensuring mathematical integrity before translation kicks into execution bounds.
- `tests/`: 12 mathematically intense OPEX structures enforcing Turing evaluation. 
- `ir_outputs/`: The exact rendered `.ir` quadruple sequences exported side-by-side with the OPEX Source Code.
- `A4_Report.pdf`: The complete comprehensive execution thesis.

## How to Build & Evaluate the Quadruples

1. **Recompile the Internal Engine**:
    ```bash
    make clean && make
    ```
2. **Execute Full 12-Script TAC Conversion**:
    ```bash
    make test_ir
    ```
This routine explicitly triggers the 100% compliant export mechanism mathematically matching the exact assignments bounding constraints directly into `/ir_outputs/`.

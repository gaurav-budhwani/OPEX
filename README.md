# Syntax Analyzer

This branch contains the **Syntax Analyzer (Parser)** for the OPEX programming language, developed for CS327: Compilers.

## Team
- **Gaurav Budhwani** (22110085)
- **John Twipraham Debbarma** (22110108)
- **Harshit** (22110095)

## Overview
The Syntax Analyzer is built using **Bison (Yacc)** and **Flex**. It validates the syntax of OPEX programs against a defined Context-Free Grammar (CFG), supporting features like structs, matrix indexing, logic, loop controls, and image processing operations.

## Project Structure
- `src/parser.y`: The Bison grammar specification.
- `src/lexer.l`: The Flex lexer modified to return Bison tokens.
- `tests/`: 12 diverse `.opx` test files demonstrating language constructs.
- `A3_Report.tex` / `A3_Report.pdf`: Comprehensive report including the CFG and deliverables.
- `Makefile`: Build scripts to automate compilation.

## How to Build & Test
Please ensure `gcc`, `flex`, and `bison` are installed.

1.  **Compile the Parser:**
    ```bash
    make
    ```
2.  **Run specific test file:**
    ```bash
    ./parser < tests/sample.opx
    ```
3.  **Run all test cases:**
    ```bash
    make test_all
    ```

If the syntax is correct, the parser will output:
`Syntax Correct`

Otherwise, it will output a granular line-by-line syntax error.

Please check A3_report.pdf for the further details in this current directory.


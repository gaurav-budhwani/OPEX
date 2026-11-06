# Compiler Architecture & Pipeline

The OPEX compiler is built using a classical multi-pass architecture, engineered for correctness, clean abstractions, and native machine execution.

---

## High-Level Compilation Flow

```mermaid
flowchart TD
    subgraph FrontEnd ["Front-End Phase"]
        Src["Source Code (.opx)"] --> Lexer["Lexical Analyzer (Flex)"]
        Lexer --> Tokens["Token Stream"]
        Tokens --> Parser["Syntax Analyzer (Bison)"]
        Parser --> AST["Abstract Syntax Tree (AST)"]
    end
    
    subgraph MiddleEnd ["Middle-End Phase"]
        AST --> Semantic["Semantic Analyzer & Symbol Table"]
        Semantic -->|"Phase 1: IR Generation"| SDT["Syntax Directed Translation"]
        SDT --> IR["Three-Address Code (3AC Quadruples)"]
    end
    
    subgraph BackEnd ["Back-End Phase"]
        Semantic -->|"Phase 2: Code Generation"| Lowering["C99 Low-Level Code Generator"]
        Lowering --> CSource["Intermediate C Source (.c)"]
        CSource --> Runtime["OPEX Runtime (runtime.h)"]
        Runtime --> HostCC["Host C Compiler (GCC / Clang)"]
        HostCC --> Binary["Native Machine Binary (Mach-O / ELF)"]
    end

    classDef stage fill:#ffffff,stroke:#7c3aed,stroke-width:1.5px,color:#0f172a,rx:6px,ry:6px;
    classDef sub fill:#fcfbfe,stroke:#ddd6fe,stroke-width:1px,color:#6d28d9;
    class Src,Lexer,Tokens,Parser,AST,Semantic,SDT,IR,Lowering,CSource,Runtime,HostCC,Binary stage;
    class FrontEnd,MiddleEnd,BackEnd sub;
```

---

## Architectural Stages

### 1. Front-End: Lexing & Parsing
- **Scanner**: Implemented in Flex ([`src/lexer.l`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/lexer.l)). Recognizes keywords, literals, range operators, and comments. Automatically tracks column and line coordinates via `YY_USER_ACTION`.
- **Parser**: Implemented in Bison ([`src/parser.y`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/parser.y)). Validates syntax against an LALR(1) Context-Free Grammar.
- **AST Construction**: Semantic actions dynamically allocate memory for an N-ary Abstract Syntax Tree ([`src/ast.c`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/ast.c)).

### 2. Middle-End: Semantic Validation & 3AC
- **Semantic Analyzer**: Traverses the AST with a scoped symbol table to catch undeclared variables and duplicate declarations ([`src/semantic.c`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/semantic.c)).
- **Intermediate Representation**: Post-order AST traversal emits Three-Address Code (3AC) Quadruples (`op, arg1, arg2, result`) managing temporary registers and jump labels ([`src/ir.c`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/ir.c)).

### 3. Back-End: Native Code Generation
- **Target Lowering**: Lowers the verified AST into clean, structured C99 ([`src/codegen.c`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/codegen.c)).
- **Runtime Library**: Links against a self-contained header ([`src/runtime.h`](https://github.com/gaurav-budhwani/OPEX/blob/main/src/runtime.h)) implementing memory buffers, convolution, and image filtering.
- **Native Execution**: Invokes `gcc`/`clang` to generate bare-metal executables.


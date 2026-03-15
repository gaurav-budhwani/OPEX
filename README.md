# OPEX Language

**OPEX** (Optimized Processing Engine for eXecution) is a domain-specific programming language designed for CS327: Compilers. It features strongly-typed semantics, built-in computer vision matrix operations, structured object constructs, and dynamic loop workflows.

---

## Language Specifications

The authoritative specifications for OPEX are provided in the `language_specifications.pdf`. This defines the Lexical rules, Context-Free Grammar, constraints, scoping limits, and compiler expectations.

### Core Features
- **Strongly Typed**: Supports `INT`, `FLOAT`, `BOOL`, `STRING`, `VOID`.
- **Implicit Typing**: Leverages `AUTO` keyword for type inference on assignment.
- **Complex Structures**: User-defined `STRUCT` compositions supporting nested traits.
- **Collections**: Supports 1D and 2D `ARRAY` constructs with advanced slicing options.
- **Image Processing Types**: First-class support for `IMAGE`, `MATRIX`, `KERNEL`, and `PIXEL`.
- **Advanced Control Flow**: Standard loops (`FOR`, `WHILE`), traversals (`FOREACH IN`), and robust pattern matching (`MATCH ... WHEN`).
- **Computer Vision Operators**: Built-in convolution (`**`) and filter pipelines (`|>` for chaining).

### Example: Edge Detection
```opex
PROGRAM EdgeDetection
BEGIN
    KERNEL sobelX := [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]
    AUTO img := LOAD("input.jpg")
    AUTO gray := GRAYSCALE(img)
    AUTO edges := (gray ** sobelX) |> THRESHOLD(50)
    SAVE(edges, "edges.png")
END
```

---

## Architectural Branches

The development cycle of the OPEX Compiler spans across different subsystems. Each phase of the compilation process is maintained in a distinct Git branch:

### [`lexer` Branch](https://github.com/gaurav-budhwani/OPEX/tree/lexer)
Contains the Lexical Analyzer (Scanner). Utilizes **Flex** to tokenize OPEX source files. Defines all Regex mappings and verifies that the provided keywords and operators are recognized correctly.

### [`parser` Branch](https://github.com/gaurav-budhwani/OPEX/tree/parser)
Contains the Syntax Analyzer. Utilizes **Bison (Yacc)** to evaluate the stream of tokens against the strict Context-Free Grammar of OPEX. Will catch syntax violations, bracket mismatches, and incorrect statement structuring. Includes comprehensive `.opx` integration tests.

---

## Contributors (CS327)
- **Gaurav Budhwani** (22110085)
- **John Twipraham Debbarma** (22110108)
- **Harshit** (22110095)

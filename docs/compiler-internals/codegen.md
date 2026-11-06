# Native Code Generation

The final compiler pass lowers the AST into standard ISO C99, linking against the OPEX runtime to generate native machine binaries.

---

## Why Lower to C99?

Rather than emitting raw assembly for a single architecture (e.g. x86-64 only), lowering through C99 provides distinct engineering advantages:

1. **Cross-Platform Portability**: Compiles identically on macOS (ARM64 Apple Silicon), Linux (x86-64, AArch64), and BSD.
2. **Industrial Optimization**: The host compiler (`clang` or `gcc`) automatically performs SIMD vectorization, register allocation, and dead code elimination with `-O2`.
3. **Robust Runtime Integration**: Memory allocation, call stacks, and recursion are managed with zero overhead.

---

## Driver Workflow (`opex --run` & `-o`)

When compiling or running an OPEX program:

```
[OPEX Source]
     │
     ▼ (parse & validate)
[Verified AST]
     │
     ▼ (codegen.c)
[/tmp/opex_<pid>.c]  ───> Links with [src/runtime.h]
     │
     ▼ (gcc -O2 -lm)
[Native Mach-O / ELF Binary]
     │
     ▼ (execute & cleanup)
[stdout / Return Code]
```

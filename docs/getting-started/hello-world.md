# Hello World in OPEX

Every OPEX source file uses the `.opx` extension and follows a clear program structure.

---

## Your First Program

Create a file named `hello.opx`:

```opex
PROGRAM HelloWorld
BEGIN
    PRINT "Hello, OPEX World!";
    
    VAR year : INT;
    year := 2026;
    
    PRINT "Compiler running in year {year}!";
END
```

---

## Running Your Program

You have two primary ways to run an OPEX program:

### Method 1: On-the-Fly Execution (`--run`)
Executes the code directly, ideal for quick testing, development, and scripting:

```bash
./opex --run hello.opx
```

**Output:**
```
Hello, OPEX World!
Compiler running in year 2026!
```

---

### Method 2: Standalone Native Binary Compilation (`-o`)
Compiles the OPEX code into an optimized native machine binary (`Mach-O` on macOS, `ELF` on Linux):

```bash
# Compile to a native executable
./opex -o hello hello.opx

# Inspect the binary
file hello
# Output: hello: Mach-O 64-bit executable arm64

# Execute anywhere
./hello
```

---

## Program Structure Anatomy

1. **`PROGRAM <Identifier>`**: Defines the program entry namespace.
2. **`BEGIN ... END`** or **`MAIN BEGIN ... END`**: Encloses the main executable block.
3. **`VAR <Identifier> : <Type>;`**: Statically typed variable declaration.
4. **`:=`**: The OPEX assignment operator.
5. **`PRINT "<text> {variable}"`**: Formatted output with dynamic string interpolation.


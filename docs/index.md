# OPEX Programming Language

<p align="center">
  <strong>Optimized Processing Engine for eXecution</strong><br>
  <em>A domain-specific compiled programming language for algorithms and computer vision pipelines.</em>
</p>

---

## What is OPEX?

**OPEX** is a statically-typed domain-specific programming language and multi-stage optimizing compiler developed for **CS327: Compilers** at IIT Gandhinagar. It bridges classical algorithmic computing with high-level computer vision workflows, providing first-class language support for multi-channel images, matrix transformations, spatial convolution, and pipeline filter chaining.

```opex
PROGRAM EdgeDetectionDemo
BEGIN
    // Define 3x3 Sobel spatial kernels
    KERNEL sobelX := [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]
    KERNEL sobelY := [[-1, -2, -1], [ 0,  0,  0], [ 1,  2,  1]]

    // Load and convert image to grayscale
    AUTO img   := LOAD("input.jpg")
    AUTO gray  := GRAYSCALE(img)

    // Convolve with Sobel kernels and chain through binary thresholding
    AUTO edges := ((gray ** sobelX) + (gray ** sobelY)) |> THRESHOLD(50)

    // Save final edge map
    SAVE(edges, "edges.png")
    PRINT "Edge detection complete for {img.width}x{img.height} image."
END
```

---

## Core Features

=== "Strong & Inferred Typing"
    Supports primitive types `INT`, `FLOAT`, `BOOL`, `STRING`, and `VOID`. The `AUTO` keyword allows compile-time type inference on initial assignment without sacrificing type safety.

=== "Computer Vision First-Class Types"
    Native language primitives for `IMAGE`, `MATRIX`, `KERNEL`, and `PIXEL`. Manipulate pixels, channels, and spatial matrices with clean language syntax rather than verbose C API calls.

=== "Convolution (`**`) & Pipeline (`|>`) Operators"
    Perform 2D image convolution with kernels using the infix `**` operator (`gray ** sobelX`). Pipe image transformations sequentially using the Unix-style `|>` pipeline operator (`img |> GRAYSCALE |> THRESHOLD(50)`).

=== "Data Structures & Control Flow"
    Fixed-size 1D and 2D arrays (`ARRAY [10][10] OF INT`), user-defined `STRUCT` compositions with field access, `FOR ... TO ... STEP`, `FOREACH ... IN`, `WHILE`, and pattern matching (`MATCH ... WHEN`).

=== "Native Binary Compilation"
    The compiler lowers OPEX code through an LALR(1) parser and Three-Address Code (3AC) intermediate representation into optimized C99, compiling to standalone **Mach-O / ELF native binaries** with bare-metal speed.

---

## Quick Start

```bash
# Clone repository
git clone https://github.com/gaurav-budhwani/OPEX.git
cd OPEX

# Compile compiler binary
make

# Run an OPEX program on the fly
./opex --run tests/bubble_sort.opx

# Or compile to a standalone native binary
./opex -o myprogram tests/bubble_sort.opx
./myprogram
```

---

## Contributors

Developed for **CS327: Compilers** under the guidance of **Prof. Shouvick Mondal**:

- **Gaurav Budhwani** (22110085)
- **John Twipraham Debbarma** (22110108)
- **Harshit** (22110095)

# Types & Variables

OPEX is a statically-typed language with compile-time type checking and support for implicit type inference.

---

## Primitive Data Types

| Type | Bit Width | Description | Default |
| :--- | :--- | :--- | :--- |
| **`INT`** | 64-bit | Signed integers, pixel coordinates, loop counters | `0` |
| **`FLOAT`** | 64-bit | Double precision IEEE 754 floating point numbers | `0.0` |
| **`BOOL`** | 8-bit | Boolean flags (`TRUE`, `FALSE`) | `FALSE` |
| **`STRING`** | Dynamic | UTF-8 string literals with `{var}` interpolation | `""` |
| **`VOID`** | 0-bit | Function return type indicating no return value | N/A |

### Explicit Declarations (`VAR`)

Variables declared using the `VAR` keyword must explicitly define their type:

```opex
VAR count : INT;
VAR pi : FLOAT;
VAR active : BOOL;
VAR greeting : STRING;

count := 42;
pi := 3.1415926535;
active := TRUE;
greeting := "Welcome to OPEX";
```

---

## Type Inference (`AUTO`)

The `AUTO` keyword deduces the variable's type from its initialization expression at compile time:

```opex
AUTO steps := 100;           // Inferred as INT
AUTO threshold := 0.75;      // Inferred as FLOAT
AUTO enabled := TRUE;        // Inferred as BOOL
AUTO label := "Normalized";  // Inferred as STRING
```

> **Note**: Once inferred, the type of an `AUTO` variable is immutable. You cannot assign a float to an `AUTO` variable initialized with an integer.

---

## Collections (`ARRAY`)

Arrays in OPEX are fixed-size, homogeneous collections allocated in contiguous memory.

### 1D Arrays
```opex
// 10-element integer array
VAR buffer : ARRAY[10] OF INT;

buffer[0] := 5;
buffer[1] := 10;
```

### 2D Arrays (Matrices)
```opex
// 3x3 matrix
VAR grid : ARRAY[3][3] OF INT;

grid[0][0] := 1;
grid[0][1] := 0;
grid[0][2] := 0;
```

### Array Slicing
Arrays support range-based slicing using the `..` operator:

```opex
VAR subRegion : ARRAY[5][10] OF INT;
subRegion := matrixA[0..5];
```

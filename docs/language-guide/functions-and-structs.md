---
icon: material/function
---

# Functions & Structs

OPEX supports modular program architecture through functions, recursion, and user-defined product types (`STRUCT`).

---

## Functions

Functions are defined with explicit parameter lists and return types:

```opex
FUNCTION add(a : INT, b : INT) : INT
BEGIN
    RETURN a + b;
END

FUNCTION logMessage(msg : STRING) : VOID
BEGIN
    PRINT msg;
END
```

### Recursive Functions
OPEX features full support for deep recursion with native call-stack frame management:

```opex
// Recursive Fibonacci
FUNCTION fib(n : INT) : INT
BEGIN
    IF n <= 1 THEN
        RETURN n;
    ELSE
        RETURN fib(n - 1) + fib(n - 2);
    ENDIF
END

// Recursive Greatest Common Divisor (GCD)
FUNCTION gcd(a : INT, b : INT) : INT
BEGIN
    IF b == 0 THEN
        RETURN a;
    ELSE
        RETURN gcd(b, a % b);
    ENDIF
END
```

---

## User-Defined Structs (`STRUCT`)

`STRUCT` definitions group related data into custom record types:

```opex
STRUCT Point
    x : INT;
    y : INT;
ENDSTRUCT

STRUCT Stack
    data : ARRAY[10] OF INT;
    top : INT;
ENDSTRUCT
```

### Struct Instantiation and Field Access
Struct members are accessed using the dot (`.`) operator:

```opex
VAR s : Stack;

// Initialize stack fields
s.top := -1;
s.top := s.top + 1;
s.data[s.top] := 100;

PRINT "Top index: {s.top}";
PRINT "Top value: {s.data[s.top]}";
```


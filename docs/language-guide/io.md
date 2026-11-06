# Input & Output

OPEX provides clean, high-level primitives for standard I/O and dynamic string interpolation.

---

## Output (`PRINT`)

The `PRINT` statement outputs values to standard output (`stdout`), automatically appending a newline.

### Basic Printing
```opex
PRINT "Hello World";
PRINT 42;
PRINT 3.14159;
PRINT TRUE;
```

### String Interpolation
String literals can embed any variable or property expression inside `{...}` braces:

```opex
VAR name : STRING;
VAR score : INT;

name := "Alice";
score := 98;

PRINT "Player {name} achieved a score of {score}!";
```

Interpolation also supports accessing struct fields and image metadata:

```opex
PRINT "Image resolution: {img.width}x{img.height}";
PRINT "Current node: {node.id}, distance: {node.dist}";
```

---

## Input (`INPUT`)

The `INPUT` statement reads values from standard input (`stdin`) into a target variable:

```opex
VAR age : INT;
PRINT "Enter your age:";
INPUT age;

PRINT "You will be {age + 1} next year.";
```

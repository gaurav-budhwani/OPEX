---
icon: material/transit-connection-variant
---

# Control Flow

OPEX provides modern, expressive constructs for branching and looping.

---

## Conditionals (`IF ... THEN ... ELSE`)

Conditionals evaluate boolean expressions:

```opex
IF score >= 90 THEN
    PRINT "Grade: A";
ELSE
    IF score >= 75 THEN
        PRINT "Grade: B";
    ELSE
        PRINT "Grade: C";
    ENDIF
ENDIF
```

---

## Loops

### Count-Controlled Loop (`FOR`)
The `FOR` loop iterates an integer variable from a start expression to an end expression inclusive:

```opex
// Basic loop from 0 to 9 (step = 1)
FOR i := 0 TO 9 DO
    PRINT i;
ENDFOR

// Loop with custom STEP increment
FOR i := 0 TO 100 STEP 10 DO
    PRINT i;
ENDFOR
```

### Collection Traversal (`FOREACH IN`)
Iterate over array elements without manual index management:

```opex
VAR numbers : ARRAY[5] OF INT;
// Fill numbers...

FOREACH val IN numbers DO
    PRINT val;
ENDFOR
```

### Condition-Controlled Loop (`WHILE`)
Executes statements while the condition evaluates to `TRUE`:

```opex
VAR count : INT;
count := 10;

WHILE count > 0 DO
    PRINT count;
    count := count - 1;
ENDWHILE
```

---

## Pattern Matching (`MATCH ... WHEN`)

The `MATCH` statement replaces nested `if-else` chains with clean pattern branches:

```opex
MATCH status
    WHEN 200:
        PRINT "HTTP OK";
    WHEN 404:
        PRINT "HTTP Not Found";
    WHEN 500:
        PRINT "Server Error";
ENDMATCH
```


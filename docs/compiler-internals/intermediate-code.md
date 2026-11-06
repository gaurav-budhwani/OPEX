# Intermediate Representation (3AC)

Before target code generation, the compiler translates high-level AST trees into **Three-Address Code (3AC) Quadruples**.

---

## Quadruple Structure

Each quadruple represents a linearized instruction of the form:

$$\text{op} \quad \text{arg1} \quad \text{arg2} \quad \text{result}$$

```c
typedef struct Quad {
    char* op;
    char* arg1;
    char* arg2;
    char* result;
    struct Quad* next;
} Quad;
```

---

## Example: Recursive Fibonacci IR

For the OPEX source:
```opex
IF n <= 1 THEN
    RETURN n;
ELSE
    RETURN fib(n - 1) + fib(n - 2);
ENDIF
```

The SDT engine emits the following quadruples:

```
op           arg1            arg2            result         
-----------------------------------------------------------
func         fib                                            
<=           n               1               t1             
ifFalse      t1                              L2             
return       n                                              
goto                                         L1             
Label                                        L2             
-            n               1               t2             
param        t2                                             
call         fib             1               t3             
-            n               2               t4             
param        t4                                             
call         fib             1               t5             
+            t3              t5              t6             
return       t6                                             
Label                                        L1             
endfunc      fib                                            
```

---

## Control Flow Flattening

- **Conditionals (`IF / ELSE`)**: Flattens nested blocks using conditional `ifFalse <cond> <label>` jumps.
- **Loops (`WHILE`, `FOR`)**: Injects a top loop marker (`L_start`), evaluates the invariant, and jumps back upon iteration completion (`goto L_start`).
- **Temporary Register Management**: Dynamically allocates unbounded virtual registers (`t1`, `t2`, `t3`, ...).

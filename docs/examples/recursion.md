# Recursive Algorithms

OPEX fully supports recursive subroutines with stack frame management.

---

## 1. Recursive Fibonacci (`tests/fibonacci.opx`)

```opex
PROGRAM FibRecursive
    FUNCTION fib(n : INT) : INT
    BEGIN
        IF n <= 1 THEN
            RETURN n;
        ELSE
            RETURN fib(n - 1) + fib(n - 2);
        ENDIF
    END

MAIN
BEGIN
    VAR terms : INT;
    VAR i : INT;

    PRINT "How many terms?";
    INPUT terms;

    PRINT "Fibonacci Sequence:";
    FOR i := 0 TO terms DO
        PRINT fib(i);
    ENDFOR
END
```

### Execution Output (`terms = 7`)
```
Fibonacci Sequence:
0
1
1
2
3
5
8
13
```

---

## 2. Recursive Euclidean GCD (`tests/gcd_recursive.opx`)

```opex
PROGRAM GCDRecursive
    FUNCTION gcd(a : INT, b : INT) : INT
    BEGIN
        IF b == 0 THEN
            RETURN a;
        ELSE
            RETURN gcd(b, a % b);
        ENDIF
    END

MAIN
BEGIN
    VAR num1 : INT;
    VAR num2 : INT;
    VAR result : INT;

    PRINT "Enter first number:";
    INPUT num1;
    PRINT "Enter second number:";
    INPUT num2;

    result := gcd(num1, num2);
    PRINT "GCD of {num1} and {num2} is {result}";
END
```

### Execution Output (`num1 = 48`, `num2 = 18`)
```
GCD of 48 and 18 is 6
```

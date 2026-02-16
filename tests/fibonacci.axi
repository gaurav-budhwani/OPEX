PROGRAM FibonacciSeq
BEGIN
    VAR n : INT;
    VAR t1 : INT;
    VAR t2 : INT;
    VAR nextTerm : INT;
    VAR i : INT;

    t1 := 0;
    t2 := 1;
    // Initialize nextTerm
    nextTerm := t1 + t2;

    PRINT "Enter the number of terms: ";
    INPUT n;

    PRINT "Fibonacci Series: {t1}, {t2}, ";

    FOR i := 3 TO n DO
        PRINT "{nextTerm}, ";
        t1 := t2;
        t2 := nextTerm;
        nextTerm := t1 + t2;
    ENDFOR
END

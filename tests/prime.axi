PROGRAM PrimeCheck
BEGIN
    VAR n : INT;
    VAR i : INT;
    VAR isPrime : BOOL;

    PRINT "Enter a number to check:";
    INPUT n;

    // Assume true initially
    isPrime := TRUE;

    // Handle edge cases
    IF n <= 1 THEN
        isPrime := FALSE;
    ENDIF

    // Iterate from 2 to n/2
    // OPEX's FOR loop automatically handles the range
    FOR i := 2 TO n / 2 DO
        // If n is divisible by i, it is not prime
        IF (n % i) == 0 THEN
            isPrime := FALSE;
        ENDIF
    ENDFOR

    IF isPrime == TRUE THEN
        PRINT "{n} is a Prime Number";
    ELSE
        PRINT "{n} is NOT a Prime Number";
    ENDIF
END

PROGRAM PrimeFactorization
BEGIN
    VAR n : INT;
    VAR i : INT;

    PRINT "Enter a number to find prime factors:";
    INPUT n;

    PRINT "Prime factors of {n}:";

    // Print the number of 2s that divide n
    WHILE (n % 2) == 0 DO
        PRINT "2 ";
        n := n / 2;
    ENDWHILE

    // n must be odd at this point. So we can skip one element (Note i = i + 2)
    FOR i := 3 TO n / 2 STEP 2 DO
        WHILE (n % i) == 0 DO
            PRINT "{i} ";
            n := n / i;
        ENDWHILE
    ENDFOR

    // This condition is to handle the case when n is a prime number
    // greater than 2
    IF n > 2 THEN
        PRINT "{n}";
    ENDIF
END

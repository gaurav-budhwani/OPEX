PROGRAM GCCCheck
BEGIN
    VAR n1 : INT;
    VAR n2 : INT;
    VAR result : INT;

    FUNCTION gcd(a : INT, b : INT) : INT
    BEGIN
        IF b == 0 THEN
            RETURN a;
        ELSE
            RETURN gcd(b, a % b);
        ENDIF
    END

    PRINT "Enter two positive integers: ";
    INPUT n1;
    INPUT n2;

    result := gcd(n1, n2);
    PRINT "G.C.D of {n1} and {n2} is {result}.";
END

PROGRAM MatrixMultiplication
BEGIN
    VAR r1 : INT;
    VAR c1 : INT;
    VAR r2 : INT;
    VAR c2 : INT;
    VAR i : INT;
    VAR j : INT;
    VAR k : INT;
    VAR a : ARRAY[10][10] OF INT;
    VAR b : ARRAY[10][10] OF INT;
    VAR result : ARRAY[10][10] OF INT;

    PRINT "Enter rows and columns for first matrix: ";
    INPUT r1;
    INPUT c1;
    PRINT "Enter rows and columns for second matrix: ";
    INPUT r2;
    INPUT c2;

    IF c1 != r2 THEN
        PRINT "Matrix multiplication not possible.";
        RETURN;
    ENDIF

    PRINT "Enter elements of matrix 1:";
    FOR i := 0 TO r1 - 1 DO
        FOR j := 0 TO c1 - 1 DO
            INPUT a[i][j];
        ENDFOR
    ENDFOR

    PRINT "Enter elements of matrix 2:";
    FOR i := 0 TO r2 - 1 DO
        FOR j := 0 TO c2 - 1 DO
            INPUT b[i][j];
        ENDFOR
    ENDFOR

    // Initialize result matrix
    FOR i := 0 TO r1 - 1 DO
        FOR j := 0 TO c2 - 1 DO
            result[i][j] := 0;
        ENDFOR
    ENDFOR

    // Multiply
    FOR i := 0 TO r1 - 1 DO
        FOR j := 0 TO c2 - 1 DO
            FOR k := 0 TO c1 - 1 DO
                result[i][j] += a[i][k] * b[k][j];
            ENDFOR
        ENDFOR
    ENDFOR

    PRINT "Resultant Matrix:";
    FOR i := 0 TO r1 - 1 DO
        FOR j := 0 TO c2 - 1 DO
            PRINT "{result[i][j]} ";
        ENDFOR
        PRINT "\n";
    ENDFOR
END

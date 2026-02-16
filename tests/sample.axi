PROGRAM MatrixMagic
    // Global Struct Definition
    STRUCT Pixel
        r : INT
        g : INT
        b : INT
    ENDSTRUCT

    FUNCTION initMatrix() : VOID
    BEGIN
        PRINT "Initializing...";
    END

MAIN
BEGIN
    // Type Inference: Compiler knows 'rows' is INT
    AUTO rows := 10;
    
    // 2D Array Declaration
    VAR matrixA : ARRAY[10][10] OF INT;
    VAR matrixB : ARRAY[10][10] OF INT;
    VAR sumMatrix : ARRAY[10][10] OF INT;

    // FOREACH Loop (Iterates through rows)
    FOREACH row IN matrixA DO
        FOREACH val IN row DO
            val := 5;
        ENDFOR
    ENDFOR

    // Vectorized Addition (Conceptual for Semantics)
    // In A4, this generates loops automatically
    sumMatrix := matrixA + matrixB;

    // Matrix Slicing (Accessing a sub-region)
    // Extracts rows 0 to 5
    VAR subRegion : ARRAY[5][10] OF INT;
    subRegion := matrixA[0..5];

    PRINT "Matrix Processing Complete";
END

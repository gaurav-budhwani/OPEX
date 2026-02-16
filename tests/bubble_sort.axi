PROGRAM BubbleSort
BEGIN
    VAR array : ARRAY[100] OF INT;
    VAR n : INT;
    VAR c : INT;
    VAR d : INT;
    VAR swap : INT;

    PRINT "Enter number of elements";
    INPUT n;
    PRINT "Enter {n} integers";

    FOR c := 0 TO n - 1 DO
        INPUT array[c];
    ENDFOR

    FOR c := 0 TO n - 2 DO
        FOR d := 0 TO n - c - 2 DO
            IF array[d] > array[d + 1] THEN
                swap       := array[d];
                array[d]   := array[d + 1];
                array[d + 1] := swap;
            ENDIF
        ENDFOR
    ENDFOR

    PRINT "Sorted list in ascending order:";

    FOR c := 0 TO n - 1 DO
        PRINT "{array[c]}";
    ENDFOR
END

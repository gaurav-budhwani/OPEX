PROGRAM BinarySearch
BEGIN
    VAR arr : ARRAY[10] OF INT;
    VAR n : INT;
    VAR i : INT;
    VAR x : INT;
    VAR low : INT;
    VAR high : INT;
    VAR mid : INT;
    VAR found : BOOL;

    n := 10;
    // Initialize sorted array
    FOR i := 0 TO n - 1 DO
        arr[i] := i * 2;
    ENDFOR

    PRINT "Enter element to search:";
    INPUT x;

    low := 0;
    high := n - 1;
    found := FALSE;

    WHILE low <= high DO
        mid := low + (high - low) / 2;

        IF arr[mid] == x THEN
            PRINT "Element found at index {mid}";
            found := TRUE;
            BREAK; // Assuming BREAK exists, otherwise logic needs adjustment
        ENDIF

        IF arr[mid] < x THEN
            low := mid + 1;
        ELSE
            high := mid - 1;
        ENDIF
    ENDWHILE

    IF found == FALSE THEN
        PRINT "Element not found";
    ENDIF
END

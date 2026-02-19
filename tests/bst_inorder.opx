PROGRAM BSTInOrder
BEGIN
    VAR tree : ARRAY[100] OF INT; // Array based BST
    VAR n : INT;
    VAR i : INT;

    FUNCTION inOrder(index : INT) : VOID
    BEGIN
        IF index >= 100 OR tree[index] == -1 THEN
            RETURN; // NULL equivalent
        ENDIF

        inOrder(2 * index);     // Left child
        PRINT "{tree[index]} "; // Root
        inOrder(2 * index + 1); // Right child
    END

    // Initialize tree with -1 (empty)
    FOR i := 0 TO 99 DO
        tree[i] := -1;
    ENDFOR

    // Hardcoded tree for testing
    //      10
    //     /  \
    //    5    15
    tree[1] := 10;
    tree[2] := 5;
    tree[3] := 15;

    PRINT "In-order Traversal:";
    inOrder(1);
END

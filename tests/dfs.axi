PROGRAM DFSAlgorithm
BEGIN
    VAR visited : ARRAY[10] OF INT;
    VAR adj : ARRAY[10][10] OF INT;
    VAR n : INT;
    VAR i : INT;
    VAR j : INT;
    VAR startNode : INT;

    FUNCTION DFS(u : INT) : VOID
    BEGIN
        VAR v : INT;
        PRINT "{u} ";
        visited[u] := 1;
        FOR v := 0 TO n - 1 DO
            IF adj[u][v] == 1 AND visited[v] == 0 THEN
                DFS(v);
            ENDIF
        ENDFOR
    END

    PRINT "Enter number of nodes:";
    INPUT n;

    PRINT "Enter adjacency matrix:";
    FOR i := 0 TO n - 1 DO
        visited[i] := 0;
        FOR j := 0 TO n - 1 DO
            INPUT adj[i][j];
        ENDFOR
    ENDFOR

    PRINT "Enter start node:";
    INPUT startNode;

    PRINT "DFS Traversal:";
    DFS(startNode);
END

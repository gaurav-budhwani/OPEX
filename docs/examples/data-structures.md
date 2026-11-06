# Data Structures

Implementations of classical computer science data structures using OPEX `STRUCT` compositions and functions.

---

## 1. Struct-Based Stack (`tests/stack.opx`)

```opex
PROGRAM StackDemo
    STRUCT Stack
        data : ARRAY[10] OF INT;
        top : INT;
    ENDSTRUCT

    VAR s : Stack;

    FUNCTION push(val : INT) : VOID
    BEGIN
        IF s.top >= 9 THEN
            PRINT "Error: Stack Overflow";
        ELSE
            s.top := s.top + 1;
            s.data[s.top] := val;
        ENDIF
    END

    FUNCTION pop() : INT
    BEGIN
        VAR val : INT;
        IF s.top < 0 THEN
            PRINT "Error: Stack Underflow";
            RETURN -1;
        ELSE
            val := s.data[s.top];
            s.top := s.top - 1;
            RETURN val;
        ENDIF
    END

MAIN
BEGIN
    s.top := -1;

    PRINT "Pushing 10, 20, 30...";
    push(10);
    push(20);
    push(30);

    PRINT "Popping values...";
    PRINT pop(); // 30
    PRINT pop(); // 20
    PRINT pop(); // 10
END
```

---

## 2. Circular Queue (`tests/queue.opx`)

```opex
PROGRAM QueueDemo
    STRUCT Queue
        data : ARRAY[5] OF INT;
        head : INT;
        tail : INT;
        count : INT;
        capacity : INT;
    ENDSTRUCT

    VAR q : Queue;

    FUNCTION enqueue(val : INT) : VOID
    BEGIN
        IF q.count == q.capacity THEN
            PRINT "Error: Queue Full";
        ELSE
            q.data[q.tail] := val;
            q.tail := (q.tail + 1) % q.capacity;
            q.count := q.count + 1;
        ENDIF
    END

    FUNCTION dequeue() : INT
    BEGIN
        VAR val : INT;
        IF q.count == 0 THEN
            PRINT "Error: Queue Empty";
            RETURN -1;
        ELSE
            val := q.data[q.head];
            q.head := (q.head + 1) % q.capacity;
            q.count := q.count - 1;
            RETURN val;
        ENDIF
    END

MAIN
BEGIN
    q.head := 0;
    q.tail := 0;
    q.count := 0;
    q.capacity := 5;

    PRINT "Enqueueing 1, 2, 3...";
    enqueue(1);
    enqueue(2);
    enqueue(3);

    PRINT "Dequeueing...";
    PRINT dequeue(); // 1
    PRINT dequeue(); // 2
END
```


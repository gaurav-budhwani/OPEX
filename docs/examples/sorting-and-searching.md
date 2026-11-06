---
icon: material/sort-alphabetical-ascending
---

# Sorting & Searching

Algorithmic implementations in OPEX demonstrating array manipulations, nested loops, and binary search.

---

## 1. Bubble Sort (`tests/bubble_sort.opx`)

Sorts an array of 5 integers in ascending order:

```opex
PROGRAM BubbleSort
BEGIN
    VAR arr : ARRAY[5] OF INT;
    VAR i : INT;
    VAR j : INT;
    VAR temp : INT;
    VAR n : INT;

    n := 5;
    
    // Initialize unsorted array
    arr[0] := 64;
    arr[1] := 34;
    arr[2] := 25;
    arr[3] := 12;
    arr[4] := 22;

    PRINT "Sorting array...";

    // Bubble Sort nested loops
    FOR i := 0 TO n - 2 DO
        FOR j := 0 TO n - i - 2 DO
            IF arr[j] > arr[j + 1] THEN
                temp := arr[j];
                arr[j] := arr[j + 1];
                arr[j + 1] := temp;
            ENDIF
        ENDFOR
    ENDFOR

    PRINT "Sorted Array:";
    FOREACH val IN arr DO
        PRINT val;
    ENDFOR
END
```

### Execution Output
```
Sorting array...
Sorted Array:
12
22
25
34
64
```

---

## 2. Binary Search (`tests/binary_search.opx`)

Performs $O(\log n)$ logarithmic search over a sorted 10-element array:

```opex
PROGRAM BinarySearch
BEGIN
    VAR data : ARRAY[10] OF INT;
    VAR target : INT;
    VAR low : INT;
    VAR high : INT;
    VAR mid : INT;
    VAR found : BOOL;
    
    FOR low := 0 TO 9 DO
        data[low] := low * 2;
    ENDFOR

    PRINT "Enter value to search for:";
    INPUT target;

    low := 0;
    high := 9;
    found := FALSE;

    WHILE low <= high DO
        mid := (low + high) / 2;
        IF data[mid] == target THEN
            PRINT "Found at index: {mid}";
            found := TRUE;
            low := high + 1; // Break
        ELSE
            IF data[mid] < target THEN
                low := mid + 1;
            ELSE
                high := mid - 1;
            ENDIF
        ENDIF
    ENDWHILE

    IF found == FALSE THEN
        PRINT "Value not found";
    ENDIF
END
```


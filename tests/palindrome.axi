PROGRAM PalindromeCheck
BEGIN
    VAR n : INT;
    VAR reversedInteger : INT;
    VAR remainder : INT;
    VAR originalInteger : INT;

    PRINT "Enter an integer: ";
    INPUT n;

    originalInteger := n;
    reversedInteger := 0;

    // reversed integer is stored in variable 
    WHILE ( n != 0 ) DO
        remainder := n % 10;
        reversedInteger := reversedInteger * 10 + remainder;
        n := n / 10;
    ENDWHILE

    // palindrome if orignalInteger and reversedInteger are equal
    IF originalInteger == reversedInteger THEN
        PRINT "{originalInteger} is a palindrome.";
    ELSE
        PRINT "{originalInteger} is not a palindrome.";
    ENDIF
END

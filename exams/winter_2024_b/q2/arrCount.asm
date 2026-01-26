


// ARRCOUNT:
(ARRCOUNT)
    // arr = (int*)*(SP + 1);
    @SP
    A = M + 1
    D = M
    @arr
    M = D

    // arrLength = (SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @arr
    M = D

    // int counter = 0;
    @counter
    M = 0

    // int i = 1;
    @i
    M = 1

// FOR:
(FOR)
    // if (i >= arrLength) goto END_FOR
    @arrLength
    D = M
    @i
    D = M - D
    @END_FOR
    D;JGE

    // firstDerivative = arr[i + 1] - arr[i - 1];
    @i
    D = M + 1
    @arr
    D = M + D
    A = D
    D = M
    @firstDerivative // arr[i + 1]
    M = D

    @i
    D = M - 1
    @arr
    D = M + D
    A = D
    D = M
    @firstDerivative
    D = M - D 

    // secondDerivative = arr[i + 1] - 2 * arr[i] + arr[i - 1];
    @i
    D = M + 1
    @arr
    D = M + D
    A = D
    D = M
    @secondDerivative // arr[i + 1]
    M = D

    @i
    D = M
    @arr
    D = M + D
    A = D
    D = M + M
    @secondDerivative // arr[i + 1] -2*arr[i]
    D = M - D
    M = D

    @i
    D = M - 1
    @arr
    D = M + D
    A = D
    D = M
    @secondDerivative
    D = M + D 

    (IF)
        // if (firstDerivative != 0) goto SKIP_IF
        @firstDerivative
        D = M
        @SKIP_IF
        D;JNE

        // if (secondDerivative >= 0) goto SKIP_IF
        @secondDerivative
        D = M
        @SKIP_IF
        D;JGE

        @counter
        M = M + 1

    // SKIP_IF:
    (SKIP_IF)
        @i
        M = M + 1
        @FOR
        0;JMP

// END_FOR:
(END_FOR)
    // D = arrCountRetAdd
    @counter
    D = M
    @arrCountRetAdd
    A = M
    0;JMP
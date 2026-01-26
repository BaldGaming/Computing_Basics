// ENCRYPTION:
(ENCRYPTION)
    // arr = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @arr
    M = D

    // size = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @size
    M = D

    // key = *(SP + 3);
    @3
    D = A
    @SP
    A = M + D
    D = M
    @key
    M = D

    // int i = 0;
    @i
    M = 0
    
    // FOR:
    (FOR)
        // if (i >= size) goto END_FOR
        @size
        D = M
        @i
        D = M - D
        @END_FOR
        D;JGE

        // IF:
        (IF)
            // if (AXORB(arr[i], key) != 0) goto SKIP_IF

            // push arr[i]
            @i
            D = M
            @arr
            A = M + D
            D = M
            @SP
            AM = M - 1
            M = D

            // push key
            @key
            D = M
            @SP
            AM = M - 1
            M = D

            // push RET
            @RET
            D = A
            @SP
            AM = M - 1
            D = M

            // goto AXORB
            @AXORB
            0;JMP

            (RET)
                // if (AXORB(arr[i], key) != 0) goto SKIP_IF
                @SKIP_IF
                D;JNE

            // return 1;
            D = 1
            @SP
            A = M
            A = M
            0;JMP

        // SKIP_IF:
        (SKIP_IF)
            // i = i + 1;
            @i
            M = M + 1

            // goto FOR
            @FOR
            0;JMP

    // END_FOR:
    (END_FOR)
        // return 0;
        D = 0
        @SP
        A = M
        A = M
        0;JMP
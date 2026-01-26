// REMAINDER:
(REMAINDER)
    // x = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @x
    M = D

    // y = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @y
    M = D

    // WHILE:
    (WHILE)
        // if (y < x) goto END_WHILE
        @x
        D = M
        @y
        D = M - D
        @END_WHILE
        D;JLT

        // x = x - y;
        @y
        D = M
        @x
        M = M - D

        // goto WHILE
        @WHILE
        0;JMP

    // END_WHILE:
    (END_WHILE)
        // D = x;
        @x
        D = M

        // goto *(SP)
        @SP
        A = M
        A = M
        0;JMP
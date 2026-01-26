// MAXINARR:
(MAXINARR)
    // arr1 = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @arr1
    M = D

    // size1 = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @size1
    M = D

    // int i = 0;
    @i
    M = 0

    // int curMax = -32767
    @32767
    D = -A
    @curMax
    M = D

    // int maxIndex
    @maxIndex
    M = 0

    // FOR:
    (FOR)
        // if (i >= size1) goto END_FOR
        @size1
        D = M
        @i
        D = M - D
        @END_FOR
        D;JGE

        // IF:
        (IF)
            // if (arr1[i] <= curMax) goto SKIP_IF
            // arr1[i] = arr1i
            @i
            D = M
            @arr1
            A = M + D
            D = M
            @arr1i
            M = D

            @curMax
            D = M
            @arr1i
            D = M - D
            @SKIP_IF
            D;JLE

            // curMax = arr1[i];
            @i
            D = M
            @arr1
            A = M + D
            D = M
            @curMax
            M = D

            // maxIndex = i;
            @i
            D = M
            @maxIndex
            M = D

            // SKIP_IF:
            (SKIP_IF)
                // i++
                @i
                M = M + 1

                // goto FOR
                @FOR
                0;JMP
    
    // END_FOR:
    (END_FOR)
        // D = maxIndex
        @maxIndex
        D = M

        // goto *(SP)
        @SP
        A = M
        A = M
        0;JMP


//     size = *(SP + 2);

//     FOR1:
//         if (i >= size) goto END_FOR1
//         i = 0;

//         FOR2:
//             if (i >= numArr[j]) goto END_FOR2
//             if (i*i != numArr[j]) goto SKIP_IF
//             count = count + 1;

//             SKIP_IF:
//                 i = i + 1;
//                 goto FOR2
        
//         END_FOR2:
//             j = j + 1;
//             goto FOR1
    
//     END_FOR1:
//         D = count;
//         goto *(SP)


// COUNT_SQUARE:
(COUNT_SQUARE)
    // int count = 0, j = 0;
    @count
    M = 0
    @j
    M = 0

    // numArr = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @numArr
    M = D

    // size = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @numArr
    M = D

    // FOR1:
    (FOR1)
        // if (j >= size) goto END_FOR1
        @size
        D = M
        @j
        D = M - D
        @END_FOR1
        D;JGE

        // i = 0;
        @i
        M = 0

        // FOR2:
        (FOR2)
            // if (i >= numArr[j]) goto END_FOR2
            @j
            D = M
            @numArr
            A = M + D
            D = M
            @i
            D = M - D
            @END_FOR2
            D;JGE

            // if (i*i != numArr[j]) goto SKIP_IF
            // push i
            @i
            D = M
            @SP
            AM = M - 1
            M = D
            //push return address
            @RET
            D = M
            @SP
            AM = M - 1
            M = D
            @MULTSELF
            0;JMP

            (RET)
                @retI
                M = D
                // actual SKIP_IF condition here VVV
                @j
                D = M
                @numArr
                A = M + D
                D = M
                @retI
                D = M - D
                @SKIP_IF
                D;JNE

                // count = count + 1;
                @count
                M = M + 1

            // SKIP_IF
            (SKIP_IF)
                @i
                M = M + 1
                @FOR2
                0;JMP
        
        // END_FOR2:
        (END_FOR2)
            @j
            M = M + 1
            @FOR1
            0;JMP
    
    // END_FOR1:
    (END_FOR1)
        // D = count;
        @count
        D = M

        // goto *(SP)
        @SP
        A = M
        A = M
        0;JMP
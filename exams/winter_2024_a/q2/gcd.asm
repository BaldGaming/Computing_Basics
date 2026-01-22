//     WHILE:
//         if (n2 == 0) goto END_WHILE
//         temp = n2;
//         push(n1);
//         push(n2);
//         push(@RET)
//         goto modulo;

//     RET:
//         n2 = D;
//         SP = SP + 2;
//         n1 = temp;
//         goto WHILE;

//     END_WHILE:
//         D = n1;
//         goto *(SP);



// GCD:
(GCD)
    // numArr = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @numArr
    M = D

    // if (arr[0] > arr[1]) goto ELSE
    @numArr
    A = M
    D = M
    A = A + 1
    D = D - M
    @ELSE
    D;JLT

    // n1 = numArr[1];
    @numArr
    A = M + 1
    D = M
    @n1
    M = D

    // n2 = numArr[0];
    @numArr
    A = M
    D = M
    @n2
    M = D

    // goto WHILE;
    @WHILE
    0;JMP

    (ELSE)
        // n1 = numArr[0];
        @numArr
        A = M
        D = M
        @n1
        M = D

        // n2 = numArr[1];
        @numArr
        A = M + 1
        D = M
        @n2
        M = D
    
    // WHILE;
    (WHILE)
        // if (n2 == 0) goto END_WHILE
        @n2
        D = M
        @END_WHILE
        D;JEQ

        // temp = n2;
        @n2
        D = M
        @temp
        M = D

        // push(n1);
        @n1
        D = M
        @SP
        AM = M - 1
        M = D

        // push(n2);
        @n2
        D = M
        @SP
        AM = M - 1
        M = D

        // push(@RET);
        @RET
        D = M
        @SP
        AM = M - 1
        M = D

        // goto modulo;
        @modulo
        0;JMP

        // RET:
        (RET)
            // n2 = D;
            @n2
            M = D

            // SP = SP + 2
            @2
            D = A
            @SP
            M = M + D

            // n1 = temp;
            @temp
            D = M
            @n1
            M = D

            @WHILE
            0;JMP
    
    // END_WHILE
    (END_WHILE)
        // D = n1;
        @n1
        D = M

        // goto *(SP);
        @SP
        A = M
        A = M
        0;JMP
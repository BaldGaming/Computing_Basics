
//     
//     
//     
//     

//     ;


    



        
//         END_FOR2:
//             goto *(SP)


// SUMSAMEREM:
(SUMSAMEREM)
    // arr = (int*)*(SP + 1);
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

    // result = (int*)*(SP + 3);
    @3
    D = A
    @SP
    A = M + D
    D = M
    @result
    M = D

    // num = *(SP + 4);
    @4
    D = A
    @SP
    A = M + D
    D = M
    @num
    M = D

    // int i = 0
    @i
    M = 0

    // FOR1:
    (FOR1)
        // if (i >= size) goto END_FOR1
        @size
        D = M
        @i
        D = M - D
        @END_FOR1
        D;JGE

        // result[i] = 0;
        @i
        D = M
        @result
        A = D
        M = D

        // i = i + 1
        @i
        M = M + 1

    // END_FOR1
    (END_FOR1)
        // i = 0
        M = 0

        // FOR2
        (FOR2)
            // if (i >= size) goto END_FOR2
            @size
            D = M
            @i
            D = M - D
            @END_FOR2
            D;JGE

            // int arrI = arr[i];
            @i
            D = M
            @arrI
            A = D
            D = M
            @arrI
            M = D

            //push(num);
	        @num
	        D = M
	        @SP
	        M = M - 1
	        A = M
	        M = D

            //push(*arr);
	        @arr
	        A = M
	        D = M
	        @SP
	        M = M - 1
	        A = M
	        M = D

            //push(RET);
	        @RET
	        D = A
	        @SP
	        M = M - 1
	        A = M
	        M = D

            //goto REMAINDER
	        @REMAINDER
	        0;JMP

            // RET:
            (RET)
                // REM = D;
                @REM
                M = D

                // SP = SP + 3;
                @3
                D = A
                @SP
                M = M + D




//             RET:
//                 REM = D;
//                 SP = SP + 3;
//                 result[rem] = result[rem] + arrI;
//                 goto FOR2
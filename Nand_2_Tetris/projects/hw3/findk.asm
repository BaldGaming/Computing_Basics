// SP setup
@SCREEN
D = A
@SP
M = D

// Stack setup
@50
D = A
@R1
M = D

// Push R3
@R3
D = M
@SP
AM = M - 1
M = D

// Push R2
@R2
D = M
@SP
AM = M - 1
M = D

// Push R1
@R1
D = M
@SP
AM = M - 1
M = D

// Push RET1 (returns here at the end)
@RET1
D = A
@SP
AM = M - 1
M = D

// Jumps to the FINDKTH function
@FINDKTH
0;JMP

(RET)

    // Puts the result into R4
    @R4
    M = D

    // Empty stack
    @4
    D = A
    @SP
    M = D + M

    // Ends the program
    @END
    0;JMP


// FINDABOVECOUNT:
//     int counter = 0;
//     int j = 0;
//
//     int size_f = *(SP + 2);
//     int arr_f = *(SP + 3);
//     int num_f = *(SP + 4);
// 
//     WHILE2:
//         if (j - size_f >= 0) goto FIND_END;
// 
//         int current_addr = arr_f + j;   (Calculates the address of the current element)
//         int current_val = *current_addr; (Reads the RAM at said address)
// 
//         if (current_val - num_f <= 0) goto INC_J;
//         counter = counter + 1;
// 
//     INC_J:
//         j = j + 1;
//         goto WHILE2;
// 
//     FIND_END:
//         D = Counter;
//         goto *(SP + 1);
// 
// END:
//     goto END;


(FINDABOVECOUNT)
    // int counter and j
    @counter
    M = 0
    @j
    M = 0

    // int size_f
    @3
    D = A
    @SP
    A = M + D
    D = M
    @size_f
    M = D

    // int arr_f
    @2
    D = A
    @SP
    A = M + D
    D = M
    @arr_f
    M = D

    // int num_f
    @1
    D = A
    @SP
    A = M + D
    D = M
    @num_f
    M = D

    // While loop
    (WHILE2)

        // if (j - size_f >= 0) break
        @size_f
        D = M
        @j
        D = M - D
        @FIND_END
        D;JGE

        @j
        D = M
        @arr_f
        D = M + D
        @current_addr
        M = D // saves pointer to specific element

        A = M
        D = M
        @current_val // holds said element
        M = D

        // if (current_val - num_f <= 0) skip increment
        @num_f
        D = M
        @current_val
        D = M - D
        @INC_J
        D;JLE // current_val - num_f <= 0 check

        @counter
        M = M + 1 // counter increment

    // j++
    (INC_J)
        @j
        M = M + 1
        @WHILE2
        0;JMP // goes back to the while

    // end of function -> goes back to FINDKTH
    (FIND_END)
        @counter
        D = M
        @SP
        A = M
        A = M
        0;JMP

// endless loop
(END)
    @END
    0;JMP
// Adjusted code:
//
// SP = SCREEN;
// int R1 = 7; (arr address)
// int R2 = 6; (arr length)
// int R3 = 3; (Kth largest)

// push(R3); (arg3: k)
// push(R2); (arg2: size)
// push(R1); (arg1: arr)
// push(&RET); (return address)
// goto FINDKTH;

// RET:
//     int R4 = D; (Saves result to R4)
//     SP = SP + 4; (Clears stack)
//     goto END;

// Initialize Stack Pointer to SCREEN address
@SCREEN
D = A
@SP
M = D

// Initialize R1 with Array Address (7)
@7
D = A
@R1
M = D

// Initialize R2 with Array Size (6)
@6
D = A
@R2
M = D

// Initialize R3 with K value (3)
@3
D = A
@R3
M = D

// Push R3 (k) onto the stack
@R3
D = M
@SP
AM = M - 1
M = D

// Push R2 (size) onto the stack
@R2
D = M
@SP
AM = M - 1
M = D

// Push R1 (array pointer) onto the stack
@R1
D = M
@SP
AM = M - 1
M = D

// Push Return Address (RET) onto the stack
@RET
D = A
@SP
AM = M - 1
M = D

// Call Function: Jump to FINDKTH
@FINDKTH
0;JMP

// Return Label: Main program resumes here
(RET)

    // Store the result (D) into R4
    @R4
    M = D

    // Clean up the stack (Pop 4 arguments)
    @4
    D = A
    @SP
    M = D + M

    // Jump to Infinite Loop (End of Program)
    @END
    0;JMP


// FINDKTH:
//     int flag = 1;
//     int i = 0;
// 
//     int k = *(SP + 3);
//     int size = *(SP + 2)
//     int pos = *(SP + 1);
//     
//     WHILE1:
//         if (i - size >= 0) goto RET; (stops the loop and returns to main)
//
//         push(size); (pushes size for FINDABOVE)
//         push(pos); (pushes array pointer for FINDABOVE)
//         push(*(pos + i)); (pushes VALUE of array[i])
//         push(&RET_LOOP);
//         goto FINDABOVECOUNT
//
//         RET_LOOP:
//         flag = D; (result from function)
//         SP = SP + 4; (clean stack)
//         i = i + 1
//         
//         if (flag - (k - 1) != 0) goto WHILE1;
//
//     FINDK_END:
//         D = *(pos + i - 1)
//         goto *SP;

(FINDKTH)

    // Initialize flag = 1
    @flag
    M = 1

    // Initialize i = 0
    @i
    M = 0

    // Load Argument: k (from SP + 3)
    @3
    D = A
    @SP
    A = M + D
    D = M
    @k
    M = D

    // Load Argument: size (from SP + 2)
    @2
    D = A
    @SP
    A = M + D
    D = M
    @size
    M = D

    // Load Argument: pos (array pointer from SP + 1)
    @SP
    A = M + 1
    D = M
    @pos
    M = D

    // Start of Outer Loop
    (WHILE1)

        // Check Loop Condition: if (i >= size) goto RET
        @size
        D = M
        @i
        D = M - D
        @RET
        D;JGE

        // Prepare Call: Push size argument
        @size
        D = M
        @SP
        AM = M - 1
        M = D

        // Prepare Call: Push pos (array ptr) argument
        @pos
        D = M
        @SP
        AM = M - 1
        M = D

        // Prepare Call: Calculate & Push value of arr[i]
        @pos
        D = M
        @i
        D = M + D
        A = D
        D = M
        @SP
        AM = M - 1
        M = D

        // Prepare Call: Push Return Address (RET_LOOP)
        @RET_LOOP
        D = A
        @SP
        AM = M - 1
        M = D

        // Jump to Function: FINDABOVECOUNT
        @FINDABOVECOUNT
        0;JMP

        // Return Point from FINDABOVECOUNT
        (RET_LOOP)

        // Store Result: flag = Returned Value (D)
        @flag
        M = D

        // Clean Stack: Pop 4 arguments
        @4
        D = A
        @SP
        M = D + M

        // Increment Loop Counter: i++
        @i
        M = M + 1

        // Check Match: if (flag != k - 1) continue loop
        @k
        D = M
        D = D - 1
        @flag
        D = M - D
        @WHILE1
        D;JNE

    // Result Found Block
    (FINDK_END)

        // Retrieve Logic: D = arr[i - 1]
        @i
        D = M - 1
        @pos
        D = D + M
        A = D
        D = M

        // Return from FINDKTH: Jump to Address at *SP
        @SP
        A = M
        A = M
        0;JMP

// FINDABOVECOUNT:
//     int counter = 0;
//     int j = 0;
//
//     int size_f = *(SP + 3);
//     int arr_f = *(SP + 2);
//     int num_f = *(SP + 1);
// 
//     WHILE2:
//         if (j - size_f >= 0) goto FIND_END;
// 
//         if (arr[j] - num_f <= 0) goto INC_J;
//         counter = counter + 1;
// 
//     INC_J:
//         j = j + 1;
//         goto WHILE2;
// 
//     FIND_END:
//         D = counter;
//         goto *SP;
// 
// END:
//     goto END;


(FINDABOVECOUNT)
    
    // Initialize local vars: counter = 0, j = 0
    @counter
    M = 0
    @j
    M = 0

    // Load Argument: size_f (from SP + 3)
    @3
    D = A
    @SP
    A = M + D
    D = M
    @size_f
    M = D

    // Load Argument: arr_f (from SP + 2)
    @2
    D = A
    @SP
    A = M + D
    D = M
    @arr_f
    M = D

    // Load Argument: num_f (from SP + 1)
    @1
    D = A
    @SP
    A = M + D
    D = M
    @num_f
    M = D

    // Start of Inner Loop
    (WHILE2)

        // Check Loop Condition: if (j >= size_f) goto FIND_END
        @size_f
        D = M
        @j
        D = M - D
        @FIND_END
        D;JGE

        // Logic Check: if (num_f >= arr[j]) skip increment
        @arr_f
        D = M
        @j
        A = M + D
        D = M
        @num_f
        D = D - M
        @INC_J
        D;JLE

        // Increment Counter: Found larger element
        @counter
        M = M + 1

    // Loop Increment Block
    (INC_J)

        // j++
        @j
        M = M + 1

        // Jump back to start of loop
        @WHILE2
        0;JMP // goes back to the while

    // Return from FINDABOVECOUNT
    (FIND_END)

        // Set Return Value: D = counter
        @counter
        D = M

        // Jump to Return Address at *SP
        @SP
        A = M
        A = M
        0;JMP

// Infinite Loop (Program End)
(END)
    @END
    0;JMP
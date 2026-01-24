// push size = 7
@7
D = A
@SP
AM = M - 1
M = D

// push arrNum
@arrNum
D = M
@SP
AM = M - 1
M = D

// push funcRET
@funcRET
D = A
@SP
AM = M - 1
M = D

// call to function
@COUNT_SQUARE
0;JMP

(funcRET)
    // puts result into count
    @count
    M = D

    // cleans stack
    @3
    D = A
    @SP
    M = M + D
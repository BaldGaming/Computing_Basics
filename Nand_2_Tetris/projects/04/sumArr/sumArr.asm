// variables
@R0
M = 0 // sets R0 to be 0
@i
M = 0 // sets i to be 0

@R1
D = M
@target
M = D // sets pointer "target" to point at R1



(WHILE)
    // while exit check
    @i
    D = M
    @R2
    D = D - M
    @END
    D;JGE

    // get array value
    @target
    A = M
    D = M

    @1
    D = D & A // if (value & 1) == 0

    @SKIP
    D;JGT // skips the sum if the check is false

    // get array value
    @target
    A = M
    D = M

    // preforms sum
    @R0
    M = D + M

(SKIP)
    @target
    M = M + 1 // pointer++

    @i
    M = M + 1 // i++

    @WHILE
    0;JMP

(END)
    @END
    0;JMP


// int i = 0
// int sum = 0 (R0)
// *prt = R1

// WHILE:
//  int value = *ptr (value from pointer target)
//  if (value & 1) == 0 -> sum = sum + value (does addition if the number is even)
//  ptr++ (moves the pointer by 1)
//  i++ increments the i

// END:
// goto END
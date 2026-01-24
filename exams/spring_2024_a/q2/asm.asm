// push arr
@arr
D = M
@SP
AM=M-1
M=D

// push n
@n
D = M
@SP
AM=M-1
M=D

// push ret
@RET
D = M
@SP
AM=M-1
M=D

// call to function
@COMPUTE_DIVISORS
0;JMP

// ret
(RET)
    // return value gets put into k
    @k
    M = D

    // clear stack
    @3
    D = A
    @SP
    M = M + D

(END)
    goto END

(COMPUTE_DIVISORS)
    // n = *(SP + 1)
    @SP
    A = M + 1
    D = M
    @n
    M = D

    // arrptr = *(SP + 2)
    @2
    D = A
    @SP
    A = M + D
    D = M
    @arrptr
    M = D

    // *arrptr = 1
    @arrptr
    A = M
    M = 1

    // arrptr++;
    @arrptr
    M = M + 1

    // k = 1, i = 2
    @k
    M = 1
    @2
    D = A
    @i
    M = A

(WHILE1)
    // if (!(i < n)) goto SKIP_WHILE1
    @n
    D = M
    @i
    D = M - D
    @SKIP_WHILE1
    D;JGE

    // sum = i
    @i
    D = M
    @sum
    M = D

(WHILE2)
    // if (!(sum < n)) goto SKIP_WHILE2
    @n
    D = M
    @sum
    D = M - D
    @SKIP_WHILE2
    D;JGE
    
    // sum = sum + i
    @i
    D = M
    @sum
    M = D + M
    
    // goto WHILE2
    @WHILE2
    0;JMP

(SKIP_WHILE2)
    // if (sum != n) goto SKIP_IF
    @n
    D = M
    @sum
    D = M - D
    @SKIP_IF
    D;JNE

    // *arrptr = i
    @i
    D = M
    @arrptr
    A = M
    M = D

    // arrptr++
    M = M + 1

    // k++
    @k
    M = M + 1

(SKIP_IF)
    // i++
    @i
    M = M + 1

    // goto WHILE1
    @WHILE1
    0;JMP

(SKIP_WHILE1)
    // *arrptr = n
    @n
    D = M
    @arrptr
    A = M
    M = D

    // k++
    @k
    M = M + 1

    // D = k
    D = M

    //goto *SP
    @SP
    A = M
    A = M
    0;JMP
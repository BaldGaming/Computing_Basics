//initializing SP (address 0)
@SCREEN
D=A
@SP
M=D

//push(&R4);
@R4
D=A
@SP
M=M-1
A=M
M=D

//push(&R3);
@R3
D=A
@SP
M=M-1
A=M
M=D

//push(R2);
@R2
D=M
@SP
M=M-1
A=M
M=D

//push(R1);
@R1
D=M
@SP
M=M-1
A=M
M=D

//push(&RET1);
@RET1
D=A
@SP
M=M-1
A=M
M=D

//goto DIVMOD;
@DIVMOD_ADDRESS
0;JMP

(RET1)

//int flag1 = D;
@R5
M = D

//SP+=5 clears the 5 arguments;
@5
D=A
@SP
M=D+M

@END_DIVMOD
0;JMP

(DIVMOD_ADDRESS)

    //x  = *(SP+1); 
    @1
    D=A
    @SP
    A=D+M
    D=M
    @x
    M=D

    //y = *(SP+2);
    @2
    D=A
    @SP
    A=D+M
    D=M
    @y
    M=D

    // resptr = *(SP+3)
    @3
    D=A
    @SP
    A=D+M
    D=M
    @resptr
    M=D

    // modptr = *(SP+4)
    @4
    D=A
    @SP
    A=D+M
    D=M
    @modptr
    M=D

    // if(y==0) goto END_DIVMOD;
    @y
    D = M
    @ZERO
    D;JEQ

    // *resptr = 0
    @resptr
    A = M    
    M = 0

    //resptr  = *(SP+3); 
    @3
    D=A
    @SP
    A=D+M
    D=M
    @resptr
    M=D

    //modptr = *(SP+4);
    @4
    D=A
    @SP
    A=D+M
    D=M
    @modptr
    M=D

// Loop for subtraction
(WHILE1)
    //R1 - R2 >= 0 stopping condition for the subtraction loop
    @y
    D = M
    @x
    D = M - D

    // If (x - y < 0) goto END_WHILE1
    @END_WHILE1
    D;JLT

    // Update R1 with R1 - R2
    @x
    M = D

    // Update *resptr (*resptr++)
    @resptr
    A = M
    M = M + 1      // R3++

    @WHILE1
    0;JMP

(END_WHILE1)

    // update *modptr
    @x
    D = M
    @modptr
    A = M
    M = D

    // Success: Return 1
    D = 1
    @RETURN
    0;JMP

    (ZERO)
    // Failure: Return 0
    D = 0
    @RETURN
    0;JEQ

(RETURN)
    // returns to *SP
    @SP
    A = M
    A = M
    0;JMP

(END_DIVMOD)
    @END_DIVMOD
    0;JMP
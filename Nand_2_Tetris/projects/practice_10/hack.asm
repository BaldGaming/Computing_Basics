// 1. label ABC
(ABC)


// 2. pop local 3
@3
D = A
@LCL
D = M + D

@R13
M=D

@SP
AM=M-1
D=M

@R13
A=M
M=D


// 3. if-goto ABC
@SP
AM = M - 1
D = M

@ABC
D;JNE


// 4. and
@SP
AM = M - 1
D = M
A = A - 1
M = D&M
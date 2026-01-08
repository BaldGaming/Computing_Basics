// call f.funcy 3

// return address
@returnLabel
D = A
@SP
A = M
M = D
@SP
M = M + 1

// Push LCL
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1

// Push ARG
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1

// Push THIS
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1

// Push THAT
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1

// ARG (ARG = SP - n - 5)
@SP
D = M
@8
D = D - A
@ARG
M = D

// Reposition LCL (LCL = SP)
@SP
D = M
@LCL
M = D

// goto f.funcy
@f.funcy
0;JMP

(returnLabel)
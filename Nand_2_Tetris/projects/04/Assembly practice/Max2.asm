// Creates D = R1 - R2
@R2
D = M
@R1
D = M - D

// Checks if D<0, sends it to ELSE if true
@ELSE
D;JLT

// Does R0 = R1
@R1
D = M
@R0
M = D
@END
0;JMP

// Does R0 = R2
(ELSE)
@R2
D = M
@R0
M = D

// END loop
(END)
@END
0;JMP
// RAM[15] = RAM[0] + RAM[1] + 9

@9
D = A
@z
D = M + D
@y
D = M + D
@x // starts from RAM[16]
M = D

(END)
@END
0;JMP
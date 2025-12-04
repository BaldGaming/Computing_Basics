// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// Assumes that R0 >= 0, R1 >= 0, and R0 * R1 < 32768.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// RAM[2] = 0
@R2
M = 0

// int i = 0
@i
M = 0

(LOOP)
    // if check
    @i
    D = M
    @R0
    D = D - M
    @END
    D;JGE

    // loop content
    @R1
    D = M
    @R2
    M = D + M

    // i++
    @i
    M = M + 1

    // loop back
    @LOOP
    0;JMP

(END)
    @END
    0;JMP
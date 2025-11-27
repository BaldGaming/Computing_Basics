// Variables
@cur
M = 0
@prev
M = 0
@counter
M = 0

(WHILE)
// cur = KBD;
@KBD
D=M
@cur
M=D

// if(cur > prev)
@cur
D=M
@prev
A=M
D=D-A     // D = cur - prev

@SET_PREV
D;JLE     // Jumps if cur <= prev (D <= 0)

// counter++;
@counter
M=M+1
(SET_PREV)

// prev = cur;
@cur
D=M
@prev
M=D

// End of loop, jump back to WHILE
@WHILE
0;JMP
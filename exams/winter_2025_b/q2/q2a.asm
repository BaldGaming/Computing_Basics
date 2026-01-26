// AXORB:
(AXORB)
    // a = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @a
    M = D

    // b = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @b
    M = D

    // c = (!a & b);
    @a
    D = !M
    @b
    D = D&M
    @c
    M = D

    // d = (a & !b);
    @b
    D = !M
    @a
    D = D&M
    @d
    M = D

    // D = c | d;
    @c
    D = M
    @d
    D = M | D

    // goto *(SP)
    @SP
    A = M
    A = M
    0;JMP
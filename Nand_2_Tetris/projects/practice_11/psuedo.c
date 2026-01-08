void main() {
    static int q = calcQuotient(988,21);
}

int calcQuotient(x,y) {
    int q=0, rem, v=x-y;
    while(v >= 0) {
        q++;
        v = v - y;
    }
    return q;
}

// ##################################;
// Adjusted code:

// void main() {
//     static int q;
//     q = calcQuotient(98, 21);
// END:
//     goto END;
// }

// int calcQuotient(x, y) {
//     int q, v;
//     q = 0
//     v = x - y

// WHILE_LOOP:
//     if(v < 0) goto END_LOOP;
//     q = q + 1;
//     v = v - y
//     goto WHILE_LOOP;

// END_LOOP:
//     return q;
// }
// ##################################;

// x = 988;
push constant 988
pop static 0

// y = 21;
push constant 21
pop static 1

// q = 0;
push constant 0
pop static 2

// v = x - y;
push static 0
push static 1
sub
pop static 3

// while loop;
label WHILE_LOOP

    // exit condition;
    push static 3
    push constant 0
    lt
    if-goto END_WHILE_LOOP

    // q = q + 1
    push static 2
    push constant 1
    add
    pop static 2

    // v = v - y;
    push static 3
    push static 1
    sub
    pop static 3

    // goto WHILE_LOOP;
    goto WHILE_LOOP

label END_WHILE_LOOP

    // rem = v + y;
    push static 3
    push static 1
    add
    pop static 4

    goto END

label END
    goto END
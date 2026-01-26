#include <stdio.h>

int AXORB(int a, int b);

int main()
{
    int a = 26, b = 17;

    printf("result of encryption: %d", AXORB(a, b));
}

int AXORB(int a, int b)
{
    return (~a & b) | (a & ~b);
}

// AXORB:
//     a = *(SP + 1);
//     b = *(SP + 2);
//     c = (!a & b);
//     d = (a & !b);
//     D = c | d;
//     goto *(SP)
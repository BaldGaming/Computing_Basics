#include <stdio.h>

int remainder(int x, int y);

int main()
{
    int x = 17, y = 5;
    printf("The remainder of %d and %d is: %d.", x, y, remainder(x, y));
}

int remainder(int x, int y)
{
    while(y <= x)
    {
        x = x - y;
    }
    return x;
}


// REMAINDER:
//     x = *(SP + 1);
//     y = *(SP + 2);

//     WHILE:
//         if (y < x) goto END_WHILE
//         x = x - y;
//         goto WHILE

//     END_WHILE:
//         D = x;
//         goto *(SP)
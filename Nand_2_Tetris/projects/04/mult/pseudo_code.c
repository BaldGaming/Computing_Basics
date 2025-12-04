#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
    int R0=6;
    int R1=7;
    int R2=0;
    int i=0;

    for (i; i<R0; i++)
        R2 = R2 + R1;
    return 0;
}

// int R0 = 6 !
// int R1 = 7 !
// int R2 = 0
// int i = 0

// LOOP:
//  if (i - R0 >= 0) goto END
//  R2 = R2 + R1
//  i++
// goto LOOP

// END:
//  goto END
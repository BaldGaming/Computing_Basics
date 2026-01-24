#include <stdio.h>
#define N 3

int SumOfSquares(int n);

int main()
{
    printf("The sum of squares in n = %d is: %d.", N, SumOfSquares(N));
}

int SumOfSquares(int n)
{
    if (n == 0)
        return 0;
    return n*n + SumOfSquares(n - 1);
}



// SUMOFSQUARES:
//     if (n != 0) goto SKIP_IF
//     return 0

//     SKIP_IF:
//         int sum = 0, i = 0

//         FOR_START:
//             if (!(i < n)) goto END_FOR
// 	        sum += n
// 	        i++
// 	        goto FOR_START

//         END_FOR:
//         	return sum + SumOfSquaresAdjusted(n - 1)


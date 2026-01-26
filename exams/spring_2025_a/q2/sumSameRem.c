#include <stdio.h>

int remainder(int x, int y);
void sumSameRem(int arr[], int size, int result[], int num);

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

void sumSameRem(int arr[], int size, int result[], int num)
{
    int i = 0;

    for (i; i < size; i++)
        result[i] = 0;

    for (i = 0, i < size; i++)
    {
        int arrI = arr[i];
        int rem = reminder(arrI, num);
		result[rem] = result[rem] + arrI;
    }
}

// SUMSAMEREM:
//     arr = (int*)*(SP + 1);
//     size = *(SP + 2);
//     result = (int*)*(SP + 3);
//     num = *(SP + 4);

//     int i = 0;

//     FOR1:
//         if (i >= size) goto END_FOR1
//         result[i] = 0;
//         i = i + 1;
    
//     END_FOR1:
//         i = 0;
//         FOR2:
//             if (i >= size) goto END_FOR2
//             int arrI = arr[i];
//             push(num);
//             push (arrI);
//             push(RET);
//             goto REMAINDER

//             RET:
//                 REM = D;
//                 SP = SP + 3;
//                 result[rem] = result[rem] + arrI;
//                 goto FOR2
        
//         END_FOR2:
//             goto *(SP)

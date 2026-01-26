#include <stdio.h>

int arrCount(int *arr, int arrLength);

int main()
{
    int arr[] = {4, 10, 4, 2, 2, 2, 5, 9, 5};
    int length = 9;

    printf("%d", arrCount(arr, length));
}

int arrCount(int *arr, int arrLength)
{
    int counter = 0;
    int firstDerivative, secondDerivative;
    for (int i = 1; i < arrLength - 1; i++)
    {
        firstDerivative = arr[i + 1] - arr[i - 1];

        secondDerivative = arr[i + 1] - 2 * arr[i] + arr[i - 1];
        
        if (firstDerivative == 0 && secondDerivative < 0)
            counter++;
    }
    return counter;
}


// ARRCOUNT:
//     arr = (int*)*(SP + 1);
//     arrLength = (SP + 2);
//     int counter = 0;
//     int i = 1;

//     FOR:
//         if (i >= arrLength) goto END_FOR

//         firstDerivative = arr[i + 1] - arr[i - 1];

//         secondDerivative = arr[i + 1] - 2 * arr[i] + arr[i - 1];

//         IF:
//             if (firstDerivative != 0) goto SKIP_IF
//             if (secondDerivative >= 0) goto SKIP_IF
//             counter = counter + 1;
        
//         SKIP_IF:
//             i = i + 1;
//             goto FOR
    
//     END_FOR:
//         D = arrCountRetAdd;
//         goto *(SP)
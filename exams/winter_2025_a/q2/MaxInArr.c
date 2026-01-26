#include <stdio.h>

int MaxInArr(int arr1[], int size1);

int main()
{
    int arr[] = {3, 7, -1, 7, 0};
    int size = 5;

    printf("%d", MaxInArr(arr, size));
}

int MaxInArr(int arr1[], int size1)
{
    int i = 0;
    int curMax = -999999;
    int maxIndex = 0;

    for (i; i < size1; i++)
    {
        if (arr1[i] > curMax)
            {
                curMax = arr1[i];
                maxIndex = i;
            }
    }
    return maxIndex;
}

// MAXINARR:
//     arr1 = *(SP + 1);
//     size1 = *(SP + 2);

//     int i = 0;
//     int curMax = -999999;
//     int maxIndex = 0;

//     FOR:
//         if (i >= size1) goto END_FOR

//         IF:
//             if (arr1[i] <= curMax) goto SKIP_IF
//             curMax = arr1[i];
//             maxIndex = i;
        
//         SKIP_IF:
//             goto FOR
    
//     END_FOR:
//         D = maxIndex
//         goto *(SP)
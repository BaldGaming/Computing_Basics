#include <stdio.h>
#define SIZE 5

int count_square(int numArr[], int size);
int multself(int i);

int main()
{
    int arr[SIZE] = {6, 4, 11, -33, 9};

    printf("There are %d numbers with whole square roots in the array.", count_square(arr, SIZE));
}

int count_square(int numArr[], int size)
{
    int count = 0, j = 0, i;

    for (j; j < size; j++)
    {
        i = 0;
        for (i; i < numArr[j]; i++)
        {
            if (multself(i) == numArr[j])
                count++;
        }
    }
    return count;
}

int multself(int i)
{
    return i*i;
}



// COUNT_SQUARE:
//     int count = 0, j = 0, i;
//     numArr = *(SP + 1);
//     size = *(SP + 2);

//     FOR1:
//         if (j >= size) goto END_FOR1
//         i = 0;

//         FOR2:
//             if (i >= numArr[j]) goto END_FOR2
//             if (i*i != numArr[j]) goto SKIP_IF
//             count = count + 1;

//             SKIP_IF:
//                 i = i + 1;
//                 goto FOR2
        
//         END_FOR2:
//             j = j + 1;
//             goto FOR1
    
//     END_FOR1:
//         D = count;
//         goto *(SP)
#include <stdio.h>
#define SIZE 9

int findAboveCount(int num, int* arr, int size);
int findKth(int* arr, int size, int k);

int main()
{
    int array[SIZE] = {7, 6, 3, 11, 22, 33, 55, 44, 100};
    int res = 0;

    res = findKth(array, SIZE, 3);

    printf("The largest 3rd element is %d", res);
    return 0;
}

// Adjusted code:
// SP = SCREEN;
// int R1 = 50; (arr address)
// int R2 = 9; (arr length)
// int R3 = 3; (Kth largest)

// push(R3); (arg3: k)
// push(R2); (arg2: size)
// push(R1); (arg1: arr)
// push(&RET1); (return address)
// goto FINDKTH;

// RET:
//     int R4 = D; (Saves result to R4)
//     SP = SP - 4; (Empties stack)
//     goto END;

int findKth(int* arr, int size, int k)
{
    int counted;
    int i = 0;

    while (i < size)
    {
        counted = findAboveCount(arr[i], arr, size);

        if (counted == k - 1)
            return arr[i];

        i = i + 1;
    }

    return arr[i];
}

// FINDKTH:
//     int counted = 0;
//     int i = 0;
// 
//     int k = *(SP - 4);
//     int size = *(SP - 3)
//     int arr_ptr = *(SP - 2);
//     
//     WHILE1:
//         if (i - size >= 0) goto RET; (stops the loop and returns to main)
//         push(size); (pushes size for FINDKTH)
//         push(arr_ptr); (pushes array pointer for FINDKTH)
// 
// 
//         push(val)
//
//         push(&RET_LOOP);
//         goto FINDABOVE
//

int findAboveCount(int num, int* arr, int size)
{

    int counter = 0;
    int j = 0;

    while (j < size)
    {
        if (arr[j] > num)
            counter = counter + 1;

        j = j + 1;
    }

    return counter;
}
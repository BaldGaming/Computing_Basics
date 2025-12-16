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
//
// SP = SCREEN;
// int R1 = 7; (arr address)
// int R2 = 6; (arr length)
// int R3 = 3; (Kth largest)

// push(R3); (arg3: k)
// push(R2); (arg2: size)
// push(R1); (arg1: arr)
// push(&RET); (return address)
// goto FINDKTH;

// RET:
//     int R4 = D; (Saves result to R4)
//     SP = SP + 4; (Clears stack)
//     goto END;

int findKth(int* arr, int size, int k)
{
    int flag = 1;
    int i = 0;
    int* pos = arr;

    while (1) 
    {
        if (i - size >= 0)
            break;

        flag = findAboveCount(arr[i], arr, size);
            
        i = i + 1;
            
        if (flag == k - 1) 
            break; 
    }

    return arr[i - 1];
}

// FINDKTH:
//     int flag = 1;
//     int i = 0;
// 
//     int k = *(SP + 3);
//     int size = *(SP + 2)
//     int pos = *(SP + 1);
//     
//     WHILE1:
//         if (i - size >= 0) goto RET; (stops the loop and returns to main)
//
//         push(size); (pushes size for FINDABOVE)
//         push(pos); (pushes array pointer for FINDABOVE)
//         push(*(pos + i)); (pushes VALUE of array[i])
//         push(&RET_LOOP);
//         goto FINDABOVECOUNT
//
//         RET_LOOP:
//         flag = D; (result from function)
//         SP = SP + 4; (clean stack)
//         i = i + 1
//         
//         if (flag - (k - 1) != 0) goto WHILE1;
//
//     FINDK_END:
//         D = *(pos + i - 1)
//         goto *SP;

int findAboveCount(int num_f, int* arr, int size_f)
{
    int counter = 0;
    int j = 0;

    while (j < size_f)
    {
        if (arr[j] > num_f)
            counter = counter + 1;

        j = j + 1;
    }

    return counter;
}

// FINDABOVECOUNT:
//     int counter = 0;
//     int j = 0;
//
//     int size_f = *(SP + 3);
//     int arr_f = *(SP + 2);
//     int num_f = *(SP + 1);
// 
//     WHILE2:
//         if (j - size_f >= 0) goto FIND_END;
// 
//         if (arr[j] - num_f <= 0) goto INC_J;
//         counter = counter + 1;
// 
//     INC_J:
//         j = j + 1;
//         goto WHILE2;
// 
//     FIND_END:
//         D = counter;
//         goto *SP;
// 
// END:
//     goto END;
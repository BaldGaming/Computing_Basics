#include <stdio.h>

int AXORB(int a, int b);
int ENCRYPTION(int arr[], int size, int key);

int main()
{
    int arr[3] = {30, 20, 10};

    printf("result of encryption: %d", ENCRYPTION(arr, 3, 20));
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

int ENCRYPTION(int arr[], int size, int key)
{
    int i = 0;

    for (i ; i < size; i++)
    {
        if (AXORB(arr[i], key) == 0)
            return 1;
    }
    return 0;
}

// ENCRYPTION:
//     arr = *(SP + 1);
//     size = *(SP + 2);
//     key = *(SP + 3);
//     int i = 0;

//     FOR:
//         if (i >= size) goto END_FOR

//         IF:
//             if (AXORB(arr[i], key) != 0) goto SKIP_IF
//             return 1;
        
//         SKIP_IF:
//             i = i + 1;
//             goto FOR

//     END_FOR:
//         return 0;
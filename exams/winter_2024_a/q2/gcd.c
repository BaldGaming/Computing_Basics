#include <stdio.h>
#include <math.h>
#define SIZE 2

int gcd(int *arr);

int main() {
    int arr[SIZE] = {24, 18};

    int res = gcd(arr);

    printf("GCD: %d\n", res);
    
    return 0;
}

int gcd(int *arr) {
    int n1, n2, temp;

    if (arr[0] < arr[1]) {
        n1 = arr[1];
        n2 = arr[0];
    }

    else {
        n1 = arr[0];
        n2 = arr[1];
    }

    while (n2 != 0) {
        temp = n2;
        n2 = n1%n2;
        n1 = temp;
    }

    return n1;
}


// GCD:
//     numArr = *(SP + 1);
//     if (arr[0] > arr[1]) goto ELSE
//     n1 = numArr[1];
//     n2 = numArr[0];
//     goto WHILE;

//     ELSE:
//         n1 = numArr[0];
//         n2 = numArr[1];

//     WHILE:
//         if (n2 == 0) goto END_WHILE
//         temp = n2;
//         push(n1);
//         push(n2);
//         push(@RET)
//         goto modulo;

//     RET:
//         n2 = D;
//         SP = SP + 2;
//         n1 = temp;
//         goto WHILE;

//     END_WHILE:
//         D = n1;
//         goto *(SP);
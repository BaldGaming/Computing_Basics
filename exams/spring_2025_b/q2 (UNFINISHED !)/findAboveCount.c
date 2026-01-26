#include <stdio.h>
#define SIZE 6

int findAboveCount(int num, int arr[], int size);

int main()
{
    int arr[SIZE] = {11, 22 ,33 ,55, 44, 100};
    int num = 3;

    printf("The %drd biggest number in the array is: %d", num, findAboveCount(num, arr, SIZE));
}


int findAboveCount(int num, int arr[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		int arri = arr[i];
		if (arri > num)
			count++;
	}
	return count;
}

    
// FINDABOVECOUNT:
//     num = *(SP + 1);
//     arr = (int*)*(SP + 2);
//     size = *(SP + 3);

//     count = 0;
//     i = 0;

//     FOR1:
//     	if (i >= size) goto FOR1_END;
//     	arri = arr[i];
//     	if (arri > num)
//     		count++;
//     	i++;
//     	goto FOR1;

//     FOR1_END:
//     D = count;
//     goto *SP;
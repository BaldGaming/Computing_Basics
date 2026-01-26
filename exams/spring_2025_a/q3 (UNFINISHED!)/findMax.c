#include <stdio.h>

int findMax(int arr[], int num)
{
    int last = getArray(arr, num - 1);
    if (num == 1)
        return last;

    int maxBeforeLast = findMax(arr, num - 1);

    if (maxBeforeLast > last)
        return maxBeforeLast;

    else
        return last;
}
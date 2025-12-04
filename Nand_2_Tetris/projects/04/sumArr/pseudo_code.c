#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;
    int sum = 0;   // This is R0
    int *ptr = R1; // Pointer starting at address R1

    while (i < R2)
    {
        int value = *ptr; // Get value from RAM
        
        // Check if even: (value & 1) must be 0
        if ((value & 1) == 0)
            sum = sum + value;
        
        ptr++; // Move pointer to next address
        i++;
}


// int i = 0
// int sum = 0 (R0)
// *prt = R1
// WHILE:
//  int value = *ptr (value from pointer target)
//  if (value & 1) == 0 -> sum = sum + value (does addition if the number is even)
//  ptr++ (moves the pointer by 1)
//  i++ increments the i
#include <stdio.h>

int SumOfSquares(int n);

int main()
{
    int n = 6;
    printf("Current: n = %d\n", n);
    printf("After: sum = %d", SumOfSquares(n));
    
    return 0;
}

int SumOfSquares(int n)
{
    if (n == 0)
        return 0;

    return SumOfSquares(n - 1) + (n * n);
}


// Variable Declaration
    int n_arg, n_squared, prev_result, return_val;
    
    // (We don't need global mult_x/mult_y anymore because we pass them as arguments)
    int mult_sum, mult_i;

// Main
MAIN:
    push static 0;
    call SumOfSquares;
    pop static 1;
    goto END;

// Recursive Function
SumOfSquares:
    if (n != 0) goto RECURSIVE_STEP;
    return 0;

RECURSIVE_STEP:
    // Recursive Call: SumOfSquares(n-1)
    n_arg = n - 1;
    push n_arg;
    call SumOfSquares;
    pop prev_result;

    // --- CHANGED SECTION START ---
    // Instead of "mult_x = n", we push the arguments for the function
    push n;        // Argument 0 for MULT
    push n;        // Argument 1 for MULT
    call MULT; 
    // --- CHANGED SECTION END ---
    
    pop n_squared;

    return_val = prev_result + n_squared;
    return return_val;

// Mult Logic
MULT:
    // (Arguments x and y are now implied to be on the stack/argument segment)
    mult_sum = 0;
    mult_i = 0;

MULT_LOOP:
    // We check against 'y' (which is Argument 1)
    if (mult_i >= y) goto MULT_END;

    // Body: sum += x (which is Argument 0)
    mult_sum += x;

    mult_i = mult_i + 1;
    goto MULT_LOOP;

MULT_END:
    return mult_sum;

END:
    goto END;
#include <stdio.h>

int div_by_m(int n, int m)
{
    int i, result, powm, prev, prev2;

    result = 0;

    while (n > 0)
    {
        prev2 = 0;
        prev = 1;
        powm = m;

        while (powm <= n)
        {
            prev2 = prev;
            prev = powm;

            for (i = 0; i < (m - 1); i++)
                powm = powm + prev;
        }

        result = result + prev2;
        n = n - prev;
    }
    return result;
}

int main() {
    int n1 = 100;
    int m1 = 10;
    int res1 = div_by_m(n1, m1);
    printf("Result of %d / %d = %d\n", n1, m1, res1);

    return 0;
}


// DIV_BY_M:
//     int i, result, powm, prev, prev2;
//     result = 0

// WHILE1:
//     if (!(n > 0)) goto END_WHILE1
//     prev2 = 0
//     prev = 1
//     powm = m

// WHILE2:
//     if (powm > n) goto END_WHILE2
//     prev2 = prev
//     prev = powm
//     i = 0

// FOR:
//     if (!(i < (m - 1))) goto END_FOR
//     powm = powm + prev
//     i = i + 1
//     goto FOR

// END_FOR:
//     goto WHILE2

// END_WHILE2:
//     result = result + prev2
//     n = n - prev
//     goto WHILE1

// END_WHILE1:
//     return result
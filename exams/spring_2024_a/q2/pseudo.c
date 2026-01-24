// return address: SP
// n: SP + 1
// arr: SP + 2
COMPUTE_DIVISORS:
    // n AND arrptr
    n = *(SP + 1);
    arrptr = *(SP + 2);

    // *arrptr = 1
    *arrprt = 1;
    arrptr++;

    // k = 1, i = 2
    k = 1;
    i = 2;

    // while1
    WHILE1:
        if (!(i < n)) goto SKIP_WHILE1
        sum = i;
        WHILE2:
            if (!(sum < n)) goto SKIP_WHILE2
            sum = sum + i;
            goto WHILE2;
        
        SKIP_WHILE2:
        if (sum != n) goto SKIP_IF
        *arrptr = i;
        arrptr++;
        k++;

        SKIP_IF:
        i++;
        goto WHILE1;
    
    SKIP_WHILE1:
    *arrptr = n;
    k++;
    D = k
    goto *(SP)

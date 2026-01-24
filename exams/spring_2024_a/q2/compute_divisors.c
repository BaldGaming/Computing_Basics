int compute_divisors(int n, int arr[])
{
    int i, k, sum;
    arrptr = arr;
    *arrptr = 1;
    arrptr++;
    k = 1;
    i = 2;
    while (i < n)
    {
        sum = i;
        while (sum < n)
            sum = sum + i;
        if (sum == n)
        {
            *arrptr = i;
            arrptr++;
            k++;
        }
        i++;
    }
    *arrptr = n;
    k++;
    return k;
}

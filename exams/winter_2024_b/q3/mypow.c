int mypow(int n, int p)
{
    int i, j, k, gsum, tsum, psum, n1, n2, pgsum;

    gsum = 0;
    n2 = n;
    for (k = 1; k < p; k++)
    {
        pgsum = gsum;
        n1 = n;
        while (n1 > 0)
        {
            psum = 0;
            tsum = n2;
            i = 1;
            while (i <= n1)
            {
                psum = tsum;
                tsum = tsum + tsum;
                j = i;
                i = i + i;
            }
            gsum = gsum + psum;
            n1 = n1 - j;
        }
        gsum = gsum - pgsum;
        pgsum = gsum;
        n2 = gsum;
    }
    return gsum;
}

// ARGUMENT: 0-n, 1-p
// MYPOW:
// LOCAL: 0-i, 1-j, 2-k, 3-gsum, 4-tsum, 5-psum, 6-n1, 7-n2, 8-pgsum

//     gsum = 0
//     n2 = n
//     label FOR:
//         if (!(k < p)) goto END_FOR
//         pgsum = gsum
//         n1 = n
        
//         label WHILE1:
//             if (!(n1 > 0)) goto END_WHILE1
//             psum = 0
//             tsum = n2
//             i = 1

//             label WHILE2:
//                 if (i > n1) goto END_WHILE2
//                 psum = tsum
//                 tsum = tsum + tsum
//                 j = i
//                 i = i + i
//                 goto WHILE2

//             label END_WHILE2:
//                 gsum = gsum + psum
//                 n1 = n1 - j
//                 goto WHILE1
        
//         label END_WHILE1:
//             gsum = gsum - pgsum
//             pgsum = gsum
//             n2 = gsum
//             k = k + 1
//             goto FOR
    
//     label END_FOR:
//         return gsum
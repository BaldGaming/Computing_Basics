void maxSort(int arr[], int size);
    int i = 0;
    int maxIndex;
    int temp;

    for (i ; i < size; i++)
    {
        maxIndex = MaxInArr(arr + i, size - i);
        temp = arr[i];
        arr[i] = arr[i + maxIndex];
        arr[i + maxIndex] = temp;
    }


// MAXSORT:
//     arr = *(SP + 1);
//     size = *(SP + 2);

//     int i = 0;

//     FOR:
//         if (i >= size) goto END_FOR
//         maxIndex = MaxInArr(arr + i, size - i);
//         temp = arr[i];
//         arr[i] = arr[i + maxIndex];
//         arr[i + maxIndex] = temp;
//         i = i + 1;
//         goto FOR
    
//     END_FOR:
//         goto *(SP)



// MAXSORT:
(MAXSORT)
    // arr = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @arr
    M = D

    // size = *(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @size
    M = D

    // int i = 0;
    @i
    M = 0
    
    // FOR:
    (FOR)
        // if (i >= size) goto END_FOR
        @size
        D = M
        @i
        D = M - D
        @END_FOR
        D;JGE

        // maxIndex = MaxInArr(arr + i, size - i);
        // size + i, then push
        @i
        D = M
        @size
        D = M + D
        @SP
        AM = M - 1
        M = D
        // size - i, then push
        @i
        D = M
        @size
        D = M - D
        @SP
        AM = M - 1
        M = D
        // push RET
        @RET
        D = M
        @SP
        AM = M - 1
        M = D
        // goto MaxInArr
        @MaxInArr
        0;JMP

        (RET)
            // save D into maxIndex
            @maxIndex
            M = D

            // clean stack
            @3
            D = A
            @SP
            M = M + D

        // temp = arr[i]
        @i
        D = A
        @arr
        A = M + D
        D = M
        @temp
        M = D

        // arr[i] = arr[i + maxIndex];
        // arrimaxIndex = arr[i + maxIndex]
        @i
        D = M
        @maxIndex
        D = M + D
        @arr
        A = M + D
        D = M
        @arrimaxIndex
        M = D
        // temptemp = arr[i]
        @i
        D = M
        @arr
        A = M + D
        D = M
        @temptemp
        M = D

        //  temptemp = arr[i] = arr[i + maxIndex] = arrimaxIndex;
        @arrimaxIndex
        D = M
        @temptemp
        M = D
        @
//     FOR:
//         if (i >= size) goto END_FOR
//         maxIndex = MaxInArr(arr + i, size - i);
//         temp = arr[i];
//         arr[i] = arr[i + maxIndex];
//         arr[i + maxIndex] = temp;
//         i = i + 1;
//         goto FOR
    
//     END_FOR:
//         goto *(SP)
// FINDABOVECOUNT:
(FINDABOVECOUNT)
    // num = *(SP + 1);
    @SP
    A = M + 1
    D = M
    @num
    M = D

    // arr = (int*)*(SP + 2);
    @2
    D = A
    @SP
    A = M + D
    D = M
    @arr
    M = D

    // size = *(SP + 3);
    @3
    D = A
    @SP
    A = M + D
    D = M
    @arr
    M = D
    
    // count = 0;
    @count
    M = 0

    // i = 0;
    @i
    M = 0

// FOR1:
(FOR1)
    // if (i >= size) goto FOR1_END;
    @size
    D = M
    @i
    D = M - D
    @FOR1_END
    D;JGE

    // arri = arr[i];
    @i
    D = M
    @arr
    A = M + D
    D = M
    @arri
    M = D

    // if (arri > num)
//     
//     	
//     	arri = arr[i];
//     	if (arri > num)
//     		count++;
//     	i++;
//     	goto FOR1;

//     FOR1_END:
//     D = count;
//     goto *SP;
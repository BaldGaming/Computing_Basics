#include <stdio.h>

int getArray1D(int* arr, int i);
void setArray1D(int* arr, int i, int val);
int getArray2D(int* mat, int rowIndex, int colIndex, int numCols);
int mult(int x, int y);
void multMatrixVector(int* res, int* mat, int* vec, int matRows, int matCols);

int main()
{
    int matrix1[3][4] = {{5 , 6 , 7 , 8 },
                         {9 , 10, 11, 12},
                         {13, 14, 15, 16}
                        };
                        
    int matrix2[4][1] = {{1},
                         {2},
                         {3},
                         {4}
                        };

    int res[3];

    multMatrixVector(res, (int*)matrix1, (int*)matrix2, 3, 4);

    printf("Result Vector:\n");
    for (int i = 0; i < 3; i++)
        printf("%d\n", res[i]);

    return 0;
}

int getArray1D(int* arr, int i)
{ return arr[i]; }

void setArray1D(int* arr, int i, int val)
{ arr[i] = val; }

int getArray2D(int* mat, int rowIndex, int colIndex, int numCols)
{ return mat[rowIndex * numCols + colIndex]; }

int mult(int x, int y)
{ return x*y; }

void multMatrixVector(int* res, int* mat, int* vec, int matRows, int matCols)
{
    int i = 0, sum, j;
    for (i ; i < matRows; i++)
    {
        sum = 0;
        
        for (j = 0; j < matCols; j++)
        {
            int matVal = getArray2D(mat, i, j, matCols);
            
            int vecVal = getArray1D(vec, j);
            
            sum = sum + mult(matVal, vecVal);
        }
        
        setArray1D(res, i, sum);
    }
}


// MULTMATRIXVECTOR:
//     int i = 0; sum, j

//     FOR1:
//         if (!(i < matRows)) goto END_FOR1
//         sum = 0
//         j = 0

//         FOR2:
//             if (!(j < matCols)) goto END_FOR2
//             int matVal = getArray2D(mat, i, j, matCols)
            
//             int vecVal = getArray1D(vec, j)
            
//             sum = sum + mult(matVal, vecVal)

//             j = j + 1
//             goto FOR2
        
//         END_FOR2:
//             setArray1D(res, i, sum)
//             i = i + 1
//             goto FOR1
    
//     END_FOR1:
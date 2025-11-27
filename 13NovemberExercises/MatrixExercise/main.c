#include <windows.h>
#include <heapapi.h>
#include <stdio.h>

static size_t rows = 3;
static size_t columns = 3;

void setNumberInMatrix(int *matrix, int row, int column, int number)
{
    matrix[(columns* column)+row] = number;
}

int getNumberInMatrix(int *matrix, int row, int column)
{
    printf("The number is %d \n", matrix[(columns* column)+row]);
    return matrix[(columns* column)+row];
}


int main() 
{

    HANDLE heap = GetProcessHeap();
    SIZE_T totalBytes = rows * columns * sizeof(int);

    int *matrix = (int*)HeapAlloc(heap, HEAP_ZERO_MEMORY, totalBytes);
    if (!matrix) {
        printf("Failed allocation\n");
        return 1;
    }
    int i = 0;
    i = getNumberInMatrix(matrix,2,2);
    i++;
    setNumberInMatrix(matrix,2,2,i);
    i = getNumberInMatrix(matrix,2,2);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i*columns + j]);
        }
        printf("\n");
    }

    HeapFree(heap, 0, matrix);
    return 0;
}

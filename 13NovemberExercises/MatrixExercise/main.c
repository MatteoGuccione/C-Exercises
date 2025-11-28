#include <stdio.h>
#include <stdlib.h>

static int rows = 3;
static int columns = 3;

int** CreateMatrix()
{
    int **matrix = calloc(rows,sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = calloc(columns,sizeof(int));
    }
    return matrix;
}

void setNumberInMatrix(int **matrix, int row, int column, int number)
{
    matrix[row][column] = number;
}

int getNumberInMatrix(int **matrix, int row, int column)
{
    return matrix[row][column];
}

void freeMatrix(int *matrix)
{
    for(int i = 0; i < rows; i++) {
        free(&matrix[i]);
    }
    free(matrix);
}



int main() 
{

    int** matrix = CreateMatrix();

    int i2 = 2;
    setNumberInMatrix(matrix,2,2,i2);

    int result;
    result = getNumberInMatrix(matrix,2,2);
    printf("%d \n", result);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", getNumberInMatrix(matrix,i,j));
        }
        printf("\n");
    }
    

    printf("Over");

    return 0;
}

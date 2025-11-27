#include <stdio.h>

int* staticFunctionPointer()
{
    static int number = 2;
    int* pointer = &number;
    return pointer;
}




int main()
{
    int* pointer = staticFunctionPointer();
    *pointer=*pointer+2;
    printf("Value: %d",*pointer);
}
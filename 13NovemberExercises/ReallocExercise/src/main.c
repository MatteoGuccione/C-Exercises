#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* pointer, size_t old_size, size_t new_size) 
{
    if (new_size == 0) {
        free(pointer);
        return NULL;
    }
    if (pointer == NULL) {
        return malloc(new_size);
    }

    void* new_pointer = calloc(new_size,sizeof(new_size));
    if (!new_pointer) {
        return NULL; 
    }

    size_t copy_size = old_size < new_size ? old_size : new_size;
    memcpy(new_pointer, pointer, copy_size);

    free(pointer);
    return new_pointer;
}



int main()
{
    int* intArray = calloc(5,sizeof(int));
    
    int newSize = 10;
    intArray[0] = 1;
    intArray[1] = 1;
    intArray[2] = 1;

    intArray = my_realloc(intArray, 5 * sizeof(int), newSize * sizeof(int));

    for(int i=0;i<newSize;i++)
    {
        printf("Array element %d is %d \n",i,intArray[i]);
    }
}
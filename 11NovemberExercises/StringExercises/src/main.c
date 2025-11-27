#include <string.h>
#include <stdio.h>

int stringLenght(char* string)
{
    int keepGoing = 1;
    int counter = 0;
    while(keepGoing)
    {
        if(!string[counter])
        {
            return counter;
        }
        counter++;
    }
    return counter;

}

int stringCompare(char* string,char* string2)
{
    int counter1 = stringLenght(string);
    int counter2 = stringLenght(string2);
    if(counter1 != counter2)
    {
        printf("Not equals");
        return 0;
    }
    for(int i = 0; i<counter1;i++)
    {
        if(string[i]!=string2[i])
        {
            printf("Not equals");
            return 0;
        }
    }
    printf("Equals");
    return 1;
}

void stringAdder(char* buffer,rsize_t bufferSize, char* string)
{
    int stringlenght = stringLenght(string);
    int stringCounter = 0;
    for(int i = 0; i<bufferSize;i++)
    {
        if(!buffer[i])
        {
            printf("Found empty spot");
            stringCounter++;
            if(stringCounter == stringlenght)
            {
                break;
            }
        }
        else
        {
            stringCounter = 0;
        }
    }

}

int main() 
{
    char* first = "Hello";
    char* second = "Hellw";
    char* buffer[1024];
    int lenght = stringLenght(first);
    printf("The lenght of the string is %d \n", lenght);
    int result = stringCompare(first,second);
    stringAdder(buffer,1024,first);
}
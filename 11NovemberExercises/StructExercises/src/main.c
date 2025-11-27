#include <stdio.h>
#include <string.h>

struct struct1 
{
    short s1;  // Offset 0
    char  c1;  // Offset 2
               // Padding 1
    short s2;  // Offset 4
};

struct struct2
{
    short s1;  //offset 0
    short s2;  //offset 2
    char  c1;  //offset 4
               //Padding 4
    int i1;    //offset 8
};

struct struct3 
{
    char s1;  //offset 0
    char s2;  //offset 1
    char c1;  //offset 2
              //Padding 6
    double d1; //offset 8
};

struct struct4 
{
    double d1; //offset 0
    double d2; //offset 8
    int i1;    //offset 16
               //Padding 4 
    double d3; //offset 24

};




int main() 
{
    printf("struct1 size: %llu\n", sizeof(struct struct1));

    printf("struct2 size: %llu\n", sizeof(struct struct2));

    printf("struct3 size: %llu\n", sizeof(struct struct3));

    printf("struct4 size: %llu\n", sizeof(struct struct4));
}
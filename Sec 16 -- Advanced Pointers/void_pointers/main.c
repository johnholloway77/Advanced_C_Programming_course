#include <stdio.h>

void printVP(void *pData, int type);

enum type{
    INT,
    FLOAT,
    CHAR
};

int main()
{
    printf("Void Pointers\n");

    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr = NULL;

    vptr = &i;

    //printf("Value of i = %d\n", *(int *)vptr);
    printVP(vptr, INT);

    vptr = &f;

    //printf("Value of f = %f\n", *(float *)vptr);
    printVP(vptr, FLOAT
            );
    vptr = &ch;

    //printf("Value of c = %c\n", *(char*)vptr);
    printVP(vptr, CHAR);

    return 0;
}

void printVP(void *pData, int type){
    switch(type){

    case INT:
        printf("Value of i = %d\n", *(int *)pData);
        break;
    case FLOAT:
        printf("Value of f = %f\n", *(float*)pData);
        break;
    case CHAR:
        printf("Value of c = %c\n", *(char*)pData);
        break;
    }
}

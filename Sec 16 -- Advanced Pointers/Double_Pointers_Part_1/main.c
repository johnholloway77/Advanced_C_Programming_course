#include <stdio.h>

int main()
{
    printf("Pointer to Pointer!\n");

    int a = 10;

    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;


    printf("Address of a = %p Value of a = %d\n", &a, a);
    printf("Address of p1 = %p Value of *p1 = %d\n", &p1, *p1);
    printf("Address of p2 = %p Value of **p2 = %d\n\n", &p2, **p2);

    printf("Value at the address stored by p2 = %p\n", *p2);
    printf("Value at the address stored by p1 = %d\n", *p1);

    return 0;
}

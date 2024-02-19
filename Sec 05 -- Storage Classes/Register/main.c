#include <stdio.h>

extern int foo();

int main()
{
    register int x; //register variable

    /*
     *  Cannot create pointer for x as it does not have a memory location.
     *
     *  int *p = &x;
     *
     *  will result in compiler error.
     */


    for(x = 1; x <= 15; x++){

        printf("%d\n", x);
    }

    printf("foo()\n");
    foo();

    return 0;
}

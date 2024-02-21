#include <stdio.h>
#include <stdnoreturn.h>
#include <stdlib.h>

noreturn void randomFunction(){
    exit(1);
}

int main()
{
    printf("Noreturn functions\n");

    randomFunction();

    return 0;
}

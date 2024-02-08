#include <stdio.h>

extern int count;

int i = 5; // global variable as it's declared outside of a function.

void foo(void);

extern void write_extern();

int main(void)
{
    printf("%i\n", i);

    foo(); //this will use a variable in another file to change i

    printf("%i\n", i);

    write_extern();

}

#include <stdio.h>

int count = 7;

void write_extern(void){
    printf("count is %d\n", count);
}

void foo (void){
    extern int i; //external variable declared as a local variable.
    i = 100;
}

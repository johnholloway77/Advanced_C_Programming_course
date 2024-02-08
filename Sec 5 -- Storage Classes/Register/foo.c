#include <stdio.h>

int foo(){
    static int i = 5;
    if(--i){ //checks if i is not equal to 0. Executes if i isn't zero.
        printf("%d ", i);
        foo();
    }

    return 0;
}

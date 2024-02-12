#include <stdio.h>

volatile int x = 1;

int main()
{
    int a = x;
    // some code not involving x

    // it is possible another thread may have changed the value of x;
    int b = x;

    return 0;
}

/*

    Volatile tells the compiler not to cache x and retreive its value from memory. Ensures that if it's
    value was changed, it will be retreived from memory.


*/

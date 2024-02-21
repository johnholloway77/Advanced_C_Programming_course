#include <stdio.h>

inline static void someFunction();


int main()
{
    printf("Inline Functions\n");

    someFunction();

    return 0;
}


inline static void someFunction(){
    //do something
}

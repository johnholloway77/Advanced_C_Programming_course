#include <stdio.h>

int main()
{
    extern int myVariable;
    void testFunction(void);

    printf("Hello!\n");
    printf("myVariable is set to %d\n", myVariable);
    testFunction();
    printf("updating value of myVariable\n");
    myVariable = 42;
    testFunction();
    return 0;
}

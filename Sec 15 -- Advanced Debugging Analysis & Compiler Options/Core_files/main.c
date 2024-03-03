#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = NULL;

    // stored in read only part of data segment
    str = "Grg";

    //problem: trying to moidy read only memory
    // will cause crash

    *(str + 1) = 'n';

    return 0;
}

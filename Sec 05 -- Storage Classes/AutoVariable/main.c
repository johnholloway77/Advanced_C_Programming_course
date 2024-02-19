#include <stdio.h>

int main()
{
    int x; // local variable scope of main function
            //same as writing auto int x

    {
        int i; //only in scope of this block
    }

    i = 5; //can't use i here as it is only scoped to the above block

    return 0;
}

int func_name()
{
    int y ; //local to this function
            //same as auto int y
    return y;
}

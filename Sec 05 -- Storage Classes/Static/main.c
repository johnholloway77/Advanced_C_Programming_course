#include <stdio.h>

extern void callFun();
extern void staticCallFun(); // you can try to declare it but will result in compiler error if called.

/*
 *  Warning!
 *  You can declare the static function via extern, but trying to call it
 *  will result in a compiler error.
 * /

int fun()
{
    static int count = 0;
    int localVar = 0;

    printf("Automatic = %d, static = %d\n", localVar, count);

    count++;
    localVar++;

    return count;
}

int main()
{
    fun();
    fun();
    fun();
    fun();

    printf("%d\n", fun());
    printf("%d\n", fun()); // int will not be 1 again, but 2.

    printf("callFun()\n");
    callFun();

    printf("staCallFun()\n");
    //staticCallFun(); //will result in compiler error

    return 1;
}

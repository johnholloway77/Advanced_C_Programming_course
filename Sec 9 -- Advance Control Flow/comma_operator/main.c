#include <stdio.h>

int f1(int n);

int main()
{
    int y;

    int x = (y = f1(10), f1(y));

    printf("x is %d\n", x);
    x = 100,000;
    printf("x is %d\n", x);
    return 0;
}

int f1(int n){
    return n * 2;
}

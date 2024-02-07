#include <stdio.h>

double multiplyByTwo (double input){
    double twice = input * 2.0; //this variable will exist in the stack only when the stackframe for the function is popped on
    return twice;
}

int main(int argc, char *argv[])
{
    int age = 30;
    double salary = 12345.67;
    double myList[3] = {1.2, 2,3, 3.4};
    printf("Double your salary is $%.2f\n", multiplyByTwo(salary));
    return 0;
}

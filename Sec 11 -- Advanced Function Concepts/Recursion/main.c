#include <stdio.h>

int factorial(int n);
void up_and_down(int n);

int main()
{
    printf("Recursion\n");

    int n = factorial(5);
    printf("%d\n", n);

    printf("%d\n", factorial(3));

    up_and_down(0);
    return 0;
}

int factorial(int n){

    if(n == 0) return 1;


    return (n * factorial(n - 1));

}

void up_and_down(int n){
    printf("Level %d n location %p\n", n, &n);

    if(n < 4)
        up_and_down(n+1);

     printf("Level %d n location %p\n", n, &n);
}

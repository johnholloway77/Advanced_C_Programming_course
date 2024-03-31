#include <stdio.h>
#include <math.h>
#define NDEBUG
#include <assert.h>
#define BLAHBLAH 10

int main()
{
    printf("Asserts\n");

    int some_variable = 5;

    assert(some_variable < 10);
    puts("First Assert passed!");

    //static_assert(BLAHBLAH < 3, "static asset failed!");
    //puts("Second assert passed!");

    double x, y, z;

#undef NDEBUG
#include <assert.h>

    puts("Enter a pair of numbers (0 0 to quit):");

    while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0)){
        z = x * x - y * y; //should be +
        assert(z >= 0);
        printf("Answer is %f\n", sqrt(z));
        puts("Enter next pair of numbers: ");

    }

    puts("Done!");

    return 0;
}

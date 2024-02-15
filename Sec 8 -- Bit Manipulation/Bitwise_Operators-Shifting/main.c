 #include <stdio.h>
#include <math.h>

long long convertDecimalToBinary(int n){
    unsigned long long bin = 0;
    int i = 0;

    do{
        bin += (n % 2) * pow(10, i);
        n = n / 2;
        //printf("n: %d bin: %lld\n", n, bin);

        i++;
    } while (n != 0);

    return bin;
}


int main()
{
    printf("Left shift n <<= 1;\n");
    int n = 3;

    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n <<= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n <<= 1;

    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n <<= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n <<= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n <<= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    printf("Right shift n >>= 1;\n");

    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n >>= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n >>= 1;

    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n >>= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n >>= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));

    n >>= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));


    n >>= 1;
    printf("n: %d\n%016lld\n", n, convertDecimalToBinary(n));


    return 0;
}



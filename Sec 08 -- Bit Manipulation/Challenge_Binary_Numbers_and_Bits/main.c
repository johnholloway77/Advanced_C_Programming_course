/*
 Challenge 1: write a function that converts a binary number to a numeric value
    eg: long long bin = 01001001
    you can pass bin as an argument to the function and have the function return an int value of 25

Challenge 2: Write a function that converts an integer to a binary value (long long)
    long long convertDecimalToBinary(int n)


*/

#include <stdio.h>
#include <math.h>



int binaryToDecimal(long long bin);
long long convertDecimalToBinary(int n);

int main()
{

    unsigned long long bin = 1001001;
    printf("1: The decimal value of %lld is: %d\n", bin, binaryToDecimal(bin));

    bin = 11111111;
    printf("1: The decimal value of %lld is: %d\n", bin, binaryToDecimal(bin));

    bin = 1111111111111111ULL;
    printf("1: The decimal value of %lld is: %d\n", bin, binaryToDecimal(bin));

    bin = 11001;
    printf("1: The decimal value of %lld is: %d\n", bin, binaryToDecimal(bin));



    printf("2. The binary value of %d is %lld\n", 13, convertDecimalToBinary(13));

    printf("2. The binary value of %d is %lld\n", 13, convertDecimalToBinary(13));

    printf("2. The binary value of %d is %lld\n", 255, convertDecimalToBinary(255));

    printf("2. The binary value of %d is %lld\n", 6144, convertDecimalToBinary(6144));

    return 0;
}

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

int binaryToDecimal(long long bin){

    int value = 0;
    unsigned int i = 0;

    while(bin > 0){

        if(bin % 10 == 1){
            value += pow(2,i);

        }

        bin /= 10;
        i++;
    }

    return value;
}

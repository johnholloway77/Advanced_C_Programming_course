#include <stdio.h>

long long convertDecimalToBinary(int n);

int main()
{
    printf("Hello World!\n");
    return 0;
}


// not perfect as it only works up to 16 digits
// works okay for reference.
long long convertDecimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1, absN;

    // Handle negative numbers
    if (n < 0) {
        absN = -n;
        binaryNumber = 1; // Set the sign bit to 1 for negative numbers
    } else {
        absN = n;
    }

    while (absN != 0) {
        remainder = absN % 2;
        absN /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    if (n < 0) {

        binaryNumber *= -1;
        binaryNumber += 1;
    }

    return binaryNumber;
}

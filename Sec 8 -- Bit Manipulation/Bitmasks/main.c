#include <stdio.h>

#define MASK 2

long long convertDecimalToBinary(int n);

int main() {
  printf("Hello World!\nWe're all going to die!\n");

  printf("Binary value of MASK  : %016lld\n", convertDecimalToBinary(MASK));

  int flag = 18;

  printf("Binary value of flag  : %016lld\n", convertDecimalToBinary(flag));

  printf("Binary value of Equals: %016lld\n",
         convertDecimalToBinary(flag & MASK));

  printf("\n");
  printf("\n");
  int flags = 15; // 0000 1111
  printf("f = %d\n", flags);

  printf("%08lld\n", convertDecimalToBinary(flags));
  int mask = 182; // 1011 0110

  printf("%08lld\n", convertDecimalToBinary(mask));
  flags |= mask; // 1011 1110
  printf("%08lld\n", convertDecimalToBinary(flags));
  printf("f = %d\n", flags);
  printf("\n");
  printf("\n");

  printf("~mask is: %d %08lld\n", ~mask, convertDecimalToBinary(~mask));

  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("~mask %08lld\n",
         convertDecimalToBinary(~mask) *
             -1); // convert back to positive int to improve readability
  flags &= ~mask;
  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("f = %d\n", flags);
  printf("Note that only the bits that correspond to the 1 bits in ~mask have "
         "been set to 0\n");
  printf("\n");
  printf("\n");

  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("mask  %08lld\n", convertDecimalToBinary(mask));
  flags ^= mask; // 1011 1110
  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("f = %d\n", flags);
  printf(
      "We can run the process again to toggle it back to its original value\n");
  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("mask  %08lld\n", convertDecimalToBinary(mask));
  flags ^= mask; // 1011 1110
  printf("flags %08lld\n", convertDecimalToBinary(flags));
  printf("f = %d\n", flags);
  printf("\n");
  printf("\n");

    //checking the value of the bits

  printf("We first mask the flags variable with the mask (using AND) and then compare the result to the MASK. If the result is true, then the bits set to 1 in the mask are set to 1 in the flag.\n");
  printf("if((flags & MASK) == MASK)\n\t...blah blah blah\n}\n");

  printf("Binary value of flag  : %08lld\n", convertDecimalToBinary(flag));

  printf("Binary value of MASK  : %08lld\n",
         convertDecimalToBinary(MASK));
  printf("Binary value of AND   : %08lld\n",
         convertDecimalToBinary(flag & MASK));

  printf("Is the binary value of the 2nd right most bit is set to 1: %s\n", (flag & MASK) == MASK ? "true!": "Nope!");


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

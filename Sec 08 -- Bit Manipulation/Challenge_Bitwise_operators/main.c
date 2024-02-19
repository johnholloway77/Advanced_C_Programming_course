/*

    Write a program that reads to integers from the user

    then display the results of te following
    ~ to each number
    the ^, \, and ^ operators to the pair
    the << and >> operators to a specific number
    show the results as binary strings


*/

#include <math.h>
#include <ncurses.h>
#include <stdio.h>

long long convertDecimalToBinary(int n);

int main() {

  printf("Please enter two integers!\n");
  refresh();
  int n1;
  scanf("%d", &n1);
  printf("n1 is equal to %d\nPlaese enter your second int\n", n1);
  refresh();
  int n2;
  scanf("%d", &n2);
  printf("n2 is equal to %d\n", n2);
  refresh();

  printf("the result of applying the ~ operator on number %d (%016lld) is: "
         "%d (%lld)\n",
         n1, convertDecimalToBinary(n1), ~n1, convertDecimalToBinary(~n1));
  printf("the result of applying the ~ operator on number %d (%016lld) is: "
         "%d (%lld)\n",
         n2, convertDecimalToBinary(n2), ~n2, convertDecimalToBinary(~n2));

  printf("\n");

  printf("The result of %d & %d is: %d\n", n1, n2, n1 & n2);
  printf("n1     : %016lld\n", convertDecimalToBinary(n1));
  printf("n2     : %016lld\n", convertDecimalToBinary(n2));
  printf("n1 ^ n2: %016lld\n", convertDecimalToBinary(n1 & n2));

  printf("\n");
  printf("The result of %d | %d is: %d\n", n1, n2, n1 | n2);
  printf("n1     : %016lld\n", convertDecimalToBinary(n1));
  printf("n2     : %016lld\n", convertDecimalToBinary(n2));
  printf("n1 ^ n2: %016lld\n", convertDecimalToBinary(n1 | n2));

  printf("\n");
  printf("The result of %d ^ %d is: %d\n", n1, n2, n1 ^ n2);
  printf("n1     : %016lld\n", convertDecimalToBinary(n1));
  printf("n2     : %016lld\n", convertDecimalToBinary(n2));
  printf("n1 ^ n2: %016lld\n", convertDecimalToBinary(n1 ^ n2));
  printf("\n");

  int n3 = n1 << 1;
  printf("The result of %d << 1 is: %d\n", n1, n3);
  printf("n1     : %016lld\n", convertDecimalToBinary(n1));
  printf("n1 << 1: %016lld\n", convertDecimalToBinary(n1));
  n3 = n2 << 1;
  printf("The result of %d >> 1 is: %d\n", n2, n3);
  printf("n2     : %016lld\n", convertDecimalToBinary(n2));
  printf("n2 >> 1: %016lld\n", convertDecimalToBinary(n3));

  return 0;
}

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
    binaryNumber -= 1;
    binaryNumber *= -1;
  }

  return binaryNumber;
}

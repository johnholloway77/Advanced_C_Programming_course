/*
    Challenge: Formatting fucntions

    Write a program that takes an input, a set of numbers from a file, and write
   even, odd, and prime numberss to stdout You can use either fscanf() or
   fgets() & sscanf() to accomplish the above.

    Use the same file numbers.txt

*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isEven(int n);
bool isPrime(int n);

int main() {
  FILE *fp = NULL;
  int n;

  if ((fp = fopen("../Challenge_Formatting_Functions/numbers.txt", "r")) ==
      NULL) {
    fprintf(stderr, "Couldn't open file\n");
    return 1;
  }

  while (fscanf(fp, "%i", &n) != EOF) {

    if (isEven(n)) {
      printf("Even number found: %d\n", n);
    } else if (isPrime(n)) {
      printf("Prime number found: %d\n", n);
    } else {
      printf("Odd number found: %d\n", n);
    }
  }

  fclose(fp);
  return 0;
}

bool isEven(int n) {
  if (n & 1) {
    return false;
  } else
    return true;
}

bool isPrime(int n) {

  if (n <= 1)
    return false;

  int s = (int)sqrt((double)n);
  bool isPrime = true;

  for (int i = 2; i <= s; i++) {
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }

  return isPrime;
}

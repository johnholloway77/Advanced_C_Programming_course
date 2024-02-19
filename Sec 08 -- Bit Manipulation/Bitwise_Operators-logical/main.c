#include <math.h>
#include <stdio.h>

long long convertDecimalToBinary(int n);

int main() {
  unsigned long long bin1 = 0;
  unsigned long long bin2 = 0;
  unsigned long long bin3 = 0;

  short int w1 = 25;
  short int w2 = 77;

  short int w3 = w1 & w2;

  printf("w3 = %d & %d = %d\n", w1, w2, w3);
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  printf("w3 = %016lld\n", convertDecimalToBinary(w3));
  printf("\n");

  w3 = w1 | w2;

  printf("w3 = %d | %d = %d\n", w1, w2, w3);
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  printf("w3 = %016lld\n", convertDecimalToBinary(w3));
  printf("\n");

  w3 = w1 ^ w2;

  printf("w3 = %d ^ %d = %d\n", w1, w2, w3);
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  printf("w3 = %016lld\n", convertDecimalToBinary(w3));
  printf("\n");

  w3 = ~w1;
  printf("w3= ~%d\n", w1);
  printf("w3: %d\n", w3);

  printf("\n");


  w3 = ~w2;
  printf("w3= ~%d\n", w2);
  printf("w3: %d\n", w3);

  signed int s1 = 2;
  signed int result = 0;

  printf("s1 = %d\n", s1);
  printf("s1 = %016lld\n", convertDecimalToBinary(s1));
  printf("result = ~s1\n", s1);
  result = ~s1;
  printf("result = %d\n", result);
  printf("result = %016lld\n", convertDecimalToBinary(result));
  printf("\n");

  s1 = 128;
  result = 0;

  printf("s1 = %d\n", s1);
  printf("s1 = %016lld\n", convertDecimalToBinary(s1));
  printf("result = ~s1\n");
  result = ~s1;
  printf("result = %d\n", result);
  printf("result = %016lld\n", convertDecimalToBinary(result));

  printf("\n");

  printf("Use XOR to swap values without using a temp variable\n");
  printf("w1 ^= w2\n");
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  w1 ^= w2;
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 ^= w1\n");
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  w2 ^= w1;
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  printf("w1 ^= w2\n");
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  printf("w2 = %016lld\n", convertDecimalToBinary(w2));
  w1 ^= w2;
  printf("w1 = %016lld\n", convertDecimalToBinary(w1));
  return 0;
}

long long convertDecimalToBinary(int n) {
  unsigned long long bin = 0;
  int i = 0;

  do {
    bin += (n % 2) * pow(10, i);
    n = n / 2;
    // printf("n: %d bin: %lld\n", n, bin);

    i++;
  } while (n != 0);

  return bin;
}

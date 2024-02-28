#include <stdio.h>

#define PI 3.14
#define PRNT(a, b)                                                             \
  printf("Value 1 = %d\n", a);                                                 \
  printf("Value 2 = %d\n", b);

int main() {
  printf("MACROS!\n");

  int x = 2;
  int y = 3;

  PRNT(x, y);

  return 0;
}

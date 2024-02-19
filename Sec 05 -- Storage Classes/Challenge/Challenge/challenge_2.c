/*  Challenge 2:
 *  write a C program which finds the sum of various numbers
 *  you cannot pass any variable repersenting the total to the sum() function
 */

#include <stdio.h>

int sum(int n) {
  static int i = 0;
  i += n;
  return i;
}

int challenge2(void) {
  printf("%d\n", sum(25));
  printf("%d\n", sum(15));
  printf("%d\n", sum(30));
  return 0;
}


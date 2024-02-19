/*

    Challenge is to write a program that simulates a nested looping strcuture
 that prints out a triange of asterisks Output should resemble this:
      *
    *   *
   *     *
  *       *
 ***********

    program should be written without any looping constructs and instead only
 use the goto statement. It will probably produce evil spaghetti code

    You will hate spaghetti so much it will ruin dinner forever

*/

#include <stdbool.h>
#include <stdio.h>

int main() {

  int loop = 5;

  printf("Practice with regular loop first!\n\n");

  for (int i = 0; i < 5; i++) {
    for (int j = 1; j < 10; j++) {
      if (j == (loop - i) || j == (loop + i)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");

    if (i == 4) {
      printf("**********");
    }
  }

  printf("\n\nDamm goto statements!!\n\n");
  loop = 5;
  int i = 0;
  int j = 0;

loop_outer:
  if (i < 5) {
    j = 1;

  loop_inner:
    if (j < 10) {
      if (j == (loop - i) || j == (loop + i)) {
        printf("*");
      } else {
        printf(" ");
      }

      j++;
      goto loop_inner;
    }
    printf("\n");

    if (i == 4) {
      printf("**********");
    }
    i++;
    goto loop_outer;
  }

  return 0;
}

// this is a pain in the ass

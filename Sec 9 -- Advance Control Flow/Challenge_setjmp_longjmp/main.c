/*
    Challenge setjmp and longjmp

    Use setjmp and longjmp to gracefully handle unrecoverable program errors.
   When you discover an unrecoverable error you should transfer control back to
   the main input loop and start again tere

    crete a function named error_recovery that prints out an error and then
   longjmp control back to main loop

    your main function should include a forever loop that uses setjmp at the top
   of the loop before processing.

    You can even add "dummy code in your loop that simulates a error (By calling
   error_recovery) when setjmp returns 0;

*/

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;

void error_recovery() {
  printf("Error handled. Press any key to continue\n");
  getchar();
  getchar();
  longjmp(buf, 0);
}

int main() {
  while (1) {
    if (setjmp(buf) == 0) {
      // system("clear");

      double d1, d2, result;
      printf("Welcome to calculator!\n");
      printf("Enter first number: \n");
      scanf("%lf", &d1);
      printf("Enter second number number: \n");
      scanf("%lf", &d2);

      if (d2 == 0)
        error_recovery();

      printf("Result is: %lf\n", d1 / d2);
    } else {
      printf("Error recovering...\n");
    }
  }
  return 0;
}

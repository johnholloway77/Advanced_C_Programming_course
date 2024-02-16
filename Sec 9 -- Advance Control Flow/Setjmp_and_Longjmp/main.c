#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;
jmp_buf buf2;

void println(char *s) {
  printf("%s\n", s); // god I miss println() from java
}

void myfunction() {
  printf("in myFucntion()\n");
  longjmp(buf, 1);

  // not reached
  printf("You will never see this because I longjmp'd\n");
}

double divide(double f1, double f2){
    if(f2 == 0) println("Can't divide by 0 you jackass!"), longjmp(buf2, 1);
    return f1/f2;
}

int main() {

  if (setjmp(buf))
    printf("back in main\n");
  else {
    printf("First time through\n");
    myfunction();
  }

  println("");
  println("Division test");

  double f1, f2, result;
  println("Enter first number");
  scanf("%lf", &f1);
  println("Enter second number");
  scanf("%lf", &f2);

  if(setjmp(buf2) == 0){
      result = divide(f1, f2);
      printf("Result is %lf\n", result);
  }

  return 0;
}

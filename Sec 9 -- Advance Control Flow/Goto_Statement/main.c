#include <stdio.h>

int main() {

  const int maxInput = 5;

  int i = 0;

  for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
          for(int k = 0; k < 20; k++){
              if ((k+j+i) == 1) goto escape; //example escape conditional
              printf("loopy do!\n");
          }
      }
  }

  escape:
    ;

  double number, average, sum = 0.0;

  for (i = 1; i <= maxInput; i++) {
    printf("Enter a number\n");
      scanf("%lf", &number);

    if (number < 0.0)
      goto jump;

    sum += number;
  }

jump:
  average = sum / (i - 1);
  printf("Sum = %.2f\n", sum);
  printf("Average = %.2f", average);

  return 0;
}

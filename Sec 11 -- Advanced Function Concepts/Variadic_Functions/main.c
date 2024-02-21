#include <stdarg.h>
#include <stdio.h>

double average(double v1, double v2, ...);

int main() {
  double v1 = 10.5, v2 = 2.5;
  int num1 = 6, num2 = 5;
  long num3 = 12L, num4 = 20L;

  printf("Hello Average!\n");

  printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
  printf("Average = %.2lf\n", average(10., 2.0, 0.0));
  printf("Average = %.2lf\n", average((double)num2, v2, (double)num1, (double)num4, (double)num3, 5.5, 0.0));
  return 0;
}

//Implementing variadic function

double average (double v1, double v2, ...){
    va_list parg;

    //get the madatory parameters out of the way
    double sum = v1 + v2;
    double value = 0.0;
    int count = 2; //start count at 2 as ther are two mandatory parameters

    va_start(parg, v2); //v2 is the last mandatory paramater, so we start after that one.

    //loop throught the parg and add it to the sum, increment counter
    while((value = va_arg(parg, double)) != 0.0){ //what happens if 0.0 is a legit argument? This assumes last argument will be 0.0
        sum += value;
        ++count;
    }

    va_end(parg);

    return sum / count;
}

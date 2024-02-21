/*
    Challenge:
    Write a program that creates a variadic function that will allow a
   programmer to add any amount of numbers (integers) that they would like to be
   added together. In order to know how many numbers are being passed to this
   variadic function, either use the first number as a count or designate a
   specific value to mark the end .


    Additional challenges:
        -Try to make it so that you can sum both ints and doubles
        -Do something to caclulate averages of unknown values
        -Implement your own printf function
            ~You would need a character to specify the format
            ~You acn use '%', as it is implemented in printf and scanf or some
   other character.

*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addingNumbers(int count, ...);
double addingNumbers2(double d1, ...);
void printformatted(char *s, ...);
char *sliceString(const char *str, int start, int end);

int main() {

  printf("Challenge Variadic Functions!\n");

  printf("\n");
  printf("addingNumbers1\n");
  printf("%d\n", addingNumbers(2, 10, 20));
  printf("%d\n", addingNumbers(3, 10, 20, 30));
  printf("%d\n", addingNumbers(4, 10, 20, 30, 40));

  printf("\n");
  printf("addingNumbers2\n");
  printf("%.2f\n", addingNumbers2(10.0, (double)20, 0.0));
  printf("%.2f\n", addingNumbers2(10.0, (double)20, 30.0, 0.0));
  printf("%.2f\n", addingNumbers2(10.0, (double)20, 30.0, (double)40, 0.0));

  printformatted("number is %d char is: %c string is: %s double is: %f text\n",
                 5, 'x', "cat", 3.14);

  char *str = "The cat in the hat!";
  // printf("Test String slice: %s\n", sliceString(str, 0,7));

  return 0;
}

int addingNumbers(int count, ...) {
  int sum = 0;
  va_list args;

  va_start(args, count);

  for (int i = 0; i < count; i++) {
    sum += va_arg(args, int);
  }

  va_end(args);
  return sum;
}

double addingNumbers2(double d1, ...) {
  double sum = d1;
  double val = 0.0;
  int count = 0;

  va_list args;

  va_start(args, d1);

  while ((val = va_arg(args, double)) != 0.0) {
    sum += val;
    count++;
  }

  va_end(args);
  return sum;
}

void printformatted(char s[], ...) {
  va_list args;
  va_start(args, s);
  int count = 0;

  int i = 0;
  int perIndex[32] = {-1};
  char charVal[32] = {'\0'};

  char buf[256] = {'\0'};

  for (int j = 0; s[j] != '\0'; j++) {
    if (s[j] == '%') {
      count++;
      perIndex[i] = j;
      charVal[i] = s[j + 1];
      i++;
    }
  }

  int start = 0;

  for (int j = 0; j <= count; j++) {
    char *temp = NULL;
    if (j < count) {

      temp = sliceString(s, start, perIndex[j]);
      char temp2[256];
      int num;
      double dub;
      char ch;
      char *string;

      if (temp != NULL) {
        strcat(buf, temp);
        // free(temp);
      }

      start = perIndex[j] + 2;

      switch (charVal[j]) {
      case 'c':
        ch = (char)va_arg(args, int);
        sprintf(temp2, "%c", ch);
        strcat(buf, temp2);
        break;
      case 'd':
        num = va_arg(args, int);
        sprintf(temp2, "%d", num);
        strcat(buf, temp2);
        break;
      case 'f':
        dub = va_arg(args, double);
        sprintf(temp2, "%f", dub);
        strcat(buf, temp2);
        break;
      case 's':
        strlcpy(temp2, va_arg(args, char *), sizeof(temp2));
        strcat(buf, temp2);
        break;
      }
    } else {
      int slength = 0;
      while (s[slength] != '\0')
        slength++;

      temp = sliceString(s, start, slength);
      if (temp != NULL) {
        strcat(buf, temp);
        // free(temp);
      }
    }

    free(temp);
  }

  printf("%s", buf);

  va_end(args);
}

char *sliceString(const char *str, int start, int end) {
  char *temp = malloc(sizeof(char) * 64);
  int i, j = 0;

  for (i = start; i < end; i++) {
    temp[j++] = str[i];
  }
  temp[j] = '\0';

  return temp;
}

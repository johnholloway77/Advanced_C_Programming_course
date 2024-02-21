/*
    Challenge 1:
        Write a program that will calculate the sum of numbers from 1 to n using
   recursion.

    Challenge 2:
        Write a program which will find the Greatest Common Denominator of two
   numbers using recursion eg: The GCD of 10 and 50 is: 10;

    Challenge3:
        Write a program that will find the reverse of a string using recusion
          eg:   Enter the string: studytonight
                The original string is: studytonight
                The reverse string is: thginotyduts

*/
#include <stdio.h>
#include <string.h>

int challenge1(int n);
int challenge2(int n1, int n2);
char *reverseString(char *str, int len, int n);

int main() {
  char str[256];
  int length = 0;
  int n1 = 0;
  int n2 = 0;

  printf("Challenge Recursion\n\n");

  printf("challenge1:\n");
  printf("Enter a number: ");
  scanf("%d", &n1);
  printf("The sum of 1 to %d is %d\n", n1, challenge1(n1));

  printf("Challenge 2\n");
  printf("Two numbers required. Enter number 1: ");
  scanf("%d", &n1);
  printf("Enter second number: ");
  scanf("%d", &n2);
  printf("The greatest common denominator of %d and %d is %d\n", n1, n2,
         challenge2(n1, n2));

  printf("Challenge 3\n");
  printf("Enter the string: ");
  if (fgets(str, sizeof(str), stdin) != NULL) {
    char *ptr = strchr(str, '\n');
    *ptr = '\0';

    while (str[length] != 0) {
      length++;
    }

    printf("The original string is: %s\n", str);
    printf("The reverse strign is: %s\n", reverseString(str, length, 0));
  }

  return 0;
}

int challenge1(int n) {
  if (n > 0)
    n += challenge1(n - 1);

  return n;
}

int challenge2(int n1, int n2) {

  if (n2 != 0) {
    return challenge2(n2, n1 % n2);
  }
    return n1;
}

char *reverseString(char str[], int len, int n) {

  if (n == (len / 2))
    return str;

  char temp = str[n];
  str[n] = str[len - n - 1];
  str[len - n - 1] = temp;

  str = reverseString(str, len, n + 1);
  return str;
}

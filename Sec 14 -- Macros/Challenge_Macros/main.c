/*

    Challenge 1: Write a program that uses the following predefined symbolic
   constants
    __LINE__, __FILE__, __DATE__, __TIME__, __STDC___

    Challenge 2: Write a program that will accept two parameters and return the
   sum of the two -Have the user enter two values

    Challenge 3: Write a program that takes a value from the user and squares
   and cubes it using macros
*/

#include <stdio.h>
#define SUM(x, y) ((x) + (y))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

//The boolean comparison doesn't need to return a value as it will generate the true/false value itself.
//#define IS_UPPER(ch) (((ch >= 'A') && (ch <='Z')) ? 1 : 0) //Redundant
//#define IS_LOWER(ch) (((ch >= 'a') && (ch <='z')) ? 1 : 0) //redundant
#define IS_UPPER(ch) ((ch >= 'A') && (ch <='Z'))
#define IS_LOWER(ch) ((ch >= 'a') && (ch <='z'))

int main() {
  printf("Challenge 1:\n"
         "This is line %d inside the file %s\n"
         "The file was created on %s at %s\n"
         "Is this file ISO standard? %s \n",
         __LINE__, __FILE__, __DATE__, __TIME__, __STDC__ ? "Yes" : "NO");

  printf("\nChallenge 2:\n");
  int x;
  int y;
  printf("Enter the first number: ");
  scanf("%d", &x);
  printf("Enter second number: ");
  scanf("%d", &y);

  printf("The sum of %d and %d is %d\n", x, y, SUM(x, y));

  printf("\nChallenge 3\n");
  int z;
  printf("Enter the number to get it squared and cubed: ");
  scanf("%d", &z);
  printf("The value of %d squared is %d and cubed is %d\n", z, SQUARE(z), CUBE(z));

  getchar(); //clear stdin

  printf("\nChallenge 4\n");
  char c;
  printf("Enter a char to have it checked by as upper or lower case ");
  c = getchar();
  printf("Is %c uppercase? %s\n", c, IS_UPPER(c) ? "yes" : "no");
  printf("Is %c lowercase? %s\n", c, IS_LOWER(c)? "YES" : "no");


  return 0;
}

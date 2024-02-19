#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char ch = '\0';

  ch = getc(stdin);
  getchar(); // absorb the new line break from enter

  printf("Read in character %c\n", ch);

  printf("\n");

  printf("getchar() test\n");

  printf("printf(\"%c\", getchar());\n");
  printf("%c\n", getchar());

  printf("\n");

  printf("getchar() test 2\n");

  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }

  FILE *fp = NULL;
  fp = fopen("../char_functions/cats.txt", "r");

  if (fp == NULL) {
    printf("Couldn't open file :( \n");
    return 1;
  }

  printf("reading from file\n");

  ch = fgetc(fp);
  while (ch != EOF) {
    putchar(ch);
    ch = fgetc(fp);
  }

  fclose(fp);
  ch = getchar();\


  //Stdin is messing up and auto filling for getchar() due to the other functions in the program
  // char c;
  // printf("\n\nungetc()\n\n");
  // c = '0';

  // while (isspace(c = getchar()))
  //   ;
  // ungetc(c, stdin);
  // printf("Char is %c\n", c);

  return 0;
}

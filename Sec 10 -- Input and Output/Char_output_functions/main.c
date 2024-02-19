#include <stdio.h>

int main() {
  char ch = '\0';
  FILE *fp = NULL;
  FILE *fp2 = NULL;
  fp = fopen("../char_functions/cats.txt", "r");
  fp2 = fopen("../Char_output_functions/test.txt", "w");

  if (fp == NULL) {
    printf("Couldn't open file :( \n");
    return 1;
  }

  if (fp2 == NULL) {
    printf("Couldn't open test.txt\n");
    return 1;
  } else {
    printf("Test.txt opened!\n");
  }

  printf("reading from file cats.txt\n");

  ch = fgetc(fp);
  while (ch != EOF) {
    // putchar(ch);
    putc(ch, stdout);
    //    putc(ch, fp2);
    ch = fgetc(fp);
  }

  printf("Enter text to be written to test.txt\n");
  while ((ch = getchar()) != EOF) {
    putc(ch, fp2);
  }

  fclose(fp);
  fclose(fp2);

  char string[] = "Hello World!\nWelcome to hell!\n";
  int i = 0;

  while (string[i] != '\0') {
    if (string[i] != ' ') {
      putchar(string[i]);
    } else {
      putchar('_');
    }
    i++;
  }

  return 0;
}

/*
    Challenge:
    Write a program which takes two command line arguments
        -the first is a character
        -the second is an argument

    The requirements of the program are that it should print only those lines in
   the file contain the given character. -Lines in a file are identified by a
   terminating '\n' -Assume no line is no more than 256 chars

    You are required to get fgets() or getline() or both for reading of the file
        -use puts() to display to output.

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("Not enough arguments\n");
    return 1;
  }
  if (argc > 3) {
    printf("Too many arguments jackass\n");
    return 1;
  }

  int ch = argv[1][0];
  char *fileAddr = argv[2];
  char *buffer = NULL;
  size_t bufferSize = 256;
  FILE *fp = NULL;
  bool containsCh = false;


  if ((fp = fopen(fileAddr, "r")) == NULL) { //keep code clean and consise. Use a single line
    printf("Error open file\n");
    return 1;
  }

  buffer = (char *)malloc(sizeof(char) * bufferSize);

  while (getline(&buffer, &bufferSize, fp) != EOF) {
    char *c = NULL;
    c = strchr(buffer, ch);
    if (c != NULL) {
      containsCh = true;
      fputs(buffer, stdout);
    }
  }

  if (!containsCh) {
    printf("The file does not contain any line with the character %c\n", ch);
  }

  return 0;
}

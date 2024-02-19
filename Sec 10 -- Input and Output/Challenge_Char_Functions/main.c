/*
    Challenge 1
    Write a program in C to count the number of words and characters in a file
   OR from STDIN. This program can take zero commandline arguments or one
   command-line argument -If no arguments, then stdin is used -if one argument,
   the argument is the file name.

    Note: It is not counting the correct number of woords because it's not
   getting triggered when ch = EOF

*/

#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *args[]) {
  char ch = '.';
  int i = 0;
  int wordcount = 0;
  FILE *fp = NULL;
  bool useFile = false;
  bool isWord = true; // start from true

  if (argc < 2) {
    printf("Using stdin!\n");
  }
  if (argc == 2) {
    printf("using file name!\n");
    // printf("File name is: ");
    // while(ch){
    //     ch = args[1][i];
    //     putchar(ch);
    //     i++;
    // }
    // printf("\n");
    // printf("This filename has %d chars in it!\n", i - 1); //decrease by 1
    // since it incremetns even after printing last ch
    useFile = true;
  }
  if (argc > 2) {
    printf("Only one argument allowed jackass!\n");
  }

  if (useFile) {
    fp = fopen(args[1], "r");
    if (fp == NULL)
      printf("Error opening file\n");

    while ((ch = getc(fp)) != EOF) {
      putchar(ch);

      i++;

      if (isWord) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF) {
          wordcount++;
          // printf("wc++\n");
          isWord = false;
        }
      }

      // reset check
      if (!isWord) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF) {
          isWord = true;
        }
      }
    }

    while ((ch = getchar()) != EOF) {
      i++;

      if (isWord) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF) {
          wordcount++;
          // printf("wc++\n");
          isWord = false;
        }
      }

      // reset check
      if (!isWord) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF) {
          isWord = true;
        }
      }
    }

    printf("\n");

    printf("The number of words in the file are: %d\n", wordcount);
    printf("the number of characters in the file are: %d\n", i);
  }

  if (!useFile) {
    // fp = fopen(args[1], "r");
    // if (fp == NULL)
    //     printf("Error opening file\n");

    while ((ch = getchar()) != EOF) {
      i++;

      if (isWord) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF) {
          wordcount++;
          // printf("wc++\n");
          isWord = false;
        }
      }

      // reset check
      if (!isWord) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF) {
          isWord = true;
        }
      }
    }

    if ((ch = getchar()) == EOF) {
      if (isWord) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF) {
          wordcount++;
          // printf("wc++\n");
          isWord = false;
        }
      }

      // reset check
      if (!isWord) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != EOF) {
          isWord = true;
        }
      }
    }

    printf("\n");

    printf("The number of words in the file are: %d\n", wordcount);
    printf("the number of characters in the file are: %d\n", i);
  }

  return 0;
}

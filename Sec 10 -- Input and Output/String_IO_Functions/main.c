#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char buf[255];
  char ch = '\0';
  char *p = NULL;

  if (fgets(buf, sizeof(buf), stdin)) {
    p = strchr(buf, '\n'); // returns a pointer to the first character in the
                           // string that is equal to '\n'

    if (p) {
      *p = '\0'; // will change the char at p from \n to \0
    } else {
      while (((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin)) {
        // dumps the rest of the characters after newline character
        // clears the stdin buffer
      }
    }
  } else {
    // something to handle the errors
  }

  printf("Our buffer contains %s\n", buf);

  char *buffer = NULL;
  size_t buffsize = 32; // size in bytes
  size_t characters;
  FILE *fp = NULL;

  fp = fopen("./temp.txt", "w");
  if (fp == NULL)
    exit(1);

  buffer = (char *)malloc(buffsize * sizeof(char));

  if (buffer == NULL) {
    exit(1); // not able to allocate memory
  }

  printf("\nType something for getline(): ");

  characters = getline(&buffer, &buffsize, stdin);
  buffer[strcspn(buffer, "\n")] = '\0';

  printf("%zu characters read.\n", characters);
  printf("You typed \"%s\"\n", buffer);

  if(fputs(buffer, fp) != EOF){
      puts("Files writen to temp.txt");
  }

  free(buffer);

  return 0;
}

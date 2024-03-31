#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);
int comp_ints(const void *p1, const void *p2);

FILE *openFile(const char *file) {
  FILE *inFile;

  if ((inFile = fopen(file, "r")) == NULL) {
    fprintf(stderr, "Can't open %s for reading.\n", file);
    atexit(too_bad); // register too_bad() function
    // exit (EXIT_FAILURE);
    abort();
  }

  return inFile;
}

int main() {
  char address[256];
  char buffer[256];

  atexit(sign_off); // register the sign_off() function

  puts("Testing qsort() first");

  int data[5] = {54, 34, 3, -1, 0};

  for(int i = 0; i < 5; i++){
      printf("%d\n", data[i]);
  }
  puts("running qsort() on data");
  qsort(data, 5, sizeof(int), comp_ints);
  for(int i = 0; i < 5; i++){
      printf("%d\n", data[i]);
  }

  printf("the exit() function!\n");

  puts("Please enter a file address");

  scanf("%s", address);

  FILE *file = openFile(address);

  if (file != NULL)
    puts("Yay! You read the file!");

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    fprintf(stdout, "%s", buffer);
  }

  fclose(file);

  return 0;
}

void too_bad(void) { puts("too bad!"); }

void sign_off(void) { puts("signing off for now."); }

int comp_ints(const void *p1, const void *p2) {
  const int i1 = *(const int *)p1;
  const int i2 = *(const int *)p2;
  return i1 - i2;
}

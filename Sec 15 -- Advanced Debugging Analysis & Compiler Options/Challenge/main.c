#include <stdlib.h>
#include <stdio.h>


int sum(int x, int y, int z) {
  char c = 2;
  int *a = NULL;

#if DEBUG
  fprintf(stderr, "x=%d\n", x);
  fprintf(stderr, "y=%d\n", y);
  fprintf(stderr, "z=%d\n", z);
  fprintf(stderr, "a=%ld\n", (long)a);
#endif


 // a = malloc(sizeof(int));
  *a = 5;
#ifdef DEBUG
  fprintf(stderr, "*a=%d\n", *a);
#endif
  return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }
#ifdef DEBUG
  fprintf(stderr, "DEBUG mode!\n");
  fprintf(stderr, "Number of parameters %d\n", argc);
  if (argc > 1){
  fprintf(stderr, "%s %s %s %s\n", argv[0],argv[1], argv[2], argv[3]);
  }
#endif

  i = atoi(argv[1]);
#ifdef DEBUG
  fprintf(stderr, "i=%d\n", i);
#endif
  j = atoi(argv[2]);
#ifdef DEBUG
  fprintf(stderr, "j=%d\n", j);
#endif
  k = atoi(argv[3]);
#ifdef DEBUG
  fprintf(stderr, "k=%d\n", k);
#endif

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}

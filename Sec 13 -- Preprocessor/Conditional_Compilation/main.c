#include <stdio.h>
#define MYDEF 5
#define MYDEF2 5150
#define JUST_CHECKING
#define LIMIT 4


int main() {
  printf("Conditional Compilation\n\n");

  int i;
  int total = 0;

  for (i = 0; i <= LIMIT; i++) {

    total += 2 * i * i + 1;

#ifdef JUST_CHECKING
    printf("i =%d, running total is %d\n", i, total);
#endif
  }
  printf("Grand total is %d\n", total);

  puts("\n#undef JUST_CHECKING");
#undef JUST_CHECKING

  total = 0;

  for (i = 0; i <= LIMIT; i++) {

    total += 2 * i * i + 1;

#ifdef JUST_CHECKING
    printf("i =%d, running total is %d\n", i, total);
#endif
  }
  printf("Grand total is %d\n", total);

  puts("\n#if conditional");

#if MYDEF == 4

  puts("MYDEF == 4");
#elif MYDEF == 5 && MYDEF2 == 5150
  puts("MYDEF == 5 && MYDEF2 == 5150");
#else
  puts("MYDEF set to something else or not defined");

#endif
  return 0;
}

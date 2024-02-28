#include <stdio.h>

int main() {
  printf("Predefined Macros\n");

  printf("This is line number %d inside of the function %s in the file "
         "\n%s\nOn the date %s at the time of %s\n",
         __LINE__, __func__, __FILE__, __DATE__, __TIME__);
  return 0;
}

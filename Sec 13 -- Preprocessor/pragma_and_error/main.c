#include <stdio.h>

int main() {

  printf("#pragma and #error\n");

  //#pragma clang poison printf

  printf("will this work?\n");
#pragma GCC message "message"

#pragma clang diagnostic push "test"

#if __STDC_VERSION__ != 201112L
  printf("C stamdard: %ld\n", __STDC_VERSION__);
#endif

  int x = 5;
  int y = 5;

  //#error "test error"

  printf("Warning in %s on line %d\n", __FILE__,  __LINE__);

  return 0;
}

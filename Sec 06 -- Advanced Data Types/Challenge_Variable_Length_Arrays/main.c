#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t size = 0;
  printf("Enter array length:!\n");

  scanf("%zd", &size);

  int nums[size];

  int x = 0;
  while (x < size) {
    printf("Enter number:\n");
    scanf("%d", &nums[x++]); // x will increase after being called with postfix.
  }


  return 0;
}

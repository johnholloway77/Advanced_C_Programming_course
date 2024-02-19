#include <malloc.h>
#include <stdio.h>

struct s {
  int arraySize;
  int array[];
};

int main() {
    int desiredSize = 5;
    struct s *ptr;

    ptr = malloc(sizeof(struct s) + desiredSize * sizeof(int));


  return 0;
}

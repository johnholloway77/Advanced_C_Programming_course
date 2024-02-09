#include <stdio.h>

void array(int size) {
  printf("\nNew array!\n");
  char alpha[size];
  int x = 0;
  while (x < size) {
    alpha[x] = 'A' + x;
    printf("alpha is: %c\n", alpha[x]);
    x++;
  }
}


/*
 * in older versions of C you have to specifically list the names of the ints the array
 * int sum2d(int rows, int cols, int array[rows][cols]);
 *
 * In C99+ we can use generic array[x][x]
*/

int sum2d(int rows, int cols, int array[rows][cols])
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++){
        for (c = 0; c < cols; c++){
            tot += array[r][c];
        }

    }
    return tot;
}

int main() {
  size_t size = 0;
  printf("Enter the number of elements you want to store:\n");
  scanf("%zd", &size);

  float values[size];

  array(5);
  array(15);
  array(63);

  return 0;
}

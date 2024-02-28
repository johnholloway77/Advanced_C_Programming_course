#include <stdio.h>
#define PI 3.14159

#define CIRCLE_AREA(x) ((PI) * (x) * (x))
#define CIRCLE_AREA2(x) (PI * x * x)
#define CIRCLE_AREA3(x) (PI * SQUARE(x))
#define SQUARE(x) ((x) * (x))
#define WARNING(...) fprintf(stderr, __VA_ARGS__)
#define WARNING2(str, ...) fprintf(stderr, str, __VA_ARGS__)



int main() {
  printf("Creating our own Macros \n");

  int c = 3;

  int area = CIRCLE_AREA(c + 1);
  int area2 = CIRCLE_AREA2(c + 1);
  int area3 = CIRCLE_AREA3(c + 1);

  printf("Area is %d\n", area);
  printf("Area2 is %d\n", area2);
  printf("Area3 is %d\n", area3);

  WARNING("%s: this program was here\n", "John");

  WARNING("%s: this program was here %d %c %f %s\n", "John2", 5, 'c', 3.14259,
          "meow");

  return 0;
}

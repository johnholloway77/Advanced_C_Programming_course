#include <stdlib.h>
#include <stdio.h>

union car {
  int i_value;
  float f_value;
  char c_value[40];
} car4, car5, car6; // alternate method to declare union variables

typedef union {
  int i_value;
  float f_value;
  char c_value[40];
} Motorcycle; // alternate method to define a new type which is a union.

enum symbolType { TYPE_A, TYPE_B, TYPE_O };

#define SOMEVALUE 100
struct {
  char *name;
  enum symbolType type;
  union {
    int i;
    float f;
    char c;
  } data;
} table[SOMEVALUE];

union mixed {
  char c;
  float f;
  int i;
};

//union inside of a union

union vehicle{
    union car car_variable;
    Motorcycle moto_variable;
};

int main() {
  printf("Unions\n");

  union car car1, car2, *car3;

  Motorcycle moto1, moto2, moto3;

  printf("memory size occupied by data of type car union: %zu\n", sizeof(car1));
  printf("memory size occupied by data of array table: %zu\n", sizeof(table));
  printf("size of each struct in array table: %zu\n",
         sizeof(table) / SOMEVALUE);

  union mixed m;
  m.i = 5150;
  printf("value of m.1: %d\n", m.i);
  printf("value of m.f: %.2f\n", m.f);

  m.f = 51.50;
  printf(" The variable m.f = 51.50\nNotice how when we try to print the integer value, we get the binary vlaue of the float read as an int.\nThis is because m.i and m.f share the same memory location\n");
  printf("value of m.1: %d\n", m.i);
  printf("value of m.f: %.2f\n", m.f);

  union mixed *mptr = malloc(sizeof(union mixed));
  mptr->c = 'z';
    printf("value of mptr.c: %c\n", mptr->c);
  mptr->i = 5150;
    printf("Value of mptr.i: %d\n", mptr->i);



  return 0;
}

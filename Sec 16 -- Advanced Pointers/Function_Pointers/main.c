#include <stdio.h>

int someDisplay();

void funct1(int x);
void funct2(int x);

int main() {
  printf("Function Pointers\n");

  int (*func_ptr)();
  func_ptr = someDisplay;

  printf("Address of function someDisplay is %p\n", func_ptr);

  // lets invoke the funciton
  func_ptr();

  // using a typedef
  typedef void (*FuncType)(int x);

  FuncType func_ptr1 = NULL;
  func_ptr1 = funct1;

  func_ptr1(5150);

  FuncType func_ptr2 = funct2;

  func_ptr2(666);

  return 0;
}

int someDisplay() {
  puts("someDisplay!");
  return 0;
}

void funct1(int x) { printf("funct1 received the argument %d\n", x); };

void funct2(int x) { printf("funct2 received the argument %d\n", x); };

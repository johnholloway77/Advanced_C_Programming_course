#include <malloc.h>
#include <stdio.h>
#include <string.h>

void foo(int *ptr) {
  int a = 5;
  ptr = &a;
  printf("void foo: Address of local ptr = %p Value of ptr = %d\n", &ptr, *ptr);
}

void bar(int **ptr) {
  int a = 5;
  *ptr = &a;
  printf("void bar: Address of local ptr = %p Value of *ptr = %p Value of **ptr= %d\n", &ptr,
         *ptr, **ptr);
}

void foo2 (char **ptr){

    *ptr = malloc(sizeof(char) * 255);
    strlcpy(*ptr, "Hello World!", sizeof(char) * 255);
    printf("size of: %zu\n", sizeof(char) * 255);
    //strcpy(*ptr, "Hello World!");
}

int main() {
  int *ptr = NULL;
  ptr = (int *)malloc(sizeof(int));
  *ptr = 10;
  printf("Address of main ptr = %p Value of ptr = %d\n", &ptr, *ptr);
  foo(ptr);
  printf("Address of main ptr = %p Value of ptr = %d\n", &ptr, *ptr);

  bar(&ptr);
  printf("Address of main ptr = %p Value of ptr = %d\n", &ptr, *ptr);
  // int **dptr = NULL;
  // *dptr = &ptr;
  // printf("Address of main dptr = %p Value of dptr = %p\n", &dptr, *dptr);

  char *charPtr = NULL;
  //foo(charPtr);
  foo2(&charPtr);
  printf("%s\n", charPtr);

  free(charPtr);

  return 0;
}

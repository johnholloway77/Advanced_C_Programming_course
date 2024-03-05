/*

    Challenge 1: Test your understanding of double pointers (declare,
   initialize, and access)
        1. Create a normal int variable and assign it random value
        2. Create a single integer pointer variable
        3. Create a souble integer pointer variable
        4. Assign the address of the normal integer variable (step 1) to the
   single pointer (step2)
        5. Assignt the address of the single pointer (step 2) to the double
   pointer variable (step3)

    Challenge 2:
    Write a program that includes a funciton that modifies a pointer's value
    -Not the value that the pointer is pointing to, but the actual value of the
   pointer (the address that the pointer is pointing to); -Essentially
   simulating "pass by reference"

    1) Create a function naed allocateMemory that takes a single integer pointer
   as the function parameter -void allocateMemory(int *ptr); -This function
   should allocaet memory for this pointer

    2) Now create a main function that does the following:
        -Creates an integer pointer and initializes it to NULL
        -Invokes the allocateMemory function, passing the integer pointer just
   created -Assign a value to the integer pointer that it is pointing
   (de-reference) -print the value of what the pointer is pointing to
   (de-reference) -free the pointer

    3) Now modify your program to use a double pointer

       Modify the function allocateMemory to take a double pointer of type int
   as a function parameter

*/

#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int *ptr);
void allocateMemory2(int **ptr);

int main() {
  printf("Challenge Double Pointers!\n");

  puts("\nChallenge #1:");

  int x = (arc4random_uniform(1000000 - 0 + 1)) + 0;
  int *ptr;
  int **dubPtr;

  ptr = &x;
  dubPtr = &ptr;

  printf("The memory address of x is %p and the value is %d\n", &x, x);
  printf("The memory address of ptr is %p and it is pointing to %p and the "
         "object to which it's pointing has a value of %d\n",
         &ptr, ptr, *ptr);
  printf("The memory address of dubPtr is %p and it is pointing to %p. The "
         "object to which it is pointing has the memory address %p and is "
         "pointing to %p. The object to which the pointer to which the pointer "
         "is pointing is %d\n",
         &dubPtr, dubPtr, dubPtr, *dubPtr, **dubPtr);

  puts("\nChallenge 2:");

  int *iPtr = NULL;

  printf("Using allocateMemory2\n");
  allocateMemory(iPtr);

  if(iPtr != NULL){
      printf("Location of iPtr: %p Value of iPtr: %d\n", &iPtr, *iPtr);
      free(iPtr); //Will cause crash if NULL
  } else{
      puts("iPtr is NULL");
  }


  printf("Using allocateMemory2\n");
  allocateMemory2(&iPtr);
  if(iPtr != NULL){
      printf("Location of iPtr: %p Value of iPtr: %d\n", &iPtr, *iPtr);
      free(iPtr); //Will cause crash if NULL
  } else{
      puts("iPtr is NULL");
  }

  return 0;
}

void allocateMemory(int *ptr) {
  ptr = malloc(sizeof(int));
  *ptr = 10;
  printf("allocateMemory: value of *ptr: %d\n", *ptr);
};

void allocateMemory2(int **ptr) {
  *ptr = malloc(sizeof(int));
  **ptr = 10;

  printf("allocateMemory2: value of **ptr: %d\n", **ptr);
};

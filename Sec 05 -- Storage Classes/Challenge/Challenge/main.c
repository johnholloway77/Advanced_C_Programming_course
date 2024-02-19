/*
 * Challenge 3:
 * Create a C program that shares a varable amongst two files
 *
 * create a source file named main.c
 * this source should include a global variable used to iterate through a loop 5 times
 *      - inside the loop a function should be invoked (display) that is defined in another file
 *      - display function should take no prarameters.
 *
 * Create another source file named display.c
 * the display function is to be created in this file
 *  -this function displays the global variable from main.c(incremeted by 1)
 */

#include <stdio.h>

int global = 5;

extern int display(void);
extern int challenge2(void);

int main(void)
{
    challenge2();
    printf("\n");
    display();
}

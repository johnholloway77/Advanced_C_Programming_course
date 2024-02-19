/*
 *  Challenge 1:
 *  Create a small program that declares the following
 *  - an int variable with block scope & temporary storage
 *  - a global double varaible that is only accessable inside this file
 *  - a global float accessable within the entire program
 *  - a register int variable
 *  - a function that is only accessable within the file it is defined
 */

#include <stdio.h>

//global double only access file
static double db = 0.0;

//global float
float fl = 0.0; //extern by default

//function limited to file

static int getInt(void)
{
    //int w/ block scope & temp storage
    int i = 5150;

    return i;
}


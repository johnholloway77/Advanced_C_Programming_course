#include <stdio.h>



int main()
{
    const double pi = 3.141592654;

    //cant do something like this pi++;

    const float *pf; //pf points to a constant float pointer. The value of the const to which it points cannot be changed, but we can still change the address
    float * const pt = pf; // this is a constant pointer, always pointing to the same address.
    const float * const ptr; //both the address for the pointer, and the float at that address cannot change value.

    return 0;
}

void display(const int arr[], int limit); // const int arr[] will not allow the function to change the value of arr[]

char *strcat(char *restrict s1, const char *restrict s2); //the const for the second parameter means that the function can't change it.

#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo (double *input)
{
    double *twice = malloc(sizeof(double)); //variable is declared on the heap by allocating space
    *twice = *input * 2.0;  //the dereferenced pointer value is assigned.
    return twice;
}

int main(int argc, char *argv[])
{
    int *age = malloc(sizeof(int));
    *age = 30;

    double *salary = malloc(sizeof(double));
    *salary = 12345.67;

    double *myList = malloc(sizeof(double) * 3);
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;

    double *twiceSalary = multiplyByTwo(salary);

    printf("Double your salary is $%0.2f\n", *twiceSalary);

    free(age);
    free(salary);
    free(myList);
    free(twiceSalary);

    return 0;

}

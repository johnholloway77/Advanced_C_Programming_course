#include <stdio.h>
#include <stdlib.h>

void f1(int n, float *restrict a1, const float *restrict a2)
{
    int i;
    for(i = 0; i < n; i++){
        a1[i] += a2[i];
    }
}


int main()
{
    int n;
    int array[10];

    int *restrict restar = (int*)malloc(10 * sizeof(int)); //it is the only way ot access memory to which it points
    int *par = array; //cannot be qualified as restrict as it points to array;


    for (int i = 0; i < 10; i++){
        array[i] = restar[i] = 0;
    }

    for (n = 0; n < 10 ; n++){

        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;

        //  Because restar is the only way to access that memory location, the compiler can change the lines "restar[i] += 5" and "restar[i] +=3" to simply "restar[i] = 8"
        //  The compiler can do this because it has been told that restar is the only way to access this memory location, therefore there will not be another variable to change the values in a different manner
        //  like there is with array and par.
        //  for the latter, the compiler has to perform checks to ensure that it is other things isn't messing
    }

    for (int i = 0; i < 10; i++){
        printf("array: %d restar: %d\n", array[i], restar[i]);
    }


    free(restar);
    //free(par);

    return 0;
}

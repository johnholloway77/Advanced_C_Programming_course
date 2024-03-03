#include <stdio.h>
#include <stdlib.h>

char returnRandom(){
    return (rand() % (122-65 + 1) + 65);
}

int main()
{
    int array[2147486];

    printf("Test!\n");
    for(int i = 0; i < 2147486; i++){
        array[i] = returnRandom();
    }
    return 0;
}

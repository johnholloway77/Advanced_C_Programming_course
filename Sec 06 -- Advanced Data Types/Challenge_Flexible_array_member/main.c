#include <stdio.h>
#include <malloc.h>

struct myArray{
    int arraySize;
    int array[]
};

int main()
{
    size_t size;
    int x = 0;
    printf("Hello, enter the length of your flexible array !\n");
    scanf("%zd", &size);

    struct myArray *ptr = malloc(sizeof(struct myArray) + size * sizeof(int));

    while(x < size){
        printf("enter array data\n");
        scanf("%d", &ptr->array[x++]);
    }

    x = 0;
    while(x < size){
        printf("ptr[x] is %d\n", ptr->array[x++]);
    }

    free(ptr);
    return 0;
}

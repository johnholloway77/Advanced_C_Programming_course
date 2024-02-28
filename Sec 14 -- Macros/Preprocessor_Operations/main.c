#include <stdio.h>
#include <stdlib.h>

#define str(x) #x
#define HELLO(x) printf("Hello, " #x "!!!\n")

#define CONCAT(x, y) x##y
#define STRINGIFY(x) #x

//Create a function based on parameters passed in, and then anotherfunction that invokes the previous function

#define DeclareSort(prefix, type) \
    static int \
_DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) \
{ \
const type *aa; const type *bb; \
aa = a; bb = b; \
if(aa < bb) return -1; \
else if(bb < aa) return 1; \
else return 0; \
}\
\
void \
prefix ## _sort(type *a, int n)\
{\
qsort(a, sizeof(type), n, _DeclareSort_ ## prefix ## _Compare);\
}

    DeclareSort(int, int);
int main()
{
    printf("PreProcessor Operations!\n");

    puts(str(testing\n)); //str(x) will convert testing into a string literal "testing"
    HELLO(john);
    char *str1 = "Hello";
    char *str2 = "World";
    char *str = STRINGIFY(Hello) " " STRINGIFY(World);
    printf("%s\n", str);

    int x = 5;
    int *a = &x;
    int n = 6;

    int_sort(a, n);

    int y = _DeclareSort_int_Compare(a, &n);
    printf("The value of y is %d\n", y);



    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    printf("atoi()\n");

    char a[10] = "101.1";
    printf("Char a = %s\n", a);

    int value = atoi(a);

    printf("Value = %d\n", value);

    float valuef = atof(a);
    printf("valuef = %.2f\n", valuef);

    long valuel = atol(a);
    printf("valuel = %ld\n", valuel);

    char b[] = "123.456zyx", *end;
    double valued = 0;
    valued = strtod(b, &end);

    printf("valued = %lf\n", valued);

    char c[] ="365.25 7.0", *end2;
    valuef = strtof(c, &end2);
    double valuef2 = strtof(end2, NULL);

    printf("valuef = %f\nvaluef2 = %f\n", valuef, valuef2);

    char str[30] = " 2030200 This is a test";
    char *ptr = NULL;
    long ret = 0;
    ret = strtol(str, &ptr, 10);
    printf("The number (unsigned long integer is %ld\n", ret);
    printf("The string part is |%s|\n", ptr);

    puts("Random numbers");
    for(int i = 0; i < 5; i++){
        printf("%d. %d\n", i, rand() % 10 + 1);

        printf("%da. %d\n", i, arc4random());
    }


    return 0;
}

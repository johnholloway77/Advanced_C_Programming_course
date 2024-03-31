#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("General Utilities 3 !\n");

    int i;
    i = system("mkdir /tmp/data");
    printf("The result of system() function is %d\n", i);
    i = system("touch /tmp/data/test.txt");
    printf("The result of system() function is %d\n", i);

    i = system("nvim /tmp/data/test.txt");
    printf("The result of system() function is %d\n", i);

    i = system("rm /tmp/data/test.txt && rmdir /tmp/data");
    if(i == 0) puts("Tmp folder and file successfully removed");

    printf("Environment Variable \"PATH\" is %s\n", getenv("PATH"));

    printf("Environment Variable \"LOGNAME\" is %s\n", getenv("LOGNAME"));

    printf("Environment Variable \"HOME\" is %s\n", getenv("HOME"));

    printf("Environment Variable \"jholloway\" is %s\n", getenv("jholloway"));

    char s[] = "Hello my baby\nHello My darling\nHello my ragtime girl";
    char *str = strdup(s);
    puts(str);
    free(str);

    str = strndup(s, 5);
    puts(str);
    free(str);

    return 0;
}

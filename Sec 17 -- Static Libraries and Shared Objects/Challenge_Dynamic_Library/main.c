#include <stdio.h>
#include "StringFunctions.h"

int main()
{
    printf("Challenge Static Library!\n");

    puts("Test numberOfCharactersInString");
    char string[255] = "Hello World 1234";

    printf("The number of l's in %s is %d\n\n", string, numberOfCharactersInString(string, 'l'));

    puts("Test removeNonAlphaCharacters()");

    removeNonAlphaCharacters(string);
    printf("%s\n\n", string);

    puts("test lengthOfString()");
    printf("The length of %s is %d \n\n", string, lengthOfString(string));

    puts("Test strCopy()");
    char strDest[250] = "\0";
    char strDest2[250] = "\0";

    printf("Copying %s into strDest\n", string);
    strCopy(string, strDest);
    printf("Value of strDest is %s \n\n", strDest);

    puts("Test strConcat()\nConcating \"Hello World\" into strDest");
    strConcat(strDest, "Hello World");
    printf("Value of strDest is %s \n\n", strDest);

    puts("Test substring()");
    printf("Get substring of %s starting at index %d for %d characters\n", "Hello World!", 2, 8);
    substring("Hello World", 2, 8, strDest2);
    printf("Value of strDest2 is %s \n", strDest2);


    return 0;
}

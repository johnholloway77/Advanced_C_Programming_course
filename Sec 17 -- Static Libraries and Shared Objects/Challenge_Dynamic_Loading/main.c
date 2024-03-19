/*
    Challenge:
    Dynamically load the symbols from the shared object library lib_stringfunctions.so created in the previous challenge.
    -Create another program that uses dlopen and dlsym funcitons
    -convert your driver program (main.c) from the last challenge to dynamically load all the string functions in the shared object.

    Make sure to use absolute path for shared object filename
    Create funciton pointers for all 6 functions

    //set up function pointers
    int (*numChars)(char *, char);
    int (*removeNonAlpha)(char *);
    int (*lengthStr)(char *);
    int (*strConcat)(char *, char *);
    int (*strCopy)(char *, char *);
    int (*substring)(char *, int, int, char *);

*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{

    void *handle = NULL;
    char *error = NULL;

    //set up function pointers
    int (*numChars)(char *, char) = NULL;
    int (*removeNonAlpha)(char *) = NULL;
    int (*lengthStr)(char *) = NULL;
    int (*strConcat)(char *, char *) = NULL;
    int (*strCopy)(char *, char *) = NULL;
    int (*substring)(char *, int, int, char *) = NULL;

    printf("Challenge Dynamic Loading!\n");

    handle = dlopen("/home/jholloway/WorkSpace/Advanced_C_Programming_course/Sec 17 -- Static Libraries and Shared Objects/Challenge_Dynamic_Library/libStringFunctions.so", RTLD_LAZY);

    if(!handle){
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror();

    numChars = dlsym(handle, "numberOfCharactersInString");
    removeNonAlpha = dlsym(handle, "removeNonAlphaCharacters");
    lengthStr = dlsym(handle, "lengthOfString");
    strConcat = dlsym(handle, "strConcat");
    strCopy = dlsym(handle, "strCopy");
    substring = dlsym(handle, "substring");

    if((error = dlerror()) != NULL){
        fputs(error, stderr);
        exit(1);
    }

    puts("Test numChars");
    char string[255] = "Hello World 1234";
    printf("The number of l's in %s is %d\n\n", string, numChars(string, 'l'));

    puts("Test removeNonAlpha");

    removeNonAlpha(string);
    printf("%s\n\n", string);

    puts("test lengthStr");
    printf("The length of %s is %d \n\n", string, lengthStr(string));

    puts("Test strCopy");
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



    dlclose(handle);
    return 0;
}

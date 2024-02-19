/*
    Write a C program to conver uppercase to lowercase and vice versal
    The program can either take a command line argument for the name of a file, or if one isn't provided
    as the user for the name of the file.

    You will need to create a temporary file to store the result.
        -Can then rename this temporary file back to the original fle.
    Will need ot use isupper(ch) to check for upper and lower case, and use tolower & to upper.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 256

int main(int argc, char *args[]) {
    char ch = '.';
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    char fileName[256];

    if (argc < 2) {
        printf("Please enter the address for your file\n");
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = '\0';

    }
    if (argc == 2) {
        printf("using file name!\n");


        strlcpy(fileName, args[1], sizeof(fileName));

    }
    if (argc > 2) {
        printf("Only one argument allowed jackass!\n");
    }

    //printf("filename entered: %s\n", fileName);

    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    fp2 = fopen("./temp", "w");
    if(fp2 == NULL){
        printf("Error opening new file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF){

        if(isupper(ch)){
            putc(tolower(ch), fp2);
        }
        else{
            putc(toupper(ch), fp2);
        }


    }

    fclose(fp);
    fclose(fp2);


    return 0;
}

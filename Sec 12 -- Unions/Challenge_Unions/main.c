/*

    Challenge Unions:
    Write a program which will define a union and then use this union to assign and access its members

    Define a union named student that consists of the following three elements
        -char letterGrade
        -int roundedGrade
        -float exactGrade

    Program should declare two variables inside the main method
        -variable_1
        -variable_2

    Your program hsould assign random values to variable_1
        -Print these values and you'll notice something is wrong.

    Your program should then assign a value to each of variable_2's members and print them out sequentially.

    Why will there be differences?


Example output:
    Union record1 values example:
    Letter Grade  :
    Rounded Grade   : 1118622984
    Exact Grade : 86.50000

    Union record 2 values example
    Letter Grade    :A
    Rounded Grade   :100
    Exact Grade 99.50000

*/

#include <stdio.h>

typedef union{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
} Student;

int main()
{
    printf("Challenge Unions\n");

    Student variable_1, variable_2;

    variable_1.letterGrade = 'B';
    variable_1.roundedGrade = 87;
    variable_1.exactGrade = 86.5;
    puts("");
    puts("Union record1 value exmaple:");
    printf("LetterGrade: %c\n", variable_1.letterGrade);
    printf("RoundedGrade: %d\n", variable_1.roundedGrade);
    printf("ExactGrade: %f\n", variable_1.exactGrade);



    puts("");
    puts("Union record2 value exmaple:");
    variable_2.letterGrade = 'A';
    printf("LetterGrade: %c\n", variable_2.letterGrade);
    variable_2.roundedGrade = 100;
    printf("RoundedGrade: %d\n", variable_2.roundedGrade);
    variable_2.exactGrade = 99.5;
    printf("ExactGrade: %f\n", variable_2.exactGrade);


    puts("");
    puts("Variable 1 looks all weird because the memory adderss is constantly being over written with different data types, ending with the union being assigned a float value. This value cannot be read as an 8 bit char character, nor will its binary values equal the same numerical value when read as an int");
    return 0;
}

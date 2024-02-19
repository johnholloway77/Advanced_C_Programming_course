/*

 challenge:
    write a program to input any number from a user.
    the program should check whether the nth bit of a given number is set(1) or not
    the program should set the nth bit to the given number as 1


*/

#include <stdio.h>

int main()
{
    unsigned int num;
    unsigned int num2;
    unsigned char n;
    printf("Please enter a number between 0 to 4,294,967,295\n");
    scanf("%u", &num);
    printf("Please enter a position to check for on (0 - 31)\n");
    scanf("%hhu", &n);

    while (n > 31){
        printf("Please enter a position to check for on (0 - 31)\n");
        scanf("%hhu", &n);
    }

    printf("The %hhu bit is set to %d\n", n, (num >> n) & 0x1);

    num2 = num | (0x1 << n);
    printf("Bit set successfully\n");
    printf("Number before setting %d bit: %d (in decimal)\n", n, num);
    printf("Number after setting %d bit: %d (in decimal)\n", n, num2);


    return 0;
}

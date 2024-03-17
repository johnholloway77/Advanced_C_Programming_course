/*
    Create a C source file named StringFunctions.c

    Should contain functions to perform the following string manipulations
    -Find the frequency of characters in a string
    -Remove all the chars in a String except Alphabets
    -Calculate the length of a string without using strlen
    -Concat two strings without using strcat
    -copy a string manually without using strcpy
    -find the substring of a given string

*/

#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

/*
 * str - string to search
 * searchChar - character to look for
 * return type - int : count for the number of times that character was found
 */

int numberOfCharactersInString(char *str, char searchChar);

/*
 * source - source string
 * return type - int : 0 on success
 */
int removeNonAlphaCharacters(char *source);

/*
 * source - source string
 * return type - int : lenth of string
 */
int lengthOfString(char *source);

/*
 * str1 - string to concatenate to (resulting string)
 * str2 - second string from which to concatenate
 * return type - int: 0 on success
 */
int strConcat(char *str1, char *str2);

/*
 * source - string to cpy from
 * destination - second string to copy to
 * return type - int: 0 on success
 */
int strCopy(char *source, char *destination);

/*
 * source - source string
 * from -starting index from where you want to get substring
 * n - number of characters to be copied in substring
 * target - target string in which you want to store target string
 * return type - int: 0 on success
 */
int substring(char *source, int form, int n, char *target);

#endif // STRINGFUNCTIONS_H

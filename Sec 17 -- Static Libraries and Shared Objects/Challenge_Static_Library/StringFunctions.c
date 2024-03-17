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


int numberOfCharactersInString(char *str, char searchChar) {
  int n = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == searchChar)
      n++;
  }
  return n;
};

/*
 * source - source string
 * return type - int : 0 on success
 */
int removeNonAlphaCharacters(char *source) {
  char str[255] = "\0";
  int i = 0;
  int k = 0;

  while (source[i] != '\0') {
      if ((source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= 'a' && source[i] <= 'z')) {
      str[k] = source[i];
        k++;
    }
    i++;
  }

  for (i = 0; str[i] != '\0'; i++) {
    source[i] = str[i];
  }
  source[i] = '\0';

  return 0;
};

/*
 * source - source string
 * return type - int : lenth of string
 */
int lengthOfString(char *source) {
  int n = 0;
  while (source[n] != '\0') {
    n++;
  }
  return n;
};

/*
 * str1 - string to concatenate to (resulting string)
 * str2 - second string from which to concatenate
 * return type - int: 0 on success
 */
int strConcat(char *str1, char *str2){
    int i = 0;
    int j = 0;
    while(str1[i] != '\0'){
        i++;
    }

    while(str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    return 0;
};

/*
 * source - string to cpy from
 * destination - second string to copy to
 * return type - int: 0 on success
 */
int strCopy(char *source, char *destination){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';

    return 0;
};

/*
 * source - source string
 * from -starting index from where you want to get substring
 * n - number of characters to be copied in substring
 * target - target string in which you want to store target string
 * return type - int: 0 on success
 */
int substring(char *source, int from , int n, char *target){
    int i = 0;
    while (i < n){
        target[i] = source[from + i];
        i++;
    }
    target[i] = '\0';

    return 0;
};

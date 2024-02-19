#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = NULL;
  char ch[100];
  char string[100];
  int a = 10, b = 20, c = 0;
  c = a + b;

  sprintf(string, "Sum of %d and %d is %d", a, b, c);
  puts(string);

  if ((f = fopen("../Formatting_Functions/test.txt", "w")) == NULL) {
    printf("Couldn't open file\n");
    return 1;
  }

  for (int i = 0; i < 10; i++) {
    fprintf(f, "The count number is %d\n", i);
  }

  fclose(f);

  if ((f = fopen("../Formatting_Functions/test.txt", "r+")) == NULL) {
    fprintf(stderr, "Couldn't open file\n");
    return 1;
  }

  puts("File content is:");

  while (!feof(f)) {
    fgets(ch, 100, f);
    printf("%s", ch);
  }

  fclose(f);

  FILE *fp = NULL;
  char buff[256];

  if ((fp = fopen("../Formatting_Functions/test.txt", "r")) == NULL) {
    fprintf(stderr, "could not read file");
  }

  int i = 1;
  while (fscanf(fp, "%s", buff) != EOF) {
    printf("%d %s\n", i++,
           buff); // notice how it scans the file until a space is reached.
  }

  fclose(fp);


  char *str = "Jason Instructor 43"; //you could use getline to get an entire line like this
  char name[50];
  char title[50];
  int age = 0;
  int ret = 0;

  ret = sscanf(str, "%49s %49s %d", name, title, &age); //the "%s %s %d" splits the string on the spaces. However, we need to know how many spaces are in the line
  printf("Name: %s\n", name);
  printf("Title: %s\n", title);
  printf("Age: %d\n", age);

  return 0;
}

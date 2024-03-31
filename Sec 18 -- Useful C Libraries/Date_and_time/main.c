#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  clock_t start, end, total;

  printf("Date and Time\n");

  printf("CLOCKS_PER_SEC is: %d\n", CLOCKS_PER_SEC);
  start = clock();
  int evencount = 0;
  for (int i = 0; i < 100000000; i++) {
    if (i % 2 == 0)
      evencount++;
  }

  printf("evencount %d\n", evencount);
  end = clock();
  total = end - start;
  printf("end: %d\n", end);
  printf("Total process time is: %f\n", (double)total / CLOCKS_PER_SEC);

  start = clock();
  evencount = 0;
  for (int i = 0; i < 100000000; i++) {
    if (!(i & 1))
      evencount++;
  }

  printf("evencount %d\n", evencount);
  end = clock();
  total = end - start;
  printf("end: %d\n", end);
  printf("Total process time is: %f\n", (double)total / CLOCKS_PER_SEC);

  char time_str[30] = {'\0'};
  time_t calendar = time(NULL);
  printf("%s", ctime(&calendar));

  // alternate method
  strlcpy(time_str, ctime(&calendar), sizeof(time_str));

  printf("time_str = %s", time_str);

  struct tm *timedata;
  const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  const char *suffix[] = {"st", "nd", "rd", "th"};

  timedata = localtime(&calendar);

  printf("Today is %s %s %d %d\n", days[timedata->tm_wday], months[timedata->tm_mon], timedata->tm_mday, timedata->tm_year + 1900);


  time_t time_ptr;
  time(&time_ptr);
  printf("Current date and time = %s", asctime(localtime(&time_ptr)));

  struct tm birthday = {0};
  char name[30] = {'\0'};
  printf("Enter a name ");
  scanf("%s", name);

  printf("Enter the birthday for %s as day month year integers separeted by spaces.\n", name);

  scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);
  birthday.tm_mon -=1;
  birthday.tm_year -= 1900;

  if(mktime(&birthday) == -1){
      fprintf(stderr, "Shit's fucked!\n");
      exit(1);
  } else{
      printf("%s was born on %s", name, asctime(&birthday));

  }



  return 0;
}

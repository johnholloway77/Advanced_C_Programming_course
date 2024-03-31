/*
  Challenge 1 random numbers:
    Write a program that generates 50 random numbers between -0.5 and 0.5
    -The first line of output should be the number of data
    -The next 50 lines should be the 50 random numbers.
    You are required to use the srand function, passing in the time function
        -as a seed to using the rand() function.

    Challenge 2 quicksort algorithm:
    Write a program which sorts and array of doubles from lowest to highest
  using the qsort function. Create a function that takes a double array and a
  size parameter which generates some random doubles. -void fillarray((double
  ar[], int n); Create a function that displays the array -void showarray(const
  double ar[], int n); sort it with q sort(will need to make a comparator) and
  display the sorted array.


    Challenge 3: Time
    Write a program to print the current time
    -use time() and ctime() functions
    -handle errors with fprintf() and exit();

    Challenge 4: Time 2
    Write a program that will computer the number of seconds passed since the
    beginning of the current month
        -You should use the localtime, difftime, and mktime functions
        -you should handle errors with fprintf and exit functions

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fill_array(double ar[], int n);
void display_array(const double ar[], int n);
int comparator(const void *p1, const void *p2);

int main() {
  printf("Challenge!\n");
  clock_t start;
  clock_t end;
  clock_t completion_time;

  start = clock();
  puts("Challenge 1: Write a program that generates 50 random numbers between "
       "-0.5 and 0.5");
  int rand_count = 50;
  double min = -0.5;
  double max = 0.5;
  double random_number = 0.0;
  double arc4random_number = 0.0;

  srand(time(0)); // seed rand

  for (int i = 0; i < rand_count; i++) {
    random_number = ((double)rand() / RAND_MAX) * (max - min) + min;
    arc4random_number =
        (arc4random_uniform(10000) / 10000.0) * (max - min) + min;
    printf("rand: %1.5f arc4random: %1.5f\n", random_number, arc4random_number);
  }
  end = clock();

  completion_time = end - start;
  printf("Challenge 1 took %d cycles and a total of %1.5f seconds\n\n",
         completion_time, (double)completion_time / CLOCKS_PER_SEC);

  puts("Challenge 2: Using quicksort algorthm");

  start = clock();

  int ar_length;
  // ar_length = 8388608;
  ar_length = 100000;

  // create an array with a variable array length using malloc
  double *ar = (double *)malloc(ar_length * sizeof(double));
  if (ar == NULL) {
    fprintf(stderr, "Could not allocate memory for variable ar\n");
    exit(1);
  }

  fill_array(ar, ar_length);
  display_array(ar, ar_length);

  qsort(ar, ar_length, sizeof(ar[0]), comparator);
  // heapsort(ar, ar_length, sizeof(ar[0]), comparator);

  display_array(ar, ar_length);

  end = clock();
  completion_time = end - start;

  free(ar);

  printf("Challenge 2 took %d cycles and a total of %1.5f seconds\n\n",
         completion_time, (double)completion_time / CLOCKS_PER_SEC);

  puts("Challenge 3: Time!");

  time_t unix_time = 0;
  unix_time = time(NULL);

  if (unix_time == 0) {
    fprintf(stderr, "error getting time(NULL)\n");
    exit(1);
  } else {
    printf("It has been %ld seconds since the unix epoch\n", unix_time);
  }

  char current_time[26] = {'\0'};
  if (ctime(&unix_time) == NULL) {
    fprintf(stderr, "Error getting value from ctime()\n");
    exit(1);
  } else {
    strlcpy(current_time, ctime(&unix_time), sizeof(current_time));
    printf("%s\n", current_time);
  }

  puts("Challenge 4: Time 2");

  time_t current_time_t, month_begin_time_t;
  struct tm *current_tm;
  struct tm *month_begin_tm = (struct tm *)malloc(sizeof(struct tm));

  current_tm = localtime(&unix_time);


    month_begin_tm->tm_year = current_tm->tm_year;
    month_begin_tm->tm_mon = current_tm->tm_mon;

  month_begin_tm->tm_mday = 1;
  month_begin_tm->tm_sec = 0;
  month_begin_tm->tm_min = 0;
  month_begin_tm->tm_hour = 0;

  month_begin_time_t = mktime(month_begin_tm);
  current_time_t = mktime(current_tm);

  char month_begin_str[26] = {'\0'};
  char current_str[26] = {'\0'};


  //copy the return values of asctime to their respective strings
  //invoking the two inside of the printf() function will cause the pointer
  //value returned to be overwritten by the second invocation.
  strlcpy(month_begin_str, asctime(month_begin_tm), sizeof(month_begin_str));
  strlcpy(current_str, asctime(current_tm), sizeof(current_str));


  printf("The difference in seconds between:\n %s\tand\n %sis %.1f\n",
         month_begin_str, current_str,
         difftime(current_time_t, month_begin_time_t));

  free(month_begin_tm);

  return 0;
}

void fill_array(double ar[], int n) {
  double min = -10000000.0;
  double max = 10000000.0;
  double random = 0.0;

  for (int i = 0; i < n; i++) {
    ar[i] =
        ((double)arc4random_uniform(UINT32_MAX) / UINT32_MAX) * (max - min) +
        min;
  }
}

void display_array(const double ar[], int n) {

  for (int i = 0; i < n; i++) {
    printf("%7.5f ", ar[i]);
  }
  printf("\n");
}

int comparator(const void *p1, const void *p2) {

  const double d1 = *(const double *)p1;
  const double d2 = *(const double *)p2;

  if (d1 < d2)
    return -1;
  if (d1 > d2)
    return 1;

  return 0;
}

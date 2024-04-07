/*
 Challenge 1
    test your understanding of threads
    -creating, exiting, joining threads and passing arguments.

    write a program in whcih multiple threads prints a message.
    -Create 10 seperate 10s and have heach thread call one function


    Update: As a test, don't use mutexes to synch data
*/

#include <pthread.h>
#include <stdio.h>
#include <sys/thr.h>
#include <unistd.h>

pthread_mutex_t lock;
int counter = 0;

void *increase_count(void *ptr);

int main() {
  printf("Challenge 1!\n");
  pthread_t threads[10];

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < 10; ++i) {
    pthread_create(&threads[i], NULL, increase_count, (void *)i);
  }

  //

  for (int i = 0; i < 10; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("\nAll threads finished executing\ncounter value %d\n", counter);

  return 0;
}

void *increase_count(void *ptr) {
  int index = (int)ptr;
  long thread_id;
  thr_self(&thread_id);
  printf("Inxex %d, thread id %ld counter: %d\n", index, thread_id, counter);
  //pthread_mutex_lock(&lock);
  counter++;
  //pthread_mutex_unlock(&lock);

  printf("Index %d, thread id: %ld has increased counter to %d\n", index,
         thread_id, counter);
  pthread_exit(NULL);
}

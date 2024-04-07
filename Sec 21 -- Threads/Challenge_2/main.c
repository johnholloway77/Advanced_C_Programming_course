/*
 Challenge 2: threads & mutexes
   You will make sure that the data is shared between threads is mutually exclusive
when updated and when read

*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/thr.h>

pthread_mutex_t lock;
int counter = 0;

void *increase_counter(void *ptr);

int main()
{
    printf("Challenge 2!\n");

    pthread_t threads[10];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 10; ++i) {
        pthread_create(&threads[i], NULL, increase_counter, (void *) i);
    }

    for(int i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Threads completed execution. Final counter vale %d\n", counter);

    return 0;
}


void *increase_counter(void *ptr){

    int index = (int)ptr;
    long thread_id;
    thr_self(&thread_id);

    pthread_mutex_lock(&lock);

    printf("Index %d thread id %ld counter value %d\n", index, thread_id, counter);

    counter++;

    printf("index %d thread id %ld counter increased to %d\n", index, thread_id, counter);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);

}

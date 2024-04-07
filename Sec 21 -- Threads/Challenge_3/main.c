/*
    Challenge 3: threads & conditional variables

    We will modify the program from challenge 2 so that certain threads execute
    critical sections beofre others do.

    This program should print messages from threads that pass an even number first (parameter)
    and those that pass an odd number after all the evens have been printed
    -We must have the odd threads wait until all the even threads have printed
    -We do not care about the order of the invididual threads, only that they are grouped even/odd.

    odd threads will sleep until a condition is met.
    Condition variables are always associated with locks because the shared information that they depend
    on must be synchronized across threads

    Use pthread_cond_wait and pthread_cond_broadcast

    Use a global variable that indicates when all even threads have finished
    -int number_evens_finished = 0; (shared data amongst threads)
    -you can increment the global variables for each even thread and signal the other threads
    when this count is even to NUM_THREADS/2

    You can check if numbers are even by using the modulus operator

    You can use the sleep(1) call after all threads have been created and are running before checking if
    even threads have finished

*/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/thr.h>

#define THREAD_COUNT 10

pthread_mutex_t lock;
pthread_cond_t cond;

int thr_counter = 0;

int counter = 0;

void *increase_counter(void *ptr);

int main()
{
    printf("Callenge 3!\n");
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);



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

    while(1){
        long index = (long)ptr;
        long thread_id;
        thr_self(&thread_id);

        pthread_mutex_lock(&lock);

        if(index & 1){
            while(thr_counter < THREAD_COUNT/2){
                pthread_cond_wait(&cond, &lock);
            }
        }

        printf("Index %d thread id %ld counter value %d\n", index, thread_id, counter);

        counter++;

        printf("index %d thread id %ld counter increased to %d\n", index, thread_id, counter);

        thr_counter++;
        pthread_mutex_unlock(&lock);

        if(thr_counter >= THREAD_COUNT /2){
            pthread_cond_broadcast(&cond);
        }

        pthread_exit(NULL);
    }

}


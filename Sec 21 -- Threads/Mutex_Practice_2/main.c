#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/thr.h>

#define NTHREADS 10

void *thread_function(void *);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;


int main()
{
    printf("Mutex Practice 2\n");

    pthread_t thread_id[NTHREADS];

    int i, j;

    for(i = 0; i < NTHREADS; i++){
        pthread_create(&thread_id[i], NULL, thread_function, NULL);
    }


    for (int i = 0; i < NTHREADS; ++i) {
        pthread_join(thread_id[i], NULL);
    }


    printf("Final counter value %d\n", counter);

    return 0;
}

void *thread_function(void *dummyPtr){
    long id;
    thr_self(&id);
    printf("Thread number %ld\n", id);

    pthread_mutex_lock(&mutex1);
    counter++;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

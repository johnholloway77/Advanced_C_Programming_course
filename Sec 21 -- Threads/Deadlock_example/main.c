#include <stdio.h>
#include <pthread.h>
#include <sys/thr.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;


void *resource1(){
    pthread_mutex_lock(&lock1);
    printf("Job started in resource1...\n");
    sleep(2);

    printf("Trying to get resource2\n");
    pthread_mutex_lock(&lock2);
    printf("Aqquired resource2\n");
    pthread_mutex_unlock(&lock2);

    printf("Job finished in resource 1...\n");

    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);

}


void *resource2(){
    pthread_mutex_lock(&lock2);
    puts("Job started in resource 2");
    sleep(2);

    puts("Trying to get resource1");

    //pthread_mutex_lock will create a deadlock
    //pthread_mutex_lock(&lock1);

    //use pthread_mutex_trylock() instead

    while(pthread_mutex_trylock(&lock1)){
        //unlock our resource so it is not being held up while we wait for lock
        puts("Unable to get lock1. Will attempt in 2 seconds");
        pthread_mutex_unlock(&lock2);

        sleep(2); //let time pass before locking & trying again
        pthread_mutex_lock(&lock2);

    }
    puts("Got resource1");


    pthread_mutex_unlock(&lock1);

    puts("Job finished in resource 2");

    pthread_mutex_unlock(&lock2);
    pthread_exit(NULL);

}

int main()
{
    printf("Deadlock exampled!\n");


    pthread_mutex_init(&lock1, NULL);

    pthread_mutex_init(&lock2, NULL);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, resource1, NULL);
    pthread_create(&t2, NULL, resource2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    return 0;
}

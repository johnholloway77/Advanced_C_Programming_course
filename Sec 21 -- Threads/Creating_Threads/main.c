#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *hello_fun(){
    printf("hello world!\n");
    for (int i = 0; i < 5; ++i) {
        printf("Thread 2: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    printf("Creating threads \n");

    pthread_t thread = 0;
    pthread_create(&thread, NULL, hello_fun, NULL);
    for (int i = 0; i < 5; ++i) {
        printf("Thread 1: %d\n", i);
        sleep(1);
    }
    pthread_join(thread, NULL);


    pthread_exit(NULL);



    return 0;
}

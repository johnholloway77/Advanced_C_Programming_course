#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *my_function(void* ptr){
    while(1){
        printf("Thread is running\n");
        sleep(1);
    }

    pthread_exit(NULL);
}

int main()
{
    printf("pthread_cancle\n");

    pthread_t thread = NULL;

    pthread_create(&thread, NULL, my_function, NULL);

    sleep(5); //let the thread run for a while

    pthread_cancel(thread);


    pthread_join(thread, NULL);

    printf("Thread canceled\n");

    return 0;
}

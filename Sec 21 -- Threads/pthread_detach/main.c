#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *threadFn(void *arg){
    pthread_detach(pthread_self());

    sleep(1);
    printf("Thread fn\n");
    pthread_exit(NULL);

}


int main()
{
    printf("pthread_detach()\n");

    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFn, NULL);

    if(ret != 0) {
        perror("Thread creation error\n");
        exit(1);
    }

    printf("After thread created in Main\n");
    pthread_exit(NULL);

    return 0;
}

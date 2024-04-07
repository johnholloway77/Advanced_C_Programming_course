#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/thr.h>

pthread_attr_t attr;

void *dowork(void *threadId){
    long tid;
    size_t mystacksize;


    tid = (long)threadId;
    thr_self(&tid);
    pthread_attr_getstacksize(&attr, &mystacksize);

    printf("Thread %ld: stack size = %li bytes \n", tid, mystacksize);
    pthread_exit(NULL);
}


int main()
{
    printf("Thread Stack Size\n");

    pthread_t myThread;
    size_t stacksize;
   // pthread_t myId;
    int myId;
    long t = 5;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("Default stacksize is %li\n", stacksize);

    stacksize = 9000000;

    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);

    printf("Creating thread with stacksize = %li bytes\n", stacksize);

    myId = pthread_create(&myThread, &attr, dowork, (void *)t);

    if(myId){
        printf("Error: return code from pthread_create() is %d\n", myId );
        exit(-1);
    }

    pthread_exit(NULL);

    return 0;
}

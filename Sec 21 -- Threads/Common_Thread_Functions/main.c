#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/thr.h>

void *calls(void *ptr){
    //using pthread_self() to get current thread id
    printf("In function \nthread id = %ld\n", (long)pthread_self());
    printf("In function \nthread id = %p\n", pthread_self());
    long tid;
    thr_self(&tid);
    printf("return value of thr_self(): %d\n", (int)tid);
    printf("return value of thr_self(): %d\n", tid);
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    printf("Common Thread Functions\n");


    pthread_t thread; //declare thread
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main \nthread id = %ld\n", (long)pthread_self());
        printf("In main \nthread id = %p\n", pthread_self());
    long tid;
    thr_self(&tid);
    printf("main: return value of thr_self(): %d\n", (int)tid);

    pthread_join(thread, NULL);


    return 0;
}

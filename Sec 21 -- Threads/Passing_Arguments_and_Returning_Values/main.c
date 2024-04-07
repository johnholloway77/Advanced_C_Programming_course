#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *print_message_function(void *ptr);



int main()
{
    printf("Passing arguments and returning values!\n");

    pthread_t thread1, thread2;

    char *message1 = "Thread 1";
    char *message2 = "Thread 2";

    int iret1, iret2;

    //create independent threads each will execute function

    iret1 = pthread_create(&thread1, NULL, print_message_function, (void *)message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*)message2);

     /*
      * Wait till threads are complete before main continues.
      * Unless we wait, we run the rist of executing an exit which will terminate
      * the processes and all of the threads before threads have finished.
    */

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);


    return 0;
}


void *print_message_function(void *ptr){
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}

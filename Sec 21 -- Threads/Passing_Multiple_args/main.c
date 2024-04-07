#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>

struct thread_data{
    int thread_id;
    int sum;
    char *message;
};

void *printHello(void *thread_arg){
    struct thread_data *my_data;

    int taskid = 0;
    int sum = 0;

    char hello_msg[255];

    my_data = (struct thread_data*) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strlcpy(hello_msg, my_data->message, sizeof(hello_msg));
    printf("taskid = %d, sum = %d, message = %s\n", taskid, sum, hello_msg);
}


int main()
{
    printf("Passing multiple arguments!\n");


    pthread_t my_thread;
    struct thread_data my_thread_data;

    my_thread_data.message = malloc(sizeof(char) * 255);
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Hello World!";

    int my_id = pthread_create(&my_thread, NULL, printHello, (void*) &my_thread_data);

    pthread_join(my_thread, NULL);
    pthread_exit(NULL);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *hello_return(void *args){
    //allocate a new string on the heap with "hello world"
    char *hello = strdup("Hello World!");
    return (void*) hello;
}


int main()
{
    printf("returning values\n");

    char *str;

    pthread_t thread; //thread identifer

    //createa new therad that runs hello return without arguments
    pthread_create(&thread, NULL, hello_return, NULL);

    //wait until thread has completed, assign its value to str
    pthread_join(thread, (void **) &str);
    //pthread_exit(NULL);

    printf("%s\n", str);


    return 0;
}

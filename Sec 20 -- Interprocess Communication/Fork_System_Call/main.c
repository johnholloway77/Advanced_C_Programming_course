#include <stdio.h>
#include <string.h>>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 100
#define BUF_SIZE 100


int main()
{

    printf("fork() yeah!\n");

    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();

    for (int i = 0; i < MAX_COUNT; ++i) {
        sprintf(buf, "This line is from pid %d, value %d\n", pid, i);
        write(1, buf, strlen(buf));
        /*
         * We use write() because printf() is buffered meaning that output of a process is grouped together
         * Using write() will print to console as the output is generated. allowing for it to intermix if occured
         */
    }



    return 0;
}

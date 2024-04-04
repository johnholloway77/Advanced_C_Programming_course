#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Interprocess Communication\n");

    int mypid, myppid;
    printf("Program to know PID and PPID's info\n");

    mypid = getpid();
    myppid = getppid();

    printf("My process ID is: %d\n", mypid);
    printf("My parent process id is %d\n", myppid);

    printf("Cross verification of PIDs by executing process commands on shell\n");
    system("ps -ef");



    return 0;
}

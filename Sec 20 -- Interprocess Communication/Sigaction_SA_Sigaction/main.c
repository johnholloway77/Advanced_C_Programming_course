#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

//handler takes three parameters because we're using sigaction
static void hdl(int sig, siginfo_t *siginfo, void *context){
    printf("Sending pid: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main(int argc, char *argv[])
{


    printf("Sigaction!\n");


    struct sigaction act;

    memset(&act, '\0', sizeof(act));

    /*
     * use the sa sigaction field because the handles has two additional parameters
     * hdl constains a siginfo_t and a void pointer, see the function prototype
    */

    act.sa_sigaction = &hdl;
    act.sa_flags = SA_SIGINFO;

    // if(sigaction(SIGTERM, &act, NULL) < 0){
    //     perror ("sigaction");
    //     return 1;
    // }

    if(sigaction(SIGINT, &act, NULL) < 0){
        perror ("sigaction");
        return 1;
    }

    while(1){
        sleep(3);
        printf("nada\n");
    }

    return 0;
}

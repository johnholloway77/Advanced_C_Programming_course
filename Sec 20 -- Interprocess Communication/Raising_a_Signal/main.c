#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void catch (int signum) {
  printf("Look, I caught a signal!\n");
  printf("Caught signal: %d - %s\n", signum, strsignal(signum));
  exit(0);
}

void handler_divideByZero(int signum);

int main() {
  printf("Raising a Signal!\n\n");
  printf("Set a signal with alarm(3)");

  // need to catch SIGALRM or process terminates

  // handle signal

  // signal(SIGALRM, catch); //call catch function
  signal(SIGALRM, SIG_IGN); // ignore signal

  alarm(3);

  // count to 3
  for (int i = 0; i < 3; i++) {
    printf("%d\n", i);
    sleep(1); // sleep for 1 second
  }

  printf("If you see this the alarm signal was ignored\n");

  printf("lets deal with a divide by zero signal\n");

  int result = 0;
  int v1 = 0, v2 = 0;

  void (*sigHandlerReturn)(int);

  sigHandlerReturn = signal(SIGFPE, handler_divideByZero);

  result = v1 / v2;

  if (sigHandlerReturn == SIG_ERR) {
    perror("Signal Error: ");
    return 1;
  }


  printf("Result of divide by zero is %d\n", result);

  return 0;
}

void handler_divideByZero(int signum) {

  printf("received %d - %s - %s\n", signum, sys_signame[signum],
         strsignal(signum));
    exit(0);
}

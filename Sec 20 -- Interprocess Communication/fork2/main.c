#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 100

void childProcess(void);
void parentProcess(void);

int main(void) {
  printf("Fork() 2: Electric Boogaloo!\n");
  pid_t pid;

  pid = fork();

  if (pid == 0)
    childProcess();
  else if (pid > 0)
    parentProcess();
  else {
    printf("fork() failed!\n");
    return 1;
  }

  return 0;
}

void childProcess(void){
    for (int i = 0; i < MAX_COUNT; ++i) {
        printf("this line is from child, value = %d\n", i);
    }
    printf("***Child process is done ***\n");
}

void parentProcess(void){
    for (int i = 0; i < MAX_COUNT; ++i) {
        printf("\tThis line is from parent process, value = %d\n", i);
    }
    printf("--- parent Process is done ---\n");
}

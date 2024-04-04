/*
    Challenge 2: Forking

    Need to create a program to create one parent and three children processes
   (total four processes)'

    Your program should contain output that identifies each parent and each
   child -output = Parent, First Child, Second Child, Third Child,

    Utilize the getpid() and getppid() functions to display each pid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  system("clear");
  printf("Challenge 2: forking!\n\n");

  pid_t pid1;

  pid1 = fork();
      //pid2 = fork();

  if (pid1 == 0) {

   // pid2 = fork();
      pid1 = fork();

    if (pid1 == 0) {
      printf("Third child! Child of Child!\tpid = %d ppid = %d\n", getpid(),
             getppid());
    } else if (pid1 > 0) {
      printf("First child! Child of Parent!\tpid = %d, parent pid = %d\n",
             getpid(), getppid());
    }
  } else if (pid1 > 0) {


      pid1 = fork();

    if (pid1 == 0) {
      printf("Second child! Child of Parent!\tpid = %d, parent pid = %d\n",
             getpid(), getppid());
    } else if (pid1 > 0) {
      printf("Parent process! Both pids greater than 0."
             "\tpid = %d, parent pid = %d\n",
             getpid(), getppid());
    }
  }

  return 0;
}

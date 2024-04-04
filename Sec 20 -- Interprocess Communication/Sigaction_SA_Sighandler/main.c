#include <signal.h>
#include <stdio.h>

// handler only takes one it as parameter as we are using sa_handler
void termination_handler(int signum) {
  struct temp_file *p;

  // before termination we are doing clean up
  for (p = temp_file_list; p; p = p->next)
    unlink(p->name);
}

int main() {
  printf("sigaction()!\n");

  struct sigaction new_action, old_action;

  // set up the structure to specify the new action

  new_action.sa_handler = termination_handler;

  sigemptyset(
      &new_action
           .sa_mask); // set masks to empty as we are not blocking any signals
  new_action.sa_flags = 0; // not setting any masks


  sigaction(SIGINT, NULL, &old_action);

  if (old_action.sa_handler != SIG_IGN) {
    sigaction(SIGINT, &new_action, NULL);
  }

  if (old_action.sa_handler != SIG_IGN)
    sigaction(SIGHUP, &new_action, NULL);

  sigaction(SIGTERM, NULL, &old_action);

  if (old_action.sa_handler != SIG_IGN)
    sigaction(SIGTERM, &new_action, NULL);

  return 0;
}

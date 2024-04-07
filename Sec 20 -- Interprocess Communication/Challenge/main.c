/*
    Challenge 1: Signals
    Write a program to test a user's multiplication skills
    The program will ask the user to work on an answer to a simple
   multiplication program -keep track of how many answers are correct.

    Program will run forever unless
    -the user takes more than 5 secodns to answer a question.
    -User presses CTRL-C

    When program ends it will display the final score

    handle the signal for SIGALRM
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int score = 0;

void end_game() {
  printf("\nFinal Score: %d\n", score);
  exit(0);
}

 void times_up(){
    printf("\ntimes up!!");
    raise(SIGINT);
}

 void *countdown(void *ptr){
     int n = (int) ptr;
     while (n > 0){
         printf("\t%d\n", n);
         n--;
         sleep(1);
     }

     pthread_exit(NULL);
 }

int catch_signal(int sig, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL);
}

void error(char *msg) { fprintf(stderr, "%s: %s\n", msg, strerror(errno)); }

int main() {


    //signal(SIGINT, end_game);
    //signal(SIGALRM, times_up);
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);

    system("clear");

  printf("Challenge 1!\n");

  srand(time(NULL));

  while (1) {
    int a = arc4random_uniform(11);
    int b = arc4random_uniform(11);
    char txt[4] = {'\0'};
    int timeout = 5;
    pthread_t pthread;

    printf("\nWhat is %d * %d?\n", a, b);
    printf("You have %d seconds to answer!\n", timeout);

    pthread_create(&pthread, NULL, &countdown, (void *)timeout);

    alarm(timeout);
    //printf("Your answer: ");

    fgets(txt, 4, stdin);
    if(txt[0] != '\0'){
        pthread_cancel(pthread);
    }

    system("clear");

    int answer = atoi(txt);

    if(answer == a * b){
        score++;
        printf("\nCorrect! Score: %d\n", score);
    }
    else{
        printf("\nWrong! Answer was: %d\nScore: %d\n", a * b, score);
    }


  }
  return 0;
}

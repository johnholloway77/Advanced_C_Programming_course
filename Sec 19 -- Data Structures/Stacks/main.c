#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

struct stackArray {
  int stk[MAXSIZE];
  int top;
};

typedef struct stackArray STACK_ARR;

struct Node {
  int data;
  struct Node *link;
};

// create first element for linked list
struct Node *top = NULL;

// create an instance of a STACK_ARR;
STACK_ARR sArr;

void pushArr(void);
int popArr(void);
void displayArr(void);

void push(int data) {
  struct Node *temp = malloc(sizeof(struct Node));

  if (temp != NULL) {
    temp->data = data;
    temp->link = top;
    top = temp;
  }
}

int isEmpty(void) { return top == NULL; }

void pop(void) {
  struct Node *temp;

  if (top != NULL) {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void display(void) {
  struct Node *temp;

  if (top != NULL) {
    temp = top;
    while (temp != NULL) {
      printf("%d: \n", temp->data);
      temp = temp->link;
    }
  }
}

int main() {
  printf("Stack Data Structure\n");

  printf("Linked List implementation");
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  display();

  printf("pop!\n");
  pop();

  display();

  printf("\nArray based implementation\n");

  int choice;
  int option = -1;
  sArr.top = -1;

  while(option){
      printf(
          "\t1 --> PUSH\n"
          "\t2 --> POP\n"
          "\t3 --> DISPLAY\n"
          "\t4 --> EXIT\n"
          );

      printf("Enter your choice\n");
      scanf("%d", &choice);

      switch (choice){
      case 1:
          pushArr();
          break;

      case 2:
          popArr();
          break;

      case 3:
          displayArr();
          break;

      case 4:
          fflush(stdin);
          printf("Do you want to continue (type 0 or 1)?\n");
          scanf("%d", &option);
          break;;

      default:
          printf("invalid choice\n");

      }



  }

  return 0;
}

void pushArr(void){
    int num;
    if(sArr.top == (MAXSIZE -1)){
        printf("StackArr is full\n");
        return;
    }
    else{
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        sArr.top++;
        sArr.stk[sArr.top] = num;
    }
    return; //isn't this redundent?
}


int popArr(void){
    int num = 0;
    //check if empty
    if(sArr.top == -1){
        printf("Stack is empty\n");
        return (sArr.top);
    }
    else{
        num = sArr.stk[sArr.top];
        printf("Popped element is %d\n", num);
        sArr.top--;
    }

    return num;
}


void displayArr(void){
    int i = 0;
    if(sArr.top == -1){
        printf("stack is empty\n");
        return;
    }
    else{
        printf("The values of the stack are:\n");
        for(i = sArr.top; i >= 0 ; i--){
            printf("%d\n", sArr.stk[i]);
        }
    }
    printf("\n");
}

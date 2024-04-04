#include <stdio.h>

#define MAX 50

void enQueue();
void deQueue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main() {
  printf("Array Based Queues\n");

  int choice;

  while (1) {
    printf("1. Insert element to queue \n"
           "2. Delete element from queue\n"
           "3. Display all elements of queue\n"
           "4. QUIT\n"
           "Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

      // enQueue
    case 1:
      enQueue();
      break;

    // deQueue
    case 2:
      deQueue();
      break;

      // display
    case 3:
      display();
      break;

      // quit
    case 4:
      return 0;
      break;

    case 5:
      printf("Invalid choice\n");
    }
  }

  return 0;
}

void enQueue() {
  int add_item = 0;

  if (rear == MAX - 1) {
    printf("Queue overflow! \n");

  } else {
    if (front == -1)
      front = 0; // increase front to from empty to one

    printf("Insert the element in queue: ");
    scanf("%d", &add_item);
    rear++;
    queue_array[rear] = add_item;
  }
}

void deQueue() {

  // check if empty
  if (front == -1 || front > rear) {
    printf("Queue Underflow \n");
    return;
  } else {
    printf("Element deleted from queue is %d\n", queue_array[front]);
    front++;
  }
}

void display(){

    //check if empty
    if (front == -1 ) {
        printf("Queue is empty! \n");
    }
    else{
        printf("Queue is :\n");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }

}

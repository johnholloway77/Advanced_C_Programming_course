#include <stdio.h>
#include <stdlib.h>

struct QNode {
  int key;
  struct QNode *next;
};

struct Queue {
  struct QNode *front, *rear;
};

struct QNode *newNode(int k) {
  struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
  temp->key = k;
  temp->next = NULL;
  return temp;
}

struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

void enQueue(struct Queue *q, int k) {
  struct QNode *temp = newNode(k);

  // if queue is empty, then new node is both front and rear
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    return;
  }

  // Add the new node at the end of the queue and update rear;
  q->rear->next = temp;
  q->rear = temp;
}

struct QNode *deQueue(struct Queue *q) {
  // if queue is empty, return NULL
  if (q->front == NULL)
    return NULL;

  struct QNode *temp = q->front;
  q->front = q->front->next;

  // if front becomes NULL queue is tempty. Change rear to also NULL;
  if (q->front == NULL)
    q->rear = NULL;

  return temp;
  //temp's value should be freed

}

int main() {
  printf("Queues!\n");

  printf("Linked List implementation!\n");


  struct Queue* q = createQueue();
  enQueue(q, 1);
  enQueue(q, 2);
  deQueue(q); //memory leak
  deQueue(q); //memory leak
  enQueue(q, 3);
  enQueue(q, 4);
  enQueue(q, 5);
  struct QNode* n = deQueue(q);
  if(n != NULL){
      printf("dequeued item is %d\n", n->key);
      free(n);
  }

  return 0;
}

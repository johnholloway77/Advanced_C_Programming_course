/*

    Challenge Linked Lists:

    Create a linked list that stores integers and uses pointers

    Your program should perform the following operations:
    -insert node at first
    -insert node at last
    -insert node at any position
    -update node value
    -Search Element in the linked list
    -display list
    -exit

*/

#include <stdio.h>
#include <stdlib.h>

// create node
typedef struct node {
  int data;
  struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

// prototypes:
void insertAtBeginning(ListNodePtr *head, int value);
void insertAtEnd(ListNodePtr *head, int value);
void insertAtPosition(ListNodePtr *head, int value, int position);
int deleteAtPosition(ListNodePtr *head, int position);
int updateNode(ListNodePtr *head, int value, int position);
int searchElement(ListNodePtr head, int value);
void printList(ListNodePtr head);
int isEmpty(ListNodePtr head);

void displayMenu(void);

int main() {
  printf("Challenge Linked Lists\n");

  ListNodePtr head = NULL;

  int choice = 0;
  int item = 0;
  int position = 0;

  while (choice != 8) {
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {

      // insert node at beginning
    case 1:
      printf("Enter an int: ");
      scanf("\n %d", &item);
      insertAtBeginning(&head, item);
      printList(head);
      break;

      // Insert node at end
    case 2:
      printf("Enter an int: ");
      scanf("\n %d", &item);
      insertAtEnd(&head, item);
      printList(head);
      break;

      // Insert node at a specific position
    case 3:
      printf("Enter an int: ");
      scanf("\n %d", &item);
      printf("Enter the position (count starts at 0) ");
      scanf("\n %d", &position);
      insertAtPosition(&head, item, position);
      printList(head);
      break;

      // Delete node from any position
    case 4:
      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {
        printf("Enter the position (count starts at 0) ");
        scanf("\n %d", &position);
        deleteAtPosition(&head, position);
        printList(head);
      }
      break;

      // Update node value
    case 5:

      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {
        printf("Enter an int ");
        scanf("\n %d", &item);
        printf("Enter the position (count starts at 0) ");
        scanf("\n %d", &position);
        updateNode(&head, item, position);
        printList(head);
      }
      break;

    // Search element in linked list
    case 6:
      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {
        position = searchElement(head, item);
        printf("Enter an int: ");
        scanf("\n %d", &item);
        if (position < 0) { // item not found
          printf("%d not found in linked list\n\n", item);
        } else {
          printf("%d found in position %d\n\n", item, position);
        }
      }

      break;

      // display list
    case 7:
      printList(head);
      break;

    default:
      printf("Invalid choice!\n");
      break;
    }
    // end switch
  }
  // end while-loop

  return 0;
}

void displayMenu(void) {
  printf("Enter your choice:\n"
         "\t1. Insert Node at beginning\n"
         "\t2. Insert node at end\n"
         "\t3. Insert node at a specific position\n"
         "\t4. Delete Node from Position\n"
         "\t5. Update Node Value\n"
         "\t6. Search Element in the linked list\n"
         "\t7. Display List\n"
         "\t8. Exit\n\n");

  printf("Enter your choice: ");
}

void insertAtBeginning(ListNodePtr *head, int value) {
  ListNodePtr new_node = malloc(sizeof(node_t));
  new_node->data = value;
  new_node->nextPtr = *head;
  *head = new_node;
}

void insertAtEnd(ListNodePtr *head, int value) {
  ListNodePtr currentPtr = *head;

  if (currentPtr != NULL) {
    while (currentPtr->nextPtr != NULL) {
      currentPtr = currentPtr->nextPtr;
    }
    currentPtr->nextPtr = malloc(sizeof(node_t));
    currentPtr->nextPtr->data = value;
    currentPtr->nextPtr->nextPtr = NULL;

  } else { // node is empty, add to head
    currentPtr = malloc(sizeof(node_t));
    currentPtr->data = value;
    currentPtr->nextPtr = NULL;
    *head = currentPtr;
  }
}

void insertAtPosition(ListNodePtr *head, int value, int position) {
  ListNodePtr newPtr;
  ListNodePtr previousPtr = NULL;
  ListNodePtr currentPtr;

  if (position == 0) {
    newPtr = malloc(sizeof(node_t));
    newPtr->data = value;
    newPtr->nextPtr = *head;
    *head = newPtr;
  } else {
    currentPtr = *head;

    int i = 0;
    while (i < position && currentPtr != NULL) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
      i++;
    }

    if (currentPtr == NULL) {
      printf("Position %d not found in linked list\n\n", position);
      return;
    } else {
      newPtr = malloc(sizeof(node_t));
      newPtr->data = value;
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
  }
}

int deleteAtPosition(ListNodePtr *head, int position) {
  ListNodePtr currentPtr = *head;
  ListNodePtr previousPtr = NULL;
  ListNodePtr tempPtr;
  int value;

  // if first position, update head
  if (position == 0) {
    tempPtr = currentPtr;
    value = currentPtr->data;
    *head = currentPtr->nextPtr;
    free(tempPtr);
    return value;
  } else {

    int i = 0;
    while (i < position && currentPtr != NULL) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
      i++;
    }

    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      value = currentPtr->data;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    } else {
      printf("Position %d not found in linked list\n\n", position);
      return -1;
    }
  }
}

int updateNode(ListNodePtr *head, int value, int position) {
  ListNodePtr currentPtr = *head;

  int i = 0;
  while (i < position && currentPtr != NULL) {
    currentPtr = currentPtr->nextPtr;
    i++;
  }

  if (currentPtr != NULL) {
    int temp = currentPtr->data;
    currentPtr->data = value;
    return temp;
  } else {
    printf("Position %d not found in linked list\n\n", position);
    return value;
  }
}

int searchElement(ListNodePtr head, int value) {
  int position = 0; // initialize

  // check first value
  if (head->data == value) {
    return position;
  } else {
    while (head != NULL && head->data != value) {
      head = head->nextPtr;
      position++;
    }

    if (head != NULL) {
      return position;
    } else {
      // if head is null, then value not found
      return -1;
    }
  }
}

void printList(ListNodePtr head) {
  if (head == NULL) {
    printf("List is empty.\n\n");
  } else {
    printf("The list is: \n");
    while (head != NULL) {
      printf("%d --> ", head->data);
      head = head->nextPtr;
    }
    printf("NULL\n\n");
  }
};

int isEmpty(ListNodePtr head) { return head == NULL; }

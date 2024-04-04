/*

    for fun Linked Lists:

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
  struct node *prevPtr;
} node_t;

typedef node_t *ListNodePtr;

// prototypes:
void insertAtBeginning(ListNodePtr *head, ListNodePtr *tail, int value);
void insertAtEnd(ListNodePtr *head, ListNodePtr *tail, int value);
void insertAtPosition(ListNodePtr *head, ListNodePtr *tail, int value,
                      int position);
int deleteAtPosition(ListNodePtr *head, ListNodePtr *tail, int position);
int updateNode(ListNodePtr *head, ListNodePtr *tail, int value, int position);

int searchElement(ListNodePtr head, int value);
int searchElementReverse(ListNodePtr tail, int value);

void printList(ListNodePtr head, ListNodePtr tail);
int isEmpty(ListNodePtr head);

void displayMenu(void);

int main() {
  system("clear");

  printf("Challenge Linked Lists\n");

  ListNodePtr head = NULL;
  ListNodePtr tail = NULL;

  int choice = 0;
  int item = 0;
  int position = 0;

  while (choice != 9) {
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {

      // insert node at beginning
    case 1:
      system("clear");
      printf("Enter an int: ");
      scanf("\n %d", &item);
      insertAtBeginning(&head, &tail, item);
      printList(head, tail);
      break;

      // Insert node at end
    case 2:
      system("clear");
      printf("Enter an int: ");
      scanf("\n %d", &item);
      insertAtEnd(&head, &tail, item);
      printList(head, tail);
      break;

      // Insert node at a specific position
    case 3:
      system("clear");
      printf("Enter an int: ");
      scanf("\n %d", &item);
      printf("Enter the position (count starts at 0) ");
      scanf("\n %d", &position);
      insertAtPosition(&head, &tail, item, position);
      printList(head, tail);
      break;

      // Delete node from any position
    case 4:
      system("clear");
      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {
        printf("Enter the position (count starts at 0) ");
        scanf("\n %d", &position);
        deleteAtPosition(&head, &tail, position);
        printList(head, tail);
      }
      break;

      // Update node value
    case 5:
      system("clear");

      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {
        printf("Enter an int ");
        scanf("\n %d", &item);
        printf("Enter the position (count starts at 0) ");
        scanf("\n %d", &position);
        updateNode(&head, &tail, item, position);
        printList(head, tail);
      }
      break;

      // Search element in linked list
    case 6:
      system("clear");
      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {

        printf("Enter an int: ");
        scanf("\n %d", &item);
        position = searchElement(head, item);
        if (position < 0) { // item not found
          printf("%d not found in linked list\n\n", item);
        } else {
          printf("%d found in position %d\n\n", item, position);
        }
      }

      break;

      // Search element in linked list reverse order
    case 7:
      system("clear");
      if (isEmpty(head)) {
        printf("List empty\n\n");
      } else {

        printf("Enter an int: ");
        scanf("\n %d", &item);
        position = searchElementReverse(tail, item);
        if (position > 0) { // item not found
          printf("%d not found in linked list\n\n", item);
        } else {
          printf("%d found in position %d\n\n", item, position);
        }
      }

      break;

      // display list
    case 8:
      system("clear");
      printList(head, tail);
      break;

    case 9:
      printf("Goodbye!\n");
      break;

    default:
      system("clear");
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
         "\t7. Search Elements from tail\n"
         "\t8. Display List\n"
         "\t9. Exit\n\n");

  printf("Enter your choice: ");
}

void insertAtBeginning(ListNodePtr *head, ListNodePtr *tail, int value) {

  ListNodePtr new_node = malloc(sizeof(node_t));

  new_node->data = value;
  new_node->nextPtr = *head;
  new_node->prevPtr = NULL;

  if (*head != NULL) {
    (*head)->prevPtr = new_node;
  } else { // if list is empty
    *tail = new_node;
  }

  *head = new_node;
}

void insertAtEnd(ListNodePtr *head, ListNodePtr *tail, int value) {
  ListNodePtr currentPtr = *head;

  if (currentPtr != NULL) {

    while (currentPtr->nextPtr != NULL) {
      ListNodePtr tempPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    currentPtr->nextPtr = malloc(sizeof(node_t));
    currentPtr->nextPtr->data = value;
    currentPtr->nextPtr->nextPtr = NULL;
    currentPtr->nextPtr->prevPtr =
        currentPtr; // tell the new pointer to point to inserted node at end
    *tail = currentPtr->nextPtr;

  } else { // node is empty, add to head
    currentPtr = malloc(sizeof(node_t));
    currentPtr->data = value;
    currentPtr->nextPtr = NULL;
    currentPtr->prevPtr = NULL;
    *head = currentPtr;
    *tail = currentPtr;
  }
}

void insertAtPosition(ListNodePtr *head, ListNodePtr *tail, int value,
                      int position) {
  ListNodePtr newPtr;
  ListNodePtr previousPtr = NULL;
  ListNodePtr currentPtr;

  if (isEmpty(*head)) {
    printf("Value %d insterted into empty linked list\n\n", value);
    insertAtBeginning(head, tail, value);
    return;
  }

  if (position == 0 || position < 0) {
    insertAtBeginning(head, tail, value);
  } else {
    currentPtr = *head;

    int i = 0;
    while (i < position && currentPtr != NULL) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
      i++;
    }

    printf("i %d\tposition: %d\n", i, position);

    // if i equals position, then position is equal to size of linked list (add
    // to end)  if i is less than position, position exceeds size of linked list
    if (i < position) {
      printf("Position %d exceeds size of linked list\n"
             "New node appened to linked list with value %d\n\n",
             position, value);
      insertAtEnd(head, tail, value);
    }

    else {
      newPtr = malloc(sizeof(node_t));
      newPtr->data = value;
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
      newPtr->prevPtr = previousPtr;
      currentPtr->prevPtr = newPtr;

      // check if pointer is at end of list
      // assign it to tail if so
      if (currentPtr == NULL) {
        *tail = newPtr;
      }
    }
  }
}

int deleteAtPosition(ListNodePtr *head, ListNodePtr *tail, int position) {
  ListNodePtr currentPtr = *head;
  ListNodePtr previousPtr = NULL;
  ListNodePtr tempPtr;
  int value;

  // if first position, update head
  if (position == 0) {
    tempPtr = currentPtr;
    value = currentPtr->data;
    *head = currentPtr->nextPtr;
    currentPtr->nextPtr->prevPtr = NULL;
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

      if (currentPtr->nextPtr !=
          NULL) { // check if currentPtr is in the last position in Linked List
        currentPtr->nextPtr->prevPtr = previousPtr;
      } else {
        *tail = previousPtr;
      }

      free(tempPtr);
      return value;
    } else {
      printf("Position %d not found in linked list\n\n", position);
      return -1;
    }
  }
}

int updateNode(ListNodePtr *head, ListNodePtr *tail, int value, int position) {
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

int searchElementReverse(ListNodePtr tail, int value) {
  int position = -1; // initialize

  // check first value
  if (tail->data == value) {
    return position;
  } else {
    while (tail != NULL && tail->data != value) {
      tail = tail->prevPtr;
      position--;
      printf("position while loop: %d\n", position);
    }

    if (tail != NULL) {
      printf("position: %d\n", position);
      return position;
    } else {
      // if tail is null, then value not found
      printf("tail null\n"
             "position: %d\n",
             position);
      return 1;
    }
  }
}

void printList(ListNodePtr head, ListNodePtr tail) {
  if (head == NULL) {
    printf("List is empty.\n\n");
  } else {
    int position = 0;
    printf("Head: %d | Tail: %d\n", head->data, tail->data);
    printf("The list is: \n");
    printf("prev |data| next\n");
    while (head != NULL) {
      if (head->prevPtr == NULL && head->nextPtr == NULL) {
        printf("N <--| %d |--> N\t\t<== position %d\n", head->data, position);
      } else if (head->prevPtr == NULL) {
        printf("N <--| %d |--> %d\t\t<== position %d\n", head->data,
               head->nextPtr->data, position);
      } else if (head->nextPtr == NULL) {
        printf("%d <--| %d |--> N\t\t<== position %d\n", head->prevPtr->data,
               head->data, position);
      } else {
        printf("%d <--| %d |--> %d\t\t<== position %d\n", head->prevPtr->data,
               head->data, head->nextPtr->data, position);
      }

      if (head->nextPtr != NULL) {
        printf("       |        \n");
        printf("      \\ / \n");
        printf("       V \n");
      }
      head = head->nextPtr;
      position++;
    }
    // printf("NULL\n\n");
    printf("\n\n");
  }
};

int isEmpty(ListNodePtr head) { return head == NULL; }

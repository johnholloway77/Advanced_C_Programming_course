#include <stdio.h>
#include <stdlib.h>

// create struct node
// A type of self-referential structure

/*
 in order for node to be self referential, you must create a struct with a
 name (struct node) rather than just use anonomous structs with a typedef
*/
typedef struct node {
  char data;
  struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

// prototypes
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete (ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main() {
  printf("Linked List Implementation!\n");

  ListNodePtr head = NULL; // initializes an empty linked list

  int choice = 0;
  char item = '\0';

  // display menu
  printf("Enter your choice:\n"
         "\t1 to insert an element into the list in alphabetical order.\n"
         "\t2 to insert and element at the end of the list.\n"
         "\t3 to insert an element at the beginning of the list.\n"
         "\t4 to delele an element from the list.\n"
         "\t5 to delete an element from the beginning of the list\n"
         "\t6 to check if list is empty\n"
         "\t7 to end.\n");

  printf(":: ");
  scanf("%d", &choice);

  while (choice != 7) {

    switch (choice) {

    case 1:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insert(&head, item);
      printList(head);
      break;

    case 2:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insertAtEnd(&head, item);
      printList(head);
      break;

    case 3:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insertAtBeginning(&head, item);
      printList(head);
      break;

    case 4: // delete an element

      // if list is not empty:
      if (!isEmpty(head)) {
        printf("Enter a character to be deleted: ");
        scanf("\n%c", &item);

        // if character is found remove it
        if (delete (&head, item)) {
          printf("%c deleted.\n\n", item);
          printList(head);
        } else {
          printf("%c not found.\n\n", item);
        }
      }
      // else if list is empty
      else {
        printf("List is empty.\n\n");
      }
      break;

    case 5:
      // check if list is empty
      if (!isEmpty(head)) {
        deleteAtBeginning(&head);
        printf("%c is deleted\n\n", item); // is item set?
        printList(head);
      } else {
        printf("List is empty.\n\n");
      }
      break;

    case 6:
      if (isEmpty(head)) {
        printf("Linked List is empty\n\n");
      } else {
        printf("Linked list is not empty\n\n");
      }
      break;

    default:
      printf("Invalid choice!\n\n");
      printf("Enter your choice:\n"
             "\t1 to insert an element into the list in alphabetical order.\n"
             "\t2 to insert and element at the end of the list.\n"
             "\t3 to insert an element at the beginning of the list.\n"
             "\t4 to delele an element from the list.\n"
             "\t5 to delete an element from the beginning of the list\n"
             "\t6 to end.\n");
      break;
    }

    printf("? ");
    scanf(" %d", &choice);
  } // end while-loop

  return 0;
}

void insert(ListNodePtr *head, char value) {
  ListNodePtr newPtr;
  ListNodePtr previousPtr;
  ListNodePtr currentPtr;

  newPtr = malloc(sizeof(node_t));

  if (newPtr != NULL) {
    newPtr->data = value;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = *head;

    // Loop to find the correct location in the list

    while (currentPtr != NULL && value > currentPtr->data) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    // previousPtr will be NULL (as will currentPtr) if the linked list is empty
    // We can add the new node to list as head
    if (previousPtr == NULL) {
      newPtr->nextPtr = *head; // isn't this redundant as head is already NULL?
      *head = newPtr;
    } else {
      // insert new node between previousPtr and currentPtr
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }

  } else {
    // out of memory
    fprintf(stderr, "Error:\n%c not inserted. could not allcoate memory\n",
            value);
    exit(1);
  }
}

// Every time we call this function it creates a new head value;
void insertAtBeginning(ListNodePtr *head, char value) {

  ListNodePtr new_node = malloc(sizeof(node_t));
  new_node->data = value;
  new_node->nextPtr = *head;
  *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value) {
  ListNodePtr current = *head; // point current at the first node in Linked List

  if (current != NULL) { // checks if linked list is empty
    while (current->nextPtr != NULL) {
      current = current->nextPtr; // moves the pointer to the last node in the
                                  // Linked-list
    }

    current->nextPtr = malloc(sizeof(node_t));
    current->nextPtr->data = value;
    current->nextPtr->nextPtr = NULL;

  } else {
    // if linked list is emptry, create an try node
    current = malloc(sizeof(node_t));
    current->data = value;
    current->nextPtr = NULL;
    *head = current;
  }
}

char delete (ListNodePtr *head, char value) {
  ListNodePtr previousPtr;
  ListNodePtr currentPtr;
  ListNodePtr tempPtr;

  // delete first node
  if (value == (*head)->data) {
    tempPtr = *head;
    *head = (*head)->nextPtr;
    free(tempPtr);
    return value;
  } else {
    previousPtr = *head;
    currentPtr = (*head)->nextPtr;

    // find the value to be deleted
    while (currentPtr != NULL && currentPtr->data != value) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }
  }
  return '\0';
}

void deleteAtBeginning(ListNodePtr *head) {
  ListNodePtr current = *head;

  if (current != NULL) {
    *head = current->nextPtr;
    free(current);
  }
};

int isEmpty(ListNodePtr head) { return head == NULL; };

void printList(ListNodePtr currentPtr) {

  if (currentPtr == NULL) {
    printf("List is empty.\n\n");
  } else {
    printf("The list is: \n");
    while (currentPtr != NULL) {
      printf("%c --> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    printf("NULL\n\n");
  }
};

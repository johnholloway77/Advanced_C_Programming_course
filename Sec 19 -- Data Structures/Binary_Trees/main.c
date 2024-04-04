#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
  int data;
  struct treeNode *leftPtr;
  struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// prototypes

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main() {
  printf("Binary Trees!\n");

  int i = 0;                  // counter to loop from 1 - 10
  int item = 0;               // variable to hold random balues
  TreeNodePtr rootPtr = NULL; // Tree initially empty

  srand(time(NULL));
  printf("The numbers being placed in the tree are:\n");

  // insert random numbers between 0 and 14 in the tree
  for (i = 1; i <= 10; i++) {
    item = rand() % 15;
    printf("%3d", item);
    insertNode(&rootPtr, item);
  }

  printf("\n\nThe preOrder traversal is:\n");
  preOrder(rootPtr);

  printf("\n\nThe inOrder traversal is:\n");
  inOrder(rootPtr);

  printf("\n\nThe postOrder traversal is:\n");
  postOrder(rootPtr);

  return 0;
}

void insertNode(TreeNodePtr *treePtr, int value) {

    //if treePtr is empty
  if (*treePtr == NULL) {
    *treePtr = malloc(sizeof(TreeNode));

    // if memory was allocated then assign the data
    if (*treePtr != NULL) {
      (*treePtr)->data = value;
      (*treePtr)->leftPtr = NULL;
      (*treePtr)->rightPtr = NULL;
    } // end if
    else {
        printf("%d not inserted. No memory available.\n", value);
    }
  }
  //if tree is not empty
  else{

      //data to insert is less than data in current node
      if(value < (*treePtr)->data){
          //recursively insert into subtree
          insertNode(&((*treePtr)->leftPtr), value);
      }
      //data to insert is greater than data in current node
      else if(value > (*treePtr)->data){
          insertNode(&((*treePtr)->rightPtr), value);
      }
      else{ //duplicate data value ignored
          printf(" dup ");
      }

  }

}


void inOrder(TreeNodePtr treePtr){
    if(treePtr !=NULL){
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}


void preOrder(TreeNodePtr treePtr){
    if(treePtr != NULL){
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }

}

void postOrder(TreeNodePtr treePtr){
    if(treePtr != NULL){
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}

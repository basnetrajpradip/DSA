#include <stdio.h>
#include <stdlib.h>

// Structure for node/element of the linked list implementation of stack.
struct Node {
  int data;
  struct Node *next;
};

// Display the contents of the stack.
void displayStack(struct Node *top);

// Delete the entire linked list stack.
void deleteStack(struct Node **top);

// Stack ADT

// Create new node/element of the stack.
struct Node *createStackNode(int data);

// Check if stack is empty
int isEmpty(struct Node *top);

// Push an element onto the stack.
void push(struct Node **top, int data);

// Pop an element off the stack.
int pop(struct Node **top);

// Return the element at the top of stack
int top(struct Node *top);

// main function
int main() {
  struct Node *topPtr = NULL;

  // Display top of empty stack.
  top(topPtr);

  // Push item to the stack and display the stack
  push(&topPtr, 50);
  push(&topPtr, 52);
  push(&topPtr, 365);
  displayStack(topPtr);

  // Display top of the stack.
  top(topPtr);

  // Pop and display the stack.
  pop(&topPtr);
  displayStack(topPtr);

  // Delete the stack
  deleteStack(&topPtr);
}

struct Node *createStackNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  if (!newNode) {
    printf("Memory Error!");
    return NULL;
  }

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int isEmpty(struct Node *top) { return (top == NULL); }

void push(struct Node **top, int data) {
  struct Node *newNode = createStackNode(data);
  newNode->next = *top;
  *top = newNode;
}

int pop(struct Node **top) {
  if (isEmpty(*top)) {
    printf("Stack underflow!\n");
  }
  struct Node *temp = *top;
  int popped = temp->data;
  *top = (*top)->next;
  free(temp);
  printf("%d is popped.\n", popped);
  return popped;
}

int top(struct Node *top) {
  if (isEmpty(top)) {
    printf("Stack underflow.\n");
    return -99999;
  }
  printf("%d is at the top of stack.\n", top->data);
  return top->data;
}

void displayStack(struct Node *top) {
  if (isEmpty(top)) {
    printf("Stack is Empty.\n");
    return;
  }
  struct Node *current = top;
  printf("Stack content: \n");
  while (current != NULL) {
    printf("%d\t", current->data);
    current = current->next;
  }
  printf("\n");
}

void deleteStack(struct Node **top) {
  struct Node *current, *temp;
  current = *top;
  while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *top = NULL;
  printf("Stack has been deleted.\n");
}
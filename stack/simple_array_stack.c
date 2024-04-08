#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3;

// Structure for array based implementation of stack.
struct Stack {
  int top;
  int capacity;
  int *array;
};

// Display Stack contents
void displayStack(struct Stack *S);

// Stack ADT

// Create stack and return pointer
struct Stack *createStack();

// Check if the stack is empty
int isEmptyStack(struct Stack *S);

// Check if the stack is full
int isFullStack(struct Stack *S);

// Push an item to the stack
void push(struct Stack *S, int data);

// Pop the item from the stack
int pop(struct Stack *S);

// Return the item at the top of stack
int top(struct Stack *S);

// Delete the stack
void deleteStack(struct Stack *S);

// Main function
int main() {
  struct Stack *S = createStack();

  // Display the top of empty stack.
  top(S);

  // Push item to the stack and display the stack
  push(S, 50);
  push(S, 52);
  push(S, 365);
  displayStack(S);

  // Push more item than capacity & display the stack
  push(S, 98);
  displayStack(S);

  // Display top of the stack.
  top(S);

  // Pop and display the stack.
  pop(S);
  displayStack(S);

  // Delete the stack
  deleteStack(S);
}

struct Stack *createStack() {
  struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
  if (!S) {
    return NULL;
  }
  S->capacity = MAXSIZE;
  S->top = -1;
  S->array = malloc(S->capacity * sizeof(int));
  if (!S->array) {
    return NULL;
  }
  return S;
}

int isEmptyStack(struct Stack *S) { return (S->top == -1); }

int isFullStack(struct Stack *S) { return (S->top == (S->capacity) - 1); }

void push(struct Stack *S, int data) {
  if (isFullStack(S)) {
    printf("Stack Overflow.\n");
    return;
  } else {
    S->array[++(S->top)] = data;
    return;
  }
}

int pop(struct Stack *S) {
  if (isEmptyStack(S)) {
    printf("Stack Underflow.\n");
    return -99999;
  } else {
    printf("%d is popped\n", S->array[S->top]);
    return S->array[(S->top)--];
  }
}

int top(struct Stack *S) {
  if (isEmptyStack(S)) {
    printf("Stack Underflow.\n");
    return -99999;
  } else {
    printf("%d is at the top of stack.\n", S->array[S->top]);
    return S->array[S->top];
  }
}

void deleteStack(struct Stack *S) {
  if (S) {
    if (S->array) {
      free(S->array);
      free(S);
      printf("Stack has been deleted.\n");
    }
  }
}

void displayStack(struct Stack *S) {
  if (isEmptyStack(S)) {
    printf("Stack Underflow.\n");
  } else {
    printf("Stack content:\n");
    for (int i = S->top; i >= 0; i--) {
      printf("%d\t", S->array[i]);
    }
    printf("\n");
  }
}
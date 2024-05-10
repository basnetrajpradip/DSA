#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3;

// Structure for array based implementation of queue.
typedef struct Queue {
  int front, rear;
  int capacity;
  int *array;
} Queue;

// Create Queue and return pointer
Queue *createQueue();

// Check if the queue is empty
int isEmptyQueue(Queue *Q);

// Check if the queue is full
int isFullQueue(Queue *Q);

// Enqueue an item to the queue
void enqueue(Queue *Q, int data);

// Dequeue the item from the queue
int dequeue(Queue *Q);

// Display Queue contents
void displayQueue(Queue *Q);

// Delete the queue
void deleteQueue(Queue *Q);

// Return Front of the queue
int front(Queue *Q);

int main() {
  Queue *Q = createQueue();

  // Display the front of empty queue.
  front(Q);

  // Enqueue item to the queue and display the queue
  enqueue(Q, 50);
  enqueue(Q, 52);
  enqueue(Q, 365);
  displayQueue(Q);

  // Enqueue more item than capacity & display the queue
  enqueue(Q, 98);
  displayQueue(Q);

  // Display front of the queue.
  front(Q);

  // Dequeue and display the queue.
  dequeue(Q);
  displayQueue(Q);

  deleteQueue(Q);
  return 0;
}

Queue *createQueue() {
  Queue *Q = malloc(sizeof(Queue *));
  if (!Q) {
    printf("Memory Error!\n");
    return NULL;
  }
  Q->capacity = MAXSIZE;
  Q->front = Q->rear = -1;
  Q->array = malloc(Q->capacity * sizeof(int));

  if (!Q->array) {
    printf("Memory Error!\n");
    return NULL;
  }
  return Q;
}

int isEmptyQueue(Queue *Q) { return Q->front == -1; }

int isFullQueue(Queue *Q) { return ((Q->rear + 1) % Q->capacity == Q->front); }

void enqueue(Queue *Q, int data) {
  if (isFullQueue(Q)) {
    printf("Queue Overflow.\n");
    return;
  }
  Q->rear = (Q->rear + 1) % Q->capacity;
  Q->array[Q->rear] = data;
  if (Q->front == -1) {
    Q->front = Q->rear;
  }
}

int dequeue(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue Underflow.\n");
    return -9999;
  }
  int data = Q->array[Q->front];
  if (Q->front == Q->rear) {
    Q->front = Q->rear = -1;
  }
  Q->front = (Q->front + 1) % Q->capacity;
  printf("%d is Dequeued.\n", data);
  return data;
}

void displayQueue(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue UnderFlow.\n");
    return;
  }
  printf("Queue content:\n");
  int i = Q->front;
  do {
    printf("%d ", Q->array[i]);
    i = (i + 1) % Q->capacity;
  } while (i != (Q->rear + 1) % Q->capacity);
  printf("\n");
}

void deleteQueue(Queue *Q) {
  if (Q) {
    if (Q->array) {
      free(Q->array);
      free(Q);
      printf("Queue has been deleted.\n");
    }
  }
}

int front(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue Underflow.\n");
    return -9999;
  }
  printf("%d is at the front of the queue.\n", Q->array[Q->front]);
  return Q->array[Q->front];
}
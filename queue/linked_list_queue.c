#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
  int data;
  struct Node *next;
};

// Structure for queue
typedef struct Queue {
  struct Node *front, *rear;
} Queue;

// Function to create queue
Queue *createQueue();

// Function to check if the queue is empty
int isEmptyQueue(Queue *Q);

// Function to enqueue an item to the queue
void enqueue(Queue *Q, int data);

// Function to dequeue an item from the queue
int dequeue(Queue *Q);

// Function to display the front of the queue
int front(Queue *Q);

// Function to display the queue
void displayQueue(Queue *Q);

// Function to delete the queue
void deleteQueue(Queue *Q);

int main() {
  Queue *Q = createQueue();

  // Display the front of empty queue.
  front(Q);

  // Enqueue item to the queue and display the queue
  enqueue(Q, 50);
  enqueue(Q, 52);
  enqueue(Q, 365);
  displayQueue(Q);

  // Dequeue and display the queue.
  dequeue(Q);
  displayQueue(Q);

  // Display front of the queue.
  front(Q);

  deleteQueue(Q);
  return 0;
}

Queue *createQueue() {
  Queue *Q = malloc(sizeof(Queue));
  if (!Q)
    return NULL;
  Q->front = Q->rear = NULL;
  return Q;
}

int isEmptyQueue(Queue *Q) { return Q->front == NULL; }

void enqueue(Queue *Q, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (!newNode) {
    printf("Memory Error\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  if (Q->rear) {
    Q->rear->next = newNode;
  }
  Q->rear = newNode;

  if (Q->front == NULL) {
    Q->front = Q->rear;
  }
}

int dequeue(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue underflow\n");
    return -999999;
  }
  int data = Q->front->data;
  struct Node *temp = Q->front;
  Q->front = Q->front->next;
  free(temp);
  printf("%d is dequeued\n", data);
  return data;
}

int front(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue is empty\n");
    return -999999;
  }
  printf("Front of the queue is %d\n", Q->front->data);
  return Q->front->data;
}

void displayQueue(Queue *Q) {
  if (isEmptyQueue(Q)) {
    printf("Queue underflow.\n");
    return;
  }
  struct Node *temp = Q->front;
  printf("Queue content:\n ");
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void deleteQueue(Queue *Q) {
  if (Q) {
    struct Node *temp;
    while (Q->front) {
      temp = Q->front;
      Q->front = Q->front->next;
      free(temp);
    }
  }
  free(Q);

  printf("Queue has been deleted.\n");
  return;
}
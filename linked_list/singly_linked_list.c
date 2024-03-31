#include <stdio.h>
#include <stdlib.h>

// Structure for singly linked list node.
struct ListNode {
  int data;
  struct ListNode *next;
};

// Count the length of the list
int ListLength(struct ListNode *head);

// Display the linked list
void displayList(struct ListNode *head);

// Insert new node at the specified position of the list
void InsertIntoLinkedList(struct ListNode **head, int data, int position);

// Delete node from the linked list
void DeleteNodeFromLinkedList(struct ListNode **head, int position);

// Delete Linked list
void DeleteLinkedList(struct ListNode **head);

// Main function
int main() {
  // Head pointer for the linked list
  struct ListNode *head = NULL;

  // Inserting nodes at the specified position of the list
  InsertIntoLinkedList(&head, 5, 1);
  InsertIntoLinkedList(&head, 19, 2);
  InsertIntoLinkedList(&head, 45, 3);

  // printing details of the list
  printf("Length of the list is: %d\n", ListLength(head));
  displayList(head);

  // Deleting node from the list and displaying new info
  DeleteNodeFromLinkedList(&head, 2);
  printf("Length of the list is: %d\n", ListLength(head));
  displayList(head);

  // Deleting the linked list and verifying it.
  DeleteLinkedList(&head);
  printf("Length of the list is: %d\n", ListLength(head));
  displayList(head);
};

int ListLength(struct ListNode *head) {
  struct ListNode *current = head;
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void displayList(struct ListNode *head) {
  if (head == NULL) {
    printf("The List is Empty.");
    return;
  } else {
    struct ListNode *current = head;
    int listData;
    printf("The linked list is as follows:\n");
    while (current != NULL) {
      listData = current->data;
      printf("%d\t", listData);
      current = current->next;
    }
    printf("\n");
    return;
  }
}

void InsertIntoLinkedList(struct ListNode **head, int data, int position) {
  int k = 1;
  struct ListNode *p, *q, *newNode;

  newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!newNode) {
    printf("Memory Error");
    return;
  }

  newNode->data = data;
  p = *head;

  // Inserting a ndoe at the begining
  if (position == 1) {
    newNode->next = p;
    *head = newNode;
  } else {
    // Traverse the list until the position where we want to insert
    while ((p != NULL) && (k < position)) {
      k++;
      q = p;
      p = p->next;
    }

    q->next = newNode;
    newNode->next = p;
  }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
  int k = 1;
  struct ListNode *p, *q;
  if (*head == NULL) {
    printf("List is Empty");
    return;
  }

  p = *head;

  // Deleting a node at the begining
  if (position == 1) {
    *head = (*head)->next;
    free(p);
    return;
  }

  else {
    // Traverse the list until arriving at the position from which we want to
    // delete
    while ((p != NULL) && (k < position)) {
      k++;
      q = p;
      p = p->next;
    }
    if (p == NULL) {
      printf("Position doesn't exist");
    } else {
      q->next = p->next;
      free(p);
    }
  }
}

void DeleteLinkedList(struct ListNode **head) {
  struct ListNode *auxilaryNode, *iterator;
  iterator = *head;
  while (iterator) {
    auxilaryNode = iterator->next;
    free(iterator);
    iterator = auxilaryNode;
  }

  *head = NULL;
}
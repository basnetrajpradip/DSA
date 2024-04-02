#include <stdio.h>
#include <stdlib.h>

// Structure for singly linked list node.
struct ListNode {
  int data;
  struct ListNode *next;
};

// Count the length of the list
int listLength(struct ListNode *head);

// Display the linked list
void displayList(struct ListNode *head);

// Insert new node at the specified position of the list
void insertIntoLinkedList(struct ListNode **head, int data, int position);

// Delete node from the linked list
void deleteNodeFromLinkedList(struct ListNode **head, int position);

// Delete Linked list
void deleteLinkedList(struct ListNode **head);

// Main function
int main() {
  // Head pointer for the linked list
  struct ListNode *head = NULL;

  // Inserting nodes at the specified position of the list
  insertIntoLinkedList(&head, 5, 1);
  insertIntoLinkedList(&head, 19, 2);
  insertIntoLinkedList(&head, 45, 3);

  // printing details of the list
  printf("Length of the list is: %d\n", listLength(head));
  displayList(head);

  // Deleting node from the list and displaying new info
  deleteNodeFromLinkedList(&head, 2);
  printf("Length of the list is: %d\n", listLength(head));
  displayList(head);

  // Deleting node position that doesn't exist.
  deleteNodeFromLinkedList(&head, 4);
  printf("Length of the list is: %d\n", listLength(head));
  displayList(head);

  // Deleting the linked list and verifying it.
  deleteLinkedList(&head);
  printf("Length of the list is: %d\n", listLength(head));
  displayList(head);
};

int listLength(struct ListNode *head) {
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
    printf("The List is Empty.\n");
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

void insertIntoLinkedList(struct ListNode **head, int data, int position) {
  int k = 1;
  struct ListNode *temp1, *temp2, *newNode;

  newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!newNode) {
    printf("Memory Error");
    return;
  }

  newNode->data = data;
  temp1 = *head;

  // Inserting a ndoe at the begining
  if (position == 1) {
    newNode->next = temp1;
    *head = newNode;
  } else {
    // Traverse the list until the position where we want to insert
    while ((temp1 != NULL) && (k < position)) {
      k++;
      temp2 = temp1;
      temp1 = temp1->next;
    }

    temp2->next = newNode;
    newNode->next = temp1;
  }
}

void deleteNodeFromLinkedList(struct ListNode **head, int position) {
  int k = 1;
  struct ListNode *temp1, *temp2;
  if (*head == NULL) {
    printf("List is Empty.\n");
    return;
  }

  temp1 = *head;

  // Deleting a node at the begining
  if (position == 1) {
    *head = (*head)->next;
    free(temp1);
    return;
  }

  else {
    // Traverse the list until arriving at the position from which we want to
    // delete
    while ((temp1->next != NULL) && (k < position)) {
      k++;
      temp2 = temp1;
      temp1 = temp1->next;
    }
    if (k != position) {
      printf("Position doesn't exist\n");
      return;
    } else {
      temp2->next = temp1->next;
      free(temp1);
    }
  }
}

void deleteLinkedList(struct ListNode **head) {
  struct ListNode *temp, *current;
  current = *head;
  while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }

  *head = NULL;
}
#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node.
struct ListNode {
  int data;
  struct ListNode *next;
  struct ListNode *prev;
};

// Insert new node at the specified position of the list.
void insertIntoLinkedList(struct ListNode **head, int data, int position);

// Delete node from the specified position of the list.
void deleteNodeFromLinkedList(struct ListNode **head, int position);

// Display the linked list
void displayList(struct ListNode *head);

// Count the length of the linked list
int listLength(struct ListNode *head);

// Delete the linked list
void deleteLinkedList(struct ListNode **head);

// Main function
int main() {

  struct ListNode *head;

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
}

void insertIntoLinkedList(struct ListNode **head, int data, int position) {
  int k = 1;
  struct ListNode *temp, *newNode;

  newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!newNode) {
    printf("Memory Error!");
    return;
  }

  newNode->data = data;

  // Inserting node at the beginning
  if (position == 1) {
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head) {
      (*head)->prev = newNode;
    }

    *head = newNode;
    return;
  } else {
    // Inserting node by traversing at the specified position

    temp = *head;

    while ((temp->next != NULL) && (k < position - 1)) {
      temp = temp->next;
      k++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) {
      temp->next->prev = newNode;
    }

    temp->next = newNode;
    return;
  }
}

void deleteNodeFromLinkedList(struct ListNode **head, int position) {
  struct ListNode *temp;
  int k = 1;
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }

  temp = *head;

  // Deleting a node at the begining
  if (position == 1) {
    *head = (*head)->next;

    if (*head != NULL) {
      (*head)->prev = NULL;
    }
    free(temp);
    return;
  } else {
    // Traverse the list until arrives at position to delete.
    while ((temp->next != NULL) && (k < position)) {
      temp = temp->next;
      k++;
    }

    if (k != position) {
      printf("Position doesn't exist.");
      return;
    }

    temp->prev->next = temp->next;

    if (temp->next) {
      temp->next->prev = temp->prev;
    }
    free(temp);
    return;
  }
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

int listLength(struct ListNode *head) {
  struct ListNode *current = head;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void deleteLinkedList(struct ListNode **head) {
  struct ListNode *current, *temp;
  current = *head;
  while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *head = NULL;
}
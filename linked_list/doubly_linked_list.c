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

// Main function
int main() {
  struct ListNode *head;
  insertIntoLinkedList(&head, 5, 1);
  insertIntoLinkedList(&head, 45, 2);
  displayList(head);
  deleteNodeFromLinkedList(&head, 4);
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
  struct ListNode *temp1, *temp2;
  int k = 1;
  if (*head == NULL) {
    printf("List is empty");
    return;
  }

  temp1 = *head;

  // Deleting a node at the begining
  if (position == 1) {
    *head = (*head)->next;

    if (*head != NULL) {
      (*head)->prev = NULL;
    }
    free(temp1);
    return;
  } else {
    // Traverse the list until arrives at position to delete.
    while ((temp1->next != NULL) && (k < position)) {
      temp1 = temp1->next;
      k++;
    }
    if (k != position - 1) {
      printf("Position doesn't exist.");
    }
    temp2 = temp1->prev;
    temp2->next = temp1->next;

    if (temp1->next) {
      temp1->next->prev = temp2;
    }
    free(temp1);
    return;
  }
}
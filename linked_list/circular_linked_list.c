#include <stdio.h>
#include <stdlib.h>

// Structure for circular linked list.
struct ListNode {
  int data;
  struct ListNode *next;
};

// Count the length of the list.
int listLength(struct ListNode *head);

// Display the linked list.
void displayList(struct ListNode *head);

// Insert new node at the begining of Circular linked list.
void insertAtBeginning(struct ListNode **head, int data);

// Insert new node at the end of Circular linked list.
void insertAtEnd(struct ListNode **head, int data);

// Insert new node at the specified position of the list.
void insertIntoLinkedList(struct ListNode **head, int data, int position);

// Delete node from the specified position of the list.
void deleteNodeFromLinkedList(struct ListNode **head, int position);

// Delete the linked list.
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
  deleteNodeFromLinkedList(&head, 3);
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

int listLength(struct ListNode *head) {
  struct ListNode *current = head;
  int count = 0;
  if (head == NULL) {
    return count;
  }
  do {
    current = current->next;
    count++;
  } while (current != head);
  return count;
}

void displayList(struct ListNode *head) {
  struct ListNode *current = head;
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  printf("The linked list is as follows:\n");
  do {
    printf("%d\t", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
  return;
}

void insertAtBeginning(struct ListNode **head, int data) {
  struct ListNode *current = *head;
  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!newNode) {
    printf("Memory Error!.\n");
    return;
  }

  newNode->data = data;

  if (*head == NULL) {
    *head = newNode;
    (*head)->next = *head;
  } else {
    while (current->next != *head) {
      current = current->next;
    }
    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
  }
}

void insertAtEnd(struct ListNode **head, int data) {
  struct ListNode *current = *head;
  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!newNode) {
    printf("Memory Error!.\n");
    return;
  }

  newNode->data = data;

  if (*head == NULL) {
    *head = newNode;
    (*head)->next = *head;
  } else {

    while (current->next != *head) {
      current = current->next;
    }
    newNode->next = *head;
    current->next = newNode;
  }
}

void insertIntoLinkedList(struct ListNode **head, int data, int position) {
  struct ListNode *newNode, *temp1, *temp2;
  int k = 1;

  temp1 = *head;

  if (*head == NULL || position == 1) {
    insertAtBeginning(head, data);
    return;
  } else if (position == listLength(*head)) {
    insertAtEnd(head, data);
  } else {
    while ((temp1 != NULL) && k < position) {
      k++;
      temp2 = temp1;
      temp1 = temp1->next;
    }

    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->data = data;

    temp2->next = newNode;
    newNode->next = temp1;
  }
}

void deleteNodeFromLinkedList(struct ListNode **head, int position) {
  int k = 1;
  struct ListNode *temp1, *temp2;

  if (*head == NULL) {
    printf("The list is empty.\n");
  }

  temp1 = *head;

  if (position == 1) {
    if ((*head)->next == *head) {
      free(*head);
      *head = NULL;
      return;
    } else {
      while (temp1->next != *head) {
        temp1 = temp1->next;
      }
      temp2 = *head;
      temp1->next = (*head)->next;
      *head = (*head)->next;
      free(temp2);
      return;
    }
  } else {

    while ((temp1->next != *head) && k < position) {
      temp2 = temp1;
      temp1 = temp1->next;
      k++;
    }
    if (k != position) {
      printf("Position doesn't exist.\n");
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
  while (current->next != *head) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *head = NULL;
}
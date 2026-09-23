#include <stdio.h>
#include <stdlib.h>

// Node creation
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

// insert at first
void insertAtFirst(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// insert at last
void insertAtLast(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// insert at position
void insertAtPosition(struct Node **head, int data, int position) {
    struct Node* newNode = createNode(data);
    if(position == 0) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* temp = *head;
    for(int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// searching
int search(struct Node **head, int key) {
    struct Node* temp = *head;
    while (temp->next != NULL) {
        if (temp->data == key) {
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}

// reverse linked list
Node* reverse(struct Node **head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = *head;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// delete at first
void deleteAtFirst(struct Node **head) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("Nothing to delete\n");
        return;
    }
    *head = (*head)->next;
    free(temp);
}

// delete at end
void deleteAtLast(struct Node **head) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("Nothing to delete\n");
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node **head, int position) {
    Node* temp = *head;
    if (*head == NULL) {
        printf("Nothing to delete\n");
        return;
    }
    if (position == 0) {
        deleteAtFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        Node* next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }
}

// concatenate

void concatenate(struct Node **head1, struct Node **head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
}

// printing
void print(struct Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head);

    printf("Linked list after inserting the node:20 at the end \n");
    insertAtLast(&head, 20);
    print(head);

    printf("Linked list after inserting the node:5 at the end \n");
    insertAtLast(&head, 5);
    print(head);

    printf("Linked list after inserting the node:30 at the end \n");
    insertAtLast(&head, 30);
    print(head);

    printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);

    printf("Linked list after deleting the first node: \n");
    deleteAtFirst(&head);
    print(head);

    printf("Linked list after deleting the last node: \n");
    deleteAtLast(&head);
    print(head);

    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head);

    head = reverse(&head);
    print(head);

    int found = search(&head, 15);
    if (found == 1) {
        printf("Found\n");
    }
    else {
        printf("Not Found\n");
    }

    Node *head1 = NULL;
    Node *head2 = NULL;

    // First list
    insertAtLast(&head1, 10);
    insertAtLast(&head1, 20);
    insertAtLast(&head1, 30);

    // Second list
    insertAtLast(&head2, 40);
    insertAtLast(&head2, 50);
    insertAtLast(&head2, 60);

    printf("List 1: ");
    print(head1);

    printf("List 2: ");
    print(head2);

    concatenate(&head1, &head2);

    printf("After concatenation: ");
    print(head1);

    return 0;
}
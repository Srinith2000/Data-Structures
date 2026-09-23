#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;


// ==================== CREATE NODE ====================

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}


// ==================== INSERT AT FIRST ====================

void insertAtFirst(node** head, int data) {
    node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}


// ==================== INSERT AT LAST ====================

void insertAtLast(node** head, int data) {
    node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


// ==================== INSERT AT POSITION ====================

void insertAtPosition(node** head, int data, int position) {

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtFirst(head, data);
        return;
    }

    node* temp = *head;

    // Move to node before required position
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    node* newNode = createNode(data);

    // Connect new node
    newNode->next = temp->next;
    newNode->prev = temp;

    // Connect next node back to new node
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    // Connect previous node to new node
    temp->next = newNode;
}


// ==================== PRINT FORWARD ====================

void print(node* head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = head;

    printf("Forward List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


// ==================== PRINT REVERSE ====================

void printReverse(node* head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = head;

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse List: ");

    // Move using prev
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}


// ==================== REVERSE DLL ====================

void reverse(node** head) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* current = *head;
    node* temp = NULL;

    while (current != NULL) {

        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node
        current = current->prev;
    }

    // Set new head
    if (temp != NULL) {
        *head = temp->prev;
    }
}


// ==================== DELETE FROM FIRST ====================

void deleteFromFirst(node** head) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = *head;

    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}


// ==================== DELETE FROM LAST ====================

void deleteFromLast(node** head) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = *head;

    // Only one node
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Remove last node
    temp->prev->next = NULL;

    free(temp);
}


// ==================== DELETE FROM POSITION ====================

void deleteFromPosition(node** head, int position) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteFromFirst(head);
        return;
    }

    node* temp = *head;

    // Move to required position
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    // Connect next node to previous node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Connect previous node to next node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


// ==================== CONCATENATION ====================

node* concatenate(node** head1, node** head2) {

    // If first list is empty
    if (*head1 == NULL) {

        *head1 = *head2;

        if (*head1 != NULL) {
            (*head1)->prev = NULL;
        }

        return *head1;
    }

    // If second list is empty
    if (*head2 == NULL) {
        return *head1;
    }

    node* temp = *head1;

    // Go to last node of first list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect last node of first list
    // to first node of second list
    temp->next = *head2;

    // Connect second list back to first list
    (*head2)->prev = temp;

    return *head1;
}


// ==================== MAIN ====================

int main() {

    node* head = NULL;

    // ---------------- INSERTION ----------------

    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtFirst(&head, 5);
    insertAtPosition(&head, 15, 2);

    printf("After Insertions:\n");
    print(head);

    /*
        List:

        5 <-> 10 <-> 15 <-> 20
    */


    // ---------------- PRINT REVERSE ----------------

    printf("\nPrinting in reverse:\n");
    printReverse(head);


    // ---------------- REVERSE LIST ----------------

    reverse(&head);

    printf("\nAfter reversing the list:\n");
    print(head);

    /*
        List:

        20 <-> 15 <-> 10 <-> 5
    */


    // ---------------- DELETE FIRST ----------------

    deleteFromFirst(&head);

    printf("\nAfter deleting first:\n");
    print(head);


    // ---------------- DELETE LAST ----------------

    deleteFromLast(&head);

    printf("\nAfter deleting last:\n");
    print(head);


    // ---------------- DELETE POSITION ----------------

    deleteFromPosition(&head, 1);

    printf("\nAfter deleting position 1:\n");
    print(head);


    // =================================================
    // CONCATENATION
    // =================================================

    node* head1 = NULL;
    node* head2 = NULL;


    // First list

    insertAtLast(&head1, 10);
    insertAtLast(&head1, 20);
    insertAtLast(&head1, 30);


    // Second list

    insertAtLast(&head2, 40);
    insertAtLast(&head2, 50);
    insertAtLast(&head2, 60);


    printf("\nList 1:\n");
    print(head1);

    printf("List 2:\n");
    print(head2);


    // Concatenate

    concatenate(&head1, &head2);


    printf("After concatenation:\n");
    print(head1);


    return 0;
}
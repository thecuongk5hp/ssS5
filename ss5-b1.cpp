#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to print the list in reverse order
void printReverse(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    // Traverse to the last node
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Print from the last node to the first node
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a doubly linked list: 1 <-> 3 <-> 5 <-> 7
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(5);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(7);
    head->next->next->next->prev = head->next->next;

    // Print the list in reverse order
    printReverse(head);

    return 0;
}


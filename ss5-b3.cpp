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

// Function to delete the last node
void deleteLastNode(Node** head) {
    if (*head == NULL) {
        // If the list is empty
        printf("Danh sách r?ng\n");
        return;
    }

    // If there's only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Danh sách r?ng\n");
        return;
    }

    // Traverse to the last node
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the second last node's next pointer
    current->prev->next = NULL;
    free(current);
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sách r?ng\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
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

    // Print the initial list
    printf("Danh sách ban ð?u: ");
    printList(head);

    // Delete the last node
    printf("Xóa ph?n t? cu?i:\n");
    deleteLastNode(&head);
    printList(head);

    // Delete all remaining nodes
    printf("Xóa ph?n t? cu?i:\n");
    deleteLastNode(&head);
    printList(head);

    printf("Xóa ph?n t? cu?i:\n");
    deleteLastNode(&head);
    printList(head);

    printf("Xóa ph?n t? cu?i:\n");
    deleteLastNode(&head);
    printList(head);

    return 0;
}


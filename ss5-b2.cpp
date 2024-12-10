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

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);

    // Case 1: Insert at the beginning
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Traverse to the position
    Node* current = *head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }

    // If position is invalid (beyond the end of the list)
    if (current == NULL) {
        printf("L?i: v? trí không h?p l?\n");
        free(newNode);
        return;
    }

    // Case 2: Insert in the middle or end
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a doubly linked list: 1 <-> 3 <-> 5
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(5);
    head->next->next->prev = head->next;

    // Print the initial list
    printf("Danh sách ban ð?u: ");
    printList(head);

    // Insert 4 at position 2
    printf("Chèn 4 vào v? trí 2:\n");
    insertAtPosition(&head, 4, 2);
    printList(head);

    // Try to insert 8 at invalid position 5
    printf("Chèn 8 vào v? trí 5:\n");
    insertAtPosition(&head, 8, 5);

    return 0;
}


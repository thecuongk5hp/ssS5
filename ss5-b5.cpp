#include <stdio.h>
#include <stdlib.h>

// Ð?nh ngh?a c?u trúc c?a m?t node trong danh sách liên k?t ðôi
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Hàm t?o m?t node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm ð?o ngý?c danh sách liên k?t ðôi
Node* reverseList(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // Ð?i hý?ng các con tr? prev và next cho t?ng node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Di chuy?n v? phía trý?c
    }

    // N?u danh sách không r?ng, c?p nh?t head
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Hàm in danh sách liên k?t ðôi
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm chính
int main() {
    // T?o danh sách liên k?t ðôi: 1 <-> 2 <-> 3 <-> 4
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Danh sach ban dau: ");
    printList(head);

    // Ð?o ngý?c danh sách
    head = reverseList(head);

    printf("Danh sach sau khi dao nguoc: ");
    printList(head);

    return 0;
}


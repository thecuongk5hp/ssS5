#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c c?a m?t node trong danh s�ch li�n k?t ��i
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// H�m t?o m?t node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// H�m �?o ng�?c danh s�ch li�n k?t ��i
Node* reverseList(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // �?i h�?ng c�c con tr? prev v� next cho t?ng node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Di chuy?n v? ph�a tr�?c
    }

    // N?u danh s�ch kh�ng r?ng, c?p nh?t head
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// H�m in danh s�ch li�n k?t ��i
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// H�m ch�nh
int main() {
    // T?o danh s�ch li�n k?t ��i: 1 <-> 2 <-> 3 <-> 4
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Danh sach ban dau: ");
    printList(head);

    // �?o ng�?c danh s�ch
    head = reverseList(head);

    printf("Danh sach sau khi dao nguoc: ");
    printList(head);

    return 0;
}


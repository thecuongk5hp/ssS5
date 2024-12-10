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

// H�m �?m s? l�?ng ph?n t? trong danh s�ch li�n k?t ��i
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// H�m ch�nh
int main() {
    // T?o danh s�ch li�n k?t ��i
    Node* head = createNode(2);
    head->next = createNode(4);
    head->next->prev = head;
    head->next->next = createNode(6);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(8);
    head->next->next->next->prev = head->next->next;

    // �?m s? l�?ng ph?n t?
    int count = countNodes(head);
    printf("So luong phan tu trong danh sach: %d\n", count);

    // Tr�?ng h?p danh s�ch r?ng
    Node* emptyList = NULL;
    printf("So luong phan tu trong danh sach rong: %d\n", countNodes(emptyList));

    return 0;
}


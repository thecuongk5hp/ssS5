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

// Hàm ð?m s? lý?ng ph?n t? trong danh sách liên k?t ðôi
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm chính
int main() {
    // T?o danh sách liên k?t ðôi
    Node* head = createNode(2);
    head->next = createNode(4);
    head->next->prev = head;
    head->next->next = createNode(6);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(8);
    head->next->next->next->prev = head->next->next;

    // Ð?m s? lý?ng ph?n t?
    int count = countNodes(head);
    printf("So luong phan tu trong danh sach: %d\n", count);

    // Trý?ng h?p danh sách r?ng
    Node* emptyList = NULL;
    printf("So luong phan tu trong danh sach rong: %d\n", countNodes(emptyList));

    return 0;
}


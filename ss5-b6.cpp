#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c c?a m?t node
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

// H�m th�m m?t node v�o cu?i danh s�ch
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// H�m in danh s�ch li�n k?t ��i
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

// H�m thay th? gi� tr? trong danh s�ch
void replace(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Da thay the gia tri %d bang %d.\n", oldValue, newValue);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay phan tu can thay the.\n");
}

int main() {
    Node* head = NULL;

    // T?o danh s�ch li�n k?t t? input
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Danh sach truoc khi thay the: ");
    printList(head);

    // Gi� tr? c?n thay th? v� gi� tr? m?i
    int oldValue = 2;
    int newValue = 10;

    // Th?c hi?n thay th?
    replace(head, oldValue, newValue);

    printf("Danh sach sau khi thay the: ");
    printList(head);

    return 0;
}


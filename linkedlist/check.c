#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void printLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* deleteAtHead(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next; 
    free(temp); 
    return head;
}

struct Node* deleteAtTail(struct Node* head) {
    if (head == NULL) return NULL; 
    if (head->next == NULL) { 
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next); 
    temp->next = NULL;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) return NULL; 
    if (position == 1) return deleteAtHead(head); 

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next; 
    }
    if (temp == NULL || temp->next == NULL) return head; 

    struct Node* nodeToDelete = temp->next; 
    temp->next = nodeToDelete->next;
    free(nodeToDelete); 
    return head;
}
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) return NULL;
    if (head->data == value) {
        return deleteAtHead(head);
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; 
        free(nodeToDelete);
    }

    return head;
}
int main() {
    struct Node* head = NULL;
    head = insertAtHead(head, 300); // 300
    head = insertAtHead(head, 200); // 200 -> 300
    head = insertAtHead(head, 100); // 100 -> 200 -> 300

    printf("Initial list: ");
    printLL(head);

    head = deleteAtHead(head);
    printf("After deleting head: ");
    printLL(head);

    head = deleteAtTail(head);
    printf("After deleting tail: ");
    printLL(head);

    head = deleteAtPosition(head, 1); // Delete first position
    printf("After deleting at position 1: ");
    printLL(head);

    head = deleteByValue(head, 200); // Delete by value
    printf("After deleting value 200: ");
    printLL(head);

    return 0;
}

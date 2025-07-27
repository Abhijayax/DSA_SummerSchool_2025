#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void append(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void reverseDLL(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    reverseDLL(&slow);
    struct Node* firstHalf = head;
    struct Node* secondHalf = slow;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);

    printf("Original DLL:\n");
    printList(head);

    if (isPalindrome(head))
        printf("\n The DLL is a palindrome!\n");
    else
        printf("\n The DLL is NOT a palindrome!\n");

    return 0;
}

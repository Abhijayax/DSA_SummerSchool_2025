#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* reverseInGroups(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    
    while (current != NULL) {
        struct Node* groupHead = NULL;
        struct Node* groupTail = current;
        int count = 0;

        while (current != NULL && count < k) {
            
            struct Node* next = current->next;
            
            current->next = groupHead;
            if (groupHead != NULL) {
                groupHead->prev = current;
            }
            
            groupHead = current;
            groupHead->prev = NULL;
            current = next;
            count++;
        }
        
        if (newHead == NULL) {
            newHead = groupHead; 
            if (newHead != NULL) {
                newHead->prev = NULL;
            }
            tail = groupTail;
        } else {
            tail->next = groupHead;
            if (groupHead != NULL) {
                groupHead->prev = tail;
            }
            tail = groupTail;
        }
    }
    
    return newHead;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = node->prev = NULL;
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
    printf("NULL ← ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" ⇄ ");
        }
        head = head->next;
    }
    printf(" → NULL\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 1; i <= 9; i++) {
        append(&head, i);
    }
    
    printf("Original list:\n");
    printList(head);
    
    int k = 4;
    head = reverseInGroups(head, k);
    
    printf("\nList after reversing in groups of %d:\n", k);
    printList(head);
    
    return 0;
}

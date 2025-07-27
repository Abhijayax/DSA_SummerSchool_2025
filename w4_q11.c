#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    
    while (current != NULL) {
        next = current->next;  
        current->next = prev; 
        prev = current;        
        current = next;        
    }
  
    return prev;
}

struct ListNode* newNode(int data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    
    printf("Original List: ");
    printList(head);
    
    head = reverseList(head);
    
    printf("Reversed List: ");
    printList(head);
    
    return 0;
}

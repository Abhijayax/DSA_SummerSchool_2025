#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteNodesWithValue(struct Node** head, int x) {
    struct Node* current = *head;
    struct Node* temp;

    while (current != NULL) {
        if (current->data == x) {
        
            temp = current->next;

            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            current = temp; 
        } else {
            current = current->next; 
        }
    }
}

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

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 6);

    printf("Original DLL:\n");
    printList(head);

    int x = 2;
    deleteNodesWithValue(&head, x);
    printf("\nDLL after deleting nodes with value %d:\n", x);
    printList(head);

    return 0;
}

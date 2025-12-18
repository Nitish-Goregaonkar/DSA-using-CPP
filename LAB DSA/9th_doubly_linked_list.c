#include <stdio.h>
#include <stdlib.h>

// Structure definition for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    // Allocate memory for nodes
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    // Assign data
    node1->data = 100;
    node2->data = 200;
    node3->data = 300;

    // Link nodes
    node1->prev = NULL;  // Start of the list
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = NULL;  // End of the list

    // Traversal example
    struct Node* temp = node1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

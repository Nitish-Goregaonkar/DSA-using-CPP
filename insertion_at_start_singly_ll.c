#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    char data;
    struct node *link;
};

int main() {
    // Step 1: Create the old list with three nodes for example
    struct node *head, *second, *third;

    // Allocating nodes
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Initializing nodes
    head->data = 'B';
    head->link = second;

    second->data = 'C';
    second->link = third;

    third->data = 'E';
    third->link = NULL;

    // Step 2: Create a new node
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 'A';

    // Step 3: Link new node to current head
    ptr->link = head;

    // Step 4: Update head to new node
    head = ptr;

    // Print the list to verify
    struct node *temp = head;
    printf("Linked list after inserting new node at beginning:\n");
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct node *next = temp->link;
        free(temp);
        temp = next;
    }

    return 0;
}

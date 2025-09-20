#include <stdio.h>
#include <stdlib.h>

// Definition of node structure
struct node {
    char data;
    struct node *link;
};

int main() {
    // Step 1: Create the existing linked list with three nodes
    struct node *head, *second, *third;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 'B';
    head->link = second;

    second->data = 'C';
    second->link = third;

    third->data = 'E';
    third->link = NULL;

    // Step 2: Create the new node and fill its data
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 'A';
    ptr->link = NULL;

    // Step 3: Find the last node
    struct node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    // Step 4: Link last node to new node
    temp->link = ptr;

    // Print the list to verify
    temp = head;
    printf("Linked list after inserting new node at end:\n");
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

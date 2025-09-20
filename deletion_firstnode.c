#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Create initial linked list: 10 -> 20 -> 30 -> 50
    int values[] = {10, 20, 30, 50};
    int n = sizeof(values)/sizeof(values[0]);
    struct node *head = NULL, *temp = NULL, *new_node = NULL;

    // Building the linked list using a loop
    for (int i = 0; i < n; i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = values[i];
        new_node->link = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->link = new_node;
            temp = new_node;
        }
    }

    // Print original list
    printf("Original linked list:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    // Steps to delete the first node
    struct node *delNode = head;   // Step 1
    head = head->link;             // Step 2
    free(delNode);                 // Step 3

    // Print list after deletion
    printf("After deleting the first node:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    // Free rest of memory
    temp = head;
    while (temp != NULL) {
        struct node *next = temp->link;
        free(temp);
        temp = next;
    }
    return 0;
}

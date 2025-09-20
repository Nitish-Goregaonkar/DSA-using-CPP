#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Create initial linked list: 10 -> 20 -> 30 -> 50 -> 60
    int values[] = {10, 20, 30, 50, 60};
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

    // Steps to delete the last node
    if (head != NULL && head->link != NULL) { 
        struct node *ptr = head;
        struct node *ptrNext = head->link;
        // Traverse to last but one node
        while (ptrNext->link != NULL) {
            ptr = ptrNext;
            ptrNext = ptrNext->link;
        }
        // Step 1: Set previous node's link to NULL
        ptr->link = NULL;
        // Step 2: Store address of last node
        struct node *delNode = ptrNext;
        // Step 3: Free memory of last node
        free(delNode);
    } else if (head != NULL) {
        // Only one node exists, so delete it
        free(head);
        head = NULL;
    }

    // Print list after deletion
    printf("After deleting the last node:\n");
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

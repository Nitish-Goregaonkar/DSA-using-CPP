#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find LOC (node containing item) and LOCP (previous node)
// start: head of the list
// item: value being searched for
// loc: pointer to store the address of node containing item (output)
// locp: pointer to store the address of previous node (output)
void findLOCAndLOCP(struct Node* start, int item, struct Node** loc, struct Node** locp) {
    struct Node *save, *ptr;

    // Step 1: If the list is empty, set both loc and locp to NULL and return
    if (start == NULL) {
        *loc = NULL;
        *locp = NULL;
        return;
    }

    // Step 2: If the first node contains the item, set loc to start and locp to NULL
    if (start->data == item) {
        *loc = start;
        *locp = NULL;
        return;
    }

    // Step 3: Initialize traversal pointers: save for previous node, ptr for current node
    save = start;
    ptr = start->next;

    // Step 4: Traverse the list from the second node onwards
    // If item is found, set loc to its address and locp to the previous node's address
    while (ptr != NULL) {
        if (ptr->data == item) {
            *loc = ptr;
            *locp = save;
            return;
        }
        save = ptr;       // move both pointers one step forward
        ptr = ptr->next;
    }

    // Step 7: If item not found, set loc to NULL and locp to last node checked
    *loc = NULL;
    *locp = save;
}

// Function to insert a new node with given data at the end of the list
void insert_end(struct Node** head, int data) {
    // Allocate memory for new node and initialize
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If list is empty, new node becomes the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    // Link the new node at the end
    last->next = newNode;
}

int main() {
    struct Node* head = NULL;  // Pointer to the head of the list
    struct Node* loc = NULL;   // Will store address of node with item
    struct Node* locp = NULL;  // Will store address of previous node

    // Create a simple linked list: 10->20->30->40
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);

    int item = 30; // value to search in the list

    // Find the location of item and its previous node
    findLOCAndLOCP(head, item, &loc, &locp);

    // Display result
    if (loc != NULL)
        printf("Item %d found at node address %p\n", item, (void*)loc);
    else
        printf("Item %d not found in the list\n", item);

    if (locp != NULL)
        printf("Previous node address is %p\n", (void*)locp);
    else
        printf("Previous node is NULL (first node)\n");

    return 0;
}

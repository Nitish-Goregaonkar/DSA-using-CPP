#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char label;              // Node label like 'A', 'B', etc.
    int data;                // Node data
    struct Node* next;       // Pointer to next node
};

int main() {
    // Create nodes
    struct Node* nodeA = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodeB = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodeC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodeD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* nodeE = (struct Node*)malloc(sizeof(struct Node));

    // Assign labels and data as per diagram
    nodeA->label = 'A'; nodeA->data = 20;
    nodeB->label = 'B'; nodeB->data = 30;
    nodeC->label = 'C'; nodeC->data = 40;
    nodeD->label = 'D'; nodeD->data = 50;
    nodeE->label = 'E'; nodeE->data = 10;

    // Link nodes to make it circular
    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nodeE;
    nodeE->next = nodeA; // Circular link back to start

    // Traversal—print labels and data once around the circle
    struct Node* temp = nodeA;
    do {
        printf("%c: %d\n", temp->label, temp->data);
        temp = temp->next;
    } while (temp != nodeA);

    // Free nodes
    free(nodeA);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeE);

    return 0;
}

// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) return;
//     struct Node* temp = *head;
//     if (temp->next == *head) { // only one node
//         free(temp);
//         *head = NULL;
//         return;
//     }
//     struct Node* last = *head;
//     while (last->next != *head)
//         last = last->next;
//     last->next = temp->next;
//     *head = temp->next;
//     free(temp);
// }

// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     if (*head == NULL) {
//         newNode->next = newNode;
//         *head = newNode;
//         return;
//     }
//     struct Node* temp = *head;
//     while (temp->next != *head) {
//         temp = temp->next;
//     }
//     newNode->next = *head;
//     temp->next = newNode;
//     *head = newNode;
// }

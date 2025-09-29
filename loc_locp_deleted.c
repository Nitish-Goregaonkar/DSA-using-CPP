#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* avail = NULL;  // Global pointer for available nodes (free pool)
struct Node* getNode(int data) {
    struct Node* newNode;
    if (avail != NULL) {
        // Reuse node from avail list
        newNode = avail;
        avail = avail->next;
    } else {
        // Allocate new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_end(struct Node** head, int data) {
    struct Node* newNode = getNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

void delete_node(struct Node** head, int item) {
    struct Node *ptr = *head, *prev = NULL;

    while (ptr != NULL && ptr->data != item) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Item %d not found.\n", item);
        return;
    }

    // Adjust pointers to remove node from list
    if (prev == NULL) 
        *head = ptr->next;
    else
        prev->next = ptr->next;

    // Add node to avail list instead of freeing
    ptr->next = avail;
    avail = ptr;
    printf("Item %d deleted and added to avail list.\n", item);
}
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void print_avail() {
    printf("Avail nodes: ");
    struct Node* temp = avail;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;

    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);

    printf("List: ");
    print_list(head);

    delete_node(&head, 20);
    printf("List after deletion: ");
    print_list(head);

    print_avail();

    insert_end(&head, 40);  // This will reuse a node from avail if any

    printf("List after adding 40: ");
    print_list(head);

    print_avail();

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *link;
// };
// struct node *start;
// int main() {
//     // Create first node
//     start = (struct node*)malloc(sizeof(struct node));
//     start->data = 10;
//     // Create second node
//     struct node *second = (struct node*)malloc(sizeof(struct node));
//     second->data = 20;  
//     start->link = second;
//     // Create third node
//     struct node *third = (struct node*)malloc(sizeof(struct node));
//     third->data = 30;
//     second->link = third;
//     // Create fourth node
//     struct node *fourth = (struct node*)malloc(sizeof(struct node));
//     fourth->data = 50;
//     third->link = fourth;
//     // Create fifth node
//     struct node *fifth = (struct node*)malloc(sizeof(struct node));
//     fifth->data = 50;
//     fourth->link = fifth;
//     fifth->link = NULL; // End of list
//     // Traverse and print linked list
//     struct node *ptr = start;
//     if (ptr == NULL)
//         printf("Linked list is empty\n");
//     else {
//         while (ptr != NULL) {
//             printf("Data: %d\n", ptr->data);
//             ptr = ptr->link;
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;   // head pointer

// Insert a new node at the beginning
void insert_beginning(int item) {
    // create a new node & store address into variable called ptr
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return;
    }

    // Copy the data into data field of the node
    ptr->data = item;

    // copy start node address into link field of newnode
    ptr->link = start;

    // Update the head pointer that is now head will point to new node
    start = ptr;
}

// Delete a node from the beginning
void delete_beginning() {
    // if list empty
    if (start == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    // Copy Start value into the temporary pointer variable called DEL
    struct node *del = start;

    // Update the start pointer value after delete
    // start will point to the second node in the linked list
    start = start->link;

    // Deallocate the memory occupied by the first node using free(del)
    free(del);
}

// Traverse and print linked list
void display() {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("Linked list is empty\n");
    } else {
        while (ptr != NULL) {
            printf("Data: %d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}

int main() {
    // Create first node
    start = (struct node*)malloc(sizeof(struct node));
    start->data = 10;

    // Create second node
    struct node *second = (struct node*)malloc(sizeof(struct node));
    second->data = 20;
    start->link = second;

    // Create third node
    struct node *third = (struct node*)malloc(sizeof(struct node));
    third->data = 30;
    second->link = third;

    // Create fourth node
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    fourth->data = 40;
    third->link = fourth;

    // Create fifth node
    struct node *fifth = (struct node*)malloc(sizeof(struct node));
    fifth->data = 50;
    fourth->link = fifth;
    fifth->link = NULL; // End of list

    printf("Original list:\n");
    display();

    // Insert new node at beginning
    insert_beginning(5);
    printf("\nAfter insertion at beginning (5):\n");
    display();

    // Delete node from beginning
    delete_beginning();
    printf("\nAfter deletion from beginning:\n");
    display();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start;
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
    fourth->data = 50;
    third->link = fourth;
    // Create fifth node
    struct node *fifth = (struct node*)malloc(sizeof(struct node));
    fifth->data = 50;
    fourth->link = fifth;
    fifth->link = NULL; // End of list
    
    // Traverse and print linked list
    struct node *ptr = start;
    if (ptr == NULL)
        printf("Linked list is empty\n");
    else {
        while (ptr != NULL) {
            printf("Data: %d\n", ptr->data);
            ptr = ptr->link;
        }
    }
    
    return 0;
}
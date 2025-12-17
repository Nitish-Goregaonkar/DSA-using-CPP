#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;   // start of the list

/* Function prototypes */
void insert_end(int x);
void delete_first(void);
void display(void);

int main(void)
{
    int choice, x;

    while (1) {
        printf("\n1. Insert at end");
        printf("\n2. Delete first node");
        printf("\n3. Display list");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &x);
            insert_end(x);
            break;
        case 2:
            delete_first();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

/* (i) Insert a new node at the end */
void insert_end(int x)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    /* If list is empty, new node becomes first node */
    if (head == NULL) {
        head = newNode;
        return;
    }

    /* Otherwise, traverse to last node */
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;      // link new node at the end
}

/* (ii) Delete the first node */
void delete_first(void)
{
    struct Node *temp;

    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }

    temp = head;              // node to delete
    head = head->next;        // move head to second node
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

/* Display entire list */
void display(void)
{
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

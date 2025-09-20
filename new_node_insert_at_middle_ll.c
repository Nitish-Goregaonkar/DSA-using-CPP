#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *link;
};

int main() {
    char values[] = {'B', 'C', 'E', 'F', 'G'};
    int n = sizeof(values)/sizeof(values[0]);
    struct node *head = NULL, *temp = NULL, *new_node = NULL;

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

    // Print the list to verify
    temp = head;
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

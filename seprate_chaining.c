#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Node {
    int key;
    struct Node *next;
};

struct Node *table[SIZE];

int hash(int k) { return k % SIZE; }

void insert(int k) {
    int i = hash(k);
    struct Node *n = malloc(sizeof(struct Node));
    n->key = k;
    n->next = table[i];
    table[i] = n;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node *cur = table[i];
        while (cur) {
            printf("%d -> ", cur->key);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(1);
    insert(6);
    insert(11);
    insert(2);
    display();
    return 0;
}

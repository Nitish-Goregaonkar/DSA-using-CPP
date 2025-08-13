#include <stdio.h>

#define SIZE 5
#define EMPTY -1

int table[SIZE];

int hash(int k) { return k % SIZE; }

void insert(int k) {
    int i = hash(k);
    for (int j = 0; j < SIZE; j++) {
        int idx = (i + j) % SIZE;
        if (table[idx] == EMPTY) {
            table[idx] = k;
            break;
        }
    }
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, table[i]);
}

int main() {
    for (int i = 0; i < SIZE; i++) table[i] = EMPTY;
    insert(1);
    insert(6);
    insert(11);
    insert(2);
    display();
    return 0;
}

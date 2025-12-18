// #include <stdio.h>

// #define SIZE 7
// #define EMPTY -1
// #define DELETED -2

// int hashTable[SIZE];

// // Initialize hash table
// void init() {
//     for (int i = 0; i < SIZE; i++) {
//         hashTable[i] = EMPTY;
//     }
// }

// // Hash function
// int hashFunction(int key) {
//     return key % SIZE;
// }

// // Insert key
// void insert(int key) {
//     int hashIndex = hashFunction(key);
//     int originalIndex = hashIndex;
    
//     while (hashTable[hashIndex] != EMPTY && hashTable[hashIndex] != DELETED && hashTable[hashIndex] != key) {
//         hashIndex = (hashIndex + 1) % SIZE;
//         if (hashIndex == originalIndex) {
//             printf("Hash table full, cannot insert key %d\n", key);
//             return;
//         }
//     }
//     hashTable[hashIndex] = key;
// }

// // Search key
// int search(int key) {
//     int hashIndex = hashFunction(key);
//     int originalIndex = hashIndex;
    
//     while (hashTable[hashIndex] != EMPTY) {
//         if (hashTable[hashIndex] == key)
//             return 1;
//         hashIndex = (hashIndex + 1) % SIZE;
//         if (hashIndex == originalIndex)
//             return 0;
//     }
//     return 0;
// }

// // Delete key
// void delete(int key) {
//     int hashIndex = hashFunction(key);
//     int originalIndex = hashIndex;
    
//     while (hashTable[hashIndex] != EMPTY) {
//         if (hashTable[hashIndex] == key) {
//             hashTable[hashIndex] = DELETED;
//             return;
//         }
//         hashIndex = (hashIndex + 1) % SIZE;
//         if (hashIndex == originalIndex)
//             return;
//     }
// }

// // Display hash table
// void display() {
//     for (int i = 0; i < SIZE; i++) {
//         if (hashTable[i] == EMPTY)
//             printf("Slot %d: EMPTY\n", i);
//         else if (hashTable[i] == DELETED)
//             printf("Slot %d: DELETED\n", i);
//         else
//             printf("Slot %d: %d\n", i, hashTable[i]);
//     }
// }

// int main() {
//     init();
    
//     insert(10);
//     insert(20);
//     insert(15);
    
//     display();
    
//     printf("Search 15: %s\n", search(15) ? "Found" : "Not Found");
    
//     delete(15);
//     display();
    
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// initialize: -1 means empty, -2 means deleted
void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// insert
void insert(int key) {
    int index = hash(key);
    int start = index;

    // find next empty or deleted slot
    while (hashTable[index] != -1 && hashTable[index] != -2) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash table full\n");
            return;
        }
    }
    hashTable[index] = key;
}

// search
int search(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1) {      // stop when empty slot
        if (hashTable[index] == key)
            return index;                 // found
        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;                        // full cycle
    }
    return -1;                            // not found
}

// delete
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("%d not found\n", key);
        return;
    }
    hashTable[index] = -2;                // mark as deleted
    printf("%d deleted\n", key);
}

// display
void display() {
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);
}

int main() {
    init();

    insert(12);
    insert(25);
    insert(36);
    insert(20);
    insert(30);

    display();

    printf("Search 36: %d\n", search(36));
    deleteKey(25);
    display();

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 7

// // Node structure for linked list
// typedef struct Node {
//     int key;
//     struct Node* next;
// } Node;
// Node* hashTable[SIZE];
// // Hash function
// int hashFunction(int key) {
//     return key % SIZE;
// }
// // Insert key into hash table
// void insert(int key) {
//     int hashIndex = hashFunction(key);
//     Node* newNode = (Node*) malloc(sizeof(Node));
//     newNode->key = key;
//     newNode->next = hashTable[hashIndex];
//     hashTable[hashIndex] = newNode;
// }
// // Search key in hash table
// int search(int key) {
//     int hashIndex = hashFunction(key);
//     Node* temp = hashTable[hashIndex];
//     while (temp != NULL) {
//         if (temp->key == key)
//             return 1;
//         temp = temp->next;
//     }
//     return 0;
// }
// // Delete key from hash table
// void delete(int key) {
//     int hashIndex = hashFunction(key);
//     Node* temp = hashTable[hashIndex];
//     Node* prev = NULL;
//     while (temp != NULL && temp->key != key) {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL) return; // Key not found
//     if (prev == NULL) {
//         hashTable[hashIndex] = temp->next;
//     } else {
//         prev->next = temp->next;
//     }
//     free(temp);
// }
// // Display hash table
// void display() {
//     for (int i = 0; i < SIZE; i++) {
//         printf("Bucket %d: ", i);
//         Node* temp = hashTable[i];
//         while (temp != NULL) {
//             printf("%d -> ", temp->key);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }
// int main() {
//     for(int i = 0; i < SIZE; i++) {
//         hashTable[i] = NULL;
//     }
//     insert(10);
//     insert(20);
//     insert(15);
//     display();
//     printf("Search 20: %s\n", search(20) ? "Found" : "Not Found");
//     delete(20);
//     display();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define size 10
// typedef struct Node
// {
//     int key;
//     struct Node *link;
// } node;
// node *hashtable[size];
// int hashfunction(int key)
// {
//     return key % size;
// }
// void insert(int key)
// {
//     int hashindex = hashfunction(key);
//     node *newnode = (node *)malloc(sizeof(node));
//     newnode->key = key;
//     newnode->link = hashtable[hashindex];
//     hashtable[hashindex] = newnode;
// }
// int search(int key)
// {
//     int hashindex = hashfunction(key);
//     node *temp = hashtable[hashindex];
//     while (temp != NULL)
//     {
//         if (temp->key == key)
//         {
//             return 1;
//         }
//         temp = temp->link;
//     }
//     return 0;
// }
// void delete(int key)
// {
//     int hashindex = hashfunction(key);
//     node *temp = hashtable[hashindex];
//     node *prev = NULL;
//     while (temp != NULL && temp->key != key)
//     {
//         prev = temp;
//         temp = temp->link;
//     }
//     if (temp == NULL)
//     {
//         return;
//     }
//     if (prev == NULL)
//     {
//         hashtable[hashindex] = temp->link;
//     }
//     else
//     {
//         prev->link = temp->link;
//     }
//     free(temp);
// }
// void display()
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("Bucket %d:", i);
//         node *temp = hashtable[i];
//         while (temp != NULL)
//         {
//             printf("%d->", temp->key);
//             temp = temp->link;
//         }
//         printf("NULL\n");
//     }
// }
// int main()
// {
//     for (int i = 0; i < size; i++)
//     {
//         hashtable[i] = NULL;
//     }

//     int x[]={1,3,8,10,33,18,21};
//     for(int i=0;i<7;i++){
//         insert(x[i]);
//     }
//     display();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 10

// typedef struct Node {
//     int key;
//     struct Node *next;
// } Node;

// Node *table[SIZE];

// int hash(int key) {
//     return key % SIZE;
// }

// void insert(int key) {
//     int h = hash(key);
//     Node *n = malloc(sizeof(Node));
//     n->key = key;
//     n->next = table[h];     // insert at beginning of chain
//     table[h] = n;
// }

// int search(int key) {
//     for (Node *p = table[hash(key)]; p != NULL; p = p->next)
//         if (p->key == key) return 1;
//     return 0;
// }

// void erase(int key) {
//     int h = hash(key);
//     Node *p = table[h], *prev = NULL;

//     while (p && p->key != key) {
//         prev = p;
//         p = p->next;
//     }
//     if (!p) return;             // not found

//     if (!prev) table[h] = p->next;
//     else       prev->next = p->next;
//     free(p);
// }

// void display(void) {
//     for (int i = 0; i < SIZE; i++) {
//         printf("Bucket %d: ", i);
//         for (Node *p = table[i]; p; p = p->next)
//             printf("%d -> ", p->key);
//         printf("NULL\n");
//     }
// }

// int main(void) {
//     int keys[] = {1, 3, 8, 10, 33, 18, 21};
//     int n = sizeof(keys)/sizeof(keys[0]);

//     for (int i = 0; i < SIZE; i++) table[i] = NULL;

//     for (int i = 0; i < n; i++) insert(keys[i]);

//     display();
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE];

// hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// insert key
void insert(int key) {
    int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->key  = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// search key
int search(int key) {
    int index = hash(key);
    struct Node *temp = hashTable[index];

    while (temp) {
        if (temp->key == key)
            return index;          // found
        temp = temp->next;
    }
    return -1;                     // not found
}

// delete key  (same logic as in your notes)
void deleteKey(int key) {
    int index = hash(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while (temp && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {                               // key not present
        printf("%d not found\n", key);
        return;
    }

    if (!prev)                                 // first node in chain
        hashTable[index] = temp->next;
    else                                       // middle / last node
        prev->next = temp->next;

    free(temp);
    printf("%d deletion\n", key);
}

// small display using for
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        for (struct Node *p = hashTable[i]; p; p = p->next)
            printf("%d -> ", p->key);
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    insert(12);
    insert(25);
    insert(36);
    insert(20);
    insert(30);

    display();

    printf("Search 30: %d\n", search(30));
    deleteKey(25);
    display();

    return 0;
}



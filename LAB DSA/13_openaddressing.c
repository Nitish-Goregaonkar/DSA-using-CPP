// // #include<stdio.h>
// // #define size
// // struct Node
// // {
// //     int data;
// // };
// // struct Node *hashtable[size];
// // int hashfunction(int key){
// //     return key%size;
// // }
// // void insert (int key){
// //     int index=
    
// // }
// // int main(){
// //     for (int i =0;i<size;i++){
// //         hashtable[i]=NULL;
// //     }
// //     return 0;
// // }
// #include <stdio.h>

// #define size 10

// int hashtable[size];

// // Hash function
// int hashfunction(int key) {
//     return key % size;
// }   

// // Insert using simple linear probing
// void insert(int key) {
//     int index = hashfunction(key);

//     while (hashtable[index] != -1) {
//         index = (index + 1) % size;  // move to next index
//     }

//     hashtable[index] = key;
// }

// void display() {
//     for (int i = 0; i < size; i++) {
//         printf("Index %d: %d\n", i, hashtable[i]);
//     }
// }

// int main() {
//     // Initialize table with -1 meaning "empty"
//     for (int i = 0; i < size; i++) {
//         hashtable[i] = -1;
//     }

//     insert(15);
//     insert(25);
//     insert(35);
//     insert(5);

//     display();

//     return 0;
// }
// Open Addressing - Linear Probing
#include <stdio.h>

#define size 10

int hashtable[size];  // store integers directly

int hashfunction(int key) {
    return key % size;
}

void insert(int key) {
    int index = hashfunction(key);

    int start = index;

    // linear probing
    while (hashtable[index] != -1) {
        index = (index + 1) % size;

        if (index == start) {
            printf("Hash Table is full!\n");
            return;
        }
    }

    hashtable[index] = key;
}

void display() {
    for (int i = 0; i < size; i++) {
        if (hashtable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashtable[i]);
    }
}

int main() {
    int key[] = {10, 25, 30, 40, 50};  
    int n = sizeof(key)/sizeof(key[0]);

    // initialize table with -1 for empty
    for (int i = 0; i < size; i++)
        hashtable[i] = -1;

    for (int i = 0; i < n; i++)
        insert(key[i]);

    display();
    return 0;
}



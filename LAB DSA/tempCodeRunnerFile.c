#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Find Minimum key
int findMin(struct Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL)
        root = root->left;

    return root->key;
}

// Find Maximum key
int findMax(struct Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->key;
}

// Search for a key
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Find predecessor
int predecessor(struct Node* root, int key) {
    struct Node* current = search(root, key);
    if (current == NULL) return -1;

    // Case 1: left subtree exists
    if (current->left != NULL) {
        return findMax(current->left);
    }

    // Case 2: no left subtree → use ancestors
    struct Node* pred = NULL;
    while (root != NULL) {
        if (key > root->key) {
            pred = root;
            root = root->right;
        }
        else if (key < root->key) {
            root = root->left;
        }
        else break;
    }
    return pred ? pred->key : -1;
}

// Find successor
int successor(struct Node* root, int key) {
    struct Node* current = search(root, key);
    if (current == NULL) return -1;

    // Case 1: right subtree exists
    if (current->right != NULL) {
        return findMin(current->right);
    }

    // Case 2: use ancestors
    struct Node* succ = NULL;
    while (root != NULL) {
        if (key < root->key) {
            succ = root;
            root = root->left;
        }
        else if (key > root->key) {
            root = root->right;
        }
        else break;
    }
    return succ ? succ->key : -1;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else { // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children: Get inorder successor
        int minRight = findMin(root->right);
        root->key = minRight;
        root->right = deleteNode(root->right, minRight);
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert sample values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Minimum key = %d\n", findMin(root));
    printf("Maximum key = %d\n", findMax(root));

    // Search
    int key = 40;
    printf("Search %d: %s\n", key, search(root, key) ? "Found" : "Not Found");

    // Predecessor and successor
    printf("Predecessor of 60 = %d\n", predecessor(root, 60));
    printf("Successor of 60 = %d\n", successor(root, 60));

    // Deletion
    root = deleteNode(root, 30);
    printf("Node 30 deleted successfully.\n");

    return 0;
}
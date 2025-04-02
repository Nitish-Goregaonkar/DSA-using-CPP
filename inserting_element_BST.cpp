#include <iostream>
using namespace std;
class BST
{
    int data;
    BST *left, *right;
    public:
        // Default constructor.
        BST();
        // Parameterized constructor.
        BST(int);
        // Insert function.
        BST* Insert(BST *, int);
        // Inorder traversal.
        void Inorder(BST *);
};


// C++ program to detect loop in a linked list
// using hashset
#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};
b
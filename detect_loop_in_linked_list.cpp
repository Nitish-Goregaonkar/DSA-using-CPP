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
bool detectLoop(Node* head) {
    unordered_set<Node*>st;
    while (head != nullptr) {
        // If this node is already present
        // in hashmap it means there is a cycle
       \
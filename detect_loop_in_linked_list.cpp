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
        if (st.find(head) != st.end())
            return true;
        // If we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);
        head = head->next;
    }
    return false;
}
int main() {
    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* head = new Node(1);

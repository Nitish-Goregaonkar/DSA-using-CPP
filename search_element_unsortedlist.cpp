#include <iostream>

using namespace std;

struct node {
    int info;
    struct node *link;
} *start = NULL;

int main() {
    int i = 0, item, data, count = 0, flag = 0, n;
    struct node *ptr;

    cout << "Enter the size of the linked list\n";
    cin >> n;

    while (i < n) {
        cin >> data;
        struct node *temp = new node;  // No need for 'struct' in C++
        temp->info = data;
        temp->link = NULL;

        if (start == NULL)
            start = temp;
        else {
            ptr = start;
            while (ptr->link != NULL)
                ptr = ptr->link;
            ptr->link = temp;
        }
        i++;
    }

   
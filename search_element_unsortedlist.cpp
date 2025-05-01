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
    cout << "Elements in the linked list are as follows:\n";
    struct node *p = start;
    while (p != NULL) {
        cout << p->info << "\t";
        p = p->link;
    }
    cout << "\n";
    cout << "Enter the element you want to search\n";
    cin >> item;
    struct node *q = start;
    while (q != NULL) {
        count++;
        if (q->info == item) {
            cout << "Element found at position " << count << "\n";
            flag = 1;
            break;
        }
        q = q->link;
    }

    if (flag == 0)
        cout << "Element not found\n";

    // Free allocated memory
    struct node *temp;
    while (start != NULL) {
        temp = start;
        start = start->link;
        delete temp;
    }

    return 0;
}

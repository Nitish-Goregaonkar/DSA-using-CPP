#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int data[MAX];
    int beg, end, mid, item, i, n;

    cout << "Enter the size and elements of the array\n";
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> data[i];

    cout << "Following is the given array\n";
    for (i = 0; i < n; i++)
        cout << data[i] << "\t";
    
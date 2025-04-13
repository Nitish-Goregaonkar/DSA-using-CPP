#include <iostream>
using namespace std;
#define MAX 100
int main() {
    int beg, mid, end, n, item;
    int data[MAX];
    cout << "Enter the size and elements of an array in ascending order\n";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    
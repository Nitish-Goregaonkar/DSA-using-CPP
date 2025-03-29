#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int data[MAX];
    int k, ptr, n, i, temp;

    cout << "Enter the size and elements of the array\n";
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> data[i];

    cout << "***** Array before sorting **********\n";
    for (i = 0; i < n; i++)
        cout << data[i] << "\t";
    cout << "\n";

    
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

    // Use of bubble sort for sorting
    for (k = 1; k < n; k++) {
        ptr = 0;
        while (ptr < n - k) {
            if (data[ptr] > data[ptr + 1]) {
                // Swap elements
                temp = data[ptr];
                data[ptr] = data[ptr + 1];
                data[ptr + 1] = temp;
            }
            ptr++;
        }
    }

    cout << "***** Array after sorting **********\n";
    for (i = 0; i < n; i++)
        cout << data[i] << "\t";
    cout << "\n";

    return 0;
}

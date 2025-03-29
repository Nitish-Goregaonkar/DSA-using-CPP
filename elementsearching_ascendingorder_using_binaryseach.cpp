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

    cout << "***** Given Array **********\n";
    for (int i = 0; i < n; i++)
        cout << data[i] << "\t";
    cout << "\n";

    cout << "Enter the element you are searching for\n";
    cin >> item;

    beg = 0;
    end = n - 1;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (data[mid] == item) {
            cout << "The element is found at index: " << mid + 1 << "\n";
            return 0;
        } else if (item < data[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    cout << "The element is not present in the array\n";
    return 0;
}

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
    cout << "\n";

    cout << "Enter the element you want to search:\n";
    cin >> item;

    // Implementing Linear Search with Sentinel
    data[n] = item;  // Sentinel element
    i = 0;

    while (data[i] != item)
        i++;

    if (i == n)
        cout << "The element that you are searching for is not present in the array\n";
    else
        cout << "The element is found at location= " << i + 1 << "\n";

    return 0;
}

#include <iostream>
using namespace std;
#define MAX 100

int main() {
    int j, k, n, item;
    int LA[MAX];

    cout << "Enter size and elements of the array\n";
    cin >> n;

    for (j = 0; j < n; j++)
        cin >> LA[j];

    cout << "*****Array before deletion********\n";
    for (j = 0; j < n; j++)
        cout << LA[j] << "\t";
    cout << "\n";

    cout << "Enter the position of the element you want to delete\n";
    cin >> k;

    if (k < 1 || k > n) {  // Check for valid index
        cout << "Invalid position! Please enter a position between 1 and " << n << ".\n";
        return 1; // Exit with an error code
    }

    item = LA[k - 1];  // Store the element to be deleted

    // Corrected the loop syntax
    for (j = k - 1; j <= n - 2; j++) 
        LA[j] = LA[j + 1];

    n = n - 1; // Reduce the array size

    cout << "*****Array after deletion********\n";
    for (j = 0; j < n; j++)
        cout << LA[j] << "\t";
    cout << "\n";

    return 0;
}

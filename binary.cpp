#include <iostream>
using namespace std;
int binarysearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;  // Corrected: 'e' should be n-1 instead of n
    while (s <= e) {
        
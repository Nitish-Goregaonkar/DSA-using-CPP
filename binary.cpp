#include <iostream>
using namespace std;
int binarysearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;  // Corrected: 'e' should be n-1 instead of n
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == key) {
            return mid;  // Return index if key is found
        } else if (arr[mid] > key) {
            e = mid - 1;  // Search in the left half
       
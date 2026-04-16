#include <stdio.h>
#include <stdbool.h>

int minmax(int arr[], int start, int end, bool isMax) {
    if (start == end) {
        return arr[start];
    }

    // divide
    int mid = (start + end) / 2;

    // conquer
    int left = minmax(arr, start, mid, !isMax);
    int right = minmax(arr, mid + 1, end, !isMax);

    // combine
    if (isMax) {
        if (left > right)
            return left;
        else
            return right;
    } else {
        if (left < right)
            return left;
        else
            return right;
    }
}

int main() {
    int arr[] = {1, 2, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = minmax(arr, 0, n - 1, true);
    int result2 = minmax(arr, 0, n - 1, false);

    printf("answer:- %d\n", result);
        printf("answer:- %d\n", result2);

    return 0;
}
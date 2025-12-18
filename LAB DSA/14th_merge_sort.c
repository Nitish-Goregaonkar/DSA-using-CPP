// #include <stdio.h>

// // Function to merge two halves
// void merge(int arr[], int l, int m, int r) {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;

//     // Temporary arrays
//     int L[n1], R[n2];

//     // Copy data to temp arrays L[] and R[]
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];

//     // Merge the temp arrays back into arr[l..r]
//     i = 0;
//     j = 0;
//     k = l;

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy remaining elements (if any)
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // Merge sort function
// void mergeSort(int arr[], int l, int r) {
//     if (l < r) {
//         int m = (l + r) / 2;  // Middle index

//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);

//         // Merge the sorted halves
//         merge(arr, l, m, r);
//     }
// }

// int main() {
//     int arr[50], n;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     printf("Enter %d elements: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     mergeSort(arr, 0, n - 1);

//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

#include <stdio.h> 
 
void merge(int a[], int p, int q, int r) { 
    int i, j, k; 
    int n1 = q - p + 1; 
    int n2 = r - q; 
    int L[20], R[20]; 
 
    for(i = 0; i < n1; i++) 
        L[i] = a[p + i]; 
    for(j = 0; j < n2; j++) 
        R[j] = a[q + 1 + j]; 
 
    i = 0; j = 0; k = p; 
 
    while(i < n1 && j < n2) { 
        if(L[i] <= R[j]) 
            a[k++] = L[i++]; 
        else 
            a[k++] = R[j++]; 
    } 
 
    while(i < n1) 
        a[k++] = L[i++]; 
    while(j < n2) 
        a[k++] = R[j++]; 
} 
 
void mergeSort(int a[], int p, int r) { 
    if(p < r) { 
        int q = (p + r) / 2; 
        mergeSort(a, p, q); 
        mergeSort(a, q + 1, r); 
        merge(a, p, q, r); 
    } 
} 
 
int main() { 
    int a[10], n, i; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter elements:\n"); 
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]); 
 
    mergeSort(a, 0, n - 1); 
 
    printf("Sorted array:\n"); 
    for(i = 0; i < n; i++) 
        printf("%d ", a[i]); 
 
    return 0; 
} 
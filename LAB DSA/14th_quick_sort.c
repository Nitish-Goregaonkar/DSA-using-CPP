// #include <stdio.h>

// // Function to swap two numbers
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Partition function
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];  
//     int i = (low - 1);      

//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {  
//             i++;               
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

// // Quick Sort function
// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);  

//         quickSort(arr, low, pi - 1);  
//         quickSort(arr, pi + 1, high); 
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

//     quickSort(arr, 0, n - 1);

//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }
#include <stdio.h> 
 
void quickSort(int list[], int first, int last) { 
    int pivot, i, j, temp; 
 
    if(first < last) { 
        pivot = first; 
        i = first; 
        j = last; 
 
        while(i < j) { 
            while(list[i] <= list[pivot] && i < last) 
                i++; 
            while(list[j] > list[pivot]) 
                j--; 
 
            if(i < j) { 
                temp = list[i]; 
                list[i] = list[j]; 
                list[j] = temp; 
            } 
        } 
 
        temp = list[pivot]; 
        list[pivot] = list[j]; 
        list[j] = temp; 
 
        quickSort(list, first, j - 1); 
        quickSort(list, j + 1, last); 
    } 
} 
 
int main() { 
    int list[10], n, i; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter elements:\n"); 
    for(i = 0; i < n; i++) 
        scanf("%d", &list[i]); 
 
    quickSort(list, 0, n - 1); 
 
    printf("Sorted array:\n"); 
    for(i = 0; i < n; i++) 
        printf("%d ", list[i]); 
 
    return 0; 
} 

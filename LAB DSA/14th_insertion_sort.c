// #include <stdio.h>

// #define SIZE 10

// void insertion_sort(int *A, int length) {
//     for (int i = 1; i < length; i++) {   
//         int key = A[i];
//         int j = i - 1;

      
//         while (j >= 0 && A[j] > key) {
//             A[j + 1] = A[j];
//             j--;
//         }

//         A[j + 1] = key;  
//     }
// }

// int main() {
//     int array[] = {32, 51, 27, 85, 66, 23, 13, 57};
//     int length = sizeof(array) / sizeof(array[0]);

//     insertion_sort(array, length);

//     printf("Sorted List:\n");
//     for (int i = 0; i < length; i++) {
//         printf("%d ", array[i]);
//     }

//     return 0;
// }


#include <stdio.h> 
int main() { 
int a[10], n, i, j, key; 
printf("Enter number of elements: "); 
scanf("%d", &n); 
printf("Enter elements:\n"); 
for(i = 0; i < n; i++) 
scanf("%d", &a[i]); 
for(i = 1; i < n; i++) { 
key = a[i]; 
j = i - 1; 
while(j >= 0 && a[j] > key) { 
a[j + 1] = a[j]; 
j--; 
} 
a[j + 1] = key; 
} 
printf("Sorted array:\n"); 
for(i = 0; i < n; i++) 
printf("%d ", a[i]); 
return 0; 
} 
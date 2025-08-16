#include <stdio.h>
int main() {
    // int n =6;
    int arr[10] = {10, 20, 30, 40, 50}; // Step 1: Create array
    int *ptr;                          // Step 2: Declare pointer
    int i;
    // int j =6;
    int size=5;
    int pos =4 ;
    int j =pos;
     int value=100;
    ptr = arr; // Point to the first element of the array
   while(j<size){
    *(ptr + j) = *(ptr + j + 1);
    j++;
   }// Insert value
    // *(ptr + pos) = value;
    size--;
    printf("Array elements using pointers:\n");
    for (i = 0; i < size ; i++) {
        printf("Element %d: %d\n", i, *(ptr + i)); // Pointer arithmetic
    }
    return 0;
}
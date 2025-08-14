// #include <stdio.h>
// int main(){
 
//     int arr [5] = {10,20,30,40,50};
//     // for (int i = 0; i<5; i++){
//     //     arr[i]
//     // }
//     int *ptr;
//     ptr = &arr;
//     int arr2[5]=*ptr;
//     for (int i =0; i<5; i++){
//         printf("%d", arr2[i]);
//     }  
//     return 0;
// }
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50}; // Step 1: Create array
    int *ptr;                          // Step 2: Declare pointer
    int i;

    ptr = arr; // Point to the first element of the array

    printf("Array elements using pointers:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i)); // Pointer arithmetic
    }

    return 0;
}
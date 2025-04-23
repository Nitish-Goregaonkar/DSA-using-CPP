#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int l, int h) {
    int pivot, index, i;
    index = l;
    pivot = h;
    for(i = l; i < h; i++) {
        if(a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[pivot], &a[index]);
    return index;
}

int RandomPivotPartition(int a[], int l, int h) {
    int pvt, n, temp;
    n = rand();
    pvt = l + n % (h - l + 1);
    swap(&a[h], &a[pvt]);

    return Partition(a, l, h);
}


// Problem: Sort an array using Insertion Sort
// Insertion Sort is stable and works efficiently for nearly sorted arrays.

#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements greater than key
        // to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

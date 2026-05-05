// Problem: Sort array of non-negative integers using Counting Sort
// Steps:
// 1. Find maximum element
// 2. Create frequency array
// 3. Compute prefix sums
// 4. Build sorted output array

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int i;

    // Find maximum element
    int max = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // Create frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store frequency of each element
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Compute prefix sums
    for(i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create output array
    int output[n];

    // Build output array (stable sorting)
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy output back to original array
    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
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

    printf("Enter non-negative array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

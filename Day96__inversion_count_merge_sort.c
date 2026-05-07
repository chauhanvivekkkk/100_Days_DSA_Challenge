// Problem: Count number of inversions using Modified Merge Sort
// Inversion condition:
// i < j and a[i] > a[j]

#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long invCount = 0;

    // Merge two sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // Remaining elements in left half
            // form inversions
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n", inversions);

    return 0;
}

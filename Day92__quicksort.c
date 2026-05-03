
#include <stdio.h>

// ---------- Lomuto Partition ----------
int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quicksort_lomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high);
        quicksort_lomuto(arr, low, pi - 1);
        quicksort_lomuto(arr, pi + 1, high);
    }
}

// ---------- Hoare Partition ----------
int hoare_partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quicksort_hoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoare_partition(arr, low, high);
        quicksort_hoare(arr, low, pi);
        quicksort_hoare(arr, pi + 1, high);
    }
}

// ---------- Utility ----------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------- Main ----------
int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    quicksort_lomuto(arr1, 0, n1 - 1);
    printf("Sorted using Lomuto: ");
    printArray(arr1, n1);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    quicksort_hoare(arr2, 0, n2 - 1);
    printf("Sorted using Hoare: ");
    printArray(arr2, n2);

    return 0;
}

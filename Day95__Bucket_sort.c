// Problem: Sort real numbers in range [0,1) using Bucket Sort
// Steps:
// 1. Distribute elements into buckets
// 2. Sort individual buckets
// 3. Concatenate all buckets

#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

// Node structure for linked list
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    struct Node* buckets[BUCKETS];

    // Initialize buckets
    for (int i = 0; i < BUCKETS; i++) {
        buckets[i] = NULL;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKETS;
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets back into array
    int k = 0;

    for (int i = 0; i < BUCKETS; i++) {
        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements in range [0,1):\n");

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// File: meeting_rooms.c
// Problem: Given meeting intervals, find minimum number of rooms required.
// Approach:
// 1. Sort meetings by start time.
// 2. Use Min-Heap to store end times.
// 3. If current meeting starts after earliest ending meeting,
//    reuse the room.
// 4. Heap size at the end = minimum rooms required.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Comparator for qsort
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

// Min Heap for end times
typedef struct {
    int *arr;
    int size;
} MinHeap;

// Heapify up
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->arr[parent] <= heap->arr[index])
            break;

        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent;
    }
}

// Heapify down
void heapifyDown(MinHeap *heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size &&
            heap->arr[left] < heap->arr[smallest])
            smallest = left;

        if (right < heap->size &&
            heap->arr[right] < heap->arr[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;

        index = smallest;
    }
}

// Insert into heap
void insertHeap(MinHeap *heap, int value) {
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Remove minimum element
void removeMin(MinHeap *heap) {
    if (heap->size == 0)
        return;

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);
}

// Get minimum element
int getMin(MinHeap *heap) {
    return heap->arr[0];
}

// Function to find minimum rooms
int minMeetingRooms(Meeting meetings[], int n) {

    // Sort by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    MinHeap heap;
    heap.arr = (int *)malloc(n * sizeof(int));
    heap.size = 0;

    // Add first meeting end time
    insertHeap(&heap, meetings[0].end);

    for (int i = 1; i < n; i++) {

        // If room becomes free
        if (meetings[i].start >= getMin(&heap)) {
            removeMin(&heap);
        }

        // Allocate current meeting
        insertHeap(&heap, meetings[i].end);
    }

    int result = heap.size;

    free(heap.arr);

    return result;
}

int main() {

    Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    int rooms = minMeetingRooms(meetings, n);

    printf("Minimum meeting rooms required: %d\n", rooms);

    return 0;
}

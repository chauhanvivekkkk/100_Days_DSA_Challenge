/* Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int n) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->arr = (int*)malloc(sizeof(int)*n);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = n;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if(q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(CircularQueue* q) {
    if(q->size == 0) return;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void display(CircularQueue* q) {
    int i;
    int index = q->front;
    for(i=0;i<q->size;i++) {
        printf("%d ", q->arr[index]);
        index = (index + 1) % q->capacity;
    }
}

int main() {
    int n,i,m,x;
    scanf("%d",&n);

    CircularQueue* q = createQueue(n);

    for(i=0;i<n;i++) {
        scanf("%d",&x);
        enqueue(q,x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}

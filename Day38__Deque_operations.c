/* 
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int count;
} Deque;

Node* createNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void push_front(Deque* dq, int value) {
    Node* temp = createNode(value);
    if(dq->front == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
    dq->count++;
}

void push_back(Deque* dq, int value) {
    Node* temp = createNode(value);
    if(dq->rear == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->prev = dq->rear;
        dq->rear->next = temp;
        dq->rear = temp;
    }
    dq->count++;
}

void pop_front(Deque* dq) {
    if(dq->front == NULL) return;
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if(dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if(dq->rear == NULL) return;
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if(dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->count--;
}

int front(Deque* dq) {
    if(dq->front == NULL) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if(dq->rear == NULL) return -1;
    return dq->rear->data;
}

int empty(Deque* dq) {
    return dq->count == 0;
}

int size(Deque* dq) {
    return dq->count;
}

void clear(Deque* dq) {
    while(dq->front != NULL) {
        pop_front(dq);
    }
}

void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;
    while(curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp != NULL) {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

void printDeque(Deque* dq) {
    Node* temp = dq->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    dq.front = dq.rear = NULL;
    dq.count = 0;

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_back(&dq, 30);

    printf("%d\n", front(&dq));
    printf("%d\n", back(&dq));
    printf("%d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    printDeque(&dq);

    reverse(&dq);

    printDeque(&dq);

    clear(&dq);

    printf("%d\n", empty(&dq));

    return 0;
}
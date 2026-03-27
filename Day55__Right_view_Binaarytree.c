/* 
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) nodes[i] = createNode(arr[i]);
        else nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n) nodes[i]->left = nodes[left];
            if (right < n) nodes[i]->right = nodes[right];
        }
    }

    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = nodes[0];

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            if (i == size - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }

    return 0;
}

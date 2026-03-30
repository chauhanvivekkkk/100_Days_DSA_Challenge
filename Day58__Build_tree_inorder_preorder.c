/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTreeUtil(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end)
        return NULL;

    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = buildTreeUtil(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTreeUtil(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}

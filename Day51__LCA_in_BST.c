/*
Problem: Lowest Common Ancestor in a BST

Input:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output:
- Print the LCA value
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, x, p, q;
    struct TreeNode* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values for BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct TreeNode* ans = LCA(root, p, q);

    printf("LCA is: %d\n", ans->val);

    return 0;
}

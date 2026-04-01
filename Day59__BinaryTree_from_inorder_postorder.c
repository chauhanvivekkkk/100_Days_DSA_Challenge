/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->right = build(inorder, inIndex + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, inIndex - 1, postorder, postIndex);

    return root;
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct TreeNode* root = build(inorder, 0, n - 1, postorder, &postIndex);

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}

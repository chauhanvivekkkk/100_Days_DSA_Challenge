/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Enter number of nodes
- Enter BST values
- Enter value to search

Output:
- Prints subtree (inorder) if found
- Otherwise prints "Value not found"
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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int n, val, searchVal;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter value to search: ");
    scanf("%d", &searchVal);

    struct TreeNode* result = searchBST(root, searchVal);

    if (result == NULL)
        printf("Value not found\n");
    else {
        printf("Subtree (Inorder): ");
        inorder(result);
    }

    return 0;
}

/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, s;

    scanf("%d", &n);

    int adj[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(s, n, adj);

    return 0;
}

/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED
*/

#include <stdio.h>

#define MAX 100005

int adj[MAX][100];
int adjSize[MAX];
int visited[MAX];

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < adjSize[node]; i++) {
        int neigh = adj[node][i];
        if (!visited[neigh]) dfs(neigh);
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}

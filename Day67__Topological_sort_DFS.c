/**
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* adjSize, int* stack, int* top) {
    visited[node] = 1;

    for(int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if(!visited[neighbor]) {
            dfs(neighbor, visited, adj, adjSize, stack, top);
        }
    }

    stack[(*top)++] = node;
}

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, visited, adj, adjSize, stack, &top);
        }
    }

    printf("Topological Order: ");
    for(int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}

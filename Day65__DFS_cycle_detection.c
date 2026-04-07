/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:
- YES or NO
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int parent, int** adj, int* adjSize, bool* visited) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neigh = adj[node][i];

        if (!visited[neigh]) {
            if (dfs(neigh, node, adj, adjSize, visited))
                return true;
        } else if (neigh != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSize, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}

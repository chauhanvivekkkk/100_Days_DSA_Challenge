/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void bfs(int n, int s) {
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS traversal: ");
    bfs(n, s);

    return 0;
}

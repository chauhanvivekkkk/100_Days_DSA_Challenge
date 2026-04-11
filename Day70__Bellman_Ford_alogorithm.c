/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int edges[m][3];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
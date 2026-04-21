/* Problem Statement
   Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

   Input Format
   n m
   u v w
   ...

   Output Format
   Total weight of MST.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 1005

int graph[MAX][MAX];
int key[MAX], mst[MAX];

int minKey(int n) {
    int min = INT_MAX, min_index;
    for (int i = 1; i <= n; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[1] = 0;

    for (int i = 1; i < n; i++) {
        int u = minKey(n);
        mst[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += key[i];
    }

    printf("Total weight of MST: %d", total);

    return 0;
}

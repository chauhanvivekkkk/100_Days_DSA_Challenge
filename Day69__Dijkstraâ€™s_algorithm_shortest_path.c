/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[101];
    bool visited[101];

    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[k] = 0;

    for(int i = 1; i <= n; i++){
        int u = -1, minDist = INT_MAX;

        for(int j = 1; j <= n; j++){
            if(!visited[j] && dist[j] < minDist){
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = true;

        for(int j = 0; j < timesSize; j++){
            int src = times[j][0];
            int dest = times[j][1];
            int wt = times[j][2];

            if(src == u && dist[u] != INT_MAX && dist[u] + wt < dist[dest]){
                dist[dest] = dist[u] + wt;
            }
        }
    }

    int maxTime = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) return -1;
        if(dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int n, m, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int** times = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        times[i] = (int*)malloc(3 * sizeof(int));
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &times[i][0], &times[i][1], &times[i][2]);
    }

    printf("Enter source node k: ");
    scanf("%d", &k);

    int timesColSize[100];
    for(int i = 0; i < m; i++){
        timesColSize[i] = 3;
    }

    int result = networkDelayTime(times, m, timesColSize, n, k);

    printf("Minimum time: %d\n", result);

    for(int i = 0; i < m; i++){
        free(times[i]);
    }
    free(times);

    return 0;
}

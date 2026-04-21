#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    
    int INF = 1000000000;

    // Step 1: Create distance matrix
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Step 2: Fill edge distances
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    // Step 4: Find city with minimum reachable cities
    int resultCity = -1;
    int minReachable = INT_MAX;

    for (int i = 0; i < n; i++) {

        int count = 0;

        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold)
                count++;
        }

        // Tie-breaking: choose greater index
        if (count <= minReachable) {
            minReachable = count;
            resultCity = i;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);

    return resultCity;
}
#include <stdio.h>
#include <stdlib.h>

int findParent(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]); // Path compression
    }
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } 
        else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } 
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {

    int n = edgesSize;

    // Allocate parent and rank arrays
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* rank = (int*)calloc((n + 1), sizeof(int));

    // Initialize parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If both nodes have same parent → cycle detected
        if (parentU == parentV) {
            result[0] = u;
            result[1] = v;
        } 
        else {
            unionSet(parent, rank, u, v);
        }
    }

    *returnSize = 2;

    free(parent);
    free(rank);

    return result;
}
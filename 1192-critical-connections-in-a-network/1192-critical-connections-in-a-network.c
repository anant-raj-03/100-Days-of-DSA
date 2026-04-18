#include <stdio.h>
#include <stdlib.h>

int *head, *to, *nextEdge;
int edgeCount;

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

void dfs(int u, int parent,
         int* disc, int* low,
         int** result,
         int* returnSize,
         int* timer) {

    disc[u] = low[u] = (*timer)++;

    for (int i = head[u]; i != -1; i = nextEdge[i]) {

        int v = to[i];

        if (v == parent)
            continue;

        if (disc[v] == -1) {

            dfs(v, u,
                disc, low,
                result,
                returnSize,
                timer);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }

        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n,
                          int** connections,
                          int connectionsSize,
                          int* connectionsColSize,
                          int* returnSize,
                          int** returnColumnSizes) {

    head = (int*)malloc(n * sizeof(int));
    to = (int*)malloc(2 * connectionsSize * sizeof(int));
    nextEdge = (int*)malloc(2 * connectionsSize * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    edgeCount = 0;

    for (int i = 0; i < connectionsSize; i++) {

        int u = connections[i][0];
        int v = connections[i][1];

        addEdge(u, v);
        addEdge(v, u);
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    int** result =
        (int**)malloc(connectionsSize * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(connectionsSize * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = 0;

    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {

            dfs(i, -1,
                disc, low,
                result,
                returnSize,
                &timer);
        }
    }

    return result;
}
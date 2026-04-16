#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    
    // Color array: -1 = uncolored
    int* color = (int*)malloc(graphSize * sizeof(int));
    
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Queue for BFS
    int* queue = (int*)malloc(graphSize * sizeof(int));
    
    for (int start = 0; start < graphSize; start++) {
        
        // Skip if already colored
        if (color[start] != -1)
            continue;

        int front = 0, rear = 0;

        // Start BFS
        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {
            
            int node = queue[front++];

            // Visit neighbors
            for (int i = 0; i < graphColSize[node]; i++) {
                
                int neighbor = graph[node][i];

                // If not colored
                if (color[neighbor] == -1) {
                    
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // If same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    
    return true;
}
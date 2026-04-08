#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites,
               int prerequisitesSize,
               int* prerequisitesColSize,
               int* returnSize) {

    // Step 1: Create indegree array
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    // Step 2: Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // Step 3: Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    // Step 4: Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 5: Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while (front < rear) {
        int course = queue[front++];
        result[count++] = course;

        for (int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    // Step 6: Check if all courses completed
    if (count != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0);
    }

    *returnSize = numCourses;
    return result;
}
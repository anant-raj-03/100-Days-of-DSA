#include <stdlib.h>

typedef struct {
    int x, y;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    
    int rows = gridSize;
    int cols = gridColSize[0];
    
    // Direction vectors (up, down, left, right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // Queue (max size rows*cols)
    Node* queue = (Node*)malloc(rows * cols * sizeof(Node));
    
    int front = 0, rear = 0;
    int fresh = 0;
    
    // Step 1: Add rotten oranges to queue & count fresh
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            }
            
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    // If no fresh oranges
    if (fresh == 0) {
        free(queue);
        return 0;
    }
    
    int minutes = 0;
    
    // Step 2: BFS
    while (front < rear) {
        
        int size = rear - front;
        int rottenThisRound = 0;
        
        for (int i = 0; i < size; i++) {
            
            Node curr = queue[front++];
            
            for (int d = 0; d < 4; d++) {
                
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];
                
                if (nx >= 0 && nx < rows &&
                    ny >= 0 && ny < cols &&
                    grid[nx][ny] == 1) {
                    
                    grid[nx][ny] = 2;
                    queue[rear++] = (Node){nx, ny};
                    fresh--;
                    rottenThisRound = 1;
                }
            }
        }
        
        if (rottenThisRound)
            minutes++;
    }
    
    free(queue);
    
    // Step 3: Check if fresh left
    if (fresh > 0)
        return -1;
    
    return minutes;
}
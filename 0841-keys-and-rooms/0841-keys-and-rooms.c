bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
 bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    
    // stack for DFS
    int* stack = (int*)malloc(sizeof(int) * roomsSize);
    int top = 0;

    // start from room 0
    stack[top++] = 0;
    visited[0] = true;

    while (top > 0) {
        int room = stack[--top];

        for (int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];

            if (!visited[key]) {
                visited[key] = true;
                stack[top++] = key;
            }
        }
    }

    // check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            free(stack);
            return false;
        }
    }

    free(visited);
    free(stack);
    return true;    
}
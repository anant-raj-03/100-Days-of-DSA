void dfs(int** image, int rows, int cols, int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    // If color doesn't match, stop
    if (image[r][c] != oldColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, rows, cols, r + 1, c, oldColor, newColor);
    dfs(image, rows, cols, r - 1, c, oldColor, newColor);
    dfs(image, rows, cols, r, c + 1, oldColor, newColor);
    dfs(image, rows, cols, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    int oldColor = image[sr][sc];

    // If same color, no need to process
    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    // Run DFS
    dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);

    // Return values
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);

    // Allocate memory for rows
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* pos = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currRow = 0;
    int direction = 1; // 1 = down, -1 = up

    for (int i = 0; i < len; i++) {
        rows[currRow][pos[currRow]++] = s[i];

        if (currRow == 0)
            direction = 1;
        else if (currRow == numRows - 1)
            direction = -1;

        currRow += direction;
    }

    // Combine rows
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < pos[i]; j++) {
            result[k++] = rows[i][j];
        }
        free(rows[i]);
    }

    result[k] = '\0';

    free(rows);
    free(pos);

    return result;    
}
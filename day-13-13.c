//Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, 
//traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>

int main() {
    int m, n;
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    printf("Spiral Order Traversal:\n");

    while (top <= bottom && left <= right) {

        for (j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
    return 0;
}

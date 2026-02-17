//Problem: Given a matrix, calculate the sum of its primary diagonal elements. 
//The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>

int main() {
    int n, i, j;
    int sum = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    printf("Sum of diagonal elements = %d\n", sum);
    return 0;
}

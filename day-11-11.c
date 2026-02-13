//Write a program to perform addition of two matrices having the same dimensions. 
//The sum of two matrices is obtained by adding corresponding elements of the matrices.
#include <stdio.h>

int main() {
    int r, c;
    int A[10][10], B[10][10], Sum[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Sum of the two matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}

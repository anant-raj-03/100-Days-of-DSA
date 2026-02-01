/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers.
Shift existing elements to the right to make space.
*/
#include <stdio.h>
#define MAX 100
int main(){
    int n, pos, x, arr[MAX];
    int i;

    printf("Enter number of elements n: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter number to insert: ");
    scanf("%d", &x);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return 1;
    }
    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++;

    printf("After insertion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

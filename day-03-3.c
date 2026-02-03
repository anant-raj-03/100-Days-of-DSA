//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);

    int comparisons = 0;
    int foundIndex = -1;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

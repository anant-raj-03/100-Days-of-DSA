//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], size, i, j, k;
    
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    printf("Enter elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray before: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    // Remove duplicates
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
            
                for(k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; 
                j--;
            }
        }
    }
    
    printf("\nArray after removing duplicates: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

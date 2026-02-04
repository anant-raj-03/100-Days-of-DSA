//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

void reverseArray(int* nums, int n) {
    int left = 0;          
    int right = n - 1;     
    
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

int main() {
    int n;
    printf("Enter n number of array:");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    reverseArray(nums, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
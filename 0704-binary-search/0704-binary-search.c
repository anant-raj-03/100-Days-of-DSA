int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // target found
        }
        else if (nums[mid] < target) {
            left = mid + 1;  // search right half
        }
        else {
            right = mid - 1; // search left half
        }
    }

    return -1;
}
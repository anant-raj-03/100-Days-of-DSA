int maxSubarraySumCircular(int* nums, int numsSize) {
  int totalSum = 0;

    int maxEnding = nums[0], maxSoFar = nums[0];
    int minEnding = nums[0], minSoFar = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        totalSum += x;

        maxEnding = (i == 0) ? x : (maxEnding + x > x ? maxEnding + x : x);
        maxSoFar = (maxSoFar > maxEnding) ? maxSoFar : maxEnding;

        minEnding = (i == 0) ? x : (minEnding + x < x ? minEnding + x : x);
        minSoFar = (minSoFar < minEnding) ? minSoFar : minEnding;
    }

    // If all numbers are negative
    if (maxSoFar < 0)
        return maxSoFar;

    return (maxSoFar > totalSum - minSoFar)
           ? maxSoFar
           : totalSum - minSoFar;    
}
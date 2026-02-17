/* Given an integer array nums, find the subarray with the largest sum, and return its sum. */

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currSum = nums[0];

    for(int i = 1; i < numsSize; i++) {
        if(currSum < 0)
            currSum = nums[i];
        else
            currSum += nums[i];

        if(currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d", maxSubArray(nums, n));
    return 0;
}

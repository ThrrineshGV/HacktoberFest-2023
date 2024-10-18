#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numsSize) {
    // If there is only one element, we are already at the end.
    if (numsSize == 1) {
        return true;
    }

    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        // If the current position is not reachable, return false
        if (i > maxReach) {
            return false;
        }

        // Update the maximum reachable position
        maxReach = (i + nums[i] > maxReach) ? (i + nums[i]) : maxReach;

        // If we can reach the end of the array, return true
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4}; // Example input array
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (canJump(nums, numsSize)) {
        printf("Yes, you can reach the end of the array!\n");
    } else {
        printf("No, you cannot reach the end of the array.\n");
    }

    return 0;
}

#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = search(nums1, sizeof(nums1)/sizeof(nums1[0]), target1);
    printf("Example 1:\nInput: target = %d\nOutput: %d\n\n", target1, result1);

    int nums2[] = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = search(nums2, sizeof(nums2)/sizeof(nums2[0]), target2);
    printf("Example 2:\nInput: target = %d\nOutput: %d\n", target2, result2);

    return 0;
}

/**

Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
 

Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0

 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int compareFn(const void* a, const void* b)
{
    const int int_a = *(const int*)a;
    const int int_b = *(const int*)b;
    return int_a - int_b;
}

int findMaxK(int* nums, int numsSize) {
    
    qsort(nums, numsSize, sizeof(int), compareFn);

    int leftId = 0;
    int rightId = numsSize - 1;

    int abs_left = 0;
    while((nums[leftId] < 0) && (nums[rightId] > 0) &&(leftId < rightId))
    {
        abs_left = -1 * nums[leftId];
        if(abs_left == nums[rightId])
        {
            return abs_left;
        }
        else if(abs_left < nums[rightId])
        {
            --rightId;
        }
        else
        {
            ++leftId;
        }
    }

    return -1;
}
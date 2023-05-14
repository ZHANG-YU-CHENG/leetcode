/**
 * The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
 * For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
 * Given an integer array nums, choose four distinct indices w, x, y, and z 
 * such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
 * 
 * Return the maximum such product difference.
 * 
 * 
 * Example 1:
 * Input: nums = [5,6,2,7,4]
 * Output: 34
 * Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
 * The product difference is (6 * 7) - (2 * 4) = 34.
 * 
 * Example 2:
 * Input: nums = [4,2,5,9,7,4,8]
 * Output: 64
 * Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
 * The product difference is (9 * 8) - (2 * 4) = 64.
 * 
 * 
 * Constraints:
 * 4 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
int compareFunc(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int maxProductDifference(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compareFunc);
    return nums[numsSize-1]*nums[numsSize-2]-nums[0]*nums[1];
}
*/

/*
int maxProductDifference(int* nums, int numsSize){
    int max1=0, max2=0, min1=10001, min2=10001;
    int tmp;
    for(int i=0; i<numsSize; ++i)
    {
        if(max1<nums[i])
        {
            max1=nums[i];
            //swap
            if(max1>max2)
            {
                tmp=max1;
                max1=max2;
                max2=tmp;
            }
        }
        if(min1>nums[i])
        {
            min1=nums[i];
            //swap
            if(min1<min2)
            {
                tmp=min1;
                min1=min2;
                min2=tmp;
            }
        }
    }
    return max1*max2-min1*min2;
}
*/


int maxProductDifference(int* nums, int numsSize){
    int max1=0, max2=0, min1=10001, min2=10001;
    int tmp;
    for(int i=0; i<numsSize; ++i)
    {
        if(max1<nums[i])
        {
            max2=max1;
            max1=nums[i];
        }
        else if(max2<nums[i])
        {
            max2=nums[i];
        }

        if(min1>nums[i])
        {
            min2=min1;
            min1=nums[i];
        }
        else if(min2>nums[i])
        {
            min2=nums[i];
        }
    }
    return max1*max2-min1*min2;
}
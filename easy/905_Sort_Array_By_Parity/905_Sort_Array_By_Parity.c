/**
 * Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
 * Return any array that satisfies this condition.
 * 
 * 
 * Example 1:
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* out = (int*)malloc(sizeof(int)*numsSize);
    int head=0;
    int tail=numsSize-1;
    for(int i=0; i<numsSize; ++i)
    {
        if(nums[i]%2==0)
        {
            out[head] = nums[i];
            ++head;
        }
        else
        {
            out[tail] = nums[i];
            --tail;
        }
    }
    return out;
}
*/

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int head=0;
    int tail=numsSize-1;
    int tmp;
    while(head<tail)
    {
        if(nums[head]%2==1 && nums[tail]%2==0)
        {
            tmp = nums[head];
            nums[head] = nums[tail];
            nums[tail] = tmp;
            ++head;
            --tail;
            continue;
        }
        if(nums[head]%2==0)
            ++head;
        if(nums[tail]%2==1)
            --tail;
    }
    return nums;
}
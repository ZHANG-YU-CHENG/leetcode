/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 * 
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * Follow up: Could you minimize the total number of operations done?
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
int findNextNonZeroId(int* nums, int numsSize, int curId)
{
    for(int i=curId+1; i<numsSize; ++i)
    {
        if(nums[i]!=0) return i;
    }    
    return -1;
}

void moveZeroes(int* nums, int numsSize){
    for(int i=0; i<numsSize; ++i)
    {
        if(nums[i]==0)
        {
            int curId = i;
            int nextNonZeroId = findNextNonZeroId(nums, numsSize, curId);
            if(nextNonZeroId==-1) break;
            int zeroCount = nextNonZeroId - curId;
            for(int j=nextNonZeroId; j<numsSize; ++curId, ++j)
            {
                nums[curId] = nums[j];
            }
            for(int j=numsSize-zeroCount; j<numsSize; ++j)
            {
                nums[j] = 0;
            }
            numsSize -= zeroCount;
            zeroCount = 0;
        }
    }
}
*/

/*
void moveZeroes(int* nums, int numsSize){
    for(int lastNonZeroFoundAt=0, cur=0; cur<numsSize; ++cur)
    {
        if(nums[cur]!=0)
        {
            int t = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[cur];
            nums[cur] = t;
            ++lastNonZeroFoundAt;
        }
    }
}
*/


int findNextZero(int* nums, int numsSize, int start)
{
    for(int i=start; i<numsSize; ++i)
    {
        if(nums[i]==0) return i;
    }
    return -1;
}

int findNextNonZero(int* nums, int numsSize, int start)
{
    for(int i=start; i<numsSize; ++i)
    {
        if(nums[i]!=0) return i;
    }
    return -1;
}

void swap(int* nums, int a, int b)
{
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void moveZeroes(int* nums, int numsSize){

    int zeroPtr = findNextZero(nums, numsSize, 0);
    if(zeroPtr==-1) return;
    int cur = findNextNonZero(nums, numsSize, zeroPtr);
    if(cur==-1) return;

    while(1)
    {
        swap(nums, zeroPtr, cur);

        zeroPtr = findNextZero(nums, numsSize, zeroPtr+1);
        if(zeroPtr==-1) break;
        cur = findNextNonZero(nums, numsSize, zeroPtr);
        if(cur==-1) break;
    }
}

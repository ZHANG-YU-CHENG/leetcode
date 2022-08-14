/**
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* time limit exceeded
bool containsDuplicate(int* nums, int numsSize){
    bool tmpAns = false;
    for(int i=0; i<numsSize; ++i)
    {
        for(int j=i+1; j<numsSize; ++j)
        {
            if(nums[i]==nums[j]) return true;
        }     
    }
    return false;
}
*/

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize==1) return false;
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    for(int i=0; i<numsSize-1; ++i)
    {
        if(nums[i]==nums[i+1]) return true;
    }
    return false;
}
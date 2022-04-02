/**
 * Given an integer array nums where every element appears three times except for one, which appears exactly once. 
 * Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * 
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element which appears once.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    long long int bitSum; //deal with negative number
    //go through each bits
    for(int i=0; i<32; ++i)
    {
        bitSum = 0;
        for(int j=0; j<numsSize; ++j)
        {
            bitSum += (nums[j] >> i) & 1;
        }
        bitSum = bitSum % 3;
        bitSum = bitSum << i;
        ans = ans | bitSum;  
    }
    return ans;
}
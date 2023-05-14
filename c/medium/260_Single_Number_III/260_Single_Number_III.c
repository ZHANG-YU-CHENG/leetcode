/**
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
 * Find the two elements that appear only once. You can return the answer in any order.
 * You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 * 
 * Example 2:
 * Input: nums = [-1,0]
 * Output: [-1,0]
 * 
 * Example 3:
 * Input: nums = [0,1]
 * Output: [1,0]
 * 
 * 
 * Constraints:
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int)*2);
    ans[0] = 0;
    ans[1] = 0;

    //xor all (equals to xor a, b)
    int xor_a_b = 0;
    for(int i=0; i<numsSize; ++i)
    {
        xor_a_b ^= nums[i]; 
    }

    //since a do not equals to b, 
    //there must be at least one bit different between a, b
    //get the first different bit (first 1 from the right hand side) mask
    //ex. a = 011, b = 101, xor_a_b = 110, the first different bit mask is 010

    //v1
    /*
    long long int mask;
    for(int i=0; i<32; ++i)
    {
        mask = (xor_a_b >> i) & 1;
        if(mask)
        {
            mask = mask << i;
            break;
        }
    }
    */
    
    //v2
    long long int mask = xor_a_b & (long long int)-xor_a_b;

    //use the mask to seperate the input nums into two groups, one group have a, and the other group have b
    //xor group to get a, b
    for(int i=0; i<numsSize; ++i)
    {
        if(nums[i]&mask) ans[0] ^= nums[i];
        else ans[1] ^= nums[i];
    }
    return ans;
}
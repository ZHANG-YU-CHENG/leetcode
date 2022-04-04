/**
 * Given an array of integers nums which is sorted in ascending order, 
 * and an integer target, write a function to search target in nums. 
 * If target exists, then return its index. Otherwise, return -1.
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 104
 * -10^4 < nums[i], target < 10^4
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    int leftID = 0;
    if(nums[leftID]==target) return leftID;
    int rightID = numsSize - 1;
    if(nums[rightID]==target) return rightID;
    
    int midID = (leftID+rightID)/2;
    while(leftID+1<rightID)
    {
        if(nums[midID]==target) 
            return midID;
        else if(nums[midID]<target)
            leftID = midID;
        else
            rightID = midID;
        midID = (leftID+rightID)/2;
    }
    return -1;
}
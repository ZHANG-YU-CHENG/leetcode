/**
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * 
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int leftID = 0;
    if(target == nums[leftID]) return leftID;
    if(target < nums[leftID]) return 0;
    int rightID = numsSize - 1;
    if(target == nums[rightID]) return rightID;
    if(target > nums[rightID]) return rightID + 1;
    
    int midID = (leftID + rightID) / 2;
    while(leftID + 1 < rightID)
    {
        if(nums[midID] == target) 
            return midID;
        else if(nums[midID] < target)
            leftID = midID;
        else
            rightID = midID;
        midID = (leftID + rightID) / 2;
    }
    return rightID;
}
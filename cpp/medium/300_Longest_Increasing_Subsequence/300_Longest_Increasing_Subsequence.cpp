/**
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *  
 *  
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * 
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

//dp solution
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int max_dp = dp[0];
        for(int i=1; i<n; ++i) {
            for(int j=i-1; j>=0; --j){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            ++dp[i];
            max_dp = max(max_dp, dp[i]);
        }
        return max_dp;
    }
};
*/

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> x;
        x.push_back(nums[0]);
        for(int i=1; i<n; ++i){
            if(nums[i] > x[x.size()-1]){
                x.push_back(nums[i]);
                continue;
            }
            for(int j=x.size()-1; j>=0; --j){
                if(nums[i]==x[j]) break;
                if(j==0){
                    x[0] = min(x[0], nums[i]);
                    break;
                }
                if(nums[i]>x[j-1] && nums[i]<x[j]){
                    x[j] = nums[i];
                }
            }            
        }
        return x.size();
    }
};
*/

//binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> x;
        x.push_back(nums[0]);
        for(int i=1; i<n; ++i){
            if(nums[i] > x[x.size()-1]){
                x.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(x.begin(), x.end(), nums[i]);
            *it = nums[i];           
        }
        return x.size();
    }
};
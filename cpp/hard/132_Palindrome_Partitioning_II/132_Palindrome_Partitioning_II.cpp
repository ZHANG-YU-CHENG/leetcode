/**
 * 
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * 
 * Example 2:
 * Input: s = "a"
 * Output: 0
 * 
 * Example 3:
 * Input: s = "ab"
 * Output: 1
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 2000
 * s consists of lowercase English letters only.
 * 
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome_dp(n, vector<bool>(n, false));
        vector<int> minCut_dp(n, 0);
        // head | a a b | tail
        for(int tail=0; tail<n; ++tail) {
            int cur_minCut = tail;
            for(int head=0; head<=tail; ++head) {
                if(s[head]==s[tail] && (tail-head <= 2 || isPalindrome_dp[head+1][tail-1])){
                    isPalindrome_dp[head][tail] = true;
                    cur_minCut = (head==0) ? 0 : min(cur_minCut, minCut_dp[head-1]+1); 
                }
            }
            minCut_dp[tail] = cur_minCut;
        }
        return minCut_dp[n-1];
    }
};


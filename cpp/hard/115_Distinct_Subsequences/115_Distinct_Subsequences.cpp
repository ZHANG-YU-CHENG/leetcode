/**
 * 
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * 
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 * 
 * 
 * Example 1:
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * Example 2:
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * Constraints:
 * 1 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

//   0 r a b b b i t [s]
// 0 1 1 1 1 1 1 1 1
// r 0 1 1 1 1 1 1 1
// a 0 0 1 1 1 1 1 1
// b 0 0 0 1 2 3 3 3
// b 0 0 0 0 1 3 3 3
// i 0 0 0 0 0 0 3 3
// t 0 0 0 0 0 0 0 3
//[t]

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<unsigned long>>dp(m+1, vector<unsigned long>(n+1, 0));

        // Base case: If the target string is empty, there is one subsequence
        // (empty string) that can be formed from any string.
        for(int j=0; j<=n; ++j){
            dp[0][j] = 1;
        }

        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                // If the current characters match, we have two options:
                // 1. Include the current character in the subsequence,
                //    so we consider the previous characters from both strings.
                // 2. Exclude the current character from the subsequence,
                //    so we consider the previous characters from the first string.
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1]; //ex: dp[ra][ra] (t=ra, s=ra) = dp[ra][r] + dp[r][r]
                }
                else{
                    dp[i][j] = dp[i][j-1]; //ex: dp[r][ra] (t=r, s=ra) = dp[r][r]
                }
            }
        }
        return dp[m][n];
    }
};
/**
 * 
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * 
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // head | a a b | tail
        for(int tail=0; tail<n; ++tail) {
            for(int head=0; head<=tail; ++head) {
                if(s[head]==s[tail] && (tail-head <= 2 || dp[head+1][tail-1]))
                    dp[head][tail] = true;
            }
        }

        vector<vector<string>> results;
        vector<string> result;
        partition_helper(s, 0, dp, result, results);
        return results;
    }

private:
    void partition_helper(const string s, int head, const vector<vector<bool>> dp, vector<string>& result, vector<vector<string>>& results) {
        int n = s.length();
        if(head == n) {
            results.push_back(result);
            return;
        }
        for(int tail=head; tail<n; ++tail) {
            if(dp[head][tail]) {
                result.push_back(s.substr(head, tail-head+1));
                partition_helper(s, tail+1, dp, result, results);
                result.pop_back();
            }
        }
    }
};





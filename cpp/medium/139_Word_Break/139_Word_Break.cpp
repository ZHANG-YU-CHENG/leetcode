/**
 * 
 * Given a string s and a dictionary of strings wordDict, 
 * return true if s can be segmented into a space-separated sequence of one or more dictionary words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 * 
 *  
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 * 
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *  
 * 
 * Constraints:
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false);
        for(int i=0; i<n; ++i){
            for(string word : wordDict){
                int word_length = word.length();
                if(i+1 < word_length){
                    continue;
                }
                string tStr = s.substr(i-word_length+1, word_length);
                if(i+1 == word_length){
                    if(tStr.compare(word)==0){
                        dp[i] = true;
                    }
                    continue;
                }
                if(i+1 > word_length){
                    if(tStr.compare(word)==0 && dp[i-word_length]){
                        dp[i] = true;
                    }                    
                }

            }
        }
        return dp[n-1];
    }
};
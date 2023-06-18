/**
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        string longP = "";
        for(int i=0; i<s.length()-1; ++i){
            string oddP = subPalindrome(s, i, i);
            string evenP = subPalindrome(s, i, i+1);
            string curP = oddP.length() > evenP.length() ? oddP : evenP; 
            longP = longP.length() > curP.length() ? longP : curP;
        }
        return longP;
    }
private:
    string subPalindrome(string s, int left, int right){
        while(left >= 0 && right < s.length()){
            if(s[left]==s[right]){
                --left;
                ++right;
                continue;
            }
            else{
                return s.substr(left+1, right-1 - (left+1) + 1);
            }
        }
        return s.substr(left+1, right-1 - (left+1) + 1);
    }
};
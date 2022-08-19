/**
 * You are given a string s and an integer array indices of the same length. 
 * The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
 * Return the shuffled string.
 * 
 * 
 * Example 1:
 * Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
 * Output: "leetcode"
 * Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
 * 
 * Example 2:
 * Input: s = "abc", indices = [0,1,2]
 * Output: "abc"
 * Explanation: After shuffling, each character remains in its position.
 * 
 * 
 * Constraints:
 * s.length == indices.length == n
 * 1 <= n <= 100
 * s consists of only lowercase English letters.
 * 0 <= indices[i] < n
 * All values of indices are unique.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * restoreString(char * s, int* indices, int indicesSize){
    char* out = (char*)malloc(sizeof(char)*(indicesSize+1));
    memset(out, '\0', indicesSize+1);
    for(int i=0; i<indicesSize; ++i)
    {
        out[indices[i]] = s[i];
    }
    return out;
}
/**

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

 

Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: s = "III"
Output: [0,1,2,3]
Example 3:

Input: s = "DDI"
Output: [3,2,0,1]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'I' or 'D'.

 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int s_len = strlen(s);
    int permLen = s_len + 1;
    int* perm = (int*)malloc(sizeof(int)*permLen);
    int max = permLen-1;
    int min = 0;
    for(int i=0; i<s_len; ++i)
    {
        perm[i] = (s[i] == 'I') ? min++ : max--;
    }
    perm[permLen-1] = min; // min == max

    *returnSize = permLen;
    return perm;
}
/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
int compare(const void * a, const void * b)
{
    return (*(char*)a - *(char*)b);
}

bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t)) return false;
    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);
    return !strcmp(s,t);
}
*/

bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t)) return false;
    int count_table[26] = {0};
    for(int i=0; i<strlen(s);++i)
    {
        ++count_table[s[i]-97];
        --count_table[t[i]-97];
    }
    for(int i=0; i<26; ++i)
    {
        if(count_table[i]!=0) return false;
    }
    return true;
}
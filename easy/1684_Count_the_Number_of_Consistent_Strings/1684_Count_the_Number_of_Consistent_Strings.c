/**
 * You are given a string allowed consisting of distinct characters and an array of strings words. 
 * A string is consistent if all characters in the string appear in the string allowed.
 * 
 * Return the number of consistent strings in the array words.
 * 
 * 
 * Example 1:
 * Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
 * Output: 2
 * Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
 * 
 * Example 2:
 * Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
 * Output: 7
 * Explanation: All strings are consistent.
 * 
 * Example 3:
 * Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
 * Output: 4
 * Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 * 
 * 
 * Constraints:
 * 1 <= words.length <= 10^4
 * 1 <= allowed.length <= 26
 * 1 <= words[i].length <= 10
 * The characters in allowed are distinct.
 * words[i] and allowed contain only lowercase English letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int allowedtable[123] = {0}; //ascii a-z , 97-122
    for(int i=0; i<(int)strlen(allowed); ++i)
    {
        ++allowedtable[allowed[i]];
    }
    int count = 0;
    bool isAllowed = true;
    for(int i=0; i<wordsSize; ++i)
    {
        for(int j=0; j<(int)strlen(words[i]); ++j)
        {
            if(allowedtable[words[i][j]]==0)
            {
                isAllowed = false;
                break;
            }
        }

        if(isAllowed)
            ++count;

        isAllowed = true;
    }
    return count;
}
*/

/*
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int allowed_mask = 0;
    for(int i=0; i<strlen(allowed); ++i)
    {
        allowed_mask |= 1<<(allowed[i]-'a');
    }

    int count = 0;
    int word_mask = 0;
    for(int i=0; i<wordsSize; ++i)
    {
        for(int j=0; j<strlen(words[i]); ++j)
        {
            word_mask |= 1<<(words[i][j]-'a');
        }
        if(allowed_mask==(allowed_mask | word_mask)) ++count;
        word_mask = 0;
    }
    return count;
}
*/

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int count = 0;
    for(int i=0; i<wordsSize; ++i)
    {
        if(strspn(words[i], allowed)==strlen(words[i]))
            ++count;
    } 
    return count;
}
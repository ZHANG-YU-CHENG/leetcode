/**
 * Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
 * 
 * A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), 
 * we get the desired word.
 * 
 * Recall that a permutation of letters is a bijection from letters to letters: 
 * every letter maps to another letter, and no two letters map to the same letter.
 * 
 * 
 * Example 1:
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
 * 
 * Example 2:
 * Input: words = ["a","b","c"], pattern = "a"
 * Output: ["a","b","c"]
 * 
 * 
 * Constraints:
 * 1 <= pattern.length <= 20
 * 1 <= words.length <= 50
 * words[i].length == pattern.length
 * pattern and words[i] are lowercase English letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    int word_size = strlen(pattern);
    if(word_size==1)
    {
        *returnSize = wordsSize;
        return words;        
    }
    char** out = (char**)malloc(sizeof(char*)*wordsSize);
    int out_size = 0;
    int table_w[123] = {0};
    int table_p[123] = {0};
    bool match;
    for(int i=0; i<wordsSize; ++i)
    {
        match = true;
        for(int j=0; j<word_size; ++j)
        {
            if(table_w[words[i][j]]==0 && table_p[pattern[j]]==0)
            {
                table_w[words[i][j]] = pattern[j];
                table_p[pattern[j]] = words[i][j];
            }
            else
            {
                if(table_w[words[i][j]]!=pattern[j] || table_p[pattern[j]]!=words[i][j])
                {
                    match = false;
                    break;
                }
            }
        }
        if(match)
        {
            out[out_size] = words[i];
            ++out_size;            
        }
        match = false;
        for(int j=97; j<123; ++j)
        {
            table_w[j] = 0;
            table_p[j] = 0;
        }
    }
    *returnSize = out_size;
    return out;
}


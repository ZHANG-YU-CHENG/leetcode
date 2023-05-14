/**
 * Given a string s, return true if s is a good string, or false otherwise.
 * A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
 * 
 * 
 * Example 1:
 * Input: s = "abacbc"
 * Output: true
 * Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
 * 
 * Example 2:
 * Input: s = "aaabb"
 * Output: false
 * Explanation: The characters that appear in s are 'a' and 'b'.
 * 'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
bool areOccurrencesEqual(char * s){
    int s_len = strlen(s);
    int table[123] = {0};
    for(int i=0; i<s_len; ++i)
    {
        ++table[s[i]];
    }
    int first_item_occurences = 0;
    bool first_item_flag = true;
    for(int i=97; i<123; ++i)
    {
        if(table[i]!=0 && first_item_flag)
        {
            first_item_occurences = table[i];
            first_item_flag = false;
        }
        if(table[i]!=0 && !first_item_flag && first_item_occurences!=table[i])
            return false;
    }
    return true;
}
*/

bool areOccurrencesEqual(char * s){
    int s_len = strlen(s);
    int table[123] = {0};
    for(int i=0; i<s_len; ++i)
    {
        ++table[s[i]];
    }

    int first_item_occurences = table[s[0]];
    for(int i=97; i<123; ++i)
    {
        if(table[i]!=0 && first_item_occurences!=table[i])
            return false;
    }
    return true;
}
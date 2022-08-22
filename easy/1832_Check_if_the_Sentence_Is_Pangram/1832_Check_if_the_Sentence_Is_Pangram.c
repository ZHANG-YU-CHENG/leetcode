/**
 * A pangram is a sentence where every letter of the English alphabet appears at least once.
 * Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
 * 
 * 
 * Example 1:
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English alphabet.
 * 
 * Example 2:
 * Input: sentence = "leetcode"
 * Output: false
 * 
 * 
 * Constraints:
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
bool checkIfPangram(char * sentence){
    int table[123] = {0}; //ascii a-z, 97-122
    for(int i=0; i<strlen(sentence); ++i)
    {
        ++table[sentence[i]];
    }
    int count = 0;
    for(int i=97; i<123; ++i)
    {
        if(table[i]>0)
            ++count;
    }
    return (count==26) ? true : false;
}
*/

bool checkIfPangram(char * sentence){
    bool table[123] = {false}; //ascii a-z, 97-122
    for(int i=0; i<strlen(sentence); ++i)
    {
        table[sentence[i]] = true;
    }

    for(int i=97; i<123; ++i)
    {
        if(!table[i])
            return false;
    }
    return true;
}
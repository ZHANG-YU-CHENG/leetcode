/**
 * A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
 * Each of the words consists of only uppercase and lowercase English letters (no punctuation).
 * 
 * For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
 * You are given a sentence s and an integer k. You want to truncate s such that it contains only the first k words. Return s after truncating it.
 * 
 * 
 * Example 1:
 * Input: s = "Hello how are you Contestant", k = 4
 * Output: "Hello how are you"
 * Explanation:
 * The words in s are ["Hello", "how" "are", "you", "Contestant"].
 * The first 4 words are ["Hello", "how", "are", "you"].
 * Hence, you should return "Hello how are you".
 * 
 * Example 2:
 * Input: s = "What is the solution to this problem", k = 4
 * Output: "What is the solution"
 * Explanation:
 * The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
 * The first 4 words are ["What", "is", "the", "solution"].
 * Hence, you should return "What is the solution".
 * 
 * Example 3:
 * Input: s = "chopper is not a tanuki", k = 5
 * Output: "chopper is not a tanuki"
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 500
 * k is in the range [1, the number of words in s].
 * s consist of only lowercase and uppercase English letters and spaces.
 * The words in s are separated by a single space.
 * There are no leading or trailing spaces.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char * truncateSentence(char * s, int k){
    int count = 0;
    int out_len = 0;
    for(int i=0; i<strlen(s); ++i)
    {
        if(s[i]==' ')
            ++count;

        if(count==k)
        {
            out_len = i;
            break;
        }
    }
    if(count!=k)
        return s;

    char* out = (char*)malloc(sizeof(char)*(out_len+1));
    memset(out, '\0', out_len+1);
    strncpy(out, s, out_len);

    return out;
}
*/

char * truncateSentence(char * s, int k){
    int count = 0;
    for(int i=0; i<strlen(s); ++i)
    {
        if(s[i]==' ')
            ++count;

        if(count==k)
        {
            s[i]='\0';
            return s;
        }
    }
    return s;
}
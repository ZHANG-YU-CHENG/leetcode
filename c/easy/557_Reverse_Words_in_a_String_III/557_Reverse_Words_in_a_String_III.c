/**
 * Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * 
 * 
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char * reverseWords(char * s){
    int s_len = strlen(s);
    char* out = (char*)malloc(sizeof(char)*(s_len+1));
    memset(out, '\0', (s_len+1));
    int word_head = 0;
    for(int i=0; i<s_len+1; ++i)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            for(int j=i-1; j>=word_head; --j)
            {
                strncat(out, &s[j], 1);
            }
            strncat(out, &s[i], 1);
            if(s[i]=='\0')
                break;
            word_head = i+1;
        }
    }
    return out;
}
*/

char * reverseWords(char * s){
    int s_len = strlen(s);
    int word_head = 0;
    int p1, p2;
    char tmp;
    for(int i=0; i<s_len+1; ++i)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            p1 = word_head;
            p2 = i-1;
            while(p1<p2)
            {
                tmp = s[p1];
                s[p1] = s[p2];
                s[p2] = tmp;
                ++p1;
                --p2;
            }
            word_head = i+1;
        }
    }
    return s;
}


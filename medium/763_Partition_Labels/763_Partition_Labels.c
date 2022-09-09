/**
 * You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
 * 
 * Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
 * 
 * Return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 * 
 * Example 2:
 * Input: s = "eccbbbbdec"
 * Output: [10]
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
int* partitionLabels(char * s, int* returnSize){
    int table[123][2]; //ascii : a-z = 97-122, [0]:min id, [1]:max id
    for(int i=97; i<123; ++i)
    {
        table[i][0] = -1;
        table[i][1] = -1;
    }
    int s_size = strlen(s);
    for(int i=0; i<s_size; ++i)
    {
        if(table[s[i]][0]==-1)
            table[s[i]][0] = i; // min id = current id
        table[s[i]][1] = i; // max id = current id
    }
    int start = 0;
    int end = 0;
    int out_size = 0;
    int* out = (int*)malloc(sizeof(int)*1);
    for(int i=0; i<s_size; ++i)
    {
        end = table[s[i]][1];
        for(int j=i+1; j<s_size; ++j)
        {
            if(end < table[s[j]][0]) // end < min
            {
                ++out_size;
                out = (int*)realloc(out, sizeof(int)*out_size);
                out[out_size-1] = end - start + 1;

                //new partition start
                i = j;
                start = table[s[i]][0];
                --i; //neutralize ++i
                break;
            }
            else
            {
                if(end < table[s[j]][1]) // end > min but end < max
                    end = table[s[j]][1];
            }
        }
        if(end==s_size-1)
        {
            ++out_size;
            out = (int*)realloc(out, sizeof(int)*out_size);
            out[out_size-1] = end - start + 1;
            i = s_size;
            break;
        }
    }
    *returnSize = out_size;
    return out;
}
*/

int* partitionLabels(char * s, int* returnSize){
    int table[123]; //ascii : a-z = 97-122, max id
    for(int i=97; i<123; ++i)
        table[i] = -1;
    int s_size = strlen(s);
    for(int i=0; i<s_size; ++i)
        table[s[i]] = i; // max id = current id
    int start = 0;
    int end = 0;
    int out_size = 0;
    int* out = (int*)malloc(sizeof(int)*26); //maximum 26 partition
    for(int i=0; i<s_size; ++i)
    {
        end = end > table[s[i]] ? end : table[s[i]];
        if(end==i)
        {
            out[out_size] = end - start + 1;
            ++out_size;
            start = i+1;
        }
    }
    *returnSize = out_size;
    return out;
}


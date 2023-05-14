/**
 * You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. 
 * Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
 * 
 * 
 * Example 1:
 * Input: jewels = "aA", stones = "aAAbbbb"
 * Output: 3
 * 
 * Example 2:
 * Input: jewels = "z", stones = "ZZ"
 * Output: 0
 * 
 * 
 * Constraints:
 * 1 <= jewels.length, stones.length <= 50
 * jewels and stones consist of only English letters.
 * All the characters of jewels are unique.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int numJewelsInStones(char * jewels, char * stones){
    int count = 0;
    for(int i=0; i<strlen(stones); ++i)
    {
        for(int j=0; j<strlen(jewels); ++j)
        {
            if(stones[i]==jewels[j])
            {
                ++count;
                break;
            }
        }
    }
    return count;
}
*/

int numJewelsInStones(char * jewels, char * stones){
    int count = 0;
    // use hash table should save more space than this table
    int table[123] = {0}; //ascii A-Z (65-90), a-z (97-122)

    for(int i=0; i<strlen(jewels); ++i)
        ++table[jewels[i]];

    for(int i=0; i<strlen(stones); ++i)
    {
        if(table[stones[i]]==1)
            ++count;
    }
    return count;
}
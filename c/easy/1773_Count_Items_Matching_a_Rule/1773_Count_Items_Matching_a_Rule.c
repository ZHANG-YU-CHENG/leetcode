/**
 * You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. 
 * You are also given a rule represented by two strings, ruleKey and ruleValue.
 * 
 * The ith item is said to match the rule if one of the following is true:
 * 
 * ruleKey == "type" and ruleValue == typei.
 * ruleKey == "color" and ruleValue == colori.
 * ruleKey == "name" and ruleValue == namei.
 * 
 * Return the number of items that match the given rule.
 * 
 * 
 * Example 1:
 * Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
 * Output: 1
 * Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
 * 
 * Example 2:
 * Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
 * Output: 2
 * Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. 
 * Note that the item ["computer","silver","phone"] does not match.
 * 
 * 
 * Constraints:
 * 1 <= items.length <= 10^4
 * 1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
 * ruleKey is equal to either "type", "color", or "name".
 * All strings consist only of lowercase letters.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int count = 0;
    if(!strncmp(ruleKey, "type", strlen(ruleKey)))
    {
        for(int i=0; i<itemsSize; ++i)
        {
            if(strlen(items[i][0])==strlen(ruleValue) && !strncmp(items[i][0], ruleValue, strlen(items[i][0])))
                ++count;
        }
    }
    else if(!strncmp(ruleKey, "color", strlen(ruleKey)))
    {
        for(int i=0; i<itemsSize; ++i)
        {
            if(strlen(items[i][1])==strlen(ruleValue) && !strncmp(items[i][1], ruleValue, strlen(items[i][1])))
                ++count;
        }
    }
    else
    {
        for(int i=0; i<itemsSize; ++i)
        {
            if(strlen(items[i][2])==strlen(ruleValue) && !strncmp(items[i][2], ruleValue, strlen(items[i][2])))
                ++count;
        }
    }
    return count;
}
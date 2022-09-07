/**
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize){
    int head = 0;
    int tail = sSize-1;
    char tmp;
    while(head<tail)
    {
        tmp = s[head];
        s[head] = s[tail];
        s[tail] = tmp;
        ++head;
        --tail;
    }
}
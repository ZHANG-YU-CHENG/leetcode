/**
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 * 
 * 
 * Example 1:
 * Input: n = 5
 * Output: true
 * Explanation: The binary representation of 5 is: 101
 * 
 * Example 2:
 * Input: n = 7
 * Output: false
 * Explanation: The binary representation of 7 is: 111.
 * 
 * Example 3:
 * Input: n = 11
 * Output: false
 * Explanation: The binary representation of 11 is: 1011.
 * 
 * 
 * Constraints:
 * 1 <= n <= 2^31 - 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
bool hasAlternatingBits(int n){
    long int mask = 0b10000000000000000000000000000000;
    bool start_check = false;
    bool cur = true;
    for(int i=0; i<32; ++i)
    {
        if(n & mask)
            start_check = true;
        if(start_check)
        {
            if(n & mask)
            {
                if(!cur)
                    return false;
            }
            else
            {
                if(cur)
                    return false;
            }
            cur = !cur;
        }
        mask>>=1;
    }
    return true;
}
*/

bool hasAlternatingBits(int n){
    int cur = n%2; //last bit
    n>>=1;
    while(n)
    {
        if(cur == n%2) 
            return false;
        cur = n%2;
        n>>=1;
    }
    return true;
}
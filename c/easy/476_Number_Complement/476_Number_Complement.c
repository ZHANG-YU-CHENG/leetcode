/**
 * The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
 * 
 * For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
 * 
 * Given an integer num, return its complement.
 * 
 * 
 * Example 1:
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * 
 * Example 2:
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 * 
 * 
 * Constraints:
 * 1 <= num < 2^31
 * Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
int findComplement(int num){
    long int c_masks[] =
    {
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000001,
        0b00000000000000000000000000000011,
        0b00000000000000000000000000000111,
        0b00000000000000000000000000001111,
        0b00000000000000000000000000011111,
        0b00000000000000000000000000111111,
        0b00000000000000000000000001111111,
        0b00000000000000000000000011111111,
        0b00000000000000000000000111111111,
        0b00000000000000000000001111111111,
        0b00000000000000000000011111111111,
        0b00000000000000000000111111111111,
        0b00000000000000000001111111111111,
        0b00000000000000000011111111111111,
        0b00000000000000000111111111111111,
        0b00000000000000001111111111111111,
        0b00000000000000011111111111111111,
        0b00000000000000111111111111111111,
        0b00000000000001111111111111111111,
        0b00000000000011111111111111111111,
        0b00000000000111111111111111111111,
        0b00000000001111111111111111111111,
        0b00000000011111111111111111111111,
        0b00000000111111111111111111111111,
        0b00000001111111111111111111111111,
        0b00000011111111111111111111111111,
        0b00000111111111111111111111111111,
        0b00001111111111111111111111111111,
        0b00011111111111111111111111111111,
        0b00111111111111111111111111111111,
        0b01111111111111111111111111111111,
        0b11111111111111111111111111111111
    };
    long int mask = 0b10000000000000000000000000000000;
    for(int i=32; i>=0; --i)
    {
        if(num & mask)
        {
            num = num ^ c_masks[i];
            break;
        }
        mask>>=1;
    }
    return num;
}
*/

int findComplement(int num){
    int temp = num;
    long int mask = 0;
    while(temp)
    {
        mask = (mask<<1)|1;
        temp>>=1;
    }
    return num ^ mask;
}
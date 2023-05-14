/**
 * Reverse bits of a given 32 bits unsigned integer.
 * Note:
 * Note that in some languages, such as Java, there is no unsigned integer type. 
 * In this case, both input and output will be given as a signed integer type. 
 * They should not affect your implementation, 
 * as the integer's internal binary representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement notation. 
 * Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 * 
 * 
 * Example 1:
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
 * so return 964176192 which its binary representation is 00111001011110000010100101000000.
 * 
 * Example 2:
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
 * so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 * 
 * 
 * Constraints:
 * The input must be a binary string of length 32
 * 
 * 
 * Follow up: If this function is called many times, how would you optimize it?
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t out = 0;
    long long int mask = 0;
    for(int i=0; i<32; ++i)
    {
        mask = (n & ((long long int)1<<i));
        out |= (i<=15) ? mask << (31-2*i) : mask >> (31-2*(31-i));
    }
    return out;
}

/*
0 => 31 (x<<31)
1 => 30 (x<<29)
2 => 29 (x<<27)
3 => 28 (x<<25)
4 => 27 (x<<23)
5 => 26 (x<<21)
6 => 25 (x<<19)
7 => 24 (x<<17)
8 => 23 (x<<15)
9 => 22 (x<<13)
10 => 21 (x<<11)
11 => 20 (x<<9)
12 => 19 (x<<7)
13 => 18 (x<<5)
14 => 17 (x<<3)
15 => 16 (x<<1)
16 => 15 (x>>1)
17 => 14 (x>>3)
18 => 13 (x>>5)
19 => 12 (x>>7)
20 => 11 (x>>9)
21 => 10 (x>>11)
22 => 9 (x>>13)
23 => 8 (x>>15)
24 => 7 (x>>17)
25 => 6 (x>>19)
26 => 5 (x>>21)
27 => 4 (x>>23)
28 => 3 (x>>25)
29 => 2 (x>>27)
30 => 1 (x>>29)
31 => 0 (x>>31)
*/
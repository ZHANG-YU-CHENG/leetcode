/**
 * Given an integer n, return true if it is a power of two. Otherwise, return false.
 * An integer n is a power of two, if there exists an integer x such that n == 2x.
 * 
 * 
 * Example 1:
 * Input: n = 1
 * Output: true
 * Explanation: 20 = 1
 * 
 * Example 2:
 * Input: n = 16
 * Output: true
 * Explanation: 24 = 16
 * 
 * Example 3:
 * Input: n = 3
 * Output: false
 * 
 * 
 * Constraints:
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
bool isPowerOfTwo(int n){
    if(n==1||n==2||n==4||n==8||n==16||
        n==32||n==64||n==128||n==256||n==512||
       n==1024||n==2048||n==4096||n==8192||n==16384||
       n==32768||n==65536||n==131072||n==262144||n==524288||
       n==1048576||n==2097152||n==4194304||n==8388608||n==16777216||
       n==33554432||n==67108864||n==134217728||n==268435456||n==536870912||n==1073741824)
        return true;
    else return false;
}
*/

/*
bool isPowerOfTwo(int n){
    if(n==1) return true;
    if(n<0) return false;
    while(n>0)
    {
        if(n==2) return true;
        if(n%2!=0) return false;
        n /= 2;
    }
    return false;
}
*/

bool isPowerOfTwo(int n){
    return n>0 && (n & (n-1))==0;
}


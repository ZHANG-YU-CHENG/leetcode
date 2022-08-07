/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return true if n is an ugly number.
 * 
 * 
 * Example 1:
 * Input: n = 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * Input: n = 1
 * Output: true
 * Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 * 
 * Example 3:
 * Input: n = 14
 * Output: false
 * Explanation: 14 is not ugly since it includes the prime factor 7.
 * 
 * 
 * Constraints:
 * -2^31 <= n <= 2^31 - 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int n){
    if(n==1) return true;
    if(n<=0) return false;
    
    while(n>=2)
    {
        if(n==2) return true;
        if(n%2==0) n/=2;
        else break;
    }

    while(n>=2)
    {
        if(n==3) return true;
        if(n%3==0) n/=3;
        else break;
    }

    while(n>=2)
    {
        if(n==5) return true;
        if(n%5==0) n/=5;
        else break;
    }

    return false;
}


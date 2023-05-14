/**
 * You are a product manager and currently leading a team to develop a new product. 
 * Unfortunately, the latest version of your product fails the quality check. 
 * Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
 * which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which returns whether version is bad. 
 * Implement a function to find the first bad version. You should minimize the number of calls to the API.
 * 
 * 
 * Example 1:
 * Input: n = 5, bad = 4
 * Output: 4
 * Explanation:
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * Then 4 is the first bad version.
 * 
 * Example 2:
 * Input: n = 1, bad = 1
 * Output: 1
 * 
 * 
 * Constraints:
 * 1 <= bad <= n <= 2^31 - 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int firstBad;
bool isBadVersion(int version)
{
    return (version>=firstBad);
}

//v1
/*
int firstBadVersion(int n) {
    if(n==1) return 1;
    if(n==2 && !isBadVersion(1)) return 2;
    if(n>2 && !isBadVersion(n-1)&&isBadVersion(n)) return n;

    long long int left = 1;
    long long int right = n;
    long long int mid = (left + right) / 2;
    while(left+1<right)
    {
        if(!isBadVersion(mid-1)&&isBadVersion(mid)) 
            return mid;
        else if(isBadVersion(mid))
            right = mid;
        else
            left = mid; 
        mid = (left + right) / 2;
    }
    return mid;
}
*/

//v2
int firstBadVersion(int n) {
    if(n==1) return 1;
    if(n==2 && !isBadVersion(1)) return 2;
    if(n>2 && !isBadVersion(n-1)&&isBadVersion(n)) return n;

    int left = 1;
    int right = n;
    int mid = left + (right - left) / 2;
    while(left+1<right)
    {
        if(!isBadVersion(mid-1)&&isBadVersion(mid)) 
            return mid;
        else if(isBadVersion(mid))
            right = mid;
        else
            left = mid; 
        mid = left + (right - left) / 2;
    }
    return mid;
}




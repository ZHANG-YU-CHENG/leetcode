/**
 * You are given a positive integer num consisting only of digits 6 and 9.
 * 
 * Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 * 
 * 
 * Example 1:
 * Input: num = 9669
 * Output: 9969
 * Explanation: 
 * Changing the first digit results in 6669.
 * Changing the second digit results in 9969.
 * Changing the third digit results in 9699.
 * Changing the fourth digit results in 9666.
 * The maximum number is 9969.
 * 
 * Example 2:
 * Input: num = 9996
 * Output: 9999
 * Explanation: Changing the last digit 6 to 9 results in the maximum number.
 * 
 * Example 3:
 * Input: num = 9999
 * Output: 9999
 * Explanation: It is better not to apply any change.
 * 
 * 
 * Constraints:
 * 1 <= num <= 10^4
 * num consists of only 6 and 9 digits.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int maximum69Number(int num){
    char num_str[5] = {0};
    sprintf(num_str, "%d", num);
    for(int i=0; i<4; ++i)
    {
        if(num_str[i]=='6')
        {
            num_str[i]='9';
            return atoi(num_str);
        }
    }
    return atoi(num_str);
}
*/

/*
int maximum69Number(int num){
    char num_str[5] = {0};
    sprintf(num_str, "%d", num);
    char* p = strchr(num_str, '6');
    if(p) *p = '9';
    return atoi(num_str);
}
*/

int maximum69Number(int num){
    int n = num;
    int add = 0;
    int tmp = 3;
    while(n)
    {
        if(n%10==6)
            add = tmp;
        n/=10;
        tmp*=10;
    }
    return num+add;
}
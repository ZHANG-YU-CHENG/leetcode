/**
 * There is a hidden integer array arr that consists of n non-negative integers.
 * 
 * It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. 
 * For example, if arr = [1,0,2,1], then encoded = [1,2,3].
 * 
 * You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].
 * 
 * Return the original array arr. It can be proved that the answer exists and is unique.
 * 
 * 
 * Example 1:
 * Input: encoded = [1,2,3], first = 1
 * Output: [1,0,2,1]
 * Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
 * 
 * Example 2:
 * Input: encoded = [6,2,7,3], first = 4
 * Output: [4,2,0,7,4]
 * 
 * 
 * Constraints:
 * 2 <= n <= 10^4
 * encoded.length == n - 1
 * 0 <= encoded[i] <= 10^5
 * 0 <= first <= 10^5
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// a^b=c
// a^c=b
// b^c=a
//ex : a = 101 = 5
//     b = 110 = 6
//     c = 011 = 3
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int out_size = encodedSize+1;
    *returnSize = out_size;
    int* out = (int*)malloc(sizeof(int)*out_size);

    out[0] = first;
    for(int i=1; i<out_size; ++i)
        out[i] = out[i-1]^encoded[i-1];
    
    return out;
}
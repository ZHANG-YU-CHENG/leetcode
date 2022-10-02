/**
 * Given an array of integers arr.
 * 
 * We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
 * 
 * Let's define a and b as follows:
 * 
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 * 
 * Note that ^ denotes the bitwise-xor operation.
 * 
 * Return the number of triplets (i, j and k) Where a == b.
 * 
 * 
 * Example 1:
 * Input: arr = [2,3,1,6,7]
 * Output: 4
 * Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
 * 
 * Example 2:
 * Input: arr = [1,1,1,1,1]
 * Output: 10
 * 
 * 
 * Constraints:
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
 * 
 */

#include <stdio.h>
#include <stdlib.h>
/*
int countTriplets(int* arr, int arrSize){
    int count = 0;
    int A;
    int B;
    for(int I=0; I<arrSize; ++I)
    {
        A = 0;
        for(int J=I+1; J<arrSize; ++J)
        {
            A ^= arr[J-1];
            B = 0;
            for(int K=J; K<arrSize; ++K)
            {
                B ^=arr[K];
                if(A==B)
                    ++count;
            }
        }
    }
    return count;
}
*/

int countTriplets(int* arr, int arrSize){

    //    arr  = {a,b,c,d,e} 
    // => xors = {a, a^b, a^b^c, a^b^c^d, a^b^c^d^e}
    for(int i=1; i<arrSize; ++i)
        arr[i]^=arr[i-1];

    int count = 0;
    int tmp;
    // find the range i to k so that all element's cumulative xor is 0, 
    // then j can be anywhere between i to k
    // answer will be : k - i
    // also, be aware that:
    // arr[i] ^ ... ^ arr[k] = xors[i-1] ^ xors[k] /* (0~k) - (0~i-1) = (i~k) */
    for(int i=0; i<arrSize; ++i)
    {
        for(int k=i+1; k<arrSize; ++k)
        {
            tmp = (i==0) ? arr[k] : arr[i-1] ^ arr[k];
            if(tmp==0)
                count += k - i;
        }
    }
    return count;
}

/* TODO : there is O(N) solution, need to figure out */
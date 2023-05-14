/**
 * You are given an integer array arr. 
 * Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers 
 * have the same number of 1's you have to sort them in ascending order.
 * 
 * Return the array after sorting it.
 * 
 * 
 * Example 1:
 * Input: arr = [0,1,2,3,4,5,6,7,8]
 * Output: [0,1,2,4,8,3,5,6,7]
 * Explantion: [0] is the only integer with 0 bits.
 * [1,2,4,8] all have 1 bit.
 * [3,5,6] have 2 bits.
 * [7] has 3 bits.
 * The sorted array by bits is [0,1,2,4,8,3,5,6,7]
 * 
 * Example 2:
 * Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
 * Output: [1,2,4,8,16,32,64,128,256,512,1024]
 * Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 * 
 * 
 * Constraints:
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    int* table = (int*)malloc(sizeof(int)*arrSize);
    int temp;
    int count;
    for(int i=0; i<arrSize; ++i)
    {
        temp = arr[i];
        count = 0;
        while(temp)
        {
            if(temp & 1)
                ++count;
            temp>>=1;
        }
        table[i] = count;
    }

    //bubble sort
    for(int i=0; i<arrSize-1; ++i)
    {
        for(int j=0; j<arrSize-1-i; ++j)
        {
            if((table[j]>table[j+1]) || (table[j]==table[j+1] && arr[j]>arr[j+1]))
            {
                swap(&arr[j], &arr[j+1]);
                swap(&table[j], &table[j+1]);
            }
        }
    }
    return arr;
}
*/

int compareFunc(const void* a, const void* b)
{
    int a_pop = __builtin_popcount(*(int*)a);
    int b_pop = __builtin_popcount(*(int*)b);
    if(a_pop == b_pop)
        return *(int*)a - *(int*)b;
    return a_pop - b_pop;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), compareFunc);
    return arr;
}
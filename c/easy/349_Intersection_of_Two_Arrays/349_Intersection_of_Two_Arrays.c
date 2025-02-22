/**
    Given two integer arrays nums1 and nums2, return an array of their intersection. 
    Each element in the result must be unique and you may return the result in any order.

    Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

    Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]

    Explanation: [4,9] is also accepted.
     
    Constraints:
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
 * 
 */

#include "stdio.h"
#include "stdlib.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compareInt(const void *a, const void *b){
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return int_a - int_b;
}

// v1

// int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//     qsort(nums1, nums1Size, sizeof(int), compareInt);
//     qsort(nums2, nums2Size, sizeof(int), compareInt);
//     int nums1Id = 0;
//     int nums2Id = 0;
//     int returnNumsId = 0;
//     int* returnNums = NULL;
//     while((nums1Id < nums1Size) && (nums2Id < nums2Size))
//     {
//         if(nums1[nums1Id] > nums2[nums2Id])
//         {
//             ++nums2Id;
//         }
//         else if(nums1[nums1Id] < nums2[nums2Id])
//         {
//             ++nums1Id;
//         }
//         else 
//         {
//             if(returnNums)
//             {
//                 if(returnNums[returnNumsId-1] != nums1[nums1Id])
//                 {
//                     returnNums = (int*)realloc(returnNums, sizeof(int)*(returnNumsId+1));
//                     returnNums[returnNumsId] = nums1[nums1Id];
//                     ++returnNumsId;                    
//                 }
//             }
//             else
//             {
//                 returnNums = (int*)malloc(sizeof(int)*1); //first element in returnNums
//                 returnNums[returnNumsId] = nums1[nums1Id];
//                 ++returnNumsId;
//             }
//             ++nums1Id;
//             ++nums2Id;
//         }
//     }
//     *returnSize = returnNumsId;
//     return returnNums;
// }



// v2

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compareInt);
    qsort(nums2, nums2Size, sizeof(int), compareInt);
    int nums1Id = 0;
    int nums2Id = 0;
    int returnNumsId = 0;
    int returnNumsMinSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* returnNums = (int*)malloc(sizeof(int)*returnNumsMinSize);
    while((nums1Id < nums1Size) && (nums2Id < nums2Size))
    {
        if(nums1[nums1Id] > nums2[nums2Id])
        {
            ++nums2Id;
        }
        else if(nums1[nums1Id] < nums2[nums2Id])
        {
            ++nums1Id;
        }
        else 
        {
            if(returnNumsId ==0 || returnNums[returnNumsId-1] != nums1[nums1Id])
            {
                returnNums[returnNumsId] = nums1[nums1Id];
                ++returnNumsId;
            }
            ++nums1Id;
            ++nums2Id;
        }
    }
    *returnSize = returnNumsId;
    returnNums = (int*)realloc(returnNums, sizeof(int)*(*returnSize));
    return returnNums;
}
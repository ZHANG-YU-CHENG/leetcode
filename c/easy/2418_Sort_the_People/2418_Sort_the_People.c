/**

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.

 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    char* name;
    int height;
} Pair;

int comparePair(const void* pair1, const void* pair2)
{
    const Pair p1 = *(const Pair*)pair1;
    const Pair p2 = *(const Pair*)pair2;
    return p2.height - p1.height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    char** sortedNames = (char**)malloc(sizeof(char*)*namesSize);
    for(int i=0; i<namesSize; ++i)
    {
        sortedNames[i] = (char*)malloc(sizeof(char)*21);
    }

    Pair* p_arr = (Pair*)malloc(sizeof(Pair)*namesSize);
    for(int i=0; i<namesSize; ++i)
    {
        p_arr[i].name = names[i];
        p_arr[i].height = heights[i];
    }

    qsort(p_arr, namesSize, sizeof(Pair), comparePair);

    for(int i=0; i<namesSize; ++i)
    {
        strcpy(sortedNames[i], p_arr[i].name);
    }

    *returnSize = namesSize;
    return sortedNames;
}
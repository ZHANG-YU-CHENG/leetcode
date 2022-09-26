/**
 * Given an array of integers nums, sort the array in ascending order and return it.
 * You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), 
 * while the positions of other numbers are changed (for example, 1 and 5).
 * 
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * Explanation: Note that the values of nums are not necessairly unique.
 * 
 * 
 * Constraints:
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
#define MAX 50001
void merge(int* nums, int front, int mid, int end)
{
    int arr1Size = mid - front + 2;
    int arr2Size = end - mid + 1;
    int* arr1 = (int*)malloc(sizeof(int)*arr1Size);
    int* arr2 = (int*)malloc(sizeof(int)*arr2Size);
    for(int i=0; i<arr1Size-1; ++i)
        arr1[i] = nums[i+front];
    arr1[arr1Size-1] = MAX;
    for(int i=0; i<arr2Size-1; ++i)
        arr2[i] = nums[mid+1+i];
    arr2[arr2Size-1] = MAX;

    int arr1Id = 0;
    int arr2Id = 0;
    for(int i=front; i<=end; ++i)
    {
        if(arr1[arr1Id]<=arr2[arr2Id])
        {
            nums[i] = arr1[arr1Id];
            ++arr1Id;
        }
        else
        {
            nums[i] = arr2[arr2Id];
            ++arr2Id;
        }
    }
    free(arr1);
    free(arr2);
}

void mergesort(int* nums, int front, int end)
{
    if(front < end)
    {
        int mid = (front + end)/2;
        mergesort(nums, front, mid);
        mergesort(nums, mid+1, end);
        merge(nums, front, mid, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    mergesort(nums, 0, numsSize-1);
    return nums;
}
*/

/*
#define MAX 50001
void merge(int* nums, int front, int mid, int end)
{
    int arr1Size = mid - front + 2;
    int arr2Size = end - mid + 1;
    int* arr1 = (int*)malloc(sizeof(int)*arr1Size);
    int* arr2 = (int*)malloc(sizeof(int)*arr2Size);
    for(int i=0; i<arr1Size-1; ++i)
        arr1[i] = nums[i+front];
    arr1[arr1Size-1] = MAX;
    for(int i=0; i<arr2Size-1; ++i)
        arr2[i] = nums[mid+1+i];
    arr2[arr2Size-1] = MAX;

    int arr1Id = 0;
    int arr2Id = 0;
    int numsId = front;
    while( (arr1Id!=arr1Size-1) && (arr2Id!=arr2Size-1) )
    {
        if(arr1[arr1Id]<=arr2[arr2Id])
        {
            nums[numsId] = arr1[arr1Id];
            ++arr1Id;
            ++numsId;
        }
        else
        {
            nums[numsId] = arr2[arr2Id];
            ++arr2Id;
            ++numsId;
        }
    }

    if(arr1Id==arr1Size-1)
    {
        while(arr2Id!=arr2Size-1)
        {
            nums[numsId] = arr2[arr2Id];
            ++arr2Id;
            ++numsId;
        }
    }
    else
    {
        while(arr1Id!=arr1Size-1)
        {
            nums[numsId] = arr1[arr1Id];
            ++arr1Id;
            ++numsId;
        }
    }
    free(arr1);
    free(arr2);
}

void mergesort(int* nums, int front, int end)
{
    if(front < end)
    {
        int mid = (front + end)/2;
        mergesort(nums, front, mid);
        mergesort(nums, mid+1, end);
        merge(nums, front, mid, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    mergesort(nums, 0, numsSize-1);
    return nums;
}
*/

/*
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* nums, int front, int end)
{
    int i = front - 1;
    int j;
    for(j=front; j<end; ++j)
    {
        if(nums[j] < nums[end])
        {
            ++i;
            swap(&nums[i], &nums[j]);
        }
    }
    ++i;
    swap(&nums[i], &nums[j]);
    return i;
}

void quicksort(int* nums, int front, int end)
{
    if(front < end)
    {
        int pivot = partition(nums, front, end);
        quicksort(nums, front, pivot-1);
        quicksort(nums, pivot+1, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    quicksort(nums, 0, numsSize-1);
    return nums;
}
*/


void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// rand pivot selection will deal with sorted nums input
int partition(int* nums, int front, int end)
{
    int i = front - 1;
    int j;
    int pivot = rand()%(end-front+1)+front; //select random position for pivot
    swap(&nums[pivot], &nums[end]); // put the pivot to the end
    for(j=front; j<end; ++j)
    {
        if(nums[j] < nums[end])
        {
            ++i;
            swap(&nums[i], &nums[j]);
        }
    }
    ++i;
    swap(&nums[i], &nums[j]);
    return i;
}

void quicksort(int* nums, int front, int end)
{
    if(front < end)
    {
        int pivot = partition(nums, front, end);
        quicksort(nums, front, pivot-1);
        quicksort(nums, pivot+1, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    quicksort(nums, 0, numsSize-1);
    return nums;
}


/* TO DO : 3-way partition */
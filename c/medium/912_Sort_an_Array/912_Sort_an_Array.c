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

/*
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
*/

/*
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

   // This function partitions a[] in three parts 
   // a) a[l..i] contains all elements smaller than pivot 
   // b) a[i+1..j-1] contains all occurrences of pivot 
   // c) a[j..r] contains all elements greater than pivot 
void partition(int a[], int l, int r, int* i, int* j) 
{ 
    *i = l - 1, *j = r; 
    int pivot = rand()%(r-l+1)+l; //select random position for pivot
    swap(&a[pivot], &a[r]); // put the pivot to the end    
    int p = l - 1, q = r, v = a[r]; 
    while (true) { 
        while (a[++(*i)] < v); // 從左到右找第一個 >= v 的
        while (v < a[--(*j)]) // 從右到左找第一個 <= v 的
            if (*j == l) 
                break; 
        if (*i >= *j) break; // If i and j cross, then we are done
        
        swap(&a[*i], &a[*j]); 
        // Move all same left occurrence of pivot to beginning of array and keep count using p 
        if (a[*i] == v) { 
            p++; 
            swap(&a[p], &a[*i]); 
        } 
        // Move all same right occurrence of pivot to end of array and keep count using q
        if (a[*j] == v) { 
            q--; 
            swap(&a[*j], &a[q]); 
        } 
    } 
    swap(&a[*i], &a[r]); // Move pivot element to its correct index 
    // Move all left same occurrences from beginning to adjacent to arr[i] 
    *j = *i - 1; 
    for (int k = l; k < p; k++, (*j)--) 
        swap(&a[k], &a[*j]); 
    // Move all right same occurrences from end to adjacent to arr[i] 
    *i = *i + 1; 
    for (int k = r-1; k > q; k--, (*i)++) 
        swap(&a[*i], &a[k]); 
} 

// 3-way partition based quick sort
void quicksort(int a[], int l, int r) 
{ 
    if (r <= l) return; 
    int i, j; 
    partition(a, l, r, &i, &j); // Note that i and j are passed as reference
    
    quicksort(a, l, j); 
    quicksort(a, i, r); 
} 


int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    quicksort(nums, 0, numsSize-1);
    return nums;
}
*/

#include <time.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 3-way partition
void partition(int* nums, int front, int* mid1, int* mid2, int end)
{
    int i = front-1;
    int j = end;
    int p = front-1;
    int q = end;
    int pivot_id = rand()%(end-front+1)+front; //select a random position as a pivot position
    swap(&nums[pivot_id], &nums[end]); // put the pivot to the end of the array
    int pivot_value = nums[end];
    while(i<j)
    {
        //find the first i so that nums[i] >= pivot value
        while(nums[++i]<pivot_value)
            if(i==end) break;

        //find the first j so that nums[j] <= pivot value
        while(nums[--j]>pivot_value)
            if(j==front) break;
        
        if(i>=j) break;
        
        swap(&nums[i], &nums[j]);

        //put the nums[i] close to the front of the array if nums[i] == pivot value
        if(nums[i]==pivot_value)
        {
            ++p;
            swap(&nums[i], &nums[p]);
        }
        //put the nums[j] close to the end of the array if nums[j] == pivot value
        if(nums[j]==pivot_value)
        {
            --q;
            swap(&nums[j], &nums[q]);
        }
    }
    //put the pivot to the right position
    swap(&nums[i], &nums[end]);

    int k1 = i-1;
    //leave one left occurrence of pivot, move all the other left occurrences from the beginning(close to front) to close to the central pivot
    while(p>front)
    {
        swap(&nums[k1], &nums[p]);
        --k1;
        --p;
    }
    int k2 = i+1;
    //move all right occurrences of pivot from the end(close to end) to close to the central pivot
    while(q<end)
    {
        swap(&nums[k2], &nums[q]);
        ++k2;
        ++q;
    }
    *mid1 = k1;
    *mid2 = k2;
}

void quicksort(int* nums, int front, int end)
{
    if(front < end)
    {
        int mid1, mid2;
        partition(nums, front, &mid1, &mid2, end);
        quicksort(nums, front, mid1);
        quicksort(nums, mid2, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    time_t t;
    srand((unsigned) time(&t));
    *returnSize = numsSize;
    quicksort(nums, 0, numsSize-1);
    return nums;
}



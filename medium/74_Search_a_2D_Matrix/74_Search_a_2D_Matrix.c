/**
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * 
 * Example 1:
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * Example 2:
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//v1
/*
bool search(int* nums, int numsSize, int target){
    int leftID = 0;
    if(target == nums[leftID]) return true;
    int rightID = numsSize - 1;
    if(target == nums[rightID]) return true;
    
    int midID = (leftID + rightID) / 2;
    while(leftID + 1 < rightID)
    {
        if(nums[midID] == target) 
            return true;
        else if(nums[midID] < target)
            leftID = midID;
        else
            rightID = midID;
        midID = (leftID + rightID) / 2;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    for(int i=0; i<matrixSize; ++i)
    {
        if(search(matrix[i], matrixColSize[i], target)) 
            return true;
    }
    return false;
}
*/

//v2
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize;
    int col = matrixColSize[0];
    if(target == matrix[0][0]) return true;
    if(target == matrix[row-1][col-1]) return true;

    int leftID = 0;
    int rightID = row*col-1;
    
    int midID = (leftID + rightID) / 2;
    int midRowID;
    int midColID;
    while(leftID + 1 < rightID)
    {
        midRowID = midID/col;
        midColID = midID%col;
        if(matrix[midRowID][midColID] == target) 
            return true;
        else if(matrix[midRowID][midColID] < target)
            leftID = midID;
        else
            rightID = midID;
        midID = (leftID + rightID) / 2;
    }
    return false;
}




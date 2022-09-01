/**
 * A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column 
 * and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], 
 * where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
 * 
 * Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
 * 
 * 
 * Example 1:
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * Example 2:
 * Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 * 
 * 
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compareFunc(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = matSize;
    *returnColumnSizes = (int*)malloc(sizeof(int)*matSize);
    int** out = (int**)malloc(sizeof(int*)*matSize);
    for(int i=0; i<matSize; ++i)
    {
        (*returnColumnSizes)[i]=matColSize[i];
        out[i]=(int*)calloc(matColSize[i], sizeof(int));
    }

    int row = matSize-1;
    int tmp_row;
    int tmp_col;
    int tmp_size;
    int count;
    int* tmp;
    //
    //  *
    //  **
    //left side, start from (n-1, 0), --row until row==1
    while(row>0)
    {
        //get tmp size
        tmp_row = row;
        tmp_col = 0;
        tmp_size = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            ++tmp_size;
            ++tmp_row;
            ++tmp_col;
        }
        tmp = (int*)malloc(sizeof(int)*tmp_size);

        //assign diagonal line of mat to tmp ,then sort
        tmp_row = row;
        tmp_col = 0;
        count = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            tmp[count]=mat[tmp_row][tmp_col];
            ++count;
            ++tmp_row;
            ++tmp_col;
        }
        qsort(tmp, tmp_size, sizeof(int), compareFunc);

        //assign tmp to diagonal line of 'out'
        tmp_row = row;
        tmp_col = 0;
        count = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            out[tmp_row][tmp_col]=tmp[count];
            ++count;
            ++tmp_row;
            ++tmp_col;
        } 
        --row;
    }

    int col = 0;
    // ****
    //  *** 
    //   **
    //right side, start from (0, 0), ++col until col==n-1
    while(col<matColSize[0])
    {
        //get tmp size
        tmp_row = 0;
        tmp_col = col;
        tmp_size = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            ++tmp_size;
            ++tmp_row;
            ++tmp_col;
        }
        tmp = (int*)malloc(sizeof(int)*tmp_size);

        //assign diagonal line of mat to tmp ,then sort
        tmp_row = 0;
        tmp_col = col;
        count = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            tmp[count]=mat[tmp_row][tmp_col];
            ++count;
            ++tmp_row;
            ++tmp_col;
        }
        qsort(tmp, tmp_size, sizeof(int), compareFunc);

        //assign tmp to diagonal line of 'out'
        tmp_row = 0;
        tmp_col = col;
        count = 0;
        while(tmp_row<matSize&&tmp_col<matColSize[0])
        {
            out[tmp_row][tmp_col]=tmp[count];
            ++count;
            ++tmp_row;
            ++tmp_col;
        } 
        ++col;
    }    
    return out;
}
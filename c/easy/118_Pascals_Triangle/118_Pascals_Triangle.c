/**
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 1 <= numRows <= 30
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = (int*)calloc(numRows, sizeof(int));
    int** out = (int**)malloc(sizeof(int*)*numRows);
    for(int i=0; i<numRows; ++i)
    {
        (*returnColumnSizes)[i] = i+1;
        out[i] = (int*)malloc(sizeof(int)*(i+1));
        if(i==0) //row 1
        {
            out[0][0]=1;
        }
        else if(i==1) //row 2
        {
            out[1][0]=1;
            out[1][1]=1;
        }
        else //row 3 - row n
        {
            out[i][0]=1;
            out[i][i]=1;
            int mid = (int)(i/2);
            for(int j=1; j<=mid; ++j)
            {
                out[i][j]=out[i-1][j-1]+out[i-1][j];
                out[i][i-j]=out[i][j];
            }
        }
    }
    return out;
}
/**

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

Constraints:

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.

 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int** returnImage = (int**)malloc(sizeof(int*)*imageSize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*imageSize);
    *returnSize = imageSize;
    for(int i=0; i<imageSize; ++i)
    {
        (*returnColumnSizes)[i] = imageColSize[i];
        returnImage[i] = (int*)malloc(sizeof(int)*imageColSize[i]);
    }

    if(imageSize==1)
    {
        returnImage[0][0] = image[0][0] ? 0 : 1;
        return returnImage;
    }

    for(int i=0; i<imageSize; ++i)
    {
        int leftId = 0;
        int rightId = imageColSize[i] - 1;
        while(rightId > leftId)
        {
            returnImage[i][leftId] = image[i][rightId] ? 0 : 1;
            returnImage[i][rightId] = image[i][leftId] ? 0 : 1;
            ++leftId;
            --rightId;
            if(leftId==rightId)
            {
                returnImage[i][leftId] = image[i][rightId] ? 0 : 1;
            }
        }
    }
    return returnImage;
}
/**
 * Given the root of a binary tree, return the level order traversal of its nodes' values. 
 * (i.e., from left to right, level by level).
 * 
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * 
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 * 
 * Example 3:
 * Input: root = []
 * Output: []
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 * 
 */

extern "C" {
#include "binary_tree_utils.h"
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    /*
    // example:
    int* col1 = (int*) malloc(sizeof(int));
    col1[0] = 3;
    int* col2 = (int*) malloc(sizeof(int)*2);
    col2[0] = 9;
    col2[1] = 20;
    int* col3 = (int*) malloc(sizeof(int)*2);
    col3[0] = 15;
    col3[1] = 7;
    int** levelOrderArr = (int**) malloc(sizeof(int*)*3);
    levelOrderArr[0] = col1;
    levelOrderArr[1] = col2;
    levelOrderArr[2] = col3;

    *returnSize = 3;
    *returnColumnSizes = (int*)malloc(sizeof(int)*3);
    (*returnColumnSizes)[0] = 1;
    (*returnColumnSizes)[1] = 2;
    (*returnColumnSizes)[2] = 2;
    */

    struct QueueNode* queue = NULL;
    struct TreeNode* current = root;
    int level = 0;
    int queueSize = 1;
    int tmpQueueSize = 0;
    int* tmpCol = NULL;
    int** levelOrderArr = (int**) malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*2000);
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    queue_push(&queue, current);
    while(current)
    {
        tmpCol = (int*) malloc(sizeof(int)*queueSize);
        (*returnColumnSizes)[level] = queueSize;
        for(int i=0; i<queueSize; ++i)
        {
            current = queue_pop(&queue);
            tmpCol[i] = current->val;  

            if(current->left)
            {
                queue_push(&queue, current->left);
                ++tmpQueueSize;
            }
            if(current->right)
            {
                queue_push(&queue, current->right);  
                ++tmpQueueSize;      
            }
        }
        levelOrderArr[level] = tmpCol;
        if(queue_is_empty(queue)) break;
        queueSize = tmpQueueSize;
        tmpQueueSize = 0;
        ++level;
    }
    *returnSize = level+1;

    return levelOrderArr;
}
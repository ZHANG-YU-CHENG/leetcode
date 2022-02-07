/**
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
 * (i.e., from left to right, level by level from leaf to root).
 * 
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct QueueNode* queue = NULL;
    struct TreeNode* current = root;
    int level = 0;
    int queueSize = 1;
    int tmpQueueSize = 0;
    int* tmpCol = NULL;
    int** levelOrderArr = (int**) malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*2000);

    //If tree do not have any node, return directly
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    queue_push(&queue, current);
    while(current)
    {
        //Allocate current queue size amount of memories for this col
        tmpCol = (int*) malloc(sizeof(int)*queueSize);
        
        //Col size of current level = current queue size (which means how many nodes in queue) 
        (*returnColumnSizes)[level] = queueSize;

        //iterate over the queue
        for(int i=0; i<queueSize; ++i)
        {
            current = queue_pop(&queue);
            tmpCol[i] = current->val;  

            if(current->left)
            {
                //the new nodes be pushed in this "for loop iteration" 
                //will be iterated next time(next while loop iteration)
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

        //update queue size = how many times we push node in this "for loop iteration"
        queueSize = tmpQueueSize;
        tmpQueueSize = 0;
        ++level;
    }
    *returnSize = level+1;

    return levelOrderArr;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    //If tree do not have any node, return directly
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int** levelOrderArr = NULL;
    levelOrderArr = levelOrder(root, returnSize, returnColumnSizes);

    int** levelOrderBottomArr = (int**) malloc(sizeof(int*)*(*returnSize));
    int* levelOrderBottomeColumnSizes = (int*) malloc(sizeof(int)*(*returnSize));

    //reverse the 2d array "levelOrderArr" and assign to "levelOrderBottomArr"
    //reverse the col array "returnColumnSizes" and assgin levelOrderBottomeColumnSizes
    for(int i=0, j=(*returnSize)-1; i<(*returnSize), j>=0; ++i, --j)
    {
        levelOrderBottomArr[i] = levelOrderArr[j];
        levelOrderBottomeColumnSizes[i] = (*returnColumnSizes)[j];
    }
    *returnColumnSizes = levelOrderBottomeColumnSizes;
    return levelOrderBottomArr;
}
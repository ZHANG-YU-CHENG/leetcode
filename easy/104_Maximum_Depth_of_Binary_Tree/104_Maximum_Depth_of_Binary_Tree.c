/**
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * Example 2:
 * Input: root = [1,null,2]
 * Output: 2
 * 
 * Example 3:
 * Input: root = []
 * Output: 0
 * 
 * Example 4:
 * Input: root = [0]
 * Output: 1
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
 * 
 */

#include <math.h>
#include "binary_tree_utils.h"
 
/*
// v1
int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    int left = 0;
    int right = 0;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return (left>right) ? left+1 : right+1;
}
*/


// v2
int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    return 1+fmax(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    char* arr[] = {"3","9","20","x","x","15","7"}; //expected output = 3
    // char* arr[] = {"1","x","2"}; //expected output = 2
    // char* arr[] = {}; //expected output = 0
    // char* arr[] = {"0"}; //expected output = 1
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    int max_depth = 0;
    max_depth =  maxDepth(root);
    printf("maxDepth=%d\n", max_depth);

    return 0;
}

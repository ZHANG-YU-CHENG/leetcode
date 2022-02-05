/**
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
 * A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
 * The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 * 
 * 
 * Example 1:
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 * 
 * Example 2:
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 3 * 104].
 * -1000 <= Node.val <= 1000
 * 
 */

#include "binary_tree_utils.h"
#include <math.h>

/*
//v1
int max;
int find(struct TreeNode* root){
    //If reached the end of a branch, return 0.
    if(root==NULL) return 0;

    //The max value of left subtree, if the value less than 0, then set to 0
    int left = fmax(find(root->left), 0);

    //The max value of right subtree, if the value less than 0, then set to 0
    int right = fmax(find(root->right), 0);

    //If current max value greater than max (ans), then update max (ans)
    //max = current node value + left + right
    max = fmax(max, root->val + left + right);

    //The max value of subtree = current node value + the greater path (left or right)
    return root->val + fmax(left, right);
}

int maxPathSum(struct TreeNode* root){
    max = -1001;
    find(root);
    return max;
}
*/


//v1.1
int find(struct TreeNode* root, int* max){
    //If reached the end of a branch, return 0.
    if(root==NULL) return 0;

    //The max value of left subtree, if the value less than 0, then set to 0
    int left = fmax(find(root->left, max), 0);

    //The max value of right subtree, if the value less than 0, then set to 0
    int right = fmax(find(root->right, max), 0);

    //If current max value greater than max (ans), then update max (ans)
    //current max value = current node value + left + right
    *max = fmax(*max, root->val + left + right);

    //The max value of subtree = current node value + the greater path (left or right)
    return root->val + fmax(left, right);
}

int maxPathSum(struct TreeNode* root){
    int max = -1001;
    find(root, &max);
    return max;
}
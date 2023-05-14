/**
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 *      The left subtree of a node contains only nodes with keys less than the node's key.
 *      The right subtree of a node contains only nodes with keys greater than the node's key.
 *      Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * Input: root = [2,1,3]
 * Output: true
 * 
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * -231 <= Node.val <= 231 - 1
 * 
 */

#include<limits.h>

extern "C" {
#include "binary_tree_utils.h"
}

bool _isValidBST(struct TreeNode* root, long long int lowerBound, long long int upperBound){
    //If reached the end of the branch and it still a valid BST, return true
    if(root==NULL) return true;
    //If current node is smaller than lowerBound or greater than uppgerBound, means it is not a valid BST, return false
    if(root->val<=lowerBound || root->val>=upperBound) return false;
    //recursively search left subtree (change upper bound to current node value) 
    //and right subtree (change lower bound to current node value) until reach the end of the branch
    return _isValidBST(root->left, lowerBound, root->val) && _isValidBST(root->right, root->val, upperBound);
}

bool isValidBST(struct TreeNode* root){
    if(root==NULL) return true;
    return _isValidBST(root, LONG_MIN, LONG_MAX);
}


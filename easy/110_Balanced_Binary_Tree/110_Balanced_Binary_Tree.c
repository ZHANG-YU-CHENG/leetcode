/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 * 
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 * 
 * Example 3:
 * Input: root = []
 * Output: true
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -104 <= Node.val <= 104
 * 
 */

#include "binary_tree_utils.h"
#include <math.h>
#include <stdbool.h>


/*
//v1
int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    return 1+fmax(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int diff = maxDepth(root->left) - maxDepth(root->right);
    if(diff==0 || diff==1 || diff==-1) return isBalanced(root->left) && isBalanced(root->right);
    else return false;
}
*/

//v1.1
int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    return 1+fmax(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int diff = maxDepth(root->left) - maxDepth(root->right);
    return (diff==0 || diff==1 || diff==-1) && isBalanced(root->left) && isBalanced(root->right);
}

/*
//v2
bool isBalanced_flag = true;
int maxDepth(struct TreeNode* root){
    if(root==NULL || !isBalanced_flag)
    {
        return 0;
    }
    int dL = maxDepth(root->left);
    int dR = maxDepth(root->right);

    if(abs(dL-dR)>1)
    {
        isBalanced_flag = false;
        return 0;
    }
    else
    {
        return 1+fmax(maxDepth(root->left), maxDepth(root->right));
    }
}

bool isBalanced(struct TreeNode* root){
    isBalanced_flag = true;
    maxDepth(root);
    return isBalanced_flag;
}
*/
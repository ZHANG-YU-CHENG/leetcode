/**
 * Given the root of a binary tree, invert the tree, and return its root.
 * 
 * 
 * Example 1:
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 * 
 * Example 2:
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 * 
 * Example 3:
 * Input: root = []
 * Output: []
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 */

#include <stdio.h>
#include <stdlib.h>


 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/*
void __invertTree(struct TreeNode* root){
    if(root)
    {
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        __invertTree(root->left);
        __invertTree(root->right);        
    }
}

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;
    __invertTree(root);
    return root;
}
*/

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;    

    invertTree(root->left);
    invertTree(root->right);
    return root;
}
/**
 * You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
 * Return the root node of the BST after the insertion. 
 * It is guaranteed that the new value does not exist in the original BST.
 * Notice that there may exist multiple valid ways for the insertion, 
 * as long as the tree remains a BST after insertion. You can return any of them.
 * 
 * 
 * Example 1:
 * Input: root = [4,2,7,1,3], val = 5
 * Output: [4,2,7,1,3,5]
 * Explanation: Another accepted tree is:
 * 
 * Example 2:
 * Input: root = [40,20,60,10,30,50,70], val = 25
 * Output: [40,20,60,10,30,50,70,null,null,25]
 * 
 * Example 3:
 * Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
 * Output: [4,2,7,1,3,5]
 * 
 * 
 * Constraints:
 * The number of nodes in the tree will be in the range [0, 104].
 * -108 <= Node.val <= 108
 * All the values Node.val are unique.
 * -108 <= val <= 108
 * It's guaranteed that val does not exist in the original BST.
 * 
 */

#include<limits.h>

extern "C" {
#include "binary_tree_utils.h"
}

void find(struct TreeNode* root, int val){
    if(val > root->val)
    {
        if(root->right==NULL)
        {
            root->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            root->right->val = val;
            root->right->left = NULL;
            root->right->right = NULL;
            return;
        }
        find(root->right, val);
    }
    if(val < root->val)
    {
        if(root->left==NULL)
        {
            root->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            root->left->val = val;
            root->left->left = NULL;
            root->left->right = NULL;
            return;
        }
        find(root->left, val);
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(root==NULL)
    {
        struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    find(root, val);
    return root;
}
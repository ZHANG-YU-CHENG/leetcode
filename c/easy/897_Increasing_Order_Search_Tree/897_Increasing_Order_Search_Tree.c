/**
 * Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
 * and every node has no left child and only one right child.
 * 
 * 
 * Example 1:
 * Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * Example 2:
 * Input: root = [5,1,7]
 * Output: [1,null,5,null,7]
 * 
 * 
 * Constraints:
 * The number of nodes in the given tree will be in the range [1, 100].
 * 0 <= Node.val <= 1000
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
struct TreeNode* out;
struct TreeNode* cur;

void inorderTraversal(struct TreeNode* root)
{
    if(root && root->left)
        inorderTraversal(root->left);
    if(root)
    {
        if(out)
        {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->val = root->val;
            newNode->left = NULL;
            newNode->right = NULL;
            cur->right = newNode;
            cur = cur->right;
        }
        else
        {
            //first node
            out = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            out->val = root->val;
            out->left = NULL;
            out->right = NULL;     
            cur = out;       
        }
    }
    if(root && root->right)
        inorderTraversal(root->right);
}

//global variable solution
struct TreeNode* increasingBST(struct TreeNode* root){
    out = NULL;
    cur = NULL;
    inorderTraversal(root);
    return out;
}
*/


void inorderTraversal(struct TreeNode* root, struct TreeNode** cur)
{
    if(root && root->left)
        inorderTraversal(root->left, cur);
    if(root)
    {
        if((*cur)->val==-1)
        {
            //first node
            (*cur)->val = root->val;
        }
        else
        {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->val = root->val;
            newNode->left = NULL;
            newNode->right = NULL;
            (*cur)->right = newNode;
            *cur = (*cur)->right;
        }
    }
    if(root && root->right)
        inorderTraversal(root->right, cur);
}

//call by reference solution
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* out = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    out->left = NULL;
    out->right = NULL;
    out->val = -1;
    struct TreeNode* cur = out;
    inorderTraversal(root, &cur);
    return out;
}
/**
 * You are given the root of a binary tree where each node has a value 0 or 1. 
 * Each root-to-leaf path represents a binary number starting with the most significant bit.
 * 
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
 * The test cases are generated so that the answer fits in a 32-bits integer.
 * 
 * 
 * Example 1:
 * Input: root = [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * Example 2:
 * Input: root = [0]
 * Output: 0
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val is 0 or 1.
 * 
 */

#include <stdio.h>
#include <stdlib.h>


 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

void __sumRootToLeaf(struct TreeNode* root, int currNum, int* sum){
    if(root)
    {
        currNum = (currNum << 1) | root->val;
        if(root->left==NULL && root->right==NULL)
            *sum += currNum;
        __sumRootToLeaf(root->left, currNum, sum);
        __sumRootToLeaf(root->right, currNum, sum);        
    }
}

int sumRootToLeaf(struct TreeNode* root){
    int currNum = 0;
    int sum = 0;
    __sumRootToLeaf(root, currNum, &sum);
    return sum;
}



/* TODO, use morris preorder traversal to solve this problem */
void morrisPreorderTraversal(struct TreeNode* root)
{
    struct TreeNode* predecessor;
    while(root)
    {
        if(root->left)
        {
            predecessor = root->left;
            while(predecessor->right && predecessor->right!=root)
                predecessor = predecessor->right;
            if(predecessor->right==NULL)
            {
                printf("%d ", root->val);
                predecessor->right = root;
                root = root->left;
            }
            else
            {
                predecessor->right = NULL;
                root = root->right;
            }
        }
        else
        {
            printf("%d ", root->val);
            root = root->right;
        }
    }
}
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

/*
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
    morrisPreorderTraversal(root);
    puts("");
    int currNum = 0;
    int sum = 0;
    __sumRootToLeaf(root, currNum, &sum);
    return sum;
}
*/

// morris preorder traversal
int sumRootToLeaf(struct TreeNode* root)
{
    struct TreeNode* predecessor;
    int currNum = 0;
    int sum = 0;
    int steps = 0;
    while(root)
    {
        if(root->left)
        {
            predecessor = root->left;
            steps = 1;
            while(predecessor->right && predecessor->right!=root)
            {
                ++steps;
                predecessor = predecessor->right;
            }

            if(predecessor->right==NULL) /* if the link is NOT exist */
            {
                predecessor->right = root; /* add the link */
                currNum = (currNum << 1) | root->val;
                root = root->left;
            }
            else
            {
                if(predecessor->left==NULL)  /* this node is a leaf node */ 
                    sum += currNum;
                for(int i=0; i<steps; ++i)
                    currNum >>= 1;
                predecessor->right = NULL; /* break the link */
                root = root->right;
            }
        }
        else
        {
            currNum = (currNum << 1) | root->val;
            if(root->right==NULL) /* this node is a leaf node */
                sum += currNum;
            root = root->right;
        }
    }
    return sum;
}





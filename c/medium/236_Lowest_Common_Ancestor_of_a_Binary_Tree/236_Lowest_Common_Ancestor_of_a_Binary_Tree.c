/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: 
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
 * (where we allow a node to be a descendant of itself).”
 * 
 * 
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 * 
 * Example 3:
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [2, 105].
 * -109 <= Node.val <= 109
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
 * 
 */

#include "binary_tree_utils.h"

/*
//v1
struct TreeNode* anc = NULL;
bool findAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){

    //If reached the end of a branch, return False.
    if(root==NULL) return false;

    //If the left branch returns True, this means p or q was found below.
    bool left = findAncestor(root->left, p, q);
    
    //If the right branch returns True, this means p or q was found below.
    bool right = findAncestor(root->right, p, q);

    //If the current node itself is one of p or q, we would mark a variable mid as True
    bool mid = root==p || root==q;

    //If at any point in the traversal, any two of the three flags left, right or mid become True, 
    //this means we have found the lowest common ancestor for the nodes p and q
    if((left && right) || (mid && left) || (mid && right))
    {
        anc = root;
        return true;
    }

    //Return True if either of the three bool values is True
    return left || right || mid;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    anc = NULL;
    findAncestor(root, p, q);
    return anc;    
}
*/


//v1.1
bool findAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode** anc){

    //If reached the end of a branch, return False.
    if(root==NULL) return false;

    //If the left branch returns True, this means p or q was found below.
    bool left = findAncestor(root->left, p, q, anc);
    
    //If the right branch returns True, this means p or q was found below.
    bool right = findAncestor(root->right, p, q, anc);

    //If the current node itself is one of p or q, we would mark a variable mid as True
    bool mid = root==p || root==q;

    //If at any point in the traversal, any two of the three flags left, right or mid become True, 
    //this means we have found the lowest common ancestor for the nodes p and q
    if((left && right) || (mid && left) || (mid && right))
    {
        *anc = root;
        return true;
    }

    //Return True if either of the three bool values is True
    return left || right || mid;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* anc = NULL;
    findAncestor(root, p, q, &anc);
    return anc;    
}
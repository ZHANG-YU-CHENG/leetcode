#include "binary_tree_utils.h"

extern bool isBalanced(struct TreeNode* root);

int main()
{
    // char* arr[] = {"3","9","20","x","x","15","7"}; //expected output = true
    // char* arr[] = {"1","2","2","3","3","x","x","4","4"}; //expected output = false
    // char* arr[] = {}; //expected output = true
    char* arr[] = {"1","2","2","3","x","x","3","4","x","x","4"}; //expected output = false
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);
    printf("is balanced ? %s\n", isBalanced(root) ? "true" : "false" );
}
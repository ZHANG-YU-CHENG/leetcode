#include "binary_tree_utils.h"

extern int maxDepth(struct TreeNode* root);

int main()
{
    char* arr[] = {"3","9","20","x","x","15","7"}; //expected output = 3
    // char* arr[] = {"1","x","2"}; //expected output = 2
    // char* arr[] = {}; //expected output = 0
    // char* arr[] = {"0"}; //expected output = 1
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    int max_depth = 0;
    max_depth =  maxDepth(root);
    printf("maxDepth=%d\n", max_depth);

    return 0;
}
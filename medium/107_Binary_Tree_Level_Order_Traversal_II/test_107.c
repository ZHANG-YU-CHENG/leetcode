#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "binary_tree_utils.h"
}

extern int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

TEST(levelOrderBottomTest, test1) {
    char* arr[] = {(char*)"3",(char*)"9",(char*)"20",(char*)"x",(char*)"x",(char*)"15",(char*)"7"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** levelOrderBottomArr = NULL;
    levelOrderBottomArr = levelOrderBottom(root, &returnSize, &returnColumnSizes);

    int* col1 = (int*) malloc(sizeof(int));
    col1[0] = 3;
    int* col2 = (int*) malloc(sizeof(int)*2);
    col2[0] = 9;
    col2[1] = 20;
    int* col3 = (int*) malloc(sizeof(int)*2);
    col3[0] = 15;
    col3[1] = 7;
    int** ansArr = (int**) malloc(sizeof(int*)*3);
    ansArr[0] = col3;
    ansArr[1] = col2;
    ansArr[2] = col1;
    int* ansColArr = (int*) malloc(sizeof(int)*3);
    ansColArr[0] = 2;
    ansColArr[1] = 2;
    ansColArr[2] = 1;

    EXPECT_EQ(3, returnSize);

    //iterate over each row
    for(int row=0; row<returnSize; ++row)
    {
        EXPECT_EQ(ansColArr[row], returnColumnSizes[row]);

    	//iterate over each col
    	for(int col=0; col<returnColumnSizes[row]; ++col)
    	{
    		EXPECT_EQ(ansArr[row][col], levelOrderBottomArr[row][col]);
    	}
    }
    
    free(ansArr[0]);
    free(ansArr[1]);
    free(ansArr[2]);
    free(ansArr);
    free(levelOrderBottomArr[0]);
    free(levelOrderBottomArr[1]);
    free(levelOrderBottomArr[2]);
    free(levelOrderBottomArr);
    free(returnColumnSizes);
    deleteTree(&root);
}

TEST(levelOrderBottomTest, test2) {
    char* arr[] = {(char*)"1"};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** levelOrderBottomArr = NULL;
    levelOrderBottomArr = levelOrderBottom(root, &returnSize, &returnColumnSizes);

    int* col1 = (int*) malloc(sizeof(int));
    col1[0] = 1;
    int** ansArr = (int**) malloc(sizeof(int*));
    ansArr[0] = col1;
    int* ansColArr = (int*) malloc(sizeof(int)*1);
    ansColArr[0] = 1;

    EXPECT_EQ(1, returnSize);

    //iterate over each row
    for(int row=0; row<returnSize; ++row)
    {
        EXPECT_EQ(ansColArr[row], returnColumnSizes[row]);

    	//iterate over each col
    	for(int col=0; col<returnColumnSizes[row]; ++col)
    	{
    		EXPECT_EQ(ansArr[row][col], levelOrderBottomArr[row][col]);
    	}
    }
    
    free(ansArr[0]);
    free(ansArr);
    free(levelOrderBottomArr[0]);
    free(levelOrderBottomArr);
    free(returnColumnSizes);
    deleteTree(&root);
}

TEST(levelOrderBottomTest, test3) {
    char* arr[] = {};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct TreeNode* root = NULL;
    root = arr2BT(arr, arrlen);

    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** levelOrderBottomArr = NULL;
    levelOrderBottomArr = levelOrderBottom(root, &returnSize, &returnColumnSizes);

    EXPECT_EQ(0, returnSize);
    EXPECT_EQ(NULL, returnColumnSizes);
    EXPECT_EQ(NULL, levelOrderBottomArr);
    deleteTree(&root);
}



int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
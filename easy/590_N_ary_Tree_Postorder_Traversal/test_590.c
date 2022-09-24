#include "gtest/gtest.h"

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

extern int* postorder(struct Node* root, int* returnSize);

TEST(postorderTest, test1) {
    //level 0 (root)
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = 1;
    root->numChildren = 3;
    root->children = NULL;
    //level 1
    struct Node** children_level1 = (struct Node**)malloc(sizeof(struct Node*)*3);
    root->children = children_level1;
    children_level1[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[0])->val = 3;
    (children_level1[0])->numChildren = 2;
    (children_level1[0])->children = NULL;
    children_level1[1] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[1])->val = 2;
    (children_level1[1])->numChildren = 0;
    (children_level1[1])->children = NULL;
    children_level1[2] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[2])->val = 4;
    (children_level1[2])->numChildren = 0;
    (children_level1[2])->children = NULL;
    //level 2
    struct Node** children_level2 = (struct Node**)malloc(sizeof(struct Node*)*2);
    (children_level1[0])->children = children_level2;
    children_level2[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2[0])->val = 5;
    (children_level2[0])->numChildren = 0;
    (children_level2[0])->children = NULL;
    children_level2[1] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2[1])->val = 6;
    (children_level2[1])->numChildren = 0;
    (children_level2[1])->children = NULL;

    int returnSize;
    int* ans = postorder(root, &returnSize);
    EXPECT_EQ(returnSize, 6);
    int expect[] = {5,6,3,2,4,1};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(postorderTest, test2) {
    //level 0 (root)
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = 1;
    root->numChildren = 4;
    root->children = NULL;
    //level 1
    struct Node** children_level1 = (struct Node**)malloc(sizeof(struct Node*)*4);
    root->children = children_level1;
    children_level1[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[0])->val = 2;
    (children_level1[0])->numChildren = 0;
    (children_level1[0])->children = NULL;
    children_level1[1] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[1])->val = 3;
    (children_level1[1])->numChildren = 2;
    (children_level1[1])->children = NULL;
    children_level1[2] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[2])->val = 4;
    (children_level1[2])->numChildren = 1;
    (children_level1[2])->children = NULL;
    children_level1[3] = (struct Node*)malloc(sizeof(struct Node));
    (children_level1[3])->val = 5;
    (children_level1[3])->numChildren = 2;
    (children_level1[3])->children = NULL;
    //level 2-1
    struct Node** children_level2_1 = (struct Node**)malloc(sizeof(struct Node*)*2);
    (children_level1[1])->children = children_level2_1;
    children_level2_1[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2_1[0])->val = 6;
    (children_level2_1[0])->numChildren = 0;
    (children_level2_1[0])->children = NULL;
    children_level2_1[1] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2_1[1])->val = 7;
    (children_level2_1[1])->numChildren = 1;
    (children_level2_1[1])->children = NULL;
    //level 2-2
    struct Node** children_level2_2 = (struct Node**)malloc(sizeof(struct Node*)*1);
    (children_level1[2])->children = children_level2_2;
    children_level2_2[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2_2[0])->val = 8;
    (children_level2_2[0])->numChildren = 1;
    (children_level2_2[0])->children = NULL;
    //level 2-3
    struct Node** children_level2_3 = (struct Node**)malloc(sizeof(struct Node*)*2);
    (children_level1[3])->children = children_level2_3;
    children_level2_3[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2_3[0])->val = 9;
    (children_level2_3[0])->numChildren = 1;
    (children_level2_3[0])->children = NULL;
    children_level2_3[1] = (struct Node*)malloc(sizeof(struct Node));
    (children_level2_3[1])->val = 10;
    (children_level2_3[1])->numChildren = 0;
    (children_level2_3[1])->children = NULL;
    //level 3-1
    struct Node** children_level3_1 = (struct Node**)malloc(sizeof(struct Node*)*1);
    (children_level2_1[1])->children = children_level3_1;
    children_level3_1[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level3_1[0])->val = 11;
    (children_level3_1[0])->numChildren = 1;
    (children_level3_1[0])->children = NULL;
    //level 3-2
    struct Node** children_level3_2 = (struct Node**)malloc(sizeof(struct Node*)*1);
    (children_level2_2[0])->children = children_level3_2;
    children_level3_2[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level3_2[0])->val = 12;
    (children_level3_2[0])->numChildren = 0;
    (children_level3_2[0])->children = NULL;
    //level 3-3
    struct Node** children_level3_3 = (struct Node**)malloc(sizeof(struct Node*)*1);
    (children_level2_3[0])->children = children_level3_3;
    children_level3_3[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level3_3[0])->val = 13;
    (children_level3_3[0])->numChildren = 0;
    (children_level3_3[0])->children = NULL;
    //level 4-0
    struct Node** children_level4_0 = (struct Node**)malloc(sizeof(struct Node*)*1);
    (children_level3_1[0])->children = children_level4_0;
    children_level4_0[0] = (struct Node*)malloc(sizeof(struct Node));
    (children_level4_0[0])->val = 14;
    (children_level4_0[0])->numChildren = 0;
    (children_level4_0[0])->children = NULL;

    int returnSize;
    int* ans = postorder(root, &returnSize);
    EXPECT_EQ(returnSize, 14);
    int expect[] = {2,6,14,11,7,3,12,8,4,13,9,10,5,1};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
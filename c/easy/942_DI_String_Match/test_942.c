#include "gtest/gtest.h"

extern int* diStringMatch(char* s, int* returnSize);

TEST(diStringMatchTest, test1) {
    const char* s = "IDID";
    int* perm = NULL;
    int returnSize = 0;
    perm = diStringMatch((char*)s, &returnSize);

    int expectedPerm[] = {0,4,1,3,2}; 
    int expectedPermSize = sizeof(expectedPerm)/sizeof(expectedPerm[0]);
    EXPECT_EQ(returnSize, expectedPermSize);
    if(returnSize != expectedPermSize)
    {
        if(perm) free(perm);
        return;
    }

    for(int i=0; i<expectedPermSize; ++i)
    {
        EXPECT_EQ(perm[i], expectedPerm[i]);
    }

    if(perm) free(perm);
}

TEST(diStringMatchTest, test2) {
    const char* s = "III";
    int* perm = NULL;
    int returnSize = 0;
    perm = diStringMatch((char*)s, &returnSize);

    int expectedPerm[] = {0,1,2,3}; 
    int expectedPermSize = sizeof(expectedPerm)/sizeof(expectedPerm[0]);
    EXPECT_EQ(returnSize, expectedPermSize);
    if(returnSize != expectedPermSize)
    {
        if(perm) free(perm);
        return;
    }

    for(int i=0; i<expectedPermSize; ++i)
    {
        EXPECT_EQ(perm[i], expectedPerm[i]);
    }

    if(perm) free(perm);
}

TEST(diStringMatchTest, test3) {
    const char* s = "DDI";
    int* perm = NULL;
    int returnSize = 0;
    perm = diStringMatch((char*)s, &returnSize);

    int expectedPerm[] = {3,2,0,1}; 
    int expectedPermSize = sizeof(expectedPerm)/sizeof(expectedPerm[0]);
    EXPECT_EQ(returnSize, expectedPermSize);
    if(returnSize != expectedPermSize)
    {
        if(perm) free(perm);
        return;
    }

    for(int i=0; i<expectedPermSize; ++i)
    {
        EXPECT_EQ(perm[i], expectedPerm[i]);
    }

    if(perm) free(perm);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize);

TEST(sortPeopleTest, test1) {
    const char* names[] = {"Mary","John","Emma"};
    int namesSize = sizeof(names)/sizeof(names[0]);
    int heights[] = {180,165,170};
    int heightsSize = sizeof(heights)/sizeof(heights[0]);
    int returnSize = 0;
    char** sortedNames = NULL;
    sortedNames = sortPeople((char**)names, namesSize, heights, heightsSize, &returnSize);

    EXPECT_EQ(returnSize, namesSize);

    if(returnSize != namesSize)
    {
        if(sortedNames) free(sortedNames);
        return;
    }


    const char* expectedNames[] = {"Mary","Emma","John"};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(strcmp(sortedNames[i], expectedNames[i]), 0);
    }

    if(sortedNames) free(sortedNames);
}

TEST(sortPeopleTest, test2) {
    const char* names[] = {"Alice","Bob","Bob"};
    int namesSize = sizeof(names)/sizeof(names[0]);
    int heights[] = {155,185,150};
    int heightsSize = sizeof(heights)/sizeof(heights[0]);
    int returnSize = 0;
    char** sortedNames = NULL;
    sortedNames = sortPeople((char**)names, namesSize, heights, heightsSize, &returnSize);

    EXPECT_EQ(returnSize, namesSize);

    if(returnSize != namesSize)
    {
        if(sortedNames) free(sortedNames);
        return;
    }


    const char* expectedNames[] = {"Bob","Alice","Bob"};
    for(int i=0; i<returnSize; ++i)
    {
        EXPECT_EQ(strcmp(sortedNames[i], expectedNames[i]), 0);
    }

    if(sortedNames) free(sortedNames);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
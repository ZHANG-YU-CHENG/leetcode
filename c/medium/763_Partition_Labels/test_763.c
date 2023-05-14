#include "gtest/gtest.h"

extern int* partitionLabels(char * s, int* returnSize);

TEST(partitionLabelsTest, test1) {
    char s[] = "ababcbacadefegdehijhklij";
    int returnSize;
    int* ans = partitionLabels(s, &returnSize);
    EXPECT_EQ(returnSize, 3);
    EXPECT_EQ(ans[0], 9);
    EXPECT_EQ(ans[1], 7);
    EXPECT_EQ(ans[2], 8);
    if(ans) free(ans);
}

TEST(partitionLabelsTest, test2) {
    char s[] = "eccbbbbdec";
    int returnSize;
    int* ans = partitionLabels(s, &returnSize);
    EXPECT_EQ(returnSize, 1);
    EXPECT_EQ(ans[0], 10);
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
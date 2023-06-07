#include "gtest/gtest.h"
#include "1143_Longest_Common_Subsequence.cpp"
#include <vector>
#include <string>
using namespace std;

TEST(longestCommonSubsequenceTest, test1) {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    int result = sol.longestCommonSubsequence(text1, text2);
    EXPECT_EQ(result, 3);
}

TEST(longestCommonSubsequenceTest, test2) {
    Solution sol;
    string text1 = "abc";
    string text2 = "abc";
    int result = sol.longestCommonSubsequence(text1, text2);
    EXPECT_EQ(result, 3);
}

TEST(longestCommonSubsequenceTest, test3) {
    Solution sol;
    string text1 = "abc";
    string text2 = "def";
    int result = sol.longestCommonSubsequence(text1, text2);
    EXPECT_EQ(result, 0);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
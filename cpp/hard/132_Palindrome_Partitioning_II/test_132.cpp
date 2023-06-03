#include "gtest/gtest.h"
#include "132_Palindrome_Partitioning_II.cpp"
#include <vector>
using namespace std;

TEST(minCutTest, test1) {
    Solution sol;
    int result = sol.minCut("aab");
    EXPECT_EQ(result, 1);
}

TEST(minCutTest, test2) {
    Solution sol;
    int result = sol.minCut("a");
    EXPECT_EQ(result, 0);
}

TEST(minCutTest, test3) {
    Solution sol;
    int result = sol.minCut("ab");
    EXPECT_EQ(result, 1);
}

TEST(minCutTest, test4) {
    Solution sol;
    int result = sol.minCut("ababababababababababababcbabababababababababababa");
    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
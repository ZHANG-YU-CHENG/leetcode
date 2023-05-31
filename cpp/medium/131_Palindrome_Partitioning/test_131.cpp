#include "gtest/gtest.h"
#include "131_Palindrome_Partitioning.cpp"
#include <vector>
using namespace std;

TEST(partitionTest, test1) {
    Solution sol;
    vector<vector<string>> expected = {
        {"a", "a", "b"},
        {"aa", "b"}
    };
    vector<vector<string>> result = sol.partition("aab");
    EXPECT_EQ(result, expected);
}

TEST(partitionTest, test2) {
    Solution sol;
    vector<vector<string>> expected = {
        {"a"}
    };
    vector<vector<string>> result = sol.partition("a");
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
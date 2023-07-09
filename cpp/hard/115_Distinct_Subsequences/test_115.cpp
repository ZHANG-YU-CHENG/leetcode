#include "gtest/gtest.h"
#include "115_Distinct_Subsequences.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(numDistinctTest, test1) {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    int expected = 3;
    int result = sol.numDistinct(s, t);
    EXPECT_EQ(result, expected);
}

TEST(numDistinctTest, test2) {
    Solution sol;
    string s = "babgbag";
    string t = "bag";
    int expected = 5;
    int result = sol.numDistinct(s, t);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
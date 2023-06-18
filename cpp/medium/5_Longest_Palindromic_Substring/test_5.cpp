#include "gtest/gtest.h"
#include "5_Longest_Palindromic_Substring.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(longestPalindromeTest, test1) {
    Solution sol;

    string s = "babad";
    string result = sol.longestPalindrome(s);
    EXPECT_TRUE(result == "bab" || result == "aba");
}

TEST(longestPalindromeTest, test2) {
    Solution sol;

    string s = "cbbd";
    string result = sol.longestPalindrome(s);
    EXPECT_EQ(result, "bb");
}

TEST(longestPalindromeTest, test3) {
    Solution sol;

    string s = "a";
    string result = sol.longestPalindrome(s);
    EXPECT_EQ(result, "a");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
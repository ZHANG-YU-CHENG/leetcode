#include "gtest/gtest.h"
#include "139_Word_Break.cpp"
#include <vector>
#include <string>
using namespace std;

TEST(wordBreakTest, test1) {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    bool result = sol.wordBreak(s, wordDict);
    EXPECT_TRUE(result);
}

TEST(wordBreakTest, test2) {
    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};
    bool result = sol.wordBreak(s, wordDict);
    EXPECT_TRUE(result);
}

TEST(wordBreakTest, test3) {
    Solution sol;
    string s = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    bool result = sol.wordBreak(s, wordDict);
    EXPECT_FALSE(result);
}



int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
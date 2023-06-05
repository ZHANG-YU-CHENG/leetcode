#include "gtest/gtest.h"
#include "300_Longest_Increasing_Subsequence.cpp"
#include <vector>
using namespace std;

TEST(lengthOfLISTest, test1) {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 4);
}

TEST(lengthOfLISTest, test2) {
    Solution sol;
    vector<int> nums = {0,1,0,3,2,3};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 4);
}

TEST(lengthOfLISTest, test3) {
    Solution sol;
    vector<int> nums = {7,7,7,7,7,7,7};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 1);
}

TEST(lengthOfLISTest, test4) {
    Solution sol;
    vector<int> nums = {4,10,4,3,8,9};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 3);
}

TEST(lengthOfLISTest, test5) {
    Solution sol;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 6);
}

TEST(lengthOfLISTest, test6) {
    Solution sol;
    vector<int> nums = {0};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 1);
}

TEST(lengthOfLISTest, test7) {
    Solution sol;
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 6);
}

TEST(lengthOfLISTest, test8) {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int result = sol.lengthOfLIS(nums);
    EXPECT_EQ(result, 4);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
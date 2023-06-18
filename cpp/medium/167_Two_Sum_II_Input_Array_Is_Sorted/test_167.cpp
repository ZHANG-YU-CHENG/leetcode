#include "gtest/gtest.h"
#include "167_Two_Sum_II_Input_Array_Is_Sorted.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(twoSumTest, test1) {
    Solution sol;

    vector<int> numbers = {2, 7, 11, 15};
    vector<int> expected = {1, 2};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    EXPECT_EQ(result, expected);
}

TEST(twoSumTest, test2) {
    Solution sol;

    vector<int> numbers = {2, 3, 4};
    vector<int> expected = {1, 3};
    int target = 6;
    vector<int> result = sol.twoSum(numbers, target);
    EXPECT_EQ(result, expected);
}

TEST(twoSumTest, test3) {
    Solution sol;

    vector<int> numbers = {-1, 0};
    vector<int> expected = {1, 2};
    int target = -1;
    vector<int> result = sol.twoSum(numbers, target);
    EXPECT_EQ(result, expected);
}

TEST(twoSumTest, test4) {
    Solution sol;

    vector<int> numbers = {5, 25, 75};
    vector<int> expected = {2, 3};
    int target = 100;
    vector<int> result = sol.twoSum(numbers, target);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
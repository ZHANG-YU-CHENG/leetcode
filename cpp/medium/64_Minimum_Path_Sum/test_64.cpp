#include "gtest/gtest.h"
#include "64_Minimum_Path_Sum.cpp"
#include <vector>
using namespace std;

TEST(minPathSumTest, test1) {
    Solution sol;
    vector<vector<int>> grid = {
      {1, 3, 1},
      {1, 5, 1},
      {4, 2, 1}
    };
    int result = sol.minPathSum(grid);
    EXPECT_EQ(result, 7);
}

TEST(minPathSumTest, test2) {
    Solution sol;
    vector<vector<int>> grid = {
      {1, 2, 3},
      {4, 5, 6}
    };
    int result = sol.minPathSum(grid);
    EXPECT_EQ(result, 12);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
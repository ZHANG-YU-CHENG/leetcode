#include "gtest/gtest.h"
#include "63_Unique_Paths_II.cpp"
#include <vector>
using namespace std;

TEST(uniquePathsWithObstaclesTest, test1) {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
      {0, 0, 0},
      {0, 1, 0},
      {0, 0, 0}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    EXPECT_EQ(result, 2);
}

TEST(uniquePathsWithObstaclesTest, test2) {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
      {0, 1},
      {0, 0}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    EXPECT_EQ(result, 1);
}

TEST(uniquePathsWithObstaclesTest, test3) {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
      {1}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    EXPECT_EQ(result, 0);
}

TEST(uniquePathsWithObstaclesTest, test4) {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
      {0}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    EXPECT_EQ(result, 1);
}

TEST(uniquePathsWithObstaclesTest, test5) {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
      {1, 0}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
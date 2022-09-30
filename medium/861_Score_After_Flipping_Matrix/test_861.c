#include "gtest/gtest.h"

extern int matrixScore(int** grid, int gridSize, int* gridColSize);

TEST(matrixScoreTest, test1) {
    int grid0[] = {0,0,1,1};
    int grid1[] = {1,0,1,0};
    int grid2[] = {1,1,0,0};
    int* grid[] = {(int*)grid0, (int*)grid1, (int*)grid2};
    int gridSize = 3;
    int gridColSize[] = {4,4,4};
    int ans = matrixScore(grid, gridSize, gridColSize);
    EXPECT_EQ(ans, 39);
}

TEST(matrixScoreTest, test2) {
    int grid0[] = {0};
    int* grid[] = {(int*)grid0};
    int gridSize = 1;
    int gridColSize[] = {1};
    int ans = matrixScore(grid, gridSize, gridColSize);
    EXPECT_EQ(ans, 1);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
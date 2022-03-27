#include "gtest/gtest.h"

extern int numIslands(char** grid, int gridSize, int* gridColSize);

TEST(numIslandsTest, test1) {
    int gridSize = 4;
    int gridColSize[4] = {5, 5, 5, 5};
    char** grid = (char**)malloc(sizeof(char*)*4);
    char grid0[5] = {'1','1','1','1','0'};
    char grid1[5] = {'1','1','1','1','0'};
    char grid2[5] = {'1','1','1','1','0'};
    char grid3[5] = {'1','1','1','1','0'};
    grid[0] = grid0;
    grid[1] = grid1;
    grid[2] = grid2;
    grid[3] = grid3;
    int out = numIslands(grid, gridSize, gridColSize);
    EXPECT_EQ(1, out);
    free(grid);
}

TEST(numIslandsTest, test2) {
    int gridSize = 4;
    int gridColSize[4] = {5, 5, 5, 5};
    char** grid = (char**)malloc(sizeof(char*)*4);
    char grid0[5] = {'1','1','0','0','0'};
    char grid1[5] = {'1','1','0','0','0'};
    char grid2[5] = {'0','0','1','0','0'};
    char grid3[5] = {'0','0','0','1','1'};
    grid[0] = grid0;
    grid[1] = grid1;
    grid[2] = grid2;
    grid[3] = grid3;
    int out = numIslands(grid, gridSize, gridColSize);
    EXPECT_EQ(3, out);
    free(grid);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
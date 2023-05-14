#include "gtest/gtest.h"
#include <stdint.h>

extern bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);

TEST(searchMatrixTest, test1) {
    int matrixSize = 3;
    int matrixColSize[] = {4,4,4,4};
    int* matrix[3];
    int m0[] = {1,3,5,7};
    int m1[] = {10,11,16,20};
    int m2[] = {23,30,34,60};
    matrix[0] = m0;
    matrix[1] = m1;
    matrix[2] = m2;
    int target = 3;
    int out = searchMatrix(matrix, matrixSize, matrixColSize, target);
    EXPECT_TRUE(out);
}

TEST(searchMatrixTest, test2) {
    int matrixSize = 3;
    int matrixColSize[] = {4,4,4,4};
    int* matrix[3];
    int m0[] = {1,3,5,7};
    int m1[] = {10,11,16,20};
    int m2[] = {23,30,34,60};
    matrix[0] = m0;
    matrix[1] = m1;
    matrix[2] = m2;
    int target = 13;
    int out = searchMatrix(matrix, matrixSize, matrixColSize, target);
    EXPECT_FALSE(out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
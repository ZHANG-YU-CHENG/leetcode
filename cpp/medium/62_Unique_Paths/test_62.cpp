#include "gtest/gtest.h"
#include "62_Unique_Paths.cpp"
#include <vector>
using namespace std;

TEST(uniquePathsTest, test1) {
    Solution sol;
    int m = 3;
    int n = 7;
    int result = sol.uniquePaths(m, n);
    EXPECT_EQ(result, 28);
}

TEST(uniquePathsTest, test2) {
    Solution sol;
    int m = 3;
    int n = 2;
    int result = sol.uniquePaths(m, n);
    EXPECT_EQ(result, 3);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
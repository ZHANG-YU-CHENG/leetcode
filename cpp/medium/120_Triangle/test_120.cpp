#include "gtest/gtest.h"
#include "120_Triangle.cpp"
#include <vector>
using namespace std;

TEST(minimumTotalTest, test1) {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    int result = sol.minimumTotal(triangle);
    EXPECT_EQ(result, 11);
}

TEST(minimumTotalTest, test2) {
    Solution sol;
    vector<vector<int>> triangle = {
        {-10}
    };
    int result = sol.minimumTotal(triangle);
    EXPECT_EQ(result, -10);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
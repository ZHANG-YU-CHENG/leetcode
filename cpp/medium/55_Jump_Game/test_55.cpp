#include "gtest/gtest.h"
#include "55_Jump_Game.cpp"
#include <vector>
using namespace std;

TEST(jumpGameTest, test1) {
    Solution sol;
    vector<int> nums{2,3,1,1,4};
    bool result = sol.canJump(nums);
    EXPECT_TRUE(result);
}

TEST(jumpGameTest, test2) {
    Solution sol;
    vector<int> nums{3,2,1,0,4};
    bool result = sol.canJump(nums);
    EXPECT_FALSE(result);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"
#include "45_Jump_Game_II.cpp"
#include <vector>
using namespace std;

TEST(jumpTest, test1) {
    Solution sol;
    vector<int> nums{2,3,1,1,4};
    int result = sol.jump(nums);
    EXPECT_EQ(result, 2);
}

TEST(jumpTest, test2) {
    Solution sol;
    vector<int> nums{2,3,0,1,4};
    int result = sol.jump(nums);
    EXPECT_EQ(result, 2);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
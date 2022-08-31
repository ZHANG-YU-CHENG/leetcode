#include "gtest/gtest.h"

extern int minimumSum(int num);

TEST(minimumSumTest, test1) {
    int num = 2932;
    int ans = minimumSum(num);
    EXPECT_EQ(ans, 52);
}

TEST(minimumSumTest, test2) {
    int num = 4009;
    int ans = minimumSum(num);
    EXPECT_EQ(ans, 13);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern int numberOfSteps(int num);

TEST(numberOfStepsTest, test1) {
    int num = 14;
    int ans = numberOfSteps(num);
    EXPECT_EQ(ans, 6);
}

TEST(numberOfStepsTest, test2) {
    int num = 8;
    int ans = numberOfSteps(num);
    EXPECT_EQ(ans, 4);
}

TEST(numberOfStepsTest, test3) {
    int num = 123;
    int ans = numberOfSteps(num);
    EXPECT_EQ(ans, 12);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern int maximum69Number(int num);

TEST(maximum69NumberTest, test1) {
    int num = 9669;
    int ans = maximum69Number(num);
    EXPECT_EQ(ans, 9969);
}

TEST(maximum69NumberTest, test2) {
    int num = 9996;
    int ans = maximum69Number(num);
    EXPECT_EQ(ans, 9999);
}

TEST(maximum69NumberTest, test3) {
    int num = 9999;
    int ans = maximum69Number(num);
    EXPECT_EQ(ans, 9999);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern int findComplement(int num);

TEST(findComplementTest, test1) {
    int num = 5;
    int ans = findComplement(num);
    EXPECT_EQ(ans, 2);
}

TEST(findComplementTest, test2) {
    int num = 1;
    int ans = findComplement(num);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
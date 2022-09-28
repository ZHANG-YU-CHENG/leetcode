#include "gtest/gtest.h"

extern int bitwiseComplement(int n);

TEST(bitwiseComplementTest, test1) {
    int num = 5;
    int ans = bitwiseComplement(num);
    EXPECT_EQ(ans, 2);
}

TEST(bitwiseComplementTest, test2) {
    int num = 7;
    int ans = bitwiseComplement(num);
    EXPECT_EQ(ans, 0);
}

TEST(bitwiseComplementTest, test3) {
    int num = 10;
    int ans = bitwiseComplement(num);
    EXPECT_EQ(ans, 5);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
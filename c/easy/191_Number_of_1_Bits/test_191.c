#include "gtest/gtest.h"

extern int hammingWeight(uint32_t n);

TEST(hammingWeightTest, test1) {
    uint32_t n = 0b00000000000000000000000000001011;
    int out = hammingWeight(n);
    EXPECT_EQ(out, 3);
}

TEST(hammingWeightTest, test2) {
    uint32_t n = 0b00000000000000000000000010000000;
    int out = hammingWeight(n);
    EXPECT_EQ(out, 1);
}

TEST(hammingWeightTest, test3) {
    uint32_t n = 0b11111111111111111111111111111101;
    int out = hammingWeight(n);
    EXPECT_EQ(out, 31);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
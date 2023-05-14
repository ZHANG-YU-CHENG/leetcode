#include "gtest/gtest.h"
#include <stdint.h>

extern uint32_t reverseBits(uint32_t n);

TEST(reverseBitsTest, test1) {
    uint32_t n = 0b00000010100101000001111010011100;
    uint32_t out = reverseBits(n);
    uint32_t ans = 0b00111001011110000010100101000000;
    EXPECT_EQ(ans, out);
}

TEST(reverseBitsTest, test2) {
    uint32_t n = 0b11111111111111111111111111111101;
    uint32_t out = reverseBits(n);
    uint32_t ans = 0b10111111111111111111111111111111;
    EXPECT_EQ(ans, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern bool squareIsWhite(char * coordinates);

TEST(squareIsWhiteTest, test1) {
    char coordinates[] = "a1";
    bool ans = squareIsWhite(coordinates);
    EXPECT_FALSE(ans);
}

TEST(squareIsWhiteTest, test2) {
    char coordinates[] = "h3";
    bool ans = squareIsWhite(coordinates);
    EXPECT_TRUE(ans);
}

TEST(squareIsWhiteTest, test3) {
    char coordinates[] = "c7";
    bool ans = squareIsWhite(coordinates);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
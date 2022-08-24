#include "gtest/gtest.h"

extern char * replaceDigits(char * s);

TEST(replaceDigitsTest, test1) {
    char s[] = "a1c1e1";
    char* ans = replaceDigits(s);
    EXPECT_STREQ(ans, "abcdef");
}

TEST(replaceDigitsTest, test2) {
    char s[] = "a1b2c3d4e";
    char* ans = replaceDigits(s);
    EXPECT_STREQ(ans, "abbdcfdhe");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
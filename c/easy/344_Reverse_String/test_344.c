#include "gtest/gtest.h"

extern void reverseString(char* s, int sSize);

TEST(reverseStringTest, test1) {
    char s[] = "hello";
    int sSize = strlen(s);
    reverseString(s, sSize);
    EXPECT_STREQ(s, "olleh");
}

TEST(reverseStringTest, test2) {
    char s[] = "Hannah";
    int sSize = strlen(s);
    reverseString(s, sSize);
    EXPECT_STREQ(s, "hannaH");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
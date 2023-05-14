#include "gtest/gtest.h"

extern char * reversePrefix(char * word, char ch);

TEST(reversePrefixTest, test1) {
    char word[] = "abcdefd";
    char ch = 'd';
    char* ans = reversePrefix(word, ch);
    EXPECT_STREQ(ans, "dcbaefd");
}

TEST(reversePrefixTest, test2) {
    char word[] = "xyxzxe";
    char ch = 'z';
    char* ans = reversePrefix(word, ch);
    EXPECT_STREQ(ans, "zxyxxe");
}

TEST(reversePrefixTest, test3) {
    char word[] = "abcd";
    char ch = 'z';
    char* ans = reversePrefix(word, ch);
    EXPECT_STREQ(ans, "abcd");
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern char * reverseWords(char * s);

TEST(reverseWordsTest, test1) {
    char s[] = "Let's take LeetCode contest";
    char* ans = reverseWords(s);
    EXPECT_STREQ(ans, "s'teL ekat edoCteeL tsetnoc");
}

TEST(reverseWordsTest, test2) {
    char s[] = "God Ding";
    char* ans = reverseWords(s);
    EXPECT_STREQ(ans, "doG gniD");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
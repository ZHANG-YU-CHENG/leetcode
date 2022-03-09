#include "gtest/gtest.h"

extern char* decodeString(char * s);

TEST(decodeStringTest, test1) {
    char* s = (char*)"3[a]2[bc]";
    char* out = decodeString(s);
    EXPECT_EQ(strcmp(out, "aaabcbc"), NULL);
}

TEST(decodeStringTest, test2) {
    char* s = (char*)"3[a2[c]]";
    char* out = decodeString(s);
    EXPECT_EQ(strcmp(out, "accaccacc"), NULL);
}

TEST(decodeStringTest, test3) {
    char* s = (char*)"2[abc]3[cd]ef";
    char* out = decodeString(s);
    EXPECT_EQ(strcmp(out, "abcabccdcdcdef"), NULL);
}

TEST(decodeStringTest, test4) {
    char* s = (char*)"100[leetcode]";
    char* out = decodeString(s);
    EXPECT_EQ(strcmp(out, "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"
        "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode"), NULL);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize);

TEST(findAndReplacePatternTest, test1) {
    char* words[] = {(char*)"abc",(char*)"deq",(char*)"mee",(char*)"aqq",(char*)"dkd",(char*)"ccc"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char pattern[] = "abb";
    int returnSize;
    char** ans = findAndReplacePattern(words, wordsSize, pattern, &returnSize);
    EXPECT_EQ(returnSize, 2);
    EXPECT_STREQ(ans[0], "mee");
    EXPECT_STREQ(ans[1], "aqq");
}

TEST(findAndReplacePatternTest, test2) {
    char* words[] = {(char*)"a",(char*)"b",(char*)"c"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char pattern[] = "a";
    int returnSize;
    char** ans = findAndReplacePattern(words, wordsSize, pattern, &returnSize);
    EXPECT_EQ(returnSize, 3);
    EXPECT_STREQ(ans[0], "a");
    EXPECT_STREQ(ans[1], "b");
    EXPECT_STREQ(ans[2], "c");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
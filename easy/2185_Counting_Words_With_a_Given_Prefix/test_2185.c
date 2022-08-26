#include "gtest/gtest.h"

extern int prefixCount(char ** words, int wordsSize, char * pref);

TEST(prefixCountTest, test1) {
    char* words[] = {(char*)"pay",(char*)"attention",(char*)"practice",(char*)"attend"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char pref[] = "at";
    int ans = prefixCount(words, wordsSize, pref);
    EXPECT_EQ(ans, 2);
}

TEST(prefixCountTest, test2) {
    char* words[] = {(char*)"leetcode",(char*)"win",(char*)"loops",(char*)"success"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char pref[] = "code";
    int ans = prefixCount(words, wordsSize, pref);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
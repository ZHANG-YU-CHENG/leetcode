#include "gtest/gtest.h"

extern int countConsistentStrings(char * allowed, char ** words, int wordsSize);

TEST(countConsistentStringsTest, test1) {
    char allowed[] = "ab";
    char* words[] = {(char*)"ad",(char*)"bd",(char*)"aaab",(char*)"baa",(char*)"badab"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int ans;
    ans = countConsistentStrings(allowed, words, wordsSize);
    EXPECT_EQ(ans, 2);
}

TEST(countConsistentStringsTest, test2) {
    char allowed[] = "abc";
    char* words[] = {(char*)"a",(char*)"b",(char*)"c",(char*)"ab",(char*)"ac",(char*)"bc",(char*)"abc"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int ans;
    ans = countConsistentStrings(allowed, words, wordsSize);
    EXPECT_EQ(ans, 7);
}

TEST(countConsistentStringsTest, test3) {
    char allowed[] = "cad";
    char* words[] = {(char*)"cc",(char*)"acd",(char*)"b",(char*)"ba",(char*)"bac",(char*)"bad",(char*)"ac",(char*)"d"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int ans;
    ans = countConsistentStrings(allowed, words, wordsSize);
    EXPECT_EQ(ans, 4);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
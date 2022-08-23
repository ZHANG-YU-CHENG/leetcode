#include "gtest/gtest.h"

extern int numOfStrings(char ** patterns, int patternsSize, char * word);

TEST(numOfStringsTest, test1) {
    char* patterns[] = {(char*)"a",(char*)"abc",(char*)"bc",(char*)"d"};
    int patternsSize = sizeof(patterns)/sizeof(patterns[0]);
    char word[] = "abc";
    int ans = numOfStrings(patterns, patternsSize, word);
    EXPECT_EQ(ans, 3);
}

TEST(numOfStringsTest, test2) {
    char* patterns[] = {(char*)"a",(char*)"b",(char*)"c"};
    int patternsSize = sizeof(patterns)/sizeof(patterns[0]);
    char word[] = "aaaaabbbbb";
    int ans = numOfStrings(patterns, patternsSize, word);
    EXPECT_EQ(ans, 2);
}

TEST(numOfStringsTest, test3) {
    char* patterns[] = {(char*)"a",(char*)"a",(char*)"a"};
    int patternsSize = sizeof(patterns)/sizeof(patterns[0]);
    char word[] = "ab";
    int ans = numOfStrings(patterns, patternsSize, word);
    EXPECT_EQ(ans, 3);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
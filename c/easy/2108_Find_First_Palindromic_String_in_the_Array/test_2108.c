#include "gtest/gtest.h"

extern char * firstPalindrome(char ** words, int wordsSize);

TEST(firstPalindromeTest, test1) {
    char* words[] = {(char*)"abc",(char*)"car",(char*)"ada",(char*)"racecar",(char*)"cool"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char* ans = firstPalindrome(words, wordsSize);
    EXPECT_STREQ(ans, "ada");
}

TEST(firstPalindromeTest, test2) {
    char* words[] = {(char*)"notapalindrome",(char*)"racecar"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char* ans = firstPalindrome(words, wordsSize);
    EXPECT_STREQ(ans, "racecar");
}

TEST(firstPalindromeTest, test3) {
    char* words[] = {(char*)"def",(char*)"ghi"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    char* ans = firstPalindrome(words, wordsSize);
    EXPECT_STREQ(ans, "");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
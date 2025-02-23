#include "gtest/gtest.h"

extern int uniqueMorseRepresentations(char ** words, int wordsSize);

TEST(uniqueMorseRepresentationsTest, test1) {
    const char* words[] = {"gin","zen","gig","msg"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int out = 0;
    out = uniqueMorseRepresentations((char**)words, wordsSize);
    EXPECT_EQ(2, out);
}

TEST(uniqueMorseRepresentationsTest, test2) {
    const char* words[] = {"a"};
    int wordsSize = sizeof(words)/sizeof(words[0]);
    int out = 0;
    out = uniqueMorseRepresentations((char**)words, wordsSize);
    EXPECT_EQ(1, out);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
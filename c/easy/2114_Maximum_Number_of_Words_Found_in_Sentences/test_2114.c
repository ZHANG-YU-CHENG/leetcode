#include "gtest/gtest.h"

extern int mostWordsFound(char ** sentences, int sentencesSize);

TEST(mostWordsFoundTest, test1) {
    char* sentences[] = {(char*)"alice and bob love leetcode", (char*)"i think so too", (char*)"this is great thanks very much"};
    int sentencesSize = sizeof(sentences)/sizeof(sentences[0]);
    int ans;
    ans = mostWordsFound(sentences, sentencesSize);
    EXPECT_EQ(ans, 6);
}

TEST(mostWordsFoundTest, test2) {
    char* sentences[] = {(char*)"please wait", (char*)"continue to fight", (char*)"continue to win"};
    int sentencesSize = sizeof(sentences)/sizeof(sentences[0]);
    int ans;
    ans = mostWordsFound(sentences, sentencesSize);
    EXPECT_EQ(ans, 3);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
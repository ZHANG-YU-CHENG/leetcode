#include "gtest/gtest.h"

extern char * sortSentence(char * s);

TEST(sortSentenceTest, test1) {
    char s[] = "is2 sentence4 This1 a3";
    char* ans;
    ans = sortSentence(s);
    EXPECT_STREQ(ans, "This is a sentence");
    if(ans) free(ans);
}

TEST(sortSentenceTest, test2) {
    char s[] = "Myself2 Me1 I4 and3";
    char* ans;
    ans = sortSentence(s);
    EXPECT_STREQ(ans, "Me Myself and I");
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
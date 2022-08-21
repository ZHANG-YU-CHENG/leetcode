#include "gtest/gtest.h"

extern char * truncateSentence(char * s, int k);

TEST(truncateSentenceTest, test1) {
    char s[] = "Hello how are you Contestant";
    int k = 4;
    char* ans;
    ans = truncateSentence(s, k);
    EXPECT_STREQ(ans, "Hello how are you");
    // if(ans) free(ans);
}

TEST(truncateSentenceTest, test2) {
    char s[] = "What is the solution to this problem";
    int k = 4;
    char* ans;
    ans = truncateSentence(s, k);
    EXPECT_STREQ(ans, "What is the solution");
    // if(ans) free(ans);
}

TEST(truncateSentenceTest, test3) {
    char s[] = "chopper is not a tanuki";
    int k = 5;
    char* ans;
    ans = truncateSentence(s, k);
    EXPECT_STREQ(ans, "chopper is not a tanuki");
    // if(ans) free(ans); //do not free char array
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
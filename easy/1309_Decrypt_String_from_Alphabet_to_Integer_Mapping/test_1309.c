#include "gtest/gtest.h"

extern char * freqAlphabets(char * s);

TEST(freqAlphabetsTest, test1) {
    char s[] = "10#11#12";
    char* ans = freqAlphabets(s);
    EXPECT_STREQ(ans, "jkab");
}

TEST(freqAlphabetsTest, test2) {
    char s[] = "1326#";
    char* ans = freqAlphabets(s);
    EXPECT_STREQ(ans, "acz");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
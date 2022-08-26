#include "gtest/gtest.h"

extern bool areOccurrencesEqual(char * s);

TEST(areOccurrencesEqualTest, test1) {
    char s[] = "abacbc";
    bool ans = areOccurrencesEqual(s);
    EXPECT_TRUE(ans);
}

TEST(areOccurrencesEqualTest, test2) {
    char s[] = "aaabb";
    bool ans = areOccurrencesEqual(s);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
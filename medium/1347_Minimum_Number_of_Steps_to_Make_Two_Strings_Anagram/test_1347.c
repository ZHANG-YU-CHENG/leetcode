#include "gtest/gtest.h"

extern int minSteps(char * s, char * t);

TEST(minStepsTest, test1) {
    char s[] = "bab";
    char t[] = "aba";
    int ans = minSteps(s, t);
    EXPECT_EQ(ans, 1);
}

TEST(minStepsTest, test2) {
    char s[] = "leetcode";
    char t[] = "practice";
    int ans = minSteps(s, t);
    EXPECT_EQ(ans, 5);
}

TEST(minStepsTest, test3) {
    char s[] = "anagram";
    char t[] = "mangaar";
    int ans = minSteps(s, t);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
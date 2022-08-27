#include "gtest/gtest.h"

extern bool halvesAreAlike(char * s);

TEST(halvesAreAlikeTest, test1) {
    char s[] = "book";
    bool ans = halvesAreAlike(s);
    EXPECT_TRUE(ans);
}

TEST(halvesAreAlikeTest, test2) {
    char s[] = "textbook";
    bool ans = halvesAreAlike(s);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
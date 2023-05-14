#include "gtest/gtest.h"

extern char repeatedCharacter(char * s);

TEST(repeatedCharacterTest, test1) {
    char s[] = "abccbaacz";
    char ans = repeatedCharacter(s);
    EXPECT_EQ(ans, 'c');
}

TEST(repeatedCharacterTest, test2) {
    char s[] = "abcdd";
    char ans = repeatedCharacter(s);
    EXPECT_EQ(ans, 'd');
}

TEST(repeatedCharacterTest, test3) {
    char s[] = "abcd";
    char ans = repeatedCharacter(s);
    EXPECT_EQ(ans, 'd');
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
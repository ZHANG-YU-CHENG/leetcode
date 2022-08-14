#include "gtest/gtest.h"

extern bool isAnagram(char * s, char * t);

TEST(isAnagramTest, test1) {
    char s[] = "anagram";
    char t[] = "nagaram";
    bool ans;
    ans = isAnagram(s, t);
    EXPECT_TRUE(ans);
}

TEST(isAnagramTest, test2) {
    char s[] = "rat";
    char t[] = "car";
    bool ans;
    ans = isAnagram(s, t);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
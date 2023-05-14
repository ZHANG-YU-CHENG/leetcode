#include "gtest/gtest.h"

extern bool checkIfPangram(char * sentence);

TEST(checkIfPangramTest, test1) {
    char sentence[] = "thequickbrownfoxjumpsoverthelazydog";
    bool ans = checkIfPangram(sentence);
    EXPECT_TRUE(ans);
}

TEST(checkIfPangramTest, test2) {
    char sentence[] = "leetcode";
    bool ans = checkIfPangram(sentence);
    EXPECT_FALSE(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"

extern int numJewelsInStones(char * jewels, char * stones);

TEST(numJewelsInStonesTest, test1) {
    char jewels[] = "aA";
    char stones[] = "aAAbbbb";
    int ans;
    ans = numJewelsInStones(jewels, stones);
    EXPECT_EQ(ans, 3);
}

TEST(numJewelsInStonesTest, test2) {
    char jewels[] = "z";
    char stones[] = "ZZ";
    int ans;
    ans = numJewelsInStones(jewels, stones);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
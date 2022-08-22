#include "gtest/gtest.h"

extern int countPoints(char * rings);

TEST(countPointsTest, test1) {
    char rings[] = "B0B6G0R6R0R6G9";
    int ans = countPoints(rings);
    EXPECT_EQ(ans, 1);
}

TEST(countPointsTest, test2) {
    char rings[] = "B0R0G0R9R0B0G0";
    int ans = countPoints(rings);
    EXPECT_EQ(ans, 1);
}

TEST(countPointsTest, test3) {
    char rings[] = "G4";
    int ans = countPoints(rings);
    EXPECT_EQ(ans, 0);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
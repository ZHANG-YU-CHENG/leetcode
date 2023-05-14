#include "gtest/gtest.h"

extern int firstBadVersion(int n);
extern int firstBad;

TEST(firstBadVersionTest, test1) {
    int n = 5;
    firstBad = 4;
    int bad = firstBadVersion(n);
    EXPECT_EQ(4, bad);
}

TEST(firstBadVersionTest, test2) {
    int n = 1;
    firstBad = 1;
    int bad = firstBadVersion(n);
    EXPECT_EQ(1, bad);
}

TEST(firstBadVersionTest, test3) {
    int n = 3;
    firstBad = 3;
    int bad = firstBadVersion(n);
    EXPECT_EQ(3, bad);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"
#include "72_Edit_Distance.cpp"
#include <vector>
#include <string>
using namespace std;

TEST(minDistanceTest, test1) {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    int result = sol.minDistance(word1, word2);
    EXPECT_EQ(result, 3);
}

TEST(minDistanceTest, test2) {
    Solution sol;
    string word1 = "intention";
    string word2 = "execution";
    int result = sol.minDistance(word1, word2);
    EXPECT_EQ(result, 5);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
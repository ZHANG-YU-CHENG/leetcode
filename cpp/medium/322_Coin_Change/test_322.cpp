#include "gtest/gtest.h"
#include "322_Coin_Change.cpp"
#include <vector>
using namespace std;

TEST(coinChangeTest, test1) {
    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    EXPECT_EQ(result, 3);
}

TEST(coinChangeTest, test2) {
    Solution sol;
    vector<int> coins = {2};
    int amount = 3;
    int result = sol.coinChange(coins, amount);
    EXPECT_EQ(result, -1);
}

TEST(coinChangeTest, test3) {
    Solution sol;
    vector<int> coins = {1};
    int amount = 0;
    int result = sol.coinChange(coins, amount);
    EXPECT_EQ(result, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
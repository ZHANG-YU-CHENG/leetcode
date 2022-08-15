#include "gtest/gtest.h"

extern int maxProfit(int* prices, int pricesSize);

TEST(maxProfitTest, test1) {
    int prices[] = {7,1,5,3,6,4};
    int pricesSize = sizeof(prices)/sizeof(prices[0]);
    int ans;
    ans = maxProfit(prices, pricesSize);
    EXPECT_EQ(ans, 5);
}

TEST(maxProfitTest, test2) {
    int prices[] = {7,6,4,3,1};
    int pricesSize = sizeof(prices)/sizeof(prices[0]);
    int ans;
    ans = maxProfit(prices, pricesSize);
    EXPECT_EQ(ans, 0);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
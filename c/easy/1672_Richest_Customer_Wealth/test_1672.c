#include "gtest/gtest.h"

extern int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);

TEST(maximumWealthTest, test1) {
    int accounts_0[] = {1,2,3};
    int accounts_1[] = {3,2,1};
    int* accounts[] = {(int*)accounts_0,(int*)accounts_1};
    int accountsSize = sizeof(accounts)/sizeof(accounts[0]);
    int accountsColSize[] = {3,3};
    int ans = maximumWealth(accounts, accountsSize, accountsColSize);
    EXPECT_EQ(ans, 6);
}

TEST(maximumWealthTest, test2) {
    int accounts_0[] = {1,5};
    int accounts_1[] = {7,3};
    int accounts_2[] = {3,5};
    int* accounts[] = {(int*)accounts_0,(int*)accounts_1,(int*)accounts_2};
    int accountsSize = sizeof(accounts)/sizeof(accounts[0]);
    int accountsColSize[] = {2,2,2};
    int ans = maximumWealth(accounts, accountsSize, accountsColSize);
    EXPECT_EQ(ans, 10);
}

TEST(maximumWealthTest, test3) {
    int accounts_0[] = {2,8,7};
    int accounts_1[] = {7,1,3};
    int accounts_2[] = {1,9,5};
    int* accounts[] = {(int*)accounts_0,(int*)accounts_1,(int*)accounts_2};
    int accountsSize = sizeof(accounts)/sizeof(accounts[0]);
    int accountsColSize[] = {3,3,3};
    int ans = maximumWealth(accounts, accountsSize, accountsColSize);
    EXPECT_EQ(ans, 17);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
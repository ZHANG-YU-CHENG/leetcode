#include "gtest/gtest.h"

extern int countTriplets(int* arr, int arrSize);

TEST(countTripletsTest, test1) {
    int arr[] = {2,3,1,6,7};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int ans = countTriplets(arr, arrSize);
    EXPECT_EQ(ans, 4);
}

TEST(countTripletsTest, test2) {
    int arr[] = {1,1,1,1,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int ans = countTriplets(arr, arrSize);
    EXPECT_EQ(ans, 10);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
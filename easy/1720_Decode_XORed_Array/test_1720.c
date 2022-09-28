#include "gtest/gtest.h"

extern int* decode(int* encoded, int encodedSize, int first, int* returnSize);

TEST(decodeTest, test1) {
    int encoded[] = {1,2,3};
    int encodedSize = sizeof(encoded)/sizeof(encoded[0]);
    int first = 1;
    int returnSize;
    int* ans = decode(encoded, encodedSize, first, &returnSize);
    EXPECT_EQ(returnSize, encodedSize+1);

    int expect[] = {1,0,2,1};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

TEST(decodeTest, test2) {
    int encoded[] = {6,2,7,3};
    int encodedSize = sizeof(encoded)/sizeof(encoded[0]);
    int first = 4;
    int returnSize;
    int* ans = decode(encoded, encodedSize, first, &returnSize);
    EXPECT_EQ(returnSize, encodedSize+1);

    int expect[] = {4,2,0,7,4};
    for(int i=0; i<returnSize; ++i)
        EXPECT_EQ(ans[i], expect[i]);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
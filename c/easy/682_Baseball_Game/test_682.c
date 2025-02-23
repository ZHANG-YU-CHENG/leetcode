#include "gtest/gtest.h"

extern int calPoints(char** operations, int operationsSize);

TEST(calPointsTest, test1) {
    const char* operations[] = {"5","2","C","D","+"};
    int operationsSize = sizeof(operations)/sizeof(operations[0]);
    int sum = 0;
    sum = calPoints((char**)operations, operationsSize);
    EXPECT_EQ(30, sum);
}

TEST(calPointsTest, test2) {
    const char* operations[] = {"5","-2","4","C","D","9","+","+"};
    int operationsSize = sizeof(operations)/sizeof(operations[0]);
    int sum = 0;
    sum = calPoints((char**)operations, operationsSize);
    EXPECT_EQ(27, sum);
}

TEST(calPointsTest, test3) {
    const char* operations[] = {"1","C"};
    int operationsSize = sizeof(operations)/sizeof(operations[0]);
    int sum = 0;
    sum = calPoints((char**)operations, operationsSize);
    EXPECT_EQ(0, sum);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\r\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
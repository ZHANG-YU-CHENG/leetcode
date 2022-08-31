#include "gtest/gtest.h"

extern int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize);

TEST(minMovesToSeatTest, test1) {
    int seats[] = {3,1,5};
    int seatsSize = sizeof(seats)/sizeof(seats[0]);
    int students[] = {2,7,4};
    int studentsSize = sizeof(students)/sizeof(students[0]);
    int ans = minMovesToSeat(seats, seatsSize, students, studentsSize);
    EXPECT_EQ(ans, 4);
}

TEST(minMovesToSeatTest, test2) {
    int seats[] = {4,1,5,9};
    int seatsSize = sizeof(seats)/sizeof(seats[0]);
    int students[] = {1,3,2,6};
    int studentsSize = sizeof(students)/sizeof(students[0]);
    int ans = minMovesToSeat(seats, seatsSize, students, studentsSize);
    EXPECT_EQ(ans, 7);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
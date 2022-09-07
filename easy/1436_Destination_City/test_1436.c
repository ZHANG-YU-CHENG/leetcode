#include "gtest/gtest.h"

extern char * destCity(char *** paths, int pathsSize, int* pathsColSize);

TEST(destCityTest, test1) {
    char* paths0[] = {(char*)"London",(char*)"New York"};
    char* paths1[] = {(char*)"New York",(char*)"Lima"};
    char* paths2[] = {(char*)"Lima",(char*)"Sao Paulo"};
    char** paths[] = {(char**)paths0, (char**)paths1, (char**)paths2};
    int pathsSize = sizeof(paths)/sizeof(paths[0]);
    int pathsColSize[] = {2,2,2};
    char* ans = destCity(paths, pathsSize, pathsColSize);
    EXPECT_STREQ(ans, "Sao Paulo");
}

TEST(destCityTest, test2) {
    char* paths0[] = {(char*)"B",(char*)"C"};
    char* paths1[] = {(char*)"D",(char*)"B"};
    char* paths2[] = {(char*)"C",(char*)"A"};
    char** paths[] = {(char**)paths0, (char**)paths1, (char**)paths2};
    int pathsSize = sizeof(paths)/sizeof(paths[0]);
    int pathsColSize[] = {2,2,2};
    char* ans = destCity(paths, pathsSize, pathsColSize);
    EXPECT_STREQ(ans, "A");
}

TEST(destCityTest, test3) {
    char* paths0[] = {(char*)"A",(char*)"Z"};
    char** paths[] = {(char**)paths0};
    int pathsSize = sizeof(paths)/sizeof(paths[0]);
    int pathsColSize[] = {2};
    char* ans = destCity(paths, pathsSize, pathsColSize);
    EXPECT_STREQ(ans, "Z");
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
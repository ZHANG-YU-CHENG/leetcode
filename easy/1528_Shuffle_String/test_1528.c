#include "gtest/gtest.h"

extern char * restoreString(char * s, int* indices, int indicesSize);

TEST(restoreStringTest, test1) {
    char s[] = "codeleet";
    int indices[] = {4,5,6,7,0,2,1,3};
    int indicesSize = sizeof(indices)/sizeof(indices[0]);
    char* ans;
    ans = restoreString(s, indices, indicesSize);
    EXPECT_STREQ(ans, "leetcode");
    if(ans) free(ans);
}

TEST(restoreStringTest, test2) {
    char s[] = "abc";
    int indices[] = {0,1,2};
    int indicesSize = sizeof(indices)/sizeof(indices[0]);
    char* ans;
    ans = restoreString(s, indices, indicesSize);
    EXPECT_STREQ(ans, "abc");
    if(ans) free(ans);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
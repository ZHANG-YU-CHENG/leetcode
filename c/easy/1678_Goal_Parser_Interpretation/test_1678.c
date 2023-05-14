#include "gtest/gtest.h"

extern char * interpret(char * command);

TEST(interpretTest, test1) {
    char command[] = "G()(al)";
    char* ans;
    ans = interpret(command);
    EXPECT_STREQ(ans, "Goal");
    if(ans) free(ans);
}

TEST(interpretTest, test2) {
    char command[] = "G()()()()(al)";
    char* ans;
    ans = interpret(command);
    EXPECT_STREQ(ans, "Gooooal");
    if(ans) free(ans);
}

TEST(interpretTest, test3) {
    char command[] = "(al)G(al)()()G";
    char* ans;
    ans = interpret(command);
    EXPECT_STREQ(ans, "alGalooG");
    if(ans) free(ans);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
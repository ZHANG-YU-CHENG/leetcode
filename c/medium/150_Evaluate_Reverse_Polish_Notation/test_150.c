#include "gtest/gtest.h"

extern int evalRPN(char ** tokens, int tokensSize);

TEST(evalRPNTest, test1) {
    char* tokens[] = {(char*)"2",(char*)"1",(char*)"+",(char*)"3",(char*)"*"};
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int out = evalRPN(tokens, tokensSize);
    EXPECT_EQ(out, 9);
}

TEST(evalRPNTest, test2) {
    char* tokens[] = {(char*)"4",(char*)"13",(char*)"5",(char*)"/",(char*)"+"};
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int out = evalRPN(tokens, tokensSize);
    EXPECT_EQ(out, 6);
}

TEST(evalRPNTest, test3) {
    char* tokens[] = {
        (char*)"10",(char*)"6",(char*)"9",(char*)"3",(char*)"+",(char*)"-11",(char*)"*",
        (char*)"/",(char*)"*",(char*)"17",(char*)"+",(char*)"5",(char*)"+"
    };
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int out = evalRPN(tokens, tokensSize);
    EXPECT_EQ(out, 22);
}

TEST(evalRPNTest, test4) {
    char* tokens[] = {
        (char*)"-78",(char*)"-33",(char*)"196",(char*)"+",(char*)"-19",(char*)"-",(char*)"115",
        (char*)"+",(char*)"-",(char*)"-99",(char*)"/",(char*)"-18",(char*)"8",(char*)"*",
        (char*)"-86",(char*)"-",(char*)"-",(char*)"16",(char*)"/",(char*)"26",(char*)"-14",
        (char*)"-",(char*)"-",(char*)"47",(char*)"-",(char*)"101",(char*)"-",(char*)"163",
        (char*)"*",(char*)"143",(char*)"-",(char*)"0",(char*)"-",(char*)"171",(char*)"+",
        (char*)"120",(char*)"*",(char*)"-60",(char*)"+",(char*)"156",(char*)"/",(char*)"173",
        (char*)"/",(char*)"-24",(char*)"11",(char*)"+",(char*)"21",(char*)"/",(char*)"*",
        (char*)"44",(char*)"*",(char*)"180",(char*)"70",(char*)"-40",(char*)"-",(char*)"*",
        (char*)"86",(char*)"132",(char*)"-84",(char*)"+",(char*)"*",(char*)"-",(char*)"38",
        (char*)"/",(char*)"/",(char*)"21",(char*)"28",(char*)"/",(char*)"+",(char*)"83",
        (char*)"/",(char*)"-31",(char*)"156",(char*)"-",(char*)"+",(char*)"28",(char*)"/",
        (char*)"95",(char*)"-",(char*)"120",(char*)"+",(char*)"8",(char*)"*",(char*)"90",
        (char*)"-",(char*)"-94",(char*)"*",(char*)"-73",(char*)"/",(char*)"-62",(char*)"/",
        (char*)"93",(char*)"*",(char*)"196",(char*)"-",(char*)"-59",(char*)"+",(char*)"187",
        (char*)"-",(char*)"143",(char*)"/",(char*)"-79",(char*)"-89",(char*)"+",(char*)"-"
    };
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int out = evalRPN(tokens, tokensSize);
    EXPECT_EQ(out, 165);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
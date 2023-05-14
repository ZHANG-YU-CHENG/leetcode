#include "gtest/gtest.h"

extern int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue);

TEST(countMatchesTest, test1) {
    char* item0[] = {(char*)"phone",(char*)"blue",(char*)"pixel"};
    char* item1[] = {(char*)"computer",(char*)"silver",(char*)"lenovo"};
    char* item2[] = {(char*)"phone",(char*)"gold",(char*)"iphone"};
    char** items[] = {(char**)item0, (char**)item1, (char**)item2};
    int itemsSize = sizeof(items)/sizeof(items[0]);
    int itemsColSize[itemsSize] = {3,3,3};
    char ruleKey[] = "color";
    char ruleValue[] = "silver";
    int ans;
    ans = countMatches(items, itemsSize, itemsColSize, ruleKey, ruleValue);
    EXPECT_EQ(ans, 1);
}

TEST(countMatchesTest, test2) {
    char* item0[] = {(char*)"phone",(char*)"blue",(char*)"pixel"};
    char* item1[] = {(char*)"computer",(char*)"silver",(char*)"phone"};
    char* item2[] = {(char*)"phone",(char*)"gold",(char*)"iphone"};
    char** items[] = {(char**)item0, (char**)item1, (char**)item2};
    int itemsSize = sizeof(items)/sizeof(items[0]);
    int itemsColSize[itemsSize] = {3,3,3};
    char ruleKey[] = "type";
    char ruleValue[] = "phone";
    int ans;
    ans = countMatches(items, itemsSize, itemsColSize, ruleKey, ruleValue);
    EXPECT_EQ(ans, 2);
}

TEST(countMatchesTest, test3) {
    char* item0[] = {(char*)"lrllrl",(char*)"l",(char*)"l"};
    char* item1[] = {(char*)"l",(char*)"l",(char*)"lrllrl"};
    char* item2[] = {(char*)"lrllrl",(char*)"lrllrl",(char*)"lrllrl"};
    char* item3[] = {(char*)"l",(char*)"l",(char*)"lrllrl"};
    char* item4[] = {(char*)"lrllrl",(char*)"l",(char*)"lrllrl"};
    char* item5[] = {(char*)"l",(char*)"l",(char*)"l"};
    char* item6[] = {(char*)"l",(char*)"lrllrl",(char*)"l"};
    char** items[] = {(char**)item0, (char**)item1, (char**)item2, (char**)item3, (char**)item4, (char**)item5, (char**)item6};
    int itemsSize = sizeof(items)/sizeof(items[0]);
    int itemsColSize[itemsSize] = {3,3,3,3,3,3,3};
    char ruleKey[] = "name";
    char ruleValue[] = "lrllrl";
    int ans;
    ans = countMatches(items, itemsSize, itemsColSize, ruleKey, ruleValue);
    EXPECT_EQ(ans, 4);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
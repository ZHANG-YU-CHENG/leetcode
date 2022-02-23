#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern bool isPalindrome(struct ListNode* head);

TEST(isPalindromeTest, test1) {
    int arr[] = {1,2,2,1};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    EXPECT_TRUE(isPalindrome(head));

    if(head) free(head);
    head = NULL;
}

TEST(isPalindromeTest, test2) {
    int arr[] = {1,2};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    EXPECT_FALSE(isPalindrome(head));

    if(head) free(head);
    head = NULL;
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
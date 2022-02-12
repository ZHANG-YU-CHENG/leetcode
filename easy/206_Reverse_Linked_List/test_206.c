#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern struct ListNode* reverseList(struct ListNode* head);

TEST(reverseListTest, test1) {
    int arr[] = {1,2,3,4,5}; //expected output={5,4,3,2,1}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = reverseList(head);
    // printList(out);

    int ansarr[] = {5,4,3,2,1};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(out, ansList));

    if(head) free(head);
    head = NULL;
    out = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

TEST(reverseListTest, test2) {
    int arr[] = {1,2}; //expected output={2,1}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = reverseList(head);
    // printList(out);

    int ansarr[] = {2,1};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(out, ansList));

    if(head) free(head);
    head = NULL;
    out = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

TEST(reverseListTest, test3) {
    int arr[] = {}; //expected output={}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = reverseList(head);
    // printList(out);

    int ansarr[] = {};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(out, ansList));

    if(head) free(head);
    head = NULL;
    out = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
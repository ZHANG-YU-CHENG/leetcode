#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern struct ListNode* sortList(struct ListNode* head);

TEST(sortListTest, test1) {
    int arr[] = {4,2,1,3};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = sortList(head);
    // printList(out);

    int ansarr[] = {1,2,3,4}; //expected output
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

TEST(sortListTest, test2) {
    int arr[] = {-1,5,3,4,0};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = sortList(head);
    // printList(out);

    int ansarr[] = {-1,0,3,4,5}; //expected output
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
#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern struct ListNode* partition(struct ListNode* head, int x);

TEST(partitionTest, test1) {
    int arr[] = {1,4,3,2,5,2};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    int x = 3;
    out = partition(head, x);
    // printList(out);

    int ansarr[] = {1,2,2,4,3,5}; //expected output
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

TEST(partitionTest, test2) {
    int arr[] = {2,1};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    int x = 2;
    out = partition(head, x);
    // printList(out);

    int ansarr[] = {1,2}; //expected output
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
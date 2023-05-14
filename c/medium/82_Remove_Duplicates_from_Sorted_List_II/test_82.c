#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern struct ListNode* deleteDuplicates(struct ListNode* head);

TEST(deleteDuplicatesTest, test1) {
    int arr[] = {1,2,3,3,4,4,5}; //expected output={1,2,5}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = deleteDuplicates(head);
    // printList(out);

    int ansarr[] = {1,2,5};
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

TEST(deleteDuplicatesTest, test2) {
    int arr[] = {1,1,1,2,3}; //expected output={2,3}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = deleteDuplicates(head);
    // printList(out);

    int ansarr[] = {2,3};
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

TEST(deleteDuplicatesTest, test3) {
    int arr[] = {1,2,2}; //expected output={1}
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    struct ListNode* out = NULL;
    out = deleteDuplicates(head);
    // printList(out);

    int ansarr[] = {1};
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

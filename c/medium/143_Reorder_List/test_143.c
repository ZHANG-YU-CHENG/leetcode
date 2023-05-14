#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern void reorderList(struct ListNode* head);

TEST(reorderListTest, test1) {
    int arr[] = {1,2,3,4};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    reorderList(head);
    // printList(head);

    int ansarr[] = {1,4,2,3}; //expected output
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(head, ansList));

    if(head) free(head);
    head = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}


TEST(reorderListTest, test2) {
    int arr[] = {1,2,3,4,5};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    reorderList(head);
    // printList(head);

    int ansarr[] = {1,5,2,4,3}; //expected output
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(head, ansList));

    if(head) free(head);
    head = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
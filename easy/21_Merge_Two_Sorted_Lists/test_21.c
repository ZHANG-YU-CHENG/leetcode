#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

TEST(mergeTwoListsTest, test1) {
    int arr1[] = {1,2,4};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct ListNode* l1 = NULL;
    l1 = arr2List(arr1, arr1len);
    int arr2[] = {1,3,4};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct ListNode* l2 = NULL;
    l2 = arr2List(arr2, arr2len);

    struct ListNode* mergedlist = NULL;
    mergedlist = mergeTwoLists(l1, l2);
    // printList(mergedlist);

    int ansarr[] = {1,1,2,3,4,4};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(mergedlist, ansList));

    if(l1) free(l1);
    l1 = NULL;
    if(l2) free(l2);
    l2 = NULL;
    mergedlist = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

TEST(mergeTwoListsTest, test2) {
    int arr1[] = {};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct ListNode* l1 = NULL;
    l1 = arr2List(arr1, arr1len);
    int arr2[] = {0};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct ListNode* l2 = NULL;
    l2 = arr2List(arr2, arr2len);

    struct ListNode* mergedlist = NULL;
    mergedlist = mergeTwoLists(l1, l2);
    // printList(mergedlist);

    int ansarr[] = {0};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(mergedlist, ansList));

    if(l1) free(l1);
    l1 = NULL;
    if(l2) free(l2);
    l2 = NULL;
    mergedlist = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

TEST(mergeTwoListsTest, test3) {
    int arr1[] = {5};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct ListNode* l1 = NULL;
    l1 = arr2List(arr1, arr1len);
    int arr2[] = {1,2,4};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct ListNode* l2 = NULL;
    l2 = arr2List(arr2, arr2len);

    struct ListNode* mergedlist = NULL;
    mergedlist = mergeTwoLists(l1, l2);
    // printList(mergedlist);

    int ansarr[] = {1,2,4,5};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(mergedlist, ansList));

    if(l1) free(l1);
    l1 = NULL;
    if(l2) free(l2);
    l2 = NULL;
    mergedlist = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

TEST(mergeTwoListsTest, test4) {
    int arr1[] = {1};
    int arr1len = (int) (sizeof(arr1)/sizeof(arr1[0]));
    struct ListNode* l1 = NULL;
    l1 = arr2List(arr1, arr1len);
    int arr2[] = {2};
    int arr2len = (int) (sizeof(arr2)/sizeof(arr2[0]));
    struct ListNode* l2 = NULL;
    l2 = arr2List(arr2, arr2len);

    struct ListNode* mergedlist = NULL;
    mergedlist = mergeTwoLists(l1, l2);
    // printList(mergedlist);

    int ansarr[] = {1,2};
    int ansarrlen = (int) (sizeof(ansarr)/sizeof(ansarr[0]));
    struct ListNode* ansList = NULL;
    ansList = arr2List(ansarr, ansarrlen);

    EXPECT_TRUE(compareList(mergedlist, ansList));

    if(l1) free(l1);
    l1 = NULL;
    if(l2) free(l2);
    l2 = NULL;
    mergedlist = NULL;
    if(ansList) free(ansList);
    ansList = NULL;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
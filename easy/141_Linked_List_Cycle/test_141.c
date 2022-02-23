#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

extern bool hasCycle(struct ListNode *head);

TEST(hasCycleTest, test1) {
    int arr[] = {1,2,3,4};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    //find tail and posNode
    struct ListNode* cur = head;
    struct ListNode* posNode = NULL;
    int count = 0;
    int pos = 1;
    while(cur->next)
    {
        if(count==pos) posNode = cur;
        cur = cur->next;
        ++count;
    }
    //make a cycle, tail --> posNode
    cur->next = posNode;

    EXPECT_TRUE(hasCycle(head));

    if(head) free(head);
    head = NULL;
}

TEST(hasCycleTest, test2) {
    int arr[] = {1,2};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    //find tail and posNode
    struct ListNode* cur = head;
    struct ListNode* posNode = NULL;
    int count = 0;
    int pos = 0;
    while(cur->next)
    {
        if(count==pos) posNode = cur;
        cur = cur->next;
        ++count;
    }
    //make a cycle, tail --> posNode
    cur->next = posNode;

    EXPECT_TRUE(hasCycle(head));

    if(head) free(head);
    head = NULL;
}

TEST(hasCycleTest, test3) {
    int arr[] = {1};
    int arrlen = (int) (sizeof(arr)/sizeof(arr[0]));
    struct ListNode* head = NULL;
    head = arr2List(arr, arrlen);

    //find tail and posNode
    struct ListNode* cur = head;
    struct ListNode* posNode = NULL;
    int count = 0;
    int pos = -1;
    while(cur->next)
    {
        if(count==pos) posNode = cur;
        cur = cur->next;
        ++count;
    }
    //make a cycle, tail --> posNode
    cur->next = posNode;

    EXPECT_FALSE(hasCycle(head));

    if(head) free(head);
    head = NULL;
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
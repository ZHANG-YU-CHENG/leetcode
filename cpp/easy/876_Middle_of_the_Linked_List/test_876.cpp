#include "gtest/gtest.h"
#include "876_Middle_of_the_Linked_List.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(middleNodeTest, test1) {
    Solution sol;

    // Test case 1: head = [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = sol.middleNode(head);
    EXPECT_EQ(middle->val, 3);

    // Clean up
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST(middleNodeTest, test2) {
    Solution sol;

    // Test case 2: head = [1,2,3,4,5,6]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode* middle = sol.middleNode(head);
    EXPECT_EQ(middle->val, 4);

    // Clean up
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
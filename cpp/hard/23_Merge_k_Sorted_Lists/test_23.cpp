#include "gtest/gtest.h"
#include "23_Merge_k_Sorted_Lists.cpp"
#include <vector>
#include <iostream>
using namespace std;

TEST(mergeKListsTest, test1) {
    Solution sol;

    // Create test input (three sorted linked lists)
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    // Expected output (sorted merged list)
    ListNode* expected = new ListNode(1);
    expected->next = new ListNode(1);
    expected->next->next = new ListNode(2);
    expected->next->next->next = new ListNode(3);
    expected->next->next->next->next = new ListNode(4);
    expected->next->next->next->next->next = new ListNode(4);
    expected->next->next->next->next->next->next = new ListNode(5);
    expected->next->next->next->next->next->next->next = new ListNode(6);

    // Call the function
    ListNode* result = sol.mergeKLists(lists);

    int result_size = 0;
    ListNode* tmp = result;
    while (tmp) {
        ++result_size;
        tmp = tmp->next;
    }
    EXPECT_EQ(result_size, 8);

    // Compare the result with the expected output
    while (result && expected) {
        EXPECT_EQ(result->val, expected->val);
        result = result->next;
        expected = expected->next;
    }

    // Clean up memory
    delete list1;
    delete list2;
    delete list3;
    delete expected;
}

TEST(mergeKListsTest, test2) {
    Solution sol;

    vector<ListNode*> lists = {};

    ListNode* expected = nullptr;

    // Call the function
    ListNode* result = sol.mergeKLists(lists);

    int result_size = 0;
    ListNode* tmp = result;
    while (tmp) {
        ++result_size;
        tmp = tmp->next;
    }
    EXPECT_EQ(result_size, 0);

    // Compare the result with the expected output
    while (result && expected) {
        EXPECT_EQ(result->val, expected->val);
        result = result->next;
        expected = expected->next;
    }

    // Clean up memory
    delete expected;
}

TEST(mergeKListsTest, test3) {
    Solution sol;

    vector<ListNode*> lists = {{}};

    ListNode* expected = nullptr;

    // Call the function
    ListNode* result = sol.mergeKLists(lists);

    int result_size = 0;
    ListNode* tmp = result;
    while (tmp) {
        ++result_size;
        tmp = tmp->next;
    }
    EXPECT_EQ(result_size, 0);

    // Compare the result with the expected output
    while (result && expected) {
        EXPECT_EQ(result->val, expected->val);
        result = result->next;
        expected = expected->next;
    }

    // Clean up memory
    delete expected;
}

TEST(mergeKListsTest, test4) {
    Solution sol;

    // Create test input (three sorted linked lists)
    ListNode* list1 = new ListNode(1);

    ListNode* list2 = new ListNode(0);

    vector<ListNode*> lists = {list1, list2};

    // Expected output (sorted merged list)
    ListNode* expected = new ListNode(0);
    expected->next = new ListNode(1);

    // Call the function
    ListNode* result = sol.mergeKLists(lists);

    int result_size = 0;
    ListNode* tmp = result;
    while (tmp) {
        ++result_size;
        tmp = tmp->next;
    }
    EXPECT_EQ(result_size, 2);

    // Compare the result with the expected output
    while (result && expected) {
        EXPECT_EQ(result->val, expected->val);
        result = result->next;
        expected = expected->next;
    }

    // Clean up memory
    delete expected;
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
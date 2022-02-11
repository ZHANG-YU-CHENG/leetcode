#ifndef LINKED_LIST_UTILS_H
#define LINKED_LIST_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* head);
struct ListNode* arr2List(int* arr, int len);
bool compareList(struct ListNode* list1, struct ListNode* list2);

#endif
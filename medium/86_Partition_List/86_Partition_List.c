/**
 * Given the head of a linked list and a value x, 
 * partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * 
 * Example 1:
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * Example 2:
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct ListNode* partition(struct ListNode* head, int x){
    //deal with 1. empty list
    //          2. one node list
    //          3. x is max or min of the list
    if(head==NULL || head->next==NULL || x>=100 || x<=-100) return head;

    //dummy left and right
    //left list for the nodes which are less than x
    //right list for the nodes which are greater than or equal to x
    struct ListNode* dummyLeft = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyLeft->next = NULL;
    dummyLeft->val = 0;
    struct ListNode* leftCur = dummyLeft;
    struct ListNode* dummyRight = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyRight->next = NULL;
    dummyRight->val = 0;
    struct ListNode* rightCur = dummyRight;
    

    struct ListNode* cur = head;
    struct ListNode* popNode = NULL;
    while(cur)
    {
        if(cur->val<x)
        {
            popNode = pop(&cur);
            leftCur->next = popNode;
            leftCur = leftCur->next;
        }
        else
        {
            popNode = pop(&cur);
            rightCur->next = popNode;
            rightCur = rightCur->next;
        }
    }
    //append right list to left list
    leftCur->next = dummyRight->next;
    return dummyLeft->next;
}


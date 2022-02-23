/**
 * Given the head of a linked list, return the list after sorting it in ascending order.
 * 
 * 
 * Example 1:
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * Example 2:
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * Example 3:
 * Input: head = []
 * Output: []
 * 
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 5 * 104].
 * -105 <= Node.val <= 105
 * 
 * 
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct ListNode* findMiddle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//merge two sorted lists
struct ListNode* mergeList(struct ListNode* head, struct ListNode* tail)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    dummy->val = 0;
    struct ListNode* cur = dummy;

    while(head&&tail)
    {
        if(head->val<=tail->val)
        {
            cur->next = pop(&head);
            cur = cur->next;
        }
        else
        {
            cur->next = pop(&tail);
            cur = cur->next;
        }
    }
    if(head) cur->next = head;
    if(tail) cur->next = tail;
    return dummy->next;
}

struct ListNode* mergeSort(struct ListNode* head)
{
    //when the list is empty or only have one node, don't need to divide and conquer the list
    if(head==NULL || head->next==NULL) return head;

    //divide the list
    struct ListNode* middle = findMiddle(head);
    struct ListNode* tail = middle->next;
    middle->next = NULL;
    
    //recursively do mergeSort
    struct ListNode* left = mergeSort(head);
    struct ListNode* right = mergeSort(tail);

    //conquer the list
    struct ListNode* mList = mergeList(left, right);
    return mList;
}

struct ListNode* sortList(struct ListNode* head){
    //deal with empty list or one node list
    if(head==NULL || head->next==NULL) return head;
    return mergeSort(head);
}
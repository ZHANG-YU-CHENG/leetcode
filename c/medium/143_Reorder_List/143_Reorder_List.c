/**
 * You are given the head of a singly linked-list. The list can be represented as:
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * Reorder the list to be on the following form:
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 * 
 * 
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * 
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 * 
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 5 * 104].
 * 1 <= Node.val <= 1000
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
    //if list have even number nodes, middle is slow->next
    //if list have odd number nodes, middle is slow
    return fast ? slow->next : slow;    
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* nxt = head->next;
    while(cur)
    {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        nxt = nxt ? nxt->next : NULL;
    }
    return pre;
}

void reorderList(struct ListNode* head){
    //deal with one node list
    if(head->next==NULL) return;

    //find middle
    struct ListNode* middle = findMiddle(head);

    //cut tail
    struct ListNode* tail = middle->next;
    middle->next = NULL;

    //reverse tail
    struct ListNode* rTail = reverseList(tail);

    //pop rTail and insert to the list before middle node
    struct ListNode* cur = head;
    struct ListNode* nxt = head->next;
    while(rTail)
    {
        cur->next = pop(&rTail);
        cur = cur->next;
        cur->next = nxt;
        cur = cur->next;
        nxt = nxt ? nxt->next : NULL;
    }
    return;
}
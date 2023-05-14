/**
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * Example 3:
 * Input: head = []
 * Output: []
 * 
 * 
 * Constraints:
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 * 
 * Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while(next)
    {
        cur->next = pre; //the next node of cur node change to where pre pointer is
        pre = cur; //pre pointer move to where cur pointer is
        cur = next; //cur pointer move to where next pointer is
        next = next->next; //next pointer move to next node
    }
    cur->next = pre;
    return cur;
}
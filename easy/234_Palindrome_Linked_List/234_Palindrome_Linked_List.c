/**
 * Given the head of a singly linked list, return true if it is a palindrome.
 * 
 * 
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 * 
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 105].
 * 0 <= Node.val <= 9
 * 
 * 
 * Follow up: Could you do it in O(n) time and O(1) space?
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct ListNode* findMiddle(struct ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

bool isPalindrome(struct ListNode* head){
    //deal with one node list
    if(head->next==NULL) return true;

    //find middle
    struct ListNode* middle = findMiddle(head);
    
    //cut list to two list (head, tail)
    struct ListNode* tail = middle->next;
    middle->next = NULL;

    //reverse tail
    struct ListNode* rTail = reverseList(tail);

    //compare two lists
    while(rTail)
    {
        if(head->val != rTail->val) return false;
        head = head->next;
        rTail = rTail->next;
    }
    return true;
}
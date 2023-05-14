/**
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 * 
 * 
 * Constraints:
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 * 
 * 
 * Follow up: Could you do it in one pass?
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    //deal with one node list, or the list that don't need to reverse
    if(head->next==NULL || left==right) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = 0;
    struct ListNode* pre = dummy;
    struct ListNode* cur = head;
    struct ListNode* nxt = head->next;
    struct ListNode* leftleft = NULL; //the node before left
                                      //rightright : the node after right
    int count = 0;

    //the next node of leftleft node is right node ( leftleft -> right )
    //the next node of left node is rightright node ( left -> rightright )
    while(cur)
    {
        ++count;
        if(count<left) 
        {
            //pre, cur, nxt move to next node respectively
            pre = cur;
            cur = nxt;
            if(nxt) nxt = nxt->next;
            continue;
        }
        if(count==left)
        {
            leftleft = pre;
            //pre, cur, nxt move to next node respectively
            pre = cur;
            cur = nxt;
            if(nxt) nxt = nxt->next;
            continue;
        }
        if(count==right)
        {
            leftleft->next->next = cur->next; //( left -> rightright )
            leftleft->next = cur; //( leftleft -> right )
            cur->next = pre; //point to pre
            break;
        }
        cur->next = pre; //point to pre
        //pre, cur, nxt move to next node respectively
        pre = cur;
        cur = nxt;
        if(nxt) nxt = nxt->next;
    }
    return dummy->next;
}
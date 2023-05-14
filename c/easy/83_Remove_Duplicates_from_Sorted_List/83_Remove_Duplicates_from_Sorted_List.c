/**
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
 * Return the linked list sorted as well.
 * 
 * 
 * Example 1:
 * Input: head = [1,1,2]
 * Output: [1,2]
 * 
 * Example 2:
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 * 
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

/*
//v1 low speed
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* current = head;
    struct ListNode* findDiffPtr = head->next;

    while(findDiffPtr)
    {
        //Find the node that is different from the current node
        //then let the next node of the current be this node
        if(findDiffPtr->val!=current->val)
        {
            current->next = findDiffPtr;
            current = current->next;

        }

        if(findDiffPtr->next)
        {
            findDiffPtr = findDiffPtr->next;
        }
        else
        {
            current->next = NULL;
            break;
        }
    }
    return head;
}
*/

//v2
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* current = head;

    while(current->next)
    {
        //If current node val == next node val
        if( current->val == (current->next)->val)
        {
            //the next node of current will be replaced to next next node
            current->next = (current->next)->next;
        }
        else
        {
            //go to the next node
            current = current->next;
        }
    }
    return head;
}
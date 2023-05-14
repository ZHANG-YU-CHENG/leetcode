/**
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. 
 * Return the linked list sorted as well.
 * 
 * 
 * Example 1:
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * Example 2:
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
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

struct ListNode* findUniqueNode(struct ListNode* node)
{
    while(node->next)
    {
        if(node->next->next)
        {
            if(node->val != node->next->val && node->next->val != node->next->next->val)
            {
                return node->next;
            }
        }
        else
        {
            //reached the end of the list, the next next node is NULL

            if(node->val != node->next->val)
            {
                return node->next;
            }
        }
        node = node->next;
    }
    return NULL;
}


struct ListNode* deleteDuplicates(struct ListNode* head){
    //empty list or one node list 
    if(head==NULL || head->next==NULL) return head;

    struct ListNode* current = head;
    struct ListNode* uniqueNode = NULL;
    bool isHeadNeedChange = true;

    //If the first node is unique
    if(head->val != head->next->val)
    {
        isHeadNeedChange = false;
    }

    while(current)
    {
        if(isHeadNeedChange)
        {
            uniqueNode = findUniqueNode(current);
            if(uniqueNode==NULL) return NULL;
            current = uniqueNode;
            head = uniqueNode;
            isHeadNeedChange = false;
            continue;
        }
        uniqueNode = findUniqueNode(current);
        current->next = uniqueNode;
        current = current->next;
    }
    return head;
}
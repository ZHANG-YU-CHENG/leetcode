/**
 * Merge two sorted linked lists and return it as a sorted list. 
 * The list should be made by splicing together the nodes of the first two lists.
 * 
 * 
 * Example 1:
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * Example 2:
 * Input: l1 = [], l2 = []
 * Output: []
 * 
 * Example 3:
 * Input: l1 = [], l2 = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    //if l1 is empty, return l2 as the merged linked list
    if(l1 == NULL) return l2;

    //if l2 is emtpy, return l1 as the merged linked list
    if(l2 == NULL) return l1;


    /** for each l2 node, insert itself in front of the l1 node that is larger than itself **/

    struct ListNode* l2_cur = l2;
    struct ListNode* l1_cur = l1;
    struct ListNode* l1_pre = l1;
    
    while(l2 != NULL)
    {
        while(l1_cur != NULL)
        {
            if(l2_cur->val < l1_cur->val || l2_cur->val == l1_cur->val)
            {
                //the first l2 node is smaller than or equals to the head of l1 list
                //let the first l2 node be the head of the l1 list
                if(l1_cur == l1_pre)
                {
                    l2 = l2->next;
                    l2_cur->next = l1;
                    l1 = l2_cur;
                    l1_pre = l1;
                    l2_cur = l2;
                    break;
                }
                //when this l2 node find the l1 node which is larger than itself,
                //insert itself in front of the l1 node
                l2 = l2->next;
                l1_pre->next = l2_cur;
                l2_cur->next = l1_cur;
                l2_cur = l2;
                l1_pre = l1_pre->next;
                break;
            }
            //l2 node can NOT find the l1 node which is larger than itself, means the rest of the l2 nodes are all larger than l1 nodes 
            //append the rest of the l2 to the tail of l1
            if(l1_cur->next == NULL)
            {
                l1_cur->next = l2;
                l2 = NULL;
                break;
            }
            //when this l2 node is larger than this l1 node, go find and compare the next l1 node
            l1_pre = l1_cur;
            l1_cur = l1_cur->next;
        }
    }
    return l1;
}

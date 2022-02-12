extern "C" {
#include "linked_list_utils.h"
}

//for debug
void printList(struct ListNode* head)
{
    while(head)
    {
        printf("[%p, %d, %p]", head, head->val, head->next);
        head = head->next;
    }
    puts("");
}

struct ListNode* arr2List(int* arr, int len)
{
    if(len==0) return NULL;
    struct ListNode* out = (struct ListNode*) malloc(sizeof(struct ListNode)*len);   
    for(int i=0; i<len; ++i)
    {
        //foo->bar = (*foo).bar
        (out[i]).val = arr[i];
        (out[i]).next = (i==len-1) ? NULL : &(out[i+1]); 
    }
    return out;
}

bool compareList(struct ListNode* list1, struct ListNode* list2)
{
    while(list1 && list2)
    {
        if(list1->val != list2->val) return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    //If list1 or list2 still have node, mean list1 and list2 have different length
    if(list1 || list2) return false;
    return true;
}
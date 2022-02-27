/**
 * A linked list of length n is given such that each node contains an additional random pointer, 
 * which could point to any node in the list, or null.
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
 * where each new node has its value set to the value of its corresponding original node. 
 * Both the next and random pointer of the new nodes should point to new nodes in the copied list 
 * such that the pointers in the original list and copied list represent the same list state. 
 * None of the pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
 * then for the corresponding two nodes x and y in the copied list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * The linked list is represented in the input/output as a list of n nodes. 
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
 * or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
 * 
 * 
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Constraints:
 * 0 <= n <= 1000
 * -104 <= Node.val <= 104
 * Node.random is null or is pointing to some node in the linked list.
 * 
 */

extern "C" {
#include "linked_list_utils.h"
}

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

int getListLength(struct Node* head)
{
    //deal with one node list
    if(head->next==NULL) return 1;

    struct Node* cur = head;
    int count = 0;
    while(cur)
    {
        ++count;
        cur = cur->next;
    }
    return count;
}

int* getValArr(struct Node* head, int len)
{
    struct Node* cur = head;
    int* valArr = (int*)malloc(sizeof(int)*len);
    for(int i=0; i<len; ++i)
    {
        valArr[i] = cur->val;
        cur = cur->next;
    }
    return valArr;
}

int* getMappingTable(struct Node* head, int len)
{
    //store every address of Node in array "table1"
    struct Node* table1[len];
    //store every random address of Node in array "table2"
    struct Node* table2[len];
    struct Node* cur = head;
    int count = 0;
    while(cur)
    {
        table1[count] = cur;
        table2[count] = cur->random;
        ++count;
        cur = cur->next;
    }

    //store random address id in array "table3"
    int* table3 = (int*)malloc(sizeof(int)*len);
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<len; ++j)
        {
            if(table2[i]==NULL)
            {
                table3[i] = -1;
                break;
            }
            if(table2[i]==table1[j])
            {
                table3[i] = j;
                break;
            }
        }
    }
    return table3;
}

// struct Node* createRandomList(int* valArr, int* randomArr, int len)
// {
//     struct Node* head1 = (struct Node*)malloc(sizeof(struct Node)*len); //CAN NOT PASS LEETCODE COMPILER
//     for(int i=0; i<len; ++i)
//     {
//         (head1[i]).val = valArr[i];
//         (head1[i]).next = (i==len-1) ? NULL : &(head1[i+1]);
//         (head1[i]).random = (randomArr[i]==-1) ? NULL : &(head1[randomArr[i]]);
//     }
//     return head1;
// }

struct Node* createRandomList(int* valArr, int* randomArr, int len)
{
    struct Node* head1[len];
    
    for(int i=0; i<len; ++i)
    {
        struct Node* head1_tmp = (struct Node*)malloc(sizeof(struct Node));
        head1[i] = head1_tmp;
    }
    for(int i=0; i<len; ++i)
    {
        (head1[i])->val = valArr[i];
        (head1[i])->next = (i==len-1) ? NULL : head1[i+1];
        (head1[i])->random = (randomArr[i]==-1) ? NULL : head1[randomArr[i]];
    }
    return head1[0];
}

struct Node* copyRandomList(struct Node* head) {
    //TO DO : should try hashmap

    //deal with empty list
    if(head==NULL) return NULL;

    //get list length
    int len = getListLength(head);

    //get val array
    int* valArr = getValArr(head, len);

    //get mapping table "randomArr"
    int* randomArr = getMappingTable(head, len);

    //create another RandomList
    struct Node* head1 = createRandomList(valArr, randomArr, len);

    if(valArr) free(valArr);
    valArr = NULL;
    if(randomArr) free(randomArr);
    randomArr = NULL;

    return head1;
}
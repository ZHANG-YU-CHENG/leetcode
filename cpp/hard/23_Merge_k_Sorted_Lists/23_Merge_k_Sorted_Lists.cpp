/**
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 *  
 * 
 * Example 1:
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * 
 * Example 2:
 * Input: lists = []
 * Output: []
 * 
 * Example 3:
 * Input: lists = [[]]
 * Output: []
 *  
 * 
 * Constraints:
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//////////////// analysis ////////////////
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         // lists:
//         // 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//         // 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> null
//         // [removed] 0xd0[2] -> 0xd1[6] -> null  //removed test data
//         // [add]     0xe0[0] -> 0xe1[3] -> null  //additional test data for case that insert the node in the head of the mList

//         ListNode* dummy = new ListNode();
//         ///(1)/// dummy = 0xa0[0] -> null

//         for(ListNode* list : lists){
//             ///(2)/// list = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//             ///(22)/// list = 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> null
//             ///(51)/// list = 0xe0[0] -> 0xe1[3] -> null

//             ListNode* listCur = list;
//             ///(3)/// listCur = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//             ///(23)/// listCur = 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> null
//             ///(52)/// listCur = 0xe0[0] -> 0xe1[3] -> null

//             while(listCur){
//                 ///(4)/// listCur = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                 ///(8)/// listCur = 0xb1[4] -> 0xb2[5] -> null
//                 ///(14)/// listCur = 0xb2[5] -> null
//                 ///(24)/// listCur = 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> null
//                 ///(31)/// listCur = 0xc1[3] -> 0xc2[4] -> null
//                 ///(40)/// listCur = 0xc2[4] -> null
//                 ///(53)/// listCur = 0xe0[0] -> 0xe1[3] -> null

//                 //insert the node (listCur) into mList directly if mList is empty
//                 if(dummy->next==nullptr){
//                     dummy->next = listCur;
//                     ///(5)/// dummy = 0xa0[0] -> 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null

//                     listCur = listCur->next;
//                     ///(6)/// listCur = 0xb1[4] -> 0xb2[5] -> null

//                     dummy->next->next = nullptr;
//                     ///(7)/// dummy = 0xa0[0] -> 0xb0[1] -> null

//                     continue;
//                 }

//                 ListNode* mListCur = dummy->next;
//                 ///(9)/// mListCur = 0xb0[1] -> null
//                 ///(15)/// mListCur = 0xb0[1] -> 0xb1[4] -> null
//                 ///(25)/// mListCur = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                 ///(32)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                 ///(41)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                 ///(54)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> 0xb1[4] -> 0xb2[5] -> null

//                 while(mListCur){
//                     ///(10)/// mListCur = 0xb0[1] -> null
//                     ///(16)/// mListCur = 0xb0[1] -> 0xb1[4] -> null
//                     ///(18)/// mListCur = 0xb1[4] -> null
//                     ///(26)/// mListCur = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(33)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(35)/// mListCur = 0xc0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(42)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(44)/// mListCur = 0xc0[1] -> 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(46)/// mListCur = 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(55)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> 0xb1[4] -> 0xb2[5] -> null

//                     //insert the node (listCur) at the head of the mList
//                     if(listCur->val < mListCur->val){
//                         dummy->next = listCur;
//                         ///(56)/// dummy = 0xa0[0] -> 0xe0[0] -> 0xe1[3] -> null

//                         listCur = listCur->next;
//                         ///(57)/// listCur = 0xe1[3] -> null

//                         dummy->next->next = mListCur;
//                         ///(56)/// dummy = 0xa0[0] -> 0xe0[0] -> 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> 0xb1[4] -> 0xb2[5] -> null
//                         break;
//                     }

//                     //find the postion in the mList that can insert the node (listCur)
//                     if((mListCur->val < listCur->val || mListCur->val == listCur->val) 
//                         && mListCur->next && (listCur->val < mListCur->next->val || listCur->val == mListCur->next->val)){
//                         ListNode* tmp = mListCur->next;
//                         ///(27)/// tmp = 0xb1[4] -> 0xb2[5] -> null
//                         ///(36)/// tmp = 0xb1[4] -> 0xb2[5] -> null
//                         ///(47)/// tmp = 0xb1[4] -> 0xb2[5] -> null

//                         mListCur->next = listCur;
//                         ///(28)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> null
//                         ///(37)/// mListCur = 0xc0[1] -> 0xc1[3] -> 0xc2[4] -> 
//                         ///(48)/// mListCur = 0xc1[3] -> 0xc2[4] -> null

//                         listCur = listCur->next;
//                         ///(29)/// listCur = 0xc1[3] -> 0xc2[4] -> null
//                         ///(38)/// listCur = 0xc2[4] -> null
//                         ///(49)/// listCur = null

//                         mListCur->next->next = tmp;
//                         ///(30)/// mListCur = 0xb0[1] -> 0xc0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                         ///(39)/// mListCur = 0xc0[1] -> 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                         ///(50)/// mListCur = 0xc1[3] -> 0xc2[4] -> null

//                         break;
//                     }

//                     //reach the end of the mlist
//                     if((mListCur->val < listCur->val || mListCur->val == listCur->val) 
//                         && mListCur->next == nullptr){
//                         mListCur->next = listCur;
//                         ///(11)/// mListCur = 0xb0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                         ///(19)/// mListCur = 0xb1[4] -> 0xb2[5] -> null

//                         listCur = listCur->next;
//                         ///(12)/// listCur = 0xb2[5] -> null
//                         ///(20)/// listCur = null

//                         mListCur->next->next = nullptr;
//                         ///(13)/// mListCur = 0xb0[1] -> 0xb1[4] -> null
//                         ///(21)/// mListCur = 0xb1[4] -> 0xb2[5] -> null

//                         break;
//                     }

//                     //do not find the position in the mList that can insert the node (listCur) yet, and do not reach the end of the mlist yet
//                     mListCur = mListCur->next;
//                     ///(17)/// mListCur = 0xb1[4] -> null
//                     ///(34)/// mListCur = 0xc0[1] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(43)/// mListCur = 0xc0[1] -> 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                     ///(45)/// mListCur = 0xc1[3] -> 0xb1[4] -> 0xb2[5] -> null
//                 }
//             }
//         }
//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        for(ListNode* list : lists){
            ListNode* listCur = list;
            while(listCur){
                //insert the node (listCur) into mList directly if mList is empty
                if(dummy->next==nullptr){
                    dummy->next = listCur;
                    listCur = listCur->next;
                    dummy->next->next = nullptr;
                    continue;
                }
                ListNode* mListCur = dummy->next;
                while(mListCur){
                    //insert the node (listCur) at the head of the mList
                    if(listCur->val < mListCur->val){
                        dummy->next = listCur;
                        listCur = listCur->next;
                        dummy->next->next = mListCur;
                        break;
                    }
                    //find the postion in the mList that can insert the node (listCur)
                    if((mListCur->val < listCur->val || mListCur->val == listCur->val) 
                        && mListCur->next && (listCur->val < mListCur->next->val || listCur->val == mListCur->next->val)){
                        ListNode* tmp = mListCur->next;
                        mListCur->next = listCur;
                        listCur = listCur->next;
                        mListCur->next->next = tmp;
                        break;
                    }
                    //reach the end of the mlist
                    if((mListCur->val < listCur->val || mListCur->val == listCur->val) 
                        && mListCur->next == nullptr){
                        mListCur->next = listCur;
                        listCur = listCur->next;
                        mListCur->next->next = nullptr;
                        break;
                    }
                    //do not find the position in the mList that can insert the node (listCur) yet, and do not reach the end of the mlist yet
                    mListCur = mListCur->next;
                }
            }
        }
        return dummy->next;
    }
};
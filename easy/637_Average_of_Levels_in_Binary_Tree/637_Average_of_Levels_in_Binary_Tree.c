/**
 * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
 * Answers within 10-5 of the actual answer will be accepted.
 * 
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [3.00000,14.50000,11.00000]
 * Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
 * Hence return [3, 14.5, 11].
 * 
 * Example 2:
 * Input: root = [3,9,20,15,7]
 * Output: [3.00000,14.50000,11.00000]
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>


 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ==================queue utils=================== 
struct queueNode{
    struct TreeNode* val;
    struct queueNode* pre;
    struct queueNode* next;
};

typedef struct{
    struct queueNode* head;
    struct queueNode* tail;
}Queue;

Queue* createQueue(void){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

bool queueIsEmpty(Queue* q){
    return (q==NULL || q->head==NULL);
}

void queuePush(Queue* q, struct TreeNode* val){
    struct queueNode* newQueueNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newQueueNode->val = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newQueueNode->val = val;
    if(queueIsEmpty(q))
    {
        newQueueNode->next = NULL;
        newQueueNode->pre = NULL;
        q->head = newQueueNode;
        q->tail = newQueueNode;
    }
    else
    {
        newQueueNode->next = q->head;
        newQueueNode->pre = NULL;
        q->head->pre = newQueueNode;
        q->head = newQueueNode;        
    }
}

struct TreeNode* queueTail(Queue* q){
    if(q==NULL || q->tail==NULL)
    {
        // queue is empty
        return NULL;
    }
    return q->tail->val; 
}

void queuePop(Queue* q){
    if(q==NULL || q->tail==NULL)
    {
        // queue is empty
        return;
    }
    struct queueNode* tmp = q->tail;
    if(q->tail->pre==NULL) //last node
    {
        q->head = NULL;
        q->tail = NULL;
    }
    else
    {
        q->tail = q->tail->pre;
        q->tail->next = NULL;
    }
    if(tmp) free(tmp);
    tmp = NULL;
}

void freeQueue(Queue* q){
    while(!queueIsEmpty(q))
        queuePop(q);
    free(q);
    q = NULL;
}

// ================================================ 

int getBinaryTreeDepth(struct TreeNode* root)
{
    if(!root)
        return 0;
    int leftSum = getBinaryTreeDepth(root->left);
    int rightSum = getBinaryTreeDepth(root->right);
    int sum = (leftSum > rightSum) ? leftSum : rightSum;
    return sum+1;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int depth = getBinaryTreeDepth(root);
    *returnSize = depth;
    double* out = (double*)malloc(sizeof(double)*depth);
    int depth_count = 0;
    struct TreeNode* tmp;
    int queue_count_cur = 1;
    int queue_count = queue_count_cur;
    int queue_count_next = 0;
    double level_sum = 0;
    Queue* q = createQueue();
    queuePush(q, root);
    while(!queueIsEmpty(q))
    {
        tmp = queueTail(q);
        queuePop(q);
        level_sum += tmp->val;
        if(tmp->left)
        {
            queuePush(q, tmp->left);
            ++queue_count_next;
        }
        if(tmp->right)
        {
            queuePush(q, tmp->right);
            ++queue_count_next;
        }
        --queue_count;
        if(queue_count==0)
        {
            out[depth_count] = level_sum/(double)queue_count_cur;
            level_sum = 0;
            ++depth_count;
            queue_count_cur = queue_count_next;
            queue_count = queue_count_cur;
            queue_count_next = 0;
        }
    }
    return out;
}





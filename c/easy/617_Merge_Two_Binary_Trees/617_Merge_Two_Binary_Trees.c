/**
 * You are given two binary trees root1 and root2.
 * 
 * Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
 * You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, 
 * then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
 * 
 * Return the merged tree.
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 
 * 
 * Example 1:
 * Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * Output: [3,4,5,5,4,null,7]
 * 
 * Example 2:
 * Input: root1 = [1], root2 = [1,2]
 * Output: [2,2]
 * 
 * 
 * Constraints:
 * The number of nodes in both trees is in the range [0, 2000].
 * -10^4 <= Node.val <= 10^4
 * 
 */

#include <stdio.h>
#include <stdlib.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/*
// recursive solution
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
*/

/*
// ==================stack utils=================== 
struct mTreeNode{
    struct TreeNode* val1;
    struct TreeNode* val2;
};

typedef struct stackNode{
    struct mTreeNode* val;
    struct stackNode* next;
}StackNode;

typedef struct{
    StackNode* top;
}Stack;

Stack* createStack(void){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool stackIsEmpty(Stack* s){
    return (s==NULL || s->top==NULL);
}

void stackPush(Stack* s, struct TreeNode* val1, struct TreeNode* val2){
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->val = (struct mTreeNode*)malloc(sizeof(struct mTreeNode));
    newStackNode->val->val1 = val1;
    newStackNode->val->val2 = val2;
    newStackNode->next = s->top;
    s->top = newStackNode;
}

struct mTreeNode* stackTop(Stack* s){
    if(s==NULL || s->top==NULL)
    {
        // puts("stack is empty");
        return NULL;
    }
    return s->top->val; 
}

void stackPop(Stack* s){
    if(s==NULL || s->top==NULL)
    {
        // puts("stack is empty");
        return;
    }
    StackNode* tmp = s->top;
    s->top = s->top->next;
    if(tmp) free(tmp);
    tmp = NULL;
}

void freeStack(Stack* s){
    while(!stackIsEmpty(s))
        stackPop(s);
    free(s);
    s = NULL;
}
// ================================================

// stack solution
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    Stack* s = createStack();
    stackPush(s, root1, root2);
    struct mTreeNode* tmp;
    while(!stackIsEmpty(s))
    {
        tmp = stackTop(s);
        stackPop(s);

        if(tmp->val1 && tmp->val2)
        {
            tmp->val1->val += tmp->val2->val;

            if(tmp->val1->left && tmp->val2->left)
                stackPush(s, tmp->val1->left, tmp->val2->left);
            else if(!tmp->val1->left && tmp->val2->left)
                tmp->val1->left = tmp->val2->left;

            if(tmp->val1->right && tmp->val2->right)
                stackPush(s, tmp->val1->right, tmp->val2->right);
            else if(!tmp->val1->right && tmp->val2->right)
                tmp->val1->right = tmp->val2->right;
        }
    }
    return root1;
}
*/

// ==================queue utils=================== 
struct mTreeNode{
    struct TreeNode* val1;
    struct TreeNode* val2;
};

struct queueNode{
    struct mTreeNode* val;
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

void queuePush(Queue* q, struct TreeNode* val1, struct TreeNode* val2){
    struct queueNode* newQueueNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newQueueNode->val = (struct mTreeNode*)malloc(sizeof(struct mTreeNode));
    newQueueNode->val->val1 = val1;
    newQueueNode->val->val2 = val2;
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

struct mTreeNode* queueTail(Queue* q){
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

// queue solution
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    Queue* q = createQueue();
    queuePush(q, root1, root2);
    struct mTreeNode* tmp;
    while(!queueIsEmpty(q))
    {
        tmp = queueTail(q);
        queuePop(q);

        if(tmp->val1 && tmp->val2)
        {
            tmp->val1->val += tmp->val2->val;

            if(tmp->val1->left && tmp->val2->left)
                queuePush(q, tmp->val1->left, tmp->val2->left);
            else if(!tmp->val1->left && tmp->val2->left)
                tmp->val1->left = tmp->val2->left;

            if(tmp->val1->right && tmp->val2->right)
                queuePush(q, tmp->val1->right, tmp->val2->right);
            else if(!tmp->val1->right && tmp->val2->right)
                tmp->val1->right = tmp->val2->right;
        }
    }
    return root1;
}
/**
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 * 
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 * 
 * Example 2:
 * Input: root = []
 * Output: []
 * 
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 * 
 * Example 4:
 * Input: root = [1,2]
 * Output: [2,1]
 * 
 * Example 5:
 * Input: root = [1,null,2]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct queueNode{
    int val;
    struct queueNode* next;
}QueueNode;

typedef struct queueList{
    QueueNode* front;
    QueueNode* back;
    int size;
}QueueList;

QueueList* createQueue(void){
    QueueList* queue = (QueueList*)malloc(sizeof(QueueList));
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
    return queue;
}

int getQueueSize(QueueList* queue){
    return queue->size;
}

bool isQueueEmpty(QueueList* queue){
    return (queue->size==0);
}

int getQueueFront(QueueList* queue){
    if(isQueueEmpty(queue))
    {
        // puts("queue is empty");
        return -101;
    } 
    return queue->front->val;
}

int getQueueBack(QueueList* queue){
    if(isQueueEmpty(queue))
    {
        // puts("queue is empty");
        return -101;
    } 
    return queue->back->val;
}

void queuePush(QueueList* queue, int val){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->val = val;
    newNode->next = NULL;
    if(isQueueEmpty(queue))
        queue->front = newNode;
    else
        queue->back->next = newNode;
    
    queue->back = newNode;
    queue->size ++;       
}

void queuePop(QueueList* queue){
    if(isQueueEmpty(queue))
    {
        // puts("queue is empty");
        return;
    }
    QueueNode* tmp = queue->front;
    queue->front = queue->front->next;
    queue->size --;
    free(tmp);
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* queue2arr(QueueList* queue){
    if(isQueueEmpty(queue)) return NULL;
    int arrSize = getQueueSize(queue);
    int* arr = (int*)malloc(sizeof(int)*arrSize);
    memset(arr, 0, arrSize);
    int i = 0;
    while(!isQueueEmpty(queue))
    {
        arr[i] = getQueueFront(queue);
        ++i;
        queuePop(queue);
    }
    return arr;
}

/* v1 - recursive */

// void inorderTraversal_r(struct TreeNode* root, QueueList* queue){
//     if(root==NULL) return;
//     inorderTraversal_r(root->left, queue);
//     queuePush(queue, root->val);
//     inorderTraversal_r(root->right, queue);
// }

// int* inorderTraversal(struct TreeNode* root, int* returnSize){
//     if(root==NULL)
//     {
//         *returnSize = 0;
//         return NULL;
//     }
//     QueueList* queue = createQueue();
//     inorderTraversal_r(root, queue);

//     *returnSize = getQueueSize(queue);
//     int* arr = queue2arr(queue);

//     return arr;
// }


/* v2 - stack */

typedef struct stackNode{
    struct TreeNode* val;
    stackNode* next;
}StackNode;

typedef struct stackList{
    stackNode* top;
}StackList;

StackList* createStack(void){
    StackList* stack = (StackList*)malloc(sizeof(StackList));
    stack->top = NULL;
    return stack;
}

bool isStackEmpty(StackList* stack){
    return (stack->top==NULL);
}

struct TreeNode* getStackTop(StackList* stack){
    if(isStackEmpty(stack))
    {
        // puts("stack is empty");
        return NULL;
    }
    return stack->top->val;
}

void stackPush(StackList* stack, struct TreeNode* val){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->val = val;
    
    if(isStackEmpty(stack))
        newNode->next = NULL;
    else
        newNode->next = stack->top;
    stack->top = newNode;
}

void stackPop(StackList* stack){
    if(isStackEmpty(stack))
    {
        // puts("stack is empty");
        return;
    }
    StackNode* tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    QueueList* queue = createQueue();
    StackList* stack = createStack();
    struct TreeNode* cur = root;
    while(cur || !isStackEmpty(stack))
    {
        if(cur)
        {
            stackPush(stack, cur);
            cur = cur->left;
        }
        else
        {
            cur = getStackTop(stack);
            if(cur==NULL) break;
            stackPop(stack);
            queuePush(queue, cur->val);
            cur = cur->right;
        }
    }

    *returnSize = getQueueSize(queue);
    int* arr = queue2arr(queue);

    return arr;
}
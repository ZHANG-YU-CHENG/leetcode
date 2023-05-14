/**
 * Implement a first in first out (FIFO) queue using only two stacks. 
 * The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 * Implement the MyQueue class:
 *  void push(int x) Pushes element x to the back of the queue.
 *  int pop() Removes the element from the front of the queue and returns it.
 *  int peek() Returns the element at the front of the queue.
 *  boolean empty() Returns true if the queue is empty, false otherwise.
 * 
 * Notes:
 * You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, the stack may not be supported natively. 
 * You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 * 
 * 
 * Example 1:
 * Input
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 1, 1, false]
 * Explanation
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 * 
 * 
 * Constraints:
 * 1 <= x <= 9
 * At most 100 calls will be made to push, pop, peek, and empty.
 * All the calls to pop and peek are valid.
 * 
 * 
 * Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? 
 * In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
    int val;
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

void stackPush(Stack* s, int val){
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->val = val;
    newStackNode->next = s->top;
    s->top = newStackNode;
}

int stackTop(Stack* s){
    if(s==NULL || s->top==NULL)
    {
        // puts("stack is empty");
        return -1;
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

typedef struct {
    Stack* s1;
    Stack* s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    Stack* s1 = createStack();
    Stack* s2 = createStack();
    q->s1 = s1;
    q->s2 = s2;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    //s1 -> s2
    while(!stackIsEmpty(obj->s1))
    {
        stackPush(obj->s2, stackTop(obj->s1));
        stackPop(obj->s1);
    }
    int peek = stackTop(obj->s2);
    stackPop(obj->s2);
    //s2 -> s1
    while(!stackIsEmpty(obj->s2))
    {
        stackPush(obj->s1, stackTop(obj->s2));
        stackPop(obj->s2);
    }
    return peek;
}

int myQueuePeek(MyQueue* obj) {
    //s1 -> s2
    while(!stackIsEmpty(obj->s1))
    {
        stackPush(obj->s2, stackTop(obj->s1));
        stackPop(obj->s1);
    }
    int peek = stackTop(obj->s2);
    //s2 -> s1
    while(!stackIsEmpty(obj->s2))
    {
        stackPush(obj->s1, stackTop(obj->s2));
        stackPop(obj->s2);
    }
    return peek;
}

bool myQueueEmpty(MyQueue* obj) {
    return stackIsEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    freeStack(obj->s1);
    freeStack(obj->s2);
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
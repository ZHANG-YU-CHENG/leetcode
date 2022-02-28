/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Implement the MinStack class:
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * 
 * 
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 * 
 * 
 * Constraints:
 * -231 <= val <= 231 - 1
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 * At most 3 * 104 calls will be made to push, pop, top, and getMin.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stackNode{
    long long int val;
    long long int lastMin; //If pop cur node, then the min of the stack will be set to this value
    struct stackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* minstack = (MinStack*)malloc(sizeof(MinStack));
    StackNode* dummy = (StackNode*)malloc(sizeof(StackNode));
    dummy->val = LONG_MAX;
    dummy->lastMin = LONG_MAX;
    dummy->next = NULL;
    minstack->top = dummy;
    return minstack;
}

void minStackPush(MinStack* obj, int val) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->val = (long long int)val;
    newNode->lastMin = (obj->top->val < obj->top->lastMin) ? obj->top->val : obj->top->lastMin;
    newNode->next = obj->top;
    obj->top = newNode; //the top pointer of stack "obj" move to where the newNode is
}

void minStackPop(MinStack* obj) {
    if(obj->top==NULL) return;
    StackNode* oriTop = obj->top; //save original top node for free memory
    obj->top = obj->top->next;

    //free original top node
    if(oriTop) free(oriTop);
    oriTop = NULL;
}

int minStackTop(MinStack* obj) {
    return (int)obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->top->val < obj->top->lastMin ? (int)obj->top->val : (int)obj->top->lastMin;
}

void minStackFree(MinStack* obj) {
    while(obj->top)
    {
        minStackPop(obj);
    }
    if(obj) free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
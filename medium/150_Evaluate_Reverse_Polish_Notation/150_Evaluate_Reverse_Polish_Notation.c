/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 * Note that division between two integers should truncate toward zero.
 * It is guaranteed that the given RPN expression is always valid. 
 * That means the expression would always evaluate to a result, and there will not be any division by zero operation.
 * 
 * 
 * Example 1:
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * Example 2:
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * Example 3:
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 * Constraints:
 * 1 <= tokens.length <= 104
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>

typedef struct stackNode{
    char* val;
    struct stackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} RPNStack;

RPNStack* RPNStackCreate() {
    RPNStack* stack = (RPNStack*)malloc(sizeof(RPNStack));
    StackNode* dummy = (StackNode*)malloc(sizeof(StackNode));
    dummy->val = (char*)"null";
    dummy->next = NULL;
    stack->top = dummy;
    return stack;
}

void RPNStackPush(RPNStack* obj, char* val) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->val = val;
    newNode->next = obj->top;
    obj->top = newNode; //the top pointer of stack "obj" move to where the newNode is
}

void RPNStackPop(RPNStack* obj) {
    if(obj->top==NULL) return;
    StackNode* oriTop = obj->top; //save original top node for free memory
    obj->top = obj->top->next;

    //free original top node
    if(oriTop) free(oriTop);
    oriTop = NULL;
}

char* RPNStackTop(RPNStack* obj) {
    return obj->top->val;
}

bool isOperand(char* token)
{
    return (!strcmp(token, "+")||!strcmp(token, "-")||!strcmp(token, "*")||!strcmp(token, "/"));
}

char* calculate(char* x1, char* x2, char* operand)
{
    int ix1 = atoi(x1);
    int ix2 = atoi(x2);
    char* out = (char*)malloc(sizeof(char)*20);
    if(!strcmp(operand, "+"))
    {
        sprintf(out, "%d", ix1 + ix2);
        return out;
    }
    else if(!strcmp(operand, "-"))
    {
        sprintf(out, "%d", ix1 - ix2);
        return out;
    }
    else if(!strcmp(operand, "*"))
    {
        sprintf(out, "%d", ix1 * ix2);
        return out;
    }
    else if(!strcmp(operand, "/"))
    {
        sprintf(out, "%d", (int)(ix1 / ix2));
        return out;
    }
    else return (char*)"error";
}

int evalRPN(char ** tokens, int tokensSize){
    RPNStack* stack = RPNStackCreate();
    char* x1 = NULL;
    char* x2 = NULL;
    char* tmp = NULL;
    for(int i=0; i<tokensSize; ++i)
    {
        if(isOperand(tokens[i]))
        {
            //pop two numbers and do operation
            x2 = RPNStackTop(stack);
            RPNStackPop(stack);
            x1 = RPNStackTop(stack);
            RPNStackPop(stack);
            tmp = calculate(x1, x2, tokens[i]);
            RPNStackPush(stack, tmp);
        }
        else
        {
            RPNStackPush(stack, tokens[i]);
        }
    }
    return atoi(stack->top->val);
}
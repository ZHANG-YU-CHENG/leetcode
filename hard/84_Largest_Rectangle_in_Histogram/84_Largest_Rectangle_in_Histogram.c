/**
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
 * return the area of the largest rectangle in the histogram.
 * 
 * 
 * Example 1:
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * 
 * Example 2:
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 * Constraints:
 * 1 <= heights.length <= 105
 * 0 <= heights[i] <= 104
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

/*******************************************************
(0) question:

{2,1,5,6,2,3}

      *
    * *
    * *
    * *   *
*   * * * *
* * * * * *


(1) divide into three subgroups with local maximum

        *
      * *
      * *
      * *     *
*     * *   * *
* | * * * | * *


(2) calculate all possible rectangles in each subgroup

           *
     * *   *
     * *   *
     * *   *                              *
*    * *   *                    * * * *   *
* |  * * , *  | * * * * * * * , * * * * , *

*******************************************************/


int largestRectangleArea(int* heights, int heightsSize){
    Stack* s = createStack();
    int maxArea = 0;
    int tmpMaxArea = 0;
    int i = 0;
    int h = 0;
    int w = 0;
    while(i<heightsSize)
    {
        if(stackIsEmpty(s) || heights[i] >= heights[stackTop(s)])
        {
            stackPush(s, i);
            // printf("add i=%d into stack, i %d -> %d\n", i, i, i+1);
            ++i;
        }
        else
        {
            h = heights[stackTop(s)]; stackPop(s);
            w = stackIsEmpty(s) ? i : i - stackTop(s) - 1;
            tmpMaxArea = h*w;
            maxArea = maxArea > tmpMaxArea ? maxArea : tmpMaxArea;
            // printf("h=%d, w=%d, maxArea=%d\n", h, w, maxArea);
        }
    }

    i = heightsSize;
    while(!stackIsEmpty(s))
    {
        h = heights[stackTop(s)]; stackPop(s);
        w = stackIsEmpty(s) ? i : i - stackTop(s) - 1;
        tmpMaxArea = h*w;
        maxArea = maxArea > tmpMaxArea ? maxArea : tmpMaxArea;
        // printf("h=%d, w=%d, maxArea=%d\n", h, w, maxArea);
    }
    return maxArea;
}
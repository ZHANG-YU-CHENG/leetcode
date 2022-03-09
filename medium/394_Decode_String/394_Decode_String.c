/**
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
 * Note that k is guaranteed to be a positive integer.
 * You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
 * For example, there will not be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * 
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * 
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef struct stackNode{
    char* val;
    struct stackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

Stack* StackCreate() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    StackNode* dummy = (StackNode*)malloc(sizeof(StackNode));
    dummy->val = (char*)"null";
    dummy->next = NULL;
    stack->top = dummy;
    return stack;
}

void StackPush(Stack* stack, char* val) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->val = val;
    newNode->next = stack->top;

    //the top pointer of stack "stack" move to where the newNode is
    stack->top = newNode; 
}

void StackPop(Stack* stack) {
    if(stack==NULL || stack->top==NULL) return;

    //save original top node for free memory
    StackNode* oriTop = stack->top;
    stack->top = stack->top->next;

    //free original top node
    if(oriTop) free(oriTop);
    oriTop = NULL;
}

char* StackTop(Stack* stack) {
    if(stack==NULL || stack->top==NULL) return NULL;
    return stack->top->val;
}

//for debug
void printStack(Stack* stack)
{
    if(StackTop(stack)==NULL)
    {
        puts("stack is empty");
        return;
    }
    printf("stack : ");
    StackNode* cur = stack->top;
    while(cur)
    {
        printf("%s, ",cur->val);
        cur = cur->next;
    }
    puts("");
}

bool isDigitStr(char* tmp)
{
    if(!strcmp(tmp, "0")||!strcmp(tmp, "1")||!strcmp(tmp, "2")||!strcmp(tmp, "3")||!strcmp(tmp, "4")||!strcmp(tmp, "5")
        ||!strcmp(tmp, "6")||!strcmp(tmp, "7")||!strcmp(tmp, "8")||!strcmp(tmp, "9"))
        return true;  
    else
        return false;
}

typedef enum{
    TokenTypeLetter,
    TokenTypeDigit
}TokenType;

//get letters or digits
char* getTokens(Stack* stack, TokenType type)
{
    char* tmp;
    int sum_size = 1 + 10; //add 10 more memory to pass leetcode, TO DO: calculate the correct size
    Stack* tmpStack = StackCreate();

    while(StackTop(stack))
    {
        tmp = StackTop(stack);

        //To get letters, means need to get all tokens between "[" and "]"
        //or means need to get all tokens before the bottom of the stack (null)
        if(type==TokenTypeLetter && (!strcmp(tmp, "[")||!strcmp(tmp, "null")))
        {
            //Do not need "[" or "null", so pop them from stack
            StackPop(stack); 
            break;
        }
        //To get digits, means need to get all tokens between "[" and the first non-digit token
        if(type==TokenTypeDigit && !isDigitStr(tmp))
            break;

        StackPop(stack);
        StackPush(tmpStack, tmp);
        sum_size += strlen(tmp);
    }

    char* sum = (char*)malloc(sizeof(char)*sum_size);
    memset(sum, '\0', sizeof(sum));

    //concat all tokens in tmpStack into a string
    while(StackTop(tmpStack))
    {
        tmp = StackTop(tmpStack);
        StackPop(tmpStack);
        if(!strcmp(tmp, "null")) 
            break;
        strcat(sum, tmp);
    }
    return sum; 
}

char* decodeString(char* s){
    Stack* stack = StackCreate();
    char* letters = NULL;
    int letters_len = 0;
    char* digits_str = NULL;
    int digits = 0;
    int combination_size = 0;
    for(int i=0; i<strlen(s); ++i)
    {
        switch(s[i])
        {
            case ']':
            {
                letters = getTokens(stack, TokenTypeLetter);
                letters_len = strlen(letters);
                digits_str = getTokens(stack, TokenTypeDigit);
                digits = atoi(digits_str);
                combination_size = digits*letters_len+1+10; //add 10 more memory to pass leetcode, TO DO: calculate the correct size
                char* combination = (char*)malloc(sizeof(char)*combination_size);
                memset(combination, '\0', sizeof(combination));
                for(int i=0; i<digits; ++i)
                {
                    strcat(combination, letters);
                }
                StackPush(stack, combination);
            }
            break;
            default:
            {
                char* tmp = (char*)malloc(sizeof(char)*2);
                sprintf(tmp, "%c", s[i]);
                StackPush(stack, tmp);
            }
            break;
        }
    }
    return getTokens(stack, TokenTypeLetter);
}
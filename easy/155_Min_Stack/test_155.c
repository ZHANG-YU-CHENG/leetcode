#include "gtest/gtest.h"

typedef struct stackNode{
    long long int val;
    long long int lastMin; //If pop cur node, then the min of the stack will be set to this value
    struct stackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} MinStack;

extern MinStack* minStackCreate();
extern void minStackPush(MinStack* obj, int val);
extern void minStackPop(MinStack* obj);
extern int minStackTop(MinStack* obj);
extern int minStackGetMin(MinStack* obj);
extern void minStackFree(MinStack* obj);

//for debug
void printStack(MinStack* obj)
{
    StackNode* cur = obj->top;
    while(cur)
    {
        printf("[%p] val=%lld, lastMin=%lld, next=%p\n", cur, cur->val, cur->lastMin, cur->next);
        cur = cur->next;
    }
}

TEST(MinStackTest, test1) {

    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    int out = minStackGetMin(obj);
    EXPECT_EQ(out, -3);
    
    minStackPop(obj);
    out = minStackTop(obj);
    EXPECT_EQ(out, 0);
    
    out = minStackGetMin(obj);
    EXPECT_EQ(out, -2);
    
    minStackFree(obj);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
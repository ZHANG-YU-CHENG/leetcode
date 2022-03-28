#include "gtest/gtest.h"

typedef struct stackNode{
    int val;
    struct stackNode* next;
}StackNode;

typedef struct{
    StackNode* top;
}Stack;

typedef struct {
    Stack* s1;
    Stack* s2;
} MyQueue;

extern MyQueue* myQueueCreate();
extern void myQueuePush(MyQueue* obj, int x);
extern int myQueuePop(MyQueue* obj);
extern int myQueuePeek(MyQueue* obj);
extern bool myQueueEmpty(MyQueue* obj);
extern void myQueueFree(MyQueue* obj);

/*
Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
Output
    [null, null, null, 1, 1, false]

Explanation
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
*/

TEST(myQueueTest, test1) {
    
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    int peek = myQueuePeek(q); EXPECT_EQ(1, peek);
    int pop = myQueuePop(q); EXPECT_EQ(1, pop);
    bool isEmpty = myQueueEmpty(q); EXPECT_FALSE(isEmpty);

    myQueueFree(q);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
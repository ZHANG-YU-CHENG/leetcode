/**
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
 * 
 * class Node {
 *     public int val;
 *     public List<Node> neighbors;
 * }
 * 
 * 
 * Test case format:
 * For simplicity, each node's value is the same as the node's index (1-indexed). 
 * For example, the first node with val == 1, the second node with val == 2, and so on. 
 * The graph is represented in the test case using an adjacency list.
 * An adjacency list is a collection of unordered lists used to represent a finite graph. 
 * Each list describes the set of neighbors of a node in the graph.
 * The given node will always be the first node with val = 1. 
 * You must return the copy of the given node as a reference to the cloned graph.
 * 
 * 
 * Example 1:
 * Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
 * Output: [[2,4],[1,3],[2,4],[1,3]]
 * Explanation: There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 * 
 * 
 * Example 2:
 * Input: adjList = [[]]
 * Output: [[]]
 * Explanation: Note that the input contains one empty list. 
 * The graph consists of only one node with val = 1 and it does not have any neighbors.
 * 
 * Example 3:
 * Input: adjList = []
 * Output: []
 * Explanation: This an empty graph, it does not have any nodes.
 * 
 * 
 * Constraints:
 * The number of nodes in the graph is in the range [0, 100].
 * 1 <= Node.val <= 100
 * Node.val is unique for each node.
 * There are no repeated edges and no self-loops in the graph.
 * The Graph is connected and all nodes can be visited starting from the given node.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

typedef struct queueNode{
    struct Node* oldAddr;
    struct Node* newAddr;
    bool ready;
    struct queueNode* next;
}QueueNode;

typedef struct queueList{
    QueueNode* front;
    QueueNode* back;
    int size;
}QueueList;

void printTable(QueueList* table);

QueueList* createQueue(void){
    QueueList* queue = (QueueList*)malloc(sizeof(QueueList));
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
    return queue;
}

bool isQueueEmpty(QueueList* queue){
    return (queue->size==0);
}

void queuePush(QueueList* queue, struct Node* oldAddr){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->oldAddr = oldAddr;
    newNode->newAddr = (struct Node*)malloc(sizeof(struct Node));
    newNode->ready = false;
    newNode->next = NULL;
    if(isQueueEmpty(queue))
        queue->front = newNode;
    else
        queue->back->next = newNode;
    
    queue->back = newNode;
    queue->size ++;       
}


bool isReady(struct Node* oldAddr, QueueList* table)
{
    QueueNode* cur = table->front;
    while(cur)
    {
        if(cur->oldAddr == oldAddr)
            return cur->ready;
        cur = cur->next;
    }
    return false;     
}

void setReady(struct Node* oldAddr, QueueList* table)
{
    QueueNode* cur = table->front;
    while(cur)
    {
        if(cur->oldAddr == oldAddr)
        {
            cur->ready = true;
            return;
        }
        cur = cur->next;
    }
    return;     
}

struct Node* getNewAddr(struct Node* oldAddr, QueueList* table)
{
    //If oldAddr is in mapping table
    //return the correspond newAddr
    QueueNode* cur = table->front;
    while(cur)
    {
        if(cur->oldAddr == oldAddr)
            return cur->newAddr;
        cur = cur->next;
    }

    //If oldAddr is NOT in mapping table,
    //Add new pair [oldAddr , newAddr] into mapping table
    //return the new pair's newAddr
    queuePush(table, oldAddr);
    return table->back->newAddr;
}

void cloneGraph_r(struct Node* s, QueueList* table) {
    //If the newNode has already been set
    if(isReady(s, table)) return;

    struct Node* newNode = getNewAddr(s, table);
    newNode->val = s->val;
    newNode->numNeighbors = s->numNeighbors;
    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node)*newNode->numNeighbors);
    for(int i=0; i<newNode->numNeighbors; ++i)
    {
        struct Node* newNeighbor = getNewAddr(s->neighbors[i], table);
        newNode->neighbors[i] = newNeighbor;
    }
    //set to ready
    setReady(s, table);

    //recursively check neighbors
    for(int i=0; i<newNode->numNeighbors; ++i)
    {
        cloneGraph_r(s->neighbors[i], table);
    }
}

struct Node *cloneGraph(struct Node *s) {
    if(s==NULL) return s;

    //mapping table : [oldAddr , newAddr]
    QueueList* table = createQueue();

    cloneGraph_r(s, table);
    printTable(table);

    return table->front->newAddr;
}


//for debug
void printTable(QueueList* table)
{
    
    struct Node* s;
    QueueNode* cur = table->front;
    puts("==============");
    puts("table:");
    while(cur)
    {
        printf("oldAddr=%p, newAddr=%p, ready=%s\n", cur->oldAddr, cur->newAddr, cur->ready?"true":"false");
        cur = cur->next;
    }
    puts("---------");
    int i = 1;
    cur = table->front;
    while(cur)
    {
        s = cur->newAddr;
        printf("s%d=%p, val=%d, num=%d, n1=%p, n2=%p\n",i, s, s->val, s->numNeighbors, s->neighbors[0], s->neighbors[1]);
        cur = cur->next;
        ++i;
    }
    puts("==============");
}
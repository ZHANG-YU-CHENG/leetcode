/**
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * Example 2:
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode {
    int row_col[2];
    struct queueNode* next;
}QueueNode;

typedef struct {
    QueueNode* head;
    QueueNode* tail;
    int size;
}Queue;

Queue* createQueue(void) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

bool queueIsEmpty(Queue* q) {
    return (q->size==0);
}

void queuePush(Queue* q, int* row_col) {
    QueueNode* qNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(q->size==0)
    {
        q->head = qNode;
        q->tail = qNode;
    }
    else
    {
        q->tail->next = qNode;
        q->tail = qNode;
    }
    qNode->next = NULL;
    qNode->row_col[0] = row_col[0];
    qNode->row_col[1] = row_col[1];
    q->size += 1;
}

//get queue first element
int* queueHead(Queue* q) {
    if(q->size==0) return NULL;
    else return q->head->row_col;
}

//get queue last element
int* queueTail(Queue* q) {
    if(q->size==0) return NULL;
    else return q->tail->row_col;
}

//remove queue first element
void queuePop(Queue* q) {
    //if queue is empty
    if(q->size==0) return;
    //if queue is only one node left
    if(q->size==1)
    {
        QueueNode* tmp = q->head;
        if(tmp) free(tmp);
        tmp = NULL;
        q->head = NULL;
        q->tail = NULL;
        q->size -= 1;
        return;
    }
    QueueNode* tmp = q->head;
    q->head = q->head->next;
    if(tmp) free(tmp);
    tmp = NULL;
    q->size -= 1;
}

void freeQueue(Queue* q) {
    while(q->size>0)
        queuePop(q);
    
    if(q) free(q);
    q = NULL;
}


int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    //deal with return value
    *returnSize = matSize;
    *returnColumnSizes = (int*)malloc(sizeof(int)*matSize);
    for(int i=0; i<matSize; ++i)
        (*returnColumnSizes)[i] = matColSize[i];

    //mark matrix record the row_col that already processed '1' and still need to be processed '0'
    int** mark = (int**)malloc(sizeof(int*)*matSize);
    // ret matrix is the return matrix
    int** ret = (int**)malloc(sizeof(int*)*matSize);
    
    //put all row_col of '0' into queue
    Queue* q = createQueue();
    for(int i=0; i<matSize; ++i)
    {
        int* markCol = (int*)malloc(sizeof(int)*matColSize[i]);
        int* retCol = (int*)malloc(sizeof(int)*matColSize[i]);
        mark[i] = markCol;
        ret[i] = retCol;
        for(int j=0; j<matColSize[i]; ++j)
        {
            if(mat[i][j]==0)
            {
                mark[i][j] = 1; //Done, don't need to process again
                int row_col[2] = {i, j};
                queuePush(q, row_col);
            }
            else
            {
                mark[i][j] = 0; //not Done yet, still need to be proccessed
            }
            ret[i][j] = 0;
        }
    }

    int curQueueSize;
    int* row_col;
    int row, col;
    int count = 0;
    while(q->size>0)
    {
        ++count;
        //since queue size will change during the process, need save the queue size
        curQueueSize = q->size; 
        for(int i=0; i<curQueueSize; ++i)
        {
            row_col = queueHead(q); 
            row = row_col[0];
            col = row_col[1];
            queuePop(q);
            mark[row][col] = 1;
            int left[2]   = {row, col-1};
            int right[2]  = {row, col+1};
            int top[2]    = {row-1, col};
            int bottom[2] = {row+1, col};
            //left
            if(col-1>=0 && mark[row][col-1]==0)
            {
                ret[row][col-1] = count;
                mark[row][col-1] = 1;
                queuePush(q, left);
            }
            //right
            if(col+1<matColSize[row] && mark[row][col+1]==0)
            {
                ret[row][col+1] = count;
                mark[row][col+1] = 1;
                queuePush(q, right);
            }
            //top
            if(row-1>=0 && mark[row-1][col]==0)
            {
                ret[row-1][col] = count;
                mark[row-1][col] = 1;
                queuePush(q, top);
            }
            //bottom
            if(row+1<matSize && mark[row+1][col]==0)
            {
                ret[row+1][col] = count;
                mark[row+1][col] = 1;
                queuePush(q, bottom);
            }
        }
    }

    for(int i=0; i<matSize; ++i)
    {
        free(mark[i]);
    }
    free(mark);
    return ret;
}
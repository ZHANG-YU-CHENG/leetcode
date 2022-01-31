#ifndef BINARY_TREE_UTILS_H
#define BINARY_TREE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode{
    struct TreeNode* val;
    struct QueueNode* next;
};

void queue_push(struct QueueNode** queue, struct TreeNode* val);
struct TreeNode* queue_pop(struct QueueNode** queue);
bool queue_is_empty(struct QueueNode* queue);
void queue_print(struct QueueNode* queue);
struct TreeNode* arr2BT(char** arr, int arrlen);

#endif
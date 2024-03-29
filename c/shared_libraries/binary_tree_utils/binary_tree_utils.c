#include "binary_tree_utils.h"


void queue_push(struct QueueNode** queue, struct TreeNode* val)
{
    struct QueueNode* newQueueNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    newQueueNode->val = val;
    newQueueNode->next = NULL;

    //first node
    if(*queue==NULL)
    {
        *queue = newQueueNode;
        return;
    }
    
    struct QueueNode* current = *queue;
    
    //find the end of the queue
    while(current->next)
    {
        current = current->next;
    }

    //append the new node in the end of the queue
    current->next = newQueueNode;

    return;
}

struct TreeNode* queue_pop(struct QueueNode** queue)
{
    struct TreeNode* pop_val = NULL;
    pop_val = (*queue)->val;

    //set the next node be the head of the queue
    (*queue) = (*queue)->next;

    return pop_val;
}

bool queue_is_empty(struct QueueNode* queue)
{
    return (queue==NULL) ? true : false;
}

void queue_print(struct QueueNode* queue)
{
    struct QueueNode* current = queue;
    while(current)
    {
        printf("%d ", current->val->val);
        current = current->next;
    }
    puts("");
}


//string array to binary tree
struct TreeNode* arr2BT(char** arr, int arrlen)
{
    if(arrlen==0 || strcmp(arr[0],"x")==0) return NULL;

    struct TreeNode* root = (struct TreeNode*) (malloc(sizeof(struct TreeNode)));
    root->val = atoi(arr[0]);
    root->left = NULL;
    root->right = NULL;

    struct TreeNode* parent_node = root;
    struct QueueNode* queue = NULL;
    for(int i=1; i<arrlen; ++i)
    {
        if(strcmp(arr[i],"x")!=0)
        {
            //add left child
            struct TreeNode* left_child = (struct TreeNode*) (malloc(sizeof(struct TreeNode)));
            left_child->val = atoi(arr[i]);
            left_child->left = NULL;
            left_child->right = NULL;
            parent_node->left = left_child;
            queue_push(&queue, left_child);            
        }

        ++i;
        if(i>=arrlen)break;

        if(strcmp(arr[i],"x")!=0)
        {
            //add right child
            struct TreeNode* right_child = (struct TreeNode*) (malloc(sizeof(struct TreeNode)));
            right_child->val = atoi(arr[i]);
            right_child->left = NULL;
            right_child->right = NULL;
            parent_node->right = right_child;
            queue_push(&queue, right_child);
        }

        parent_node = queue_pop(&queue);
    }
    return root;
}

//find unique node by val
bool findUniqueNode(struct TreeNode* root, struct TreeNode** target, int val)
{
    if(root==NULL) return false;

    if(root->val==val)
    {
        *target = root;
        return true;
    }

    bool left = findUniqueNode(root->left, target, val);
    if(left) return true;
    bool right = findUniqueNode(root->right, target, val);
    return right;
}

//helper function for deleteTree only
static void _deleteTree(struct TreeNode* root)
{
    if(root==NULL) return;

    //recursive delete left and right subtree
    _deleteTree(root->left);
    _deleteTree(root->right);

    //delete the current node
    //printf("Deleting node : %d\n", root->val);
    free(root);
}

//delete tree
void deleteTree(struct TreeNode** root)
{
    _deleteTree(*root);
    *root = NULL;
}

//compare two binary trees
bool compareBT(struct TreeNode* root1, struct TreeNode* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL && root2!=NULL)
        return false;
    if(root1!=NULL && root2==NULL)
        return false;
    if(root1->val!=root2->val)
        return false;
    else
        return compareBT(root1->left, root2->left) && compareBT(root1->right, root2->right);
}
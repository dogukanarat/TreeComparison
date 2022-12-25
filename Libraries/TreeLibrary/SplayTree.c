#include "SplayTree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// SplayTree_DestroyNode destroys a node recursively.
static inline void SplayTree_DestroyNode(SplayTreeNode* node);

// SplayTree_CreateNode creates a node.
static inline SplayTreeNode* SplayTree_CreateNode(int32_t key, int32_t data);

// SplayTree_Splay splays a node.
static inline void SplayTree_Splay(SplayTree* self, SplayTreeNode** node, int32_t key);

void SplayTree_Splay(SplayTree* self, SplayTreeNode** root, int32_t key)
{
    if (root == NULL)
    {
        return;
    }
    
    SplayTreeNode** parentNodePtr = root;
    SplayTreeNode** currentNode = parentNodePtr;
    SplayTreeNode* floatingNode = NULL;

    while(TRUE)
    {
        if(key == (*currentNode)->key || (*currentNode) == NULL)
        {
            break;
        }

        if(key < (*currentNode)->key)
        {
            parentNodePtr = currentNode;
            (currentNode) = &(*currentNode)->left;
        }

        if(key > (*currentNode)->key)
        {
            parentNodePtr = currentNode;
            (currentNode) = &(*currentNode)->right;
        }
    }
    
    if((*currentNode) != NULL && currentNode != parentNodePtr)
    {
        if((*parentNodePtr)->key < (*currentNode)->key)
        {
            self->numberOfRotation++;

            floatingNode = (*currentNode)->left;
            (*currentNode)->left = *parentNodePtr;
            (*parentNodePtr) = (*currentNode);
            (*parentNodePtr)->left->right = NULL;
            currentNode = &(*parentNodePtr)->left;
        }
        else if((*parentNodePtr)->key > (*currentNode)->key)
        {
            self->numberOfRotation++;

            floatingNode = (*currentNode)->right;
            (*currentNode)->right = *parentNodePtr;
            (*parentNodePtr) = (*currentNode);
            (*parentNodePtr)->right->left = NULL;
            currentNode = &(*parentNodePtr)->right;
        }

        SplayTreeNode** destinationNode = currentNode;
        
        if(floatingNode != NULL)
        {
            while(TRUE)
            {
                if(floatingNode->key < (*destinationNode)->key)
                {
                    if( (*destinationNode)->left != NULL)
                    {
                        destinationNode = &(*destinationNode)->left;
                    }
                    else
                    {
                        (*destinationNode)->left = floatingNode;
                        break;
                    }

                }
                else if(floatingNode->key > (*destinationNode)->key)
                {
                    if((*destinationNode)->right != NULL)
                    {
                        destinationNode = &(*destinationNode)->right;
                    }
                    else
                    {
                        (*destinationNode)->right = floatingNode;
                        break;
                    }
                }
            }
        } 

    }

    if((*root)->key != key)
    {
        SplayTree_Splay(self, root, key);
    }
}

void SplayTree_DestroyNode(SplayTreeNode* node)
{
    if (node->left != NULL)
    {
        SplayTree_DestroyNode(node->left);
    }
    if (node->right != NULL)
    {
        SplayTree_DestroyNode(node->right);
    }

    free(node);
}

SplayTreeNode* SplayTree_CreateNode(int32_t key, int32_t data)
{
    SplayTreeNode* node = (SplayTreeNode*)malloc(sizeof(SplayTreeNode));

    if (node != NULL)
    {
        node->key = key;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}


void SplayTree_Init(SplayTree* self)
{
    if (self != NULL)
    {
        self->isInitialized = TRUE;
        self->root = NULL;
    }
}

void SplayTree_Destroy(SplayTree* self)
{
    if (self != NULL && self->isInitialized)
    {
        if (self->root != NULL)
        {
            SplayTree_DestroyNode(self->root);
        }
    }
}

void SplayTree_Insert(SplayTree* self, int32_t key, int32_t data)
{
    SplayTreeNode *node = NULL;
    SplayTreeNode *next = NULL;
    SplayTreeNode *last = NULL;

    data = 1;

    /* Well, there must be a first case */
    if (self->root == NULL)
    {
        node = SplayTree_CreateNode(key, data);
        self->root = node;
    }
    else
    {
        next = self->root;

        while (next != NULL)
        {
            last = next;

            self->numberOfComparison++;

            if (key < next->key)
            {
                next = next->left;
            }
            else if (key > next->key)
            {
                next = next->right;
            }
            else if (key == next->key)
            {
                next->data += data;

                SplayTree_Splay(self, &self->root, key);
                
                return;
            }
        }

        node = SplayTree_CreateNode(key, data);

        if (key < last->key)
            last->left = node;

        if (key > last->key)
            last->right = node;
    }

    SplayTree_Splay(self, &self->root, key);
}

// SplayTree_PrintNode is a recursive function that prints the tree in order
void SplayTree_PrintNode(SplayTreeNode* node)
{
    if (node != NULL)
    {
        printf("%d ", node->key);
        SplayTree_PrintNode(node->left);
        SplayTree_PrintNode(node->right);
    }
}

void SplayTree_Print(SplayTree* self)
{
    if (self != NULL && self->isInitialized)
    {
        SplayTree_PrintNode(self->root);
    }
}

int SplayTree_GetTotalCost(SplayTree *self)
{
    int result = -1;

    if (self != NULL && self->isInitialized)
    {
        result = self->numberOfComparison + self->numberOfRotation;
    }

    return result;
}
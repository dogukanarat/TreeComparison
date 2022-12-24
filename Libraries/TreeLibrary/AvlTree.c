#include "AvlTree.h"
#include <string.h>
#include <stdlib.h>

// The AvlTree_DestroyNode function destroys a node recursively.
static inline AvlTreeNode* AvlTree_CreateNode(int32_t key, int32_t data);

// The AvlTree_GetHeight function returns the height of an AvlTree struct.
static inline int32_t AvlTree_GetHeight(AvlTree* self);

// The AvlTree_GetNodeHeight function returns the height of a node.
static inline int32_t AvlTree_GetNodeHeight(AvlTreeNode* node);

// The AvlTree_GetBalanceFactor function returns the balance factor of a node.
static inline int AvlTree_GetBalanceFactor(AvlTreeNode* node);

// The AvlTree_Balance function balances an AvlTree struct.
static inline void AvlTree_Balance(AvlTree* self);

// The AvlTree_BalanceNode function balances a node.
static inline AvlTreeNode* AvlTree_BalanceNode(AvlTreeNode* node);

// The AvlTree_RotateLeftLeft function rotates a node to the left.
static inline AvlTreeNode* AvlTree_RotateLeftLeft(AvlTreeNode* node);

// The AvlTree_RotateRightRight function rotates a node to the right.
static inline AvlTreeNode* AvlTree_RotateRightRight(AvlTreeNode* node);

// The AvlTree_RotateLeftRight function rotates a node to the left and then to the right.
static inline AvlTreeNode* AvlTree_RotateLeftRight(AvlTreeNode* node);

// The AvlTree_RotateRightLeft function rotates a node to the right and then to the left.
static inline AvlTreeNode* AvlTree_RotateRightLeft(AvlTreeNode* node);

AvlTreeNode *AvlTree_RotateLeftLeft(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    AvlTreeNode *a = node;
    AvlTreeNode *b = a->left;

    a->left = b->right;
    b->right = a;

    return b;
}

AvlTreeNode *AvlTree_RotateRightRight(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    AvlTreeNode *a = node;
    AvlTreeNode *b = a->right;

    a->right = b->left;
    b->left = a;

    return b;
}

AvlTreeNode *AvlTree_RotateLeftRight(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    AvlTreeNode *a = node;
    AvlTreeNode *b = a->left;
    AvlTreeNode *c = b->right;

    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;

    return c;
}

AvlTreeNode *AvlTree_RotateRightLeft(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    AvlTreeNode *a = node;
    AvlTreeNode *b = a->right;
    AvlTreeNode *c = b->left;

    a->right = c->left;
    b->left = c->right;
    c->left = a;
    c->right = b;

    return c;
}

int AvlTree_GetBalanceFactor(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int leftHeight = AvlTree_GetNodeHeight(node->left);
    int rightHeight = AvlTree_GetNodeHeight(node->right);

    return leftHeight - rightHeight;
}

AvlTreeNode *AvlTree_BalanceNode(AvlTreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->left != NULL)
    {
        node->left = AvlTree_BalanceNode(node->left);
    }

    if (node->right != NULL)
    {
        node->right = AvlTree_BalanceNode(node->right);
    }

    int balanceFactor = AvlTree_GetBalanceFactor(node);

    if (balanceFactor > 1)
    {
        if (AvlTree_GetBalanceFactor(node->left) > 0)
        {
            return AvlTree_RotateLeftLeft(node);
        }
        else
        {
            return AvlTree_RotateLeftRight(node);
        }
    }
    else if (balanceFactor < -1)
    {
        if (AvlTree_GetBalanceFactor(node->right) < 0)
        {
            return AvlTree_RotateRightRight(node);
        }
        else
        {
            return AvlTree_RotateRightLeft(node);
        }
    }

    return node;
}

void AvlTree_Balance(AvlTree *self)
{
    AvlTreeNode *newroot = NULL;

    newroot = AvlTree_BalanceNode(self->root);

    if (newroot != self->root)
    {
        self->root = newroot;
    }
}

void AvlTree_DestroyNode(AvlTree *self, AvlTreeNode *node)
{
    if (self != NULL && self->isInitialized)
    {
        if (node != NULL)
        {
            if (node->left != NULL)
            {
                AvlTree_DestroyNode(self, node->left);
            }

            if (node->right != NULL)
            {
                AvlTree_DestroyNode(self, node->right);
            }

            free(node);
        }
    }
}

void AvlTree_Init(AvlTree *self)
{
    if (self != NULL)
    {
        self->isInitialized = TRUE;
        self->root = NULL;
    }
}

void AvlTree_Destroy(AvlTree *self)
{
    if (self != NULL && self->isInitialized)
    {
        if (self->root != NULL)
        {
            AvlTree_DestroyNode(self, self->root);
        }
        self->isInitialized = FALSE;
    }
}

AvlTreeNode *AvlTree_CreateNode(int32_t key, int32_t data)
{
    AvlTreeNode *node = (AvlTreeNode *)malloc(sizeof(AvlTreeNode));
    if (node != NULL)
    {
        node->key = key;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void AvlTree_Insert(AvlTree *self, int32_t key, int32_t data)
{
    AvlTreeNode *node = NULL;
    AvlTreeNode *next = NULL;
    AvlTreeNode *last = NULL;

    data = 1;

    /* Well, there must be a first case */
    if (self->root == NULL)
    {
        node = AvlTree_CreateNode(key, data);
        self->root = node;
    }
    else
    {
        next = self->root;

        while (next != NULL)
        {
            last = next;

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

                return;
            }
        }

        node = AvlTree_CreateNode(key, data);

        if (key < last->key)
            last->left = node;

        if (key > last->key)
            last->right = node;
    }

    AvlTree_Balance(self);
}

int32_t AvlTree_Find(AvlTree *self, int32_t key)
{
    if (self != NULL && self->isInitialized)
    {
        if (self->root != NULL)
        {
            AvlTreeNode *currentNode = self->root;

            while (currentNode != NULL)
            {
                if (key < currentNode->key)
                {
                    currentNode = currentNode->left;
                }
                else if (key > currentNode->key)
                {
                    currentNode = currentNode->right;
                }
                else
                {
                    return currentNode->data;
                }
            }
        }
    }

    return 0;
}

int32_t AvlTree_GetHeight(AvlTree *self)
{
    if (self != NULL && self->isInitialized)
    {
        return AvlTree_GetNodeHeight(self->root);
    }
    else
    {
        return 0;
    }
}

int32_t AvlTree_GetNodeHeight(AvlTreeNode *node)
{
    if (node != NULL)
    {
        int32_t leftHeight = AvlTree_GetNodeHeight(node->left);
        int32_t rightHeight = AvlTree_GetNodeHeight(node->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
    else
    {
        return 0;
    }
}

// AvlTree_Print prints all subset of node to console stylish
void AvlTree_PrintNode(AvlTreeNode *node)
{
    
}

// AvlTree_Print prints all tree node to console stylish
void AvlTree_Print(AvlTree *self)
{


}
#include "AvlTree.h"
#include <string.h>
#include <stdlib.h>

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
                // TODO: Handle duplicate keys
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

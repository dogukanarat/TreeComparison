#include "SplayTree.h"
#include <stdlib.h>

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
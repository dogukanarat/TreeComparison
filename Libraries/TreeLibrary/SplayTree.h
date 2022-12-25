#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "TreeLibrary/Common.h"

typedef struct SplayTreeNodeStruct
{
    int32_t data;
    int32_t key;
    struct SplayTreeNodeStruct* left;
    struct SplayTreeNodeStruct* right;
} SplayTreeNode;

typedef struct
{
    bool isInitialized;
    SplayTreeNode* root;
    int numberOfComparison;
    int numberOfRotation;
} SplayTree;

// SplayTree_Init initializes a SplayTree struct.
void SplayTree_Init(SplayTree* self);

// SplayTree_Destroy destroys a SplayTree struct and nodes recursively.
void SplayTree_Destroy(SplayTree* self);

// SplayTree_Insert inserts a node into a SplayTree struct.
void SplayTree_Insert(SplayTree* self, int32_t key, int32_t data);

// SplayTree_Find finds a node in a SplayTree struct.
int32_t SplayTree_Find(SplayTree* self, int32_t key);

// SplayTree_Print prints a SplayTree preorder
void SplayTree_Print(SplayTree* self);

// SplayTree_GetTotalCost returns the total cost of the tree
int SplayTree_GetTotalCost(SplayTree *self);

#ifdef __cplusplus
}
#endif

#endif // SPLAYTREE_H

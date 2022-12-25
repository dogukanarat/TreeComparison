#ifndef AVLTREE_H
#define AVLTREE_H

// This is a header file for the AvlTree library.
// This library is a generic implementation of an AVL tree.
// The library is implemented in C and is intended to be used in C and C++.

#ifdef __cplusplus
extern "C"
{
#endif

#include "TreeLibrary/Common.h"

// The AvlTreeNode struct is the node struct of the library.
typedef struct AvlTreeNodeStruct
{
    int32_t data;
    int32_t key;
    struct AvlTreeNodeStruct* left;
    struct AvlTreeNodeStruct* right;
    int height;
} AvlTreeNode;

// The AvlTree struct is the main struct of the library.
typedef struct
{
    bool isInitialized;
    AvlTreeNode* root;
    int numberOfComparison;
    int numberOfRotation;
} AvlTree;

// The AvlTree_Init function initializes an AvlTree struct.
void AvlTree_Init(AvlTree* self);

// The AvlTree_Destroy function destroys an AvlTree struct and nodes recursively.
void AvlTree_Destroy(AvlTree* self);

// The AvlTree_Insert function inserts a node into an AvlTree struct.
void AvlTree_Insert(AvlTree* self, int32_t key, int32_t data);

// The AvlTree_Find function finds a node in an AvlTree struct.
int32_t AvlTree_Find(AvlTree* self, int32_t key);

// AvlTree_Print prints tree preorder travelsal
void AvlTree_Print(AvlTree *self);

// AvlTree_GetTotalCost returns the total cost of the tree
int AvlTree_GetTotalCost(AvlTree *self);

#ifdef __cplusplus
}
#endif

#endif // AVLTREE_H

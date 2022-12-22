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
} AvlTree;

// The AvlTree_Init function initializes an AvlTree struct.
void AvlTree_Init(AvlTree* self);

// The AvlTree_Destroy function destroys an AvlTree struct and nodes recursively.
void AvlTree_Destroy(AvlTree* self);

// The AvlTree_DestroyNode function destroys a node recursively.
AvlTreeNode* AvlTree_CreateNode(int32_t key, int32_t data);

// The AvlTree_Insert function inserts a node into an AvlTree struct.
void AvlTree_Insert(AvlTree* self, int32_t key, int32_t data);

// The AvlTree_Find function finds a node in an AvlTree struct.
int32_t AvlTree_Find(AvlTree* self, int32_t key);

// The AvlTree_GetHeight function returns the height of an AvlTree struct.
int32_t AvlTree_GetHeight(AvlTree* self);

// The AvlTree_GetNodeHeight function returns the height of a node.
int32_t AvlTree_GetNodeHeight(AvlTreeNode* node);

// The AvlTree_GetBalanceFactor function returns the balance factor of a node.
int AvlTree_GetBalanceFactor(AvlTreeNode* node);

// The AvlTree_Balance function balances an AvlTree struct.
void AvlTree_Balance(AvlTree* self);

// The AvlTree_BalanceNode function balances a node.
AvlTreeNode* AvlTree_BalanceNode(AvlTreeNode* node);

// The AvlTree_RotateLeftLeft function rotates a node to the left.
AvlTreeNode* AvlTree_RotateLeftLeft(AvlTreeNode* node);

// The AvlTree_RotateRightRight function rotates a node to the right.
AvlTreeNode* AvlTree_RotateRightRight(AvlTreeNode* node);

// The AvlTree_RotateLeftRight function rotates a node to the left and then to the right.
AvlTreeNode* AvlTree_RotateLeftRight(AvlTreeNode* node);

// The AvlTree_RotateRightLeft function rotates a node to the right and then to the left.
AvlTreeNode* AvlTree_RotateRightLeft(AvlTreeNode* node);

#ifdef __cplusplus
}
#endif

#endif // AVLTREE_H

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
} SplayTree;

void SplayTree_Init(SplayTree* self);

void SplayTree_Destroy(SplayTree* self);


#ifdef __cplusplus
}
#endif

#endif // SPLAYTREE_H

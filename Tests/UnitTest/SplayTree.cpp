#include <gtest/gtest.h>
#include "TreeLibrary/SplayTree.h"

TEST(SplayTreeTest, Init)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    EXPECT_EQ(tree.root, nullptr);
    EXPECT_EQ(tree.isInitialized, TRUE);
}



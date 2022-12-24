#include <gtest/gtest.h>
#include "TreeLibrary/SplayTree.h"

TEST(SplayTreeTest, Init)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    EXPECT_EQ(tree.root, nullptr);
    EXPECT_EQ(tree.isInitialized, TRUE);
}

TEST(SplayTreeTest, InsertOne)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    SplayTree_Insert(&tree, 1, 1);

    EXPECT_EQ(tree.root->key, 1);
    EXPECT_EQ(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->right, nullptr);
}

TEST(SplayTreeTest, InsertTwo)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    SplayTree_Insert(&tree, 1, 1);
    SplayTree_Insert(&tree, 2, 2);

    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->right, nullptr);
}

TEST(SplayTreeTest, InsertThree)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    SplayTree_Insert(&tree, 1, 1);
    SplayTree_Insert(&tree, 2, 2);
    SplayTree_Insert(&tree, 3, 3);

    EXPECT_EQ(tree.root->key, 3);
    EXPECT_EQ(tree.root->left->key, 2);
    EXPECT_EQ(tree.root->left->left->key, 1);
    EXPECT_EQ(tree.root->right, nullptr);
}

TEST(SplayTreeTest, InsertFour)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    SplayTree_Insert(&tree, 4, 4);
    SplayTree_Insert(&tree, 3, 3);
    SplayTree_Insert(&tree, 2, 2);
    SplayTree_Insert(&tree, 1, 1);

    EXPECT_EQ(tree.root->key, 1);
    EXPECT_EQ(tree.root->right->key, 2);
    EXPECT_EQ(tree.root->right->right->key, 3);
    EXPECT_EQ(tree.root->right->right->right->key, 4);

}

TEST(SplayTreeTest, InsertFourRandom)
{
    SplayTree tree;

    SplayTree_Init(&tree);

    SplayTree_Insert(&tree, 2, 2);
    SplayTree_Insert(&tree, 3, 3);
    SplayTree_Insert(&tree, 1, 1);
    SplayTree_Insert(&tree, 4, 4);

    EXPECT_EQ(tree.root->key, 4);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->right->key, 3);
    EXPECT_EQ(tree.root->left->right->left->key, 2);
    
}

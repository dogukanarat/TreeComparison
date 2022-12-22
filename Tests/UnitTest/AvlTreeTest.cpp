#include <gtest/gtest.h>
#include "TreeLibrary/AvlTree.h"

TEST(AvlTreeTest, Init)
{
    AvlTree tree;

    AvlTree_Init(&tree);

    EXPECT_EQ(tree.root, nullptr);
    EXPECT_EQ(tree.isInitialized, TRUE);
}

TEST(AvlTreeTest, InsertOne)
{
    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);

    // check that the root is not null

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 1);
    EXPECT_EQ(tree.root->data, 1);
    EXPECT_EQ(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->right, nullptr);
}

TEST(AvlTreeTest, InsertTwoBigger)
{
    // adds two nodes to the tree, the second one is bigger than the first one
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 2, 2);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 1);
    EXPECT_EQ(tree.root->data, 1);
    EXPECT_EQ(tree.root->left, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 2);
    EXPECT_EQ(tree.root->right->data, 2);
    EXPECT_EQ(tree.root->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right, nullptr);

}

TEST(AvlTreeTest, InsertTwoSmaller)
{
    // adds two nodes to the tree, the second one is smaller than the first one
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 1, 1);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_EQ(tree.root->right, nullptr);

}

TEST(AvlTreeTest, InsertThree)
{
    // adds three nodes to the tree, the second one is smaller than the first one
    // and the third one is bigger than the second one
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 3, 3);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 3);
    EXPECT_EQ(tree.root->right->data, 3);
    EXPECT_EQ(tree.root->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right, nullptr);

}

TEST(AvlTreeTest, InsertThreeReversed)
{
    // adds three nodes to the tree, the second one is bigger than the first one
    // and the third one is smaller than the second one
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 3, 3);
    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 1, 1);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 3);
    EXPECT_EQ(tree.root->right->data, 3);
    EXPECT_EQ(tree.root->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right, nullptr);

}

TEST(AvlTreeTest, InsertThreeUnbalanced)
{
    // adds three nodes to the tree, the second one is bigger than the first one
    // and the third one is bigger than the second one
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 3, 3);
    AvlTree_Insert(&tree, 2, 2);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 3);
    EXPECT_EQ(tree.root->right->data, 3);
    EXPECT_EQ(tree.root->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right, nullptr);

}

TEST(AvlTreeTest, InsertFour)
{
    // adds four nodes to the tree
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 3, 3);
    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 4, 4);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_NE(tree.root->left, nullptr);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 3);
    EXPECT_EQ(tree.root->right->data, 3);
    EXPECT_EQ(tree.root->right->left, nullptr);
    EXPECT_NE(tree.root->right->right, nullptr);
    EXPECT_EQ(tree.root->right->right->key, 4);
    EXPECT_EQ(tree.root->right->right->data, 4);
    EXPECT_EQ(tree.root->right->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right->right, nullptr);

}

TEST(AvlTreeTest, InsertFive)
{
    // adds five nodes to the tree
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 3, 3);
    AvlTree_Insert(&tree, 4, 4);
    AvlTree_Insert(&tree, 5, 5);

    EXPECT_NE(tree.root, nullptr);
    EXPECT_EQ(tree.root->key, 2);
    EXPECT_EQ(tree.root->data, 2);
    EXPECT_EQ(tree.root->left->key, 1);
    EXPECT_EQ(tree.root->left->data, 1);
    EXPECT_EQ(tree.root->left->left, nullptr);
    EXPECT_EQ(tree.root->left->right, nullptr);
    EXPECT_NE(tree.root->right, nullptr);
    EXPECT_EQ(tree.root->right->key, 4);
    EXPECT_EQ(tree.root->right->data, 4);
    EXPECT_NE(tree.root->right->left, nullptr);
    EXPECT_EQ(tree.root->right->left->key, 3);
    EXPECT_EQ(tree.root->right->left->data, 3);
    EXPECT_EQ(tree.root->right->left->left, nullptr);
    EXPECT_EQ(tree.root->right->left->right, nullptr);
    EXPECT_NE(tree.root->right->right, nullptr);
    EXPECT_EQ(tree.root->right->right->key, 5);
    EXPECT_EQ(tree.root->right->right->data, 5);
    EXPECT_EQ(tree.root->right->right->left, nullptr);
    EXPECT_EQ(tree.root->right->right->right, nullptr); 
}

TEST(AvlTreeTest, InsertSix)
{
    // adds six nodes to the tree
    // check that tree is balanced

    AvlTree tree;

    AvlTree_Init(&tree);

    AvlTree_Insert(&tree, 1, 1);
    AvlTree_Insert(&tree, 2, 2);
    AvlTree_Insert(&tree, 3, 3);
    AvlTree_Insert(&tree, 4, 4);
    AvlTree_Insert(&tree, 5, 5);
    AvlTree_Insert(&tree, 6, 6);

    EXPECT_EQ(tree.root->key, 4);
    EXPECT_EQ(tree.root->data, 4);
    EXPECT_EQ(tree.root->left->key, 2);
    EXPECT_EQ(tree.root->left->data, 2);
    EXPECT_EQ(tree.root->left->left->key, 1);
    EXPECT_EQ(tree.root->left->left->data, 1);
    EXPECT_EQ(tree.root->left->right->key, 3);
    EXPECT_EQ(tree.root->left->right->data, 3);
    EXPECT_EQ(tree.root->right->key, 5);
    EXPECT_EQ(tree.root->right->data, 5);
    EXPECT_EQ(tree.root->right->right->key, 6);
    EXPECT_EQ(tree.root->right->right->data, 6);

}
#pragma once

struct _BinaryTreeNode
{
    void *key;
    void *value;
    struct _BinaryTreeNode *rightChild;
    struct _BinaryTreeNode *leftChild;
};

typedef struct _BinaryTreeNode BinaryTreeNode;

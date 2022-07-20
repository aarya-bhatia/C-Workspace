#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "map.h"

BinaryTreeNode *BinaryTreeNode_Create()
{
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node->key = NULL;
    node->value = NULL;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

/**
 * @brief inserts node into BinaryTree situated at root
 * 
 * @param root 
 * @param new 
 * @param NodeComparator 
 * @return BinaryTreeNode* New Root of BinaryTree
 */
BinaryTreeNode *BinaryTreeNode_Insert(BinaryTreeNode *root, BinaryTreeNode *new, int (* NodeComparator)(BinaryTreeNode *, BinaryTreeNode *))
{
    if(root == NULL)
    {
        return new;
    }

    if((*NodeComparator)(root, new) <= 0)
    {
        root->leftChild = BinaryTreeNode_Insert(root->leftChild, new, NodeComparator);
    }
    else 
    {
        root->rightChild = BinaryTreeNode_Insert(root->rightChild, new, NodeComparator);
    }

    return root;
}

void BinaryTreeNode_Print(BinaryTreeNode *root, void (* PrintNodeFunction)(BinaryTreeNode *))
{
    while(root)
    {
        BinaryTreeNode *left = root->leftChild;
        BinaryTreeNode *right = root->rightChild;

        if(left)
        {
            BinaryTreeNode_Print(left, PrintNodeFunction);
        }

        (*PrintNodeFunction)(root);

        if(right)
        {
            BinaryTreeNode_Print(right, PrintNodeFunction);
        }
    }
}

void BinaryTreeNode_Free(BinaryTreeNode *root)
{
    while(root)
    {
        BinaryTreeNode_Free(root->leftChild);
        BinaryTreeNode_Free(root->rightChild);
        root->key = NULL;
        root->value = NULL;
        root->leftChild = NULL;
        root->rightChild = NULL;
        free(root);
    }
}

int IntNode_Comparator(BinaryTreeNode *n1, BinaryTreeNode *n2)
{
    int k1 = *(int *)(n1->key);
    int k2 = *(int *)(n2->key);
    return k1 - k2;
}

void IntNode_Print(BinaryTreeNode *node)
{
    int key = node->key ? *(int *)node->key : 0;
    int value = node->value ? *(int *)node->value : 0;
    printf("(%d, %d)\n", key, value);
}

int main(int argc, char *argv[])
{
    int int10 = 10;
    int int1 = 1;
    int int5 = 5;
    int int7 = 7;

    BinaryTreeNode *root = BinaryTreeNode_Create();
    BinaryTreeNode *n1 = BinaryTreeNode_Create();
    BinaryTreeNode *n2 = BinaryTreeNode_Create();
    BinaryTreeNode *n3 = BinaryTreeNode_Create();

    root->key = &int10;
    n1->key = &int1;
    n2->key = &int5;
    n3->key = &int7;

    root = BinaryTreeNode_Insert(root, n1, IntNode_Comparator);
    root = BinaryTreeNode_Insert(root, n2, IntNode_Comparator);
    root = BinaryTreeNode_Insert(root, n3, IntNode_Comparator);

    BinaryTreeNode_Print(root, IntNode_Print);
    BinaryTreeNode_Free(root);

    return 0;
}

#include "AvlTreeImplementation.h"
#include <stdlib.h>

static void updateBalance(Node *node)
{
    if (node != NULL)
    {
        node->bal = balanceFactor(node);
    }
}

int height(const Node *node)
{
    int leftHeight;
    int rightHeight;

    if (node == NULL)
    {
        return 0;
    }

    leftHeight = height(node->left);
    rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int balanceFactor(const Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return height(node->left) - height(node->right);
}

Node *createNode(int data)
{
    Node *node = malloc(sizeof *node);

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->bal = 0;
    return node;
}

Node *rightRotate(Node *node)
{
    Node *newRoot;
    Node *transferredSubtree;

    if (node == NULL || node->left == NULL)
    {
        return node;
    }

    newRoot = node->left;
    transferredSubtree = newRoot->right;
    newRoot->right = node;
    node->left = transferredSubtree;

    updateBalance(node);
    updateBalance(newRoot);
    return newRoot;
}

Node *leftRotate(Node *node)
{
    Node *newRoot;
    Node *transferredSubtree;

    if (node == NULL || node->right == NULL)
    {
        return node;
    }

    newRoot = node->right;
    transferredSubtree = newRoot->left;
    newRoot->left = node;
    node->right = transferredSubtree;

    updateBalance(node);
    updateBalance(newRoot);
    return newRoot;
}

Node *leftBalance(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (balanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
    }

    return rightRotate(node);
}

Node *rightBalance(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (balanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
    }

    return leftRotate(node);
}

Node *avlInsert(Node *root, int data)
{
    int balance;

    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = avlInsert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = avlInsert(root->right, data);
    }
    else
    {
        return root;
    }

    updateBalance(root);
    balance = root->bal;

    if (balance > 1)
    {
        return leftBalance(root);
    }
    if (balance < -1)
    {
        return rightBalance(root);
    }

    return root;
}

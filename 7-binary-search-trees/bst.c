#include "bstImplementation.h"
#include <stdlib.h>

Node *createNode(int key)
{
    Node *node = malloc(sizeof *node);

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *searchIteratively(Node *root, int key)
{
    while (root != NULL)
    {
        if (root->key == key)
        {
            return root;
        }
        else if (key < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return NULL;
}

Node *searchRecursively(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return searchRecursively(root->left, key);
    }
    return searchRecursively(root->right, key);
}

Node *findMinIteratively(Node *node)
{
    Node *current = node;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node *findMaxRecursively(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->right == NULL)
    {
        return node;
    }
    return findMaxRecursively(node->right);
}

Node *insertRecursively(Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insertRecursively(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertRecursively(root->right, key);
    }

    return root;
}

Node *removeRecursively(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = removeRecursively(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = removeRecursively(root->right, key);
    }
    else
    {
        Node *temp = findMinIteratively(root->right);
        root->key = temp->key;
        root->right = removeRecursively(root->right, temp->key);
    }

    return root;
}
#include "binaryTreesImplementation.h"
#include <stdio.h>

void preorder(Node *root)
{
    if (root)
    {
        printf("%d\n", root->number);
        preorder(root->left);
        preorder(root->left);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d\n", root->number);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->number);
    }
}
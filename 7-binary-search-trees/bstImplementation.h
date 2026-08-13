typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *searchIteratively(Node *root, int key);
Node *searchRecursively(Node *root, int key);
Node *findMinIteratively(Node *node);
Node *findMaxRecursively(Node *node);
Node *createNode(int key);
Node *insertRecursively(Node *root, int key);
Node *removeRecursively(Node *root, int key);

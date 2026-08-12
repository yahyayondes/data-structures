typedef struct Node
{
    int number;
    struct Node *right;
    struct Node *left;
} Node;

typedef struct Tree
{
    node *root;
} Tree;

void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

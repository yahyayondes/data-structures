typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int bal; /* height(left) - height(right) */
} Node;

int height(const Node *node);
int balanceFactor(const Node *node);

Node *createNode(int data);
Node *rightRotate(Node *node);
Node *leftRotate(Node *node);
Node *leftBalance(Node *node);
Node *rightBalance(Node *node);
Node *avlInsert(Node *root, int data);

#endif

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

void insertFront(Deque *dq);
int eraseFront(Deque *dq);
int eraseRear(Deque *dq);
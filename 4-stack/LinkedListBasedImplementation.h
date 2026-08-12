typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *head;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
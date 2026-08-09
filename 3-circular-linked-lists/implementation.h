typedef struct intNode
{
    int data;
    struct intNode *next;
} intNode;

typedef struct
{
    intNode *cursor;
    int elemCount;
} circularLists;

void insertFront(intNode **cursor, intNode *newNode);
void removeFront(intNode **cursor);
void removeBack(intNode **cursor);
void print(intNode **cursor);
intNode *circularToLinear(intNode *cursor);
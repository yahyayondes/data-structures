typedef struct intNode
{
    int data;
    struct intNode *next;
} intNode;

typedef struct intList
{
    intNode *head;
    int elemCount;
} intList;

void addFront(intList *list, intNode *newNode);
void addEnd(intList *list, intNode *newNode);
void addMiddle(intList *list, intNode *newNode, int pos);
void removeFront(intList *list);
void removeEnd(intList *list);
void removeValue(intList *list, int target);

int length(intList *list);
int get(intList *list, int pos);

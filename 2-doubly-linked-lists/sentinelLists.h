typedef struct intNode
{
    int data;
    struct intNode *next;
    struct intNode *previous;
} intNode;

typedef struct
{
    intNode *header;
    intNode *tailer;
} sentinelList;

void initList(sentinelList *list);
void addBetween(intNode *newNode, intNode *pred, intNode *succ);
void insertFrontSentinel(sentinelList *list, intNode *newNode);
void insertEndSentinel(sentinelList *list, intNode *newNode);
void removeSentinel(intNode *target);

int isEmptySentinel(sentinelList *list);
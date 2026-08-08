typedef struct intNode
{
    int data;
    struct intNode *next;
    struct intNode *previous;
} intNode;

typedef struct intDoublyList
{
    intNode *head;
    intNode *tail;
    int elemCount;
} intDoublyList;

void addEnd(intNode **head, intNode **tail, intnode *newNode);
void removeEnd(intNode **head, intNode **tail);
void insertAfter(intDoublyList *list, intNode *pred, intNode *newNode);
void insertAtPosition(intDoublyList *list, int pos, int data);
void removeFront(intDoublyList *list);
void removeEnd(intDoublyList *list);
void removeNode(intDoublyList *list, intNode *target);
void printForward(intDoublyList *list);
void destroyList(intDoublyList *list);
void reverseDoubly(intDoublyList *list);
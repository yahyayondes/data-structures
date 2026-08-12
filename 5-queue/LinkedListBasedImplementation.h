typedef struct Qnode
{
    int data;
    struct Qnode *next;
} Qnode;

typedef struct Queue
{
    Qnode *front;
    Qnode *rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int frontVal(Queue *q);
#define LIMIT = 1000;

typedef struct Queue
{
    int data[LIMIT];
    int front; // as index
    int rear;
    int elemCount;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int frontVal(Queue *q);
